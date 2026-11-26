package controllercfg

import (
	"encoding/json"
	"testing"
)

func TestResourceDefaultsAndExplicitInvalidValues(t *testing.T) {
	var r Resources
	if err := json.Unmarshal([]byte(`{"max_ap_sessions":2048}`), &r); err != nil {
		t.Fatal(err)
	}
	if r.MaxAPSessions != 2048 || r.MaxServices != Defaults().MaxServices || r.Validate() != nil {
		t.Fatal(r)
	}
	for _, body := range []string{`{"max_ap_sessions":0}`, `{"command_queue_depth":-1}`} {
		if err := json.Unmarshal([]byte(body), &r); err == nil && r.Validate() == nil {
			t.Fatal("invalid explicit limit accepted", body)
		}
	}
	if json.Unmarshal([]byte(`{"invented":1}`), &r) == nil {
		t.Fatal("unknown resource field accepted")
	}
	r = Defaults()
	r.MaxServices = 4096
	patched, err := r.Patch([]byte(`{"max_ap_sessions":512}`))
	if err != nil || patched.MaxServices != 4096 || patched.MaxAPSessions != 512 {
		t.Fatal("partial edit reset another setting", r, err)
	}
}
