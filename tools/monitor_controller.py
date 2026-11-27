#!/usr/bin/env python3
"""Read-only field observer. Records facts; silence is never a policy verdict.

Expected AP JSON: [{"mac": "...", "name": "...", "ip": "..."}].
No HTTP writes, packet injection, RF scans or independent roaming policy.
"""
import argparse
from collections import Counter, deque
import json
import logging
from logging.handlers import RotatingFileHandler
import os
from pathlib import Path
import signal
import time
from urllib.request import urlopen


def stamp():
    return time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime())


class EventTail:
    """Drain an open inode before switching to its successor after rotation."""
    def __init__(self, path):
        self.path = Path(path)
        self.file = None
        self.pending = b''

    def read(self):
        # Rotation names are newest .1, then .2, etc.; process oldest first.
        paths = sorted(self.path.parent.glob(self.path.name + '.*'),
                       key=lambda p: int(p.suffix[1:]) if p.suffix[1:].isdigit() else -1,
                       reverse=True) + [self.path]
        paths = [p for p in paths if p == self.path or p.suffix[1:].isdigit()]
        if self.file is None:
            for p in paths:
                if p.exists():
                    self.file = p.open('rb')
                    break
        for _ in range(len(paths) + 1):
            if self.file is None:
                return
            # Bounded per poll. Unread bytes stay in the file for the next poll.
            chunk = self.file.read(2 << 20)
            self.pending += chunk
            lines = self.pending.split(b'\n')
            self.pending = lines.pop()
            for line in lines:
                try:
                    yield json.loads(line)
                except (ValueError, UnicodeDecodeError):
                    yield {'event': 'observer.invalid_record'}
            if len(chunk) == 2 << 20:
                return
            inode = (os.fstat(self.file.fileno()).st_dev, os.fstat(self.file.fileno()).st_ino)
            existing = []
            for p in paths:
                try:
                    st = p.stat()
                    existing.append((p, (st.st_dev, st.st_ino)))
                except FileNotFoundError:
                    pass
            position = next((i for i, (_, ident) in enumerate(existing) if ident == inode), None)
            if position is None:
                yield {'event': 'observer.retention_gap'}
                successor = existing[0][0] if existing else None
            else:
                successor = existing[position + 1][0] if position + 1 < len(existing) else None
            if successor is None:
                return
            self.file.close()
            self.file = successor.open('rb')
            if self.pending:
                yield {'event': 'observer.incomplete_record'}
                self.pending = b''


class Observer:
    def __init__(self, args):
        self.args = args
        self.out = Path(args.output)
        self.out.mkdir(parents=True, exist_ok=True, mode=0o700)
        self.expected = json.loads(Path(args.expected).read_text())
        self.tail = EventTail(args.events)
        self.counts = Counter()
        self.alerts = deque(maxlen=30)
        self.previous = {}
        self.totals = {}
        self.started = stamp()
        self.last_summary = 0
        self.log = logging.getLogger('field-observer')
        self.log.setLevel(logging.INFO)
        handler = RotatingFileHandler(self.out / 'monitor.jsonl', maxBytes=8 << 20, backupCount=3)
        handler.setFormatter(logging.Formatter('%(message)s'))
        self.log.addHandler(handler)
        self.snapshot = {'started': self.started}

    def emit(self, event, **fields):
        row = {'time': stamp(), 'event': event, **fields}
        self.log.info(json.dumps(row, ensure_ascii=False, separators=(',', ':')))
        return row

    def changed(self, key, value):
        if self.previous.get(key) != value:
            self.previous[key] = value
            self.emit(key, value=value)

    def alert(self, reason, **fields):
        self.alerts.append(self.emit('monitor.attention', reason=reason, **fields))

    def events(self):
        for row in self.tail.read():
            event = row.get('event', 'unknown')
            self.counts[event] += 1
            if event == 'controller.start':
                self.snapshot['controller_run'] = row.get('run_id')
            if event == 'command.completed' and row.get('outcome') == 'failed':
                self.alert('command_failed', **{k: row.get(k) for k in ('run_id', 'command_id', 'ap_id', 'operation', 'item', 'error')})
            elif event in ('observer.records_dropped', 'observer.retention_gap', 'observer.invalid_record', 'observer.incomplete_record'):
                self.alert(event)
            elif event in ('roaming.selection_result', 'balance.decision', 'client.transition', 'acs.selection', 'rrm.state'):
                # Preserve source records without reimplementing their algorithm.
                self.emit('monitor.policy_evidence', source=row)

    def get(self, path):
        with urlopen(self.args.url.rstrip('/') + path, timeout=3) as r:
            return json.load(r)

    def poll(self):
        self.events()
        try:
            aps = self.get('/api/aps')
            facts = [{k: ap.get(k) for k in ('id', 'mac', 'name', 'model', 'local_ip', 'online', 'state', 'connected_at', 'last_seen', 'radio_status', 'reported_ssids')} for ap in aps]
            lookup = {str(ap.get('mac', ap.get('id', ''))).lower(): ap for ap in aps}
            expected = []
            for spec in self.expected:
                ap = lookup.get(spec['mac'].lower())
                state = 'online' if ap and ap.get('online') else 'offline' if ap else 'not_seen'
                row = {**spec, 'state': state}
                if ap:
                    row.update(ap_id=ap['id'], session=ap['connected_at'], reported_ip=ap.get('local_ip'))
                self.changed('ap.' + spec['mac'], {k: v for k, v in row.items()})
                expected.append(row)
            self.snapshot.update(aps=facts, expected=expected, reachable=True, last_success=stamp())
            self.changed('controller.reachable', True)
            now = time.monotonic()
            if now - self.last_summary >= 15:
                clients = self.get('/api/clients')
                clients = [{k: c.get(k) for k in ('mac', 'name', 'ap_id', 'radio_id', 'wlan_id', 'ssid', 'state', 'rssi_dbm', 'ip')} for c in clients]
                self.changed('clients.locations', [{k: c[k] for k in ('mac', 'ap_id', 'radio_id', 'wlan_id', 'state')} for c in clients])
                mobility = self.get('/api/mobility/status')
                rrm = self.get('/api/rrm')
                config = self.get('/api/config')
                apply = config.get('apply', [])
                failures = [s for s in apply if s.get('state') in ('failed', 'blocked')]
                self.changed('configuration.failures', failures)
                health = self.get('/api/observability')
                self.changed('observer.health', health)
                self.snapshot.update(clients=clients, mobility=mobility, rrm_jobs=rrm.get('jobs'), configuration_version=config.get('config', {}).get('version'), apply_failures=failures, logging=health)
                self.last_summary = now
                self.emit('monitor.summary', expected=expected, client_count=len(clients), event_counts=dict(self.counts), apply_failures=len(failures))
        except (OSError, ValueError, KeyError) as e:
            self.snapshot.update(reachable=False, error=str(e))
            self.changed('controller.reachable', str(e))
        self.snapshot.update(updated=stamp(), event_counts=dict(self.counts), recent_attention=list(self.alerts), assessment='Observations only. Paths with no events remain unexercised; ACK is not proof of RF effect.')
        temporary = self.out / '.status.tmp'
        temporary.write_text(json.dumps(self.snapshot, ensure_ascii=False, indent=2) + '\n')
        temporary.replace(self.out / 'status.json')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--url', default='http://127.0.0.1:8090')
    parser.add_argument('--expected', required=True)
    parser.add_argument('--events', required=True)
    parser.add_argument('--output', required=True)
    parser.add_argument('--interval', type=float, default=5)
    parser.add_argument('--once', action='store_true')
    args = parser.parse_args()
    if args.interval < 1:
        parser.error('interval must be at least one second')
    os.umask(0o077)
    observer = Observer(args)
    stop = False
    def end(*_):
        nonlocal stop
        stop = True
    signal.signal(signal.SIGTERM, end)
    signal.signal(signal.SIGINT, end)
    observer.emit('monitor.started', url=args.url, expected=observer.expected)
    while not stop:
        started = time.monotonic()
        observer.poll()
        if args.once:
            break
        remaining = args.interval - (time.monotonic() - started)
        # Short sleeps keep shutdown responsive; ordinary work is event/file/API bound.
        while remaining > 0 and not stop:
            time.sleep(min(remaining, .5))
            remaining = args.interval - (time.monotonic() - started)


if __name__ == '__main__':
    main()
