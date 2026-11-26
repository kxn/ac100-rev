#!/usr/bin/env python3
"""Test AP self-management with Go stopped, then restore AC and AP settings.
Only the isolated lab AP and the authorized tablet are used. Lab DHCP/DNS/NAT
stay running so loss of the controller is tested separately from IP routing.
"""
import argparse,copy,datetime,json,pathlib,re,subprocess,time,urllib.request
from adb_wifi_ui import WiFiUI
ROOT=pathlib.Path(__file__).resolve().parents[1]
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--serial',required=True);p.add_argument('--enabled',choices=('true','false'),required=True);a=p.parse_args();enabled=a.enabled=='true';ui=WiFiUI(a.serial)
 def unit(action):
  r=subprocess.run(['sudo','-n','systemctl',action,'ac100-go'],capture_output=True,text=True,timeout=25)
  if r.returncode:raise RuntimeError(r.stderr or r.stdout)
 def api(path,body=None):
  req=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
  with urllib.request.urlopen(req,timeout=20)as response:return json.load(response)
 def online():
  end=time.monotonic()+120
  while time.monotonic()<end:
   try:
    if any(ap['id']==ap_id and ap['online']for ap in api('aps')):return
   except Exception:pass
   time.sleep(1)
  raise RuntimeError('AP did not reconnect to restarted Go controller')
 def internet():
  try:return ui.shell('curl','--interface','wlan0','--connect-timeout','5','--max-time','12','-sS','-o','/dev/null','-w','%{http_code}','https://www.baidu.com').strip()=='200'
  except RuntimeError:return False
 if subprocess.run(['systemctl','is-active','--quiet','ac100-go'],capture_output=True).returncode:raise RuntimeError('Requires active managed Go service')
 ap=next(ap for ap in api('aps')if ap['online']);ap_id=ap['id'];original=copy.deepcopy(next((p for p in api('config')['config'].get('ap_profiles',[])if p['ap_id']==ap_id),{'name':ap.get('name',''),'location':ap.get('location',''),'group_id':'','template_id':'','options':{}}));original.pop('ap_id',None)
 out=ROOT/'.local/ac100/offline-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700);evidence={'enabled':enabled,'started':datetime.datetime.now().isoformat(),'steps':[]};changed=False;stopped=False
 def apply(profile):
  since=time.time();api('aps/'+ap_id+'/settings',profile);deadline=time.monotonic()+100
  while time.monotonic()<deadline:
   st=next((s for s in api('config')['apply']if s['ap_id']==ap_id and s['service_id']=='configuration-commit'),None)
   if st and st['state']=='acknowledged'and datetime.datetime.fromisoformat(st['at']).timestamp()>=since and time.time()-datetime.datetime.fromisoformat(st['at']).timestamp()>13:return
   time.sleep(1)
  raise RuntimeError('AP configuration did not settle')
 try:
  profile=copy.deepcopy(original);profile['options']={**profile.get('options',{}),'echo_seconds':5,'echo_misses':2,'offline_self_manage':enabled};changed=True;apply(profile);assert internet(),'Baseline internet failed before stopping AC'
  stopped=True;unit('stop');at=time.monotonic();evidence['ac_stopped_at']=datetime.datetime.now().isoformat()
  for offset in (5,20,40):
   while time.monotonic()-at<offset:time.sleep(.5)
   evidence['steps'].append({'after_seconds':round(time.monotonic()-at,1),'existing_client_https':internet()})
  ui.shell('cmd','wifi','set-wifi-enabled','disabled');time.sleep(2);ui.shell('cmd','wifi','set-wifi-enabled','enabled');deadline=time.monotonic()+65;connected=False
  while time.monotonic()<deadline:
   if ui.is_connected('GoAC-Lab')and internet():connected=True;break
   time.sleep(2)
  evidence['new_client_https']=connected;evidence['offline_wifi_status']=ui.shell('cmd','wifi','status');evidence['ac_still_stopped']=subprocess.run(['systemctl','is-active','--quiet','ac100-go'],capture_output=True).returncode!=0
  assert evidence['ac_still_stopped'],'Go unexpectedly restarted during offline test'
  assert connected==enabled,'Actual fresh association disagreed with configured offline self-management'
  print('AC stopped: existing connections recorded; new association/HTTPS '+('passed with self-management enabled'if connected else'was denied with self-management disabled'),flush=True)
 except Exception as e:evidence['error']=str(e);raise
 finally:
  if stopped:
   try:unit('start');online();stopped=False
   except Exception as e:evidence['restart_error']=str(e)
  if changed and not stopped:
   try:
    # Restore the defaults on the AP before removing temporary overrides.
    profile=copy.deepcopy(original);profile['options']={'echo_seconds':20,'echo_misses':5,'offline_self_manage':False,**original.get('options',{})};apply(profile);apply(original)
   except Exception as e:evidence['restore_settings_error']=str(e)
  if not stopped:
   try:ui.connect('GoAC-Lab');assert internet(),'Restored baseline has no internet';evidence['restored']=True
   except Exception as e:evidence['restore_wifi_error']=str(e)
  try:ui.shell('rm','-f','/sdcard/goac-ui.xml')
  except Exception:pass
  path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S-')+a.enabled+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
