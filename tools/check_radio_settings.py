#!/usr/bin/env python3
"""Change one supported radio setting at a time and restore it on the real AP.

Requires the isolated lab. Checks Go's actual AP model readback (verified),
never counts an ACK alone as proof. Stores private evidence and restores both
original radio profiles even on failure. Does not flash firmware or reset APs.
"""
import argparse,copy,datetime,json,pathlib,subprocess,time,urllib.request

ROOT=pathlib.Path(__file__).resolve().parents[1]
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--serial',required=True);p.add_argument('--after',help='Resume after a previously verified parameter');args=p.parse_args()
 out=ROOT/'.local/ac100/radio-setting-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700)
 def api(path,body=None):
  req=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
  with urllib.request.urlopen(req,timeout=30)as r:return json.load(r)
 ap=next(a for a in api('aps')if a['online']);cfg=api('config')['config'];original=[r for r in cfg['radios']if r['ap_id']==ap['id']]
 if len(original)!=2 or any(not r.get('advanced')for r in original):raise RuntimeError('Requires two explicit lab radio profiles')
 evidence={'started':datetime.datetime.now().isoformat(),'ap_id':ap['id'],'original':original,'steps':[]}
 def apply(row,label):
  current=api('config');existing=next((r for r in current['config']['radios']if r['ap_id']==row['ap_id']and r['radio_id']==row['radio_id']),None)
  st=next((s for s in current['apply']if s['ap_id']==ap['id']and s['service_id']=='radio:'+str(row['radio_id'])),None)
  if existing==row and st and st['state']=='verified':
   evidence['steps'].append({'label':label,'requested':row,'status':st,'already_verified':True});return
  since=datetime.datetime.now(datetime.timezone.utc);api('radios',row);end=time.monotonic()+45
  while time.monotonic()<end:
   st=next((s for s in api('config')['apply']if s['ap_id']==ap['id']and s['service_id']=='radio:'+str(row['radio_id'])),None)
   if st and datetime.datetime.fromisoformat(st['at'])>=since and st['state']in ['verified','failed','failed_recovered']:
    evidence['steps'].append({'label':label,'requested':row,'status':st})
    if st['state']!='verified':raise RuntimeError(label+': '+st.get('error',st['state']))
    print(label+': AP model readback verified',flush=True);return
   time.sleep(.5)
  raise RuntimeError(label+': radio readback timeout')
 # Every case is independent, using the original profile as its starting point.
 changes=[(1,'mode',10),(2,'mode',11),(1,'bandwidth',0),(2,'bandwidth',3),(2,'max_clients',255),(2,'wmm',False),(2,'short_gi',False),(2,'broadcast_probe',False),(2,'fragmentation',1024),(2,'rts',1024),(2,'beacon_interval',110),(2,'dtim',2),(2,'management_rate',12),(2,'rssi_restrict',True),(2,'rssi_kick',True),(2,'twt',True),(2,'gi_mode',0),(2,'gi_mode',1),(2,'gi_mode',2)]
 if args.after:
  index=next(i for i,(_,key,_)in enumerate(changes)if key==args.after);changes=changes[index+1:]
 try:
  for radio,key,value in changes:
   base=next(r for r in original if r['radio_id']==radio);row=copy.deepcopy(base);row['advanced'][key]=value
   if key=='wmm'and not value:row['advanced']['mode']=0;row['advanced']['bandwidth']=0
   if key=='rssi_restrict':row['advanced']['rssi_threshold']=-90
   if key=='rssi_kick':row['advanced']['rssi_kick_threshold']=-95
   apply(row,'radio '+str(radio)+' '+key+'='+str(value));apply(base,'restore '+key)
  for key,value in [('channel',36),('power_dbm',26)]:
   base=next(r for r in original if r['radio_id']==2);row=copy.deepcopy(base);row[key]=value;row.pop('power_level',None);apply(row,key+'='+str(value));apply(base,'restore '+key)
  for key in ['mimo','ofdma']:
   base=next(r for r in original if r['radio_id']==2);row=copy.deepcopy(base)
   for field in (['downlink_mumimo','uplink_mumimo']if key=='mimo'else['downlink_ofdma','uplink_ofdma']):row['advanced'][field]=not base['advanced'][field]
   apply(row,'toggle '+key);apply(base,'restore '+key)
  time.sleep(15)
  r=subprocess.run(['python3',str(ROOT/'tools/check_adb_wifi.py'),'cycle','--serial',args.serial],text=True,capture_output=True,timeout=240);evidence['client_regression']=r.stdout
  if r.returncode:raise RuntimeError(r.stderr)
 except Exception as e:evidence['error']=str(e);raise
 finally:
  for row in original:
   try:apply(row,'final restore')
   except Exception as e:evidence.setdefault('restore_errors',[]).append(str(e))
  path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S')+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
