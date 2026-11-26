#!/usr/bin/env python3
"""Verify AP-side ARP filtering using the actual tablet on the isolated lab.
A matching binding must allow traffic; a deliberate mismatching binding must
block fresh ARP resolution. Original policy is restored even when a check fails.
"""
import argparse,datetime,json,pathlib,re,subprocess,time,urllib.request
from adb_wifi_ui import WiFiUI
ROOT=pathlib.Path(__file__).resolve().parents[1]
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--serial',required=True);p.add_argument('--case',choices=('arp','dhcp'),default='arp');args=p.parse_args();ui=WiFiUI(args.serial)
 evidence={'case':args.case,'started':datetime.datetime.now().isoformat(),'steps':[]};out=ROOT/'.local/ac100/protection-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700)
 def api(path,body=None):
  q=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
  with urllib.request.urlopen(q,timeout=25)as r:return json.load(r)
 ap=next(a for a in api('aps')if a['online']);original=api('config')['config'].get('protection')or {'servers':[],'bindings':[],'rules':[]};status=ui.shell('cmd','wifi','status');assert 'SSID: "GoAC-Lab"'in status
 mac=re.search(r' MAC: ([0-9a-f:]+)',status)[1];ip=re.search(r'IP: /([0-9.]+)',status)[1];assert ip.startswith('192.168.70.');assert ap['features']['arp_defense'];changed=False
 def apply(policy,label):
  nonlocal changed
  since=time.time();api('protection',policy);changed=True;end=time.monotonic()+100
  while time.monotonic()<end:
   states=api('config')['apply'];bad=next((s for s in states if s['service_id']=='protection'and s['state']=='failed'and datetime.datetime.fromisoformat(s['at']).timestamp()>=since),None)
   if bad:raise RuntimeError(bad['error'])
   st=next((s for s in states if s['service_id']=='configuration-commit'and s['ap_id']==ap['id']),None)
   if st and st['state']=='acknowledged'and datetime.datetime.fromisoformat(st['at']).timestamp()>=since and time.time()-datetime.datetime.fromisoformat(st['at']).timestamp()>13:evidence['steps'].append({'label':label,'commit':st});return
   time.sleep(1)
  raise RuntimeError('Protection commit did not settle')
 def cycle(wait=True):
  ui.shell('cmd','wifi','set-wifi-enabled','disabled');time.sleep(2);ui.shell('cmd','wifi','set-wifi-enabled','enabled')
  if not wait:return
  end=time.monotonic()+70
  while time.monotonic()<end:
   if ui.is_connected('GoAC-Lab'):return
   time.sleep(1)
  raise RuntimeError('Tablet association/address did not recover')
 def internet():
  return ui.shell('curl','--interface','wlan0','--connect-timeout','5','--max-time','12','-sS','-o','/dev/null','-w','%{http_code}','https://www.baidu.com').strip()=='200'
 def arp_probe():
  v=subprocess.run(['sudo','-n','python3',str(ROOT/'tools/lab_arp_probe.py'),'--iface','enxc817f5dd9eb9','--target',ip,'--mac',mac],capture_output=True,text=True,timeout=12)
  if v.returncode:raise RuntimeError(v.stderr or v.stdout)
  return json.loads(v.stdout)
 def policy(address,wrong_gateway=False):
  # Legacy boolean-only APs cannot select wireless-only protection: include
  # the lab gateway's binding too, so its ARP replies can reach the client.
  gateway=(pathlib.Path('/sys/class/net/enxc817f5dd9eb9/address').read_text().strip())
  return {'servers':[],'bindings':[{'id':'lab-tablet','name':'Lab tablet','ip':address,'mac':mac,'description':'Temporary ARP validation'},{'id':'lab-gateway','name':'Lab gateway','ip':'192.168.70.241'if wrong_gateway else'192.168.70.1','mac':gateway,'description':'Required for legacy AP port scope'}],'rules':[{'id':'lab-only','name':'Lab ARP test','aps':[ap['id']],'groups':[],'dhcp':False,'servers':[],'arp':True,'bindings':['lab-tablet','lab-gateway'],'filter':True,'wired':True,'wireless':True}]}
 try:
  if args.case=='arp':
   apply(policy(ip),'matching binding');cycle();assert internet(),'Correct binding blocked traffic';evidence['matching_arp']=arp_probe();assert evidence['matching_arp']['replies']>0,'Matching ARP binding did not pass actual ARP replies';print('Matching ARP binding: actual client HTTPS and ARP replies passed',flush=True)
   # This AP's legacy bridge hook excludes host WLAN interfaces. Probe its
   # wired ingress by mismatching the ARP request sender's gateway binding.
   apply(policy(ip,True),'mismatched wired sender binding');evidence['mismatched_arp']=arp_probe()
   try:evidence['cached_neighbor_https']=internet()
   except RuntimeError as e:evidence['blocked_error']=str(e)
   evidence['neighbor_state']=ui.shell('ip','neigh','show','192.168.70.1','dev','wlan0')
   assert evidence['mismatched_arp']['replies']==0,'AP acknowledged ARP filter but mismatched wired sender probes still passed';print('Mismatched wired ARP binding: probes blocked by AP',flush=True)
  else:
   assert ap['features']['dhcp_defense']
   def dhcp_policy(address):
    return {'servers':[{'id':'lab-server','name':'Lab DHCP server','address':address}],'bindings':[],'rules':[{'id':'lab-only','name':'Lab DHCP test','aps':[ap['id']],'groups':[],'dhcp':True,'servers':['lab-server'],'arp':False,'bindings':[],'wired':True,'wireless':True}]}
   apply(dhcp_policy('192.168.70.1'),'trusted DHCP server');cycle();assert internet(),'Trusted DHCP server did not allow connection';print('Trusted DHCP server: actual address and HTTPS passed',flush=True)
   apply(dhcp_policy('192.168.70.240'),'untrusted DHCP server');cycle(False);deadline=time.monotonic()+45;associated=False
   while time.monotonic()<deadline:
    status=ui.shell('cmd','wifi','status');associated=associated or ('SSID: "GoAC-Lab"'in status and 'Supplicant state: COMPLETED'in status);time.sleep(2)
   evidence['dhcp_rejected_wifi']=ui.shell('cmd','wifi','status');evidence['dhcp_rejected_address']=ui.shell('ip','-4','addr','show','dev','wlan0')
   assert associated,'Client never associated; cannot attribute failure to DHCP protection'
   assert 'inet 'not in evidence['dhcp_rejected_address'],'Untrusted DHCP replies still produced an IPv4 address'
   assert next(a for a in api('aps')if a['id']==ap['id'])['online'],'AP lost control connectivity during DHCP test'
   print('Untrusted DHCP server: association happened but no IPv4 lease reached client',flush=True)
 except Exception as e:evidence['error']=str(e);raise
 finally:
  if changed:
   try:apply(original,'restore original protection');cycle();assert internet(),'Internet not restored';evidence['restored']=True
   except Exception as e:evidence['restore_error']=str(e)
  path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S-')+args.case+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
