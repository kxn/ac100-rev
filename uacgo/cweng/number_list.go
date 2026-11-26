package cweng

import "encoding/json"

// []uint8 defaults to Base64 in encoding/json. Device numbers are JSON arrays;
// raw binary protocol payloads continue to use ordinary []byte fields.
type NumberList []uint8

func (v NumberList) MarshalJSON() ([]byte, error) {
	out := make([]int, len(v))
	for i, n := range v {
		out[i] = int(n)
	}
	return json.Marshal(out)
}
