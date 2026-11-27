package admin

import (
	"encoding/json"
	"reflect"
	"testing"
)

// Independent reference for the previous JSON-overlay semantics, including
// omitempty, explicit false/zero, and atomic nested replacements.
func jsonOverlayReference[T any](base, over T) T {
	a, _ := json.Marshal(base)
	b, _ := json.Marshal(over)
	var x, y map[string]json.RawMessage
	_ = json.Unmarshal(a, &x)
	_ = json.Unmarshal(b, &y)
	for k, v := range y {
		x[k] = v
	}
	a, _ = json.Marshal(x)
	var out T
	_ = json.Unmarshal(a, &out)
	return out
}

// Cover every model field, including fields introduced after this test.
func fillResourceValue(v reflect.Value, n int) {
	switch v.Kind() {
	case reflect.Pointer:
		v.Set(reflect.New(v.Type().Elem()))
		fillResourceValue(v.Elem(), n)
	case reflect.Struct:
		for i := range v.NumField() {
			fillResourceValue(v.Field(i), n)
		}
	case reflect.Slice:
		v.Set(reflect.MakeSlice(v.Type(), 2, 2))
		for i := range v.Len() {
			fillResourceValue(v.Index(i), n)
		}
	case reflect.String:
		v.SetString(string(rune('a' + n)))
	case reflect.Bool:
		v.SetBool(n != 0)
	case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64:
		v.SetInt(int64(n))
	case reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64:
		v.SetUint(uint64(n))
	default:
		panic("unhandled config model: " + v.Type().String())
	}
}
func mutateResourceValue(v reflect.Value) {
	switch v.Kind() {
	case reflect.Pointer:
		if !v.IsNil() {
			mutateResourceValue(v.Elem())
		}
	case reflect.Struct:
		for i := range v.NumField() {
			mutateResourceValue(v.Field(i))
		}
	case reflect.Slice:
		for i := range v.Len() {
			mutateResourceValue(v.Index(i))
		}
	case reflect.String:
		v.SetString(v.String() + " changed")
	case reflect.Bool:
		v.SetBool(!v.Bool())
	case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64:
		v.SetInt(v.Int() + 1)
	case reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64:
		v.SetUint(v.Uint() + 1)
	}
}
func jsonValue(v any) any {
	b, _ := json.Marshal(v)
	var out any
	_ = json.Unmarshal(b, &out)
	return out
}
func TestAPOverlayPreservesEveryFieldAndOwnership(t *testing.T) {
	var base APOptions
	fillResourceValue(reflect.ValueOf(&base).Elem(), 3)
	for i := range reflect.TypeFor[APOptions]().NumField() {
		for _, n := range []int{0, 9} {
			var over APOptions
			fillResourceValue(reflect.ValueOf(&over).Elem().Field(i), n)
			beforeBase, beforeOver := jsonValue(base), jsonValue(over)
			got := mergeOptions(base, over)
			if !reflect.DeepEqual(jsonValue(got), jsonValue(jsonOverlayReference(base, over))) {
				t.Fatalf("overlay changed field %s", reflect.TypeFor[APOptions]().Field(i).Name)
			}
			mutateResourceValue(reflect.ValueOf(&got).Elem())
			if !reflect.DeepEqual(beforeBase, jsonValue(base)) || !reflect.DeepEqual(beforeOver, jsonValue(over)) {
				t.Fatal("overlay aliases input")
			}
		}
	}
	if got := mergeOptions(base, APOptions{Ports: []APPort{}, Radios: []RadioSetting{}}); !reflect.DeepEqual(jsonValue(got), jsonValue(base)) {
		t.Fatal("empty lists changed inheritance")
	}
}
func TestRadioOverlayPreservesOptionalAdvancedFields(t *testing.T) {
	var base RadioSetting
	fillResourceValue(reflect.ValueOf(&base).Elem(), 3)
	for i := range reflect.TypeFor[RadioSetting]().NumField() {
		var over RadioSetting
		fillResourceValue(reflect.ValueOf(&over).Elem().Field(i), 0)
		if over.Advanced != nil {
			over.Advanced.EDCA, over.Advanced.DCS, over.Advanced.Reject = nil, nil, nil
		}
		beforeBase, beforeOver := jsonValue(base), jsonValue(over)
		ref := over
		if ref.Advanced != nil {
			a := *ref.Advanced
			a.EDCA, a.DCS, a.Reject = base.Advanced.EDCA, base.Advanced.DCS, base.Advanced.Reject
			ref.Advanced = &a
		}
		want := jsonOverlayReference(base, ref)
		if over.Power != nil && over.PowerLevel == nil {
			want.PowerLevel = nil
		}
		if over.PowerLevel != nil && over.Power == nil {
			want.Power = nil
		}
		got := mergeRadio(base, over)
		if !reflect.DeepEqual(jsonValue(got), jsonValue(want)) {
			t.Fatalf("radio overlay changed %d", i)
		}
		mutateResourceValue(reflect.ValueOf(&got).Elem())
		if !reflect.DeepEqual(beforeBase, jsonValue(base)) || !reflect.DeepEqual(beforeOver, jsonValue(over)) {
			t.Fatal("radio overlay aliases input")
		}
	}
}
