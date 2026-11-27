// Package vendorbackup reads the AC's encrypted configuration export offline.
// It never executes archived files or installs system configuration.
package vendorbackup

import (
	"archive/tar"
	"bytes"
	"compress/gzip"
	"crypto/des"
	"crypto/md5"
	"encoding/hex"
	"fmt"
	"io"
	"path"
	"strings"
)

const MaxSize = 64 << 20

// Decode follows des_crypt: DES ECB, PKCS#7, then MD5[16] + payload.
// des_crypt accrypt_des_decrypt@401498, key@403b08; UAC@7a7fd8.
// The format key is a firmware-wide constant, not a device/account secret.
func Decode(input []byte) ([]byte, error) {
	if len(input) < 24 || len(input)%8 != 0 || len(input) > MaxSize {
		return nil, fmt.Errorf("invalid encrypted backup length")
	}
	block, _ := des.NewCipher([]byte{0x47, 0x8d, 0xa5, 0x0b, 0xf9, 0xe3, 0xd2, 0xcf})
	plain := make([]byte, len(input))
	for i := 0; i < len(input); i += 8 {
		block.Decrypt(plain[i:i+8], input[i:i+8])
	}
	padding := int(plain[len(plain)-1])
	if padding < 1 || padding > 8 || !bytes.Equal(plain[len(plain)-padding:], bytes.Repeat([]byte{byte(padding)}, padding)) {
		return nil, fmt.Errorf("invalid backup padding")
	}
	plain = plain[:len(plain)-padding]
	if len(plain) < 16 {
		return nil, fmt.Errorf("missing backup checksum")
	}
	digest := md5.Sum(plain[16:])
	if !bytes.Equal(digest[:], plain[:16]) {
		return nil, fmt.Errorf("backup MD5 mismatch")
	}
	return plain[16:], nil
}

type Archive struct {
	Product string
	UCI     map[string][]Section
	Files   map[string][]byte // non-UCI state, keyed by archive path
}

func Read(input []byte) (*Archive, error) {
	plain, err := Decode(input)
	if err != nil {
		return nil, err
	}
	outer, err := untar(plain)
	if err != nil {
		return nil, err
	}
	product, ok := suffix(outer, "/product_name_conf")
	if !ok {
		return nil, fmt.Errorf("missing AC product metadata")
	}
	inner, ok := suffix(outer, "/tmp_conf.tar.gz")
	if !ok {
		return nil, fmt.Errorf("missing configuration archive")
	}
	checksum, ok := suffix(outer, "/md5_sum_conf")
	digest := md5.Sum(inner)
	if !ok || strings.TrimSpace(string(checksum)) != hex.EncodeToString(digest[:]) {
		return nil, fmt.Errorf("configuration archive MD5 mismatch")
	}
	files, err := untar(inner)
	if err != nil {
		return nil, err
	}
	u, ok := suffix(files, "/uc_conf.tar.gz")
	if !ok {
		return nil, fmt.Errorf("missing UCI archive")
	}
	uciFiles, err := untar(u)
	if err != nil {
		return nil, err
	}
	n, ok := suffix(files, "/non_uci.tar.gz")
	if !ok {
		return nil, fmt.Errorf("missing application database archive")
	}
	nonuci, err := untar(n)
	if err != nil {
		return nil, err
	}
	// cfgSave writes one companion MD5 file for each persistent DB.
	for name, data := range nonuci {
		if !strings.Contains(name, "/dbs/") || !strings.HasSuffix(name, ".db") {
			continue
		}
		sum, exists := suffix(nonuci, "/dbs.md5/"+path.Base(name)+".md5")
		d := md5.Sum(data)
		if !exists || strings.TrimSpace(string(sum)) != hex.EncodeToString(d[:]) {
			return nil, fmt.Errorf("database checksum mismatch: %s", path.Base(name))
		}
	}
	a := &Archive{Product: strings.TrimSpace(string(product)), UCI: map[string][]Section{}, Files: nonuci}
	for name, data := range uciFiles {
		sections, err := ParseUCI(string(data))
		if err != nil {
			return nil, fmt.Errorf("UCI %s: %w", path.Base(name), err)
		}
		a.UCI[path.Base(name)] = sections
	}
	return a, nil
}

func (a *Archive) File(name string) ([]byte, bool) { return suffix(a.Files, "/"+name) }

func suffix(files map[string][]byte, end string) ([]byte, bool) {
	var found []byte
	for name, data := range files {
		if strings.HasSuffix("/"+name, end) {
			if found != nil {
				return nil, false
			}
			found = data
		}
	}
	return found, found != nil
}

func untar(data []byte) (map[string][]byte, error) {
	gz, err := gzip.NewReader(bytes.NewReader(data))
	if err != nil {
		return nil, err
	}
	defer gz.Close()
	tr := tar.NewReader(io.LimitReader(gz, MaxSize+1))
	files, total := map[string][]byte{}, int64(0)
	for {
		h, err := tr.Next()
		if err == io.EOF {
			return files, nil
		}
		if err != nil {
			return nil, err
		}
		if h.Typeflag == tar.TypeDir {
			continue
		}
		if h.Typeflag != tar.TypeReg || path.IsAbs(h.Name) || strings.Contains(h.Name, "\\") || path.Clean(h.Name) != h.Name || strings.HasPrefix(h.Name, "../") || h.Size < 0 || h.Size > MaxSize-total {
			return nil, fmt.Errorf("unsupported archive member: %s", h.Name)
		}
		if _, exists := files[h.Name]; exists {
			return nil, fmt.Errorf("duplicate archive member: %s", h.Name)
		}
		b, err := io.ReadAll(tr)
		if err != nil {
			return nil, err
		}
		total += h.Size
		files[h.Name] = b
	}
}
