package admin

import (
	"encoding/json"
	"fmt"
	"net"
	"net/url"
	"strconv"
	"strings"
	"time"
	"uacgo/cweng"
)

func (m *Manager) mergeWirelessSnapshot(ap cweng.APStatus, started time.Time, stations, hosts json.RawMessage) error {
	rows, err := nativeRows(stations, "wireless", "sta_list")
	if err != nil {
		return err
	}
	// A successful but truncated list must not disconnect absent clients.
	var header struct {
		Wireless struct {
			Count map[string]int `json:"count"`
		} `json:"wireless"`
	}
	if json.Unmarshal(stations, &header) == nil {
		if n, ok := header.Wireless.Count["sta_list"]; ok && n != len(rows) {
			return fmt.Errorf("AP 无线客户端表不完整")
		}
	}
	hostRows, err := nativeRows(hosts, "hosts_info", "host_info")
	if err != nil {
		return err
	}
	ips := map[string]string{}
	for _, r := range hostRows {
		ips[normalizeMAC(nativeString(r, "mac"))] = nativeString(r, "ip")
	}
	cfg := m.snapshot()
	m.mu.Lock()
	owned := map[string]map[uint8]uint8{}
	for id, rs := range m.assignments[ap.ID] {
		owned[id] = map[uint8]uint8{}
		for radio, wlan := range rs {
			owned[id][radio] = wlan
		}
	}
	m.mu.Unlock()
	present := map[[6]byte]bool{}
	var facts []cweng.ClientEvent
	for _, r := range rows {
		mac, e := net.ParseMAC(normalizeMAC(nativeString(r, "mac")))
		if e != nil || len(mac) != 6 || mac[0]&1 != 0 || mac.String() == "00:00:00:00:00:00" {
			return fmt.Errorf("AP 无线客户端 MAC 无效")
		}
		var id [6]byte
		copy(id[:], mac)
		present[id] = true
		radio, e := strconv.ParseUint(nativeString(r, "radio_id"), 10, 8)
		if e != nil || radio == 0 {
			continue
		}
		ssid, e := url.PathUnescape(nativeString(r, "ssid"))
		if e != nil {
			continue
		}
		// Older station-table formats omit VLAN. They still identify a client
		// when SSID/radio has exactly one committed service. Missing isn't VLAN
		// zero, and cannot disambiguate two services with the same SSID.
		vlanText := nativeString(r, "vlan_id")
		vlan, vlanErr := strconv.Atoi(vlanText)
		if vlanText != "" && (vlanErr != nil || vlan < 0 || vlan > 4094) {
			continue
		}
		wlan := uint8(0)
		matches := 0
		matchedService := ""
		for _, s := range cfg.Services {
			if s.SSID != ssid || !s.Enabled || s.Deleting || !serviceTargets(s, ap.ID, cfg) {
				continue
			}
			bound, v := binding(s, ap.ID, uint8(radio))
			if !selectedServiceRadios(s, ap)[uint8(radio)] || !bound || vlanText != "" && !clientVLANMatches(s, cfg, v, vlan) || radioDisabled(cfg, ap.ID, uint8(radio)) {
				continue
			}
			if n := owned[s.ID][uint8(radio)]; n != 0 {
				wlan = n
				matchedService = s.ID
				matches++
			}
		}
		if matches != 1 {
			continue
		}
		ev := cweng.ClientEvent{Connection: ap.ConnectedAt, SSID: ssid, ServiceID: matchedService, MAC: id, APID: ap.ID, RadioID: uint8(radio), WLANID: uint32(wlan), IP: ips[normalizeMAC(mac.String())]}
		if vlanText != "" {
			vlanID := uint16(vlan)
			ev.VLAN = &vlanID
		}
		if ip := net.ParseIP(ev.IP); ip == nil || ip.IsUnspecified() || ip.IsMulticast() {
			ev.IP = ""
		}
		tx, rx := nativeString(r, "tx_rate"), nativeString(r, "rx_rate")
		if tx != "" || rx != "" {
			// XAP3007's fields come from periodically measured traffic kbps,
			// not PHY negotiation. Keep native values separate from private52;
			// other AP implementations need not share their unit or meaning.
			ev.NativeRates = &cweng.ClientNativeRates{TX: tx, RX: rx, At: started}
			m.event("client.native_rates", "ap_id", ap.ID, "session", ap.ConnectedAt, "client", eventMAC(id), "radio", radio, "interface", "wireless.sta_list", "tx_rate", tx, "rx_rate", rx, "unit", "unspecified")
		}
		if raw := nativeString(r, "rssi"); raw != "" {
			// This field differs between AP implementations. A positive value
			// is not a signed dBm byte, and even its sign does not establish a
			// conversion contract. Preserve it as diagnostics, never policy RSSI.
			ev.NativeSignal = &cweng.ClientNativeSignal{Value: raw, At: started}
			m.event("client.native_signal", "ap_id", ap.ID, "session", ap.ConnectedAt, "client", eventMAC(id), "radio", radio, "interface", "wireless.sta_list.rssi", "raw_value", raw, "unit", "unspecified")
		}
		if n, e := strconv.ParseUint(nativeString(r, "connect_time"), 10, 32); e == nil {
			ev.ConnectedAt = started.Add(-time.Duration(n) * time.Second)
		}
		facts = append(facts, ev)
	}
	m.clients.WirelessSnapshot(ap.ID, ap.ConnectedAt, started, facts, present)
	return nil
}

// Native station rows contain the assigned VLAN, rather than the internal
// 5000+pool placeholder used by the AP configuration protocol.
func clientVLANMatches(s Service, cfg Config, fixed, observed int) bool {
	id := serviceOptions(s).VLANPool
	if id == 0 {
		return fixed == observed
	}
	for _, p := range cfg.VLANPools {
		if p.ID != id || p.Deleting {
			continue
		}
		for _, part := range strings.Split(p.VLANs, ",") {
			x := strings.Split(strings.TrimSpace(part), "-")
			lo, err := strconv.Atoi(x[0])
			hi := lo
			if len(x) == 2 {
				hi, err = strconv.Atoi(x[1])
			}
			if err == nil && observed >= lo && observed <= hi {
				return true
			}
		}
	}
	return false
}
