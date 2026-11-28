#!/usr/bin/env python3
"""Read-only candidate audit, correlated by run_id + decision_id.

Summary contains no client/AP identities. Optional details belong in a private
file. Historical BSSID ownership helps attribution, not proof of readiness at
the decision time. This tool never supplies candidates or infers radio policy.
"""
import argparse
import collections
import json
import pathlib


def mac(value):
    if isinstance(value,list):
        return ':'.join(f'{part:02x}' for part in value)
    return str(value or '').lower()


def utc_sort_key(event):
    value=event.get('time','').removesuffix('Z')
    seconds,_,fraction=value.partition('.')
    return seconds, fraction.ljust(9,'0')


def audit(events):
    owners=collections.defaultdict(set)
    for event in events:
        if event.get('event')=='ap.radio_statistics':
            for vap in event.get('vaps',[]):
                if vap.get('BSSID'):
                    owners[mac(vap['BSSID'])].add(event.get('ap_id'))
    reports={}
    decisions={}
    inputs=collections.defaultdict(list)
    for event in events:
        kind=event.get('event');run=event.get('run_id','legacy')
        if kind=='roaming.station_report':
            reports[(run,event.get('ap_id'),event.get('client'))]=event
        elif kind=='roaming.decision':
            key=(run,event['decision_id'])
            decisions[key]=(event,reports.get((run,event.get('ap_id'),event.get('client'))))
        elif kind=='roaming.candidate_input':
            inputs[(run,event['decision_id'])].append(event['candidate'])
    summary=collections.Counter();details=[]
    for key,(decision,report) in decisions.items():
        rows=inputs[key];summary['decisions']+=1
        if len(rows)!=decision.get('candidate_count'):
            summary['partial_input_logs']+=1
            continue
        aps={row.get('ap_id') for row in rows}
        kind='empty' if not rows else 'source_ap_only' if aps=={decision['ap_id']} else 'includes_other_ap'
        summary[kind]+=1
        raw=set();unresolved=False
        if report is None:
            raw_kind='missing_station_report'
        else:
            for neighbor in report.get('neighbors',[]):
                known=owners[mac(neighbor.get('BSSID'))]
                if len(known)!=1:
                    unresolved=True
                else:
                    raw.update(known)
            raw_kind='reported_other_ap' if raw-{decision['ap_id']} else 'unresolved_bssid_owner' if unresolved else 'raw_source_ap_only'
        if kind=='source_ap_only':
            summary['source_only:'+raw_kind]+=1
            if all(row.get('radio')!=decision.get('radio') for row in rows):
                summary['source_only:other_radio']+=1
        details.append({'run_id':key[0],'decision_id':key[1],'time':decision.get('time'),'kind':kind,'raw_input_kind':raw_kind,'decision':decision,'report':report,'candidates':rows})
    return {'summary':dict(summary),'details':details}


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('logs',nargs='+',type=pathlib.Path)
    parser.add_argument('--details',type=pathlib.Path,help='Private output containing AP/client identities')
    args=parser.parse_args()
    events=[]
    for path in args.logs:
        with path.open() as stream:
            for line in stream:
                try:event=json.loads(line)
                except ValueError:continue
                if event.get('event')=='ap.radio_statistics' or event.get('event','').startswith('roaming.'):
                    events.append(event)
    events.sort(key=utc_sort_key)
    result=audit(events)
    print(json.dumps(result['summary'],ensure_ascii=False,sort_keys=True))
    if args.details:
        args.details.parent.mkdir(parents=True,exist_ok=True)
        args.details.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
        args.details.chmod(0o600)
