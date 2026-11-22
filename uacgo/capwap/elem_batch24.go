package capwap

import "strconv"

// Batch-24: the ACS channel-scan elements (wsta intelligent roam path).
//
// 0x9b "private chnl_scan" (min 2 max 0x202, AC→AP) — the ACS scan
// request (_wsta_intelligent_roam_start_acs_send @0x483f7c: per-radio
// {idx, len, channel string}, e.g. "1,6,11"). Retrieve sequence
// cw_priv_chnl_scan_parse@0x5ad7dc: r8 r8 r8 r8 rbytes (2-byte head +
// one representative entry {idx, len, bytes}).
type ChnlScanEntry struct {
	RadioIdx uint8
	Channels string // comma-separated channel list
}

// PrivChnlScan carries the per-radio scan channel lists.
type PrivChnlScan struct {
	Head    [2]byte
	Entries []ChnlScanEntry
}

// AssembleValue writes the scan request.
func (p PrivChnlScan) AssembleValue() []byte {
	b := append([]byte(nil), p.Head[:]...)
	for _, e := range p.Entries {
		b = append(b, e.RadioIdx, byte(len(e.Channels)))
		b = append(b, e.Channels...)
	}
	return b
}

// ParsePrivChnlScan decodes the scan request.
func ParsePrivChnlScan(v []byte) (*PrivChnlScan, error) {
	if len(v) < 2 {
		return nil, ErrShortPacket
	}
	p := &PrivChnlScan{Head: [2]byte{v[0], v[1]}}
	off := 2
	for off < len(v) {
		if off+2 > len(v) {
			return nil, ErrShortPacket
		}
		idx := v[off]
		l := int(v[off+1])
		off += 2
		if off+l > len(v) {
			return nil, ErrShortPacket
		}
		p.Entries = append(p.Entries, ChnlScanEntry{
			RadioIdx: idx, Channels: string(v[off : off+l]),
		})
		off += l
	}
	return p, nil
}

// ChnlScanRecord is one 9-byte per-channel scan sample of 0x9c (the
// consumer copies the first 8 bytes — _wsta_roam_pkt_chnl_scan_report
// @0x489024: [0] channel index, [1] accumulated A, [2] accumulated B,
// [3] flag; A/B carry the per-channel BSS/load aggregates).
type ChnlScanRecord struct {
	Channel uint8
	SumA    uint8
	SumB    uint8
	Flag    uint8
	Wire    [5]byte // remaining raw bytes
}

// PrivChnlScanReport is 0x9c (min=max=0x200, AP→AC): u8 count +
// count × 9-byte records, the whole value fixed at 512 bytes.
type PrivChnlScanReport struct {
	Records []ChnlScanRecord
}

// AssembleValue writes the 512-byte report.
func (p PrivChnlScanReport) AssembleValue() []byte {
	b := make([]byte, 0x200)
	b[0] = byte(len(p.Records))
	off := 1
	for _, r := range p.Records {
		if off+9 > 0x200 {
			break
		}
		b[off] = r.Channel
		b[off+1] = r.SumA
		b[off+2] = r.SumB
		b[off+3] = r.Flag
		copy(b[off+4:off+9], r.Wire[:])
		off += 9
	}
	return b
}

// ParsePrivChnlScanReport decodes the 512-byte report.
func ParsePrivChnlScanReport(v []byte) (*PrivChnlScanReport, error) {
	if len(v) != 0x200 {
		return nil, ErrShortPacket
	}
	p := &PrivChnlScanReport{}
	cnt := int(v[0])
	off := 1
	for i := 0; i < cnt; i++ {
		if off+9 > len(v) {
			break
		}
		var r ChnlScanRecord
		r.Channel, r.SumA, r.SumB, r.Flag = v[off], v[off+1], v[off+2], v[off+3]
		copy(r.Wire[:], v[off+4:off+9])
		p.Records = append(p.Records, r)
		off += 9
	}
	return p, nil
}

// ParseChnlList parses the "1,6,11" style channel list.
func ParseChnlList(s string) []int {
	var out []int
	start := 0
	for i := 0; i <= len(s); i++ {
		if i == len(s) || s[i] == ',' {
			if i > start {
				if n, err := strconv.Atoi(s[start:i]); err == nil {
					out = append(out, n)
				}
			}
			start = i + 1
		}
	}
	return out
}
