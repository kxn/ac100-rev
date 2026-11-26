package firmware

import (
	"bytes"
	"crypto/md5"
	"encoding/hex"
	"testing"
)

func modernFixture() []byte {
	b := make([]byte, 4096)
	copy(b[4:], upgradeMagic)
	copy(b[0x204:], customMagic)
	be.PutUint16(b[0x21e:], 1)
	copy(b[0x220:], "tpHead")
	be.PutUint32(b[0x22c:], 0x400)
	be.PutUint32(b[0x230:], 0xc00)
	be.PutUint16(b[0xa0:], 1)
	copy(b[0xb0:], bytes.Repeat([]byte{0x42}, 16))
	copy(b[0x404:], tpMagic)
	copy(b[0x604:], customMagic)
	copy(b[0x4b0:], bytes.Repeat([]byte{0x73}, 16))
	copy(b[0x4c0:], "TL-TEST")
	copy(b[0x618:], "1.2.3 Build 20250317 Rel.43192\n")
	return b
}
func TestModernInspectionAndHardwareIdentity(t *testing.T) {
	b := modernFixture()
	im, err := Inspect(b)
	if err != nil {
		t.Fatal(err)
	}
	if im.Model != "TL-TEST" || im.Version != "1.2.3 Build 20250317 Rel.43192" || hex.EncodeToString(im.WireVersion) != "00010002000307e903110000a8b8" {
		t.Fatal(im)
	}
	if err = im.Compatible("renamed-model", "1.0", im.HardwareIDs[0], nil); err != nil {
		t.Fatal(err)
	}
	if err = im.Compatible("TL-TEST", "1.0", im.FirmwareID, nil); err == nil {
		t.Fatal("confused firmware ID with hardware ID")
	}
	if err = im.Compatible("TL-TEST", "1.0", im.HardwareIDs[0], []string{im.FirmwareID}); err == nil {
		t.Fatal("AP blacklist bypassed")
	}
	for _, mutate := range []func([]byte){func(b []byte) { be.PutUint16(b[0xa0:], 0xffff) }, func(b []byte) { be.PutUint16(b[0xa2:], 32) }, func(b []byte) { be.PutUint16(b[0x21e:], 65535) }, func(b []byte) { be.PutUint32(b[0x22c:], 0xfffffff0) }, func(b []byte) { b[0x604] = 0 }, func(b []byte) { copy(b[0x220:], "kernel\x00") }} {
		x := bytes.Clone(b)
		mutate(x)
		if _, err = Inspect(x); err == nil {
			t.Fatal("accepted malformed image")
		}
	}
	if !bytes.Equal(b, modernFixture()) {
		t.Fatal("inspection changed firmware")
	}
}
func legacyFixture() []byte {
	b := make([]byte, 0x3000)
	be.PutUint32(b, uint32(len(b)))
	copy(b[0x1014:], "fwup-ptn support-list base 1000 size 80\nfwup-ptn soft-version base 1100 size 0c\n")
	copy(b[0x201c:], "SupportList:\r\nTL-TEST:1.0\r\nTL-OTHER:2.1\r\n")
	copy(b[0x211c:], []byte{0, 1, 2, 3, 0x20, 0x25, 3, 0x17, 0, 0, 0xa8, 0xb8})
	h := md5.New()
	h.Write(legacySalt)
	h.Write(b[20:])
	copy(b[4:20], h.Sum(nil))
	return b
}
func TestLegacyChecksumSupportAndVersion(t *testing.T) {
	b := legacyFixture()
	im, err := Inspect(b)
	if err != nil {
		t.Fatal(err)
	}
	if len(im.Support) != 2 || im.Version != "1.2.3 Build 20250317 Rel.43192" {
		t.Fatal(im)
	}
	if err = im.Compatible("TL-TEST", "1.0", "", nil); err != nil {
		t.Fatal(err)
	}
	if err = im.Compatible("TL-TEST", "2.0", "", nil); err == nil {
		t.Fatal("wrong hardware accepted")
	}
	b[len(b)-1] ^= 1
	if _, err = Inspect(b); err == nil {
		t.Fatal("checksum corruption accepted")
	}
	b = legacyFixture()
	b = append(b, make([]byte, 128)...)
	if _, err = Inspect(b); err != nil {
		t.Fatal("signed trailer", err)
	}
}
func FuzzInspect(f *testing.F) {
	f.Add(modernFixture())
	f.Add(legacyFixture())
	f.Add([]byte{1, 2, 3})
	f.Fuzz(func(t *testing.T, b []byte) { _, _ = Inspect(b) })
}

func TestFirmwareRejectsEmptyIdentityAndOverlappingPartitions(t *testing.T) {
	for _, offset := range []int{0xb0, 0x4b0} {
		b := modernFixture()
		clear(b[offset : offset+16])
		if _, err := Inspect(b); err == nil {
			t.Fatal("empty identity accepted", offset)
		}
	}
	b := legacyFixture()
	copy(b[0x1014:], "fwup-ptn support-list base 1000 size 80\nfwup-ptn soft-version base 1040 size 0c\n")
	h := md5.New()
	h.Write(legacySalt)
	h.Write(b[20:])
	copy(b[4:20], h.Sum(nil))
	if _, err := Inspect(b); err == nil {
		t.Fatal("overlapping legacy partitions accepted")
	}
}
