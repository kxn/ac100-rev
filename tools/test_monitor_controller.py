import importlib.util
import json
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace

spec = importlib.util.spec_from_file_location('monitor', Path(__file__).with_name('monitor_controller.py'))
monitor = importlib.util.module_from_spec(spec)
spec.loader.exec_module(monitor)


class MonitorTests(unittest.TestCase):
    def test_rotation_drains_old_inode_and_partial_records(self):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / 'events.jsonl'
            path.write_text('{"event":"one"}\n{"event":')
            tail = monitor.EventTail(path)
            self.assertEqual(list(tail.read()), [{'event': 'one'}])
            with path.open('a') as f:
                f.write('"two"}\n')
            path.rename(str(path) + '.1')
            path.write_text('{"event":"three"}\n')
            self.assertEqual([e['event'] for e in tail.read()], ['two', 'three'])
            self.assertEqual(list(tail.read()), [])
            tail.file.close()

    def test_poll_records_missing_aps_failures_and_actual_paths(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            (root / 'expected.json').write_text('[{"mac":"02:00:00:00:00:01","name":"test","ip":"192.0.2.1"}]')
            (root / 'events.jsonl').write_text('{"event":"command.completed","outcome":"failed","command_id":1,"error":"timeout"}\n')
            args = SimpleNamespace(output=str(root / 'out'), expected=str(root / 'expected.json'), events=str(root / 'events.jsonl'), url='http://localhost:8090')
            observer = monitor.Observer(args)
            replies = {'/api/aps': [], '/api/clients': [], '/api/mobility/status': {}, '/api/rrm': {'jobs': {}}, '/api/config': {'config': {'version': 9, 'services': [{'password': 'secret-do-not-copy'}]}, 'apply': [{'state': 'failed', 'ap': 'test'}]}, '/api/observability': {'enabled': True, 'stats': {'dropped': 0, 'write_failures': 0}}}
            requests = []
            def get(path):
                requests.append(path)
                return replies[path]
            observer.get = get
            observer.poll()
            status = json.loads((root / 'out/status.json').read_text())
            self.assertEqual(status['expected'][0]['state'], 'not_seen')
            self.assertEqual(len(status['apply_failures']), 1)
            self.assertEqual(status['recent_attention'][0]['reason'], 'command_failed')
            self.assertNotIn('secret-do-not-copy', (root / 'out/status.json').read_text())
            self.assertEqual(status['configuration_version'], 9)
            self.assertTrue(all(path.startswith('/api/') for path in requests))
            observer.tail.file.close()
            for handler in observer.log.handlers[:]:
                handler.close()
                observer.log.removeHandler(handler)


if __name__ == '__main__':
    unittest.main()
