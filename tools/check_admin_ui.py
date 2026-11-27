#!/usr/bin/env python3
"""Exercise capability-dependent admin forms using real and synthetic AP data.
Uses mocked HTTP writes so no lab AP configuration changes during UI checks.
Requires the optional local Playwright environment, not a runtime dependency.
Uses Playwright's Chromium, or AC100_CHROMIUM_PATH for an existing browser.
"""
import copy
import http.server
import json
import os
import pathlib
import threading
import urllib.request
from playwright.sync_api import sync_playwright

ROOT = pathlib.Path(__file__).resolve().parents[1]
OUT = ROOT / ".local/ac100/ui-check"
OUT.mkdir(parents=True, exist_ok=True)


def live(p):
    return json.load(urllib.request.urlopen("http://127.0.0.1:8090/api/" + p, timeout=3))


aps = live("aps")
cfg = live("config")
defaults = live("radios/defaults?ap_id=" + aps[0]["id"] + "&radio_id=1")
clients = [
    {
        "mac": "02:03:04:05:06:07",
        "ap_id": aps[0]["id"],
        "radio_id": 2,
        "wlan_id": 1,
        "ssid": "GoAC-Lab",
        "state": "connected",
        "rssi_dbm": -52,
        "ip": "192.0.2.20",
        "connected_at": "2026-11-27T11:00:00Z",
        "last_seen": "2026-11-27T17:10:00Z",
        "statistics": {
            "negotiated_mbps": 1201,
            "upstream_kbps": 128,
            "downstream_kbps": 4096,
        },
    }
]
rates = live("rates")
mobility = live("mobility")
mobility["network_mode"] = 2
rrm = live("rrm")
upgrades = {
    "images": [
        {
            "id": "synthetic-image",
            "format": "tp-container",
            "model": aps[0]["model"],
            "version": "1.2.3 Build 20250317 Rel.43192",
            "size": 4096,
            "hardware_ids": [aps[0].get("hardware_id", "fixture-hardware")],
            "firmware_id": "test-firmware",
        }
    ],
    "jobs": {},
}
storm = {
    "defaults": {
        "enabled": False,
        "rate": 64,
        "custom": False,
        "arp_proxy": {"enabled": False, "scope": 3, "to_unicast": False},
        "nd_proxy": {"enabled": False, "scope": 3, "to_unicast": False},
        "mdns_proxy": {"enabled": False, "scope": 3, "to_unicast": False},
        "protocols": [
            {"enabled": False, "scope": 3, "rate": 64} for _ in range(8)
        ],
    },
    "protocols": [
        "ARP",
        "ICMPv6 NS",
        "ICMPv6 RS",
        "DHCP",
        "DHCPv6",
        "IGMP",
        "其他广播",
        "其他组播",
    ],
}
edca_queues = [
    {"aifs": a, "cw_min": lo, "cw_max": hi, "txop": tx}
    for a, lo, hi, tx in [
        (1, 2, 3, 47),
        (1, 3, 4, 94),
        (2, 4, 6, 0),
        (3, 4, 10, 0),
        (2, 2, 3, 47),
        (2, 3, 4, 94),
        (2, 4, 10, 0),
        (3, 4, 10, 0),
    ]
]
edca = {
    "rules": [],
    "defaults": {
        "frequency_mask": 0,
        "wmm": True,
        "custom": True,
        "scene": 1,
        "configuration": {"enabled": True, "mode": 0, "queues": edca_queues},
    },
}
resources = live("controller/resources")
resource_values = resources["defaults"]
resources = {
    "settings": dict(resource_values),
    "defaults": dict(resource_values),
    "fields": resources["fields"],
}


class Handler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *a, **k):
        super().__init__(*a, directory=str(ROOT / "uacgo/admin/assets"), **k)

    def end_headers(self):
        self.send_header(
            "Content-Security-Policy",
            "default-src 'self'; img-src 'self' data:; style-src 'self'; script-src 'self'; frame-ancestors 'none'; base-uri 'none'",
        )
        super().end_headers()

    def log_message(self, *a):
        pass


server = http.server.ThreadingHTTPServer(("127.0.0.1", 0), Handler)
threading.Thread(target=server.serve_forever, daemon=True).start()

with sync_playwright() as p:
    browser = p.chromium.launch(
        headless=True, executable_path=os.environ.get("AC100_CHROMIUM_PATH")
    )
    errors = []
    console_errors = []
    writes = []
    signal_queries = []

    for full in (False, True):
        profile = copy.deepcopy(aps)
        conf = copy.deepcopy(cfg)
        rf_defaults = copy.deepcopy(defaults)
        conf["config"]["protection"] = {
            "servers": [{"id": "srv", "name": "Router", "address": "192.0.2.1"}],
            "bindings": [
                {
                    "id": "bind",
                    "name": "Client",
                    "ip": "192.0.2.2",
                    "mac": "02:03:04:05:06:07",
                    "description": "",
                }
            ],
            "rules": [],
        }
        conf["config"]["ap_defaults"]["radios"] = [
            {"radio_id": 8, "channel": 11, "advanced": {"rts": 2000}}
        ]
        conf["config"]["groups"] = [
            {"id": "floor", "name": "Floor", "options": {"echo_seconds": 30}}
        ]
        conf["config"]["templates"] = [
            {
                "id": "template",
                "name": "Model",
                "model": profile[0]["model"],
                "hardware_version": profile[0]["hardware_version"],
                "options": {},
            }
        ]
        conf["config"]["ap_profiles"] = [
            {
                "ap_id": profile[0]["id"],
                "group_id": "floor",
                "template_id": "template",
                "name": "",
                "location": "",
                "options": {},
            }
        ]
        if full:
            a = profile[0]
            a["general_capabilities"] = [4294967295] * 4
            a["features"] = {
                **a.get("features", {}),
                **{
                    k: True
                    for k in [
                        "rssi_control",
                        "channel_optimization",
                        "fragmentation",
                        "ssid_rate_limit",
                        "frame_rate_control",
                        "edca",
                        "edca_mode",
                        "wifi6_features",
                        "mlo",
                        "multicast",
                        "multicast_per_ssid",
                        "multicast_to_unicast",
                        "vlan_pool",
                        "band_steering",
                        "band_navigation",
                    ]
                },
            }
            conf["config"]["mesh"] = {
                "enabled": True,
                "auto_add": False,
                "ssid": "ExistingBackhaul",
                "members": [
                    {
                        "parent_ap_id": a["id"],
                        "mac": "02:00:00:00:00:09",
                        "allowed": False,
                        "at": "2026-11-26T12:00:00Z",
                    }
                ],
                "has_key": True,
                "has_token": True,
                "has_web_password": True,
                "backhaul_mode": 1,
            }
            a["features"]["mesh"] = True
            a["ports"] = [
                {"id": 12, "uplink": True},
                {"id": 103, "uplink": False, "lag": True},
                {"id": 104, "uplink": False, "lag": True},
            ]
            a["downlink_port_count"] = 2
            conf["config"]["ap_profiles"][0]["options"]["lag"] = {
                "enabled": True,
                "mode": 0,
                "ports": [103, 104],
            }
            a["radio_linkage"] = {
                "table_id": 1,
                "rows": [
                    {
                        "table_mask": 2,
                        "feature_mask": 1,
                        "regions": [0],
                        "radios": [
                            {
                                "radio_id": 1,
                                "channels": [0, 1, 6],
                                "bandwidths": [0, 2],
                                "status_mask": 3,
                            }
                        ],
                    }
                ],
            }
            a["radio_modes"] = [
                {"id": 7, "name": "Dual", "rf_mode": 16387, "radios": [1, 2]}
            ]
            a["radio_mode"] = {"enabled": False, "id": 7}
            rf_defaults["edca"] = {
                "enabled": False,
                "mode": 0,
                "queues": edca_queues,
            }
            for row in conf["config"]["radios"]:
                if row.get("advanced") is not None:
                    row["advanced"]["edca"] = copy.deepcopy(rf_defaults["edca"])
            a["edca_presets"] = {
                "version": 1,
                "scenes": [
                    {
                        "id": 2,
                        "name": "Office",
                        "description": "Other AP model",
                        "bands": [
                            {
                                "band_id": 1,
                                "queues": [
                                    {
                                        "aifs": 2,
                                        "cw_min": 3,
                                        "cw_max": 4,
                                        "txop": 47,
                                    }
                                ]
                                * 8,
                            }
                        ],
                    }
                ],
            }
            conf["config"]["vlan_pools"] = [
                {"id": 1, "name": "Guests", "vlans": "100-110"}
            ]

        group_service = copy.deepcopy(conf["config"]["services"][0])
        group_service.update(
            id="fixture-group-service",
            ssid="Group-only service",
            aps=[],
            groups=["floor"],
            bindings=[],
        )
        conf["config"]["services"].append(group_service)

        spare = copy.deepcopy(profile[0])
        spare.update(
            id="02:00:00:00:00:aa",
            mac="02:00:00:00:00:aa",
            name="Fixture spare",
            online=True,
            state="RUN",
        )
        offline = copy.deepcopy(spare)
        offline.update(
            id="02:00:00:00:00:ab",
            mac="02:00:00:00:00:ab",
            name="Fixture offline",
            online=False,
            state="OFFLINE",
        )
        profile.extend([spare, offline])

        reads = []
        page = browser.new_page(viewport={"width": 1440, "height": 960})
        page.on("pageerror", lambda e: errors.append(str(e)))
        page.on(
            "console",
            lambda m: console_errors.append(m.text)
            if m.type == "error"
            else None,
        )
        page.on("dialog", lambda d: d.accept())

        def route(r):
            path = r.request.url.split("/api/")[1]
            if r.request.method != "GET":
                writes.append({"path": path, "body": r.request.post_data_json})
                r.fulfill(
                    json={"updated": 1, "skipped": 0, "errors": []}
                    if path == "aps/names/import"
                    else {"status": "saved"}
                )
                return
            reads.append(path)
            if path.startswith("clients/") and "/history?" in path:
                signal_queries.append(path)
                r.fulfill(
                    json={
                        "samples": [
                            {
                                "at": "2026-11-26T12:00:00Z",
                                "ap_id": profile[0]["id"],
                                "radio_id": 1,
                                "wlan_id": 1,
                                "ssid": "GoAC-Lab",
                                "rssi_dbm": -60,
                            },
                            {
                                "at": "2026-11-26T12:00:30Z",
                                "ap_id": profile[0]["id"],
                                "radio_id": 1,
                                "wlan_id": 1,
                                "ssid": "GoAC-Lab",
                                "rssi_dbm": -48,
                            },
                        ]
                    }
                )
                return
            history_fixture = {
                "ap_counts": [
                    {
                        "at": "2026-11-26T12:00:00Z",
                        "online": 1,
                        "offline": 2,
                        "total": 3,
                    },
                    {
                        "at": "2026-11-26T12:01:00Z",
                        "online": 2,
                        "offline": 1,
                        "total": 3,
                    },
                ],
                "radios": [
                    {
                        "at": "2026-11-26T12:00:00Z",
                        "ap_id": profile[0]["id"],
                        "radio_id": 1,
                        "clients": 1,
                        "channel": 6,
                        "power_dbm": 15,
                        "metrics": {"channelUsage": 20},
                    },
                    {
                        "at": "2026-11-26T12:01:00Z",
                        "ap_id": profile[0]["id"],
                        "radio_id": 1,
                        "clients": 2,
                        "channel": 6,
                        "power_dbm": 15,
                        "metrics": {"channelUsage": 30},
                    },
                ],
                "events": [
                    {
                        "at": "2026-11-26T12:00:10Z",
                        "client_mac": "02:03:04:05:06:07",
                        "kind": "connected",
                        "ssid": "GoAC-Lab",
                        "ap_id": profile[0]["id"],
                        "radio_id": 2,
                        "source": "wireless_snapshot",
                    }
                ],
            }
            value = (
                resources
                if path == "controller/resources"
                else profile
                if path == "aps"
                else conf
                if path == "config"
                else clients
                if path == "clients"
                else [
                    row
                    for row in conf["config"]["radios"]
                    if row["ap_id"] == profile[0]["id"]
                ]
                if path.endswith("/effective-radios")
                else rf_defaults
                if path.startswith("radios/defaults")
                else rates
                if path == "rates"
                else mobility
                if path == "mobility"
                else edca
                if path == "edca"
                else rrm
                if path == "rrm"
                else upgrades
                if path == "upgrades"
                else {"config": conf["config"].get("mesh"), "jobs": {}}
                if path == "mesh"
                else {
                    "configured_mode": 2,
                    "actual_mode": 2,
                    "mode_writable": False,
                    "unsupported_aps": [],
                }
                if path == "mobility/status"
                else storm
                if path == "storm/defaults"
                else history_fixture
                if path.startswith("history?")
                else []
            )
            r.fulfill(json=value)

        page.route("**/api/**", route)
        page.goto("http://127.0.0.1:" + str(server.server_port))
        page.wait_for_function(
            '() => document.querySelector("#connection").textContent === "控制器已连接"'
        )

        def visit(view):
            family = {
                "management": "aps",
                "templates": "aps",
                "apdefaults": "aps",
                "mesh": "aps",
                "pools": "services",
                "multicast": "services",
                "rrm": "radios",
                "rates": "radios",
                "edca": "radios",
                "balance": "mobility",
                "band": "mobility",
                "resources": "interfaces",
                "backup": "interfaces",
            }.get(view, view)
            page.locator('#navigation [data-tab="' + family + '"]').click()
            if view != family:
                page.locator('#section-navigation [data-view="' + view + '"]').click()
            page.wait_for_url("**/#" + view)

        assert page.locator("#summary").is_visible()
        assert not page.locator("#menu-toggle").is_visible()
        page.locator('.kpi-card[data-view="aps"]').first.click()
        page.wait_for_url("**/#aps")
        assert page.locator('a[href="/api/aps/export"]').is_visible()
        visit("radios")
        assert page.locator('[data-radio="1"]').count() > 0
        assert (
            page.locator(
                "[data-rrm-new],[data-edca-new],[data-band-navigation]"
            ).count()
            == 0
        )
        assert not page.locator("#summary").is_visible()

        for tab in [
            "overview",
            "aps",
            "management",
            "templates",
            "apdefaults",
            "mesh",
            "services",
            "pools",
            "multicast",
            "radios",
            "rrm",
            "rates",
            "edca",
            "mobility",
            "balance",
            "band",
            "clients",
            "history",
            "protection",
            "upgrades",
            "interfaces",
            "resources",
            "backup",
        ]:
            visit(tab)
            page.wait_for_timeout(40)

        visit("services")
        group_row = page.locator("tr").filter(has_text="Group-only service")
        assert (
            "分组 Floor" in group_row.inner_text()
            and "全部 AP" not in group_row.inner_text()
        )

        visit("radios")
        page.locator('[name="radio_ap_filter"]').select_option(profile[0]["id"])
        page.locator('[name="radio_ap_filter"]').focus()
        page.evaluate("() => { window.uiFocusedControl = document.activeElement; }")
        page.wait_for_timeout(4200)
        assert page.evaluate(
            "() => document.activeElement === window.uiFocusedControl"
        )

        visit("aps")
        if full:
            page.screenshot(path=str(OUT / "aps.png"), full_page=True)
        page.locator('#content [data-ap="' + profile[0]["id"] + '"]').first.click()
        page.wait_for_selector("#drawer[open]")
        page.locator("#drawer-body details").first.locator("summary").click()
        if full:
            page.screenshot(path=str(OUT / "ap-drawer.png"), full_page=True)
        page.wait_for_timeout(4200)
        assert page.locator("#drawer-body details").first.evaluate(
            "(e)=>e.open"
        )
        page.locator("#close-drawer").click()

        visit("overview")
        page.screenshot(
            path=str(
                OUT
                / (
                    "all-capabilities-overview.png"
                    if full
                    else "real-capabilities-overview.png"
                )
            ),
            full_page=True,
        )

        visit("resources")
        page.locator('#controller-resources-form [name="max_ap_sessions"]').fill(
            "2048"
        )
        assert page.locator(
            '#controller-resources-form input[type="number"]'
        ).count() == len(resource_values)
        if full:
            page.screenshot(path=str(OUT / "resources.png"), full_page=True)
        page.locator('#controller-resources-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "controller/resources"
            and writes[-1]["body"]["max_ap_sessions"] == 2048
            and writes[-1]["body"]["max_policy_rules"] == 1024
        )

        visit("services")
        if full:
            page.screenshot(path=str(OUT / "services.png"), full_page=True)
        page.locator("#new-service").click()
        page.locator('#service-form [name="ssid"]').fill("UI-Parity")
        page.locator('#service-form [name="passphrase"]').fill(
            "synthetic-ui-key"
        )
        page.screenshot(
            path=str(
                OUT
                / (
                    "all-capabilities-service.png"
                    if full
                    else "real-capabilities-service.png"
                )
            ),
            full_page=True,
        )
        assert page.locator('#service-form [name="radius_ip"]').count() == 0
        for pane in ["binding", "qos", "schedule", "basic"]:
            page.locator(
                '#service-form [data-editor-tab="' + pane + '"]'
            ).click()
        if not full:
            assert not page.locator(
                '#service-form [name="mc_global"]'
            ).is_visible()
        else:
            page.locator('#service-form [data-editor-tab="binding"]').click()
            page.locator('#service-form [name="vlan_pool"]').select_option("1")
        page.locator('#service-form [data-editor-tab="binding"]').click()
        page.locator('#service-form [name="band_preset"]').select_option(
            "custom"
        )
        page.evaluate(
            """() => {
              document.querySelectorAll('#service-form input[name="auto_bind_frequencies"]').forEach(el => {
                el.checked = el.value === '256';
              });
              document.querySelector('#service-form input[name="auto_bind_frequencies"]').dispatchEvent(new Event('change', {bubbles: true}));
            }"""
        )
        page.locator('#service-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert not page.locator("#editor").evaluate("(e)=>e.open"), (
            page.locator("#form-error").inner_text()
        )
        assert writes[-1]["body"]["auto_bind_frequencies"] == 256

        visit("radios")
        page.locator('[data-radio="1"]').first.click()
        page.wait_for_selector("#radio-form")
        original_mode = page.locator('#radio-form [name="mode"]').input_value()
        assert page.locator('#radio-form [name="wmm"]').is_disabled()
        assert page.locator('#radio-form [name="fragmentation"]').is_disabled()
        page.locator('#radio-form [name="mode"]').select_option("1")
        assert page.locator('#radio-form [name="wmm"]').is_enabled()
        page.locator('#radio-form [data-editor-tab="rf-performance"]').click()
        page.locator('#radio-form [name="wmm"]').uncheck()
        page.locator('#radio-form [data-editor-tab="rf-basic"]').click()
        page.locator('#radio-form [name="mode"]').select_option(original_mode)
        assert (
            page.locator('#radio-form [name="wmm"]').is_disabled()
            and page.locator('#radio-form [name="wmm"]').is_checked()
        )
        for pane in ["rf-timing", "rf-performance", "rf-basic"]:
            page.locator('#radio-form [data-editor-tab="' + pane + '"]').click()
        if full:
            page.locator(
                '#radio-form [data-editor-tab="rf-performance"]'
            ).click()
            assert page.locator('#radio-form [name="dcs_mode"]').count() == 1
            assert page.locator('#radio-form [name="edca_7_txop"]').count() == 1
            page.locator('#radio-form [name="edca_preset"]').select_option("2")
        page.locator('#radio-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert not page.locator("#editor").evaluate("(e)=>e.open"), (
            page.locator("#form-error").inner_text()
        )

        visit("band")
        page.locator('[data-band-advanced] > summary').click()
        page.locator('#band-navigation-form [name="band_threshold"]').fill("22")
        page.locator('#band-navigation-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "band-navigation"
            and writes[-1]["body"]["threshold_5g"] == 22
        )

        if full:
            visit("pools")
            page.locator("[data-new-pool]").click()
            page.locator('#pool-form [name="pool_name"]').fill("UI Pool")
            page.locator('#pool-form [name="pool_vlans"]').fill("100-110")
            page.locator('#pool-form [type="submit"]').click()
            page.wait_for_timeout(80)
            assert (
                writes[-1]["path"] == "vlan-pools"
                and writes[-1]["body"]["vlans"] == "100-110"
            )

        visit("rrm")
        page.locator('#rrm-quick-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "rrm/rules"
            and writes[-1]["body"][0]["name"] == "默认射频优化"
            and writes[-1]["body"][0]["optimize_channel"] is True
            and writes[-1]["body"][0]["optimize_power"] is True
            and writes[-1]["body"][0]["5g"]["channels"]
            == [36, 40, 44, 48, 149, 153, 157, 161]
        )
        page.locator("[data-rrm-quick-run]").click()
        page.wait_for_timeout(80)
        assert (
            writes[-2]["path"] == "rrm/rules"
            and writes[-1]["path"] == "rrm/run"
        )
        page.locator("[data-rrm-advanced] > summary").click()
        page.locator("[data-rrm-new]").click()
        page.wait_for_selector("#rrm-form")
        page.locator('#rrm-form [name="strategy_version"]').select_option("v4")
        assert page.locator(
            '#rrm-form [name="rrm_5g_secondary_channels"]'
        ).is_visible()
        assert page.locator(
            '#rrm-form [name="rrm_5g_power_threshold"]'
        ).is_disabled()
        page.locator('#rrm-form [name="strategy_version"]').select_option("v6")
        assert not page.locator(
            '#rrm-form [name="rrm_5g_secondary_channels"]'
        ).is_visible()
        assert page.locator(
            '#rrm-form [name="rrm_5g_power_threshold"]'
        ).is_enabled()
        page.locator('#rrm-form [name="name"]').fill("UI RRM")
        page.locator('#rrm-form [name="rrm_5g_channels"]').fill("36,44,149,157")
        page.locator('#rrm-form [name="optimize_channel"]').check()
        page.locator('#rrm-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "rrm/rules"
            and writes[-1]["body"][0]["name"] == "UI RRM"
        )

        visit("rates")
        page.wait_for_selector("#rates-form")
        page.locator('#rates-form [data-editor-tab="rates-mcs"]').click()
        page.locator('#rates-form [name="11ax_supported"]').fill("15")
        page.locator('#rates-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "rates"
            and writes[-1]["body"]["11ax"]["supported"] == 15
        )

        visit("rrm")
        page.locator("[data-rrm-advanced] > summary").click()
        page.locator("[data-rrm-new]").click()
        page.wait_for_selector("#rrm-form")
        page.locator('#rrm-form [name="strategy_version"]').select_option("v4")
        page.locator('#rrm-form [name="name"]').fill("UI V4 RRM")
        page.locator('#rrm-form [name="rrm_5g_channels"]').fill("36,44,149,157")
        page.locator('#rrm-form [name="rrm_5g_secondary_channels"]').fill(
            "149,157"
        )
        page.locator('#rrm-form [name="optimize_channel"]').check()
        page.locator('#rrm-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "rrm/rules"
            and writes[-1]["body"][0]["strategy_version"] == "v4"
        )
        assert writes[-1]["body"][0]["5g"]["secondary_channels"] == [149, 157]
        assert (
            writes[-1]["body"][0]["5g"]["power_threshold"]
            == writes[-1]["body"][0]["2g"]["power_threshold"]
        )

        visit("edca")
        page.locator("[data-edca-new]").click()
        page.wait_for_selector("#edca-form")
        page.locator('#edca-form [name="name"]').fill("UI EDCA")
        page.locator(
            '#edca-form input[name="frequency_mask"][value="1"]'
        ).check()
        page.locator(
            '#edca-form input[name="frequency_mask"][value="256"]'
        ).check()
        page.locator('#edca-form [name="edca_0_txop"]').fill("47")
        page.locator('#edca-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "edca/rules"
            and writes[-1]["body"][0]["frequency_mask"] == 257
        )

        visit("balance")
        assert not page.locator("[data-balance-conflict]").is_visible()
        page.locator('#balance-simple-form [name="balance_enabled"]').check()
        assert page.locator("[data-balance-conflict]").is_visible()
        page.locator('#balance-simple-form [name="client_threshold"]').fill(
            "18"
        )
        page.locator('#balance-simple-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "mobility"
            and len(writes[-1]["body"]["balance"]) == 1
            and writes[-1]["body"]["balance"][0]["enabled"] is True
            and writes[-1]["body"]["balance"][0]["client_threshold"] == 18
        )
        page.locator('#balance-simple-form [name="balance_enabled"]').check()
        page.locator('#balance-simple-form [name="balance_enabled"]').uncheck()
        assert not page.locator("[data-balance-simple-options]").is_visible()
        page.locator('#balance-simple-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "mobility"
            and writes[-1]["body"]["balance"] == []
        )
        page.locator('[data-mobility-advanced="balance"] > summary').click()
        page.locator('[data-mobility-kind="balance"]').click()
        page.wait_for_selector("#mobility-form")
        page.locator('#mobility-form [name="name"]').fill("UI Balance")
        page.locator('#mobility-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "mobility"
            and writes[-1]["body"]["balance"][0]["name"] == "UI Balance"
        )

        visit("mobility")
        if full:
            page.screenshot(path=str(OUT / "mobility.png"), full_page=True)
        page.locator('#roam-simple-form [name="roam_enabled"]').check()
        page.locator(
            '#roam-simple-form [name="roam_sensitivity"]'
        ).select_option("aggressive")
        page.locator('#roam-simple-form [name="roam_11r"]').check()
        page.locator('#roam-simple-form [name="roam_rssi_kick"]').check()
        page.locator('#roam-simple-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert writes[-1]["path"] == "mobility"
        roam_def = writes[-1]["body"]["default_roaming"]
        assert (
            roam_def["2g"]["rssi_trigger"] == -70
            and roam_def["5g"]["rssi_trigger"] == -75
            and roam_def["difference"] == 6
            and roam_def["11r"] is True
            and roam_def["2g"]["rssi_kick"] is True
            and roam_def["5g"]["rssi_kick"] is True
        )
        page.locator('#roam-simple-form [name="roam_enabled"]').uncheck()
        assert not page.locator("[data-roam-simple-options]").is_visible()
        page.locator('#roam-simple-form [type="submit"]').click()
        page.wait_for_timeout(80)
        roam_off = writes[-1]["body"]["default_roaming"]
        assert (
            roam_off["11k"] is False
            and roam_off["11v"] is False
            and roam_off["11r"] is False
            and roam_off["2g"]["rssi_kick"] is False
            and roam_off["5g"]["rssi_kick"] is False
        )
        page.locator('[data-mobility-advanced="roaming"] > summary').click()
        page.locator('[data-mobility-kind="default"]').click()
        page.wait_for_selector("#mobility-form")
        page.locator('#mobility-form [name="mode_source"]').select_option(
            "tl-ac100-v4-1.4.3"
        )
        assert not page.locator(
            '#mobility-form [name="network_mode"] option[value="1"]'
        ).is_disabled()
        page.locator('#mobility-form [name="network_mode"]').select_option("1")
        page.locator('#mobility-form [name="mode_source"]').select_option(
            "tl-ac100-v6-1.0.3"
        )
        assert (
            page.locator('#mobility-form [name="network_mode"]').input_value()
            == "2"
        )
        assert page.locator(
            '#mobility-form [name="network_mode"] option[value="1"]'
        ).is_disabled()
        page.locator('#mobility-form [name="silence_count"]').fill("7")
        page.locator('#mobility-form [name="silence_seconds"]').fill("61")
        page.locator('#mobility-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "mobility"
            and writes[-1]["body"]["default_roaming"]["2g"]["rssi_trigger"]
            == -75
        )
        assert writes[-1]["body"]["silence"] == {"count": 7, "seconds": 61}
        assert writes[-1]["body"]["mode_source"] == "tl-ac100-v6-1.0.3"
        assert (
            [w for w in writes if w["path"] == "rrm/rules"][-1]["body"][0][
                "strategy_version"
            ]
            == "v4"
        )

        visit("mobility")
        if not page.locator('[data-mobility-advanced="roaming"]').evaluate(
            "(e) => e.open"
        ):
            page.locator(
                '[data-mobility-advanced="roaming"] > summary'
            ).click()
        page.locator('[data-mobility-kind="default"]').click()
        page.wait_for_selector("#mobility-form")
        assert page.locator("#dialog-body").evaluate("(e)=>e.scrollTop") == 0
        page.locator('#mobility-form [name="mode_source"]').select_option(
            "tl-ac100-v4-1.4.3"
        )
        page.screenshot(
            path=str(
                OUT
                / (
                    "v4-strategy-options-full.png"
                    if full
                    else "v4-strategy-options.png"
                )
            )
        )
        page.locator('#mobility-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "mobility"
            and writes[-1]["body"]["mode_source"] == "tl-ac100-v4-1.4.3"
        )

        visit("protection")
        if full:
            page.screenshot(path=str(OUT / "protection.png"), full_page=True)
        for ptab, kind in [
            ("servers", "servers"),
            ("bindings", "bindings"),
            ("rules", "rules"),
        ]:
            page.locator('[data-protection-tab="' + ptab + '"]').click()
            page.locator('[data-defense-kind="' + kind + '"]').last.click()
            page.wait_for_selector("#defense-form")
            page.locator('#defense-form [name="name"]').fill("UI " + kind)
            if kind == "servers":
                page.locator('#defense-form [name="address"]').fill("192.0.2.3")
            if kind == "bindings":
                page.locator('#defense-form [name="ip"]').fill("2001:db8::3")
                page.locator('#defense-form [name="mac"]').fill(
                    "02:03:04:05:06:08"
                )
            if kind == "rules":
                page.locator('#defense-form [name="dhcp"]').check()
                page.locator(
                    '#defense-form input[name="servers"][value="srv"]'
                ).check()
                page.locator(
                    '#defense-form input[name="bindings"][value="bind"]'
                ).check()
            page.locator('#defense-form [type="submit"]').click()
            page.wait_for_timeout(80)
            assert not page.locator("#editor").evaluate("(e)=>e.open"), (
                page.locator("#form-error").inner_text()
            )
            assert writes[-1]["path"] == "protection"

        page.locator('[data-protection-tab="storm"]').click()
        page.wait_for_selector("#storm-form")
        page.locator('#storm-form [name="enabled"]').check()
        page.locator('#storm-form [name="protocol_0_rate"]').fill("200")
        page.locator('#storm-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "storm"
            and writes[-1]["body"]["protocols"][0]["rate"] == 200
        )

        visit("upgrades")
        page.wait_for_selector("[data-upgrade-image]")
        page.locator("[data-upgrade-image]").first.click()
        page.wait_for_selector("#upgrade-form")
        page.locator('#upgrade-form input[type="checkbox"]').first.check()
        page.locator('#upgrade-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "upgrades"
            and writes[-1]["body"]["image_id"] == "synthetic-image"
        )

        visit("history")
        page.wait_for_selector('svg path[stroke-width="2"]')
        assert page.locator('svg[aria-label="无线运行统计趋势"]').count() == 2
        if full:
            page.screenshot(path=str(OUT / "history.png"), full_page=True)

        visit("clients")
        if full:
            page.screenshot(path=str(OUT / "clients.png"), full_page=True)
        page.locator("[data-client-history]").first.click()
        page.wait_for_selector("#dialog-body svg")
        assert page.locator("#dialog-body").get_by_text(
            "-60 dBm", exact=True
        ).is_visible()
        before_signals = len(signal_queries)
        page.locator('[name="client_history_duration"]').select_option("3600")
        page.wait_for_timeout(100)
        assert len(signal_queries) > before_signals and signal_queries[
            -1
        ].endswith("duration=3600")
        page.locator("#close-dialog").click()

        visit("mesh")
        page.locator("[data-mesh-config]").first.click()
        page.wait_for_selector("#mesh-form")
        page.locator('#mesh-form [name="enabled"]').check()
        page.locator('#mesh-form [name="ssid"]').fill("UI Backhaul")
        page.locator('#mesh-form [name="key"]').fill("MeshKey123")
        page.locator('#mesh-form [name="web_password"]').fill("Mesh123456")
        page.locator('#mesh-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "mesh"
            and writes[-1]["body"]["ssid"] == "UI Backhaul"
        )
        if full:
            page.locator("[data-mesh-ap]").first.click()
            page.wait_for_selector("#mesh-form")
            page.locator('#mesh-form [type="submit"]').click()
            page.wait_for_timeout(80)
            assert (
                writes[-1]["path"].endswith("/mesh")
                and writes[-1]["body"]["action"] == "discover"
            )

        visit("management")
        page.locator("[data-group-new]").click()
        page.locator('#management-form [name="management_name"]').fill(
            "UI Group"
        )
        page.locator('#management-form [name="group_start_ip"]').fill(
            "192.0.2.10"
        )
        page.locator('#management-form [name="group_end_ip"]').fill(
            "192.0.2.20"
        )
        page.locator('#management-form [name="opt_echo_seconds"]').fill("25")
        page.locator('#management-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "groups"
            and writes[-1]["body"]["options"]["echo_seconds"] == 25
            and writes[-1]["body"]["strategy"]
            == {
                "enabled": True,
                "type": "ip_range",
                "start_ip": "192.0.2.10",
                "end_ip": "192.0.2.20",
            }
        )

        visit("templates")
        page.locator("[data-template-new]").click()
        page.locator('#management-form [name="management_name"]').fill(
            "UI Template"
        )
        page.locator('#management-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert writes[-1]["path"] == "templates"

        visit("management")
        page.locator('[data-group-edit="floor"]').click()
        page.locator('#management-form [name="management_name"]').fill(
            "UI Floor"
        )
        page.locator('#management-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "groups"
            and writes[-1]["body"]["name"] == "UI Floor"
        )

        visit("templates")
        page.locator('[data-template-edit="template"]').click()
        page.locator('#management-form [name="management_name"]').fill(
            "UI Model"
        )
        page.locator('#management-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "templates"
            and writes[-1]["body"]["name"] == "UI Model"
        )

        visit("apdefaults")
        page.wait_for_selector("#management-form")
        page.locator(
            '#management-form [name="opt_offline_self_manage"]'
        ).select_option("on")
        page.locator('#management-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert (
            writes[-1]["path"] == "ap-defaults"
            and writes[-1]["body"]["offline_self_manage"] is True
        )
        assert next(
            r for r in writes[-1]["body"]["radios"] if r["radio_id"] == 8
        ) == {"radio_id": 8, "channel": 11, "advanced": {"rts": 2000}}

        visit("aps")
        page.locator("[data-ap-settings]").first.click()
        page.locator('#management-form [name="opt_echo_seconds"]').fill("31")
        page.locator('#management-form [name="opt_led"]').select_option("off")
        if full:
            page.locator(
                '#management-form [data-editor-tab="ap-advanced"]'
            ).click()
            page.locator(
                '#management-form [name="opt_rf_mode_enabled"]'
            ).select_option("on")
            page.locator(
                '#management-form [name="opt_rf_mode_id"]'
            ).select_option("7")
            page.locator('#management-form [name="opt_port_103_vlan"]').fill(
                "100"
            )
            assert (
                page.locator(
                    '#management-form [name="opt_port_12_vlan"]'
                ).count()
                == 0
            )
        page.locator('#management-form [type="submit"]').click()
        page.wait_for_timeout(80)
        if full:
            assert writes[-1]["body"]["options"]["rf_mode"] == {
                "enabled": True,
                "id": 7,
            }
            assert writes[-1]["body"]["options"]["lag"]["ports"] == [103, 104]
        assert (
            writes[-1]["path"].endswith("/settings")
            and writes[-1]["body"]["options"]["led"] is False
        )
        assert not page.locator("#editor").evaluate("(e)=>e.open"), (
            page.locator("#form-error").inner_text()
        )

        for copy_radios in (False, True):
            page.locator(
                '#content [data-ap="' + profile[0]["id"] + '"]'
            ).first.click()
            page.locator('[data-ap-copy="' + profile[0]["id"] + '"]').click()
            page.locator(
                '#management-copy-form input[name="targets"][value="'
                + spare["id"]
                + '"]'
            ).check()
            page.locator('#management-copy-form [name="radios"]').set_checked(
                copy_radios
            )
            page.locator('#management-copy-form [type="submit"]').click()
            page.wait_for_timeout(80)
            assert writes[-1]["path"].endswith("/copy") and writes[-1][
                "body"
            ] == {"targets": [spare["id"]], "radios": copy_radios}

        page.locator('#content [data-ap="' + offline["id"] + '"]').first.click()
        page.locator('[data-ap-replace="' + offline["id"] + '"]').click()
        page.locator('#management-replace-form [name="target"]').select_option(
            spare["id"]
        )
        page.locator('#management-replace-form [type="submit"]').click()
        page.wait_for_timeout(80)
        assert writes[-1]["path"].endswith("/replace") and writes[-1][
            "body"
        ] == {"target_ap_id": spare["id"]}

        name_csv = "编号,MAC地址,安装位置,设备名称\n1,02-00-00-00-00-01,Original,Updated\n"
        page.locator("[data-ap-batch-names]").click()
        page.locator("#ap-names-import").set_input_files(
            {
                "name": "ap-names.csv",
                "mimeType": "text/csv",
                "buffer": name_csv.encode(),
            }
        )
        page.wait_for_timeout(100)
        assert writes[-1]["path"] == "aps/names/import" and writes[-1][
            "body"
        ] == {"csv": name_csv}

        restore = {
            "format": "go-ac-configuration",
            "schema": 1,
            "config": {"services": []},
        }
        visit("backup")
        page.locator("#management-import").set_input_files(
            {
                "name": "go-ac-ui-test.json",
                "mimeType": "application/json",
                "buffer": json.dumps(restore).encode(),
            }
        )
        page.wait_for_timeout(100)
        assert writes[-1]["path"] == "restore" and writes[-1]["body"] == restore

        visit("radios")
        page.wait_for_function("() => !refreshing")
        page.evaluate(
            '() => Object.defineProperty(document, "hidden", {configurable:true,value:true})'
        )
        before_reads = len(reads)
        page.wait_for_timeout(4200)
        assert len(reads) == before_reads, "Background page kept polling"
        page.evaluate(
            '() => { delete document.hidden; document.dispatchEvent(new Event("visibilitychange")); }'
        )
        page.wait_for_timeout(250)
        assert len(reads) > before_reads, "Visible page did not refresh"

        visit("radios")
        page.evaluate("() => window.scrollTo(0,0)")
        page.screenshot(
            path=str(
                OUT
                / (
                    "all-capabilities-desktop.png"
                    if full
                    else "real-capabilities-desktop.png"
                )
            ),
            full_page=True,
        )
        page.set_viewport_size({"width": 390, "height": 844})
        page.wait_for_timeout(250)
        assert page.locator("#menu-toggle").is_visible()
        page.screenshot(
            path=str(
                OUT
                / (
                    "all-capabilities-mobile.png"
                    if full
                    else "real-capabilities-mobile.png"
                )
            ),
            full_page=True,
        )
        if full:
            page.locator("#menu-toggle").click()
            visit("overview")
            page.wait_for_timeout(150)
            page.screenshot(path=str(OUT / "overview-mobile.png"), full_page=True)
        page.close()

    ro_errors = []
    ro_console = []
    ro_page = browser.new_page(viewport={"width": 1280, "height": 800})
    ro_page.on("pageerror", lambda e: ro_errors.append(str(e)))
    ro_page.on(
        "console",
        lambda m: ro_console.append(m.text)
        if m.type == "error" and "405" not in m.text
        else None,
    )

    def ro_route(r):
        path = r.request.url.split("/api/")[1]
        if r.request.method != "GET":
            r.fulfill(
                status=405,
                content_type="text/html; charset=utf-8",
                body="<!DOCTYPE HTML><html><body><h1>405 Read-only UI preview</h1></body></html>",
            )
            return
        value = (
            aps
            if path == "aps"
            else cfg
            if path == "config"
            else clients
            if path == "clients"
            else mobility
            if path == "mobility"
            else {
                "configured_mode": 2,
                "actual_mode": 2,
                "mode_writable": False,
                "unsupported_aps": [],
            }
            if path == "mobility/status"
            else []
        )
        r.fulfill(json=value)

    ro_page.route("**/api/**", ro_route)
    ro_page.goto("http://127.0.0.1:" + str(server.server_port) + "/#mobility")
    ro_page.wait_for_function(
        '() => document.querySelector("#connection").textContent === "控制器已连接"'
    )
    ro_page.locator('#roam-simple-form [type="submit"]').click()
    ro_page.wait_for_timeout(120)
    assert (
        ro_page.locator("#form-error").inner_text()
        == "当前为只读预览模式，无法保存修改"
    ), ro_page.locator("#form-error").inner_text()
    assert not ro_errors, ro_errors
    assert not ro_console, ro_console
    ro_page.close()

    browser.close()

server.shutdown()
assert not errors, errors
assert not console_errors, console_errors
assert len(writes) == 72, len(writes)
assert (
    next(w for w in reversed(writes) if w["path"] == "radios")["body"][
        "advanced"
    ]["edca"]["preset"]
    == 2
)
print(
    json.dumps(
        {
            "profiles": 2,
            "pages_per_profile": 23,
            "forms_submitted": len(writes),
            "javascript_errors": errors,
            "console_errors": console_errors,
            "screenshots": str(OUT),
        },
        ensure_ascii=False,
    )
)
