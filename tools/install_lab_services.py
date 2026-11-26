#!/usr/bin/env python3
"""Install persistent services for the already configured, dedicated AP lab link."""
import argparse,json,os,pwd,shutil,subprocess,tempfile
from pathlib import Path
from ac100_env import REPO,WORK

def install(path,text,mode=0o644):
    with tempfile.NamedTemporaryFile(mode='w',delete=False) as f:f.write(text);source=f.name
    try:subprocess.run(['sudo','-n','install','-m',oct(mode)[2:],source,path],check=True)
    finally:os.unlink(source)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--iface',required=True);args=p.parse_args()
    state=json.loads((WORK/'ap-direct/internet.json').read_text())
    if state['iface']!=args.iface or not args.iface.replace('-','').isalnum():p.error('NAT must already be configured for this interface')
    uplink=state['uplink']
    if not uplink.replace('-','').isalnum():p.error('invalid uplink name')
    user=pwd.getpwuid(os.getuid()).pw_name
    config_path=WORK/'go-data/controller.json'
    config=json.loads(config_path.read_text())
    if not config.get('interface'):
        config['interface']=args.iface
        config_path.write_text(json.dumps(config,ensure_ascii=False,indent=2)+'\n');config_path.chmod(0o600)
    ipt=shutil.which('iptables',path=os.environ.get('PATH','')+':/usr/sbin:/sbin')
    script=f'''#!/bin/bash
set -eu
[ -f {WORK}/ap-direct/internet.json ] || exit 0
ip -4 address show dev {args.iface} | /usr/bin/grep -q 'inet 192.168.70.1/24'
/usr/sbin/sysctl -w net.ipv4.ip_forward=1
IPT={ipt}
$IPT -w 5 -N AC100_LAB_FWD 2>/dev/null || true
$IPT -w 5 -t nat -N AC100_LAB_NAT 2>/dev/null || true
'''
    rules=[('', 'AC100_LAB_FWD',f'-i {args.iface} -o {uplink} -s 192.168.70.0/24 -j ACCEPT'),
      ('','AC100_LAB_FWD',f'-i {uplink} -o {args.iface} -d 192.168.70.0/24 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT'),
      ('-t nat','AC100_LAB_NAT','-j MASQUERADE'),
      ('','FORWARD',f'-i {args.iface} -s 192.168.70.0/24 -m comment --comment ac100-ap-lab -j AC100_LAB_FWD'),
      ('','FORWARD',f'-o {args.iface} -d 192.168.70.0/24 -m comment --comment ac100-ap-lab -j AC100_LAB_FWD'),
      ('-t nat','POSTROUTING',f'-s 192.168.70.0/24 -o {uplink} -m comment --comment ac100-ap-lab -j AC100_LAB_NAT')]
    for table,chain,rule in rules:script+=f'$IPT -w 5 {table} -C {chain} {rule} 2>/dev/null || $IPT -w 5 {table} -I {chain} 1 {rule}\n'
    subprocess.run(['sudo','-n','install','-d','/usr/local/libexec'],check=True)
    install('/usr/local/libexec/ac100-lab-network',script,0o755)
    common='''[Unit]
After=NetworkManager-wait-online.service network-online.target
Wants=network-online.target
StartLimitIntervalSec=0
'''
    dnsmasq=shutil.which('dnsmasq',path=os.environ.get('PATH','')+':/usr/sbin:/sbin')
    units={
      'ac100-ap-dhcp':common+f'''Description=DHCP and DNS on the dedicated AC100 AP lab link
[Service]
Type=simple
ExecStart={dnsmasq} --keep-in-foreground --conf-file={WORK}/ap-direct/dnsmasq.conf
Restart=on-failure
RestartSec=5
[Install]
WantedBy=multi-user.target
''',
      'ac100-ap-nat':common+'''Description=Scoped IPv4 NAT for the AC100 AP lab
[Service]
Type=oneshot
ExecStart=/usr/local/libexec/ac100-lab-network
RemainAfterExit=yes
Restart=on-failure
RestartSec=5
[Install]
WantedBy=multi-user.target
''',
      'ac100-go':common+f'''Description=Standalone Go wireless controller
After=ac100-ap-dhcp.service ac100-ap-nat.service
Wants=ac100-ap-dhcp.service ac100-ap-nat.service
[Service]
User={user}
WorkingDirectory={REPO}/uacgo
ExecStart={WORK}/bin/acd-next --data {WORK}/go-data --dtls-cert {WORK}/go-data/cacert.pem --dtls-key {WORK}/go-data/privkey.pem --http 127.0.0.1:8090 --trace {WORK}/go-trace.jsonl
Restart=on-failure
RestartSec=3
UMask=0077
TimeoutStopSec=10
[Install]
WantedBy=multi-user.target
'''}
    # Stop the transient DHCP unit before replacing it with a permanent unit.
    subprocess.run(['sudo','-n','systemctl','stop','ac100-ap-dhcp'],check=True)
    for name,text in units.items():install('/etc/systemd/system/'+name+'.service',text)
    subprocess.run(['sudo','-n','systemctl','daemon-reload'],check=True)
    subprocess.run(['sudo','-n','systemctl','enable','--now','ac100-ap-dhcp','ac100-ap-nat'],check=True)
    subprocess.run(['python3',str(REPO/'tools/go_lab.py'),'stop'],check=True)
    subprocess.run(['sudo','-n','systemctl','enable','--now','ac100-go'],check=True)
    print('Installed persistent DHCP/DNS, scoped NAT, and Go controller services.')
if __name__=='__main__':main()
