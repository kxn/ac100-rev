// Package firmware inspects TP-Link AP upgrade containers independently of
// filenames. It does not claim to verify the manufacturer's cryptographic signature.
package firmware

import (
	"bytes"
	"crypto/md5"
	"crypto/sha256"
	"encoding/binary"
	"encoding/hex"
	"fmt"
	"regexp"
	"strconv"
	"strings"
	"time"
)

const MaxSize = 32 << 20

var be = binary.BigEndian
var upgradeMagic = mustHex("55aa4c5e831f534ba1f8f7c918df8fbf7da1aa55")
var customMagic = mustHex("a5a5a5a58f72632a040f86009206bb51d2b7636a")
var tpMagic = mustHex("55aa9dd1a8c88331c969fbbfbcf0d43270c7aa55")
var legacySalt = mustHex("7a2b15ed9b98596de504ab44ac2a9f4e")

func mustHex(s string) []byte { b, _ := hex.DecodeString(s); return b }

type Support struct {
	Model    string `json:"model"`
	Hardware string `json:"hardware"`
}
type Image struct {
	ID          string    `json:"id"`
	Format      string    `json:"format"`
	Model       string    `json:"model"`
	Version     string    `json:"version"`
	Size        int       `json:"size"`
	MD5         string    `json:"md5"`
	FirmwareID  string    `json:"firmware_id,omitempty"`
	HardwareIDs []string  `json:"hardware_ids,omitempty"`
	Blocked     []string  `json:"blocked_firmware_ids,omitempty"`
	Support     []Support `json:"support,omitempty"`
	Brand       uint16    `json:"brand"`
	WireVersion []byte    `json:"wire_version"`
}

func cstring(b []byte) string {
	if i := bytes.IndexByte(b, 0); i >= 0 {
		b = b[:i]
	}
	return strings.TrimSpace(string(b))
}
func Inspect(b []byte) (Image, error) {
	var im Image
	if len(b) < 0x400 || len(b) > MaxSize {
		return im, fmt.Errorf("固件大小必须为 1 KiB–32 MiB")
	}
	sha := sha256.Sum256(b)
	sum := md5.Sum(b)
	im = Image{ID: hex.EncodeToString(sha[:]), Size: len(b), MD5: hex.EncodeToString(sum[:])}
	var err error
	if bytes.Equal(b[4:24], upgradeMagic) {
		err = im.modern(b)
	} else {
		err = im.legacy(b)
	}
	if err != nil {
		return Image{}, err
	}
	return im, nil
}

var versionRE = regexp.MustCompile(`^(\d+)\.(\d+)\.(\d+)\s+Build\s+(\d{8})\s+Rel\.(\d+)[a-zA-Z]*$`)

func versionWire(s string) ([]byte, error) {
	m := versionRE.FindStringSubmatch(s)
	if m == nil {
		return nil, fmt.Errorf("无法识别固件版本 %q", s)
	}
	var out []byte
	for _, v := range m[1:4] {
		n, err := strconv.ParseUint(v, 10, 16)
		if err != nil {
			return nil, err
		}
		out = be.AppendUint16(out, uint16(n))
	}
	d, err := time.Parse("20060102", m[4])
	if err != nil {
		return nil, err
	}
	out = be.AppendUint32(out, uint32(d.Year()<<16|int(d.Month())<<8|d.Day()))
	n, err := strconv.ParseUint(m[5], 10, 32)
	if err != nil {
		return nil, err
	}
	return be.AppendUint32(out, uint32(n)), nil
}
func (im *Image) modern(b []byte) error {
	// libfirmware dkmgt_firmwareInfo_check @0x810. Bound every partition/count,
	// including those the C implementation copied without checking.
	if !bytes.Equal(b[0x204:0x218], customMagic) {
		return fmt.Errorf("升级容器头损坏")
	}
	count := int(be.Uint16(b[0x21e:]))
	if count < 1 || count > (0x400-0x220)/20 {
		return fmt.Errorf("固件分区表无效")
	}
	head := -1
	names := map[string]bool{}
	type span struct{ a, z int }
	var spans []span
	for i := 0; i < count; i++ {
		row := b[0x220+i*20 : 0x234+i*20]
		name := cstring(row[:12])
		off, n := uint64(be.Uint32(row[12:])), uint64(be.Uint32(row[16:]))
		if name == "" || names[name] || n == 0 || off < 0x400 || off+n > uint64(len(b)) {
			return fmt.Errorf("固件分区越界或重复")
		}
		names[name] = true
		for _, s := range spans {
			if off < uint64(s.z) && uint64(s.a) < off+n {
				return fmt.Errorf("固件分区重叠")
			}
		}
		spans = append(spans, span{int(off), int(off + n)})
		if name == "tpHead" {
			if n < 0x600 {
				return fmt.Errorf("设备头过短")
			}
			head = int(off)
		}
	}
	if head < 0 || !bytes.Equal(b[head+4:head+24], tpMagic) || !bytes.Equal(b[head+0x204:head+0x218], customMagic) {
		return fmt.Errorf("缺少有效的设备固件头")
	}
	hw, bl := int(be.Uint16(b[0xa0:])), int(be.Uint16(b[0xa2:]))
	if hw < 1 || hw > 4 || bl > 96 || 0xb0+(hw+bl)*16 > 0x200 {
		return fmt.Errorf("固件硬件标识列表越界")
	}
	im.Format = "tp-container"
	im.Brand = be.Uint16(b[0x1a:])
	im.Model = cstring(b[head+0xc0 : head+0x100])
	im.Version = cstring(b[head+0x218 : head+0x24c])
	im.FirmwareID = hex.EncodeToString(b[head+0xb0 : head+0xc0])
	if im.Model == "" || im.FirmwareID == strings.Repeat("0", 32) {
		return fmt.Errorf("固件型号或版本标识为空")
	}
	seenIDs := map[string]bool{}

	for i := 0; i < hw+bl; i++ {
		id := hex.EncodeToString(b[0xb0+i*16 : 0xc0+i*16])
		if id == strings.Repeat("0", 32) || seenIDs[id] {
			return fmt.Errorf("固件硬件/禁止升级标识为空或重复")
		}
		seenIDs[id] = true
		if i < hw {
			im.HardwareIDs = append(im.HardwareIDs, id)
		} else {
			im.Blocked = append(im.Blocked, id)
		}
	}
	var err error
	im.WireVersion, err = versionWire(im.Version)
	return err
}

var partitionRE = regexp.MustCompile(`fwup-ptn\s+(\S+)\s+base\s+(?:0x)?([0-9a-fA-F]+)\s+size\s+(?:0x)?([0-9a-fA-F]+)`)
var supportRE = regexp.MustCompile(`([^\r\n:]+):\s*(\d+)\.(\d+)`)

func (im *Image) legacy(b []byte) error {
	if len(b) < 0x1814 {
		return fmt.Errorf("未知固件格式")
	}
	size := int(be.Uint32(b))
	if size != len(b) && size+128 != len(b) {
		return fmt.Errorf("固件头声明的大小不符")
	}
	hash := md5.New()
	hash.Write(legacySalt)
	hash.Write(b[20:size])
	if !bytes.Equal(hash.Sum(nil), b[4:20]) {
		return fmt.Errorf("固件内嵌 MD5 校验失败")
	}
	parts := map[string][]byte{}
	type extent struct{ start, end uint64 }
	var extents []extent
	for _, m := range partitionRE.FindAllStringSubmatch(cstring(b[0x1014:0x1814]), -1) {
		off, _ := strconv.ParseUint(m[2], 16, 32)
		n, _ := strconv.ParseUint(m[3], 16, 32)
		off += 0x101c
		if off < 0x1814 || off+n > uint64(size) || n == 0 || parts[m[1]] != nil {
			return fmt.Errorf("固件分区越界或重复")
		}
		for _, e := range extents {
			if off < e.end && e.start < off+n {
				return fmt.Errorf("固件分区重叠")
			}
		}
		extents = append(extents, extent{off, off + n})
		parts[m[1]] = b[off : off+n]
	}
	sup, ok := parts["support-list"]
	if !ok {
		return fmt.Errorf("缺少硬件支持列表")
	}
	s := cstring(sup)
	pos := strings.Index(s, "SupportList:")
	if pos < 0 {
		return fmt.Errorf("硬件支持列表无效")
	}
	for _, m := range supportRE.FindAllStringSubmatch(s[pos+12:], -1) {
		model := strings.TrimSpace(m[1])
		if len(model) > 64 {
			return fmt.Errorf("型号名称过长")
		}
		im.Support = append(im.Support, Support{model, m[2] + "." + m[3]})
	}
	if len(im.Support) < 1 || len(im.Support) > 10 {
		return fmt.Errorf("硬件支持列表数量无效")
	}
	v := parts["soft-version"]
	if len(v) < 12 {
		return fmt.Errorf("缺少软件版本")
	}
	date := fmt.Sprintf("%08x", be.Uint32(v[4:]))
	im.Version = fmt.Sprintf("%d.%d.%d Build %s Rel.%d", v[1], v[2], v[3], date, be.Uint32(v[8:]))
	im.Format = "safeloader"
	im.Model = im.Support[0].Model
	var err error
	im.WireVersion, err = versionWire(im.Version)
	return err
}

// Compatible requires AP-reported hardware identity for modern images. Firmware
// IDs denote versions; they are not interchangeable with hardware IDs.
func (im Image) Compatible(model, hw, hardwareID string, blocked []string) error {
	if im.Format == "tp-container" {
		found := false
		for _, id := range im.HardwareIDs {
			found = found || strings.EqualFold(id, hardwareID)
		}
		if hardwareID == "" || !found {
			return fmt.Errorf("固件不支持 AP 上报的硬件标识")
		}
		for _, id := range blocked {
			if strings.EqualFold(id, im.FirmwareID) {
				return fmt.Errorf("AP 禁止升级到此固件版本")
			}
		}
		return nil
	}
	for _, s := range im.Support {
		if s.Model == model && s.Hardware == hw {
			return nil
		}
	}
	return fmt.Errorf("固件型号或硬件版本不匹配")
}
func (im Image) Identifier() []byte { return append([]byte{0x12, 0x34, 0x56, 0x78}, im.WireVersion...) }
