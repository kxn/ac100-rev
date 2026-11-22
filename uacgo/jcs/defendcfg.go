package jcs

import (
	"database/sql"
	"encoding/json"
	"net"
	"strings"

	"uacgo/cweng"
)

// parseMAC parses "aa:bb:cc:dd:ee:ff" into 6 bytes (zeros on error).
func parseMAC(s string) [6]byte {
	var out [6]byte
	hw, err := net.ParseMAC(strings.TrimSpace(s))
	if err != nil || len(hw) != 6 {
		return out
	}
	copy(out[:], hw)
	return out
}

// parseIPv4 parses a dotted quad into 4 bytes (zeros on error).
func parseIPv4(s string) [4]byte {
	var out [4]byte
	ip := net.ParseIP(strings.TrimSpace(s))
	if ip == nil {
		return out
	}
	copy(out[:], ip.To4())
	return out
}

// Defense subsystem JCS surface (the *_init registrations of the binary):
//
//	macauth_mac get/add/del/set, macauth_mac_for_group del,
//	macauth_group get/add/del/set, macauth_group_for_ssid add/del/set,
//	macauth_type set                       (uac_mac_auth_init @0x451078)
//	bcast_storm_ctrl set                   (uac_bcast_storm_ctrl_init @0x45f0b8)
//	dhcpdef_svr add/del/set, dhcpdef_apbind get/set,
//	dhcpdef_apbind_svr get/set             (uac_dhcpdef_init @0x4661dc)
//	arp_defend_arp get/add/del/set, arp_defend_ap get/set
//	                                     (uac_arp_defend_init @0x476bb4)
//
// macauth wires straight into the admission engine (the binary
// registers mac_auth_wsta_callback_sta_check into the wsta check
// chain); the others are configuration managers whose payload push is
// injected as hooks.

// DefendPush delivers one config change to the APs (payload builders in
// cweng.BuildDhcpDefend/BuildArpDefend/BuildStormCtrl).
type DefendPush struct {
	OnStorm func(enable bool, rateKbps uint32)
	OnDhcp  func(enable, refresh bool, servers []cweng.DhcpDefendServer)
	OnArp   func(enable, refresh bool, binds []cweng.ArpBinding)
}

// RegisterMacAuthHandlers installs the macauth_* handlers over the
// admission engine.
func RegisterMacAuthHandlers(s *Server, db *cweng.MacAuthDB) {
	type macReq struct {
		ID   int    `json:"id"`
		Name string `json:"name"`
		MAC  string `json:"mac"`
	}
	type groupReq struct {
		ID       int    `json:"id"`
		Name     string `json:"name"`
		Note     string `json:"note"`
		BindVLAN string `json:"bind_vlan"`
		Type     int    `json:"type"`
		Status   bool   `json:"status"`
		MacIDs   []int  `json:"mac_ids"`
	}
	// macauth_type.set: 1 = by VLAN, otherwise by SSID
	s.replaceNotImpl("macauth_type.set", func(req json.RawMessage) (any, error) {
		var q struct {
			Type int `json:"type"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		db.SetMode(cweng.MacAuthMode(q.Type))
		return ok(), nil
	})
	// macauth_mac add/set/del/get
	s.replaceNotImpl("macauth_mac.add", func(req json.RawMessage) (any, error) {
		var q macReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		db.UpsertMac(cweng.MacAuthMac{ID: q.ID, Name: q.Name, MAC: parseMAC(q.MAC)})
		return ok(), nil
	})
	s.replaceNotImpl("macauth_mac.set", func(req json.RawMessage) (any, error) {
		var q macReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		db.UpsertMac(cweng.MacAuthMac{ID: q.ID, Name: q.Name, MAC: parseMAC(q.MAC)})
		return ok(), nil
	})
	s.replaceNotImpl("macauth_mac.del", func(req json.RawMessage) (any, error) {
		var q macReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		db.DelMac(q.ID)
		return ok(), nil
	})
	s.replaceNotImpl("macauth_mac.get", func(json.RawMessage) (any, error) {
		return map[string]any{"error_code": 0, "mac_list": db.MacList()}, nil
	})
	// macauth_group add/set/del/get
	addGroup := func(req json.RawMessage) (any, error) {
		var q groupReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		db.UpsertGroup(cweng.MacAuthGroup{
			ID: q.ID, Status: q.Status, Name: q.Name, Note: q.Note,
			BindVLAN: q.BindVLAN, Type: q.Type,
		})
		if len(q.MacIDs) > 0 {
			db.Bind(q.ID, q.MacIDs, true)
		}
		return ok(), nil
	}
	s.replaceNotImpl("macauth_group.add", addGroup)
	s.replaceNotImpl("macauth_group.set", addGroup)
	s.replaceNotImpl("macauth_group.del", func(req json.RawMessage) (any, error) {
		var q groupReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		db.DelGroup(q.ID)
		return ok(), nil
	})
	s.replaceNotImpl("macauth_group.get", func(json.RawMessage) (any, error) {
		return map[string]any{"error_code": 0, "group_list": db.GroupList()}, nil
	})
	// macauth_mac_for_group.del / macauth_group_for_ssid add/del/set
	s.replaceNotImpl("macauth_mac_for_group.del", func(req json.RawMessage) (any, error) {
		var q groupReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		db.Bind(q.ID, q.MacIDs, false)
		return ok(), nil
	})
	s.replaceNotImpl("macauth_group_for_ssid.add", addGroup)
	s.replaceNotImpl("macauth_group_for_ssid.set", addGroup)
	s.replaceNotImpl("macauth_group_for_ssid.del", func(req json.RawMessage) (any, error) {
		var q groupReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		db.DelGroup(q.ID)
		return ok(), nil
	})
}

// RegisterStormHandlers installs bcast_storm_ctrl.set (keys
// enable/storm_rate per _uac_bcast_storm_ctrl_jcs_set @0x45ed94).
func RegisterStormHandlers(s *Server, db *sql.DB, push *DefendPush) {
	s.replaceNotImpl("bcast_storm_ctrl.set", func(req json.RawMessage) (any, error) {
		var q struct {
			Enable    bool `json:"enable"`
			StormRate int  `json:"storm_rate"`
		}
		if len(req) > 0 {
			if err := json.Unmarshal(req, &q); err != nil {
				return nil, err
			}
		}
		if db != nil {
			if err := EnsureSyscfg(db); err == nil {
				_ = syscfgSet(db, "bcast_storm_ctrl", q)
			}
		}
		if push != nil && push.OnStorm != nil {
			push.OnStorm(q.Enable, uint32(q.StormRate))
		}
		return ok(), nil
	})
}

// RegisterDefendConfigHandlers installs the dhcpdef/arp CRUD surface
// over the syscfg KV (the binary keeps dedicated sqlite DBs; the KV
// captures the same config semantics with a push hook for the AP
// payloads).
func RegisterDefendConfigHandlers(s *Server, db *sql.DB, push *DefendPush) {
	kvSet := func(key string, out any) (any, error) {
		if db != nil {
			if err := EnsureSyscfg(db); err == nil {
				if err := syscfgSet(db, key, out); err != nil {
					return jerr(err), nil
				}
			}
		}
		return ok(), nil
	}
	kvGet := func(key string, out any) (any, error) {
		found := false
		if db != nil {
			if err := EnsureSyscfg(db); err == nil {
				found, _ = syscfgGet(db, key, out)
			}
		}
		return map[string]any{"error_code": 0, "found": found, "config": out}, nil
	}
	type dhcpReq struct {
		SvrID    int    `json:"svr_id"`
		Name     string `json:"name"`
		AddrType int    `json:"addr_type"`
		Addr     string `json:"svr_addr"`
		ApID     []int  `json:"ap_id"`
		Enable   bool   `json:"enable"`
		SvrIDs   []int  `json:"svr_ids"`
	}
	type arpReq struct {
		ArpID   int    `json:"arp_id"`
		ArpIP   string `json:"arp_ip"`
		MAC     string `json:"mac"`
		ArpName string `json:"arp_name"`
		ApID    []int  `json:"ap_id"`
		Enable  bool   `json:"enable"`
		ArpIDs  []int  `json:"arp_ids"`
	}
	// dhcpdef: the server list lives under one KV entry per operation
	var svrs []cweng.DhcpDefendServer
	s.replaceNotImpl("dhcpdef_svr.add", func(req json.RawMessage) (any, error) {
		var q dhcpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		m := parseMAC(q.Addr)
		svrs = append(svrs, cweng.DhcpDefendServer{
			AddrType: uint8(q.AddrType), Addr: append([]byte(nil), m[:]...),
		})
		if push != nil && push.OnDhcp != nil {
			push.OnDhcp(true, true, svrs)
		}
		return kvSet("dhcpdef_svr", svrs)
	})
	s.replaceNotImpl("dhcpdef_svr.set", func(req json.RawMessage) (any, error) {
		var q dhcpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		return kvSet("dhcpdef_svr", q)
	})
	s.replaceNotImpl("dhcpdef_svr.del", func(req json.RawMessage) (any, error) {
		var q dhcpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		if q.SvrID > 0 && q.SvrID <= len(svrs) {
			svrs = append(svrs[:q.SvrID-1], svrs[q.SvrID:]...)
		}
		if push != nil && push.OnDhcp != nil {
			push.OnDhcp(true, true, svrs)
		}
		return kvSet("dhcpdef_svr", svrs)
	})
	s.replaceNotImpl("dhcpdef_apbind.get", func(req json.RawMessage) (any, error) {
		var out any
		return kvGet("dhcpdef_apbind", &out)
	})
	s.replaceNotImpl("dhcpdef_apbind.set", func(req json.RawMessage) (any, error) {
		var q dhcpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		return kvSet("dhcpdef_apbind", q)
	})
	s.replaceNotImpl("dhcpdef_apbind_svr.get", func(req json.RawMessage) (any, error) {
		var out any
		return kvGet("dhcpdef_apbind_svr", &out)
	})
	s.replaceNotImpl("dhcpdef_apbind_svr.set", func(req json.RawMessage) (any, error) {
		var q dhcpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		return kvSet("dhcpdef_apbind_svr", q)
	})
	// arp_defend_arp get/add/del/set + arp_defend_ap get/set
	var binds []cweng.ArpBinding
	s.replaceNotImpl("arp_defend_arp.add", func(req json.RawMessage) (any, error) {
		var q arpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		ip := parseIPv4(q.ArpIP)
		binds = append(binds, cweng.ArpBinding{IP: ip, MAC: parseMAC(q.MAC)})
		if push != nil && push.OnArp != nil {
			push.OnArp(true, true, binds)
		}
		return kvSet("arp_defend_arp", binds)
	})
	s.replaceNotImpl("arp_defend_arp.set", func(req json.RawMessage) (any, error) {
		var q arpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		return kvSet("arp_defend_arp", q)
	})
	s.replaceNotImpl("arp_defend_arp.del", func(req json.RawMessage) (any, error) {
		var q arpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		if q.ArpID > 0 && q.ArpID <= len(binds) {
			binds = append(binds[:q.ArpID-1], binds[q.ArpID:]...)
		}
		if push != nil && push.OnArp != nil {
			push.OnArp(true, true, binds)
		}
		return kvSet("arp_defend_arp", binds)
	})
	s.replaceNotImpl("arp_defend_arp.get", func(req json.RawMessage) (any, error) {
		var out any
		return kvGet("arp_defend_arp", &out)
	})
	s.replaceNotImpl("arp_defend_ap.get", func(req json.RawMessage) (any, error) {
		var out any
		return kvGet("arp_defend_ap", &out)
	})
	s.replaceNotImpl("arp_defend_ap.set", func(req json.RawMessage) (any, error) {
		var q arpReq
		if err := json.Unmarshal(req, &q); err != nil {
			return nil, err
		}
		return kvSet("arp_defend_ap", q)
	})
}
