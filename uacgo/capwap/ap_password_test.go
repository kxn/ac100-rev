package capwap

import "testing"

func TestAPWebPasswordV2MatchesFirmwareSubstitution(t *testing.T) {
	for in, want := range map[string]string{"admin123": "WaQ7x6b09TefbwK", "test-password": "77VtUtxvyPU0wwK", "12345678901234567890": "0KcgeX92i0q0gPcQfXq7"} {
		if got := string(APWebPasswordV2(in)); got != want {
			t.Fatalf("%q encoded as %q", in, got)
		}
	}
}
