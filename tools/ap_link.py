#!/usr/bin/env python3
"""Configure a dedicated USB Ethernet link and isolated DHCP for the test AP."""
import argparse
import os
import pwd
import shutil
import shlex
import subprocess
from pathlib import Path
from ac100_env import WORK

PROFILE = "ac100-ap-direct"
UNIT = "ac100-ap-dhcp"
ADDRESS = "192.168.70.1/24"


def run(*args):
    return subprocess.run(list(args), check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=("up", "down", "status"))
    parser.add_argument("--iface", required=True)
    args = parser.parse_args()
    nic = Path("/sys/class/net") / args.iface
    if not nic.exists() or "/usb" not in str((nic / "device").resolve()):
        parser.error("--iface must name the dedicated USB Ethernet interface")
    if (nic / "master").exists():
        parser.error("USB interface is already a bridge/bond member")
    config_dir = WORK / "ap-direct"
    config_dir.mkdir(parents=True, exist_ok=True)
    config = config_dir / "dnsmasq.conf"
    if args.command == "status":
        run("ip", "-brief", "address", "show", "dev", args.iface)
        subprocess.run(["systemctl", "--no-pager", "status", UNIT])
        lease = config_dir / "dhcp.leases"
        if lease.exists():
            print(lease.read_text())
        return
    if args.command == "down":
        subprocess.run(["sudo", "-n", "systemctl", "stop", UNIT])
        subprocess.run(["sudo", "-n", "nmcli", "connection", "down", PROFILE])
        return
    # Never offer DHCP or a default route on the normal host LAN.
    active = subprocess.check_output(["ip", "route", "show", "default"], text=True)
    if f"dev {args.iface} " in active + " ":
        parser.error("refusing to configure the host's default-route interface")
    mac = (nic / "address").read_text().strip()
    exists = subprocess.run(["nmcli", "connection", "show", PROFILE], capture_output=True).returncode == 0
    if exists:
        configured = subprocess.check_output(["nmcli", "-g", "connection.interface-name", "connection", "show", PROFILE], text=True).strip()
        if configured != args.iface:
            parser.error(f"{PROFILE} already belongs to {configured}")
    else:
        run("sudo", "-n", "nmcli", "connection", "add", "type", "ethernet", "ifname", args.iface,
            "con-name", PROFILE, "802-3-ethernet.mac-address", mac, "connection.autoconnect", "yes",
            "connection.autoconnect-priority", "100", "ipv4.method", "manual", "ipv4.addresses", ADDRESS,
            "ipv4.never-default", "yes", "ipv6.method", "disabled")
    run("sudo", "-n", "nmcli", "connection", "up", PROFILE)
    user = pwd.getpwuid(os.getuid()).pw_name
    internet_enabled=(config_dir / "internet.json").exists()
    if not internet_enabled:
        config.write_text(f"""port=0
interface={args.iface}
bind-interfaces
dhcp-authoritative
dhcp-range=192.168.70.50,192.168.70.60,255.255.255.0,1h
dhcp-option=3
dhcp-option=6
dhcp-option-force=60,TP-LINK
dhcp-option-force=138,192.168.70.1
dhcp-leasefile={config_dir / 'dhcp.leases'}
user={user}
log-dhcp
log-facility=-
""")
    # Wildcard bind is needed to receive the AP's limited-broadcast discovery.
    # The relay filters peers to the dedicated USB subnet.
    (config_dir / "link.env").write_text(
        f"export AC100_AP_IFACE={shlex.quote(args.iface)}\n"
        'export AC100_RELAY_LISTEN="${AC100_RELAY_LISTEN:-0.0.0.0:5246}"\n'
        'export AC100_RELAY_PEERS="${AC100_RELAY_PEERS:-192.168.70.0/24}"\n')
    binary = shutil.which("dnsmasq", path=os.environ.get("PATH", "") + ":/usr/sbin:/sbin")
    if not binary:
        parser.error("install dnsmasq-base first")
    run("sudo", "-n", binary, "--test", f"--conf-file={config}")
    if Path("/etc/systemd/system/"+UNIT+".service").exists():
        run("sudo","-n","systemctl","restart",UNIT)
        print("AP link ready; preserved the installed DHCP/DNS configuration")
        return
    subprocess.run(["sudo", "-n", "systemctl", "stop", UNIT], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    subprocess.run(["sudo", "-n", "systemctl", "reset-failed", UNIT], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    run("sudo", "-n", "systemd-run", f"--unit={UNIT}", "--collect", "--property=Restart=on-failure",
        binary, "--keep-in-foreground", f"--conf-file={config}")
    print("AP link ready:", args.iface, ADDRESS, "DHCP 192.168.70.50-60, option 60 TP-LINK, option 138 -> 192.168.70.1")


if __name__ == "__main__":
    main()
