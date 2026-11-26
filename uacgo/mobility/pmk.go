package mobility

import "time"

// PMK is controller memory, never a Web response, backup or ordinary log.
// Layout/operations: _wsta_roam_pkt_pmk_request@4e46c0 and DB4df034/4df244.
type PMK struct {
	Service string
	Key     [32]byte
	Name    [16]byte
}
type cachedPMK struct {
	PMK
	expires time.Time
}
type PMKCache struct {
	entries   map[MAC]cachedPMK
	nextSweep time.Time
}

func (c *PMKCache) Start(now time.Time) { c.nextSweep = now.Add(time.Minute) }
func (c *PMKCache) Tick(now time.Time) {
	if c.nextSweep.IsZero() {
		c.Start(now)
		return
	}
	if now.Before(c.nextSweep) {
		return
	}
	last := c.nextSweep.Add((now.Sub(c.nextSweep) / time.Minute) * time.Minute)
	for mac, e := range c.entries {
		if !e.expires.IsZero() && !e.expires.After(last) {
			delete(c.entries, mac)
		}
	}
	c.nextSweep = last.Add(time.Minute)
}
func (c *PMKCache) Inform(mac MAC, p PMK, now time.Time) {
	c.Tick(now)
	if p.Service == "" {
		return
	}
	if c.entries == nil {
		c.entries = map[MAC]cachedPMK{}
	}
	c.entries[mac] = cachedPMK{PMK: p}
}
func (c *PMKCache) Disconnect(mac MAC, now time.Time) {
	if e, ok := c.entries[mac]; ok {
		e.expires = now.Add(time.Minute)
		c.entries[mac] = e
	}
}
func (c *PMKCache) Associate(mac MAC, service string) {
	if e, ok := c.entries[mac]; ok && e.Service == service {
		e.expires = time.Time{}
		c.entries[mac] = e
	}
}

// Firmware order matters: a missing key returns1 even if the requested slot
// is unknown; only an existing key followed by an unknown service returns2.
func (c *PMKCache) Lookup(mac MAC, service string, now time.Time) (PMK, uint8) {
	c.Tick(now)
	e, ok := c.entries[mac]
	if !ok {
		return PMK{}, 1
	}
	if service == "" {
		return PMK{}, 2
	}
	if e.Service != service {
		return PMK{}, 1
	}
	return e.PMK, 0
}
