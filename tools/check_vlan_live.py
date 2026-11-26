#!/usr/bin/env python3
"""Reversible fixed WLAN VLAN test on the isolated USB AP link.
Creates a temporary VLAN100 DHCP/HTTP lab endpoint, joins a temporary SSID,
then removes the SSID, saved tablet network, service and host VLAN interface.
No upstream route, NAT, DNS or host firewall change is made.
"""
import argparse,datetime,http.server,json,pathlib,re,subprocess,threading,time,urllib.request
from adb_wifi_ui import WiFiUI
ROOT=pathlib.Path(__file__).resolve().parents[1]
NIC='enxc817f5dd9eb9';VIF='goac-vlan100';UNIT='goac-vlan-validation';SSID='GoAC-VLAN-Test'
class Payload(http.server.BaseHTTPRequestHandler):
 def log_message(self,*a):pass
 def do_GET(self):
  data=b'GoAC VLAN100 data path verified\n';self.send_response(200);self.send_header('Content-Length',str(len(data)));self.end_headers();self.wfile.write(data)
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--serial',required=True);a=p.parse_args();ui=WiFiUI(a.serial)
 def run(*words):
  p=subprocess.run(words,capture_output=True,text=True,timeout=20)
  if p.returncode:raise RuntimeError(p.stderr or p.stdout)
  return p.stdout
 def api(path,body=None,method=None):
  r=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'},method=method)
  with urllib.request.urlopen(r,timeout=25)as response:return json.load(response)
 ap=next(ap for ap in api('aps')if ap['online']);baseline=next(s for s in api('config')['config']['services']if s['ssid']=='GoAC-Lab');assert baseline['enabled']
 nic=pathlib.Path('/sys/class/net')/NIC
 if '/usb'not in str((nic/'device').resolve())or(nic/'master').exists()or(pathlib.Path('/sys/class/net')/VIF).exists():raise RuntimeError('Requires an isolated USB link and unused lab VLAN interface')
 if subprocess.run(['systemctl','is-active','--quiet',UNIT],capture_output=True).returncode==0:raise RuntimeError('Temporary VLAN unit already active')
 out=ROOT/'.local/ac100/vlan-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700)
 evidence={'started':datetime.datetime.now().isoformat(),'vlan':100};created=False;service=None;disabled=False;server=None;started=False
 cfg=out/'dnsmasq-vlan100.conf'
 def settled(since):
  end=time.monotonic()+100
  while time.monotonic()<end:
   st=next((s for s in api('config')['apply']if s['ap_id']==ap['id']and s['service_id']=='configuration-commit'),None)
   if st and st['state']=='acknowledged'and datetime.datetime.fromisoformat(st['at']).timestamp()>=since and time.time()-datetime.datetime.fromisoformat(st['at']).timestamp()>13:return
   time.sleep(1)
  raise RuntimeError('WLAN commit did not settle')
 try:
  run('sudo','-n','ip','link','add','link',NIC,'name',VIF,'type','vlan','id','100');created=True
  run('sudo','-n','ip','addr','add','192.168.100.1/24','dev',VIF);run('sudo','-n','ip','link','set',VIF,'up')
  cfg.write_text(f'port=0\ninterface={VIF}\nbind-interfaces\ndhcp-authoritative\ndhcp-range=192.168.100.50,192.168.100.80,255.255.255.0,10m\ndhcp-option=3\ndhcp-option=6\ndhcp-leasefile={out}/dhcp.leases\nlog-dhcp\nlog-facility=-\n');cfg.chmod(0o600)
  run('sudo','-n','systemd-run','--quiet','--collect','--unit='+UNIT,'/usr/sbin/dnsmasq','--keep-in-foreground','--conf-file='+str(cfg));started=True;time.sleep(1)
  if run('systemctl','is-active',UNIT).strip()!='active':raise RuntimeError('VLAN DHCP service did not start')
  server=http.server.ThreadingHTTPServer(('192.168.100.1',32081),Payload);threading.Thread(target=server.serve_forever,daemon=True).start()
  since=time.time();service=api('services',{'ssid':SSID,'security':'wpa2-psk','passphrase':'GoAC-Test1234','enabled':True,'auto_bind_frequencies':256,'aps':[ap['id']],'radios':[],'options':{'auth':2,'cipher':2,'vlan':100,'key_update_interval':86400}})['service'];settled(since)
  row=dict(baseline);row['enabled']=False;since=time.time();api('services',row);disabled=True;settled(since)
  ui.connect(SSID,'GoAC-Test1234');status=ui.shell('cmd','wifi','status');evidence['wifi_status']=status
  ip=re.search(r'IP: /([0-9.]+)',status)[1];mac=re.search(r' MAC: ([0-9a-f:]+)',status)[1];assert ip.startswith('192.168.100.'),'Client address did not come from VLAN100'
  evidence['http']=ui.shell('curl','--interface','wlan0','--connect-timeout','5','--max-time','12','-sS','http://192.168.100.1:32081/').strip();assert evidence['http']=='GoAC VLAN100 data path verified'
  end=time.monotonic()+90
  while time.monotonic()<end:
   station=next((c for c in api('clients')if c['mac']==mac and c['state']=='connected'),None)
   if station and station.get('ssid')==SSID and station.get('vlan_id')==100 and station['ip']==ip:evidence['station']=station;break
   time.sleep(1)
  else:raise RuntimeError('AC did not display actual SSID/VLAN/IP from AP')
  print('VLAN100: tablet DHCP, actual tagged data path and AC client VLAN/SSID/IP passed',flush=True)
  evidence['forgot_temporary_network']=ui.forget(SSID)
 except Exception as e:evidence['error']=str(e);raise
 finally:
  if disabled:
   try:since=time.time();api('services',baseline);settled(since)
   except Exception as e:evidence['restore_service_error']=str(e)
  try:
   ui.shell('input','keyevent','4');ui.connect('GoAC-Lab');assert ui.shell('curl','--interface','wlan0','--connect-timeout','5','--max-time','12','-sS','-o','/dev/null','-w','%{http_code}','https://www.baidu.com').strip()=='200';evidence['baseline_restored']=True
  except Exception as e:evidence['restore_wifi_error']=str(e)
  if service:
   try:
    since=time.time();api('services/'+service['id'],method='DELETE');settled(since);deadline=time.monotonic()+45
    while any(s['id']==service['id']for s in api('config')['config']['services']):
     if time.monotonic()>deadline:raise RuntimeError('WLAN deletion incomplete')
     time.sleep(1)
   except Exception as e:evidence['cleanup_service_error']=str(e)
  if server:server.shutdown();server.server_close()
  if started:subprocess.run(['sudo','-n','systemctl','stop',UNIT],capture_output=True)
  if created:
   removed=subprocess.run(['sudo','-n','ip','link','delete',VIF],capture_output=True,text=True)
   if removed.returncode:evidence['cleanup_interface_error']=removed.stderr
  try:ui.shell('rm','-f','/sdcard/goac-ui.xml')
  except Exception:pass
  path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S')+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
