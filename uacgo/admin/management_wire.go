package admin

import (
	"context"
	"encoding/binary"
	"fmt"
	"reflect"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func privateSetting(typ uint16, value []byte) capwap.Element {
	return capwap.Element{Type: 0x25, Value: capwap.VendorEnvelopeValue(0x12345678, typ, []capwap.PrivElementValue{{Type: typ, Value: value}})}
}
func managementElements(o APOptions, ap cweng.APStatus) ([]capwap.Element, error) {
	if err := validateAPOptions(o); err != nil {
		return nil, err
	}
	var out []capwap.Element
	if mode := o.RFMode; mode != nil {
		if !ap.HasCapability(92) {
			return nil, fmt.Errorf("AP 未声明整机射频模式切换能力")
		}
		found := false
		for _, v := range ap.RadioModes {
			found = found || v.ID == mode.ID
		}
		if mode.Enabled && !found {
			return nil, fmt.Errorf("AP 未声明所选射频模式")
		}
		out = append(out, privateSetting(0xbc, []byte{boolean(mode.Enabled), mode.ID, 0}))
	}

	if o.Mesh != nil {
		if !ap.HasCapability(44) {
			return nil, fmt.Errorf("AP 未声明 Mesh 能力")
		}
		b := []byte{0, 1, 0, 0x15, 0, 2, 0, boolean(*o.Mesh)}
		out = append(out, privateSetting(0x76, b))
	}
	if o.USB != nil {
		if !ap.HasCapability(100) {
			return nil, fmt.Errorf("AP 未声明 USB 管理能力")
		}
		out = append(out, privateSetting(0xd7, []byte{0, 1, 0, 2, 0, 1, boolean(*o.USB)}))
	}
	if o.Bluetooth != nil {
		if !ap.HasCapability(77) {
			return nil, fmt.Errorf("AP 未声明蓝牙能力")
		}
		if *o.Bluetooth == 0 && (!ap.HasCapability(102) || ap.SubCapabilities[102]&1 == 0) || *o.Bluetooth == 2 && !ap.HasCapability(79) {
			return nil, fmt.Errorf("AP 未声明该蓝牙工作模式能力")
		}

		enabled, mode := byte(1), uint32(0xffffffff)
		if *o.Bluetooth == -1 {
			enabled = 0
		} else if ap.SubCapabilities[77]&1 != 0 {
			mode = map[int]uint32{0: 4, 1: 2, 2: 1}[*o.Bluetooth]
		}
		b := binary.BigEndian.AppendUint32([]byte{enabled}, mode)
		b = binary.BigEndian.AppendUint32(b, 0xffffffff)
		out = append(out, privateSetting(0xa7, b))
	}

	// V6 apmngr_pkt_config_update_request_pkt_send @0x6119c4:
	// CW Timers = discovery20/echo. Private05 is client keepalive/miss count,
	// not two independent heartbeat periods as the early prototype named it.
	if o.EchoSeconds != nil {
		out = append(out, capwap.Element{Type: 0xc, Value: []byte{20, *o.EchoSeconds}})
	}
	if o.ClientKeepAlive != nil || o.EchoMisses != nil {
		keep, miss := uint32(30), uint32(5)
		if o.ClientKeepAlive != nil {
			keep = *o.ClientKeepAlive
		}
		if o.EchoMisses != nil {
			miss = *o.EchoMisses
		}
		value := binary.BigEndian.AppendUint32(nil, keep)
		value = binary.BigEndian.AppendUint32(value, miss)
		out = append(out, privateSetting(5, value))
	}
	if o.ClientIdle != nil {
		out = append(out, capwap.Element{Type: 0x17, Value: binary.BigEndian.AppendUint32(nil, *o.ClientIdle)})
	}
	if o.OfflineSelfManage != nil {
		words := capwap.PrivApOfflineMngr{Words: [6]uint32{uint32(boolean(*o.OfflineSelfManage)), 300, 0, 0, 0, 0}}
		out = append(out, privateSetting(0x3c, words.AssembleValue()))
	}
	if o.LEDWiFiSync != nil {
		if !ap.HasCapability(42) {
			return nil, fmt.Errorf("AP 未声明 LED 随无线状态同步能力")
		}
		mode := uint32(1)
		if *o.LEDWiFiSync {
			mode = 3
		}
		out = append(out, privateSetting(0x6f, binary.BigEndian.AppendUint32(nil, mode)))
	}
	if o.LED != nil {
		out = append(out, privateSetting(0x39, binary.BigEndian.AppendUint32(nil, uint32(boolean(*o.LED)))))
	}
	if o.Trunk != nil {
		if !ap.SupportTrunk {
			return nil, fmt.Errorf("AP 未声明 Trunk 能力")
		}
		out = append(out, privateSetting(0x44, binary.BigEndian.AppendUint32(nil, uint32(boolean(*o.Trunk)))))
	}
	if o.FitFatButton != nil {
		if !ap.HasCapability(73) {
			return nil, fmt.Errorf("AP 未声明 FIT/FAT 按键控制能力")
		}
		out = append(out, privateSetting(0xa4, binary.BigEndian.AppendUint32(nil, uint32(boolean(*o.FitFatButton)))))
	}
	if o.RegionCode != nil {
		out = append(out, privateSetting(0x98, []byte{*o.RegionCode}))
	}
	if o.Account != nil {
		if o.Account.Password == "" {
			return nil, fmt.Errorf("AP 账号密码不能为空")
		}
		var user capwap.PrivApUser
		copy(user.Username[:], o.Account.Username)
		copy(user.Password[:], o.Account.Password)
		out = append(out, privateSetting(0x3d, user.AssembleValue()))
	}
	if len(o.Ports) > 0 {
		for _, p := range o.Ports {
			found := false
			for _, port := range ap.Ports {
				found = found || port.ID == p.ID && !port.Uplink
			}
			if len(ap.Ports) == 0 {
				found = int(p.ID) <= ap.ExtWirePhys
			}
			if !found {
				return nil, fmt.Errorf("AP 未声明可配置下联端口 %d", p.ID)
			}
		}
		vlan, enabled := []byte{}, []byte{}
		nv, ne := byte(0), byte(0)
		for _, p := range o.Ports {
			if p.VLAN != nil {
				vlan = append(vlan, p.ID)
				vlan = binary.BigEndian.AppendUint16(vlan, *p.VLAN)
				nv++
			}
			if p.Enabled != nil {
				enabled = append(enabled, p.ID, boolean(*p.Enabled))
				ne++
			}
		}
		if nv > 0 {
			out = append(out, apExtraSetting(1, append([]byte{nv}, vlan...)))
		}
		if ne > 0 {
			out = append(out, apExtraSetting(16, append([]byte{ne}, enabled...)))
		}
	}
	if o.LAG != nil {
		if !ap.HasCapability(71) {
			return nil, fmt.Errorf("AP 未声明链路聚合能力")
		}
		if len(ap.Ports) > 0 {
			for _, id := range o.LAG.Ports {
				found := false
				for _, port := range ap.Ports {
					found = found || port.ID == id && port.LAG
				}
				if !found {
					return nil, fmt.Errorf("端口 %d 未声明链路聚合能力", id)
				}
			}
		}
		// Original list is an ASCII physical-port string, not uint16 port IDs.
		ports := []byte("0")
		if len(o.LAG.Ports) > 0 {
			ports = nil
			for _, p := range o.LAG.Ports {
				if len(ports) > 0 {
					ports = append(ports, ',')
				}
				ports = append(ports, fmt.Sprint(p)...)
			}
		}
		if len(ports) > 20 {
			return nil, fmt.Errorf("聚合端口列表过长")
		}
		value := []byte{boolean(o.LAG.Enabled), o.LAG.Mode, byte(len(ports))}
		value = append(value, ports...)
		out = append(out, privateSetting(0xa3, value))
	}
	return out, nil
}
func apExtraSetting(kind uint16, value []byte) capwap.Element {
	b := binary.BigEndian.AppendUint16(nil, 1)
	b = binary.BigEndian.AppendUint16(b, kind)
	b = binary.BigEndian.AppendUint16(b, uint16(len(value)))
	b = append(b, value...)
	return privateSetting(0xc8, b)
}
func (m *Manager) applyAPManagement(ctx context.Context, ap cweng.APStatus, cfg Config) error {
	o, err := effectiveAPOptions(cfg, ap)
	if err == nil && o.LEDSchedule != nil && o.LEDSchedule.Enabled {
		v := o.LEDSchedule.active(time.Now())
		o.LED = &v
	}
	key := ap.ID + "/ap-settings"
	version := configurationKey(o, ap.ConnectedAt)
	m.mu.Lock()
	previous := m.status[key]
	done := m.applied[key] == version && (previous.State != "failed" || time.Since(previous.At) < 30*time.Second)
	m.mu.Unlock()
	if done {
		if previous.State == "failed" {
			return fmt.Errorf("%s", previous.Error)
		}
		return m.runAPSchedules(ctx, ap, o)
	}
	state := ApplyStatus{AP: ap.ID, Service: "ap-settings", State: "acknowledged", At: time.Now()}
	if err == nil && !reflect.DeepEqual(o, APOptions{}) {
		var els []capwap.Element
		els, err = managementElements(o, ap)
		if err == nil {
			m.dirtyAP(ap.ID)
			for _, batch := range radioBatches(els) {
				if _, err = m.engine.Request(ctx, ap.ID, 7, batch); err != nil {
					break
				}
			}
			if err == nil && (o.EchoSeconds != nil || o.EchoMisses != nil) {
				err = m.engine.SetLiveness(ctx, ap.ID, o.EchoSeconds, o.EchoMisses)
			}
		}
	}
	if err != nil {
		state.State = "failed"
		state.Error = err.Error()
	}
	m.mu.Lock()
	m.status[key] = state
	m.applied[key] = version
	m.mu.Unlock()
	if err != nil {
		return err
	}
	return m.runAPSchedules(ctx, ap, o)
}
