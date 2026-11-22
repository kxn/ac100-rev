package cweng

import (
	"bytes"
	"net"
	"testing"
	"time"

	"uacgo/capwap"
)

type testImage struct{}

func (testImage) Identifier() [4]byte { return [4]byte{0x12, 0x34, 0x56, 0x78} }
func (testImage) Info() [16]byte      { return [16]byte{1, 2, 3} }
func (testImage) File() []byte {
	f := make([]byte, 2000)
	for i := range f {
		f[i] = byte(i)
	}
	return f
}
func (testImage) ChunkSize() int { return 1024 }

// The msg 15 listener: identifier confirm adds result code + 0x1a image
// information (20 bytes); the type-5 pull returns 0x18 chunks at the
// requested offset (apupd @0x643550 + apupd_image_data_add @0x661618).
func TestUpdImageFlow(t *testing.T) {
	e, _ := NewEngine(0)
	e.RegisterAttachHandlers(fixtureIdentity{})
	e.RegisterUpdHandlers(testImage{})
	go func() { _ = e.Run() }()

	c, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: e.LocalPort()})
	if err != nil {
		t.Fatal(err)
	}
	defer c.Close()
	read := func() *capwap.ParsedPacket {
		buf := make([]byte, capwap.MaxUdpPayload)
		c.SetReadDeadline(time.Now().Add(2 * time.Second))
		n, err := c.Read(buf)
		if err != nil {
			t.Fatalf("no response: %v", err)
		}
		p, err := capwap.ParsePacket(buf[:n])
		if err != nil {
			t.Fatalf("bad response: %v", err)
		}
		return p
	}
	// reach RUN
	c.Write(withSeq(t, "cw_join_req_0074f150.bin", 2))
	read()
	c.Write(withSeq(t, "cw_cfg_req_0074ef5c.bin", 3))
	read()
	c.Write(withSeq(t, "cw_cse_req_0074ee9c.bin", 4))
	read()

	// identifier confirm
	p, _ := capwap.NewParsedPacket(capwap.MsgImageDataRequest)
	p.Control.SeqNum = 5
	p.Elements = append(p.Elements, capwap.Element{
		Type: 0x0019, Value: []byte{0x12, 0x34, 0x56, 0x78}})
	c.Write(p.Assemble())
	rsp := read()
	rc, rcOK := elementOf(rsp, 0x0021)
	if !rcOK || !bytes.Equal(rc.Value, []byte{0, 0, 0, 0}) {
		t.Fatalf("confirm result code = %v", rc)
	}
	info, infoOK := elementOf(rsp, 0x001a)
	if !infoOK || len(info.Value) != 20 {
		t.Fatalf("image information = %d bytes", len(info.Value))
	}

	// chunk pull at offset 1024 (second chunk, 976 bytes)
	chunkReq := []byte{5, 0, 4, 0, 0, 4, 0}
	p2, _ := capwap.NewParsedPacket(capwap.MsgImageDataRequest)
	p2.Control.SeqNum = 6
	p2.Elements = append(p2.Elements, capwap.Element{Type: 0x0018, Value: chunkReq})
	c.Write(p2.Assemble())
	rsp2 := read()
	data, dataOK := elementOf(rsp2, 0x0018)
	if !dataOK {
		t.Fatal("no image data chunk")
	}
	size := int(data.Value[1])<<8 | int(data.Value[2])
	if size != 976 || len(data.Value) != 3+976 {
		t.Fatalf("chunk size = %d (want 976)", size)
	}
	if data.Value[3] != byte(1024%256) { // offset 1024 first byte
		t.Fatalf("chunk data starts wrong: %x", data.Value[3:6])
	}
	rc2, rc2OK := elementOf(rsp2, 0x0021)
	if !rc2OK || !bytes.Equal(rc2.Value, []byte{0, 0, 0, 0}) {
		t.Fatalf("chunk result code = %v", rc2)
	}
}
