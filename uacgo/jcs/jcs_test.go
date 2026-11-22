package jcs

import (
	"encoding/json"
	"path/filepath"
	"testing"
	"time"
)

// Server/client over a real AF_UNIX socket: register a handler, call it,
// get the JSON response; unknown keyword errors.
func TestServerCall(t *testing.T) {
	dir := t.TempDir()
	path := filepath.Join(dir, "jcs.service.srv.uac")
	s := NewServer()
	s.Register("apmng_set.ap_list", Handler(func(req json.RawMessage) (any, error) {
		resp := map[string]any{"error_code": 0}
		return resp, nil
	}))
	serving := make(chan string)
	go func() { serving <- "up"; _ = s.Serve(path) }()
	<-serving
	time.Sleep(50 * time.Millisecond) // let Accept start

	resp, err := Call(path, "get", "apmng_set", "ap_list", nil)
	if err != nil {
		t.Fatal(err)
	}
	if indexOf(resp, "error_code") < 0 {
		t.Fatalf("response = %s", resp)
	}

	resp2, err := Call(path, "get", "nosuch", "kw", nil)
	if err != nil || indexOf(resp2, "no handler") < 0 {
		t.Fatalf("unknown keyword: %s %v", resp2, err)
	}
	s.Close()
}

func indexOf(b []byte, s string) int {
	for i := 0; i+len(s) <= len(b); i++ {
		if string(b[i:i+len(s)]) == s {
			return i
		}
	}
	return -1
}
