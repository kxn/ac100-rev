#!/usr/bin/env python3
"""Reversibly validate AP-only Go DHCP against the physical AP on the lab NIC.
Leaves DNS running, temporarily gives UDP67 exclusively to Go, then restores
normal client DHCP. Must run as root; never modifies upstream networking.
"""
import datetime,json,os,pathlib,subprocess,time,urllib.request
ROOT=pathlib.Path(__file__).resolve().parents[1];WORK=ROOT/'.local/ac100';NIC='enxc817f5dd9eb9'
def run(*a):return subprocess.run(a,check=True,capture_output=True,text=True).stdout
def api(path,body=None):
 req=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
 with urllib.request.urlopen(req,timeout=30)as r:return json.load(r)
def main():
 if os.geteuid()!=0:raise SystemExit('Requires root for temporary DHCP service and packet capture')
 out=WORK/'dhcp-live-tests'/datetime.datetime.now().strftime('%Y%m%d-%H%M%S');out.mkdir(parents=True,mode=0o700)
 config=WORK/'ap-direct/dnsmasq.conf';original=config.read_bytes();capture=None;unit='ac100-dhcp-validation';result={'started':datetime.datetime.now().isoformat()}
 lease=out/'go-leases.json';cfg=out/'go-dhcp.json';cfg.write_text(json.dumps({'interface':NIC,'server':'192.168.70.1','start':'192.168.70.50','end':'192.168.70.50','netmask':'255.255.255.0','gateway':'192.168.70.1','dns':['192.168.70.1'],'ac':['192.168.70.1'],'lease_seconds':3600,'lease_file':str(lease)}))
 try:
  deadline=time.monotonic()+100
  while time.monotonic()<deadline:
   online=[a for a in api('aps')if a['online']]
   if online:break
   time.sleep(2)
  if not online:raise RuntimeError('AP did not reconnect')
  ap=online[0];result['ap_before']=ap
  capture=subprocess.Popen(['tcpdump','-i',NIC,'-U','-s','0','-w',str(out/'dhcp.pcap'),'udp and (port 67 or port 68)'],stdout=subprocess.DEVNULL,stderr=subprocess.PIPE)
  dns_only=b'\n'.join(line for line in original.splitlines()if not line.startswith((b'dhcp-',b'log-dhcp')))+b'\n';config.write_bytes(dns_only);run('systemctl','restart','ac100-ap-dhcp')
  run('systemd-run','--quiet','--unit='+unit,'--collect','--property=User=root',str(WORK/'bin/ap-dhcp-validation'),str(cfg));time.sleep(.5)
  if run('systemctl','is-active',unit).strip()!='active':raise RuntimeError('Go DHCP did not bind')
  operation=api('aps/'+ap['id']+'/action',{'action':'reboot-device'});result['reboot']=operation;print('AP reboot acknowledged; waiting for Go DHCP lease',flush=True)
  deadline=time.monotonic()+180
  while time.monotonic()<deadline:
   if lease.exists():
    leases=json.loads(lease.read_text());bound=[(key,v)for key,v in leases.items()if v.get('bound')]
    if bound:result['leases']=leases;print('Go DHCP bound physical AP:',bound[0][1]['ip'],flush=True);time.sleep(2);break
   time.sleep(1)
  else:raise RuntimeError('No bound AP lease observed')
 finally:
  subprocess.run(['systemctl','stop',unit],capture_output=True)
  if capture:
   capture.terminate();capture.wait(timeout=5)
  config.write_bytes(original);run('systemctl','restart','ac100-ap-dhcp')
  run('chown','-R','dl:dl',str(out));result['ended']=datetime.datetime.now().isoformat();(out/'result.json').write_text(json.dumps(result,ensure_ascii=False,indent=2));print('Restored lab client DHCP/DNS. Private evidence:',out,flush=True)
if __name__=='__main__':main()
