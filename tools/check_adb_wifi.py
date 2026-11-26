#!/usr/bin/env python3
"""Exercise the dedicated AP lab with an authorized Android ADB client.

cycle toggles tablet Wi-Fi; radios additionally disables/restores each AP
radio in turn. Results are private. Original radio settings are restored in
finally. This requires a live Go AC, lab DHCP/DNS/NAT and the saved lab SSID.
"""
import argparse
import datetime
import json
import pathlib
import re
import shlex
import subprocess
import time
import urllib.request

ROOT = pathlib.Path(__file__).resolve().parents[1]


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("case", choices=("status", "cycle", "radios"))
    p.add_argument("--serial", required=True)
    # Explicit SSID allows temporary service lifecycle verification.
    p.add_argument("--ssid")
    p.add_argument("--url", default="http://127.0.0.1:8090/api/")
    args = p.parse_args()
    out = ROOT / ".local/ac100/adb-tests"
    out.mkdir(mode=0o700, parents=True, exist_ok=True)
    evidence = {"case": args.case, "started": datetime.datetime.now().isoformat(), "steps": []}

    def api(path, body=None):
        req = urllib.request.Request(args.url + path, data=None if body is None else json.dumps(body).encode(), headers={"Content-Type": "application/json"})
        with urllib.request.urlopen(req, timeout=25) as r:
            return json.load(r)

    def adb(*words):
        r = subprocess.run(["adb", "-s", args.serial, "shell", shlex.join(words)], text=True, capture_output=True, timeout=30)
        if r.returncode:
            raise RuntimeError(r.stderr or r.stdout)
        return r.stdout

    deadline=time.monotonic()+90
    while True:
        ap=next((a for a in api("aps") if a["online"]),None)
        if ap is not None:break
        if time.monotonic()>deadline:raise RuntimeError("No online AP within 90 seconds")
        time.sleep(1)
    cfg = api("config")["config"]
    service = next(s for s in cfg["services"] if s["enabled"] and not s.get("deleting") and (args.ssid is None or s["ssid"] == args.ssid))
    ssid = service["ssid"]
    original = [r for r in cfg["radios"] if r["ap_id"] == ap["id"]]
    if args.case == "radios" and {r["radio_id"] for r in original} != {1, 2}:
        raise RuntimeError("Radio matrix requires two explicitly configured lab radios")

    def settled(after=0, limit=100):
        until=time.monotonic()+limit
        while time.monotonic()<until:
            state=next((s for s in api("config")["apply"] if s["ap_id"]==ap["id"] and s["service_id"]=="configuration-commit"),None)
            if state and state["state"] in ("acknowledged","verified"):
                at=datetime.datetime.fromisoformat(state["at"]).timestamp()
                if at>=after and time.time()-at>=13:return
            time.sleep(1)
        raise RuntimeError("AP configuration did not finish committing")

    def connected(band=None, limit=65):
        until = time.monotonic() + limit
        while time.monotonic() < until:
            text = adb("cmd", "wifi", "status")
            freq = re.search(r"Frequency: (\d+)MHz", text)
            ip = re.search(r"IP: /([0-9.]+)", text)
            if f'SSID: "{ssid}"' in text and "Supplicant state: COMPLETED" in text and ip and freq:
                mhz = int(freq[1])
                if band is None or (band == 2 and mhz < 3000) or (band == 5 and 4900 < mhz < 5900):
                    address=adb("ip", "-4", "addr", "show", "dev", "wlan0")
                    if "inet "+ip[1]+"/" in address:
                        return {"wifi_status": text, "frequency": mhz, "ip": ip[1],"interface_address":address}
            time.sleep(1)
        raise RuntimeError(f"Tablet did not connect to lab SSID / band {band}")

    def verify(label, band=None):
        step = connected(band)
        step["label"] = label
        step["at"] = datetime.datetime.now().isoformat()
        step["gateway"] = adb("ping", "-I", "wlan0", "-c", "2", "-W", "3", "192.168.70.1")
        step["https"] = adb("curl", "--interface", "wlan0", "--connect-timeout", "10", "--max-time", "20", "-sS", "-o", "/dev/null", "-w", "%{http_code}", "https://www.baidu.com")
        if step["https"].strip() != "200":
            raise RuntimeError("HTTPS validation failed")
        evidence["steps"].append(step)
        step["ap"] = api("aps")
        mac = re.search(r" MAC: ([0-9a-f:]+)", step["wifi_status"])[1]
        expected_radio = 1 if step["frequency"] < 3000 else 2
        until = time.monotonic() + 140
        while True:
            latest=connected(band,limit=8)
            step.update(latest)
            expected_radio=1 if step["frequency"]<3000 else 2
            step["clients"] = api("clients")
            assignments = api("config")["assignments"]
            expected_wlan = assignments.get(ap["id"], {}).get(service["id"], {}).get(str(expected_radio))
            row = next((c for c in step["clients"] if c["mac"] == mac), None)
            if row and row["state"] == "connected" and row["ap_id"] == ap["id"] and row["radio_id"] == expected_radio and row["wlan_id"] == expected_wlan and row["ip"] == step["ip"]:
                break
            if time.monotonic() > until:
                raise RuntimeError("AC client display did not match tablet AP/radio/address")
            time.sleep(2)
        print(f'{label}: {step["frequency"]} MHz, gateway and DNS/HTTPS passed', flush=True)

    restored=False
    try:
        settled()
        verify("baseline")
        if args.case in ("cycle", "radios"):
            adb("cmd", "wifi", "set-wifi-enabled", "disabled")
            time.sleep(2)
            adb("cmd", "wifi", "set-wifi-enabled", "enabled")
            verify("tablet Wi-Fi reconnect")
        if args.case == "radios":
            for disabled, band in ((2, 2), (1, 5)):
                other = 3 - disabled
                changed=time.time()
                api("radios", {"ap_id": ap["id"], "radio_id": other, "enabled": True})
                api("radios", {"ap_id": ap["id"], "radio_id": disabled, "enabled": False})
                settled(changed)
                verify(f"radio {disabled} disabled / other band usable", band)
                # Wait for this desired state to reach the AP before restoring.
                changed=time.time()
                api("radios", next(r for r in original if r["radio_id"] == disabled))
                settled(changed)
            changed=time.time()
            for r in original:
                api("radios", r)
            settled(changed)
            adb("cmd", "wifi", "set-wifi-enabled", "disabled")
            time.sleep(2)
            adb("cmd", "wifi", "set-wifi-enabled", "enabled")
            verify("both radios restored")
            restored=True
    except Exception as exc:
        evidence["error"] = str(exc)
        raise
    finally:
        if args.case == "radios" and not restored:
            for r in original:
                api("radios", r)
        if args.case != "status":
            adb("cmd", "wifi", "set-wifi-enabled", "enabled")
        path = out / (datetime.datetime.now().strftime("%Y%m%d-%H%M%S-") + args.case + ".json")
        path.write_text(json.dumps(evidence, ensure_ascii=False, indent=2) + "\n")
        path.chmod(0o600)
        print("Private evidence:", path, flush=True)


if __name__ == "__main__":
    main()
