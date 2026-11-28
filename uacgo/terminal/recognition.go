// Package terminal implements the V6 wireless-client display classification.
// Recognition-based authentication and kicking are intentionally excluded.
package terminal

import (
	"net"
	"strings"
	"uacgo/ouidb"
)

type feature struct {
	text   string
	result byte
}
type Input struct {
	Type uint16
	Text string
	OUIs [][3]byte
}
type Result struct {
	Manufacturers      []ouidb.Match `json:"manufacturer_matches,omitempty"`
	ManufacturerSource string        `json:"manufacturer_source,omitempty"`
	Flags              byte          `json:"reported_flags"`
	Brand              byte          `json:"brand_code"`
	System             byte          `json:"system_code"`
	BrandSource        byte          `json:"brand_source"`
	SystemSource       byte          `json:"system_source"`
}

func New(mac [6]byte) Result {
	r := Result{Flags: 1, Brand: 255, System: 255}
	matches := ouidb.Default().Lookup(net.HardwareAddr(mac[:]))
	if len(matches) > 0 {
		r.Brand = manufacturerCode(matches)
		r.Manufacturers = matches
		r.ManufacturerSource = "client_mac"
	}
	return r
}
func (r Result) BrandName() string {
	if r.Brand < byte(len(brandNames)) {
		return brandNames[r.Brand]
	}
	return ""
}
func (r Result) SystemName() string {
	if r.System < byte(len(systemNames)) {
		return systemNames[r.System]
	}
	return ""
}

// @751d24: higher source priority wins; equal priority takes the new result.
func choose(old, oldSource, next, source byte, priority [][5]byte) (byte, byte) {
	if int(next) >= len(priority) {
		return old, oldSource
	}
	if int(old) < len(priority) && priority[next][source] < priority[old][oldSource] {
		return old, oldSource
	}
	return next, source
}
func match(text string, features []feature, userAgent bool) byte {
	value := byte(255)
	// C strstr is case sensitive, stops at NUL, and receives <=255 bytes.
	if i := strings.IndexByte(text, 0); i >= 0 {
		text = text[:i]
	}
	if len(text) > 255 {
		text = text[:255]
	}
	for _, f := range features {
		if strings.Contains(text, f.text) {
			value = f.result
			// Android is provisional so a later HarmonyOS/HMSCore can win.
			if !userAgent || f.text != "Android" {
				break
			}
		}
	}
	return value
}
func (r Result) Observe(in Input) Result {
	value, source := byte(255), byte(0)
	switch in.Type {
	case 0:
		source = 1
		for _, oui := range in.OUIs {
			matches := ouidb.Default().LookupOUI(oui)
			if len(matches) == 0 {
				continue
			}
			value = manufacturerCode(matches)
			chosen, chosenSource := choose(r.Brand, r.BrandSource, value, source, brandPriority[:])
			if chosen == value && chosenSource == source {
				r.Manufacturers = matches
				r.ManufacturerSource = "reported_oui"
			}
			break
		}
	case 1:
		source = 2
		value = match(in.Text, host_name, false)
	case 2:
		source = 3
		value = match(in.Text, class_identify, false)
	case 3:
		source = 4
		value = match(in.Text, http_ua, true)
	default:
		return r
	}
	if source < 3 {
		r.Brand, r.BrandSource = choose(r.Brand, r.BrandSource, value, source, brandPriority[:])
	} else {
		r.System, r.SystemSource = choose(r.System, r.SystemSource, value, source, systemPriority[:])
	}
	r.Flags |= 1 << source
	if r.Brand == 255 && r.Flags&7 == 7 {
		r.Brand = 0
	}
	if r.System == 255 && r.Flags&24 == 24 {
		r.System = 0
	}
	return r
}

// The firmware enum/priorities remain applicable to its known hostname brands.
// Other IEEE registrants use the generic slot without discarding their names.
func manufacturerCode(matches []ouidb.Match) byte {
	if len(matches) == 1 {
		for i, name := range brandNames {
			if strings.EqualFold(name, matches[0].Brand) {
				return byte(i)
			}
		}
	}
	return 0
}
func (r Result) ManufacturerName() string {
	if r.BrandSource <= 1 && len(r.Manufacturers) == 1 {
		m := r.Manufacturers[0]
		if m.Brand != "" {
			return m.Brand
		}
		return m.Organization
	}
	return r.BrandName()
}
func (r Result) BrandLabel() string {
	if r.BrandSource <= 1 && len(r.Manufacturers) > 0 {
		if len(r.Manufacturers) > 1 {
			return "登记机构有歧义"
		}
		m := r.Manufacturers[0]
		for _, name := range []string{m.BrandZH, m.OrganizationZH, m.Brand, m.Organization} {
			if name != "" {
				return name
			}
		}
	}
	labels := []string{"其他", "苹果", "三星", "微软", "诺基亚", "华为", "维沃", "OPPO", "小米", "荣耀"}
	if int(r.Brand) < len(labels) {
		return labels[r.Brand]
	}
	return ""
}
