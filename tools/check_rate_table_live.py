#!/usr/bin/env python3
"""Measure an actual 11ax rate-table change, independently of traffic shaping.
Temporarily uses only the AP's 5GHz radio in AX/20MHz, constrains AX to index0,
then restores the rate policy, radio settings and normal tablet connectivity.
"""
import argparse,copy,datetime,http.server,json,pathlib,re,threading,time,urllib.request
from adb_wifi_ui import WiFiUI
from check_wireless_data import Payload
ROOT=pathlib.Path(__file__).resolve().parents[1]
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--serial',required=True);a=p.parse_args();ui=WiFiUI(a.serial)
 def api(path,body=None):
  q=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
  with urllib.request.urlopen(q,timeout=25)as r:return json.load(r)
 ap=next(ap for ap in api('aps')if ap['online']);cfg=api('config')['config'];original=copy.deepcopy([r for r in cfg['radios']if r['ap_id']==ap['id']]);policy=api('rates')
 if len(original)!=2 or not all(r.get('advanced')for r in original):raise RuntimeError('Requires the configured dual-radio lab AP')
 if any(((s.get('options')or{}).get('rate_limit')or{}).get('enabled')for s in cfg['services']):raise RuntimeError('Disable traffic shaping before testing PHY rate tables')
 out=ROOT/'.local/ac100/rate-table-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700);evidence={'started':datetime.datetime.now().isoformat(),'steps':[]};changed=False;server=None
 def settled(since):
  deadline=time.monotonic()+100
  while time.monotonic()<deadline:
   st=next((s for s in api('config')['apply']if s['ap_id']==ap['id']and s['service_id']=='configuration-commit'),None)
   if st and st['state']=='acknowledged'and datetime.datetime.fromisoformat(st['at']).timestamp()>=since and time.time()-datetime.datetime.fromisoformat(st['at']).timestamp()>13:return
   time.sleep(1)
  raise RuntimeError('Configuration did not settle')
 def cycle():
  ui.shell('cmd','wifi','set-wifi-enabled','disabled');time.sleep(2);ui.shell('cmd','wifi','set-wifi-enabled','enabled');end=time.monotonic()+70
  while time.monotonic()<end:
   if ui.is_connected('GoAC-Lab'):
    status=ui.shell('cmd','wifi','status')
    if int(re.search(r'Frequency: (\d+)MHz',status)[1])>4900:return status
   time.sleep(1)
  raise RuntimeError('Tablet did not rejoin 5GHz')
 def measure(label):
  status=cycle();output=ui.shell('curl','--interface','wlan0','--connect-timeout','5','--max-time','55','-sS','-o','/dev/null','-w','%{http_code} %{speed_download}','http://192.168.70.1:32080/payload').strip().split();assert output[0]=='200'
  v=float(output[1])*8/1e6;evidence['steps'].append({'label':label,'wifi_status':status,'download_mbps':v});print(label+': '+str(round(v,3))+' Mbps',flush=True);return v
 try:
  server=http.server.ThreadingHTTPServer(('192.168.70.1',32080),Payload);threading.Thread(target=server.serve_forever,daemon=True).start()
  since=time.time();changed=True
  for base in original:
   row=copy.deepcopy(base)
   if row['radio_id']==1:row['enabled']=False
   else:row['advanced']['mode']=11;row['advanced']['bandwidth']=0;row['advanced']['wmm']=True;row['enabled']=True
   api('radios',row)
  settled(since);baseline=measure('AX20 baseline');assert baseline>20,'Baseline too low for a meaningful rate comparison'
  limited=copy.deepcopy(policy);limited['enabled']=True;limited['aps']=[ap['id']];limited['groups']=[];limited['11ax']['supported']=0;since=time.time();api('rates',limited);settled(since);speed=measure('AX supported index0')
  assert .3<speed<20 and speed<baseline/3,'11ax rate table did not constrain measured downlink'
  since=time.time();api('rates',policy);settled(since);restored=measure('Restored AX rates');assert restored>20 and restored>speed*3,'Original rate table did not restore throughput'
 except Exception as e:evidence['error']=str(e);raise
 finally:
  if changed:
   try:
    since=time.time();api('rates',policy)
    for row in original:api('radios',row)
    settled(since);cycle();assert ui.shell('curl','--interface','wlan0','--connect-timeout','5','--max-time','12','-sS','-o','/dev/null','-w','%{http_code}','https://www.baidu.com').strip()=='200';evidence['restored']=True
   except Exception as e:evidence['restore_error']=str(e)
  if server:server.shutdown();server.server_close()
  path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S')+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
