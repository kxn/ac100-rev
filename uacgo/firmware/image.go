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
	"io"
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
func Inspect(b []byte) (Image, error) { return InspectReader(bytes.NewReader(b), len(b)) }

// InspectReader hashes the payload in a fixed-size buffer and reads only
// metadata partitions. AP images need not reside in the Go heap.
func InspectReader(r io.ReaderAt, size int) (Image, error) {
	var im Image
	if size < 0x400 || size > MaxSize {
		return im, fmt.Errorf("固件大小必须为 1 KiB–32 MiB")
	}
	sha, sum := sha256.New(), md5.New()
	if _, err := io.CopyN(io.MultiWriter(sha, sum), io.NewSectionReader(r, 0, int64(size)), int64(size)); err != nil {
		return im, err
	}
	im = Image{ID: hex.EncodeToString(sha.Sum(nil)), Size: size, MD5: hex.EncodeToString(sum.Sum(nil))}
	header, err := readImagePart(r, 0, 0x400)
	if err != nil {
		return Image{}, err
	}
	if bytes.Equal(header[4:24], upgradeMagic) {
		err = im.modern(r, header)
	} else {
		err = im.legacy(r)
	}
	if err != nil {
		return Image{}, err
	}
	return im, nil
}

func readImagePart(r io.ReaderAt, off, size int) ([]byte, error) {
	b := make([]byte, size)
	_, err := r.ReadAt(b, int64(off))
	return b, err
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
func (im *Image) modern(r io.ReaderAt, b []byte) error {
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
		if name == "" || names[name] || n == 0 || off < 0x400 || off+n > uint64(im.Size) {
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
	if head < 0 {
		return fmt.Errorf("缺少有效的设备固件头")
	}
	device, err := readImagePart(r, head, 0x600)
	if err != nil {
		return err
	}
	if !bytes.Equal(device[4:24], tpMagic) || !bytes.Equal(device[0x204:0x218], customMagic) {
		return fmt.Errorf("缺少有效的设备固件头")
	}
	hw, bl := int(be.Uint16(b[0xa0:])), int(be.Uint16(b[0xa2:]))
	if hw < 1 || hw > 4 || bl > 96 || 0xb0+(hw+bl)*16 > 0x200 {
		return fmt.Errorf("固件硬件标识列表越界")
	}
	im.Format = "tp-container"
	im.Brand = be.Uint16(b[0x1a:])
	im.Model = cstring(device[0xc0:0x100])
	im.Version = cstring(device[0x218:0x24c])
	im.FirmwareID = hex.EncodeToString(device[0xb0:0xc0])
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
	im.WireVersion, err = versionWire(im.Version)
	return err
}

var partitionRE = regexp.MustCompile(`fwup-ptn\s+(\S+)\s+base\s+(?:0x)?([0-9a-fA-F]+)\s+size\s+(?:0x)?([0-9a-fA-F]+)`)
var supportRE = regexp.MustCompile(`([^\r\n:]+):\s*(\d+)\.(\d+)`)

func (im *Image) legacy(r io.ReaderAt) error {
	if im.Size < 0x1814 {
		return fmt.Errorf("未知固件格式")
	}
	b, err := readImagePart(r, 0, 0x1814)
	if err != nil {
		return err
	}
	size := int(be.Uint32(b))
	if size != im.Size && size+128 != im.Size {
		return fmt.Errorf("固件头声明的大小不符")
	}
	hash := md5.New()
	hash.Write(legacySalt)
	if _, err := io.CopyN(hash, io.NewSectionReader(r, 20, int64(size-20)), int64(size-20)); err != nil {
		return err
	}
	if !bytes.Equal(hash.Sum(nil), b[4:20]) {
		return fmt.Errorf("固件内嵌 MD5 校验失败")
	}
	type extent struct{ start, end uint64 }
	parts := map[string]extent{}
	var extents []extent
	for _, m := range partitionRE.FindAllStringSubmatch(cstring(b[0x1014:0x1814]), -1) {
		off, _ := strconv.ParseUint(m[2], 16, 32)
		n, _ := strconv.ParseUint(m[3], 16, 32)
		off += 0x101c
		if off < 0x1814 || off+n > uint64(size) || n == 0 || parts[m[1]].end != 0 {
			return fmt.Errorf("固件分区越界或重复")
		}
		for _, e := range extents {
			if off < e.end && e.start < off+n {
				return fmt.Errorf("固件分区重叠")
			}
		}
		extents = append(extents, extent{off, off + n})
		parts[m[1]] = extent{off, off + n}
	}
	support, ok := parts["support-list"]
	if !ok {
		return fmt.Errorf("缺少硬件支持列表")
	}
	sup, err := readImagePart(r, int(support.start), int(support.end-support.start))
	if err != nil {
		return err
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
	version := parts["soft-version"]
	if version.end-version.start < 12 {
		return fmt.Errorf("缺少软件版本")
	}
	v, err := readImagePart(r, int(version.start), 12)
	if err != nil {
		return err
	}
	date := fmt.Sprintf("%08x", be.Uint32(v[4:]))
	im.Version = fmt.Sprintf("%d.%d.%d Build %s Rel.%d", v[1], v[2], v[3], date, be.Uint32(v[8:]))
	im.Format = "safeloader"
	im.Model = im.Support[0].Model
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
