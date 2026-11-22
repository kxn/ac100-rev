// Command acd — the Go reimplementation of the TL-AC100 `uac` CAPWAP daemon.
//
// It loads every firmware-embedded dependency from data/ files:
//
//	identity.json — AC identity (vendor fixture values)
//	apdb.json     — AP capability DB (decrypted /etc/apdb.bin)
//	profile.ini   — the hard "profile" runtime config (reconstructed)
//
// Usage: acd [-data DIR] [-port 5246] [-iface IP] [-debug]
package main

import (
	"flag"
	"log"
	"net"
	"os"
	"strconv"

	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/jcs"
	"uacgo/store"
)

var listenAddr string

func main() {
	dataDir := flag.String("data", "data", "data directory (identity.json, apdb.json, profile.ini)")
	port := flag.Int("port", 5246, "UDP control port")
	listen := flag.String("iface", "", "listen address (default all)")
	debug := flag.Bool("debug", false, "verbose engine logs")
	flag.Parse()
	if *debug {
		os.Setenv("UACGO_DEBUG", "1")
	}

	id, err := cweng.LoadIdentity(*dataDir + "/identity.json")
	if err != nil {
		log.Fatalf("load identity: %v", err)
	}
	prof, err := cweng.LoadProfileINI(*dataDir + "/profile.ini")
	if err != nil {
		log.Fatalf("load profile: %v", err)
	}
	maxSess, err := cweng.ProfileInt(prof, "ac_capwap", "max_session_num")
	if err != nil {
		// The binary exits when profile reads fail (cw_ac_profile_init
		// returns -1 → "Init uac process failed, exit..."); mirror that.
		log.Fatalf("profile: %v", err)
	}
	apdb, err := cweng.LoadAPDB(*dataDir + "/apdb.json")
	if err != nil {
		log.Fatalf("load apdb: %v", err)
	}
	stores, err := store.OpenAll(*dataDir + "/dbs")
	if err != nil {
		log.Fatalf("open config dbs: %v", err)
	}
	defer stores.CloseAll()

	e, err := cweng.NewEngine(uint16(*port))
	if err != nil {
		log.Fatalf("listen udp %d: %v", *port, err)
	}
	e.MaxSessions = maxSess
	e.ACName = id.ACName
	e.ACFirmware = id.ACFirmware
	e.ControlPort = uint16(*port)
	listenAddr = *listen
	if *listen != "" {
		ip := net.ParseIP(*listen).To4()
		if ip == nil {
			log.Fatalf("bad -iface %q", *listen)
		}
		copy(e.ControlIP[:], ip)
	} else {
		e.ControlIP = cweng.ParseIPv4(id.ControlIP)
	}
	e.RegisterAttachHandlers(fileIdentity{id: id, apdb: apdb})
	e.UseStore(&cweng.SQLiteAPStore{Cfg: stores.Apmngr.DB(), Run: stores.Apmngr.DB()})
	rateDefault, err := cweng.LoadRateDefault(*dataDir + "/rate-default.bin")
	if err != nil {
		log.Printf("rate defaults: %v (SSID/radio envelopes fall back to fixture values)", err)
	}
	e.RegisterWserviceHandlers(&cweng.StoreWserviceConfig{Stores: stores, RateDefault: rateDefault})
	clients := cweng.NewClientTable()
	e.RegisterWstaHandlers(clients)
	var modelList []any
	for _, ap := range apdb.APList {
		modelList = append(modelList, map[string]any{
			"ap_name": ap.APName, "id": ap.ID, "model_count": len(ap.Models)})
	}
	// JCS AF_UNIX server (the binary's /tmp/jcs.service.srv.uac endpoint)
	jcsSrv := jcs.NewServer()
	jcs.RegisterApmngrJCS(jcsSrv, stores.Apmngr.DB(), modelList)
	svcPath := jcs.ServicePath("uac")
	go func() {
		if err := jcsSrv.Serve(svcPath); err != nil {
			log.Printf("jcs serve %s: %v", svcPath, err)
		}
	}()

	log.Printf("acd (uac-go) listening on :%d, max_sessions=%d, ac=%s, apdb=%s (%d models)",
		*port, e.MaxSessions, id.ACName, apdb.Version, len(apdb.APList))
	if err := e.Run(); err != nil {
		log.Fatalf("engine: %v", err)
	}
}

// fileIdentity adapts identity.json to the engine's IdentityProvider.
type fileIdentity struct {
	id   *cweng.Identity
	apdb *cweng.APDB
}

func (f fileIdentity) ACDescriptor() capwap.ACDescriptor {
	vendor := uint32(0x12345678)
	if v, err := strconv.ParseUint(f.id.VendorIDHex, 0, 32); err == nil {
		vendor = uint32(v)
	}
	return capwap.ACDescriptor{
		Stations: 0, StationLim: 10000, ActiveStas: 0, ActiveLim: 1000,
		Status: 2, RStatus: 2, SlaveStatus: 4,
		SubElements: []capwap.ACDescriptorSubElement{
			{Vendor: vendor, Type: 4,
				Data: capwap.PaddedString(f.id.ACName+" "+f.id.ACVersion, 64)},
			{Vendor: vendor, Type: 5,
				Data: capwap.PaddedString(f.id.ACFirmware, 64)},
		},
	}
}

func (f fileIdentity) ACName() string { return f.id.ACName }

func (f fileIdentity) ControlAddress() ([4]byte, uint16) {
	ip := cweng.ParseIPv4(f.id.ControlIP)
	if listenAddr != "" {
		if p := net.ParseIP(listenAddr); p != nil {
			copy(ip[:], p.To4())
		}
	}
	return ip, f.id.ControlPort
}

func (f fileIdentity) LocalAddress() [4]byte {
	ip, _ := f.ControlAddress()
	return ip
}

func (f fileIdentity) Radios() [][2]uint8 {
	out := make([][2]uint8, 0, len(f.id.Radios))
	for _, r := range f.id.Radios {
		out = append(out, [2]uint8{r.RadioID, r.TypeMask})
	}
	return out
}

func (f fileIdentity) CfgStatusFixed() cweng.CfgStatusFixed {
	return cweng.CfgStatusFixed{
		DiscoveryTimer: 0x14, EchoTimer: 0x14,
		DecryptPeriod: [3]byte{0x01, 0x00, 0x78},
		IdleTimeout:   3600,
		WTPFallback:   1,
		ACIPv4List:    [][4]byte{cweng.ParseIPv4(f.id.ControlIP)},
	}
}

func (f fileIdentity) Envelope(mt uint32) [][]byte { return nil }
