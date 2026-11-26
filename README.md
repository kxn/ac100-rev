# ac100-rev

> 2026-11-27：本轮已按 V6 原固件有效入口整改调度策略，并建立双向核查索引。已部署的 `587d414` 和此前模拟/单 AP 结果不证明算法等价。当前改动未部署；整改状态和源码依据见 [调度策略对照](docs/mobility-parity-audit.md)。


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
| `uacgo/data/` | firmware-derived runtime data the daemon reads from files (AP DB seed and protocol reference data) |
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
`cmd/acd` flags): `identity.json` / `apdb.json` / `controller.json`.
Standalone WLAN/RF configuration has one authority in `controller.json`;
SQLite retains AP identity IDs. The legacy JCS server and SQLite WLAN/RF
response builders are research adapters and are not registered by `acd`.
`rate-default.bin` and reconstructed `profile.ini` are only needed by
reference adapters. Standalone startup does not read the original hardware
profile. Program capacities have Go defaults and can be edited live on the
**程序配置** page; they are saved in `controller.json` and included in backups.
AP capabilities, wire constraints and firmware roaming/RRM policies remain
separate from these budgets.


## Evidence method

Current V6 strategy and protocol conclusions are traced to the supplied
firmware's active entry points, call sites and compiled data. The version-pinned
[policy audit](docs/mobility-parity-audit.md) and
[bidirectional index](docs/uac-web-parity-map.json) distinguish active code,
excluded features, legacy research adapters and unknown flash-only settings.
Older address notes and fixture tests are references; they do not prove V6
policy equivalence. `tools/audit_mobility_firmware.py` and
`tools/check_parity_map.py` reproduce the static evidence checks.

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
