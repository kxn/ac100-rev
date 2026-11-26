#!/usr/bin/env python3
"""Simulated AP for the vendor QEMU oracle, isolated from the physical AP link.

Uses independent OpenSSL DTLS 1.0, the real AP's captured identity/requests,
and records vendor-generated clear control packets for codec comparison.
It never listens on the physical AP control port and does not prove hardware
behavior. Captures stay in the private ignored work directory.
"""
import argparse
import json
import os
from pathlib import Path
import selectors
import signal
import socket
import struct
import subprocess
import sys
import time
from ac100_env import REPO, WORK

DIRECTORY = WORK / "vendor-oracle"


def packet(kind, sequence, elements=b""):
    return bytes.fromhex("0110430000000000") + struct.pack(">IBHB", kind, sequence, len(elements) + 3, 0) + elements


def serve():
    DIRECTORY.mkdir(parents=True, exist_ok=True)
    DIRECTORY.chmod(0o700)
    local = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    local.bind(("127.0.0.1", 0))
    remote = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    remote.bind(("172.30.194.1", 0))
    remote.connect(("172.30.194.2", 5246))
    source = {}
    for line in (WORK / "baseline-clear.tsv").read_text().splitlines():
        number, _, value = line.split("\t")
        source[int(number)] = bytes.fromhex(value)
    requests = {3: source[34], 5: source[36], 11: source[38]}
    echo_source = next((b for b in source.values() if len(b)>=16 and int.from_bytes(b[8:12],"big")==13),None)
    def request(kind, sequence):
        b = bytearray(requests[kind]); b[12] = sequence; return bytes(b)
    stderr = (DIRECTORY / "openssl.log").open("ab")
    proc = subprocess.Popen(["openssl", "s_client", "-dtls1", "-cipher", "AES256-SHA:@SECLEVEL=0",
                             "-connect", "%s:%d" % local.getsockname(), "-quiet", "-ign_eof"],
                            stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=stderr)
    os.set_blocking(proc.stdout.fileno(), False)
    selector = selectors.DefaultSelector()
    selector.register(local, selectors.EVENT_READ, "local")
    selector.register(remote, selectors.EVENT_READ, "remote")
    selector.register(proc.stdout, selectors.EVENT_READ, "plain")
    peer = None
    state = "JOIN"
    sequence = 3
    last_echo = time.monotonic()
    received = 0
    buffer = bytearray()
    trace = (DIRECTORY / "plain.jsonl").open("a", buffering=1)
    def write(b):
        proc.stdin.write(b); proc.stdin.flush()
        trace.write(json.dumps({"time": time.time(), "direction": "ap-tx", "hex": b.hex()}) + "\n")
    def save():
        (DIRECTORY / "status.json").write_text(json.dumps({"pid": os.getpid(), "state": state,
             "received": received, "peer": remote.getsockname(), "updated": time.time()}))
    # Discovery is plain and precedes the independent DTLS association.
    discover = (REPO / "ghidra-export/data/cw_dis_req_0074f340.bin").read_bytes()
    remote.send(discover)
    write(request(3, 1))
    stop = False
    def terminate(*_):
        nonlocal stop
        stop = True
    signal.signal(signal.SIGTERM, terminate)
    signal.signal(signal.SIGINT, terminate)
    started = time.monotonic()
    try:
        while not stop and proc.poll() is None:
            for key, _ in selector.select(.2):
                if key.data == "local":
                    b, peer = local.recvfrom(65536)
                    remote.send(b"\x01\0\0\0" + b)
                elif key.data == "remote":
                    b = remote.recv(65536)
                    if b.startswith(b"\x01\0\0\0") and peer:
                        local.sendto(b[4:], peer)
                else:
                    b = os.read(proc.stdout.fileno(), 65536)
                    buffer.extend(b)
                    while len(buffer) >= 16:
                        header_length = ((int.from_bytes(buffer[:4], "big") >> 19) & 31) * 4
                        if header_length < 8 or header_length > 124:
                            raise RuntimeError("invalid vendor CAPWAP header")
                        if len(buffer) < header_length + 8:
                            break
                        kind, seq, mel, flags = struct.unpack_from(">IBHB", buffer, header_length)
                        length = header_length + 5 + mel
                        if len(buffer) < length:
                            break
                        value = bytes(buffer[:length]); del buffer[:length]
                        received += 1
                        trace.write(json.dumps({"time": time.time(), "direction": "ac-tx", "hex": value.hex()}) + "\n")
                        if kind == 4 and state == "JOIN":
                            write(request(5, 2)); state = "CONFIGURE"
                        elif kind == 6 and state == "CONFIGURE":
                            write(request(11, 3)); state = "CSE"
                        elif kind == 12 and state == "CSE":
                            state = "RUN"
                            for n in (40,78,79,124,125):
                                sequence=(sequence+1)&255
                                event=bytearray(source[n]);event[12]=sequence;write(bytes(event))
                        elif kind in (7, 17, 0x33dd01):
                            write(packet(kind + 1, seq, bytes.fromhex("0021000400000000")))
                        save()
            if state == "RUN" and time.monotonic() - last_echo > 10:
                sequence = (sequence + 1) & 255
                if echo_source:
                    echo=bytearray(echo_source);echo[12]=sequence;write(bytes(echo))
                else:write(packet(13, sequence))
                last_echo = time.monotonic(); save()
            if state != "RUN" and time.monotonic() - started > 30:
                raise RuntimeError("vendor simulated AP did not reach RUN; inspect OpenSSL/serial logs")
    finally:
        proc.terminate()
        try: proc.wait(timeout=3)
        except subprocess.TimeoutExpired: proc.kill(); proc.wait()
        state = "STOPPED"; save()
        trace.close(); stderr.close(); local.close(); remote.close()


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("action", choices=("start", "serve", "status", "stop"))
    args = p.parse_args()
    DIRECTORY.mkdir(parents=True, exist_ok=True)
    status = DIRECTORY / "status.json"
    if args.action == "serve":
        return serve()
    state = json.loads(status.read_text()) if status.exists() else {}
    pid = state.get("pid")
    command = Path(f"/proc/{pid}/cmdline")
    active = pid and command.exists() and os.fsencode(__file__) in command.read_bytes() and state.get("state") != "STOPPED"
    if args.action == "status":
        print(json.dumps(state)); return 0 if active else 1
    if args.action == "stop":
        if active: os.kill(pid, signal.SIGTERM)
        return 0
    if active:
        raise SystemExit("oracle AP already running")
    with (DIRECTORY / "worker.log").open("ab") as log:
        process = subprocess.Popen([sys.executable, str(Path(__file__).resolve()), "serve"],
             stdin=subprocess.DEVNULL, stdout=log, stderr=log, start_new_session=True)
    status.write_text(json.dumps({"pid": process.pid, "state": "STARTING"}))
    print("Simulated AP started for QEMU only, PID", process.pid)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
