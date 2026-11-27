package vendorbackup

import (
	"bufio"
	"fmt"
	"strings"
	"unicode"
)

type Section struct {
	Type, Name string
	Values     map[string][]string
}

func (s Section) Value(key string) string {
	if v := s.Values[key]; len(v) > 0 {
		return v[len(v)-1]
	}
	return ""
}

func ParseUCI(input string) ([]Section, error) {
	var sections []Section
	scanner := bufio.NewScanner(strings.NewReader(input))
	scanner.Buffer(make([]byte, 4096), MaxSize)
	for scanner.Scan() {
		words, err := tokens(scanner.Text())
		if err != nil {
			return nil, err
		}
		if len(words) == 0 {
			continue
		}
		switch words[0] {
		case "config":
			if len(words) < 2 || len(words) > 3 {
				return nil, fmt.Errorf("invalid config declaration")
			}
			s := Section{Type: words[1], Values: map[string][]string{}}
			if len(words) == 3 {
				s.Name = words[2]
			}
			sections = append(sections, s)
		case "option", "list":
			if len(words) != 3 || len(sections) == 0 {
				return nil, fmt.Errorf("invalid option declaration")
			}
			m := sections[len(sections)-1].Values
			if words[0] == "option" {
				m[words[1]] = []string{words[2]}
			} else {
				m[words[1]] = append(m[words[1]], words[2])
			}
		default:
			return nil, fmt.Errorf("unsupported UCI directive %q", words[0])
		}
	}
	return sections, scanner.Err()
}

// UCI quoting, not a shell: no expansion or command execution.
func tokens(line string) ([]string, error) {
	var words []string
	var b strings.Builder
	var quote rune
	inWord, escaped := false, false
	for _, r := range line {
		if escaped {
			b.WriteRune(r)
			escaped = false
			continue
		}
		if r == '\\' && quote != '\'' {
			escaped, inWord = true, true
			continue
		}
		if quote != 0 {
			if r == quote {
				quote = 0
			} else {
				b.WriteRune(r)
			}
			continue
		}
		if r == '\'' || r == '"' {
			quote, inWord = r, true
		} else if r == '#' {
			break
		} else if unicode.IsSpace(r) {
			if inWord {
				words = append(words, b.String())
				b.Reset()
				inWord = false
			}
		} else {
			b.WriteRune(r)
			inWord = true
		}
	}
	if quote != 0 || escaped {
		return nil, fmt.Errorf("unterminated UCI quote/escape")
	}
	if inWord {
		words = append(words, b.String())
	}
	return words, nil
}
