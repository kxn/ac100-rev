package cweng

import (
	"encoding/binary"
	"fmt"
	"net"
	"strings"
	"time"
	"uacgo/capwap"
)

type MeshDiscovery struct {
	MAC      string `json:"mac"`
	Parent   string `json:"parent"`
	Wireless bool   `json:"wireless"`
	RSSI     int8   `json:"rssi"`
	Model    string `json:"model"`
	Hardware string `json:"hardware_version"`
}
type MeshNode struct {
	MAC      string `json:"mac"`
	Parent   string `json:"parent"`
	IPv4     string `json:"ipv4"`
	IPv6     string `json:"ipv6"`
	LED      bool   `json:"led"`
	Wireless bool   `json:"wireless"`
	Rate     uint32 `json:"rate"`
}
type MeshReport struct {
	FullTopologyAt time.Time            `json:"full_topology_at"`
	Removed        map[string]time.Time `json:"removed,omitempty"`
	ReceivedAt     time.Time            `json:"received_at"`
	DiscoveryAt    time.Time            `json:"discovery_at"`
	TopologyAt     time.Time            `json:"topology_at"`
	Discoveries    []MeshDiscovery      `json:"discoveries"`
	Nodes          []MeshNode           `json:"nodes"`
}

func meshMAC(b []byte) string { return net.HardwareAddr(b).String() }
func parseMeshDiscoveries(b []byte) ([]MeshDiscovery, error) {
	if len(b) < 2 || len(b) != 2+int(binary.BigEndian.Uint16(b))*81 {
		return nil, capwap.ErrLenMismatch
	}
	rows := []MeshDiscovery{}
	seen := map[string]bool{}
	if binary.BigEndian.Uint16(b) > 512 {
		return nil, fmt.Errorf("too many Mesh discoveries")
	}
	for b = b[2:]; len(b) > 0; b = b[81:] {
		if b[8]&1 != 0 || net.HardwareAddr(b[8:14]).String() == "00:00:00:00:00:00" {
			return nil, fmt.Errorf("invalid Mesh AP MAC")
		}
		mac := meshMAC(b[8:14])
		if seen[mac] {
			return nil, fmt.Errorf("duplicate Mesh discovery")
		}
		seen[mac] = true
		rows = append(rows, MeshDiscovery{MAC: meshMAC(b[8:14]), Parent: meshMAC(b[:6]), Wireless: b[6] == 2, RSSI: int8(b[7]), Model: strings.TrimRight(string(b[14:79]), "\x00"), Hardware: fmt.Sprintf("%d.%d", b[79], b[80])})
	}
	return rows, nil
}
func parseMeshNodes(b []byte) ([]MeshNode, error) {
	if len(b) < 2 || len(b) != 2+int(binary.BigEndian.Uint16(b))*38 || binary.BigEndian.Uint16(b) > 512 {
		return nil, capwap.ErrLenMismatch
	}
	rows := []MeshNode{}
	seen := map[string]bool{}
	for b = b[2:]; len(b) > 0; b = b[38:] {
		if b[0]&1 != 0 || meshMAC(b[:6]) == "00:00:00:00:00:00" {
			return nil, fmt.Errorf("invalid Mesh node MAC")
		}
		mac := meshMAC(b[:6])
		if seen[mac] {
			return nil, fmt.Errorf("duplicate Mesh node")
		}
		seen[mac] = true
		rows = append(rows, MeshNode{MAC: meshMAC(b[:6]), IPv4: net.IP(b[6:10]).String(), IPv6: net.IP(b[10:26]).String(), LED: b[26] != 0, Wireless: b[27] == 2, Rate: binary.BigEndian.Uint32(b[28:]), Parent: meshMAC(b[32:38])})
	}
	return rows, nil
}

// The enclosing session supplies authenticated identity. Incremental reports
// use operation0/2 add/update and operation1 remove; full lists replace state.
func updateMeshReport(old *MeshReport, b []byte) (*MeshReport, error) {
	records, err := capwap.ParseVendorList(b)
	if err != nil {
		return nil, err
	}
	out := MeshReport{Removed: map[string]time.Time{}, Discoveries: []MeshDiscovery{}, Nodes: []MeshNode{}}
	if old != nil {
		out = *old
		out.Removed = map[string]time.Time{}
		for k, v := range old.Removed {
			out.Removed[k] = v
		}
		out.Discoveries = append([]MeshDiscovery{}, old.Discoveries...)
		out.Nodes = append([]MeshNode{}, old.Nodes...)
	}
	at := time.Now()
	changed := false
	for _, r := range records {
		switch r.Type {
		case 1:
			rows, err := parseMeshDiscoveries(r.Value)
			if err != nil {
				return nil, err
			}
			out.Discoveries = rows
			out.DiscoveryAt = at
			changed = true
		case 6:
			rows, err := parseMeshNodes(r.Value)
			if err != nil {
				return nil, err
			}
			out.Nodes = rows
			out.FullTopologyAt = at
			out.Removed = map[string]time.Time{}
			out.TopologyAt = at
			changed = true
		case 7:
			if len(r.Value) < 3 || r.Value[0] > 2 {
				return nil, capwap.ErrShortPacket
			}
			rows, err := parseMeshNodes(r.Value[1:])
			if err != nil {
				return nil, err
			}
			for _, node := range rows {
				idx := -1
				for i, n := range out.Nodes {
					if n.MAC == node.MAC {
						idx = i
						break
					}
				}
				if r.Value[0] == 1 {
					if len(out.Removed) < 512 {
						out.Removed[node.MAC] = at
					}
					if idx >= 0 {
						out.Nodes = append(out.Nodes[:idx], out.Nodes[idx+1:]...)
					}
				} else if idx >= 0 {
					delete(out.Removed, node.MAC)
					out.Nodes[idx] = node
				} else {
					if len(out.Nodes) >= 512 {
						return nil, fmt.Errorf("Mesh node capacity")
					}
					delete(out.Removed, node.MAC)
					out.Nodes = append(out.Nodes, node)
				}
			}
			out.TopologyAt = at
			changed = true
		}
	}
	if changed {
		out.ReceivedAt = at
	}
	return &out, nil
}
