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
	"database/sql"
	"flag"
	"fmt"
	"log"
	"net"
	"os"
	"strconv"
	"time"

	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/jcs"
	"uacgo/store"
)

var listenAddr string

// parseMAC6 parses "aa:bb:cc:dd:ee:ff" (ApEntryCfg_table.mac column).
func parseMAC6(s string) (out [6]byte) {
	var b [6]byte
	n, err := fmt.Sscanf(s, "%02x:%02x:%02x:%02x:%02x:%02x",
		&b[0], &b[1], &b[2], &b[3], &b[4], &b[5])
	if err == nil && n == 6 {
		out = b
	}
	return out
}

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
	steerReg := cweng.NewSteerRegistry()
	// join identity (board-data sub 4 MAC) registers the session so the
	// defense hooks and 0x59 pushes can resolve entry-id → mac → session.
	e.OnAttach = func(s *cweng.Session, ap *cweng.APEntry) {
		steerReg.SetSession(ap.MAC, s)
	}
	// wsta station reports (0x34) populate both the client table and the
	// steering registry's STA rows (store-backed TriggerLookup filling).
	e.RegisterWstaHandlers(cweng.FanClientSink{clients, steerReg})
	e.RegisterStatsHandlers(steerReg, func(mac [6]byte) uint16 {
		if s := steerReg.SessionByAPMAC(mac); s != nil {
			return s.APID
		}
		return 0
	})
	// 11r fast-roaming key distribution (PMK cache, idle-expired).
	e.RegisterPmkHandlers(&cweng.PmkResponder{Store: cweng.NewPmkStore(10 * time.Minute)})
	// steering engine: 0x58 trigger → decision → 0x59 result (wsta_roam
	// centralized strategy; tables from the AC binary's estimate_snr_rate
	// tables).
	if rateTables, err := cweng.LoadEstimateRateTables(*dataDir + "/estimate-rate-tables.bin"); err != nil {
		log.Printf("steer rate tables: %v (roaming decision disabled)", err)
	} else {
		e.RegisterRoamHandlers(&cweng.SteerEngine{
			Tables: rateTables,
			Cfg:    cweng.DefaultSteerConfig(),
			Look:   steerReg,
		}, steerReg)
	}
	var modelList []any
	for _, ap := range apdb.APList {
		modelList = append(modelList, map[string]any{
			"ap_name": ap.APName, "id": ap.ID, "model_count": len(ap.Models)})
	}
	// JCS AF_UNIX server (the binary's /tmp/jcs.service.srv.uac endpoint).
	// Assembly order mirrors the vendor registrations: not-impl
	// placeholders first, replacement handlers after (batch3cfg/rt/rt2/
	// kv/deepinspect overwrite their placeholders).
	jcsSrv := jcs.NewServer()
	apmngrSt := &jcs.ApmngrStore{DB: stores.Apmngr.DB()}
	jcs.RegisterApmngrHandlers(jcsSrv, apmngrSt)
	jcs.RegisterApmngrReadHandlers(jcsSrv, stores.Apmngr.DB(), modelList)
	jcs.RegisterApmngrExtHandlers(jcsSrv, apmngrSt)
	// apmngr event setters + apdb_info get (model data from apdb.json;
	// packet hooks stay nil until the entry-id→session binding lands).
	apdbInfo := func(modelID, firmwareID string) (map[string]any, bool) {
		for _, ap := range apdb.APList {
			if strconv.FormatUint(ap.ID, 10) != modelID {
				continue
			}
			info := map[string]any{
				"model_name": ap.APName, "id": strconv.FormatUint(ap.ID, 10),
			}
			if len(ap.Models) > 0 {
				info["hardware_ver"] = ap.Models[0].HWVer
				radios := map[string]any{}
				for name, r := range ap.Models[0].Radios {
					radios[name] = map[string]any{
						"max_ssid": r.MaxSSID, "max_stations": r.MaxStations,
						"max_tx_power": r.MaxTxPower, "min_tx_power": r.MinTxPower,
						"dft_tx_power": r.DftTxPower, "dft_bw_mode": r.DftBWMode,
						"support_11ac": r.Support11Ac,
					}
				}
				info["radios"] = radios
			}
			return info, true
		}
		return nil, false
	}
	sessionForEntry := func(id int) *cweng.Session {
		var mac string
		if err := stores.Apmngr.DB().QueryRow(
			`SELECT mac FROM ApEntryCfg_table WHERE entry_id=?`, id).Scan(&mac); err != nil {
			return nil
		}
		return steerReg.SessionByAPMAC(parseMAC6(mac))
	}
	jcs.RegisterApmngrEvtHandlers(jcsSrv, stores.Apmngr.DB(), &jcs.ApmngrEvtHooks{
		OnReboot: func(ids []int) {
			for _, id := range ids {
				if s := sessionForEntry(id); s != nil {
					_ = e.SendReset(s, 1) // apmngr_pkt_reset_pkt_send code 1/2
				}
			}
		},
		OnLED: func(ids []int, on bool) {
			for _, id := range ids {
				if s := sessionForEntry(id); s != nil {
					_ = e.SendLED(s, on) // apmngr_pkt_led_pkt_send
				}
			}
		},
		OnFactoryReset: func(ids []int) {
			for _, id := range ids {
				if s := sessionForEntry(id); s != nil {
					_ = e.SendReset(s, 3) // factory reset packet
				}
			}
		},
		OnTelnet: func(ids []int, on bool) {
			for _, id := range ids {
				if s := sessionForEntry(id); s != nil {
					_ = e.SendDefendConfig(s) // telnet config push (apmngr_telnet_config_send)
				}
			}
		},
	}, apdbInfo)
	jcs.RegisterWserviceHandlers(jcsSrv, &jcs.WservStore{DB: stores.Wserv.DB()})
	jcs.RegisterRdmngrHandlers(jcsSrv, &jcs.RdmngrStore{DB: stores.Rdmngr.DB()})
	if authed, err := jcs.NewAuthedUserTable(*dataDir + "/dbs/portal.db"); err == nil {
		jcs.RegisterWportalHandlers(jcsSrv, authed)
	} else {
		log.Printf("wportal table: %v (wportal JCS disabled)", err)
	}
	sensor, err := store.Open(*dataDir+"/dbs/sensor.db",
		store.SchemaWhitelistTable,
		fmt.Sprintf(store.SchemaTable6, "testcase_tbl"))
	if err != nil {
		log.Printf("sensor.db: %v (sensor/wips JCS fall back to not-impl)", err)
	}
	var sensorDB *sql.DB
	if sensor != nil {
		sensorDB = sensor.DB()
		defer sensor.Close()
	}
	jcs.RegisterBatch3Handlers(jcsSrv, &jcs.Batch3Stores{SensorDB: sensorDB})
	jcs.RegisterSyscfgHandlers(jcsSrv, stores.Apmngr.DB())
	jcs.RegisterMeshGlobalHandler(jcsSrv, stores.Apmngr.DB())
	jcs.RegisterRRMHandlers(jcsSrv, stores.Apmngr.DB())
	jcs.RegisterLLDPHandlers(jcsSrv, stores.Apmngr.DB())
	rtState := jcs.NewRuntimeState(stores.Apmngr.DB())
	rtState.RegisterRuntimeHandlers(jcsSrv, stores.Apmngr.DB())
	rtState.RegisterMeshTriggerHandlers(jcsSrv, stores.Apmngr.DB())
	// balance admission engine: config follows ac_balance.set live
	// (usr_threshold/rssi_threshold come from UCI apmng_balance.settings —
	// profile values pending device calibration, defaults conservative).
	balanceEng := cweng.NewBalanceEngine(cweng.BalanceConfig{Mode: 1})
	syncBalance := func(c jcs.BalanceCfg) {
		balanceEng.SetConfig(cweng.BalanceConfig{
			Enable: c.Enable, Mode: 1,
			DifThreshold: uint32(c.DifThreshold), MaxFailNum: c.MaxFailNum,
		})
	}
	rtState.OnBalanceUpdate = syncBalance
	syncBalance(rtState.GetBalance())
	e.RegisterBalanceHandlers(balanceEng)
	// balance_thread_callback @0x45aaf8: 300s sweeper for the connect-wtp
	// discovery records (900s idle expiry).
	go func() {
		for range time.Tick(300 * time.Second) {
			balanceEng.Sweep()
		}
	}()
	rtTables := jcs.NewRuntimeTables(rtState)
	rtTables.RegisterRuntimeQueryHandlers(jcsSrv)
	diTables := jcs.NewDITables()
	diTables.RegisterDIQueryHandlers(jcsSrv)
	if sensorDB != nil {
		jcs.RegisterSensorTestReadHandlers(jcsSrv, sensorDB)
		jcs.RegisterSensorTestReadHandlers2(jcsSrv, sensorDB)
	}
	jcs.RegisterSensorMngtHandlers(jcsSrv, jcs.NewSensorMngt(jcs.SensorMngtHooks{}))
	jcs.RegisterWipsEventHandlers(jcsSrv, rtTables, sensorDB, nil)
	// defense subsystems: macauth admission + storm/dhcp/arp config push
	macDB := cweng.NewMacAuthDB(cweng.MacAuthBySSID)
	jcs.RegisterMacAuthHandlers(jcsSrv, macDB)
	defendPush := &jcs.DefendPush{}
	jcs.RegisterStormHandlers(jcsSrv, stores.Apmngr.DB(), defendPush)
	jcs.RegisterDefendConfigHandlers(jcsSrv, stores.Apmngr.DB(), defendPush)
	// RRM/ACS engine: 0x5d/0x9c reports feed the DCA/TPC/ACS decisions
	rrmEng := cweng.NewRRMEngine(cweng.RRMConfig{})
	e.RegisterRRMHandlers(rrmEng, func([6]byte) int { return 0 })
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
