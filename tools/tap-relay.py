#!/usr/bin/env python3
"""UDP relay: Windows-side wire relay (127.0.0.1:5257) <-> QEMU TAP AC.

The Windows side owns the physical NIC and forwards CAPWAP datagrams to
127.0.0.1:5257.  WSL2 mirrored networking cannot receive the wire packets
directly, so this process binds a per-peer source address on the TAP
(172.30.194.1) and forwards to the guest uac at 172.30.194.2:5246.
"""
import selectors
import socket

WIRE = ("127.0.0.1", 5257)
AC = ("172.30.194.2", 5246)
TAP_SRC = "172.30.194.1"

selector = selectors.DefaultSelector()
wire = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
wire.bind(WIRE)
selector.register(wire, selectors.EVENT_READ)
peers = {}

while True:
    for key, _ in selector.select():
        sock = key.fileobj
        packet, peer = sock.recvfrom(65535)
        if sock is wire:
            if peer not in peers:
                downstream = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                downstream.bind((TAP_SRC, 0))
                selector.register(downstream, selectors.EVENT_READ, peer)
                peers[peer] = downstream
            peers[peer].sendto(packet, AC)
        elif peer == AC:
            wire.sendto(packet, key.data)
