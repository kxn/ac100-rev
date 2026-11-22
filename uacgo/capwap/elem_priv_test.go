package capwap

import (
	"bytes"
	"encoding/hex"
	"testing"
)

// Round-trip every private-element payload carried by the vendor fixtures.
func envelopePrivs(t *testing.T, fixture string) map[uint16][]byte {
	t.Helper()
	pkt, err := ParsePacket(mustFixtureBytes(t, fixture))
	if err != nil {
		t.Fatal(err)
	}
	out := map[uint16][]byte{}
	for _, e := range pkt.Elements {
		if e.Type == 0x0025 && len(e.Value) >= 6 {
			v := e.Value[6:]
			for len(v) >= 4 {
				pt := uint16(v[0])<<8 | uint16(v[1])
				pl := uint16(v[2])<<8 | uint16(v[3])
				if int(pl)+4 > len(v) {
					break
				}
				out[pt] = v[4 : 4+int(pl)]
				v = v[4+int(pl):]
			}
		}
	}
	return out
}

func TestPrivElementRoundtrips(t *testing.T) {
	// wsrv para (0x09) from cw_wlan_cfg_req: 9-byte header form
	if v := envelopePrivs(t, "cw_wlan_cfg_req_0074ed8c.bin")[0x09]; v != nil {
		p, err := ParsePrivWsrvPara(v)
		if err != nil {
			t.Fatal(err)
		}
		if !bytes.Equal(p.AssembleValue(), v) {
			t.Fatalf("wsrv para roundtrip %x != %x", p.AssembleValue(), v)
		}
	} else {
		t.Fatal("no 0x09 in wlan cfg req")
	}

	// wlan list (0x1e) from cw_cfg_rsp envelope: u32+u32+{radio,32B ssid}
	if v := envelopePrivs(t, "cw_cfg_rsp_0074eeb4.bin")[0x1e]; v != nil {
		l, err := ParsePrivWlanList(v)
		if err != nil {
			t.Fatal(err)
		}
		if len(l.Entries) != 1 {
			t.Fatalf("entries = %d", len(l.Entries))
		}
		if !bytes.HasPrefix(l.Entries[0].SSID, []byte("00_YXJ_")) {
			t.Fatalf("ssid = %q", l.Entries[0].SSID)
		}
		if !bytes.Equal(l.AssembleValue(), v) {
			t.Fatal("wlan list roundtrip mismatch")
		}
	} else {
		t.Fatal("no 0x1e in cfg rsp")
	}

	// adv rd para (0x08) len 16 from cw_cfg_update_req
	if v := envelopePrivs(t, "cw_cfg_update_req_0074ede0.bin")[0x08]; v != nil {
		p, err := ParsePrivAdvRdPara(v)
		if err != nil {
			t.Fatal(err)
		}
		if p.RadioID != 1 {
			t.Fatalf("radio = %d", p.RadioID)
		}
		if !bytes.Equal(p.AssembleValue(), v) {
			t.Fatalf("adv rd para roundtrip %x != %x", p.AssembleValue(), v)
		}
	} else {
		t.Fatal("no 0x08 in cfg update req")
	}

	// rate (0x0a) len 55 from cw_cfg_update_req
	if v := envelopePrivs(t, "cw_cfg_update_req_0074ede0.bin")[0x0a]; v != nil {
		p, err := ParsePrivRate(v)
		if err != nil {
			t.Fatal(err)
		}
		if !bytes.Equal(p.AssembleValue(), v) {
			t.Fatalf("rate roundtrip %x != %x", p.AssembleValue(), v)
		}
		t.Logf("rate radio=%d body=%s...", p.RadioID, hex.EncodeToString(p.Body[:8]))
	} else {
		t.Fatal("no 0x0a in cfg update req")
	}
}
