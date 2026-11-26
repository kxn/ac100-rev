package admin

// A failure before any AP write is blocked configuration, and must not hold
// unrelated deletions hostage (e.g. waiting for a full radio's slot to free).
type serviceApplyError struct {
	staged bool
	cause  error
}

func (e serviceApplyError) Error() string { return e.cause.Error() }
func (e serviceApplyError) Unwrap() error { return e.cause }
