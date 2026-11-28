#!/usr/bin/env python3
"""Run the built Go AC images on an isolated Docker network, without lab APs."""
import argparse
import json
import ipaddress
import pathlib
import socket
import struct
import subprocess
import tempfile
import time
import urllib.error
import urllib.request
import uuid

ROOT = pathlib.Path(__file__).resolve().parents[1]


def docker(*args):
    return subprocess.check_output(['docker', *args], text=True).strip()


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--platform', choices=('linux/amd64', 'linux/arm64'), default='linux/amd64')
    p.add_argument('--image', default='go-ac:latest', help='Base name:tag before architecture/flavor suffixes')
    args = p.parse_args()
    arch = args.platform.split('/')[1]
    name = 'go-ac-check-' + uuid.uuid4().hex[:10]
    work = ROOT / '.local/ac100/docker-check'
    work.mkdir(parents=True, exist_ok=True)
    report = {'platform': args.platform, 'runs': []}
    containers = []
    network_created = volume_created = cert_volume_created = False
    with tempfile.TemporaryDirectory(dir=work) as tmp:
        tmp = pathlib.Path(tmp)
        certs = tmp / 'certs'
        certs.mkdir(mode=0o755)
        subprocess.run(['openssl', 'req', '-x509', '-newkey', 'rsa:2048', '-nodes', '-days', '1', '-subj', '/CN=container-smoke-only', '-keyout', str(certs / 'privkey.pem'), '-out', str(certs / 'cacert.pem')], check=True, capture_output=True)
        # Synthetic test key only. The temporary parent remains mode0700.
        for path in certs.iterdir():
            path.chmod(0o444)
        try:
            docker('network', 'create', '--internal', name)
            network_created = True
            docker('volume', 'create', name)
            volume_created = True
            docker('volume', 'create', name + '-certs')
            cert_volume_created = True
            docker('run', '--rm', '--platform', args.platform, '--network', 'none', '--user', '0:0', '--cap-drop', 'ALL', '--cap-add', 'CHOWN', '--cap-add', 'DAC_OVERRIDE', '--cap-add', 'FOWNER', '-v', name + '-certs:/certs', '-v', str(certs) + ':/source:ro', '--entrypoint', '/bin/sh', args.image + '-' + arch, '-c', 'cp /source/cacert.pem /source/privkey.pem /certs/ && exec /usr/local/bin/go-ac-entrypoint init-certs')
            net = json.loads(docker('network', 'inspect', name))[0]
            # Recreate Docker's freshly allocated subnet as explicit IPAM so
            # the test can assign a stable DHCP server address across restarts.
            subnet = net['IPAM']['Config'][0]['Subnet']
            gateway = net['IPAM']['Config'][0]['Gateway']
            docker('network', 'rm', name)
            network_created = False
            docker('network', 'create', '--internal', '--subnet', subnet, '--gateway', gateway, name)
            network_created = True
            # The first address after the gateway is the isolated AC endpoint.
            gateway = net['IPAM']['Config'][0]['Gateway']
            address = str(ipaddress.IPv4Address(gateway) + 1)
            for index, flavor in enumerate(('no-dhcp', 'dhcp', 'no-dhcp')):
                suffix = '-dhcp' if flavor == 'dhcp' else ''
                image = args.image + '-' + arch + suffix
                if index:
                    docker('run', '--rm', '--platform', args.platform, '--network', 'none', '--user', '0:0', '--cap-drop', 'ALL', '--cap-add', 'CHOWN', '--cap-add', 'DAC_OVERRIDE', '--cap-add', 'FOWNER', '-v', name + ':/data', image, 'init-data')
                dhcp = tmp / ('ap-dhcp-' + str(index) + '.json')
                lo = str(ipaddress.IPv4Address(gateway) + 100)
                hi = str(ipaddress.IPv4Address(gateway) + 120)
                mask = str(ipaddress.IPv4Network(net['IPAM']['Config'][0]['Subnet']).netmask)
                dhcp.write_text(json.dumps({'interface': 'eth0', 'server': address, 'start': lo, 'end': hi, 'netmask': mask, 'ac': [address], 'lease_seconds': 3600, 'lease_file': '/data/ap-dhcp-leases.json'}))
                dhcp.chmod(0o444)
                cid = name + '-' + str(index)
                port = 18090 + index
                command = ['run', '-d', '--name', cid, '--platform', args.platform, '--network', name, '--ip', address, '--cap-drop', 'ALL', '--security-opt', 'no-new-privileges:true', '--read-only', '--tmpfs', '/tmp', '-v', name + ':/data', '-v', name + '-certs:/certs:ro', '-e', 'AC_INTERFACE=eth0', '-e', 'AC_HTTP_PORT=' + str(port)]
                if arch == 'amd64':
                    command += ['--memory', '128m', '--memory-swap', '128m']
                if flavor == 'dhcp':
                    command += ['--cap-add', 'NET_BIND_SERVICE', '--cap-add', 'NET_RAW', '-v', str(dhcp) + ':/etc/go-ac/ap-dhcp.json:ro']
                command += [image]
                docker(*command)
                containers.append(cid)
                url = 'http://' + address + ':' + str(port) + '/api/'

                def api(path, body=None, wait=False):
                    deadline = time.monotonic() + (60 if wait else 0)
                    while True:
                        try:
                            data = None if body is None else json.dumps(body).encode()
                            req = urllib.request.Request(url + path, data=data, headers={'Content-Type': 'application/json'})
                            # Ignore host proxy settings for this private test network.
                            return json.load(urllib.request.build_opener(urllib.request.ProxyHandler({})).open(req, timeout=2))
                        except urllib.error.HTTPError as error:
                            raise RuntimeError(f"HTTP {error.code}: {error.read().decode()}") from error
                        except (OSError, urllib.error.URLError):
                            if time.monotonic() >= deadline:
                                raise RuntimeError('HTTP startup failed: ' + docker('logs', cid)[-3000:])
                            time.sleep(0.2)

                api('config', wait=True)
                status = docker('exec', cid, 'cat', '/proc/1/status')
                fields = dict(line.split(':', 1) for line in status.splitlines() if ':' in line)
                uid = int(fields['Uid'].split()[0])
                caps = int(fields['CapEff'].strip(), 16)
                assert (uid, caps) == ((0, 0x2400) if flavor == 'dhcp' else (10001, 0)), (flavor, uid, caps)
                udp = docker('exec', cid, 'cat', '/proc/net/udp')
                dhcp_bound = any(line.split()[1].endswith(':0043') for line in udp.splitlines()[1:])
                assert dhcp_bound == (flavor == 'dhcp'), (flavor, udp)
                dhcp_status = api('ap-dhcp')
                if flavor == 'dhcp':
                    assert dhcp_status['running'] and dhcp_status['settings']['enabled']
                    settings = dhcp_status['settings']
                    settings['enabled'] = False
                    assert not api('ap-dhcp', settings)['running'], 'Web disable did not close DHCP socket'
                    settings['enabled'] = True
                    settings['reservations'] = {'02:00:00:00:00:21': lo}
                    assert api('ap-dhcp', settings)['running'], 'Web enable failed with read-only seed mount'
                    assert json.loads(docker('exec', cid, 'cat', '/etc/go-ac/ap-dhcp.json')) == json.loads(dhcp.read_text()), 'Web save changed read-only seed'
                else:
                    assert dhcp_status['available'] is False, 'No-DHCP profile allowed saved service to activate'
                with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
                    sock.settimeout(3)
                    sock.sendto((ROOT / 'uacgo/testdata/cw_dis_req_0074f340.bin').read_bytes(), (address, 5246))
                    reply, _ = sock.recvfrom(65535)
                    assert struct.unpack('>I', reply[8:12])[0] == 2, 'No CAPWAP discovery response'
                    # Control IPv4 Address TLV type10: count2/address4/port2.
                    cursor = 16
                    control_addresses = []
                    while cursor + 4 <= len(reply):
                        typ, length = struct.unpack('>HH', reply[cursor:cursor + 4])
                        value = reply[cursor + 4:cursor + 4 + length]
                        if typ == 10:
                            control_addresses.append(value)
                        cursor += length + 4
                    assert any(socket.inet_aton(address) in v for v in control_addresses), 'Advertised stale sample control IP'
                if index:
                    assert api('controller/resources')['settings']['max_ap_sessions'] == 1025, 'Profile switch lost saved config'
                container = json.loads(docker('inspect', cid))[0]
                assert 'GOMEMLIMIT=64MiB' in container['Config']['Env'], 'Missing Go runtime memory budget'
                if arch == 'amd64':
                    assert container['HostConfig']['Memory'] == 128 << 20, 'Native memory smoke has no hard limit'
                if arch == 'amd64' and index == 0:
                    # A sparse, synthetic modern image exercises the real upload
                    # path under a hard memory cap without involving any AP.
                    size = 32 << 20
                    header = bytearray(4096)
                    header[4:24] = bytes.fromhex('55aa4c5e831f534ba1f8f7c918df8fbf7da1aa55')
                    header[0x404:0x418] = bytes.fromhex('55aa9dd1a8c88331c969fbbfbcf0d43270c7aa55')
                    custom = bytes.fromhex('a5a5a5a58f72632a040f86009206bb51d2b7636a')
                    header[0x204:0x218] = header[0x604:0x618] = custom
                    struct.pack_into('>H', header, 0x21e, 1)
                    header[0x220:0x226] = b'tpHead'
                    struct.pack_into('>II', header, 0x22c, 0x400, size - 0x400)
                    struct.pack_into('>H', header, 0xa0, 1)
                    header[0xb0:0xc0] = bytes([0x42]) * 16
                    header[0x4b0:0x4c0] = bytes([0x73]) * 16
                    header[0x4c0:0x4c7] = b'TL-TEST'
                    version = b'1.2.3 Build 20250317 Rel.43192'
                    header[0x618:0x618 + len(version)] = version
                    image_path = tmp / 'memory-fixture.bin'
                    with image_path.open('wb') as f:
                        f.write(header)
                        f.truncate(size)
                    opener = urllib.request.build_opener(urllib.request.ProxyHandler({}))
                    with image_path.open('rb') as f:
                        request = urllib.request.Request(url + 'upgrades/images', data=f, method='POST', headers={'Content-Type': 'application/octet-stream', 'Content-Length': str(size)})
                        with opener.open(request, timeout=60) as response:
                            image = json.load(response)
                    assert image['size'] == size, 'Streaming upload truncated the image'
                    status = docker('exec', cid, 'cat', '/proc/1/status')
                    fields = dict(line.split(':', 1) for line in status.splitlines() if ':' in line)
                    report['firmware_upload'] = {'size_mib': 32, 'container_limit_mib': 128, 'process_peak_rss_mib': round(int(fields['VmHWM'].split()[0]) / 1024, 2)}
                    with opener.open(urllib.request.Request(url + 'upgrades/images/' + image['id'], method='DELETE'), timeout=10) as response:
                        assert response.status == 200
                api('controller/resources', {'max_ap_sessions': 1025})
                docker('restart', cid)
                assert api('controller/resources', wait=True)['settings']['max_ap_sessions'] == 1025, 'Restart lost saved config'
                if flavor == 'dhcp':
                    assert api('ap-dhcp')['settings']['reservations'] == settings['reservations'], 'Restart lost web DHCP configuration'
                docker('stop', cid)
                assert json.loads(docker('inspect', cid))[0]['State']['ExitCode'] == 0, 'Ungraceful SIGTERM shutdown'
                docker('rm', cid)
                containers.remove(cid)
                report['runs'].append({'flavor': flavor, 'http_port': port, 'uid': uid, 'effective_capabilities': hex(caps), 'dhcp_bound': dhcp_bound, 'discovery': 'passed', 'persistence': 'passed'})
        finally:
            for cid in containers:
                subprocess.run(['docker', 'rm', '-f', cid], capture_output=True)
            if cert_volume_created:
                subprocess.run(['docker', 'volume', 'rm', name + '-certs'], capture_output=True)
            if volume_created:
                subprocess.run(['docker', 'volume', 'rm', name], capture_output=True)
            if network_created:
                subprocess.run(['docker', 'network', 'rm', name], capture_output=True)
    path = work / (arch + '.json')
    path.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
