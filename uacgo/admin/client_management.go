package admin

import (
	"encoding/csv"
	"fmt"
	"net"
	"net/http"
	"strconv"
	"strings"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

type ClientLabel struct {
	Name string `json:"name"`
	Note string `json:"note"`
}

func (m *Manager) clientRoutes(mux *http.ServeMux) {
	mux.HandleFunc("POST /api/clients/{mac}/label", func(w http.ResponseWriter, r *http.Request) {
		mac, err := net.ParseMAC(r.PathValue("mac"))
		var label ClientLabel
		if err != nil || len(mac) != 6 || decodeManagement(w, r, &label) != nil || !validLabel(label.Name, 64) || !validLabel(label.Note, 200) {
			jsonReply(w, 400, map[string]string{"error": "客户端名称、备注或 MAC 无效"})
			return
		}
		m.mu.Lock()
		defer m.mu.Unlock()
		next := m.config
		next.ClientLabels = map[string]ClientLabel{}
		for k, v := range m.config.ClientLabels {
			next.ClientLabels[k] = v
		}
		next.ClientLabels[mac.String()] = label
		if err := m.saveManagement(next); err != nil {
			jsonReply(w, 500, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 200, map[string]string{"status": "saved"})
	})
	mux.HandleFunc("POST /api/clients/{mac}/disconnect", func(w http.ResponseWriter, r *http.Request) {
		mac, err := net.ParseMAC(r.PathValue("mac"))
		if err != nil || len(mac) != 6 {
			jsonReply(w, 400, map[string]string{"error": "MAC 无效"})
			return
		}
		var station *cweng.ClientEvent
		for _, ev := range m.clients.All() {
			if net.HardwareAddr(ev.MAC[:]).String() == mac.String() {
				copy := ev
				station = &copy
			}
		}
		if station == nil || station.RadioID == 0 || station.State != "connected" {
			jsonReply(w, 409, map[string]string{"error": "没有此客户端当前关联位置"})
			return
		}
		// V6 _uac_wsta_del_cb @0x75efec: msg25 + Delete Station 0x12,
		// radio, MAC length6, MAC. AP deassociation report confirms completion.
		value := append([]byte{station.RadioID, 6}, mac...)
		var ap cweng.APStatus
		for _, a := range m.APs() {
			if a.ID == station.APID {
				ap = a
			}
		}
		if !ap.Online || station.Seen.Before(ap.ConnectedAt) {
			jsonReply(w, 409, map[string]string{"error": "客户端位置不属于当前 AP 会话，请等待新上报"})
			return
		}
		m.mu.Lock()
		busy := m.upgradeBusyLocked(ap.ID)
		m.mu.Unlock()
		if busy {
			jsonReply(w, 409, map[string]string{"error": "AP 正在升级"})
			return
		}
		result, err := m.engine.Request(cweng.PinAP(r.Context(), ap), station.APID, 25, []capwap.Element{{Type: 0x12, Value: value}})
		if err != nil {
			jsonReply(w, 502, map[string]string{"error": err.Error()})
			return
		}
		jsonReply(w, 202, result)
	})
	mux.HandleFunc("GET /api/clients/export", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		labels := m.config.ClientLabels
		m.mu.Unlock()
		w.Header().Set("Content-Type", "text/csv; charset=utf-8")
		w.Header().Set("Content-Disposition", `attachment; filename="wireless-clients.csv"`)
		out := csv.NewWriter(w)
		defer out.Flush()
		_ = out.Write([]string{"MAC", "名称", "备注", "AP", "射频", "WLAN", "SSID", "VLAN", "IPv4/主地址", "IPv6", "状态", "RSSI", "协商Mbps", "最近上报"})
		for _, ev := range m.clients.All() {
			mac := net.HardwareAddr(ev.MAC[:]).String()
			label := labels[mac]
			rssi, rate, vlan := "", "", ""
			if ev.VLAN != nil {
				vlan = fmt.Sprint(*ev.VLAN)
			}
			if ev.RSSI != nil {
				rssi = fmt.Sprint(*ev.RSSI)
			}
			if ev.Statistics != nil {
				rate = fmt.Sprint(ev.Statistics.NegotiatedMbps)
			}
			_ = out.Write([]string{mac, csvText(label.Name), csvText(label.Note), ev.APID, strconv.Itoa(int(ev.RadioID)), fmt.Sprint(ev.WLANID), csvText(ev.SSID), vlan, ev.IP, strings.Join(ev.IPv6, ","), ev.State, rssi, rate, ev.Seen.Format(time.RFC3339)})
		}
	})
	mux.HandleFunc("GET /api/operations", func(w http.ResponseWriter, r *http.Request) {
		m.mu.Lock()
		defer m.mu.Unlock()
		jsonReply(w, 200, m.operations)
	})
}
