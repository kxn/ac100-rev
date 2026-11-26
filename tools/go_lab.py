#!/usr/bin/env python3
"""Build and run the standalone Go controller on the dedicated AP lab link."""
import argparse
import json
import os
import shutil
import signal
import socket
import subprocess
import time
import urllib.request
from pathlib import Path

from ac100_env import REPO, WORK, ROOTFS, require_uac

PID = WORK / "go-ac.pid"
BIN = WORK / "bin/acd-next"
DATA = WORK / "go-data"


def managed_pid():
    p=subprocess.run(["systemctl","show","ac100-go.service","--property=MainPID","--value"],capture_output=True,text=True)
    try:return int(p.stdout.strip()) or None
    except ValueError:return None


def running():
    candidates=[]
    try:candidates.append(int(PID.read_text().strip()))
    except (OSError,ValueError):pass
    managed=managed_pid()
    if managed:candidates.append(managed)
    for pid in candidates:
        try:
            command=Path(f"/proc/{pid}/cmdline").read_bytes().split(b"\0")
            if command[0]==os.fsencode(BIN):return pid
        except (OSError,ValueError,IndexError):pass
    return None


def stop():
    pid = running()
    if pid is None:
        print("Go controller is not running")
        return
    if managed_pid()==pid:
        subprocess.run(["sudo","-n","systemctl","stop","ac100-go"],check=True)
    else:
        os.kill(pid, signal.SIGTERM)
    for _ in range(100):
        if running() != pid:
            PID.unlink(missing_ok=True)
            print("Go controller stopped")
            return
        time.sleep(0.05)
    raise SystemExit(f"PID {pid} did not stop; inspect the process (no forced kill performed)")


def build():
    BIN.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(["go", "build", "-o", str(BIN), "./cmd/acd"], cwd=REPO / "uacgo",
                   env={**os.environ, "CGO_ENABLED": "0"}, check=True)


def prepare():
    DATA.mkdir(parents=True, exist_ok=True)
    DATA.chmod(0o700)
    for source in (REPO / "uacgo/data").iterdir():
        target = DATA / source.name
        if source.is_file() and not target.exists():
            shutil.copyfile(source, target)
            target.chmod(0o600)
    for name in ("cacert.pem", "privkey.pem"):
        target = DATA / name
        if not target.exists():
            require_uac()
            shutil.copyfile(ROOTFS / "etc" / name, target)
            target.chmod(0o600)


def start(args):
    if Path("/etc/systemd/system/ac100-go.service").exists():
        subprocess.run(["sudo","-n","systemctl","start","ac100-go"],check=True)
        print("Started the managed Go controller; interface from controller.json")
        return
    if running():
        raise SystemExit("Go controller is already running; use status or restart")
    if not args.iface:
        raise SystemExit("Supply --iface with the dedicated AP network interface")
    socket.if_nametoindex(args.iface)
    link = subprocess.run(["ip", "-j", "-4", "addr", "show", "dev", args.iface],
                          capture_output=True, text=True, check=True)
    interfaces = json.loads(link.stdout)
    if not interfaces or not interfaces[0].get("addr_info"):
        raise SystemExit("The AP interface needs an IPv4 address; see tools/ap_link.py")
    probe = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        probe.bind(("0.0.0.0", 5246))
    except OSError:
        raise SystemExit("UDP 5246 is occupied. Stop the vendor relay before Go takeover.")
    finally:
        probe.close()
    prepare()
    cmd = [str(BIN), "-data", str(DATA), "-interface", args.iface,
           "-dtls-cert", str(DATA / "cacert.pem"), "-dtls-key", str(DATA / "privkey.pem"),
           "-trace", str(WORK / "go-trace.jsonl"), "-debug"]
    log = WORK / "go-ac.log"
    with log.open("ab") as output:
        log.chmod(0o600)
        process = subprocess.Popen(cmd, cwd=REPO / "uacgo", stdin=subprocess.DEVNULL,
                                   stdout=output, stderr=subprocess.STDOUT, start_new_session=True)
    PID.write_text(str(process.pid) + "\n")
    PID.chmod(0o600)
    time.sleep(0.3)
    if process.poll() is not None:
        raise SystemExit(f"Controller failed to start; inspect {log}")
    print(f"Go controller PID {process.pid}; UI http://127.0.0.1:8090; interface {args.iface}")
    print("AP DHCP remains a separate lab service. This command does not change host routing.")


def status():
    pid = running()
    print("Go controller:", pid or "not running")
    if not pid:
        return 1
    try:
        with urllib.request.urlopen("http://127.0.0.1:8090/api/aps", timeout=3) as r:
            aps = json.load(r)
        for ap in aps:
            print(f"  {ap['id']} {ap['model']} {ap['state']} last_seen={ap['last_seen']}")
        if not aps:
            print("  Waiting for AP discovery / DTLS / Join")
    except (OSError, ValueError) as e:
        print("Management interface unavailable:", e)
        return 1
    return 0


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("action", choices=("build", "start", "restart", "stop", "status"))
    p.add_argument("--iface", default=os.environ.get("AC100_AP_IFACE", ""))
    args = p.parse_args()
    if args.action in ("build", "start", "restart"):
        build()  # A failed build leaves the running controller untouched.
    if args.action in ("stop", "restart"):
        stop()
    if args.action in ("start", "restart"):
        start(args)
    if args.action == "status":
        return status()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
