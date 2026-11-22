package capwap

import "testing"

// Batch-7 standard elements: synthetic roundtrips with length validation.
func TestBatch7Roundtrips(t *testing.T) {
	tsElem := AppendACTimestamp(nil, 1700000000)
	if v, err := ParseACTimestamp(tsElem[4:]); err != nil || v != 1700000000 {
		t.Fatalf("timestamp: %v %d", err, v)
	}
	mmElem := AppendMaximumMessageLength(nil, 1500)
	if v, err := ParseMaximumMessageLength(mmElem[4:]); err != nil || v != 1500 {
		t.Fatalf("max msg len: %v %d", err, v)
	}
	b := AppendRadioOperationalState(nil, 1, 2, 3)
	if r, st, c, err := ParseRadioOperationalState(b[4:]); err != nil || r != 1 || st != 2 || c != 3 {
		t.Fatalf("radio op state: %v", err)
	}
	stElem := AppendStatisticsTimer(nil, 120)
	if v, err := ParseStatisticsTimer(stElem[4:]); err != nil || v != 120 {
		t.Fatalf("statistics timer: %v %d", err, v)
	}
	var sid [16]byte
	for i := range sid {
		sid[i] = byte(i)
	}
	sidElem := AppendSessionID(nil, sid)
	if v, err := ParseSessionID(sidElem[4:]); err != nil || v != sid {
		t.Fatalf("session id: %v", err)
	}
	var ip [16]byte
	ip[15] = 9
	ipElem := AppendCapwapLocalIPv6Address(nil, ip)
	if v, err := ParseCapwapLocalIPv6Address(ipElem[4:]); err != nil || v != ip {
		t.Fatalf("ipv6: %v", err)
	}
	// wrong lengths rejected
	if _, err := ParseACTimestamp([]byte{1}); err == nil {
		t.Fatal("timestamp len 1 must fail")
	}
	if _, err := ParseSessionID(sid[:15]); err == nil {
		t.Fatal("session id len 15 must fail")
	}
}
