package admin

import "testing"

func TestReplacementMovesAllPolicyTargetsAndDeduplicates(t *testing.T) {
	p := PolicyTarget{APs: []string{"old", "new", "other"}}
	cfg := Config{EDCARules: []EDCARule{{PolicyTarget: p}}, Rates: &RatePolicy{APs: p.APs}, Mobility: &MobilityConfig{Balance: []BalanceRule{{PolicyTarget: p}}, Roaming: []RoamRule{{PolicyTarget: p}}}, Protection: &ProtectionConfig{Rules: []ProtectionRule{{PolicyTarget: p}}}, RRM: []RRMRule{{PolicyTarget: p}}}
	retargetPolicies(&cfg, "old", "new")
	for _, ids := range [][]string{cfg.Rates.APs, cfg.Mobility.Balance[0].APs, cfg.Mobility.Roaming[0].APs, cfg.Protection.Rules[0].APs, cfg.RRM[0].APs, cfg.EDCARules[0].APs} {
		if len(ids) != 2 || ids[0] != "new" || ids[1] != "other" {
			t.Fatal(ids)
		}
	}
}
