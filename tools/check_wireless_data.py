#!/usr/bin/env python3
"""Real client rate-control and forced-disassociation checks in the AP lab.
Uses a temporary HTTP payload server bound only to the isolated lab address.
Restores the original wireless rate policy and removes the tablet test file.
ACKs are recorded separately from measured traffic and client transitions.
"""
import argparse,copy,datetime,http.server,json,pathlib,re,shlex,subprocess,threading,time,urllib.request
ROOT=pathlib.Path(__file__).resolve().parents[1]
SIZE=4*1024*1024
class Payload(http.server.BaseHTTPRequestHandler):
 def log_message(self,*a):pass
 def do_GET(self):
  self.send_response(200);self.send_header('Content-Length',str(SIZE));self.send_header('Cache-Control','no-store');self.end_headers()
  try:
   for _ in range(SIZE//65536):self.wfile.write(b'X'*65536)
  except (BrokenPipeError,ConnectionResetError):pass
 def do_POST(self):
  n=int(self.headers.get('Content-Length','0'))
  if n>SIZE:self.send_error(413);return
  while n:
   b=self.rfile.read(min(n,65536))
   if not b:return
   n-=len(b)
  self.send_response(200);self.send_header('Content-Length','0');self.end_headers()
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--serial',required=True);p.add_argument('--case',choices=('rates','disconnect'),required=True);args=p.parse_args()
 evidence={'case':args.case,'started':datetime.datetime.now().isoformat(),'steps':[]};out=ROOT/'.local/ac100/wireless-data-tests';out.mkdir(parents=True,exist_ok=True,mode=0o700)
 def api(path,body=None):
  req=urllib.request.Request('http://127.0.0.1:8090/api/'+path,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'})
  with urllib.request.urlopen(req,timeout=25)as r:return json.load(r)
 def adb(*words):
  v=subprocess.run(['adb','-s',args.serial,'shell',shlex.join(words)],capture_output=True,text=True,timeout=60)
  if v.returncode:raise RuntimeError(v.stderr or v.stdout)
  return v.stdout.strip()
 def connected(limit=60):
  end=time.monotonic()+limit
  while time.monotonic()<end:
   s=adb('cmd','wifi','status');ip=re.search(r'IP: /([0-9.]+)',s);mac=re.search(r' MAC: ([0-9a-f:]+)',s)
   if 'Supplicant state: COMPLETED' in s and ip and mac and 'inet '+ip[1]+'/' in adb('ip','-4','addr','show','dev','wlan0'):return mac[1]
   time.sleep(1)
  raise RuntimeError('Tablet WLAN did not reconnect')
 mac=connected();ap=next(a for a in api('aps')if a['online']);cfg=api('config')['config'];ssid=re.search(r'SSID: "([^"]+)"',adb('cmd','wifi','status'))[1];service=next(s for s in cfg['services']if s['ssid']==ssid);original=copy.deepcopy(service);server=None;changed=False
 def wait_commit(since):
  end=time.monotonic()+100
  while time.monotonic()<end:
   v=api('config');st=next((s for s in v['apply']if s['ap_id']==ap['id']and s['service_id']=='configuration-commit'),None)
   if st and st['state']=='acknowledged':
    at=datetime.datetime.fromisoformat(st['at']).timestamp()
    if at>=since and time.time()-at>=13:return
   time.sleep(1)
  raise RuntimeError('Wireless commit did not settle')
 def set_rate(policy):
  nonlocal changed
  current=copy.deepcopy(next(s for s in api('config')['config']['services']if s['id']==service['id']));options=current.get('options')or {'auth':2,'cipher':2,'key_update_interval':86400};options['rate_limit']=policy;current['options']=options;since=time.time();api('services',current);changed=True;wait_commit(since);connected()
 def measure(label):
  row={'label':label}
  for direction in ('download','upload'):
   url='http://192.168.70.1:32080/payload';words=['curl','--interface','wlan0','--connect-timeout','5','--max-time','50','-sS','-o','/dev/null','-w','%{http_code} %{speed_download} %{speed_upload}']
   if direction=='upload':words+=['-X','POST','--data-binary','@/data/local/tmp/goac-rate-test.bin']
   output=adb(*(words+[url]));status,down,up=output.split();assert status=='200',output;row[direction+'_mbps']=float(down if direction=='download'else up)*8/1000000
  evidence['steps'].append(row);print(label+': '+json.dumps(row),flush=True);return row
 try:
  if args.case=='disconnect':
   before=next(c for c in api('clients')if c['mac']==mac and c['state']=='connected');at=datetime.datetime.now(datetime.timezone.utc);ack=api('clients/'+mac+'/disconnect',{});evidence['ack']=ack
   end=time.monotonic()+75;seen=False
   while time.monotonic()<end:
    history=api('history?limit=1000');events=history.get('events',[])
    matches=[e for e in events if e.get('client_mac')==mac and datetime.datetime.fromisoformat(e.get('at',e.get('seen','1970-01-01T00:00:00Z')))>=at]
    if any(e.get('kind')=='disconnected'for e in matches):evidence['transitions']=matches;seen=True;break
    time.sleep(1)
   if not seen:raise RuntimeError('ACK received but no confirmed disassociation transition')
   connected();evidence['before']=before;print('Confirmed client disassociation report and reconnect',flush=True)
  else:
   if not ap.get('features',{}).get('ssid_rate_limit'):raise RuntimeError('AP lacks advertised rate control')
   server=http.server.ThreadingHTTPServer(('192.168.70.1',32080),Payload);threading.Thread(target=server.serve_forever,daemon=True).start();adb('dd','if=/dev/zero','of=/data/local/tmp/goac-rate-test.bin','bs=65536','count=64')
   baseline=measure('baseline')
   for mode in ('client','ssid'):
    set_rate({'enabled':True,'mode':mode,'upload_kbps':3000,'download_kbps':3000});row=measure(mode+' 3000 kbps')
    for d in ('download','upload'):
     speed=row[d+'_mbps'];base=baseline[d+'_mbps']
     if not .5<=speed<=4.5 or base<speed*2:raise RuntimeError(mode+' '+d+' did not show configured rate bound')
   set_rate((original.get('options')or{}).get('rate_limit'));row=measure('restored');changed=False
   if min(row['download_mbps'],row['upload_mbps'])<6:raise RuntimeError('Throughput remained restricted after restoring rate policy')
 except Exception as e:evidence['error']=str(e);raise
 finally:
  if changed:
   try:set_rate((original.get('options')or{}).get('rate_limit'))
   except Exception as e:evidence['restore_error']=str(e)
  if server:server.shutdown();server.server_close()
  if args.case=='rates':
   try:adb('rm','-f','/data/local/tmp/goac-rate-test.bin')
   except Exception as e:evidence['cleanup_error']=str(e)
  path=out/(datetime.datetime.now().strftime('%Y%m%d-%H%M%S-')+args.case+'.json');path.write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n');path.chmod(0o600);print('Private evidence:',path,flush=True)
if __name__=='__main__':main()
