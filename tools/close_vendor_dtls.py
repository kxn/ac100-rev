#!/usr/bin/env python3
"""Gracefully end our QEMU oracle's orphaned RSA-DTLS session on the owned test AP.

Uses the oracle's existing test key and its complete handshake capture. Both
server records and a live AP record must authenticate before sending close_notify.
No AP configuration is reset. Session keys are never printed or written.
"""
import argparse,hashlib,hmac,os,socket,struct,subprocess,time
from pathlib import Path
from ac100_env import WORK,ROOTFS

def phash(secret,seed,digest,n):
 a=seed;out=b''
 while len(out)<n:
  a=hmac.new(secret,a,digest).digest();out+=hmac.new(secret,a+seed,digest).digest()
 return out[:n]
def prf(secret,label,seed,n):
 half=(len(secret)+1)//2;seed=label+seed
 return bytes(a^b for a,b in zip(phash(secret[:half],seed,hashlib.md5,n),phash(secret[-half:],seed,hashlib.sha1,n)))
def records(b):
 if not b.startswith(b'\x01\0\0\0'):return
 b=b[4:]
 while len(b)>=13:
  size=int.from_bytes(b[11:13],'big');v=b[:13+size]
  if len(v)!=13+size:return
  yield v;b=b[13+size:]
def decrypt(r,key,mac):
 from cryptography.hazmat.primitives.ciphers import Cipher,algorithms,modes
 v=r[13:]
 if len(v)<48 or len(v)%16:return None
 x=Cipher(algorithms.AES(key),modes.CBC(v[:16])).decryptor().update(v[16:]);padding=x[-1]+1
 if padding>len(x) or x[-padding:]!=bytes([padding-1])*padding:return None
 x=x[:-padding]
 if len(x)<20:return None
 p,m=x[:-20],x[-20:];want=hmac.new(mac,r[3:11]+r[:3]+struct.pack('>H',len(p))+p,hashlib.sha1).digest()
 return p if hmac.compare_digest(m,want) else None

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--iface',required=True);p.add_argument('--apply',action='store_true');args=p.parse_args()
 if os.geteuid()!=0:raise SystemExit('run through sudo for the dedicated link capture')
 if args.iface!='enxc817f5dd9eb9':p.error('this diagnostic is scoped to the existing dedicated AP link')
 from scapy.all import PcapReader,IP,UDP
 from cryptography.hazmat.primitives import serialization
 from cryptography.hazmat.primitives.asymmetric import padding
 from cryptography.hazmat.primitives.ciphers import Cipher,algorithms,modes
 key=serialization.load_pem_private_key((ROOTFS/'etc/privkey.pem').read_bytes(),None)
 sessions={};server_records=[]
 with PcapReader(str(WORK/'harness/capwap.pcap')) as reader:
  for packet in reader:
   if IP not in packet or UDP not in packet:continue
   udp=packet[UDP];server=packet[IP].src=='172.30.194.2';port=udp.dport if server else udp.sport
   s=sessions.setdefault(port,{})
   for r in records(bytes(udp.payload)):
    if int.from_bytes(r[3:5],'big')==1 and server:server_records.append((port,r))
    if r[0]!=22 or r[3:5]!=b'\0\0':continue
    body=r[13:]
    while len(body)>=12:
     typ=body[0];size=int.from_bytes(body[9:12],'big');payload=body[12:12+size];body=body[12+size:]
     if len(payload)!=size:break
     if typ==1:s['client']=payload[2:34]
     elif typ==2:s['server']=payload[2:34]
     elif typ==16:s['premaster']=key.decrypt(payload[2:],padding.PKCS1v15())
 for s in sessions.values():
  if all(k in s for k in ('client','server','premaster')):
   master=prf(s['premaster'],b'master secret',s['client']+s['server'],48);s['keys']=prf(master,b'key expansion',s['server']+s['client'],104)
 verified=[]
 for port,r in server_records:
  s=sessions[port]
  if 'keys' not in s:continue
  k=s['keys'];plain=decrypt(r,k[72:104],k[20:40])
  if plain is not None:s['seq']=max(s.get('seq',0),int.from_bytes(r[5:11],'big'));verified.append(s)
 if not verified:raise SystemExit('no authenticated server record in the oracle capture')
 with socket.socket(socket.AF_PACKET,socket.SOCK_RAW,socket.htons(0x0800)) as wire:
  wire.bind((args.iface,0));wire.settimeout(1);deadline=time.monotonic()+40;peer=None;chosen=None
  while time.monotonic()<deadline:
   try:b=wire.recv(65535)
   except socket.timeout:continue
   if len(b)<42 or b[12:14]!=b'\x08\x00':continue
   ihl=(b[14]&15)*4;ip=b[14:];off=14+ihl
   if ip[9]!=17 or ip[12:16]!=socket.inet_aton('192.168.70.50') or ip[16:20]!=socket.inet_aton('192.168.70.1'):continue
   source,dest=struct.unpack_from('>HH',b,off)
   if dest!=5246:continue
   for r in records(b[off+8:]):
    for s in verified:
     k=s['keys']
     if decrypt(r,k[40:72],k[:20]) is not None:peer=('192.168.70.50',source);chosen=s;break
    if chosen:break
   if chosen:break
 if not chosen:raise SystemExit('AP is not using an authenticated captured session; nothing sent')
 print('Authenticated existing oracle session for the dedicated AP')
 if not args.apply:print('Read-only verification complete; use --apply to send close_notify');return
 seq=chosen['seq']+64;head=b'\x15\xfe\xff\x00\x01'+seq.to_bytes(6,'big');plain=b'\x01\x00';k=chosen['keys']
 mac=hmac.new(k[20:40],head[3:11]+head[:3]+struct.pack('>H',2)+plain,hashlib.sha1).digest();clear=plain+mac;n=16-len(clear)%16;clear+=bytes([n-1])*n;iv=os.urandom(16)
 encrypted=iv+Cipher(algorithms.AES(k[72:104]),modes.CBC(iv)).encryptor().update(clear);record=head+struct.pack('>H',len(encrypted))+encrypted
 subprocess.run(['systemctl','stop','ac100-go'],check=True)
 try:
  with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as sock:
   sock.setsockopt(socket.SOL_SOCKET,socket.SO_BINDTODEVICE,args.iface.encode()+b'\0');sock.bind(('192.168.70.1',5246));sock.sendto(b'\x01\0\0\0'+record,peer)
 finally:subprocess.run(['systemctl','start','ac100-go'],check=True)
 print('Sent authenticated close_notify and restored the Go controller service')
if __name__=='__main__':main()
