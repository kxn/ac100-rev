package admin

import (
	"encoding/json"
	"errors"
	"fmt"
	"sort"
	"strings"
)

type modelError struct{ code int }

var errNativeModelUnavailable = errors.New("AP 未提供该原生模型的回读字段")

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

// A value that is absent from an AP's native model is unobserved, not off.
// Only values the AP actually returned can establish a mismatch.
func compareNativeParameters(expected, actual map[string]string) ([]string, error) {
	var missing []string
	keys := make([]string, 0, len(expected))
	for k := range expected {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	for _, k := range keys {
		v, ok := actual[k]
		if !ok {
			missing = append(missing, k)
		} else if v != expected[k] {
			return nil, fmt.Errorf("AP model readback %s=%s, requested %s", k, v, expected[k])
		}
	}
	return missing, nil
}

func nativeReadbackReason(missing []string) string {
	if len(missing) == 0 {
		return ""
	}
	sort.Strings(missing)
	return "AP 未提供以下配置的独立回读，尚未验证：" + strings.Join(missing, ", ")
}
