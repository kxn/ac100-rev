#!/usr/bin/env python3
"""Provide DHCP, DNS and scoped IPv4 NAT on the dedicated AP test link."""
import argparse
import ipaddress
import json
import os
from pathlib import Path
import pwd
import shutil
import subprocess
from ac100_env import WORK

NETWORK = "192.168.70.0/24"
GATEWAY = "192.168.70.1"
FORWARD = "AC100_LAB_FWD"
NAT = "AC100_LAB_NAT"
COMMENT = "ac100-ap-lab"


def run(*args, check=True, capture=False):
    return subprocess.run(list(args), check=check, capture_output=capture, text=True)


def privileged(*args, **kwargs):
    return run("sudo", "-n", *args, **kwargs)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("action", choices=("up", "down", "status"))
    parser.add_argument("--iface", required=True)
    args = parser.parse_args()
    iface = args.iface
    nic = Path("/sys/class/net") / iface
    if not nic.is_dir() or "/usb" not in str((nic / "device").resolve()) or (nic / "master").exists():
        parser.error("use the dedicated USB Ethernet interface, without a bridge/bond")
    links = json.loads(subprocess.check_output(["ip", "-j", "-4", "addr", "show", "dev", iface]))
    if not any(a["local"] == GATEWAY and a["prefixlen"] == 24 for link in links for a in link["addr_info"]):
        parser.error("configure 192.168.70.1/24 with tools/ap_link.py first")
    routes = json.loads(subprocess.check_output(["ip", "-j", "-4", "route", "get", "1.1.1.1"]))
    uplink = routes[0]["dev"]
    if uplink == iface:
        parser.error("refusing to NAT through the AP interface itself")
    directory = WORK / "ap-direct"
    directory.mkdir(parents=True, exist_ok=True)
    config = directory / "dnsmasq.conf"
    state = directory / "internet.json"
    iptables = shutil.which("iptables", path=os.environ.get("PATH", "") + ":/usr/sbin:/sbin")
    if not iptables:
        parser.error("iptables is required")
    def ipt(*parts, **kwargs):
        return privileged(iptables, "-w", "5", *parts, **kwargs)
    jumps = [("filter", "FORWARD", ["-i", iface, "-s", NETWORK, "-m", "comment", "--comment", COMMENT, "-j", FORWARD]),
             ("filter", "FORWARD", ["-o", iface, "-d", NETWORK, "-m", "comment", "--comment", COMMENT, "-j", FORWARD]),
             ("nat", "POSTROUTING", ["-s", NETWORK, "-o", uplink, "-m", "comment", "--comment", COMMENT, "-j", NAT])]
    if args.action == "status":
        for table, chain in (("filter", FORWARD), ("nat", NAT)):
            ipt("-t", table, "-nvL", chain, check=False)
        print(config.read_text() if config.exists() else "DNS/DHCP is not configured")
        return
    if args.action == "down":
        if Path("/etc/systemd/system/ac100-ap-nat.service").exists():
            privileged("systemctl", "disable", "--now", "ac100-ap-nat")
        if state.exists():
            old = json.loads(state.read_text())
            if old["iface"] != iface:
                parser.error("NAT state belongs to a different AP interface")
            jumps = old["jumps"]
        for table, chain, rule in jumps:
            while ipt("-t", table, "-C", chain, *rule, check=False, capture=True).returncode == 0:
                ipt("-t", table, "-D", chain, *rule)
        for table, chain in (("filter", FORWARD), ("nat", NAT)):
            ipt("-t", table, "-F", chain, check=False, capture=True)
            ipt("-t", table, "-X", chain, check=False, capture=True)
        backup = directory / "dnsmasq-before-internet.conf"
        if backup.exists():
            config.write_bytes(backup.read_bytes())
            privileged("systemctl", "restart", "ac100-ap-dhcp")
        state.unlink(missing_ok=True)
        print("Removed only AP lab NAT rules and restored the isolated DHCP configuration")
        return
    if state.exists():
        old = json.loads(state.read_text())
        if old["iface"] != iface or old["uplink"] != uplink:
            parser.error("remove the previous lab NAT configuration before changing interfaces")
    if config.exists() and not (directory / "dnsmasq-before-internet.conf").exists():
        shutil.copyfile(config, directory / "dnsmasq-before-internet.conf")
    dns = []
    for line in Path("/etc/resolv.conf").read_text().splitlines():
        words = line.split()
        if len(words) == 2 and words[0] == "nameserver":
            address = ipaddress.ip_address(words[1])
            if address.version == 4 and not address.is_loopback and str(address) != GATEWAY:
                dns.append(str(address))
    if not dns:
        parser.error("host has no usable upstream IPv4 DNS server")
    user = pwd.getpwuid(os.getuid()).pw_name
    text = f"""port=53
interface={iface}
listen-address={GATEWAY}
except-interface=lo
bind-interfaces
no-resolv
domain-needed
bogus-priv
cache-size=1000
dhcp-authoritative
dhcp-range=192.168.70.50,192.168.70.199,255.255.255.0,1h
dhcp-option=3,{GATEWAY}
dhcp-option=6,{GATEWAY}
dhcp-option-force=43,01:04:c0:a8:46:01
dhcp-leasefile={directory / 'dhcp.leases'}
user={user}
log-dhcp
log-facility=-
""" + "".join(f"server={address}\n" for address in dns)
    candidate = directory / "dnsmasq-internet.conf"
    candidate.write_text(text)
    dnsmasq = shutil.which("dnsmasq", path=os.environ.get("PATH", "") + ":/usr/sbin:/sbin")
    privileged(dnsmasq, "--test", f"--conf-file={candidate}")
    # Keep Docker's chains and policy unchanged; install only our own chains.
    for table, chain in (("filter", FORWARD), ("nat", NAT)):
        ipt("-t", table, "-N", chain, check=False, capture=True)
        ipt("-t", table, "-F", chain)
    ipt("-A", FORWARD, "-i", iface, "-o", uplink, "-s", NETWORK, "-j", "ACCEPT")
    ipt("-A", FORWARD, "-i", uplink, "-o", iface, "-d", NETWORK, "-m", "conntrack", "--ctstate", "RELATED,ESTABLISHED", "-j", "ACCEPT")
    ipt("-t", "nat", "-A", NAT, "-j", "MASQUERADE")
    for table, chain, rule in jumps:
        if ipt("-t", table, "-C", chain, *rule, check=False, capture=True).returncode != 0:
            ipt("-t", table, "-I", chain, "1", *rule)
    privileged("/usr/sbin/sysctl", "-w", "net.ipv4.ip_forward=1")
    config.write_text(text)
    privileged("systemctl", "restart", "ac100-ap-dhcp")
    privileged("systemctl", "is-active", "--quiet", "ac100-ap-dhcp")
    state.write_text(json.dumps({"iface": iface, "uplink": uplink, "network": NETWORK, "dns": dns, "jumps": jumps}, indent=2) + "\n")
    if Path("/etc/systemd/system/ac100-ap-nat.service").exists():
        privileged("systemctl", "enable", "--now", "ac100-ap-nat")
    print(f"AP lab Internet ready: {iface} {NETWORK} -> NAT {uplink}; DHCP + DNS + gateway {GATEWAY}")
    print("This lab DHCP serves APs and test clients. Product TP-Link-only DHCP remains separate.")


if __name__ == "__main__":
    main()
