package admin

import (
	"context"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"net/http"
	"strconv"
	"strings"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

// V6 _uac_wserv_vlan_pool_info_pkt_create: AP-extra type 0 carries a
// pool ID, NUL-terminated VLAN range and operation (0 add/update, 1 delete).
type VLANPool struct {
	ID       uint16 `json:"id"`
	Name     string `json:"name"`
	VLANs    string `json:"vlans"`
	Deleting bool   `json:"deleting,omitempty"`
}

func validatePool(p VLANPool) error {
	if p.ID < 1 || p.ID > 255 || len([]byte(p.Name)) > 64 || strings.TrimSpace(p.Name) == "" || len(p.VLANs) > 480 {
		return fmt.Errorf("VLAN 池编号为 1–255，名称为 1–64 字节")
	}
	seen := map[int]bool{}
	for _, part := range strings.Split(p.VLANs, ",") {
		x := strings.Split(strings.TrimSpace(part), "-")
		if len(x) > 2 {
			return fmt.Errorf("VLAN 列表格式无效")
		}
		lo, err := strconv.Atoi(x[0])
		hi := lo
		if err != nil {
			return fmt.Errorf("VLAN 列表格式无效")
		}
		if len(x) == 2 {
			hi, err = strconv.Atoi(x[1])
		}
		if err != nil || lo < 1 || hi > 4094 || hi < lo {
			return fmt.Errorf("VLAN 范围为 1–4094")
		}
		for n := lo; n <= hi; n++ {
			if seen[n] {
				return fmt.Errorf("VLAN 列表不能重复")
			}
			seen[n] = true
		}
	}
	return nil
}
func poolElement(p VLANPool) capwap.Element {
	text := []byte(p.VLANs + "\x00")
	method := uint16(0)
	if p.Deleting {
		text = nil
		method = 1
	}
	record := binary.BigEndian.AppendUint16(nil, p.ID)
	record = binary.BigEndian.AppendUint16(record, uint16(len(text)))
	record = binary.BigEndian.AppendUint16(record, method)
	record = append(record, text...)
	value := []byte{0, 1, 0, 0}
	value = binary.BigEndian.AppendUint16(value, uint16(len(record)))
	value = append(value, record...)
	return capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, 0xc8, []capwap.PrivElementValue{{Type: 0xc8, Value: value}})}
}
func supportsPool(ap cweng.APStatus) bool {
	return ap.HasCapability(98) && ap.SubCapabilities[0x5f]&8 != 0
}
func (m *Manager) applyPools(ctx context.Context, ap cweng.APStatus, cfg Config) {
	if !supportsPool(ap) {
		return
	}
	for _, p := range cfg.VLANPools {
		key := ap.ID + "/vlan-pool:" + strconv.Itoa(int(p.ID))
		version := configurationKey(p, ap.ConnectedAt)
		m.mu.Lock()
		done := m.applied[key] == version && (m.status[key].State != "failed" || time.Since(m.status[key].At) < 30*time.Second)
		m.mu.Unlock()
		if done {
			continue
		}
		c, cancel := context.WithTimeout(ctx, 4*time.Second)
		m.dirtyAP(ap.ID)
		_, err := m.engine.Request(c, ap.ID, 7, []capwap.Element{poolElement(p)})
		cancel()
		st := ApplyStatus{AP: ap.ID, Service: "vlan-pool:" + strconv.Itoa(int(p.ID)), State: "acknowledged", At: time.Now()}
		if err != nil {
			st.State = "failed"
			st.Error = err.Error()
		}
		m.mu.Lock()
		m.applied[key] = version
		m.status[key] = st
		m.mu.Unlock()
	}
}
func (m *Manager) poolHTTP(w http.ResponseWriter, r *http.Request) {
	var p VLANPool
	if r.Method == "DELETE" {
		n, err := strconv.ParseUint(r.PathValue("id"), 10, 16)
		if err != nil {
			jsonReply(w, 400, map[string]string{"error": "VLAN 池编号无效"})
			return
		}
		p.ID = uint16(n)
		p.Deleting = true
	} else if err := json.NewDecoder(http.MaxBytesReader(w, r.Body, 4096)).Decode(&p); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	m.mu.Lock()
	defer m.mu.Unlock()
	idx := -1
	for i, x := range m.config.VLANPools {
		if x.ID == p.ID {
			idx = i
			if p.Deleting {
				p = x
				p.Deleting = true
			}
			break
		}
	}
	if p.Deleting {
		if idx < 0 {
			jsonReply(w, 404, map[string]string{"error": "VLAN 池不存在"})
			return
		}
		for _, s := range m.config.Services {
			if serviceOptions(s).VLANPool == p.ID {
				jsonReply(w, 409, map[string]string{"error": "请先解除无线服务与 VLAN 池的绑定"})
				return
			}
		}
	} else if err := validatePool(p); err != nil {
		jsonReply(w, 400, map[string]string{"error": err.Error()})
		return
	}
	next := m.config
	next.Version++
	next.VLANPools = append([]VLANPool{}, next.VLANPools...)
	if idx < 0 {
		next.VLANPools = append(next.VLANPools, p)
	} else {
		next.VLANPools[idx] = p
	}
	if err := m.persistConfigLocked(next, false); err != nil {
		jsonReply(w, 500, map[string]string{"error": err.Error()})
		return
	}
	jsonReply(w, 202, map[string]any{"status": "saved", "pool": p})
}
