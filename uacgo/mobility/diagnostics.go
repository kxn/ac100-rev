package mobility

import "time"

// SelectionStep observes the actual traversal, including the legacy fallback.
// It never invokes an admission callback or evaluates a decision a second time.
type SelectionStep struct {
	Phase     string    `json:"phase"`
	Reason    string    `json:"reason,omitempty"`
	Candidate Candidate `json:"candidate"`
	Rank      int       `json:"rank"`
}
type SelectionObserver func(SelectionStep)

func traceSelection(observer SelectionObserver, phase, reason string, n Candidate, rank int) {
	if observer != nil {
		observer(SelectionStep{phase, reason, n, rank})
	}
}

type BalanceDecision struct {
	Allowed        bool      `json:"allowed"`
	Reason         string    `json:"reason"`
	Source         string    `json:"source"`
	Target         string    `json:"target,omitempty"`
	FailuresBefore uint32    `json:"failures_before"`
	FailuresAfter  uint32    `json:"failures_after"`
	LastReject     time.Time `json:"last_reject"`
}
