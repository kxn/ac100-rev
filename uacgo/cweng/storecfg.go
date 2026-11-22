package cweng

import (
	"os"

	"uacgo/capwap"
	"uacgo/store"
)

// StoreWserviceConfig adapts the SQLite stores to the engine's
// WserviceConfig interface (wserv_tbl rows → SSID envelopes;
// rdmngrTable rows → radio parameter envelopes).
//
// Wire field mapping follows the vendor fixtures:
//   - wsrv para (0x09) 9-byte head, wlan-list entry radio id
//     (cw_priv_wsrv_para_parse @0x5ce6f8 / cw_priv_wlan_list_parse @0x5cba28)
//   - adv rd para head order per cw_priv_adv_rd_para_parse @0x5a3654
//   - rate (0x0a) 55-byte payload defaults come from data/rate-default.bin
//     (extracted from the firmware .data fixture cw_cfg_update_req)
type StoreWserviceConfig struct {
	Stores *store.Stores
	// RateDefault is the 55-byte vendor rate payload (data/rate-default.bin).
	RateDefault []byte
}

// LoadRateDefault reads data/rate-default.bin.
func LoadRateDefault(path string) ([]byte, error) {
	return os.ReadFile(path)
}

// WlanServices implements WserviceConfig. The radio for each SSID comes
// from the wserv_rd.db bind_tbl rows (radio_id → wserv1..8/vlan1..8);
// unbound services default to radio 1.
func (s *StoreWserviceConfig) WlanServices() []WlanService {
	rows, err := s.Stores.Wserv.WservRows()
	if err != nil {
		return nil
	}
	binds, _ := s.Stores.WservRd.BindRows()
	radioOf := map[int64]int64{}
	vlanOf := map[int64]int64{}
	for _, b := range binds {
		for i := 0; i < 8; i++ {
			if b.Wserv[i] != 0 {
				radioOf[b.Wserv[i]] = b.RadioID
				vlanOf[b.Wserv[i]] = b.Vlan[i]
			}
		}
	}
	var out []WlanService
	for _, r := range rows {
		if r.Enable != "" && r.Enable != "0" && r.Enable != "off" {
			var svc WlanService
			svc.WservID = uint8(r.WservID)
			svc.RadioID = uint8(radioOf[r.WservID])
			if svc.RadioID == 0 {
				svc.RadioID = 1
			}
			if vlanOf[r.WservID] != 0 {
				r.Vlan = vlanOf[r.WservID]
			}
			copy(svc.SSID[:], r.SSID)
			svc.Para = PrivWsrvParaFields{
				A: uint8(r.WservID), B: 2,
				C: 1,
				D: uint16(r.Vlan),
			}
			out = append(out, svc)
		}
	}
	return out
}

// Radios implements WserviceConfig.
func (s *StoreWserviceConfig) Radios() []RadioConfig {
	rows, err := s.Stores.Rdmngr.RdmngrRows()
	if err != nil {
		return nil
	}
	var rate capwap.PrivRate
	if len(s.RateDefault) == 55 {
		if p, err := capwap.ParsePrivRate(s.RateDefault); err == nil {
			rate = *p
		}
	}
	var out []RadioConfig
	for _, r := range rows {
		var adv capwap.PrivAdvRdPara
		adv.RadioID = uint8(r.RfID)
		adv.Byte15 = 0xff
		// head bytes 1..14 in parse order (@0x5a3654):
		// [1] band, [2] mode, [3] ?, [4..5] BE16 bandwidth,
		// [6] channel, [7] power, [8..0xc] reserved, [0xd] pad, [0xe..0xf]
		adv.Head = [14]byte{uint8(r.FreqBand), uint8(r.Mode), 1,
			byte(r.Bandwidth >> 8), byte(r.Bandwidth),
			uint8(r.Channel), uint8(r.PowerLevel),
			0, 0, 0, 0, 0, 0, 0}
		rate.RadioID = uint8(r.RfID)
		out = append(out, RadioConfig{RadioID: uint8(r.RfID), AdvRd: adv, Rate: rate})
	}
	return out
}
