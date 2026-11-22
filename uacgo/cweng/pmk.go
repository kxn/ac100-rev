package cweng

import (
	"sync"
	"time"

	"uacgo/capwap"
)

// 11r fast-roaming key distribution (PMK-R0 holder role of the AC).
//
// Evidence (AC binary):
//
//	_wsta_roam_pkt_pmk_request @0x486d74 — msg 9 event 0x49 in, stores or
//	looks up the PMK entry and answers inside the WTP event response
//	(cw_service_msg_add …, 0x49, "set wsta assoc rslt vendor payload").
//	wsta_roam_db_pmk_add / _get_by_mac / _expiretime_set /
//	_start_del_timer + _wsta_roam_pmk_idle_timer_handle @0x480eec —
//	idle-expiry lifecycle.
//	wsta_roam_sta_assoc_callback @0x47f130 — on successful roam assoc the
//	AC consumes the entry (expiretime_set(mac, 0)) after checking the
//	wserv match ("wserv_id_cur != wserv_id_pre").
//
// Request type names from the AC string table (PTR_s_inform @0x6f03c0 /
// l_wsta_roam_pkt_info_stat names): inform, inform_suc, request_suc,
// response.
const (
	PmkTypeInform     uint8 = 0
	PmkTypeInformSuc  uint8 = 1
	PmkTypeRequestSuc uint8 = 2
	PmkTypeResponse   uint8 = 3
)

// PmkEntry is one pending fast-roaming key (the AC's wsta_roam_db_pmk row).
type PmkEntry struct {
	Req     capwap.PrivStaPMKReq // key material (pmk_r0 / name / nonce)
	WservID uint32               // expected target wserv (match check on assoc)
	Expires time.Time            // idle deadline
}

// PmkStore is the in-memory PMK cache with idle expiry.
type PmkStore struct {
	mu  sync.Mutex
	ttl time.Duration
	m   map[[6]byte]PmkEntry
}

// NewPmkStore creates a cache; ttl is the idle timeout of an unused entry.
func NewPmkStore(ttl time.Duration) *PmkStore {
	return &PmkStore{ttl: ttl, m: map[[6]byte]PmkEntry{}}
}

// Add stores/refreshes the entry of one STA (wsta_roam_db_pmk_add).
func (s *PmkStore) Add(mac [6]byte, e PmkEntry) {
	s.mu.Lock()
	defer s.mu.Unlock()
	e.Expires = time.Now().Add(s.ttl)
	s.m[mac] = e
}

// Get returns a live entry (wsta_roam_db_pmk_get_by_mac, lazy expiry).
func (s *PmkStore) Get(mac [6]byte) (PmkEntry, bool) {
	s.mu.Lock()
	defer s.mu.Unlock()
	e, ok := s.m[mac]
	if !ok || time.Now().After(e.Expires) {
		delete(s.m, mac)
		return PmkEntry{}, false
	}
	return e, true
}

// Consume marks the entry used after a successful roam assoc
// (wsta_roam_sta_assoc_callback → expiretime_set(mac, 0)).
func (s *PmkStore) Consume(mac [6]byte) {
	s.mu.Lock()
	defer s.mu.Unlock()
	delete(s.m, mac)
}

// Sweep deletes idle entries (the pmk idle timer handler) and returns
// how many were removed.
func (s *PmkStore) Sweep(now time.Time) int {
	s.mu.Lock()
	defer s.mu.Unlock()
	n := 0
	for k, e := range s.m {
		if now.After(e.Expires) {
			delete(s.m, k)
			n++
		}
	}
	return n
}

// Len reports the live entry count.
func (s *PmkStore) Len() int {
	s.mu.Lock()
	defer s.mu.Unlock()
	return len(s.m)
}

// SendPmkResult pushes a 0x49 PMK reply as a standalone config update.
// (The binary answers inside the WTP event response; this helper is for
// the explicit-push path.)
func (e *Engine) SendPmkResult(s *Session, r capwap.PrivStaPMKReq) error {
	return e.sendACRequest(s, capwap.MsgConfigurationUpdateRequest,
		capwap.PrivElementValue{Type: 0x49, Value: r.AssembleValue()})
}

// PmkResponder decides PMK replies for the msg 9 handler.
type PmkResponder struct {
	Store *PmkStore
	// WservOf resolves (ap mac, radio, wlan) to a wserv id for the target
	// match check ("wserv_id_cur != wserv_id_pre"); nil skips the check.
	WservOf func(apMAC [6]byte, radioID, wlanID uint8) (uint32, bool)
}

// Handle mirrors _wsta_roam_pkt_pmk_request's request/response semantics
// and returns the 0x49 payload to append to the WTP event response (nil
// when nothing to answer).
func (p *PmkResponder) Handle(req capwap.PrivStaPMKReq) *capwap.PrivStaPMKReq {
	switch req.Type {
	case PmkTypeInform:
		// AP announces the key of a STA that is about to fast-roam.
		e := PmkEntry{Req: req}
		if p.WservOf != nil {
			if id, ok := p.WservOf(req.APMAC, req.Radio, req.WlanID); ok {
				e.WservID = id
			}
		}
		p.Store.Add(req.STAMAC, e)
		rsp := req
		rsp.Type = PmkTypeInformSuc
		rsp.Result = 0
		return &rsp
	case PmkTypeRequestSuc:
		// AP asks for the key material of a roaming STA.
		e, ok := p.Store.Get(req.STAMAC)
		if !ok {
			// "Can not find roam entry of mac[…]"
			rsp := req
			rsp.Type = PmkTypeResponse
			rsp.Result = 1
			return &rsp
		}
		rsp := e.Req
		rsp.Type = PmkTypeResponse
		rsp.Result = 0
		return &rsp
	}
	return nil
}

// RegisterPmkHandlers wires the msg 9 listener for 0x49 (the binary's
// _wsta_roam_pkt_wtp_event_listener dispatches 0x49/0x58/0x9c from one
// event listener; here PMK shares the register with the roam trigger).
func (e *Engine) RegisterPmkHandlers(p *PmkResponder) {
	e.Register(capwap.MsgWTPEventRequest, 51, "wsta_roam_pmk",
		func(ctx *Ctx, req, rsp *capwap.ParsedPacket) bool {
			for _, el := range req.Elements {
				if el.Type != 0x0025 || len(el.Value) < 6 {
					continue
				}
				for _, sub := range unpackVendorSubs(el.Value[6:]) {
					if sub.Type != 0x49 {
						continue
					}
					pm, err := capwap.ParsePrivStaPMKReq(sub.Value)
					if err != nil {
						continue
					}
					if out := p.Handle(*pm); out != nil {
						// the binary answers inside the WTP event response
						rsp.Elements = append(rsp.Elements, capwap.Element{
							Type: 0x0025,
							Value: capwap.VendorEnvelopeValue(0, 0,
								[]capwap.PrivElementValue{{Type: 0x49, Value: out.AssembleValue()}}),
						})
					}
				}
			}
			return true
		})
}
