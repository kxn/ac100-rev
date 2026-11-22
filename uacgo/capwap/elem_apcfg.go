package capwap

import "encoding/binary"

// AP config-update bundle elements (values decoded from the vendor
// assemble functions; schema cross-check: ApEntryCfg_table columns).

// PrivApBasePara is private element 0x05 "ap base parameter" (min=max=8):
// two BE32 keep-alive values (ap_keep_alive, client_keep_alive).
// cw_priv_ap_base_para_assemble @0x5a3df0.
type PrivApBasePara struct {
	KeepAlive       uint32
	ClientKeepAlive uint32
}

// AssembleValue writes the 8 value bytes.
func (p PrivApBasePara) AssembleValue() []byte {
	b := binary.BigEndian.AppendUint32(nil, p.KeepAlive)
	return binary.BigEndian.AppendUint32(b, p.ClientKeepAlive)
}

// ParsePrivApBasePara decodes the 8 value bytes.
func ParsePrivApBasePara(v []byte) (*PrivApBasePara, error) {
	if len(v) != 8 {
		return nil, ErrShortPacket
	}
	return &PrivApBasePara{
		KeepAlive:       binary.BigEndian.Uint32(v),
		ClientKeepAlive: binary.BigEndian.Uint32(v[4:]),
	}, nil
}

// PrivApOfflineMngr is private element 0x3c "ap offline mngr" (min=max=24):
// six BE32 words (offline-self-management parameters).
// cw_priv_ap_offline_mngr_assemble @0x5a6ae4.
type PrivApOfflineMngr struct {
	Words [6]uint32
}

// AssembleValue writes the 24 value bytes.
func (p PrivApOfflineMngr) AssembleValue() []byte {
	var b []byte
	for _, w := range p.Words {
		b = binary.BigEndian.AppendUint32(b, w)
	}
	return b
}

// ParsePrivApOfflineMngr decodes the 24 value bytes.
func ParsePrivApOfflineMngr(v []byte) (*PrivApOfflineMngr, error) {
	if len(v) != 24 {
		return nil, ErrShortPacket
	}
	var p PrivApOfflineMngr
	for i := 0; i < 6; i++ {
		p.Words[i] = binary.BigEndian.Uint32(v[i*4:])
	}
	return &p, nil
}

// PrivApUser is private element 0x3d "ap user" (min=max=128): two fixed
// 64-byte fields (username, password — ApEntryCfg account_username/
// account_password VARCHAR(64)). cw_priv_ap_user_assemble @0x5a9ad0.
type PrivApUser struct {
	Username [64]byte
	Password [64]byte
}

// AssembleValue writes the 128 value bytes.
func (p PrivApUser) AssembleValue() []byte {
	b := append([]byte(nil), p.Username[:]...)
	return append(b, p.Password[:]...)
}

// ParsePrivApUser decodes the 128 value bytes.
func ParsePrivApUser(v []byte) (*PrivApUser, error) {
	if len(v) != 128 {
		return nil, ErrShortPacket
	}
	var p PrivApUser
	copy(p.Username[:], v[:64])
	copy(p.Password[:], v[64:])
	return &p, nil
}
