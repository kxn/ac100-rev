// Package legacydtls implements the DTLS 1.0 RSA/AES-CBC control transport
// required by the TL-7AP5100. It is separate from the DTLS 1.2 Pion backend.
// Protocol: RFC 4347 and RFC 4346. AP evidence: 2026-11-26 capture, ClientHello
// feff with suites 0039,0033,0035,002f,0005,0004,000a; vendor selects 0035.
package legacydtls

import (
	"bytes"
	"crypto/aes"
	"crypto/cipher"
	"crypto/hmac"
	"crypto/md5"
	"crypto/rand"
	"crypto/rsa"
	"crypto/sha1"
	"crypto/sha256"
	"crypto/subtle"
	"crypto/tls"
	"encoding/binary"
	"errors"
	"fmt"
	"hash"
	"sync"
	"time"
)

var ErrRecord = errors.New("dtls: invalid record")

type flightRecord struct {
	kind  byte
	epoch uint16
	data  []byte
}
type peer struct {
	random, serverRandom, transcript, master []byte
	readMAC, writeMAC, readKey, writeKey     []byte
	next                                     [2]uint64
	flight                                   []flightRecord
	expected                                 uint16
	established, cipherChanged               bool
	last                                     time.Time
	top, window                              uint64
	seen                                     bool
}

type Server struct {
	mu       sync.Mutex
	cert     tls.Certificate
	key      *rsa.PrivateKey
	cookie   [32]byte
	peers    map[string]*peer
	MaxPeers int
}

func New(certFile, keyFile string) (*Server, error) {
	cert, err := tls.LoadX509KeyPair(certFile, keyFile)
	if err != nil {
		return nil, err
	}
	key, ok := cert.PrivateKey.(*rsa.PrivateKey)
	if !ok {
		return nil, errors.New("dtls: RSA certificate required")
	}
	s := &Server{cert: cert, key: key, peers: map[string]*peer{}, MaxPeers: 64}
	if _, err = rand.Read(s.cookie[:]); err != nil {
		return nil, err
	}
	return s, nil
}
func u24(b []byte) int      { return int(b[0])<<16 | int(b[1])<<8 | int(b[2]) }
func put24(b []byte, n int) { b[0] = byte(n >> 16); b[1] = byte(n >> 8); b[2] = byte(n) }
func handshake(kind byte, seq uint16, body []byte) []byte {
	b := make([]byte, 12+len(body))
	b[0] = kind
	put24(b[1:], len(body))
	binary.BigEndian.PutUint16(b[4:], seq)
	put24(b[9:], len(body))
	copy(b[12:], body)
	return b
}
func prf(secret []byte, label string, seed []byte, n int) []byte {
	seed = append(append([]byte{}, label...), seed...)
	pHash := func(f func() hash.Hash, key []byte) []byte {
		a := seed
		out := []byte{}
		for len(out) < n {
			h := hmac.New(f, key)
			h.Write(a)
			a = h.Sum(nil)
			h.Reset()
			h.Write(a)
			h.Write(seed)
			out = append(out, h.Sum(nil)...)
		}
		return out[:n]
	}
	half := (len(secret) + 1) / 2
	a := pHash(md5.New, secret[:half])
	b := pHash(sha1.New, secret[len(secret)-half:])
	for i := range a {
		a[i] ^= b[i]
	}
	return a
}
func finished(master []byte, label string, transcript []byte) []byte {
	a := md5.Sum(transcript)
	b := sha1.Sum(transcript)
	return prf(master, label, append(a[:], b[:]...), 12)
}
func (s *Server) makeCookie(addr string, random []byte) []byte {
	h := hmac.New(sha256.New, s.cookie[:])
	h.Write([]byte(addr))
	h.Write(random)
	return h.Sum(nil)[:16]
}
func record(kind byte, epoch uint16, seq uint64, body []byte) []byte {
	b := make([]byte, 13+len(body))
	b[0] = kind
	b[1] = 0xfe
	b[2] = 0xff
	binary.BigEndian.PutUint16(b[3:], epoch)
	for i := 10; i >= 5; i-- {
		b[i] = byte(seq)
		seq >>= 8
	}
	binary.BigEndian.PutUint16(b[11:], uint16(len(body)))
	copy(b[13:], body)
	return b
}
func recordMAC(key, header, plain, extra []byte) []byte {
	h := hmac.New(func() hash.Hash { return ctSHA1{sha1.New().(constantTimeHash)} }, key)
	h.Write(header[3:11])
	h.Write(header[:3])
	h.Write([]byte{byte(len(plain) >> 8), byte(len(plain))})
	h.Write(plain)
	out := h.Sum(nil)
	h.Write(extra)
	return out
}

// SHA-1's constant-time finalization and the extra write equalize CBC MAC
// processing across valid/invalid padding lengths, as in Go crypto/tls.
type constantTimeHash interface {
	hash.Hash
	ConstantTimeSum([]byte) []byte
}
type ctSHA1 struct{ constantTimeHash }

func (h ctSHA1) Sum(b []byte) []byte { return h.ConstantTimeSum(b) }
func seal(key, mac, header, plain []byte) ([]byte, error) {
	block, err := aes.NewCipher(key)
	if err != nil {
		return nil, err
	}
	body := append(append([]byte{}, plain...), recordMAC(mac, header, plain, nil)...)
	count := aes.BlockSize - len(body)%aes.BlockSize
	body = append(body, bytes.Repeat([]byte{byte(count - 1)}, count)...)
	iv := make([]byte, aes.BlockSize)
	if _, err = rand.Read(iv); err != nil {
		return nil, err
	}
	cipher.NewCBCEncrypter(block, iv).CryptBlocks(body, body)
	return append(iv, body...), nil
}
func open(key, mac, header, body []byte) ([]byte, error) {
	if len(body) < 48 || len(body)%aes.BlockSize != 0 {
		return nil, ErrRecord
	}
	block, err := aes.NewCipher(key)
	if err != nil {
		return nil, ErrRecord
	}
	plain := append([]byte{}, body[16:]...)
	cipher.NewCBCDecrypter(block, body[:16]).CryptBlocks(plain, plain)
	pad := int(plain[len(plain)-1]) + 1
	good := subtle.ConstantTimeLessOrEq(pad, len(plain))
	for i := 0; i < len(plain) && i < 256; i++ {
		check := subtle.ConstantTimeLessOrEq(i+1, pad)
		equal := subtle.ConstantTimeByteEq(plain[len(plain)-1-i], byte(pad-1))
		good &= 1 ^ (check & (1 ^ equal))
	}
	pad = subtle.ConstantTimeSelect(good, pad, 1)
	n := len(plain) - 20 - pad
	n = subtle.ConstantTimeSelect(subtle.ConstantTimeLessOrEq(0, n), n, 0)
	want := recordMAC(mac, header, plain[:n], plain[n+20:])
	good &= subtle.ConstantTimeCompare(want, plain[n:n+20])
	if good != 1 {
		return nil, ErrRecord
	}
	return plain[:n], nil
}
func (p *peer) encode(r flightRecord) ([]byte, error) {
	if len(r.data) > 16384 {
		return nil, errors.New("dtls: application record too large")
	}
	seq := p.next[r.epoch]
	if seq >= 1<<48 {
		return nil, errors.New("dtls sequence exhausted")
	}
	p.next[r.epoch]++
	b := record(r.kind, r.epoch, seq, r.data)
	if r.epoch == 1 {
		encrypted, err := seal(p.writeKey, p.writeMAC, b, r.data)
		if err != nil {
			return nil, err
		}
		b = record(r.kind, r.epoch, seq, encrypted)
	}
	return b, nil
}
func (p *peer) sendFlight() ([][]byte, error) {
	var out [][]byte
	for _, r := range p.flight {
		b, err := p.encode(r)
		if err != nil {
			return nil, err
		}
		out = append(out, b)
	}
	return out, nil
}
func (p *peer) acceptSeq(seq uint64) bool {
	if !p.seen {
		p.top = seq
		p.window = 1
		p.seen = true
		return true
	}
	if seq > p.top {
		diff := seq - p.top
		if diff >= 64 {
			p.window = 0
		} else {
			p.window <<= diff
		}
		p.window |= 1
		p.top = seq
		return true
	}
	diff := p.top - seq
	if diff >= 64 || p.window&(1<<diff) != 0 {
		return false
	}
	p.window |= 1 << diff
	return true
}

// Handle consumes one datagram WITHOUT the CAPWAP 4-byte DTLS preamble.
// It returns handshake response datagrams and authenticated application packets.
// Cookie verification happens before allocation; peers and record sizes are bounded.
func (s *Server) Handle(addr string, datagram []byte) (responses, packets [][]byte, err error) {
	s.mu.Lock()
	defer s.mu.Unlock()
	for len(datagram) > 0 {
		if len(datagram) < 13 {
			return responses, packets, ErrRecord
		}
		header := datagram[:13]
		n := int(binary.BigEndian.Uint16(header[11:]))
		if n > 18432 || n > len(datagram)-13 || header[1] != 0xfe || header[2] != 0xff {
			return responses, packets, ErrRecord
		}
		body := datagram[13 : 13+n]
		datagram = datagram[13+n:]
		epoch := binary.BigEndian.Uint16(header[3:])
		var seq uint64
		for _, b := range header[5:11] {
			seq = seq<<8 | uint64(b)
		}
		p := s.peers[addr]
		if epoch == 1 {
			if p == nil || len(p.master) == 0 || !p.cipherChanged {
				continue
			}
			body, err = open(p.readKey, p.readMAC, header, body)
			if err != nil {
				return responses, packets, err
			}
			if header[0] == 23 {
				if p.established && p.acceptSeq(seq) {
					p.last = time.Now()
					packets = append(packets, body)
				}
				continue
			}
		} else if epoch != 0 {
			continue
		}
		switch header[0] {
		case 21:
			if p != nil && epoch == 1 {
				delete(s.peers, addr)
			}
		case 20:
			if p != nil && epoch == 0 && len(p.master) > 0 && bytes.Equal(body, []byte{1}) {
				p.cipherChanged = true
			}
		case 22:
			for len(body) > 0 {
				if len(body) < 12 {
					return responses, packets, ErrRecord
				}
				size, offset, fragment := u24(body[1:]), u24(body[6:]), u24(body[9:])
				if size > 65536 || fragment > len(body)-12 || offset != 0 || fragment != size {
					return responses, packets, ErrRecord
				}
				msg := body[:12+fragment]
				body = body[12+fragment:]
				kind := msg[0]
				msgSeq := binary.BigEndian.Uint16(msg[4:])
				data := msg[12:]
				if kind == 1 && epoch == 0 {
					if len(data) < 38 || data[0] != 0xfe || data[1] != 0xff {
						return responses, packets, errors.New("dtls: AP requires unsupported protocol")
					}
					random := data[2:34]
					i := 35 + int(data[34])
					if i >= len(data) {
						return responses, packets, ErrRecord
					}
					cl := int(data[i])
					i++
					if i+cl+2 > len(data) {
						return responses, packets, ErrRecord
					}
					cookie := data[i : i+cl]
					i += cl
					wanted := s.makeCookie(addr, random)
					if !hmac.Equal(cookie, wanted) {
						hello := handshake(3, 0, append([]byte{0xfe, 0xff, byte(len(wanted))}, wanted...))
						responses = append(responses, record(22, 0, 0, hello))
						continue
					}
					suites := int(binary.BigEndian.Uint16(data[i:]))
					i += 2
					if suites%2 != 0 || i+suites >= len(data) {
						return responses, packets, ErrRecord
					}
					keyLen := 0
					suite := uint16(0)
					renegotiation := false
					for j := i; j < i+suites; j += 2 {
						v := binary.BigEndian.Uint16(data[j:])
						if v == 0x00ff {
							renegotiation = true
						}
						if v == 0x35 {
							suite = v
							keyLen = 32
						}
						if v == 0x2f && keyLen != 32 {
							suite = v
							keyLen = 16
						}
					}
					compression := i + suites
					compressionLen := int(data[compression])
					if compression+1+compressionLen > len(data) || compressionLen == 0 {
						return responses, packets, ErrRecord
					}
					nullCompression := false
					for _, v := range data[compression+1 : compression+1+compressionLen] {
						nullCompression = nullCompression || v == 0
					}
					if !nullCompression {
						return responses, packets, ErrRecord
					}
					extOffset := compression + 1 + compressionLen
					if extOffset < len(data) {
						if extOffset+2 > len(data) {
							return responses, packets, ErrRecord
						}
						end := extOffset + 2 + int(binary.BigEndian.Uint16(data[extOffset:]))
						if end != len(data) {
							return responses, packets, ErrRecord
						}
						for j := extOffset + 2; j < end; {
							if j+4 > end {
								return responses, packets, ErrRecord
							}
							typ := binary.BigEndian.Uint16(data[j:])
							size := int(binary.BigEndian.Uint16(data[j+2:]))
							j += 4
							if j+size > end {
								return responses, packets, ErrRecord
							}
							if typ == 0xff01 {
								if size != 1 || data[j] != 0 {
									return responses, packets, errors.New("dtls: renegotiation unsupported")
								}
								renegotiation = true
							}
							j += size
						}
					}
					if keyLen == 0 {
						return responses, packets, errors.New("dtls: no RSA AES-CBC suite")
					}
					if p != nil && bytes.Equal(random, p.random) {
						flight, e := p.sendFlight()
						responses = append(responses, flight...)
						if e != nil {
							return responses, packets, e
						}
						continue
					}
					for name, x := range s.peers {
						if !x.established && time.Since(x.last) > time.Minute {
							delete(s.peers, name)
						}
					}
					if s.MaxPeers > 0 && len(s.peers) >= s.MaxPeers && p == nil {
						return responses, packets, errors.New("dtls: peer limit")
					}
					p = &peer{random: append([]byte{}, random...), serverRandom: make([]byte, 32), readKey: make([]byte, keyLen), expected: msgSeq + 1, last: time.Now()}
					s.peers[addr] = p
					p.next[0] = 1
					if _, err = rand.Read(p.serverRandom); err != nil {
						return responses, packets, err
					}
					binary.BigEndian.PutUint32(p.serverRandom, uint32(time.Now().Unix()))
					hello := append([]byte{0xfe, 0xff}, p.serverRandom...)
					hello = append(hello, 0, byte(suite>>8), byte(suite), 0)
					if renegotiation {
						hello = append(hello, 0, 5, 0xff, 1, 0, 1, 0)
					}
					var chain []byte
					for _, cert := range s.cert.Certificate {
						entry := make([]byte, 3)
						put24(entry, len(cert))
						chain = append(chain, entry...)
						chain = append(chain, cert...)
					}
					certBody := make([]byte, 3)
					put24(certBody, len(chain))
					certBody = append(certBody, chain...)
					p.transcript = append([]byte{}, msg...)
					for idx, r := range []struct {
						kind byte
						body []byte
					}{{2, hello}, {11, certBody}, {14, nil}} {
						full := handshake(r.kind, uint16(idx+1), r.body)
						p.transcript = append(p.transcript, full...)
						if len(r.body) == 0 {
							p.flight = append(p.flight, flightRecord{22, 0, full})
							continue
						}
						for off := 0; off < len(r.body); off += 1000 {
							end := min(off+1000, len(r.body))
							part := append([]byte{}, full[:12]...)
							put24(part[6:], off)
							put24(part[9:], end-off)
							part = append(part, r.body[off:end]...)
							p.flight = append(p.flight, flightRecord{22, 0, part})
						}
					}
					flight, e := p.sendFlight()
					responses = append(responses, flight...)
					if e != nil {
						return responses, packets, e
					}
				} else if p != nil && kind == 16 && epoch == 0 && msgSeq == p.expected {
					if len(data) < 2 || int(binary.BigEndian.Uint16(data)) != len(data)-2 {
						return responses, packets, ErrRecord
					}
					premaster := make([]byte, 48)
					if _, err = rand.Read(premaster); err != nil {
						return responses, packets, err
					}
					// Random fallback and the session-key API prevent a PKCS#1 oracle.
					if e := rsa.DecryptPKCS1v15SessionKey(rand.Reader, s.key, data[2:], premaster); e != nil {
						return responses, packets, ErrRecord
					}
					p.master = prf(premaster, "master secret", append(append([]byte{}, p.random...), p.serverRandom...), 48)
					block := prf(p.master, "key expansion", append(append([]byte{}, p.serverRandom...), p.random...), 40+2*len(p.readKey))
					p.readMAC = append([]byte{}, block[:20]...)
					p.writeMAC = append([]byte{}, block[20:40]...)
					copy(p.readKey, block[40:40+len(p.readKey)])
					p.writeKey = append([]byte{}, block[40+len(p.readKey):]...)
					p.transcript = append(p.transcript, msg...)
					p.expected++
				} else if p != nil && kind == 20 && epoch == 1 {
					if p.established {
						flight, e := p.sendFlight()
						responses = append(responses, flight...)
						if e != nil {
							return responses, packets, e
						}
						continue
					}
					if msgSeq != p.expected || !hmac.Equal(data, finished(p.master, "client finished", p.transcript)) {
						return responses, packets, errors.New("dtls: Finished authentication failed")
					}
					p.transcript = append(p.transcript, msg...)
					p.flight = []flightRecord{{20, 0, []byte{1}}, {22, 1, handshake(20, 4, finished(p.master, "server finished", p.transcript))}}
					flight, e := p.sendFlight()
					responses = append(responses, flight...)
					if e != nil {
						return responses, packets, e
					}
					p.established = true
					p.last = time.Now()
					p.acceptSeq(seq)
				}
			}
		}
	}
	return responses, packets, nil
}
func (s *Server) Established(addr string) bool {
	s.mu.Lock()
	defer s.mu.Unlock()
	p := s.peers[addr]
	return p != nil && p.established
}

// Close sends an authenticated close_notify before discarding a peer. This
// lets an AP leave the old session when the controller exits normally.
func (s *Server) Close(addr string) ([]byte, error) {
	s.mu.Lock()
	defer s.mu.Unlock()
	p := s.peers[addr]
	if p == nil || !p.established {
		return nil, nil
	}
	b, err := p.encode(flightRecord{21, 1, []byte{1, 0}})
	delete(s.peers, addr)
	return b, err
}
func (s *Server) Generation(addr string) (out [32]byte) {
	s.mu.Lock()
	defer s.mu.Unlock()
	if p := s.peers[addr]; p != nil {
		copy(out[:], p.serverRandom)
	}
	return
}
func (s *Server) Encrypt(addr string, plain []byte) ([]byte, error) {
	return s.encrypt(addr, nil, plain)
}

// EncryptGeneration checks the connection and encrypts under the same lock.
// An address may already belong to a new handshake when an old request retries.
func (s *Server) EncryptGeneration(addr string, generation [32]byte, plain []byte) ([]byte, error) {
	return s.encrypt(addr, &generation, plain)
}

func (s *Server) encrypt(addr string, generation *[32]byte, plain []byte) ([]byte, error) {
	s.mu.Lock()
	defer s.mu.Unlock()
	p := s.peers[addr]
	if p == nil || !p.established {
		return nil, fmt.Errorf("dtls: peer %s not established", addr)
	}
	if generation != nil && string(p.serverRandom) != string(generation[:]) {
		return nil, fmt.Errorf("dtls: peer generation changed")
	}
	return p.encode(flightRecord{23, 1, plain})
}
func (s *Server) Remove(addr string) { s.mu.Lock(); delete(s.peers, addr); s.mu.Unlock() }
