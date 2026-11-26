package capwap

// APWebPasswordV2 reproduces V6 apmngr_encrypt_alg_md5_v2. Despite its vendor
// name it is a substitution encoding, not an MD5 digest. This is required by
// the AP's algorithm-1 web-account command (including Bluetooth operations).
func APWebPasswordV2(password string) []byte {
	seed := []byte("RDpbLfCPsJZ7fiv")
	table := []byte("yLwVl0zKqws7LgKPRQ84Mdt708T1qQ3Ha7xv3H7NyU84p21BriUWBU43odz3iP4rBL3cD02KZciXTysVXiV8ngg6vL48rPJyAUw0HurW20xqxv9aYb4M9wK1Ae0wlro510qXeU07kV57fQMc8L6aLgMLwygtc0F10a0Dg70TOoouyFhdysuRMO51yY5ZlOZZLEal1h0t9YQW0Ko7oBwmCAHoic4HYbUyVeU3sfQ1xtXcPcf1aT303wAQhv66qzW")
	n := max(15, len(password))
	out := make([]byte, n)
	for i := range out {
		a, b := byte(0xbb), byte(0xbb)
		if i < len(password) {
			a = password[i]
		}
		if i < 15 {
			b = seed[i]
		}
		out[i] = table[int(a^b)%255]
	}
	return out
}
