package capwap

import (
	"bytes"
	"testing"
)

// Batch-13: image information/image data + mesh/ip-report/sub-capability.
func TestBatch13Roundtrips(t *testing.T) {
	// image information: 20 bytes
	ii := ImageInformation{FileInfo: 0x12345678}
	copy(ii.Info[:], "abcdefghijklmnop")
	e := AppendImageInformation(nil, ii)
	if len(e[4:]) != 20 {
		t.Fatalf("image info len = %d", len(e[4:]))
	}
	if v, err := ParseImageInformation(e[4:]); err != nil || v.FileInfo != 0x12345678 {
		t.Fatalf("image info parse: %v", err)
	}

	// Independent V6 wire: type + raw bytes, no inner length word.
	id := ImageData{Type: 1, Data: []byte("chunk-bytes")}
	w := id.AssembleValue()
	if !bytes.Equal(w, append([]byte{1}, []byte("chunk-bytes")...)) {
		t.Fatalf("image data header = %x", w[:3])
	}
	if v, err := ParseImageData(w); err != nil || !bytes.Equal(v.Data, id.Data) {
		t.Fatalf("image data parse: %v", err)
	}
	// type 5 (pull request) with empty data
	pull := ImageData{Type: 5}
	if v, err := ParseImageData(pull.AssembleValue()); err != nil || v.Type != 5 {
		t.Fatalf("pull: %v", err)
	}
	// invalid type 3 must fail
	if _, err := ParseImageData([]byte{3, 0, 0}); err == nil {
		t.Fatal("type 3 must fail")
	}
	for _, bad := range [][]byte{{1}, {2}, {5, 0}, append([]byte{1}, make([]byte, 1025)...)} {
		if _, err := ParseImageData(bad); err == nil {
			t.Fatal("invalid image data accepted")
		}
	}

	// mesh control / sub capability / ip report: verbatim carriers
	mc, _ := ParsePrivMeshControl([]byte{1, 2, 3})
	if len(mc) != 3 {
		t.Fatal("mesh control len")
	}
	sc, _ := ParsePrivWtpSubCapability([]byte{0xf0})
	if len(sc) != 1 {
		t.Fatal("sub cap len")
	}
	ip, _ := ParsePrivIPReport([]byte{9, 8, 7})
	if len(ip) != 3 {
		t.Fatal("ip report len")
	}
}
