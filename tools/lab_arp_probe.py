#!/usr/bin/env python3
"""Send three ARP probes only on the isolated USB AP lab interface."""
import argparse, ipaddress, json, os, pathlib, select, socket, struct, time

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--iface',required=True);p.add_argument('--target',required=True);p.add_argument('--mac',required=True);a=p.parse_args()
 nic=pathlib.Path('/sys/class/net')/a.iface
 if os.geteuid()!=0 or '/usb' not in str((nic/'device').resolve()) or (nic/'master').exists():raise SystemExit('Requires root and a dedicated unbridged USB interface')
 target=ipaddress.IPv4Address(a.target);network=ipaddress.IPv4Network('192.168.70.0/24');source=ipaddress.IPv4Address('192.168.70.1')
 if target not in network or target in (source,network.network_address,network.broadcast_address):raise SystemExit('Target must be an AP lab client')
 mac=bytes.fromhex(a.mac.replace(':',''));local=bytes.fromhex((nic/'address').read_text().strip().replace(':',''))
 if len(mac)!=6 or mac[0]&1 or not any(mac):raise SystemExit('Invalid client MAC')
 packet=b'\xff'*6+local+b'\x08\x06'+struct.pack('!HHBBH',1,0x0800,6,4,1)+local+source.packed+b'\0'*6+target.packed
 with socket.socket(socket.AF_PACKET,socket.SOCK_RAW,socket.htons(0x0806))as s:
  s.bind((a.iface,0));sent=0;replies=0;deadline=time.monotonic()+4;next_probe=0
  while time.monotonic()<deadline:
   if sent<3 and time.monotonic()>=next_probe:s.send(packet);sent+=1;next_probe=time.monotonic()+1
   ready,_,_=select.select([s],[],[],.2)
   if not ready:continue
   b=s.recv(2048)
   if len(b)>=42 and b[12:14]==b'\x08\x06' and b[20:22]==b'\0\2' and b[22:28]==mac and b[28:32]==target.packed and b[38:42]==source.packed:replies+=1
 print(json.dumps({'sent':sent,'replies':replies,'target':str(target),'mac':a.mac}))

if __name__=='__main__':main()
