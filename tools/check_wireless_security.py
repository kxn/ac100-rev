#!/usr/bin/env python3
"""Join a temporary wireless service with the actual ADB tablet, then clean up.
The baseline service is retained; temporary services are removed in finally.
"""
import argparse,datetime,json,pathlib,re,time,urllib.request
from adb_wifi_ui import WiFiUI
ROOT=pathlib.Path(__file__).resolve().parents[1]
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--serial',required=True);p.add_argument('--case',choices=('open','mixed','hidden','psk-change'),required=True);args=p.parse_args();ui=WiFiUI(args.serial)
 out=ROOT/'.local/ac100/security-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700);evidence={'case':args.case,'started':datetime.datetime.now().isoformat()};service=None;baseline_disabled=False;baseline=None
 def api(path,body=None,method=None):
  q=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'},method=method)
  with urllib.request.urlopen(q,timeout=25)as r:return json.load(r)
 def settled(since):
  end=time.monotonic()+100
  while time.monotonic()<end:
   states=api('config')['apply'];a=next((s for s in states if s['service_id']=='configuration-commit'),None)
   if a and a['state']=='acknowledged'and datetime.datetime.fromisoformat(a['at']).timestamp()>=since and time.time()-datetime.datetime.fromisoformat(a['at']).timestamp()>13:return
   time.sleep(1)
  raise RuntimeError('Service commit did not settle')
 def activate_hidden():
  nonlocal baseline_disabled,baseline
  baseline=next(s for s in api('config')['config']['services']if s['ssid']=='GoAC-Lab');row=dict(baseline);row['enabled']=False;since=time.time();api('services',row);baseline_disabled=True;settled(since)
 try:
  ssid={'open':'GoAC-Open-Test','mixed':'GoAC-Mixed-Test','hidden':'GoAC-Hidden-Test','psk-change':'GoAC-Key-Test'}[args.case]
  existing=next((s for s in api('config')['config']['services']if s['ssid']==ssid),None)
  until=time.monotonic()+60
  while existing and existing.get('deleting'):
   if time.monotonic()>until:raise RuntimeError('Previous temporary service cleanup is still pending')
   time.sleep(1);existing=next((s for s in api('config')['config']['services']if s['ssid']==ssid),None)
  if existing:service=existing;settled(0)
  else:
   row={'ssid':ssid,'security':{'open':'open','mixed':'wpa2-wpa3-psk','hidden':'wpa2-psk','psk-change':'wpa2-psk'}[args.case],'enabled':True,'auto_bind_frequencies':256,'radios':[],'aps':[]}
   if args.case!='open':row.update(passphrase='GoAC-Test1234',hidden=args.case=='hidden',options={'auth':3 if args.case=='mixed'else 2,'cipher':2,'key_update_interval':86400})
   since=time.time();service=api('services',row)['service'];settled(since)
  evidence['service_id']=service['id']
  if args.case=='hidden':ui.add_hidden(ssid,'GoAC-Test1234',activate_hidden)
  else:ui.connect(ssid,None if args.case=='open'else'GoAC-Test1234')
  status=ui.shell('cmd','wifi','status');evidence['wifi_status']=status;frequency=int(re.search(r'Frequency: (\d+)MHz',status)[1]);assert frequency>4900,'Automatic 5GHz binding did not hold'
  evidence['https']=ui.shell('curl','--interface','wlan0','--connect-timeout','10','--max-time','20','-sS','-o','/dev/null','-w','%{http_code}','https://www.baidu.com').strip();assert evidence['https']=='200','No HTTPS'
  mac=re.search(r' MAC: ([0-9a-f:]+)',status)[1];end=time.monotonic()+90
  while time.monotonic()<end:
   clients=api('clients');station=next((s for s in clients if s['mac']==mac and s['state']=='connected'),None)
   if station and station['radio_id']==2 and station['wlan_id']==api('config')['assignments'].get(station['ap_id'],{}).get(service['id'],{}).get('2'):evidence['station']=station;break
   time.sleep(1)
  else:raise RuntimeError('AC did not display the connected test service correctly')
  if args.case=='psk-change':
   activate_hidden() # Temporarily disable Lab so fallback cannot mask failure.
   row=next(s for s in api('config')['config']['services']if s['id']==service['id']);row['passphrase']='GoAC-Test5678';since=time.time();api('services',row);settled(since)
   ui.shell('cmd','wifi','set-wifi-enabled','disabled');time.sleep(2);ui.shell('cmd','wifi','set-wifi-enabled','enabled');end=time.monotonic()+25;old_key_worked=False
   while time.monotonic()<end:
    old_key_worked=old_key_worked or ui.is_connected(ssid);time.sleep(1)
   evidence['old_key_rejected']=not old_key_worked
   assert not old_key_worked,'Client still associated using saved old PSK after credential change'
   ui.forget(ssid);ui.connect(ssid,'GoAC-Test5678');evidence['new_key_wifi_status']=ui.shell('cmd','wifi','status');evidence['new_key_https']=ui.shell('curl','--interface','wlan0','--connect-timeout','10','--max-time','20','-sS','-o','/dev/null','-w','%{http_code}','https://www.baidu.com').strip();assert evidence['new_key_https']=='200','New PSK did not restore actual internet'
  print(args.case+': actual tablet 5GHz association, HTTPS and AC client identity passed',flush=True)
  evidence['forgot_temporary_network']=ui.forget(ssid)
 except Exception as e:
  evidence['error']=str(e);evidence['failure_wifi_status']=ui.shell('cmd','wifi','status');evidence['failure_apply']=api('config')['apply'];raise
 finally:
  if baseline_disabled:
   try:since=time.time();api('services',baseline);settled(since)
   except Exception as e:evidence['restore_service_error']=str(e)
  if args.case=='psk-change'and service and not evidence.get('forgot_temporary_network'):
   try:evidence['forgot_temporary_network']=ui.forget('GoAC-Key-Test')
   except Exception as e:evidence['forget_error']=str(e)
  try:ui.shell('input','keyevent','4');ui.connect('GoAC-Lab')
  except Exception as e:evidence['restore_wifi_error']=str(e)
  if service:
   try:
    since=time.time();api('services/'+service['id'],method='DELETE');settled(since)
    end=time.monotonic()+45
    while any(s['id']==service['id']for s in api('config')['config']['services']):
     if time.monotonic()>end:raise RuntimeError('Temporary service deletion did not finish')
     time.sleep(1)
   except Exception as e:evidence['cleanup_error']=str(e)
  try:ui.shell('rm','-f','/sdcard/goac-ui.xml')
  except Exception:pass
  path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S-')+args.case+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
