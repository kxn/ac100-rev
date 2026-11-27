package admin

import (
	"time"
)

// chnl_rrm_start@4ad1d8 first invokes intelligent ACS. A successful mode1
// dispatch bypasses the SCA channel passes, independently of the configured
// RRM group/frequency/candidate-channel sets. Its business wait is
// get_acs_timeout()+6, distinct from the scan container's timeout()+1.
func (m *Manager) startHighPerformanceRRMJobLocked(j RRMJob) (RRMJob, error) {
	j.CommonChannelPhase, j.CommonChannel = true, true
	j.CollectUntil = time.Now().Add(highPerformanceTimeout(m.config.Mobility) + 5*time.Second)
	for id, ap := range m.known {
		if ap.Online {
			j.Targets[id] = ap.ConnectedAt
			for _, r := range effectiveRadioConfig(m.config, ap).Radios {
				if r.AP != id {
					continue
				}
				change := RRMChange{AP: id, Radio: r.Radio}
				if r.Channel != nil {
					change.OldChannel = *r.Channel
				}
				if r.Power != nil {
					change.OldPower = *r.Power
				}
				for _, observed := range ap.RadioStatus {
					if observed.Radio == r.Radio {
						change.OldChannel, change.OldPower = int(observed.Channel), int(observed.Power)
					}
				}
				j.Changes = append(j.Changes, change)
			}
		}
	}
	m.rrmJobs[j.ID] = j
	if err := m.saveRRMJobs(); err != nil {
		delete(m.rrmJobs, j.ID)
		return RRMJob{}, err
	}
	if err := m.startHighPerformanceACSLocked(time.Now()); err != nil {
		delete(m.rrmJobs, j.ID)
		_ = m.saveRRMJobs()
		return RRMJob{}, err
	}
	if m.highPerformance.State == "waiting" {
		j.CollectUntil = time.Time{}
		m.rrmJobs[j.ID] = j
		if err := m.saveRRMJobs(); err != nil {
			return RRMJob{}, err
		}
	}
	m.wakeRRMLocked()
	return j, nil
}

func (m *Manager) finishHighPerformanceRRMJobLocked(j RRMJob) RRMJob {
	j.State = "applying"
	j.AppliedVersion = m.config.Version
	j.AppliedSignature = wirelessConfigKey(m.config)
	// RF changes are applied during the ACS phase. Their ACKs may precede
	// the business timer; retain the original start boundary for observation.
	j.Updated = j.Started
	if m.highPerformance.State == "failed" {
		j.State, j.Error = "failed", m.highPerformance.Error
		return j
	}
	if m.highPerformance.State == "idle" {
		j.State = "completed"
		return j
	}
	if m.highPerformance.State == "collecting" {
		j.State, j.Error = "failed", "共同信道扫描等待超时"
		return j
	}
	before := j.Changes
	j.Changes = nil
	for id, connection := range j.Targets {
		ap, ok := m.known[id]
		if !ok || !ap.Online || ap.ConnectedAt != connection {
			delete(j.Targets, id)
			continue
		}
		for _, r := range effectiveRadioConfig(m.config, ap).Radios {
			if r.AP != id || r.Channel == nil {
				continue
			}
			bandwidth := 2
			if r.Advanced != nil {
				bandwidth = r.Advanced.Bandwidth
			}
			change := RRMChange{AP: id, Radio: r.Radio, Channel: *r.Channel, Bandwidth: bandwidth, Setting: r}
			if r.Power != nil {
				change.Power = *r.Power
			}
			for _, old := range before {
				if old.AP == id && old.Radio == r.Radio {
					change.OldChannel, change.OldPower = old.OldChannel, old.OldPower
					break
				}
			}
			j.Changes = append(j.Changes, change)
		}
	}
	if len(j.Targets) == 0 {
		j.State = "completed"
	}
	return j
}
