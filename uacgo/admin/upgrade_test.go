package admin

import (
	"bytes"
	"context"
	"crypto/md5"
	"encoding/binary"
	"encoding/hex"
	"fmt"
	"os"
	"path/filepath"
	"sync"
	"testing"
	"time"
	"uacgo/capwap"
	"uacgo/cweng"
)

func upgradeFixture(size int) []byte {
	if size < 4096 {
		size = 4096
	}
	b := make([]byte, size)
	put := binary.BigEndian.PutUint32
	magic, _ := hex.DecodeString("55aa4c5e831f534ba1f8f7c918df8fbf7da1aa55")
	copy(b[4:], magic)
	custom, _ := hex.DecodeString("a5a5a5a58f72632a040f86009206bb51d2b7636a")
	copy(b[0x204:], custom)
	copy(b[0x604:], custom)
	magic, _ = hex.DecodeString("55aa9dd1a8c88331c969fbbfbcf0d43270c7aa55")
	copy(b[0x404:], magic)
	binary.BigEndian.PutUint16(b[0x21e:], 1)
	copy(b[0x220:], "tpHead")
	put(b[0x22c:], 0x400)
	put(b[0x230:], uint32(size-0x400))
	binary.BigEndian.PutUint16(b[0xa0:], 1)
	copy(b[0xb0:], bytes.Repeat([]byte{0x42}, 16))
	copy(b[0x4b0:], bytes.Repeat([]byte{0x73}, 16))
	copy(b[0x4c0:], "TEST-AP")
	copy(b[0x618:], "1.2.3 Build 20250317 Rel.43192")
	for i := 4096; i < len(b); i++ {
		b[i] = byte(i % 251)
	}
	return b
}
func TestUpgradeBatchRejectsWrongHardwareAndInterruptedJobs(t *testing.T) {
	m, e := testController(t)
	_, a := newDeferredAP(t, e)
	_, b := newDeferredAP(t, e)
	im, err := m.importImage(upgradeFixture(0))
	if err != nil {
		t.Fatal(err)
	}
	a.HardwareID = im.HardwareIDs[0]
	b.HardwareID = "wrong"
	m.known[a.ID] = a
	m.known[b.ID] = b
	m.mu.Lock()
	_, err = m.queueUpgrades(im.ID, []string{a.ID, b.ID}, time.Time{})
	m.mu.Unlock()
	if err == nil || len(m.upgrades.Jobs) != 0 {
		t.Fatal("partial incompatible batch accepted")
	}
	m.mu.Lock()
	jobs, err := m.queueUpgrades(im.ID, []string{a.ID}, time.Now().Add(time.Hour))
	m.mu.Unlock()
	if err != nil {
		t.Fatal(err)
	}
	j := jobs[0]
	j.State = "transferring"
	m.upgrades.Jobs[j.ID] = j
	if err = m.saveUpgrades(); err != nil {
		t.Fatal(err)
	}
	restored, err := New(e, cweng.NewClientTable(), filepath.Dir(m.path))
	if err != nil {
		t.Fatal(err)
	}
	if restored.upgrades.Jobs[j.ID].State != "interrupted" {
		t.Fatal("interrupted image silently replayed")
	}
}
func TestUpgradeSequentialWireAndVersionConfirmation(t *testing.T) {
	for _, tc := range []struct {
		name         string
		size         int
		large, cap81 bool
	}{
		{"ordinary", 4096, false, true},
		{"extension81", (16 << 20) + 4096, true, true},
		{"ordinary-over-16MiB-without81", (16 << 20) + 4096, false, false},
	} {
		t.Run(tc.name, func(t *testing.T) {
			large := tc.large
			m, e := testController(t)
			f, ap := newDeferredAP(t, e)
			size := tc.size
			image := upgradeFixture(size)
			im, err := m.importImage(image)
			if err != nil {
				t.Fatal(err)
			}
			ap.HardwareID = im.HardwareIDs[0]
			ap.GeneralCapabilities = make([]uint32, 3)
			if tc.cap81 {
				ap.GeneralCapabilities[2] = 1 << 17
			}
			m.known[ap.ID] = ap
			m.mu.Lock()
			jobs, err := m.queueUpgrades(im.ID, []string{ap.ID}, time.Time{})
			m.mu.Unlock()
			if err != nil {
				t.Fatal(err)
			}
			j := jobs[0]
			j.Connection = ap.ConnectedAt
			m.upgrades.Jobs[j.ID] = j
			var lock sync.Mutex
			received := []byte{}
			var subSize, totalSize int
			var subMD5, totalMD5 []byte
			reset, flash := false, false
			var wireErr error
			seq := byte(10)
			fail := func(s string) {
				if wireErr == nil {
					wireErr = fmt.Errorf("%s", s)
				}
			}
			send := func(els ...capwap.Element) {
				seq++
				if seq == 0 {
					seq = 1
				}
				p, _ := capwap.NewParsedPacket(15)
				p.Control.SeqNum = seq
				p.Elements = els
				_, _ = f.conn.Write(p.Assemble())
			}
			f.mu.Lock()
			if !large {
				f.dropACK = true
			}
			f.onCommand = func(p *capwap.ParsedPacket) {
				lock.Lock()
				defer lock.Unlock()
				for _, el := range p.Elements {
					v := el.Value
					if el.Type == 0x19 && p.Control.MsgType == 7 {
						if !bytes.Equal(v, im.Identifier()) {
							fail("wrong version identifier")
						}
						send(capwap.Element{Type: 0x19, Value: v}, capwap.Element{Type: 0x1b})
						continue
					}
					if el.Type == 0x25 && len(v) >= 10 {
						typ := binary.BigEndian.Uint16(v[6:])
						v = v[10:]
						switch typ {
						case 0xaf:
							if len(v) != 29 || v[0] != 1 || binary.BigEndian.Uint32(v[5:]) != 2 {
								fail("bad large metadata")
							}
							totalSize = int(binary.BigEndian.Uint32(v[1:]))
							totalMD5 = bytes.Clone(v[9:25])
						case 0xb0:
							if len(v) != 26 {
								fail("bad sub metadata")
								continue
							}
							subSize = int(binary.BigEndian.Uint32(v[2:]))
							subMD5 = bytes.Clone(v[6:22])
						case 0xb1:
							if v[0] == 0 {
								if len(received) < subSize {
									fail("missing subdata")
								}
								sum := md5.Sum(received[len(received)-subSize:])
								if !bytes.Equal(sum[:], subMD5) {
									fail("sub checksum wrong")
								}
								send(privateSetting(0xb1, []byte{1, v[1], 0, 0, 0, 0}))
							}
						}
					}
					if el.Type == 0x18 {
						if v[0] == 2 && large {
							if len(v) != 5 || !bytes.Equal(v[1:], []byte{0, 0, 0, 0}) {
								fail("bad large EOF")
							}
							sum := md5.Sum(received)
							if len(received) != totalSize || !bytes.Equal(sum[:], totalMD5) {
								fail("total checksum mismatch")
							}
							send(privateSetting(0xb1, []byte{3, 255, 0, 0, 0, 0}))
							flash = true
						} else {
							if len(v) < 2 || len(v) > 1025 {
								fail("image has invented inner length")
							}
							received = append(received, v[1:]...)
							if large && v[0] != 1 {
								fail("large subdata ended image early")
							}
						}
					}
					if p.Control.MsgType == 17 {
						reset = true
					}
				}
			}
			f.mu.Unlock()
			ctx, cancel := context.WithTimeout(context.Background(), 30*time.Second)
			defer cancel()
			err = m.transferImage(ctx, ap, j, im)
			f.mu.Lock()
			if !large {
				f.dropACK = true
			}
			f.onCommand = nil
			f.mu.Unlock()
			lock.Lock()
			defer lock.Unlock()
			if err != nil || wireErr != nil || !bytes.Equal(received, image) || (!large && !reset) || (large && !flash) {
				t.Fatal(err, wireErr, len(received), size, reset, flash)
			}
			m.mu.Lock()
			state := m.upgrades.Jobs[j.ID].State
			m.mu.Unlock()
			if state != "waiting_reconnect" {
				t.Fatal("transfer was mistaken for successful upgrade", state)
			}
			ap.ConnectedAt = time.Now()
			ap.SoftwareVersion = im.Version
			m.known[ap.ID] = ap
			m.observeUpgrades(time.Now())
			if m.upgrades.Jobs[j.ID].State != "completed" {
				t.Fatal(m.upgrades.Jobs[j.ID])
			}
		})
	}
}
func TestUpgradeRejectsTamperedStorageBeforeSending(t *testing.T) {
	m, e := testController(t)
	f, ap := newDeferredAP(t, e)
	im, err := m.importImage(upgradeFixture(0))
	if err != nil {
		t.Fatal(err)
	}
	b := upgradeFixture(0)
	b[len(b)-1] ^= 1
	if err = os.WriteFile(m.imagePath(im.ID), b, 0600); err != nil {
		t.Fatal(err)
	}
	err = m.transferImage(context.Background(), ap, UpgradeJob{}, im)
	if err == nil {
		t.Fatal("storage corruption accepted")
	}
	f.mu.Lock()
	defer f.mu.Unlock()
	if len(f.packets) != 0 {
		t.Fatal("sent corrupted firmware")
	}
}

func TestUpgradeRejectsWrongSessionSequenceAndFailedFinalChecksum(t *testing.T) {
	m, _ := testController(t)
	connection := time.Now()
	ap := "02:01:02:03:04:05"
	j := UpgradeJob{ID: "job", AP: ap, Image: "image", State: "verifying", Connection: connection, Bytes: 17 << 20}
	m.upgrades.Jobs[j.ID] = j
	rt := &upgradeRuntime{Job: j.ID, Connection: connection, Expected: 255, Await: "final", Actions: make(chan capwap.PrivSubFirmwareAction, 8)}
	m.upgradeActive[ap] = rt
	for _, a := range []capwap.PrivSubFirmwareAction{{Type: 3, SubType: 1}, {Type: 1, SubType: 255}, {Type: 2, SubType: 255}} {
		if _, err := m.confirmImageAction(ap, connection, a); err == nil {
			t.Fatal("out-of-order flash authorization", a)
		}
	}
	if _, err := m.confirmImageAction(ap, connection.Add(time.Second), capwap.PrivSubFirmwareAction{Type: 3, SubType: 255}); err == nil {
		t.Fatal("new session inherited old flash permission")
	}
	reply, err := m.confirmImageAction(ap, connection, capwap.PrivSubFirmwareAction{Type: 3, SubType: 255, Action: 2})
	if err != nil || reply != nil || m.upgrades.Jobs[j.ID].State != "verifying" {
		t.Fatal("failed checksum authorized flashing", reply, err)
	}
	if err = waitImageAction(context.Background(), rt, 3, 255); err == nil {
		t.Fatal("worker ignored AP checksum failure")
	}
	if reply, err = m.confirmImageAction(ap, connection, capwap.PrivSubFirmwareAction{Type: 3, SubType: 255}); err != nil || reply == nil || reply.Type != 2 || m.upgrades.Jobs[j.ID].State != "waiting_reconnect" {
		t.Fatal("successful checksum not durably authorized", reply, err)
	}
}

func TestMeshFirmwareJobsSerializeByTransportAndAllowQueuedInitialization(t *testing.T) {
	m, _ := testController(t)
	now := time.Now()
	m.known["parent"] = cweng.APStatus{ID: "parent"}
	m.known["child"] = cweng.APStatus{ID: "child", MeshParent: "parent"}
	a := UpgradeJob{ID: "a", AP: "parent", State: "queued", NotBefore: now}
	b := UpgradeJob{ID: "b", AP: "child", State: "queued", NotBefore: now}
	m.upgrades.Jobs = map[string]UpgradeJob{"a": a, "b": b}
	if !m.upgradeTurnLocked(a) || m.upgradeTurnLocked(b) || m.upgradeTransportActiveLocked("child") {
		t.Fatal("queued transport order/initialization")
	}
	a.State = "transferring"
	m.upgrades.Jobs["a"] = a
	if !m.upgradeBusyLocked("child") || !m.upgradeTransportActiveLocked("child") || m.upgradeTurnLocked(b) {
		t.Fatal("parallel parent/child upgrade allowed")
	}
	a.State = "completed"
	m.upgrades.Jobs["a"] = a
	if !m.upgradeTurnLocked(b) {
		t.Fatal("child upgrade not released")
	}
}

func TestUpgradeTransportCycleHasOneCanonicalIdentity(t *testing.T) {
	m, _ := testController(t)
	m.known["a"] = cweng.APStatus{ID: "a", MeshParent: "b"}
	m.known["b"] = cweng.APStatus{ID: "b", MeshParent: "a"}
	m.known["leaf"] = cweng.APStatus{ID: "leaf", MeshParent: "b"}
	for _, id := range []string{"a", "b", "leaf"} {
		if m.upgradeTransportLocked(id) != "a" {
			t.Fatal("cycle produced distinct transfer groups", id)
		}
	}
}
