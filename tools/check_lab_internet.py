#!/usr/bin/env python3
"""Verify lab DNS/NAT using an isolated synthetic client; no Wi-Fi association implied."""
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys


def main():
    if os.geteuid() != 0:
        return subprocess.call(["sudo", "-n", sys.executable, str(Path(__file__).resolve())])
    def run(*args, check=True):
        return subprocess.run(args, check=check, text=True, capture_output=True)
    ns = "ac100-netcheck"
    host, peer = "ac100probe", "ac100peer"
    if run("ip", "netns", "list").stdout.find(ns) >= 0 or Path("/sys/class/net", host).exists():
        raise SystemExit("test namespace/interface already exists; inspect before reuse")
    ipt = shutil.which("iptables", path="/usr/sbin:/sbin:/usr/bin:/bin")
    rules = [["-i", host, "-s", "192.168.70.240/32", "-m", "comment", "--comment", "ac100-netcheck", "-j", "ACCEPT"],
             ["-o", host, "-d", "192.168.70.240/32", "-m", "conntrack", "--ctstate", "RELATED,ESTABLISHED", "-m", "comment", "--comment", "ac100-netcheck", "-j", "ACCEPT"]]
    directory = Path("/etc/netns", ns)
    try:
        run("ip", "netns", "add", ns)
        run("ip", "link", "add", host, "type", "veth", "peer", "name", peer)
        run("ip", "link", "set", peer, "netns", ns)
        run("ip", "addr", "add", "169.254.71.1/30", "dev", host)
        run("ip", "link", "set", host, "up")
        for args in [("link", "set", "lo", "up"), ("addr", "add", "169.254.71.2/30", "dev", peer),
                     ("link", "set", peer, "up"), ("addr", "add", "192.168.70.240/32", "dev", "lo"),
                     ("route", "add", "default", "via", "169.254.71.1")]:
            run("ip", "-n", ns, *args)
        run("ip", "route", "add", "192.168.70.240/32", "via", "169.254.71.2", "dev", host)
        for rule in rules:
            run(ipt, "-w", "5", "-I", "FORWARD", "1", *rule)
        directory.mkdir(parents=True)
        (directory / "resolv.conf").write_text("nameserver 192.168.70.1\noptions timeout:2 attempts:2\n")
        result = run("ip", "netns", "exec", ns, "curl", "--noproxy", "*", "--interface", "192.168.70.240",
                     "--max-time", "15", "--silent", "--show-error", "--output", "/dev/null",
                     "--write-out", "%{http_code} %{remote_ip}", "https://example.com")
        print("Synthetic client HTTPS through lab DNS/NAT:", result.stdout)
        print(run(ipt, "-t", "nat", "-nvL", "AC100_LAB_NAT").stdout)
        if not result.stdout.startswith("200 "):
            raise SystemExit("external HTTPS check did not return 200")
        print("PASS. Physical AP/client association remains a separate hardware test.")
    finally:
        for rule in rules:
            run(ipt, "-w", "5", "-D", "FORWARD", *rule, check=False)
        run("ip", "route", "del", "192.168.70.240/32", check=False)
        run("ip", "link", "del", host, check=False)
        run("ip", "netns", "del", ns, check=False)
        if directory.exists():
            (directory / "resolv.conf").unlink(missing_ok=True)
            directory.rmdir()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
