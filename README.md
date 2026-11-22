# ac100-rev

Reverse-engineering workspace for the TP-Link TL-AC100 `uac` binary (CAPWAP
AC controller, MIPS32 big-endian, dynamically linked against uClibc/GnuTLS)
and a from-scratch, pure-Go reimplementation of it.

**Status**: the Go implementation covers the full CAPWAP session path
(discovery → join → config-status → change-state → echo, DTLS, image
upgrade, LED/reset control, the vendor 0x25 envelope, 118 registered
message elements) plus the JCS control-socket surface (~100 handlers,
all former not-impl placeholders closed), and the AC-side decision
engines: wsta_roam centralized steering (0x58 trigger → RCPI normalize →
filter → vendor rate estimation → admission → 0x59 result, with the
`estimate_snr_rate_table_2g/5g` + `nsdTable` data extracted from the AC
binary into `uacgo/data/estimate-rate-tables.bin`; rate-estimation
semantics follow **AC300** — nf −85 / gate −84 / bw up to 160M — with
AC100's classic constants selectable via `RateModel`), the balance
admission engine, 11r PMK distribution, the RRM/ACS engine (state
machine + DCA + TPC + ACS channel selection; 0x5c/0x5d/0x9b/0x9c
wiring), the mac_auth admission tree, and the defense config push
builders (0x46/0x47/0x48/0x61/0x62). The AP side of the protocol is
cross-checked against the TL-XAP5407GC firmware
(`notes/apfw-xap5407gc-crosscheck.md`) — interaction validation only;
all data and logic provenance is the AC binary.
`go test ./...` is green (except `TestEngineApLifecycle`, which needs
UDP loopback; verified failing on the pre-change baseline in this
environment); `linux/amd64`, `linux/arm64`, `windows/amd64` build with
`CGO_ENABLED=0`.

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

## Build / test

```
cd uacgo
go build ./...          # CGO_ENABLED=0 by default; no cgo anywhere
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

Known gaps are documented in `uacgo/docs/ondevice-verify.md`: four checks
that require a real TL-AC100 or a live AP (JCS frame capture,
SendImageNotify direction, profile value calibration, on-wire DTLS
interop with the device's GnuTLS stack). The DTLS integration itself is
verified end-to-end in-process (`cweng/dtls_pion_test.go`).

## Notes for contributors

- Keep everything pure Go / zero cgo.
- When a new protocol conclusion is added, cite the binary address in
  `notes/00-architecture.md` and extend `element_retseq.txt` if it
  touches an element codec.
- The vendor certificate files are the ones shipped inside the public
  firmware image; nothing here is device-specific.
