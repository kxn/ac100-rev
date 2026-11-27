package eventlog

import (
	"bytes"
	"encoding/json"
	"os"
	"path/filepath"
	"sync"
	"testing"
)

type memoryOutput struct{ bytes.Buffer }

func (*memoryOutput) Close() error { return nil }

type stalledOutput struct {
	memoryOutput
	entered, release chan struct{}
	once             sync.Once
}

func (w *stalledOutput) Write(b []byte) (int, error) {
	w.once.Do(func() { close(w.entered); <-w.release })
	return w.memoryOutput.Write(b)
}

func TestImmutableRecordsAndConcurrentClose(t *testing.T) {
	w := &memoryOutput{}
	l := newLog(w)
	values := map[string]int{"value": 1}
	l.Event("snapshot", "data", values)
	values["value"] = 2
	var workers sync.WaitGroup
	for i := 0; i < 8; i++ {
		workers.Add(1)
		go func() {
			defer workers.Done()
			for j := 0; j < 100; j++ {
				l.Event("concurrent")
			}
		}()
	}
	workers.Add(1)
	go func() { defer workers.Done(); l.Close() }()
	workers.Wait()
	l.Close()
	first := bytes.Split(w.Bytes(), []byte{'\n'})[0]
	var row struct {
		Data map[string]int `json:"data"`
	}
	if err := json.Unmarshal(first, &row); err != nil || row.Data["value"] != 1 {
		t.Fatalf("snapshot changed: %s %v", first, err)
	}
	for _, line := range bytes.Split(bytes.TrimSpace(w.Bytes()), []byte{'\n'}) {
		if !json.Valid(line) {
			t.Fatalf("interleaved record %s", line)
		}
	}
}

func TestBlockedDiskDoesNotBlockProducerAndReportsLoss(t *testing.T) {
	w := &stalledOutput{entered: make(chan struct{}), release: make(chan struct{})}
	l := newLog(w)
	l.Event("first")
	<-w.entered
	// This loop must complete while the writer remains blocked.
	for i := 0; i < 1000; i++ {
		l.Event("burst")
	}
	if l.Stats().Dropped == 0 {
		t.Fatal("loss hidden")
	}
	close(w.release)
	l.Close()
	if !bytes.Contains(w.Bytes(), []byte(`"event":"observer.records_dropped"`)) {
		t.Fatal("loss not recorded")
	}
}

func TestRotationKeepsCompletePrivateRecords(t *testing.T) {
	path := filepath.Join(t.TempDir(), "events.jsonl")
	w, err := OpenWriter(path, 10, 2)
	if err != nil {
		t.Fatal(err)
	}
	for _, line := range []string{"first\n", "second\n", "third\n", "fourth\n"} {
		if _, err = w.Write([]byte(line)); err != nil {
			t.Fatal(err)
		}
	}
	if err = w.Close(); err != nil {
		t.Fatal(err)
	}
	for file, want := range map[string]string{path: "fourth\n", path + ".1": "third\n", path + ".2": "second\n"} {
		b, err := os.ReadFile(file)
		if err != nil || string(b) != want {
			t.Fatalf("rotation %s %q %v", file, b, err)
		}
		st, err := os.Stat(file)
		if err != nil || st.Mode().Perm() != 0600 {
			t.Fatal("private log permissions", err)
		}
	}
}
