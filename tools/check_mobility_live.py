#!/usr/bin/env python3
"""Exercise AP roaming control/ACS without requiring a second AP; restore settings."""
import copy,datetime,json,pathlib,time,urllib.request
ROOT=pathlib.Path(__file__).resolve().parents[1]
def api(path,body=None):
 req=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
 with urllib.request.urlopen(req,timeout=20)as r:return json.load(r)
def main():
 out=ROOT/'.local/ac100/mobility-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700)
 evidence={'started':datetime.datetime.now().isoformat()};original=None;radios=None
 try:
  deadline=time.monotonic()+120
  while time.monotonic()<deadline:
   aps=[a for a in api('aps')if a['online']]
   if aps and api('config')['apply']:break
   time.sleep(2)
  if not aps:raise RuntimeError('No AP reconnected')
  ap=aps[0];cfg=api('config')['config'];original=copy.deepcopy(cfg.get('mobility'));radios=copy.deepcopy(cfg['radios']);evidence['before']=ap
  p=api('mobility');p['network_mode']=2;p['default_roaming']['statistics']=True;p['default_roaming']['statistics_interval']=17
  api('mobility',p);print('Compatibility mode / RSSI reporting requested',flush=True)
  time.sleep(22)
  states=api('config')['apply'];evidence['compatibility']=states
  for name in ['roaming','roaming-mode','reporting']:
   state=next((s for s in states if s['ap_id']==ap['id']and s['service_id']==name),{})
   if state.get('state')not in ['acknowledged','verified']:raise RuntimeError(name+': '+str(state))
  p['network_mode']=1;api('mobility',p);print('High-performance mode / ACS requested',flush=True)
  deadline=time.monotonic()+150
  while time.monotonic()<deadline:
   j=api('mobility/scan')
   if j.get('state')in ['completed','failed','interrupted']:break
   time.sleep(2)
  evidence['scan']=j;evidence['after']=api('aps')
  if j.get('state')!='completed':raise RuntimeError('ACS: '+j.get('error',str(j)))
  print('AP scan report, channel plan and configuration commit passed',flush=True)
 except Exception as exc:evidence['error']=str(exc);raise
 finally:
  if original is not None:
   try:api('mobility',original)
   except Exception as exc:evidence.setdefault('restore_errors',[]).append(str(exc))
  elif radios is not None:
   # Backup restore is the only public API that preserves an absent policy.
   try:
    backup=api('backup');backup['config'].pop('mobility',None);api('restore',backup)
   except Exception as exc:evidence.setdefault('restore_errors',[]).append(str(exc))
  if radios is not None:
   for r in radios:
    try:api('radios',r)
    except Exception as exc:evidence.setdefault('restore_errors',[]).append(str(exc))
  evidence['ended']=datetime.datetime.now().isoformat();path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S')+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2));path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
