package cweng

import (
	"bytes"

	"uacgo/capwap"
)

// wserv / rdmngr subsystems.
//
// Registry evidence (registry.tsv): uac_wservice registers msg 5 (cfg status)
// listener at priority 100; rdmngr registers msg 3 (join, 0x73=115),
// msg 5 (0x5a=90) and msg 9 (0x5a). Their listeners add the SSID/radio
// envelopes to the shared response (0x25 payloads 0x1e wlan list, 0x09/0x63
// wsrv para, 0x08 adv rd para, 0x0a rate).

// WlanService mirrors one wserv_tbl row (SSID service).
type WlanService struct {
	WservID uint8
	RadioID uint8
	SSID    [32]byte // fixed 32-byte field in the wire format
	// wsrv para 0x09 header fields (semantics from wserv_tbl usage; wire
	// order per cw_priv_wsrv_para_parse @0x5ce6f8)
	Para PrivWsrvParaFields
}

// PrivWsrvParaFields are the 9 header bytes of the 0x09/0x63 elements.
type PrivWsrvParaFields struct {
	A       uint8
	B       uint8
	C       uint16
	D       uint16
	E, F, G uint8
}

// RadioConfig mirrors one rdmngrTable row subset (radio parameters).
type RadioConfig struct {
	RadioID uint8
	AdvRd   capwap.PrivAdvRdPara
	Rate    capwap.PrivRate
}

// WserviceConfig is the config-source interface for the wserv/rdmngr handlers.
type WserviceConfig interface {
	WlanServices() []WlanService
	Radios() []RadioConfig
}

// RegisterWserviceHandlers wires the wserv (msg5 prio 100) and rdmngr
// (msg3 prio 115, msg5 prio 90) listeners.
func (e *Engine) RegisterWserviceHandlers(cfg WserviceConfig) {
	// rdmngr msg 5 (prio 0x5a=90): radio parameters first
	e.Register(5, 90, "rdmngr_cfg_status", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		for _, r := range cfg.Radios() {
			adv := r.AdvRd
			rsp.Elements = append(rsp.Elements, capwap.Element{
				Type: 0x0025, Value: capwap.VendorEnvelopeValue(0x12345678, 0x08,
					[]capwap.PrivElementValue{{Type: 0x08, Value: packAdvRd(&adv)}})})
		}
		return true
	})
	// uac_wservice msg 5 (prio 100): wlan list + per-radio wsrv para
	e.Register(5, 100, "uac_wserv_cfg_status", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		svcs := cfg.WlanServices()
		if len(svcs) == 0 {
			return true
		}
		l := capwap.PrivWlanList{A: uint32(len(svcs))}
		for _, s := range svcs {
			l.Entries = append(l.Entries, capwap.PrivWlanEntry{
				RadioID: s.RadioID, SSID: append([]byte(nil), s.SSID[:]...)})
		}
		rsp.Elements = append(rsp.Elements, capwap.Element{
			Type: 0x0025, Value: capwap.VendorEnvelopeValue(0x12345678, 0x1e,
				[]capwap.PrivElementValue{{Type: 0x1e, Value: l.AssembleValue()}})})
		for _, s := range svcs {
			p := capwap.PrivWsrvPara{
				A: s.Para.A, B: s.Para.B, C: s.Para.C, D: s.Para.D,
				E: s.Para.E, F: s.Para.F, G: s.Para.G,
			}
			rsp.Elements = append(rsp.Elements, capwap.Element{
				Type: 0x0025, Value: capwap.VendorEnvelopeValue(0x12345678, 0x09,
					[]capwap.PrivElementValue{{Type: 0x09, Value: p.AssembleValue()}})})
		}
		return true
	})
	// rdmngr msg 3 (prio 0x73=115): radio parameters on join too
	e.Register(3, 115, "rdmngr_join", func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
		for _, r := range cfg.Radios() {
			adv := r.AdvRd
			rate := r.Rate
			rsp.Elements = append(rsp.Elements, capwap.Element{
				Type: 0x0025, Value: capwap.VendorEnvelopeValue(0x12345678, 0x08,
					[]capwap.PrivElementValue{{Type: 0x08, Value: packAdvRd(&adv)}})})
			rsp.Elements = append(rsp.Elements, capwap.Element{
				Type: 0x0025, Value: capwap.VendorEnvelopeValue(0x12345678, 0x0a,
					[]capwap.PrivElementValue{{Type: 0x0a, Value: rate.AssembleValue()}})})
		}
		return true
	})
}

// packAdvRd serialises the adv-rd-para value at its wire length
// (15-byte head + even-length pad byte, per cw_priv_adv_rd_para_parse).
func packAdvRd(a *capwap.PrivAdvRdPara) []byte {
	b := make([]byte, 0, 16)
	b = append(b, a.RadioID)
	b = append(b, a.Head[:]...)
	if len(b)%2 == 0 { // even total → [0x15] byte participates
		b = append(b, a.Byte15)
	}
	if a.Tail6 != nil {
		b = append(b, a.Tail6...)
	}
	return b
}

// envelopeTLV wraps one private TLV into an envelope value.
func envelopeTLV(field uint16, v []byte) []byte {
	out := []byte{byte(field >> 8), byte(field), byte(len(v) >> 8), byte(len(v))}
	return append(out, v...)
}

var _ = bytes.Equal
