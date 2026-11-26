#!/usr/bin/env python3
"""Prove Go DHCP silence/offer/ACK over veth in two disposable namespaces.
Runs only its own dhcpserver test binary, never the physical AP interface.
"""
import json,os,pathlib,subprocess,sys,tempfile,time
ROOT=pathlib.Path(__file__).resolve().parents[1]
def run(*args):return subprocess.run(args,check=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
if os.geteuid()!=0:raise SystemExit('Run with sudo; only temporary namespaces are modified.')
server='acdhcp-s-'+str(os.getpid());client='acdhcp-c-'+str(os.getpid());proc=None
try:
 run('ip','netns','add',server);run('ip','netns','add',client)
 run('ip','link','add','ac0','type','veth','peer','name','sta0');run('ip','link','set','ac0','netns',server);run('ip','link','set','sta0','netns',client)
 for ns,iface,ip in [(server,'ac0','198.18.0.1/24'),(client,'sta0','198.18.0.2/24')]:
  run('ip','-n',ns,'link','set','lo','up');run('ip','-n',ns,'addr','add',ip,'dev',iface);run('ip','-n',ns,'link','set',iface,'up')
 binary=ROOT/'.local/ac100/dhcp-wire.test'
 if not binary.exists():raise SystemExit('Build first: go -C uacgo test -c -o ../.local/ac100/dhcp-wire.test ./dhcpserver')
 proc=subprocess.Popen(['ip','netns','exec',server,'env','AC100_DHCP_WIRE_TEST=1',str(binary),'-test.run=^TestServeWire$'],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 time.sleep(.4)
 code=r'''
import socket,struct,json
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM);s.setsockopt(socket.SOL_SOCKET,socket.SO_BROADCAST,1);s.setsockopt(socket.SOL_SOCKET,socket.SO_BINDTODEVICE,b'sta0\0');s.bind(('',68));s.settimeout(.4)
def packet(v,typ=1,ip=None):
 b=bytearray(240);b[0:3]=bytes([1,1,6]);b[4:8]=b'GOT1';b[10]=128;b[28:34]=bytes.fromhex('020102030405');b[236:240]=bytes([99,130,83,99]);b+=bytes([53,1,typ]);
 if v is not None:b+=bytes([60,len(v)])+v
 if ip:b+=bytes([50,4])+ip+bytes([54,4])+socket.inet_aton('198.18.0.1')
 return b+bytes([255])
for v in [None,b'MSFT 5.0',b'TP-LINK-extra',b'TP-LINK\0',b'tp-link']:
 s.sendto(packet(v),('198.18.0.1',67))
 try:s.recvfrom(1600);raise RuntimeError('Go DHCP answered ordinary/nonmatching client')
 except socket.timeout:pass
s.sendto(packet(b'TP-LINK MESH DETECT 1.0'),('198.18.0.1',67));mesh,_=s.recvfrom(1600)
assert mesh[240:243]==bytes([53,1,2]),'Mesh Detect Discover did not receive OFFER'
s.sendto(packet(b'TP-LINK MESH DETECT 1.0',3,mesh[16:20]),('198.18.0.1',67))
try:s.recvfrom(1600);raise RuntimeError('Mesh Detect incorrectly allowed to acquire lease')
except socket.timeout:pass
s.sendto(packet(b'TP-LINK'),('198.18.0.1',67));offer,_=s.recvfrom(1600)
assert offer[0]==2 and offer[4:8]==b'GOT1' and offer[240:243]==bytes([53,1,2]),'invalid OFFER'
ip=offer[16:20];s.sendto(packet(b'TP-LINK',3,ip),('198.18.0.1',67));ack,_=s.recvfrom(1600)
assert ack[240:243]==bytes([53,1,5]) and ack[16:20]==ip,'invalid ACK'
print(json.dumps({'ordinary_clients':'silent (5 classes)','TP-LINK':'OFFER then ACK','Mesh Detect':'Discover OFFER; Request silent','lease':socket.inet_ntoa(ip)}))
'''
 print(run('ip','netns','exec',client,sys.executable,'-c',code).stdout.strip())
 output,_=proc.communicate(timeout=10)
 if proc.returncode:raise RuntimeError(output)
finally:
 if proc and proc.poll() is None:proc.terminate();proc.wait(timeout=3)
 for ns in (client,server):subprocess.run(['ip','netns','del',ns],stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
