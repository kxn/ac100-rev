// Command acd — the Go reimplementation of the TL-AC100 `uac` CAPWAP daemon.
//
// It loads every firmware-embedded dependency from data/ files:
//
//	identity.json — AC identity (vendor fixture values)
//	apdb.json     — AP capability DB (decrypted /etc/apdb.bin)
//	controller.json — standalone configuration and resource budgets
//
// Usage: acd [-data DIR] [-port 5246] [-iface IP] [-debug]
package main

import (
	"context"
	"encoding/hex"
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"net"
	"net/http"
	"os"
	"os/signal"
	"path/filepath"
	"strconv"
	"sync"
	"syscall"
	"time"
	_ "time/tzdata"
	"uacgo/admin"
	"uacgo/controllercfg"
	"uacgo/dhcpserver"
	"uacgo/internal/eventlog"
	"uacgo/ouidb"

	"uacgo/capwap"
	"uacgo/cweng"
	"uacgo/store"
)

var listenAddr string

func main() {
	dataDir := flag.String("data", "data", "data directory (identity.json, apdb.json, controller.json)")
	port := flag.Int("port", 5246, "UDP control port")
	listen := flag.String("iface", "", "listen address (default all)")
	debug := flag.Bool("debug", false, "verbose engine logs")
	interfaceName := flag.String("interface", "", "bind control traffic to this network interface (broadcast supported)")
	dtlsCert := flag.String("dtls-cert", "", "RSA certificate for the AP DTLS 1.0 compatibility transport")
	dtlsKey := flag.String("dtls-key", "", "matching RSA key")
	eventPath := flag.String("event-log", "", "private structured decision and command log (JSONL)")
	logMax := flag.Int("log-max-mib", 32, "maximum size of each diagnostic log segment")
	logBackups := flag.Int("log-backups", 4, "rotated diagnostic log segments to retain")
	tracePath := flag.String("trace", "", "write private wire and decrypted CAPWAP trace JSONL")
	httpAddress := flag.String("http", "127.0.0.1:8090", "management HTTP listen address")
	httpAllowRemote := flag.Bool("http-allow-remote", false, "explicitly allow management HTTP on a non-loopback address (trusted management networks only)")
	dhcpConfig := flag.String("ap-dhcp", "", "AP DHCP seed JSON; web saves to data/ap-dhcp.json; off forbids this service")
	flag.Parse()
	if *port < 1 || *port > 65535 {
		log.Fatal("port must be between 1 and 65535")
	}
	ctx, cancel := signal.NotifyContext(context.Background(), os.Interrupt, syscall.SIGTERM)
	defer cancel()
	var events *eventlog.Log
	if *eventPath != "" {
		var err error
		events, err = eventlog.Open(*eventPath, int64(*logMax)<<20, *logBackups)
		if err != nil {
			log.Fatal(err)
		}
		defer events.Close()
		events.Event("controller.start", "data_dir", *dataDir, "http", *httpAddress, "control_port", *port)
	}
	if *interfaceName == "" {
		var saved struct {
			Interface string `json:"interface"`
		}
		if b, err := os.ReadFile(*dataDir + "/controller.json"); err == nil && json.Unmarshal(b, &saved) == nil {
			*interfaceName = saved.Interface
		}
	}
	if *debug {
		os.Setenv("UACGO_DEBUG", "1")
	}

	id, err := cweng.LoadIdentity(*dataDir + "/identity.json")
	if err != nil {
		log.Fatalf("load identity: %v", err)
	}
	apdb, err := cweng.LoadAPDB(*dataDir + "/apdb.json")
	if err != nil {
		log.Fatalf("load apdb: %v", err)
	}
	// AP identity IDs are the only retained SQLite state in the standalone
	// daemon. WLAN/RF configuration has one authority: admin/controller.json.
	// Do not attach the prototype's separate Wserv/Rdmngr DB readers or JCS
	// writers; otherwise old tables can push different settings during Join.
	apStore, err := store.Open(filepath.Join(*dataDir, "dbs", "apmngr.db"), store.SchemaApentrycfgTable, store.SchemaApentryrunTable)
	if err != nil {
		log.Fatalf("open config dbs: %v", err)
	}
	defer apStore.Close()

	e, err := cweng.NewEngine(uint16(*port))
	if err != nil {
		log.Fatalf("listen udp %d: %v", *port, err)
	}
	e.Events = events
	e.Debug = *debug
	if *tracePath != "" {
		f, err := eventlog.OpenWriter(*tracePath, int64(*logMax)<<20, *logBackups)
		if err != nil {
			log.Fatal(err)
		}
		defer f.Close()
		var traceMu sync.Mutex
		e.Trace(func(direction string, data []byte) {
			b, _ := json.Marshal(map[string]any{"time": time.Now().UTC(), "direction": direction, "hex": hex.EncodeToString(data)})
			traceMu.Lock()
			defer traceMu.Unlock()
			_, _ = f.Write(append(b, '\n'))
		})
	}
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
	if *interfaceName != "" && *listen == "" {
		if nic, err := net.InterfaceByName(*interfaceName); err == nil {
			addrs, _ := nic.Addrs()
			for _, a := range addrs {
				ip, _, _ := net.ParseCIDR(a.String())
				if p := ip.To4(); p != nil {
					copy(e.ControlIP[:], p)
					listenAddr = ip.String()
					break
				}
			}
		}
	}
	if *interfaceName != "" {
		if err := e.BindInterface(*interfaceName); err != nil {
			log.Fatal(err)
		}
	}
	if *dtlsCert != "" || *dtlsKey != "" {
		if err := e.EnableLegacyDTLS(*dtlsCert, *dtlsKey); err != nil {
			log.Fatal(err)
		}
	}
	e.UseAPDB(apdb)
	e.RegisterAttachHandlers(fileIdentity{id: id, port: uint16(*port), engine: e})
	e.RegisterV6Compatibility()
	e.UseStore(&cweng.SQLiteAPStore{Cfg: apStore.DB(), Run: apStore.DB()})
	// Preload the offline IEEE registry before the first client association.
	registry := ouidb.Default()
	events.Event("terminal.registry_loaded", "assignments", registry.Count(), "sources", registry.Sources())
	clients := cweng.NewClientTable()
	e.RegisterWstaHandlers(clients)
	e.RegisterObservationHandlers()
	e.RegisterRPCHandlers()
	e.RegisterTelemetryHandlers()
	manager, err := admin.New(e, clients, *dataDir)
	if err != nil {
		log.Fatal(err)
	}
	var dhcp *dhcpserver.Runtime
	if *dhcpConfig != "off" {
		dhcp, err = dhcpserver.NewRuntimeFrom(ctx, filepath.Join(*dataDir, "ap-dhcp.json"), *dhcpConfig, e.BoundInterface(), events)
		if err != nil {
			log.Fatalf("AP-only DHCP: %v", err)
		}
		manager.SetDHCPRuntime(dhcp)
	}
	go manager.Run(ctx)
	go func() { <-ctx.Done(); _ = e.Close() }()
	if *httpAddress != "" {
		if err := validateHTTPBind(*httpAddress, *httpAllowRemote); err != nil {
			log.Fatal(err)
		}
		server := &http.Server{Addr: *httpAddress, Handler: manager.HandlerWithOptions(admin.HTTPOptions{AllowRemote: *httpAllowRemote}), ReadHeaderTimeout: 5 * time.Second}
		listener, err := net.Listen("tcp", *httpAddress)
		if err != nil {
			log.Fatalf("management HTTP: %v", err)
		}
		defer server.Close()
		go func() {
			log.Printf("management UI: http://%s", *httpAddress)
			if err := server.Serve(listener); err != nil && err != http.ErrServerClosed {
				log.Printf("management HTTP: %v", err)
			}
		}()
	}
	log.Printf("acd (uac-go) listening on :%d, max_sessions=%d, ac=%s, apdb=%s (%d static, %d negotiated models)",
		*port, e.MaxAPSessions(), id.ACName, apdb.Version, len(apdb.Models()), len(apdb.Negotiated))
	events.Event("controller.ready", "control_ip", net.IP(e.ControlIP[:]).String(), "interface", e.BoundInterface(), "http", *httpAddress, "dhcp", dhcp != nil && dhcp.Status().Running)
	if err := e.Run(); err != nil && ctx.Err() == nil {
		log.Fatalf("engine: %v", err)
	}
}

// Host defaults remain local. Container deployments explicitly opt into a
// reachable management address rather than adding a second HTTP proxy.
func validateHTTPBind(address string, allowRemote bool) error {
	host, _, err := net.SplitHostPort(address)
	if err != nil {
		return err
	}
	if !allowRemote && !net.ParseIP(host).IsLoopback() {
		return fmt.Errorf("management HTTP requires a loopback address; use --http-allow-remote to expose it")
	}
	return nil
}

// fileIdentity adapts identity.json to the engine's IdentityProvider.
type fileIdentity struct {
	id     *cweng.Identity
	port   uint16
	engine *cweng.Engine
}

func (f fileIdentity) ACDescriptor() capwap.ACDescriptor {
	limit := controllercfg.Defaults().MaxAPSessions
	if f.engine != nil {
		limit = f.engine.MaxAPSessions()
	}
	vendor := uint32(0x12345678)
	if v, err := strconv.ParseUint(f.id.VendorIDHex, 0, 32); err == nil {
		vendor = uint32(v)
	}
	return capwap.ACDescriptor{
		Stations: 0, StationLim: 65535, ActiveStas: 0, ActiveLim: uint16(limit),
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
	port := f.port
	if port == 0 {
		port = f.id.ControlPort
	}
	return ip, port
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
		ACIPv4List:    [][4]byte{f.LocalAddress()},
	}
}

func (f fileIdentity) Envelope(mt uint32) [][]byte { return nil }
