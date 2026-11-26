package admin

import (
	"encoding/json"
	"fmt"
)

type modelUnavailable struct{ code int }

func (e modelUnavailable) Error() string { return fmt.Sprintf("AP model error %d", e.code) }

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
		return modelUnavailable{*result.Error}
	}
	return nil
}
