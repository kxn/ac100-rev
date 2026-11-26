package capwap

import (
	"bytes"
	"fmt"
	"sync"
	"time"
)

type fragmentSet struct {
	header  []byte
	chunks  map[int][]byte
	end     int
	created time.Time
}
type Reassembler struct {
	mu   sync.Mutex
	sets map[string]*fragmentSet
}

// Push reassembles CAPWAP fragments after transport authentication. APs use
// 1400-byte chunks for JSON/configuration and larger station reports. Bound
// both memory and lifetime, and reject conflicting overlapping fragments.
func (r *Reassembler) Push(peer string, b []byte) ([]byte, error) {
	h, n, err := ParseHeader(b)
	if err != nil {
		return nil, err
	}
	if h.F == 0 {
		if h.FragOff != 0 {
			return nil, ErrBadFlags
		}
		return b, nil
	}
	body := b[n:]
	off := int(h.FragOff) * 8
	if len(body) == 0 || off+len(body) > 65535 || (h.L == 0 && len(body)%8 != 0) {
		return nil, ErrLenMismatch
	}
	r.mu.Lock()
	defer r.mu.Unlock()
	if r.sets == nil {
		r.sets = map[string]*fragmentSet{}
	}
	now := time.Now()
	for k, s := range r.sets {
		if now.Sub(s.created) > 5*time.Second {
			delete(r.sets, k)
		}
	}
	key := fmt.Sprintf("%s/%d", peer, h.FragID)
	s := r.sets[key]
	header := append([]byte{}, b[:n]...)
	header[3] &= ^byte(0xc0)
	for i := 4; i < 8; i++ {
		header[i] = 0
	}
	if s == nil {
		if len(r.sets) >= 128 {
			return nil, fmt.Errorf("CAPWAP fragment capacity")
		}
		s = &fragmentSet{header: header, chunks: map[int][]byte{}, end: -1, created: now}
		r.sets[key] = s
	} else if !bytes.Equal(s.header, header) {
		delete(r.sets, key)
		return nil, ErrBadFlags
	}
	end := off + len(body)
	if s.end >= 0 && end > s.end {
		delete(r.sets, key)
		return nil, ErrLenMismatch
	}
	for at, v := range s.chunks {
		if at == off && bytes.Equal(v, body) {
			if h.L == 0 || s.end == end {
				return nil, nil
			}
		}
		if off < at+len(v) && at < end {
			delete(r.sets, key)
			return nil, fmt.Errorf("overlapping CAPWAP fragments")
		}
	}
	if h.L != 0 {
		if s.end >= 0 && s.end != end {
			delete(r.sets, key)
			return nil, ErrLenMismatch
		}
		for at, v := range s.chunks {
			if at+len(v) > end {
				delete(r.sets, key)
				return nil, ErrLenMismatch
			}
		}
		s.end = end
	}
	s.chunks[off] = append([]byte{}, body...)
	if len(s.chunks) > 128 {
		delete(r.sets, key)
		return nil, ErrLenMismatch
	}
	if s.end < 0 {
		return nil, nil
	}
	for at := 0; at < s.end; {
		v, ok := s.chunks[at]
		if !ok {
			return nil, nil
		}
		at += len(v)
	}
	out := append([]byte{}, s.header...)
	for at := 0; at < s.end; {
		v := s.chunks[at]
		out = append(out, v...)
		at += len(v)
	}
	delete(r.sets, key)
	return out, nil
}
