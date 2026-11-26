#!/usr/bin/env python3
"""Decode the private QEMU DTLS oracle capture using its supplied RSA test key."""
import argparse,os,subprocess
from pathlib import Path
from ac100_env import WORK,ROOTFS

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--input',type=Path,default=WORK/'harness/capwap.pcap');p.add_argument('--output',type=Path,required=True);args=p.parse_args()
 from scapy.all import IP,UDP,PcapReader,PcapWriter
 os.umask(0o077);args.output.parent.mkdir(parents=True,exist_ok=True)
 stripped=args.output.with_suffix('.dtls.pcap')
 with PcapReader(str(args.input)) as source,PcapWriter(str(stripped),linktype=1) as target:
  for packet in source:
   if IP in packet and UDP in packet:
    ip,udp=packet[IP],packet[UDP]
    if 5246 in (udp.sport,udp.dport):
     payload=bytes(udp.payload)[:udp.len-8]
     if payload.startswith(b'\x01\0\0\0'):
      udp.remove_payload();udp.add_payload(payload[4:]);del ip.len,ip.chksum,udp.len,udp.chksum
   target.write(packet)
 with args.output.open('w') as out:
  subprocess.run(['tshark','-r',str(stripped),'-d','udp.port==5246,dtls','-o',f'dtls.keys_list:172.30.194.2,5246,data,{ROOTFS}/etc/privkey.pem','-Y','dtls.record.content_type == 23 && data.data','-T','fields','-E','aggregator=,','-e','frame.number','-e','ip.src','-e','data.data'],stdout=out,check=True)
 print(f'Private decoded CAPWAP: {args.output}; {len(args.output.read_text().splitlines())} records')
if __name__=='__main__':main()
