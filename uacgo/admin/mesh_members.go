package admin

import (
	"fmt"
	"net"
	"reflect"
	"sort"
	"time"
)

// Membership is configuration, not an operation-log side effect. Explicit
// denials must survive backups, history compaction and replacement of an AP.
type MeshMemberPolicy struct {
	Parent  string    `json:"parent_ap_id"`
	MAC     string    `json:"mac"`
	Allowed bool      `json:"allowed"`
	At      time.Time `json:"at"`
}

func validateMeshMembers(rows []MeshMemberPolicy) error {
	if len(rows) > 65536 {
		return fmt.Errorf("Mesh 成员策略超过容量")
	}
	seen := map[string]bool{}
	for _, r := range rows {
		for _, s := range []string{r.Parent, r.MAC} {
			mac, err := net.ParseMAC(s)
			if err != nil || len(mac) != 6 || mac[0]&1 != 0 || mac.String() == "00:00:00:00:00:00" || mac.String() != s {
				return fmt.Errorf("Mesh 成员策略需规范单播 MAC")
			}
		}
		key := r.Parent + "/" + r.MAC
		if r.Parent == r.MAC || seen[key] {
			return fmt.Errorf("Mesh 成员策略重复或引用父 AP 本身")
		}
		seen[key] = true
	}
	return nil
}

func meshMembershipAction(action string) bool {
	return action == "pair" || action == "add" || action == "unpair" || action == "delete"
}
func foldMeshMembership(rows []MeshMemberPolicy, j MeshJob) []MeshMemberPolicy {
	if !meshMembershipAction(j.Action) {
		return rows
	}
	for _, mac := range j.MACs {
		next := MeshMemberPolicy{Parent: j.AP, MAC: mac, Allowed: j.Action == "pair" || j.Action == "add", At: j.Started}
		found := false
		for i, old := range rows {
			if old.Parent == next.Parent && old.MAC == next.MAC {
				if !old.At.After(next.At) {
					rows[i] = next
				}
				found = true
				break
			}
		}
		if !found {
			rows = append(rows, next)
		}
	}
	sort.Slice(rows, func(i, j int) bool {
		if rows[i].Parent == rows[j].Parent {
			return rows[i].MAC < rows[j].MAC
		}
		return rows[i].Parent < rows[j].Parent
	})
	return rows
}

// nil members is the legacy format marker. Empty [] is authoritative too:
// old history must not reintroduce a policy omitted from a restored backup.
func (m *Manager) migrateMeshMembersLocked() error {
	if m.config.Mesh == nil || m.config.Mesh.Members != nil {
		return nil
	}
	return m.saveMeshMembersLocked(m.legacyMeshMembersLocked())
}

func (m *Manager) legacyMeshMembersLocked() []MeshMemberPolicy {
	var jobs []MeshJob
	for _, j := range m.meshJobs {
		if j.State == "completed" {
			jobs = append(jobs, j)
		}
	}
	sort.Slice(jobs, func(i, j int) bool {
		if jobs[i].Started.Equal(jobs[j].Started) {
			return jobs[i].ID < jobs[j].ID
		}
		return jobs[i].Started.Before(jobs[j].Started)
	})
	rows := []MeshMemberPolicy{}
	for _, j := range jobs {
		rows = foldMeshMembership(rows, j)
	}
	return rows
}

func (m *Manager) saveMeshMembersLocked(rows []MeshMemberPolicy) error {
	if m.config.Mesh == nil {
		return fmt.Errorf("Mesh 配置已移除，未保存过期节点结果")
	}
	if err := validateMeshMembers(rows); err != nil {
		return err
	}
	if reflect.DeepEqual(m.config.Mesh.Members, rows) {
		return nil
	}
	next := m.config
	p := *next.Mesh
	p.Members = rows
	next.Mesh = &p
	next.Version++
	if err := atomicJSON(m.path, next); err != nil {
		return err
	}
	m.config = next
	return nil
}

func (m *Manager) recordMeshMembershipLocked(j MeshJob) error {
	if !meshMembershipAction(j.Action) {
		return nil
	}
	if err := m.migrateMeshMembersLocked(); err != nil {
		return err
	}
	if m.config.Mesh == nil {
		return fmt.Errorf("Mesh 配置已移除")
	}
	rows := foldMeshMembership(append([]MeshMemberPolicy{}, m.config.Mesh.Members...), j)
	return m.saveMeshMembersLocked(rows)
}

func (m *Manager) pruneMeshJobsLocked() {
	if len(m.meshJobs) < 1000 || m.config.Mesh == nil || m.config.Mesh.Members == nil {
		return
	}
	var terminal []MeshJob
	for _, j := range m.meshJobs {
		if j.State == "completed" || j.State == "acknowledged" || j.State == "stopped" || j.State == "timed_out" {
			terminal = append(terminal, j)
		}
	}
	sort.Slice(terminal, func(i, j int) bool {
		if terminal[i].Updated.Equal(terminal[j].Updated) {
			return terminal[i].ID < terminal[j].ID
		}
		return terminal[i].Updated.Before(terminal[j].Updated)
	})
	for _, j := range terminal {
		if len(m.meshJobs) <= 800 {
			break
		}
		delete(m.meshJobs, j.ID)
	}
}

func retargetMeshMembers(rows []MeshMemberPolicy, old, target string) []MeshMemberPolicy {
	// The replacing device receives the old device's intent on a conflict.
	if rows == nil {
		return nil
	}
	normal := make([]MeshMemberPolicy, 0, len(rows))
	var moved []MeshMemberPolicy
	for _, r := range rows {
		changed := r.Parent == old || r.MAC == old
		if r.Parent == old {
			r.Parent = target
		}
		if r.MAC == old {
			r.MAC = target
		}
		if r.Parent == r.MAC {
			continue
		}
		if changed {
			moved = append(moved, r)
		} else {
			normal = append(normal, r)
		}
	}
	for _, r := range moved {
		found := false
		for i, p := range normal {
			if p.Parent == r.Parent && p.MAC == r.MAC {
				normal[i] = r
				found = true
				break
			}
		}
		if !found {
			normal = append(normal, r)
		}
	}
	return normal
}
