# ac100-rev

Reverse-engineering workspace for the TP-Link TL-AC100 `uac` binary (CAPWAP
AC controller, MIPS32 big-endian, dynamically linked against uClibc/GnuTLS)
and a from-scratch, pure-Go reimplementation of it.

**Status**: the standalone Go daemon manages a real TL-7AP5100HC AP through
a pure-Go DTLS 1.0 compatibility transport. The embedded Web UI covers AP
management, WLAN services, radio controls, clients and wireless history,
AP coordination, Mesh and capability-dependent options. Selective TP-Link AP
DHCP is available separately from the lab's ordinary DHCP/DNS/NAT tools.
Controller logic has UDP simulated-AP and API/UI regression coverage; real
multi-AP roaming and hardware-specific behavior remain compatibility checks.
See [AC acceptance](docs/ac-acceptance.md), [measured progress](docs/go-live-status.md)
and [product scope](docs/implementation-plan.md). QEMU is a reference controller,
not a runtime dependency. Delivery builds use `CGO_ENABLED=0`.

## Layout

| path | contents |
|---|---|
| `uacgo/` | the Go reimplementation (`capwap` wire codecs, `cweng` engine+FSM+DTLS, `jcs` control-socket handlers, `store` SQLite layer, `cmd/acd` daemon) |
| `uacgo/data/` | firmware-derived runtime data the daemon reads from files (`profile.ini` reconstruction, AP DB seed, rate table) |
| `notes/` | evidence notes with binary addresses for every implemented conclusion (`00-architecture.md`), element registry (`elements.tsv`), dispatch registry (`registry.tsv`), per-function retrieve sequences (`element_retseq.txt`) |
| `firmware/usr/sbin/` | the `uac` binary and the firmware-shipped symbol tables (`uac_symbol_fun` 5683 functions, `uac_symbol_obj` 1213 objects). The firmware image is publicly downloadable from the vendor site |
| `asm/` | one annotated disassembly file per function (symbol names from the shipped tables) |
| `ghidra-export/` | full Ghidra decompilation (one pseudocode file per function), extracted vendor packet fixtures, element registry dump, string table |
| `tools/` | the extraction/annotation tooling (objdump annotator, Ghidra batch exporter, element-registry extractor, call-site argument extractor) |
| `uacgo/docs/ondevice-verify.md` | the remaining on-device verification checklist (needs a real TL-AC100 / live AP) |

## Environment

Start with `source tools/env.sh` and `python3 tools/check_env.py`. The
QEMU/vendor-Web evidence uses TL-AC100 V6.0 **1.0.3 Build 260817 Rel.68871n**
and a separate complete rootfs; the checked-in legacy binary has a different
address map. See [docs/setup.md](docs/setup.md) for installation, firmware
import, native Linux USB/AP networking, and both extraction workflows.

## Build / test

```
cd uacgo
CGO_ENABLED=0 go build ./...
go test ./...           # packet fixtures in ghidra-export/data are exercised
AC100_REV_ROOT=/path/to/checkout go test ./...   # optional override
```

Needs Go 1.26+ and network access for the first module download — nothing
else. To rebuild the reverse-engineering corpus from the binary (annotated
disassembly, Ghidra pseudocode, registries) or to keep reversing, see
**`docs/setup.md`** (full toolchain walkthrough: objdump/Ghidra versions,
exact commands, env vars, known pitfalls).

The daemon reads its runtime data from a data directory (see
`cmd/acd` flags): `identity.json` / `profile.ini` / `apdb.json` /
`rate-default.bin`. `profile.ini` values marked `(recon)` are
reconstructions pending calibration against a live device
(`uci show profile`).

## Evidence method

Every conclusion that landed in the Go code was re-derived directly from
the `uac` binary this pass (disassembly, decompilation, shipped symbol
tables, vendor packet fixtures) — earlier analysis documents were treated
as references only. `notes/00-architecture.md` records the address anchors
section by section; `tools/` regenerates the corpus from
`firmware/usr/sbin/uac`.

Implementation and device-validation boundaries are documented in
[uacgo/docs/ondevice-verify.md](uacgo/docs/ondevice-verify.md). Pion DTLS 1.2
component tests and the AP's legacy DTLS compatibility transport are separate;
passing fixture tests alone does not establish device interoperability.

## Notes for contributors

- Keep everything pure Go / zero cgo.
- When a new protocol conclusion is added, cite the binary address in
  `notes/00-architecture.md` and extend `element_retseq.txt` if it
  touches an element codec.
- The vendor certificate files are the ones shipped inside the public
  firmware image; nothing here is device-specific.
