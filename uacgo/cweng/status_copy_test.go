package cweng

import (
	"encoding/json"
	"reflect"
	"testing"
)

func TestTelemetrySnapshotOwnsNestedReports(t *testing.T) {
	s := resourceSession()
	short, weak := 1, -75
	s.telemetry.VAPs[0].ShortGI, s.telemetry.VAPs[0].WeakSignal = &short, &weak
	before, _ := json.Marshal(s.telemetry)
	got := s.statusLocked().Telemetry
	encoded, _ := json.Marshal(got)
	var a, b any
	_ = json.Unmarshal(before, &a)
	_ = json.Unmarshal(encoded, &b)
	if !reflect.DeepEqual(a, b) {
		t.Fatal("snapshot changed report data")
	}
	got.Radios[0].Data["channelUsage"][1] = '9'
	got.VAPs[0].Data["txPkts"][1] = '9'
	*got.Radios[0].Channel, *got.Radios[0].MaxClients = 11, 99
	*got.VAPs[0].ShortGI, *got.VAPs[0].WeakSignal = 0, -90
	after, _ := json.Marshal(s.telemetry)
	if string(before) != string(after) {
		t.Fatal("snapshot aliases live report")
	}
}
