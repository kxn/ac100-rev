package cweng

import (
	"encoding/binary"
	"fmt"
	"uacgo/capwap"
)

// Summaries deliberately omit element values: WLAN keys, PMKs and native-model
// credentials share these same envelopes with ordinary configuration fields.
func elementSummary(elements []capwap.Element) []map[string]any {
	out := make([]map[string]any, 0, len(elements))
	for _, el := range elements {
		row := map[string]any{"type": fmt.Sprintf("0x%04x", el.Type), "bytes": len(el.Value)}
		if el.Type == 0x25 && len(el.Value) >= 6 {
			row["vendor"] = binary.BigEndian.Uint32(el.Value[:4])
			row["field"] = binary.BigEndian.Uint16(el.Value[4:6])
			var private []map[string]any
			for rest := el.Value[6:]; len(rest) >= 4; {
				kind, size := binary.BigEndian.Uint16(rest[:2]), int(binary.BigEndian.Uint16(rest[2:4]))
				rest = rest[4:]
				if size > len(rest) {
					break
				}
				private = append(private, map[string]any{"type": fmt.Sprintf("0x%04x", kind), "bytes": size})
				rest = rest[size:]
			}
			row["private"] = private
		}
		out = append(out, row)
	}
	return out
}

func errorText(err error) string {
	if err == nil {
		return ""
	}
	return err.Error()
}
