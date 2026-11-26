#!/usr/bin/env python3
"""Verify reversible AP settings against the live Go controller and Android.

Uses only the dedicated lab AP. Saves original profile before work; restores
LED/heartbeat/idle values and metadata at the end. Packet ACK and reported
values are recorded separately, never treating one as the other.
"""
import argparse
import datetime
import json
import pathlib
import subprocess
import time
import urllib.request

ROOT=pathlib.Path(__file__).resolve().parents[1]

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--serial',required=True)
    args=p.parse_args()
    base='http://127.0.0.1:8090/api/'
    def api(path,body=None):
        r=urllib.request.Request(base+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
        return json.load(urllib.request.urlopen(r,timeout=20))
    ap=next(a for a in api('aps')if a['online'])
    config=api('config')['config']
    original=next((p for p in config.get('ap_profiles',[])if p['ap_id']==ap['id']),{'name':ap.get('name',''),'location':ap.get('location',''),'group_id':'','template_id':'','options':{}})
    original=json.loads(json.dumps(original));original.pop('ap_id',None)
    profile=json.loads(json.dumps(original))
    folder=ROOT/'.local/ac100/ap-setting-tests';folder.mkdir(parents=True,exist_ok=True,mode=0o700)
    result={'started':datetime.datetime.now().isoformat(),'ap':ap['id'],'original':original,'steps':[]}
    backup=folder/'original-profile.json';backup.write_text(json.dumps(original,ensure_ascii=False,indent=2));backup.chmod(0o600)
    def apply(label,options):
        started=datetime.datetime.now(datetime.timezone.utc)
        profile['options']=options
        api('aps/'+ap['id']+'/settings',profile)
        until=time.monotonic()+30
        while time.monotonic()<until:
            status=next((s for s in api('config')['apply']if s['ap_id']==ap['id']and s['service_id']=='ap-settings'),None)
            if status and datetime.datetime.fromisoformat(status['at'])>=started:
                if status['state']=='failed':raise RuntimeError(status['error'])
                if status['state']=='acknowledged':break
            time.sleep(.5)
        else:raise RuntimeError('AP settings did not acknowledge: '+label)
        api('aps/'+ap['id']+'/refresh',{})
        time.sleep(2)
        snapshot=next(a for a in api('aps')if a['id']==ap['id'])
        step={'label':label,'requested':options,'status':status,'ap':snapshot}
        result['steps'].append(step)
        print(label+': AP acknowledged',flush=True)
        return snapshot
    try:
        profile['name']='GoAC-Lab-AP';profile['location']='AP settings verification'
        off=apply('LED off',{'led':False})
        print('AP reported LED after off:',off.get('wireless_telemetry',{}).get('led'),flush=True)
        on=apply('LED on',{'led':True})
        print('AP reported LED after on:',on.get('wireless_telemetry',{}).get('led'),flush=True)
        apply('heartbeat 19 seconds',{'led':True,'echo_seconds':19,'echo_misses':5})
        apply('client keepalive 45 seconds',{'led':True,'echo_seconds':20,'echo_misses':5,'client_keep_alive':45})
        apply('client idle 600 seconds',{'led':True,'echo_seconds':20,'echo_misses':5,'client_keep_alive':30,'client_idle':600})
        apply('offline self-management enabled',{'led':True,'echo_seconds':20,'echo_misses':5,'client_keep_alive':30,'client_idle':3600,'offline_self_manage':True})
        apply('offline self-management disabled',{'led':True,'echo_seconds':20,'echo_misses':5,'client_keep_alive':30,'client_idle':3600,'offline_self_manage':False})
        check=subprocess.run(['python3',str(ROOT/'tools/check_adb_wifi.py'),'cycle','--serial',args.serial],capture_output=True,text=True,timeout=210)
        result['client_regression']=check.stdout
        if check.returncode:raise RuntimeError(check.stderr)
        print('Android reconnect, DHCP, DNS/HTTPS and client display passed',flush=True)
    except Exception as e:
        result['error']=str(e)
        raise
    finally:
        profile.update(original)
        # Restore the controller's initial session defaults before removing
        # temporary overrides. Original explicit options take precedence.
        profile['options']={'led':True,'echo_seconds':20,'echo_misses':5,'client_keep_alive':30,'client_idle':3600,'offline_self_manage':False,**original.get('options',{})}
        api('aps/'+ap['id']+'/settings',profile)
        time.sleep(3)
        api('aps/'+ap['id']+'/settings',original)
        path=folder/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S')+'.json')
        path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600)
        print('Original profile restored; private evidence:',path,flush=True)

if __name__=='__main__':main()
