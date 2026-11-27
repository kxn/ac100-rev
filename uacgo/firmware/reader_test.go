package firmware

import (
	"bytes"
	"io"
	"testing"
)

type observedReader struct {
	io.ReaderAt
	largest int
}

func (r *observedReader) ReadAt(b []byte, off int64) (int, error) {
	r.largest = max(r.largest, len(b))
	return r.ReaderAt.ReadAt(b, off)
}
func TestImageReaderUsesBoundedPayloadReads(t *testing.T) {
	image := append(modernFixture(), make([]byte, (32<<20)-4096)...)
	r := &observedReader{ReaderAt: bytes.NewReader(image)}
	got, err := InspectReader(r, len(image))
	if err != nil || got.Size != len(image) || got.Model != "TL-TEST" {
		t.Fatal(got, err)
	}
	if r.largest > 32<<10 {
		t.Fatal("whole payload requested", r.largest)
	}
	if _, err = InspectReader(bytes.NewReader(image[:4096]), len(image)); err == nil {
		t.Fatal("truncated payload accepted")
	}
	// The device header can reside in any validated tpHead partition.
	shifted := append([]byte{}, image[:0x400]...)
	shifted = append(shifted, make([]byte, 0x10000)...)
	copy(shifted[0x10000:], image[0x400:0x1000])
	be.PutUint32(shifted[0x22c:], 0x10000)
	be.PutUint32(shifted[0x230:], 0x400)
	if _, err = InspectReader(bytes.NewReader(shifted), len(shifted)); err == nil {
		t.Fatal("undersized device partition accepted")
	}
	shifted = append(shifted, make([]byte, 0xc00)...)
	copy(shifted[0x10000:], image[0x400:0x1000])
	be.PutUint32(shifted[0x230:], 0xc00)
	if got, err = InspectReader(bytes.NewReader(shifted), len(shifted)); err != nil || got.Model != "TL-TEST" {
		t.Fatal("relocated metadata", got, err)
	}
}
