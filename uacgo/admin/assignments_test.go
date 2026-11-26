package admin

import "testing"

func TestCompactWLANStateDropsOnlyEmptyReservations(t *testing.T) {
	state := wlanState{Assignments: WLANAssignments{"a": {"removed": {}, "reserved": {1: 2}}, "empty": {}}, Owned: map[string]map[uint8]map[uint8]bool{"a": {1: {}, 2: {1: true, 2: false}}, "empty": {}}}
	compactWLANState(&state)
	if len(state.Assignments) != 1 || len(state.Assignments["a"]) != 1 || state.Assignments["a"]["reserved"][1] != 2 || len(state.Owned) != 1 || len(state.Owned["a"]) != 1 || !state.Owned["a"][2][1] || len(state.Owned["a"][2]) != 1 {
		t.Fatal(state)
	}
}
