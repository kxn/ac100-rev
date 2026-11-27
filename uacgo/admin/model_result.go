package admin

import (
	"encoding/json"
	"errors"
	"fmt"
)

type modelError struct{ code int }

func (e modelError) Error() string { return fmt.Sprintf("AP model error %d", e.code) }

// luci/torchlight/error.lua: unsupported event/operation/instruction are
// -40104/-40105/-40106. Busy, forbidden,
// invalid arguments and missing configuration are failures, not declarations
// that the model instruction is unsupported.
func unsupportedModel(err error) bool {
	var result modelError
	return errors.As(err, &result) && (result.code == -40104 || result.code == -40105 || result.code == -40106)
}

func modelResult(b json.RawMessage) error {
	var result struct {
		Error *int `json:"error_code"`
	}
	if err := json.Unmarshal(b, &result); err != nil {
		return err
	}
	if result.Error == nil {
		return fmt.Errorf("AP model reply lacks error_code")
	}
	if *result.Error != 0 {
		return modelError{*result.Error}
	}
	return nil
}
