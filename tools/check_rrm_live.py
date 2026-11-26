#!/usr/bin/env python3
"""Run a bounded single-AP NDP measurement, restore lab configuration, retain private evidence."""
import copy,datetime,json,pathlib,time,urllib.request,urllib.error,subprocess
ROOT=pathlib.Path(__file__).resolve().parents[1]
def api(path,body=None):
 req=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
 with urllib.request.urlopen(req,timeout=30)as r:return json.load(r)
def main():
 evidence={'started':datetime.datetime.now().isoformat()};out=ROOT/'.local/ac100/rrm-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700)
 original=None;rules=None
 try:
  deadline=time.monotonic()+100
  while time.monotonic()<deadline:
   online=[a for a in api('aps')if a['online']]
   if online and any(s['service_id']=='configuration-commit'for s in api('config')['apply']):break
   time.sleep(2)
  if not online:raise RuntimeError('AP did not reconnect')
  ap=online[0];evidence['before']=ap;original=copy.deepcopy(api('config')['config']['radios']);rules=copy.deepcopy(api('rrm')['rules']or[])
  # Restore the logical automatic GI after the regression fix; actual native value must be 0.
  for row in original:
   if row['ap_id']==ap['id']and row['radio_id']==2:row['advanced']['gi_mode']=-1;api('radios',row)
  time.sleep(18)
  r=api('rrm')['defaults'];r.update(id='live-ndp-check',name='单 AP 测量验证',frequency=1,optimize_power=False,enabled=False,aps=[ap['id']],groups=[]);r['2g'].update(channels=[6],bandwidth=0);api('rrm/rules',rules+[r]);time.sleep(18)
  job=api('rrm/run',{'rule_id':r['id']});evidence['job']=job;print('NDP job started:',job['id'],flush=True)
  deadline=time.monotonic()+200
  while time.monotonic()<deadline:
   state=api('rrm')['jobs'][job['id']]
   if state['state']in ['completed','failed']:break
   time.sleep(2)
  evidence['result']=state;evidence['after']=api('aps')
  if state['state']!='completed':raise RuntimeError('NDP workflow: '+state.get('error',state['state']))
  print('NDP measurement, plan, AP readback and commit completed',flush=True)
 except Exception as e:evidence['error']=str(e);raise
 finally:
  if original is not None:
   for row in original:
    try:api('radios',row)
    except Exception as e:evidence.setdefault('restore_errors',[]).append(str(e))
  if rules is not None:
   try:api('rrm/rules',rules)
   except Exception as e:evidence.setdefault('restore_errors',[]).append(str(e))
  evidence['ended']=datetime.datetime.now().isoformat();p=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S')+'.json');p.write_text(json.dumps(evidence,ensure_ascii=False,indent=2));p.chmod(0o600);print('Private evidence:',p,flush=True)
if __name__=='__main__':main()
