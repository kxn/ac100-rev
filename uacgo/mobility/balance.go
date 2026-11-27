// Package mobility implements the retained V6 controller policy, independently
// of HTTP handlers, transport retries and configuration reconciliation.
package mobility

import "time"

type MAC [6]byte

// Balance follows balance_db_dis_sta_check @0x004f6f54. RSSI is an AP-side
// discovery filter (private 0x3e), not a second controller admission predicate.
type Balance struct {
	Observe   func(MAC, BalanceDecision)
	stations  map[MAC]*discovery
	nextSweep time.Time
}

// Start establishes balance_thread_callback's 300-second sweep epoch.
func (b *Balance) Start(now time.Time) { b.nextSweep = now.Add(300 * time.Second) }

func (b *Balance) Tick(now time.Time) {
	if b.nextSweep.IsZero() {
		b.Start(now)
		return
	}
	if now.Before(b.nextSweep) {
		return
	}
	last := b.nextSweep.Add((now.Sub(b.nextSweep) / (300 * time.Second)) * 300 * time.Second)
	b.Expire(last)
	b.nextSweep = last.Add(300 * time.Second)
}

type discovery struct {
	probes     []probe
	failures   uint32
	lastReject time.Time
}

type probe struct {
	ap string
	at time.Time
}

type BalanceRule struct {
	Clients, Difference, MaxFailures uint32
}

type APCount struct {
	Online  bool
	Clients uint32
}

// Probe is called only for private 0x0b discoveries on an AP with an enabled
// balance rule. V6 balance_cnt_wtp_entry_update keeps at most ten APs per MAC,
// moves a refreshed AP to the tail, and expires them at 900 seconds.
func (b *Balance) Probe(mac MAC, ap string, now time.Time) {
	b.Tick(now)
	if b.stations == nil {
		b.stations = map[MAC]*discovery{}
	}
	d := b.stations[mac]
	if d == nil {
		d = &discovery{}
		b.stations[mac] = d
	}
	rows := d.probes[:0]
	for _, p := range d.probes {
		if p.ap != ap {
			rows = append(rows, p)
		}
	}
	d.probes = append(rows, probe{ap, now})
	if len(d.probes) > 10 {
		d.probes = append([]probe{}, d.probes[len(d.probes)-10:]...)
	}
}

// ForgetAP mirrors balance_cnt_wtp_clear on AP removal/disconnection. A later
// session must receive its own discovery instead of inheriting old coverage.
func (b *Balance) ForgetAP(ap string) {
	for mac, d := range b.stations {
		rows := d.probes[:0]
		for _, p := range d.probes {
			if p.ap != ap {
				rows = append(rows, p)
			}
		}
		d.probes = rows
		if len(rows) == 0 {
			delete(b.stations, mac)
		}
	}
}

func (b *Balance) Expire(now time.Time) {
	for mac, d := range b.stations {
		rows := d.probes[:0]
		for _, p := range d.probes {
			if !now.Before(p.at) && now.Sub(p.at) < 900*time.Second {
				rows = append(rows, p)
			}
		}
		d.probes = rows
		if len(rows) == 0 {
			delete(b.stations, mac)
		}
	}
}

// Admit uses a global per-station failure counter. The 60-second reset is
// measured from the last rejection, not from the first rejection in a window.
// The original check does not filter the discovery list by SSID, VLAN or rule.
func (b *Balance) Admit(mac MAC, ap string, rule BalanceRule, aps map[string]APCount, now time.Time) bool {
	b.Tick(now)
	d := b.stations[mac]
	var before uint32
	if d != nil {
		before = d.failures
	}
	finish := func(allowed bool, reason, target string) bool {
		if b.Observe != nil {
			event := BalanceDecision{Allowed: allowed, Reason: reason, Source: ap, Target: target, FailuresBefore: before}
			if d != nil {
				event.FailuresAfter = d.failures
				event.LastReject = d.lastReject
			}
			b.Observe(mac, event)
		}
		return allowed
	}
	if d == nil {
		return finish(true, "no_discovery_record", "")
	}
	if now.Before(d.lastReject) || now.Sub(d.lastReject) >= time.Minute {
		d.failures = 0
	}
	if d.failures+1 > rule.MaxFailures {
		return finish(true, "rejection_limit_exceeded", "")
	}
	source, exists := aps[ap]
	if !exists {
		return finish(false, "source_missing", "")
	}
	if source.Clients < rule.Clients {
		return finish(true, "below_client_threshold", "")
	}
	for _, p := range d.probes {
		target, ok := aps[p.ap]
		if !ok || !target.Online || p.ap == ap {
			continue
		}
		if target.Clients < source.Clients && source.Clients-target.Clients >= rule.Difference {
			d.failures++
			d.lastReject = now
			return finish(false, "less_loaded_discovered_ap", p.ap)
		}
	}
	return finish(true, "no_eligible_less_loaded_ap", "")
}
