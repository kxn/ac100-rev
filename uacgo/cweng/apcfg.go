package cweng

import (
	"uacgo/capwap"
)

// APConfig carries the AP management bundle pushed via a Configuration
// Update Request (msg 7), mirroring _apmngr_pkt_element_encap @0x555818:
//
//	envelope priv 0x05 base para (keep-alives)
//	envelope priv 0x3c offline mngr (6 words)
//	element 0x0c capwap timers (discovery/echo)
//	element 0x17 idle timeout
//	envelope priv 0x3d ap user (64B username + 64B password)
type APConfig struct {
	BasePara    capwap.PrivApBasePara
	OfflineMngr capwap.PrivApOfflineMngr
	DiscoveryT  uint8
	EchoT       uint8
	IdleTimeout uint32
	User        capwap.PrivApUser
}

// SendAPConfigBundle builds and sends the bundle as one msg 7.
func (e *Engine) SendAPConfigBundle(s *Session, cfg APConfig) error {
	s.mu.Lock()
	next := s.OutSeq + 1
	if s.OutSeq == 0xff {
		next = 1
	}
	s.OutSeq = next
	s.mu.Unlock()

	pkt, err := capwap.NewParsedPacket(capwap.MsgConfigurationUpdateRequest)
	if err != nil {
		return err
	}
	pkt.Header.Rid = 1
	pkt.Control.SeqNum = next
	add := func(privType uint16, val []byte) {
		pkt.Elements = append(pkt.Elements, capwap.Element{
			Type: 0x0025, Value: capwap.VendorEnvelopeValue(0x12345678, 0,
				[]capwap.PrivElementValue{{Type: privType, Value: val}})})
	}
	add(0x05, cfg.BasePara.AssembleValue())
	add(0x3c, cfg.OfflineMngr.AssembleValue())
	pkt.Elements = append(pkt.Elements, capwap.Element{
		Type: 0x000c, Value: []byte{cfg.DiscoveryT, cfg.EchoT}})
	pkt.Elements = append(pkt.Elements, capwap.Element{
		Type: 0x0017, Value: []byte{
			byte(cfg.IdleTimeout >> 24), byte(cfg.IdleTimeout >> 16),
			byte(cfg.IdleTimeout >> 8), byte(cfg.IdleTimeout)}})
	add(0x3d, cfg.User.AssembleValue())
	return e.sendTo(s.Addr, pkt.Assemble())
}
