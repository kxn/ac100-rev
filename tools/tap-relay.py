#!/usr/bin/env python3
"""Relay CAPWAP datagrams from a native Linux USB NIC or a WSL upstream to QEMU."""
import argparse
import ipaddress
import os
import selectors
import socket


def endpoint(value):
    host, port = value.rsplit(':', 1)
    return host, int(port)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--listen', default=os.environ.get('AC100_RELAY_LISTEN', '127.0.0.1:5257'),
                        help='USB NIC host address:5246 for native Linux; default loopback:5257')
    parser.add_argument('--target', default='172.30.194.2:5246')
    parser.add_argument('--source', default='172.30.194.1')
    parser.add_argument('--peer-network', default=os.environ.get('AC100_RELAY_PEERS'),
                        help='accept APs only from this IPv4 subnet (native USB link)')
    args = parser.parse_args()
    target = endpoint(args.target)
    allowed = ipaddress.ip_network(args.peer_network) if args.peer_network else None
    with selectors.DefaultSelector() as selector, socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as wire:
        wire.bind(endpoint(args.listen))
        selector.register(wire, selectors.EVENT_READ)
        peers = {}
        print(f'CAPWAP relay {wire.getsockname()} -> {target} via {args.source}', flush=True)
        try:
            while True:
                for key, _ in selector.select():
                    sock = key.fileobj
                    packet, peer = sock.recvfrom(65535)
                    if sock is wire:
                        if allowed and ipaddress.ip_address(peer[0]) not in allowed:
                            continue
                        if peer not in peers:
                            downstream = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                            downstream.bind((args.source, 0))
                            selector.register(downstream, selectors.EVENT_READ, peer)
                            peers[peer] = downstream
                        peers[peer].sendto(packet, target)
                    elif peer == target:
                        wire.sendto(packet, key.data)
        finally:
            for downstream in peers.values():
                downstream.close()


if __name__ == '__main__':
    main()
