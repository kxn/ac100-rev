"use strict";

const $ = (s) => document.querySelector(s);
const $$ = (s) => [...document.querySelectorAll(s)];
const esc = (s) =>
  String(s ?? "").replace(
    /[&<>"']/g,
    (c) =>
      ({
        "&": "&amp;",
        "<": "&lt;",
        ">": "&gt;",
        '"': "&quot;",
        "'": "&#39;",
      })[c],
  );

let data = {
  aps: [],
  clients: [],
  config: { services: [], radios: [] },
  apply: [],
  assignments: {},
  operations: {},
  timezone: "",
};
let tab = "overview";
let query = "";
let apStatusFilter = "all";
let apGroupFilter = "";
let clientQuery = "";
let clientAPFilter = "";
let clientStateFilter = "all";
let radioAPFilter = "";
let radioBandFilter = "all";
let dialogKind = "";
let currentService = null;
let currentRadio = null;
let refreshing = false;
let refreshAgain = false;
let interfaces = [];
let overviewHistory = { ap_counts: [], radios: [], events: [] };
let mobilityEvents = [];

const modes = {
  0: "802.11a",
  1: "802.11b",
  2: "802.11g",
  3: "802.11n（2.4 GHz）",
  4: "802.11n（5 GHz）",
  5: "802.11b/g",
  6: "802.11b/g/n",
  7: "802.11a/n",
  8: "802.11ac",
  9: "802.11a/n/ac",
  10: "802.11bgnax",
  11: "802.11anacax",
  12: "802.11bgnaxbe",
  13: "802.11anacaxbe",
};

const widths = {
  0: "20 MHz",
  1: "40 MHz",
  2: "自动",
  3: "80 MHz",
  4: "80 + 80 MHz",
  5: "160 MHz",
  6: "240 MHz",
};

const serviceFrequencyPresets = { dual: 32639, band2: 127, band5: 32512 };

const securityNames = {
  open: "开放网络",
  "wpa-psk": "WPA-PSK",
  "wpa2-psk": "WPA2-PSK",
  "wpa-wpa2-psk": "WPA/WPA2-PSK",
  "wpa2-wpa3-psk": "WPA2-PSK / WPA3-SAE",
};

const featureNames = {
  mesh: "Mesh 无线组网",
  rf_mode_change: "整机射频模式切换",
  usb: "USB 外设",
  dhcp_defense: "DHCP 防护",
  arp_defense: "ARP 防护",
  dhcpv6_defense: "DHCPv6 防护",
  nd_defense: "ND 防护",
  storm_control: "广播抑制",
  mlo: "MLO 多链路",
  multicast: "组播管理",
  multicast_per_ssid: "每服务组播策略",
  multicast_to_unicast: "组播转单播",
  vlan_pool: "VLAN 池",
  band_navigation: "双频优选",
  band_steering: "RSSI 频段引导",
  trunk: "下联 Trunk",
  edca_mode: "EDCA 模式",
  rssi_control: "弱信号接入与剔除",
  channel_optimization: "动态信道优化",
  fragmentation: "公平调度",
  ssid_rate_limit: "无线限速",
  new_security_format: "新版安全协议",
  frame_rate_control: "管理帧速率",
  edca: "EDCA 队列",
  wifi6_features: "Wi-Fi 6 特性",
};

async function api(path, body, method) {
  const r = await fetch(
    "/api/" + path,
    body === undefined && !method
      ? {}
      : {
          method: method || "POST",
          headers: { "Content-Type": "application/json" },
          ...(body === undefined ? {} : { body: JSON.stringify(body) }),
        },
  );
  const v = await r.json();
  if (!r.ok) throw Error(v.error || "请求失败");
  return v;
}

function toast(s) {
  const el = $("#toast");
  el.textContent = s;
  el.classList.remove("hidden");
  clearTimeout(toast.timer);
  toast.timer = setTimeout(() => el.classList.add("hidden"), 4500);
}

function ago(t) {
  const ts = Date.parse(t);
  if (!Number.isFinite(ts) || ts <= 0) return "未上报";
  const n = Math.floor((Date.now() - ts) / 1000);
  if (n < 0 || n > 1e8) return "未上报";
  if (n < 5) return "刚刚";
  if (n < 60) return n + " 秒前";
  if (n < 3600) return Math.floor(n / 60) + " 分钟前";
  if (n < 86400) return Math.floor(n / 3600) + " 小时前";
  return Math.floor(n / 86400) + " 天前";
}

function formatUptime(t) {
  const ts = Date.parse(t);
  if (!Number.isFinite(ts) || ts <= 0) return "—";
  const sec = Math.floor((Date.now() - ts) / 1000);
  if (sec < 0 || sec > 1e8) return "—";
  if (sec < 60) return "< 1 分钟";
  const mins = Math.floor(sec / 60);
  if (mins < 60) return mins + " 分钟";
  const hrs = Math.floor(mins / 60);
  if (hrs < 24) return hrs + " 小时 " + (mins % 60) + " 分";
  const days = Math.floor(hrs / 24);
  return days + " 天 " + (hrs % 24) + " 小时";
}

function apName(id) {
  return data.aps.find((a) => a.id === id)?.name || id || "未知";
}

function metric(v) {
  if (Array.isArray(v)) return metric(v.at(-1));
  return v == null ? "—" : v;
}

function table(headers, rows) {
  return `<div class="table-wrap"><table><thead><tr>${headers.map((x) => `<th>${x}</th>`).join("")}</tr></thead><tbody>${rows || `<tr><td class="empty" colspan="${headers.length}">暂无数据</td></tr>`}</tbody></table></div>`;
}

function panel(title, body, tools = "", filterBar = "") {
  return `<div class="panel"><div class="panel-heading"><h2>${title}</h2>${tools ? `<div class="toolbar-group">${tools}</div>` : ""}</div>${filterBar}${body}</div>`;
}

function statePill(state) {
  const info = {
    not_applicable: ["offline", "不适用"],
    idle: ["offline", "空闲"],
    collecting: ["pending", "测量中"],
    planning: ["pending", "计算中"],
    completed: ["online", "已完成"],
    uncertain: ["failed", "未确认"],
    timed_out: ["failed", "超时"],
    stopped: ["offline", "已停止"],
    waiting_report: ["pending", "等待报告"],
    sending: ["pending", "发送中"],
    interrupted: ["failed", "已中断"],
    queued: ["pending", "排队中"],
    transferring: ["pending", "传输中"],
    verifying: ["pending", "校验中"],
    waiting_reconnect: ["pending", "等待重连"],
    cancelled: ["offline", "已取消"],
    verified: ["online", "已校验"],
    acknowledged: ["online", "已下发"],
    applying: ["pending", "下发中"],
    failed: ["failed", "失败"],
    blocked: ["failed", "受阻"],
    failed_recovered: ["failed", "已回退"],
  };
  const [cl, label] = info[state] || ["pending", "等待同步"];
  return `<span class="pill ${cl}">${label}</span>`;
}

function bandTag(band) {
  if (!band) return '<span class="tag">—</span>';
  const cls = band.includes("2.4")
    ? "tag-2g"
    : band.includes("6")
      ? "tag-6g"
      : band.includes("5")
        ? "tag-5g"
        : "";
  return `<span class="tag ${cls}">${esc(band)}</span>`;
}

function signalMeter(rssi) {
  if (rssi == null || !Number.isFinite(Number(rssi)))
    return '<span class="muted">—</span>';
  const v = Number(rssi);
  const level = v >= -58 ? 4 : v >= -68 ? 3 : v >= -78 ? 2 : 1;
  const cls =
    level >= 3 ? "sig-good" : level === 2 ? "sig-fair" : "sig-weak";
  const bars = [4, 7, 10, 13]
    .map(
      (h, i) =>
        `<rect x="${i * 4}" y="${14 - h}" width="2.5" height="${h}" rx="0.8" fill="currentColor" fill-opacity="${i < level ? "1" : "0.22"}" />`,
    )
    .join("");
  return `<span class="signal-cell num ${cls}"><svg viewBox="0 0 15 14" width="15" height="14" aria-hidden="true">${bars}</svg><span>${esc(v)} dBm</span></span>`;
}

function meterBar(pct, tone = "accent") {
  const n = Math.max(0, Math.min(100, Math.round(Number(pct) || 0)));
  const colors = {
    accent: "#2563eb",
    ok: "#10b981",
    warn: "#f59e0b",
    err: "#ef4444",
  };
  const autoTone =
    tone === "auto"
      ? n >= 75
        ? colors.err
        : n >= 50
          ? colors.warn
          : colors.ok
      : colors[tone] || colors.accent;
  return `<span class="meter-cell num"><svg class="meter-svg" viewBox="0 0 100 6" preserveAspectRatio="none" aria-hidden="true"><rect width="100" height="6" rx="0" fill="#e5e7eb" /><rect width="${n}" height="6" rx="0" fill="${autoTone}" /></svg><span>${n}%</span></span>`;
}

function serviceStates(s) {
  const states = data.apply.filter((x) => x.service_id === s.id);
  const bad = states.find((x) =>
    ["failed", "failed_recovered", "blocked"].includes(x.state),
  );
  const pending = states.find((x) => x.state === "applying");
  return bad || pending || states[0];
}

function selectedAPs(s) {
  return data.aps.filter(
    (a) =>
      (!s.aps?.length && !s.groups?.length) ||
      s.aps?.includes(a.id) ||
      s.groups?.includes(
        (data.config.ap_profiles || []).find((p) => p.ap_id === a.id)?.group_id,
      ),
  );
}

function targetPicker(apsSelected = [], groupsSelected = [], opts = {}) {
  const apSet = new Set(apsSelected || []);
  const grpSet = new Set(groupsSelected || []);
  const apList = (opts.aps || data.aps).filter(
    (a) => !data.config.retired_aps?.includes(a.id),
  );
  const groups = data.config.groups || [];
  const hint = opts.emptyHint || "不勾选时应用到全部 AP";
  const apItems = apList.length
    ? apList
        .map(
          (a) =>
            `<label class="picker-item"><input type="checkbox" name="aps" value="${esc(a.id)}" ${apSet.has(a.id) ? "checked" : ""}><span>${esc(apName(a.id))}</span></label>`,
        )
        .join("")
    : '<span class="help">暂无 AP</span>';
  const grpItems = groups.length
    ? groups
        .map(
          (g) =>
            `<label class="picker-item"><input type="checkbox" name="groups" value="${esc(g.id)}" ${grpSet.has(g.id) ? "checked" : ""}><span>${esc(g.name)}</span></label>`,
        )
        .join("")
    : '<span class="help">暂无分组</span>';
  return `<div class="form-grid full">
    <div class="picker-box"><div class="picker-head"><span>应用 AP</span><span>${esc(hint)}</span></div><div class="picker-list">${apItems}</div></div>
    ${opts.hideGroups ? "" : `<div class="picker-box"><div class="picker-head"><span>应用分组</span><span>与所选 AP 合并</span></div><div class="picker-list">${grpItems}</div></div>`}
  </div>`;
}

function readTargetPicker(form) {
  return {
    aps: [...form.querySelectorAll('input[name="aps"]:checked')].map(
      (x) => x.value,
    ),
    groups: [...form.querySelectorAll('input[name="groups"]:checked')].map(
      (x) => x.value,
    ),
  };
}

function showTab(next) {
  tab = names[next] ? next : "overview";
  if (location.hash.slice(1) !== tab) location.hash = tab;
  query = "";
  updateNavigation();
  closeMobileSidebar();
  renderContent();
  void refresh();
}

function newID() {
  const b = crypto.getRandomValues(new Uint8Array(16));
  b[6] = (b[6] & 15) | 64;
  b[8] = (b[8] & 63) | 128;
  const h = [...b].map((x) => x.toString(16).padStart(2, "0")).join("");
  return `${h.slice(0, 8)}-${h.slice(8, 12)}-${h.slice(12, 16)}-${h.slice(16, 20)}-${h.slice(20)}`;
}

function updateBadgesAndAlerts() {
  const inventory = data.aps.filter(
    (a) => !data.config.retired_aps?.includes(a.id),
  );
  const onlineAPs = inventory.filter((a) => a.online).length;
  const connected = data.clients.filter((c) => c.state === "connected").length;
  const apBadge = $("#nav-badge-aps");
  if (apBadge) {
    apBadge.textContent = inventory.length
      ? `${onlineAPs}/${inventory.length}`
      : "";
    apBadge.classList.toggle("hidden", !inventory.length);
  }
  const clientBadge = $("#nav-badge-clients");
  if (clientBadge) {
    clientBadge.textContent = connected ? String(connected) : "";
    clientBadge.classList.toggle("hidden", !connected);
  }
  const bad = data.apply.filter((a) =>
    ["failed", "failed_recovered", "blocked"].includes(a.state),
  ).length;
  const pending = data.apply.filter((a) => a.state === "applying").length;
  const alertBtn = $("#sync-alert");
  if (alertBtn) {
    if (bad > 0) {
      alertBtn.textContent = `${bad} 项同步异常`;
      alertBtn.className = "sync-alert";
    } else if (pending > 0) {
      alertBtn.textContent = `${pending} 项下发中`;
      alertBtn.className = "sync-alert pending";
    } else {
      alertBtn.className = "sync-alert hidden";
    }
  }
}

function render() {
  updateBadgesAndAlerts();
  renderContent(true);
}

function renderClients() {
  const apsById = Object.fromEntries(data.aps.map((a) => [a.id, a]));
  const filtered = data.clients.filter((c) => {
    if (clientAPFilter && c.ap_id !== clientAPFilter) return false;
    if (clientStateFilter === "connected" && c.state !== "connected")
      return false;
    if (clientStateFilter === "2g" || clientStateFilter === "5g") {
      const cap = apsById[c.ap_id]?.capabilities?.find(
        (x) => x.radio_id === c.radio_id,
      );
      if (clientStateFilter === "2g" && !cap?.band?.includes("2.4"))
        return false;
      if (clientStateFilter === "5g" && !cap?.band?.includes("5")) return false;
    }
    if (!clientQuery) return true;
    const hay = [
      c.name,
      c.note,
      c.mac,
      c.ip,
      c.ssid,
      c.device?.device_name,
      c.device?.hostname,
      c.device?.brand,
      c.device?.system,
      apName(c.ap_id),
    ];
    return hay.some((v) => String(v || "").toLowerCase().includes(clientQuery));
  });

  const filterBar = `<div class="filter-bar">
    <div class="toolbar-group">
      <input id="client-search" class="search" type="search" aria-label="搜索客户端" placeholder="搜索名称、MAC、IP 或 SSID" value="${esc(clientQuery)}" />
      <select name="client_ap_filter" aria-label="按 AP 筛选">${Object.entries({
        "": "全部 AP",
        ...Object.fromEntries(data.aps.map((a) => [a.id, apName(a.id)])),
      })
        .map(
          ([v, l]) =>
            `<option value="${esc(v)}" ${v === clientAPFilter ? "selected" : ""}>${esc(l)}</option>`,
        )
        .join("")}</select>
    </div>
    <div class="seg-tabs" role="tablist" aria-label="筛选客户端">
      ${[
        ["all", "全部"],
        ["connected", "在线"],
        ["2g", "2.4 GHz"],
        ["5g", "5 GHz"],
      ]
        .map(
          ([id, label]) =>
            `<button type="button" data-client-filter="${id}" class="${clientStateFilter === id ? "active" : ""}">${label}</button>`,
        )
        .join("")}
    </div>
  </div>`;

  const rows = filtered
    .map((c) => {
      const a = apsById[c.ap_id];
      const cap = a?.capabilities?.find((r) => r.radio_id === c.radio_id);
      const v = a?.wireless_telemetry?.vaps?.find(
        (x) => x.radioId === c.radio_id,
      );
      const s = data.config.services.find(
        (x) =>
          Number(data.assignments?.[c.ap_id]?.[x.id]?.[c.radio_id]) ===
          c.wlan_id,
      );
      const title =
        c.name || c.device?.device_name || c.device?.hostname || c.mac;
      const meta = [c.device?.brand, c.device?.system]
        .filter(Boolean)
        .join(" · ");
      const ssid =
        c.ssid || (c.state === "connected" ? s?.ssid || v?.ssidName : "") || "—";
      const bandLabel = cap?.band || (c.radio_id ? "射频 " + c.radio_id : "—");
      const stateLabel =
        {
          connected: "在线",
          disconnected: "离线",
          observed: "已上报",
          ap_offline: "AP 离线",
        }[c.state] || c.state;
      const ipExtra = (c.ipv6 || []).slice(0, 2).join(", ");
      const mloRows = (c.radio_entries || [])
        .map(
          (r) =>
            `<small class="num">MLO 射频 ${esc(r.radio_id)} · ${r.statistics ? esc(r.statistics.negotiated_mbps) + " Mbps" : "—"} · ${r.rssi_dbm == null ? "—" : esc(r.rssi_dbm) + " dBm"}</small>`,
        )
        .join("");

      const macLine =
        title !== c.mac
          ? [c.mac, c.note].filter(Boolean).join(" · ")
          : c.note || "";
      return `<tr>
        <td>
          <strong class="${title === c.mac ? "mono" : ""}">${esc(title)}</strong>
          ${macLine ? `<small class="mono">${esc(macLine)}</small>` : ""}
          ${meta ? `<small>${esc(meta)}</small>` : ""}
        </td>
        <td>
          <span class="pill ${c.state === "connected" ? "online" : ""}">${esc(stateLabel)}</span>
          <small class="num">${c.state === "connected" && c.connected_at ? formatUptime(c.connected_at) : ago(c.last_seen)}</small>
        </td>
        <td>
          <div>${esc(apName(c.ap_id))}</div>
          <small>${esc(ssid)} · ${esc(bandLabel)}${c.vlan_id ? " · VLAN " + esc(c.vlan_id) : ""}${c.mlo ? ' · <span class="tag tag-info">MLO</span>' : ""}</small>
        </td>
        <td>${signalMeter(c.rssi_dbm)}</td>
        <td class="mono">${esc(c.ip || "—")}${ipExtra ? `<small class="mono">${esc(ipExtra)}</small>` : ""}</td>
        <td class="num">
          ${c.statistics ? esc(c.statistics.negotiated_mbps) + " Mbps" : "—"}
          <small>↑ ${c.statistics?.upstream_kbps ?? "—"} / ↓ ${c.statistics?.downstream_kbps ?? "—"} kbps</small>
          ${mloRows}
        </td>
        <td>
          <div class="actions">
            <button type="button" class="text-button" data-client-label="${esc(c.mac)}">命名</button>
            <button type="button" class="text-button" data-client-history="${esc(c.mac)}">信号</button>
            <button type="button" class="text-button danger" data-client-disconnect="${esc(c.mac)}" ${c.state === "connected" ? "" : "disabled"}>下线</button>
          </div>
        </td>
      </tr>`;
    })
    .join("");

  return panel(
    `客户端 (${filtered.length})`,
    table(
      ["终端", "状态", "接入 AP / 网络", "信号", "IP 地址", "协商 / 实时速率", "操作"],
      rows,
    ),
    "",
    filterBar,
  );
}

function renderInterfaces() {
  const rows = interfaces
    .map(
      (i) => `<tr>
        <td><strong>${esc(i.name)}</strong></td>
        <td><span class="pill ${i.bound ? "online" : ""}">${i.bound ? "当前绑定" : i.up ? "已启用" : "未启用"}</span></td>
        <td class="mono">${esc(i.addresses.join(", ") || "—")}</td>
        <td><button type="button" class="btn secondary sm" data-interface="${esc(i.name)}" ${i.bound ? "disabled" : ""}>绑定</button></td>
      </tr>`,
    )
    .join("");
  return (
    panel("通信接口", table(["接口", "状态", "IP 地址", "操作"], rows)) +
    '<p class="help">修改监听接口后需重启程序生效。</p>'
  );
}

function renderContent(background = false) {
  const root = $("#content");
  if (background) {
    if (
      root.contains(document.activeElement) &&
      ["INPUT", "SELECT", "TEXTAREA"].includes(document.activeElement.tagName)
    )
      return;
    if (root.querySelector('[data-inline][data-dirty="1"]')) return;
  }

  const renderers = {
    overview: renderOverview,
    aps: renderAPInventory,
    management: () => renderManagement("management"),
    templates: () => renderManagement("templates"),
    apdefaults: () => renderManagement("apdefaults"),
    mesh: renderMesh,
    services: renderServices,
    pools: renderVLANPools,
    multicast: renderMulticastGroups,
    radios: renderRadios,
    rrm: renderRRM,
    rates: renderRates,
    edca: renderEDCA,
    mobility: () => renderMobility("mobility"),
    balance: () => renderMobility("balance"),
    band: renderBandNavigation,
    clients: renderClients,
    history: renderHistory,
    protection: renderProtection,
    upgrades: renderUpgrades,
    interfaces: renderInterfaces,
    resources: renderControllerResources,
    backup: renderBackup,
  };

  const activeId = document.activeElement?.id;
  const selStart =
    activeId && typeof document.activeElement.selectionStart === "number"
      ? document.activeElement.selectionStart
      : null;
  const openDetails = [...root.querySelectorAll("details")].map((d) => d.open);
  const tableScrolls = [...root.querySelectorAll(".table-wrap")].map((t) => [
    t.scrollLeft,
    t.scrollTop,
  ]);
  const activeInnerTab = root.querySelector("[data-editor-tab].active")?.dataset
    .editorTab;

  root.innerHTML = (renderers[tab] || renderOverview)();

  if (activeInnerTab) {
    const tBtn = root.querySelector(
      `[data-editor-tab="${activeInnerTab}"]`,
    );
    if (tBtn) tBtn.click();
  }
  root.querySelectorAll("details").forEach((d, i) => {
    if (openDetails[i]) d.open = true;
  });
  root.querySelectorAll(".table-wrap").forEach((t, i) => {
    if (tableScrolls[i]) {
      t.scrollLeft = tableScrolls[i][0];
      t.scrollTop = tableScrolls[i][1];
    }
  });
  if (activeId && $("#" + activeId)) {
    const el = $("#" + activeId);
    el.focus();
    if (selStart !== null && typeof el.setSelectionRange === "function")
      el.setSelectionRange(selStart, selStart);
  }
  if (tab === "mesh") void loadMeshJobs();
}

async function refresh() {
  if (refreshing) {
    refreshAgain = true;
    return;
  }
  refreshing = true;
  try {
    const [aps, clients, cfg] = await Promise.all([
      api("aps"),
      api("clients"),
      api("config"),
    ]);
    data = {
      aps,
      clients,
      config: cfg.config,
      apply: cfg.apply,
      assignments: cfg.assignments || {},
      operations: cfg.operations || {},
      timezone: cfg.timezone,
    };
    if (tab === "overview") {
      overviewHistory = await api("history?limit=120").catch(
        () => overviewHistory,
      );
    }
    if (tab === "interfaces") interfaces = await api("interfaces");
    if (tab === "resources")
      controllerResources = await api("controller/resources");
    if (["mobility", "balance"].includes(tab))
      mobilityStatus = await api("mobility/status");
    if (tab === "rates") {
      const dirty = $("#content")?.querySelector("#rates-form[data-dirty='1']");
      if (!dirty) ratesData = await api("rates");
    }
    if (tab === "protection" && !stormDefaults)
      stormDefaults = await api("storm/defaults");
    if (tab === "upgrades") upgradeData = await api("upgrades");
    if (tab === "history") {
      const q = new URLSearchParams({ limit: "1440" });
      if (historyAP) q.set("ap", historyAP);
      if (historyRadio) q.set("radio", historyRadio);
      const [h, ev] = await Promise.all([
        api("history?" + q),
        api("mobility/events").catch(() => mobilityEvents),
      ]);
      historyData = h;
      mobilityEvents = Array.isArray(ev) ? ev : [];
    }
    render();
    $("#sync").textContent = new Date().toLocaleTimeString("zh-CN", {
      hour12: false,
    });
    $("#connection").textContent = "控制器已连接";
    $("#connection-dot").className = "connection-dot online";
    if (dialogKind === "ap" && $("#drawer").open) {
      const details = [...$("#drawer-body").querySelectorAll("details")];
      const open = details.map((d) => d.open);
      const scroll = $("#drawer-body").scrollTop;
      renderAPDetail(currentService);
      $("#drawer-body")
        .querySelectorAll("details")
        .forEach((d, i) => {
          if (i < open.length) d.open = open[i];
        });
      $("#drawer-body").scrollTop = scroll;
    }
  } catch (e) {
    $("#connection").textContent = "连接中断";
    $("#connection-dot").className = "connection-dot offline";
    $("#sync").textContent = e.message;
  } finally {
    refreshing = false;
    if (refreshAgain) {
      refreshAgain = false;
      void refresh();
    }
  }
}

function openDialog(kind, title, subtitle, body) {
  if ($("#drawer").open) $("#drawer").close();
  dialogKind = kind;
  $("#dialog-title").textContent = title;
  $("#dialog-subtitle").textContent = subtitle || "";
  $("#dialog-subtitle").classList.toggle("hidden", !subtitle);
  $("#dialog-body").innerHTML = body;
  if (!$("#editor").open) $("#editor").showModal();
  $("#dialog-body").scrollTop = 0;
}

function openDrawer(kind, title, subtitle, body) {
  if ($("#editor").open) $("#editor").close();
  dialogKind = kind;
  $("#drawer-title").textContent = title;
  $("#drawer-subtitle").textContent = subtitle || "";
  $("#drawer-subtitle").classList.toggle("hidden", !subtitle);
  $("#drawer-body").innerHTML = body;
  if (!$("#drawer").open) $("#drawer").showModal();
  $("#drawer-body").scrollTop = 0;
}

function closeDialogs() {
  if ($("#editor").open) $("#editor").close();
  if ($("#drawer").open) $("#drawer").close();
  dialogKind = "";
}

function tabs(items) {
  return `<div class="editor-tabs">${items.map(([id, label], i) => `<button type="button" data-editor-tab="${id}" class="${i ? "" : "active"}">${label}</button>`).join("")}</div>`;
}

function pane(id, body, first = false) {
  return `<section data-pane="${id}" class="${first ? "" : "hidden"}">${body}</section>`;
}

function field(name, label, value, type = "number", extra = "", unit = "") {
  const input = `<input name="${name}" type="${type}" value="${esc(value)}" ${extra}>`;
  return `<label>${label ? `<span>${label}</span>` : ""}${unit ? `<div class="input-unit">${input}<span class="unit-tag">${esc(unit)}</span></div>` : input}</label>`;
}

function select(name, label, values, value, extra = "") {
  const opts = Object.entries(values)
    .map(
      ([v, l]) =>
        `<option value="${esc(v)}" ${String(v) === String(value) ? "selected" : ""}>${esc(l)}</option>`,
    )
    .join("");
  return `<label>${label ? `<span>${label}</span>` : ""}<select name="${name}" ${extra}>${opts}</select></label>`;
}

function check(name, label, value, extra = "") {
  return `<label class="check"><input type="checkbox" name="${name}" ${value ? "checked" : ""} ${extra}>${label ? `<span>${label}</span>` : ""}</label>`;
}

function toggle(name, label, value, extra = "") {
  return `<label class="toggle">${label ? `<span>${label}</span>` : ""}<input type="checkbox" name="${name}" ${value ? "checked" : ""} ${extra}></label>`;
}

function formEnd(label = "保存并下发", extraActions = "") {
  return `<div class="form-footer"><span class="form-error" id="form-error" role="status"></span><div class="form-actions">${extraActions}<button class="btn primary" type="submit">${label}</button></div></div>`;
}

function renderAPDetail(id) {
  const ap = data.aps.find((a) => a.id === id);
  if (!ap) return;
  const profile = (data.config.ap_profiles || []).find((p) => p.ap_id === id);
  const group =
    (data.config.groups || []).find((g) => g.id === profile?.group_id)?.name ||
    "未分组";
  const template =
    (data.config.templates || []).find((t) => t.id === profile?.template_id)
      ?.name || "未使用";
  const settings = [...data.apply.filter((s) => s.ap_id === id)].sort((a, b) =>
    a.service_id.localeCompare(b.service_id),
  );
  const hasSyncProblem = settings.some((s) =>
    ["failed", "failed_recovered", "blocked", "applying"].includes(s.state),
  );

  const radioRows = (ap.capabilities || [])
    .map((c) => {
      const stats = ap.radio_statistics?.find((r) => r.radio_id === c.radio_id);
      const obs = ap.radio_status?.find((r) => r.radio_id === c.radio_id);
      const nat = ap.wireless_telemetry?.radios?.find(
        (r) => r.radioId === c.radio_id,
      );
      const bw =
        { 0: 20, 1: 40, 3: 80, 5: 160, 6: 240 }[stats?.bandwidth_code] ??
        nat?.bw;
      const ch = stats?.channel ?? obs?.channel ?? nat?.channel;
      const pwr = obs?.power_dbm;
      return `<tr>
        <td>${bandTag(c.band)}<small>射频 ${c.radio_id}</small></td>
        <td class="num">${ch ?? "—"} / ${bw ? esc(bw) + " MHz" : "—"}</td>
        <td class="num">${pwr != null ? esc(pwr) + " dBm" : "—"}</td>
        <td>${stats?.channel_load_percent != null ? meterBar(stats.channel_load_percent, "auto") : '<span class="muted">—</span>'}</td>
        <td><button type="button" class="text-button" data-radio="${c.radio_id}" data-radio-ap="${esc(id)}">配置</button></td>
      </tr>`;
    })
    .join("");

  const vapRows = (ap.wireless_telemetry?.vaps || [])
    .map(
      (v) =>
        `<tr><td><strong>${esc(v.ssidName)}</strong></td><td class="num">射频 ${v.radioId} · ${esc(v.bw)} MHz</td><td class="mono">${esc(v.bssid)}</td></tr>`,
    )
    .join("");

  const syncRows = settings
    .map(
      (item) =>
        `<tr><td>${esc(configurationItemName(item.service_id))}</td><td>${statePill(item.state)}</td><td>${esc(item.error || "—")}</td></tr>`,
    )
    .join("");

  const body = `
    <div class="toolbar">
      <span class="pill ${ap.online ? "online" : ""}">${ap.online ? "在线 · " + formatUptime(ap.connected_at) : "离线 · " + ago(ap.last_seen)}</span>
      <span class="tag">${esc(group)}</span>
    </div>
    <div class="drawer-section">
      <div class="drawer-actions">
        <button type="button" class="btn primary sm" data-ap-settings="${esc(id)}">配置参数</button>
        <button type="button" class="btn secondary sm" data-label="${esc(id)}">改名</button>
        <button type="button" class="btn secondary sm" data-ap-copy="${esc(id)}">复制配置</button>
        ${!ap.online ? `<button type="button" class="btn secondary sm" data-ap-replace="${esc(id)}">替换 AP</button>` : ""}
        <button type="button" class="btn secondary sm" data-readback="${esc(id)}" ${ap.online ? "" : "disabled"}>刷新状态</button>
        <button type="button" class="btn secondary sm" data-led="${esc(id)}" ${ap.online ? "" : "disabled"}>LED 开</button>
        <button type="button" class="btn secondary sm" data-led-off="${esc(id)}" ${ap.online ? "" : "disabled"}>LED 关</button>
        <button type="button" class="btn secondary sm" data-ap-action="reboot" data-action-ap="${esc(id)}" ${ap.online ? "" : "disabled"}>重启</button>
        <button type="button" class="btn secondary danger sm" data-ap-action="factory-reset" data-action-ap="${esc(id)}" ${ap.online ? "" : "disabled"}>恢复出厂</button>
      </div>
    </div>
    <div class="drawer-section">
      <h3>射频状态</h3>
      ${table(["频段", "信道 / 带宽", "功率", "信道负载", "操作"], radioRows)}
    </div>
    <div class="drawer-section">
      <h3>广播的无线服务</h3>
      ${table(["SSID", "射频 / 带宽", "BSSID"], vapRows)}
    </div>
    <details class="advanced-section" ${hasSyncProblem ? "open" : ""}>
      <summary>配置同步 (${settings.length})</summary>
      ${table(["配置项", "状态", "说明"], syncRows)}
    </details>
    <details class="advanced-section">
      <summary>硬件与能力信息</summary>
      <dl class="detail-grid">
        <div><dt>型号</dt><dd>${esc(ap.model || "—")}</dd></div>
        <div><dt>分组 / 模板</dt><dd>${esc(group)} / ${esc(template)}</dd></div>
        <div><dt>安装位置</dt><dd>${esc(profile?.location || ap.location || "—")}</dd></div>
        <div><dt>序列号</dt><dd class="mono">${esc(ap.serial || "—")}</dd></div>
        <div><dt>硬件版本</dt><dd>${esc(ap.hardware_version || "—")}</dd></div>
        <div><dt>软件版本</dt><dd>${esc(ap.software_version || ap.wireless_telemetry?.software_version || "—")}</dd></div>
      </dl>
      <div class="chips">${Object.entries(ap.features || {})
        .filter(([, enabled]) => enabled)
        .map(([key]) => `<span class="chip">${esc(featureNames[key] || key)}</span>`)
        .join("")}</div>
      <details class="advanced-section"><summary>原始能力数据</summary><pre class="raw">${esc(JSON.stringify({ general: ap.general_capabilities, sub: ap.sub_capabilities, radios: ap.capabilities }, null, 2))}</pre></details>
    </details>`;

  const sub = `${ap.model || "AP"} · ${ap.local_ip === "0.0.0.0" ? ap.address : ap.local_ip || ap.address} · ${ap.mac}`;
  if (dialogKind === "ap" && $("#drawer").open) {
    $("#drawer-title").textContent = apName(id);
    $("#drawer-subtitle").textContent = sub;
    $("#drawer-body").innerHTML = body;
    return;
  }
  currentService = id;
  openDrawer("ap", apName(id), sub, body);
}

function configurationItemName(id) {
  const labels = {
    "ap-settings": "AP 参数",
    rates: "速率表",
    roaming: "无缝漫游",
    balance: "负载均衡",
    "roaming-mode": "漫游网络模式",
    "roaming-result": "漫游候选",
    "band-navigation": "双频优选",
    reporting: "状态上报",
    "wireless-reporting": "无线状态上报",
    protection: "网络防护",
    storm: "广播抑制",
    "configuration-commit": "配置提交",
  };
  return (
    labels[id] ||
    (id.startsWith("radio:")
      ? "射频 " + id.slice(6)
      : data.config.services.find((s) => s.id === id)?.ssid || "设备配置")
  );
}

function optionDefaults(s) {
  return {
    encoding: "utf-8",
    description: "",
    isolate: false,
    vlan: 0,
    auth:
      s?.security === "wpa-psk"
        ? 1
        : s?.security?.startsWith("wpa-wpa2") || s?.security === "wpa2-wpa3-psk"
          ? 3
          : 2,
    cipher: 2,
    key_update_interval: 86400,
    ...(s?.options || {}),
  };
}

function serviceEditor(s) {
  currentService = s;
  const o = optionDefaults(s);
  const l = o.rate_limit || {
    enabled: false,
    mode: "client",
    upload_kbps: 1000,
    download_kbps: 1000,
  };
  const m = o.multicast || {
    snooping: true,
    to_unicast: true,
    drop_unknown: false,
    rate_2g: 1,
    rate_5g: 6,
    query: false,
    query_interval: 60,
    max_response: 10,
  };
  const radios = [
    ...new Set([
      1,
      2,
      ...data.aps.flatMap((a) =>
        (a.capabilities || []).map((c) => c.radio_id),
      ),
    ]),
  ];

  const basics = `<div class="form-grid">
    ${field("ssid", "无线名称（SSID）", s?.ssid || "", "text", 'required maxlength="96"')}
    ${toggle("enabled", "启用此无线服务", s?.enabled ?? true)}
  </div>`;

  const security = `<div class="form-grid">
    ${select("security", "安全方式", securityNames, s?.security || "wpa2-psk")}
    <label id="password-field"><span>无线密码</span><input name="passphrase" type="password" autocomplete="new-password" placeholder="${s?.has_password ? "留空不修改密码" : "8–63 个字符"}"></label>
  </div>
  <p class="help" id="security-compat"></p>
  <details class="advanced-section">
    <summary>更多安全与广播参数</summary>
    <div class="form-grid">
      ${select("encoding", "SSID 编码", { "utf-8": "UTF-8", gbk: "GBK" }, o.encoding)}
      ${select("cipher", "加密算法", { 2: "AES", 1: "TKIP", 0: "自动" }, o.cipher)}
      ${field("key_update_interval", "组密钥更新周期", o.key_update_interval, "number", 'min="0" max="604800"', "秒")}
      <label class="full"><span>备注</span><textarea name="description" maxlength="150" rows="2">${esc(o.description)}</textarea></label>
    </div>
    <div class="switch-list">
      ${check("hidden", "隐藏 SSID", s?.hidden)}
      ${check("isolate", "终端隔离", o.isolate)}
      ${check("mlo", "启用 MLO 多链路", o.mlo, 'id="mlo-check"')}
    </div>
  </details>`;

  const frequencyMask = s?.auto_bind_frequencies ?? 32639;
  const frequencyPreset =
    Object.keys(serviceFrequencyPresets).find(
      (key) => serviceFrequencyPresets[key] === frequencyMask,
    ) || "custom";

  const freqChecks2g = Array.from(
    { length: 8 },
    (_, i) =>
      `<label class="picker-item"><input type="checkbox" name="auto_bind_frequencies" value="${2 ** i}" ${frequencyMask & (2 ** i) ? "checked" : ""}><span>2.4 GHz · 第 ${i + 1} 路</span></label>`,
  ).join("");
  const freqChecks5g = Array.from(
    { length: 8 },
    (_, i) =>
      `<label class="picker-item"><input type="checkbox" name="auto_bind_frequencies" value="${2 ** (i + 8)}" ${frequencyMask & (2 ** (i + 8)) ? "checked" : ""}><span>5 GHz · 第 ${i + 1} 路</span></label>`,
  ).join("");

  const binds = `<div class="form-grid">
    ${targetPicker(s?.aps || [], s?.groups || [])}
    ${select("binding_mode", "频段绑定方式", { freq: "按频段自动绑定", auto: "按射频编号绑定", explicit: "逐台选择 AP / 射频" }, s?.bindings?.length ? "explicit" : s ? (s.auto_bind_frequencies != null ? "freq" : "auto") : "freq")}
    ${field("vlan", "默认 VLAN ID（0 不打标签）", o.vlan, "number", 'min="0" max="4094"')}
    <fieldset class="full">
      <legend>广播频段</legend>
      ${select("band_preset", "频段预设", { dual: "2.4 GHz 和 5 GHz（双频）", band2: "仅 2.4 GHz", band5: "仅 5 GHz", custom: "自定义频段序号" }, frequencyPreset)}
      <details class="frequency-ranks" ${frequencyPreset === "custom" ? "open" : ""}>
        <summary>多射频频段序号</summary>
        <div class="picker-grid"><div>${freqChecks2g}</div><div>${freqChecks5g}</div></div>
      </details>
    </fieldset>
    <fieldset class="full">
      <legend>按射频编号绑定</legend>
      <div class="switch-list">${radios.map((n) => check("radio_" + n, "射频 " + n, s ? s.radios.includes(n) : n <= 2)).join("")}</div>
    </fieldset>
    <div class="full">
      ${select("vlan_pool", "VLAN 池", { 0: "不使用", ...Object.fromEntries((data.config.vlan_pools || []).filter((p) => !p.deleting).map((p) => [p.id, p.name + " · " + p.vlans])) }, o.vlan_pool || 0)}
    </div>
    <div class="full" id="explicit-bindings-wrap">
      <h3 class="section-title">选择 AP / 射频</h3>
      <div class="table-wrap">
        <table class="binding-table">
          <thead><tr><th>绑定</th><th>AP / 频段</th><th>VLAN ID</th><th>支持能力</th></tr></thead>
          <tbody>${data.aps
            .flatMap((ap) =>
              (ap.capabilities || [])
                .filter((c) => c.function_type !== 1)
                .map((c) => {
                  const bound = s?.bindings?.find(
                    (b) => b.ap_id === ap.id && b.radio_id === c.radio_id,
                  );
                  return `<tr data-binding-ap="${esc(ap.id)}" data-binding-radio="${c.radio_id}">
                    <td><input aria-label="绑定 ${esc(apName(ap.id))} 射频 ${c.radio_id}" type="checkbox" class="binding-check" ${bound ? "checked" : ""}></td>
                    <td>${esc(apName(ap.id))}<small>${esc(c.band)} · 射频 ${c.radio_id}</small></td>
                    <td><input class="binding-vlan" aria-label="VLAN ID" type="number" min="0" max="4094" value="${bound?.vlan ?? o.vlan}"></td>
                    <td>${c.support_wpa3 ? "WPA3 · " : ""}最多 ${c.max_ssid} 个 SSID</td>
                  </tr>`;
                }),
            )
            .join("")}</tbody>
        </table>
      </div>
    </div>
  </div>`;

  const qos = `<fieldset>
      <legend>无线限速</legend>
      <div class="form-grid">
        ${toggle("limit_enabled", "启用限速", l.enabled)}
        ${select("limit_mode", "限速方式", { client: "按单终端", ssid: "按整个 SSID" }, l.mode)}
        ${field("upload", "上行限速", l.upload_kbps, "number", 'min="8" max="8000000" step="8"', "kbps")}
        ${field("download", "下行限速", l.download_kbps, "number", 'min="8" max="8000000" step="8"', "kbps")}
      </div>
      <p class="help">速率须为 8 的倍数。</p>
    </fieldset>
    <div id="mc-fields">
      <h3 class="section-title">组播参数</h3>
      <div class="form-grid">
        ${check("mc_global", "配置 AP 全局组播参数", m.configure_global)}
        ${check("mc_global_snoop", "AP 全局 IGMP Snooping", m.global_snooping)}
        <div class="switch-list full">
          ${check("mc_snoop", "IGMP Snooping", m.snooping)}
          ${check("mc_unicast", "组播转单播", m.to_unicast)}
          ${check("mc_drop", "丢弃未知组播", m.drop_unknown)}
          ${check("mc_query", "启用 IGMP 查询", m.query)}
        </div>
        ${select("rate2", "2.4 GHz 组播速率", Object.fromEntries([1, 2, 5, 6, 9, 11, 12, 18, 24, 36, 48, 54].map((n) => [n, n + " Mbps"])), m.rate_2g)}
        ${select("rate5", "5 GHz 组播速率", Object.fromEntries([6, 9, 12, 18, 24, 36, 48, 54].map((n) => [n + "", n + " Mbps"])), m.rate_5g)}
        ${field("query_interval", "查询周期", m.query_interval, "number", 'min="1" max="65535"', "秒")}
        ${field("max_response", "最大响应时间", m.max_response, "number", 'min="1" max="255"', "秒")}
      </div>
    </div>`;

  const schedule = o.schedule || {
    enabled: false,
    timezone: data.timezone || "Local",
    action: "on",
    windows: [],
  };
  const clock = (n) =>
    String(Math.floor(n / 60)).padStart(2, "0") +
    ":" +
    String(n % 60).padStart(2, "0");
  const scheduleBody = `<div class="form-grid">
      ${toggle("schedule_enabled", "启用无线定时", schedule.enabled)}
      ${select("schedule_action", "时段行为", { on: "时段内启用", off: "时段内停用" }, schedule.action)}
      ${field("schedule_timezone", "时区", schedule.timezone, "text")}
      <label class="full"><span>生效日期范围（可选，每行一段）</span><textarea name="schedule_dates" rows="2" placeholder="2026-12-01 ~ 2026-12-31">${esc((schedule.dates || []).map((d) => d.start + " ~ " + d.end).join("\n"))}</textarea></label>
    </div>
    <h3 class="section-title">每周时段</h3>
    <div class="form-grid">${["星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期日"]
      .map((day, i) =>
        field(
          "schedule_day_" + i,
          day,
          schedule.windows
            .filter((w) => w.days & (1 << i))
            .map((w) => clock(w.start_minute) + "-" + clock(w.end_minute))
            .join(","),
          "text",
          'placeholder="08:00-12:00,13:00-18:00"',
        ),
      )
      .join("")}</div>`;

  openDialog(
    "service",
    s ? "编辑无线服务 · " + s.ssid : "新建无线服务",
    "",
    `<form id="service-form" novalidate>${tabs([
      ["basic", "基本与安全"],
      ["binding", "AP 与频段"],
      ["qos", "限速与组播"],
      ["schedule", "无线定时"],
    ])}${pane("basic", basics + security, true)}${pane("binding", binds)}${pane("qos", qos)}${pane("schedule", scheduleBody)}${formEnd()}</form>`,
  );
  updateSecurity();
}

function bandNavigationEditor() {
  showTab("band");
}

function poolEditor(p) {
  openDialog(
    "pool",
    p ? "编辑 VLAN 池" : "新建 VLAN 池",
    "",
    `<form id="pool-form" novalidate>
      <div class="form-grid">
        ${field("pool_id", "编号", p?.id || 1, "number", 'required min="1" max="255" ' + (p ? "readonly" : ""))}
        ${field("pool_name", "名称", p?.name || "", "text", 'required maxlength="64"')}
        <label class="full"><span>VLAN 列表</span><input name="pool_vlans" required value="${esc(p?.vlans || "")}" placeholder="100-110, 200, 300-310"></label>
      </div>
      <p class="help">使用 VLAN 池时，无线服务的固定 VLAN ID 须设为 0。</p>
      ${formEnd()}
    </form>`,
  );
}

function frequencyRadioBits(ap) {
  const caps = [...(ap.capabilities || [])].sort(
    (a, b) => a.radio_id - b.radio_id,
  );
  const out = {};
  const assign = (members) => {
    const ranks = {};
    for (const r of caps) {
      if (members && !members.has(r.radio_id)) continue;
      let rank = ranks[r.band] || 0;
      ranks[r.band] = rank + 1;
      if (rank >= 8) continue;
      if (r.band === "5 GHz") rank += 8;
      else if (r.band !== "2.4 GHz") continue;
      if (!out[r.radio_id]) out[r.radio_id] = 1 << rank;
    }
  };
  if ((ap.general_capabilities?.[2] || 0) & (1 << 28)) {
    for (const mode of ap.radio_modes || []) assign(new Set(mode.radios || []));
  } else assign(null);
  return out;
}

function frequencyRadioMask(f) {
  return [
    ...f.querySelectorAll('input[name="auto_bind_frequencies"]:checked'),
  ].reduce((n, o) => n | Number(o.value), 0);
}

function frequencyRadioSelected(f, ap, c) {
  return !!(frequencyRadioMask(f) & (frequencyRadioBits(ap)[c.radio_id] || 0));
}

function updateBindingMode(f) {
  const mode = f.elements.binding_mode.value;
  f.elements.band_preset
    ?.closest("fieldset")
    ?.classList.toggle("hidden", mode !== "freq");
  const radio = f.querySelector('[name^="radio_"]');
  if (radio)
    radio.closest("fieldset").classList.toggle("hidden", mode !== "auto");
  const wrap = $("#explicit-bindings-wrap");
  if (wrap) wrap.classList.toggle("hidden", mode !== "explicit");
}

function updateSecurity() {
  const f = $("#service-form");
  if (!f) return;
  updateBindingMode(f);
  const sec = f.elements.security.value;
  $("#password-field").classList.toggle("hidden", sec === "open");
  f.elements.cipher.disabled = sec === "wpa2-wpa3-psk";
  if (sec === "wpa2-wpa3-psk") f.elements.cipher.value = "2";

  const picked = readTargetPicker(f);
  const bindings = [...f.querySelectorAll("[data-binding-ap]")].filter(
    (x) => x.querySelector(".binding-check").checked,
  );
  const explicit = f.elements.binding_mode.value === "explicit";
  const targets = explicit
    ? data.aps.filter((a) => bindings.some((b) => b.dataset.bindingAp === a.id))
    : selectedAPs(picked);

  const compatible = targets.every((a) =>
    (a.capabilities || [])
      .filter((c) =>
        explicit
          ? bindings.some(
              (b) =>
                b.dataset.bindingAp === a.id &&
                Number(b.dataset.bindingRadio) === c.radio_id,
            )
          : f.elements.binding_mode.value === "freq"
            ? frequencyRadioSelected(f, a, c)
            : f.elements["radio_" + c.radio_id]?.checked,
      )
      .every((c) => c.support_wpa3),
  );

  const option = [...f.elements.security.options].find(
    (o) => o.value === "wpa2-wpa3-psk",
  );
  if (option) option.disabled = !compatible;

  const mcGlobal = targets.every((a) => a.features?.multicast);
  const mcSSID = targets.every((a) => a.features?.multicast_per_ssid);
  const mcUnicast = targets.every((a) => a.features?.multicast_to_unicast);
  for (const name of [
    "mc_global",
    "mc_global_snoop",
    "mc_drop",
    "rate2",
    "rate5",
    "query_interval",
    "max_response",
    "mc_unicast",
  ]) {
    const el = f.elements[name];
    if (!el) continue;
    const ok = name === "mc_unicast" ? mcGlobal && mcUnicast : mcGlobal;
    el.disabled = !ok;
    el.closest("label").classList.toggle("hidden", !ok);
    if (!ok && el.type === "checkbox") el.checked = false;
  }
  for (const name of ["mc_snoop", "mc_query"]) {
    const el = f.elements[name];
    if (!el) continue;
    el.disabled = !mcSSID;
    el.closest("label").classList.toggle("hidden", !mcSSID);
    if (!mcSSID) el.checked = false;
  }
  $("#mc-fields").classList.toggle("hidden", !mcGlobal && !mcSSID);

  const poolOK = targets.every((a) => a.features?.vlan_pool);
  if (f.elements.vlan_pool) {
    f.elements.vlan_pool.disabled = !poolOK;
    f.elements.vlan_pool.closest("label").classList.toggle("hidden", !poolOK);
    if (!poolOK) f.elements.vlan_pool.value = "0";
  }

  const mloOK = sec !== "open" && targets.every((a) => a.features?.mlo);
  $("#mlo-check").closest("label").classList.toggle("hidden", !mloOK);
  if (!mloOK) f.elements.mlo.checked = false;

  $("#security-compat").textContent = compatible
    ? ""
    : "部分绑定设备不支持 WPA3，请调整绑定范围或使用 WPA2。";
}

function inheritedAPOptions(ap) {
  const cfg = data.config;
  const p = (cfg.ap_profiles || []).find((x) => x.ap_id === ap.id) || {};
  const t = (cfg.templates || []).find((x) => x.id === p.template_id);
  const g = (cfg.groups || []).find((x) => x.id === p.group_id);
  return { ...cfg.ap_defaults, ...t?.options, ...g?.options, ...p.options };
}

function effectiveRadioEditorRow(ap, id) {
  const inherited =
    inheritedAPOptions(ap).radios?.find((r) => r.radio_id === id) || {};
  const direct =
    (data.config.radios || []).find(
      (r) => r.ap_id === ap.id && r.radio_id === id,
    ) || {};
  return { ...inherited, ...direct };
}

function constrainedRadioCapability(ap, cap) {
  if (cap) cap = { ...cap, features: cap.control_features || cap.features };
  if (!cap || !ap.radio_linkage?.rows?.length) return cap;
  const p = ap.radio_linkage;
  const rawRegion = inheritedAPOptions(ap).region_code ?? 0;
  const region = rawRegion === 255 ? 0 : rawRegion;
  const rows = p.rows
    .filter(
      (r) =>
        r.table_mask & (1 << p.table_id) &&
        r.feature_mask & 1 &&
        (!r.regions.length || r.regions.includes(region)),
    )
    .flatMap((r) => r.radios.filter((m) => m.radio_id === cap.radio_id));
  const channels = new Set(rows.flatMap((m) => m.channels));
  const bandwidths = new Set(rows.flatMap((m) => m.bandwidths));
  return {
    ...cap,
    channels: cap.channels.filter((c) => channels.has(c)),
    bandwidths: cap.bandwidths.filter((b) => bandwidths.has(b)),
    automatic_channel: channels.has(0),
  };
}

function updateRadioDependencies() {
  const f = $("#radio-form");
  if (!f || !currentRadio?.cap) return;
  const mode = Number(f.elements.mode.value);
  const legacy = [0, 1, 2, 5].includes(mode);
  const nOnly = [3, 4, 6, 7, 10, 12].includes(mode);
  f.elements.wmm.disabled = !legacy;
  if (!legacy) f.elements.wmm.checked = true;
  f.elements.fragmentation.disabled = !legacy;
  f.elements.short_gi.disabled = legacy;
  const old = f.elements.bandwidth.value;
  const allowed = currentRadio.cap.bandwidths.filter((b) =>
    legacy ? [0, 2].includes(b) : nOnly ? [0, 1, 2].includes(b) : true,
  );
  f.elements.bandwidth.innerHTML = allowed
    .map((b) => `<option value="${b}">${esc(widths[b] || b)}</option>`)
    .join("");
  f.elements.bandwidth.value = allowed.includes(Number(old))
    ? old
    : String(allowed.includes(2) ? 2 : (allowed[0] ?? ""));
}

document.addEventListener("change", (e) => {
  if (e.target.closest("#radio-form") && e.target.name === "mode")
    updateRadioDependencies();
});

async function radioEditor(id, radio, reset = false) {
  const ap = data.aps.find((a) => a.id === id);
  const cap = constrainedRadioCapability(
    ap,
    ap?.capabilities?.find((c) => c.radio_id === radio),
  );
  if (!cap) throw Error("未收到射频能力");
  const effective = await api(
    "aps/" + encodeURIComponent(id) + "/effective-radios",
  );
  const current =
    effective.find((r) => r.radio_id === radio) ||
    effectiveRadioEditorRow(ap, radio);
  const a =
    (!reset && current.advanced) ||
    (await api(
      "radios/defaults?ap_id=" + encodeURIComponent(id) + "&radio_id=" + radio,
    ));
  const observed = ap.radio_status?.find((r) => r.radio_id === radio);
  currentRadio = { id, radio, advanced: a, cap };

  const basic = `${ap.radio_linkage ? '<div class="notice">关联射频可能随本次修改联动调整。</div>' : ""}<div class="form-grid">
    ${select("enabled", "射频状态", { "": "保持当前", on: "启用", off: "停用" }, current.enabled == null ? "" : current.enabled ? "on" : "off")}
    ${select("mode", "无线模式", Object.fromEntries(cap.modes.map((n) => [n, modes[n] || n])), a.mode)}
    ${select("bandwidth", "信道带宽", Object.fromEntries(cap.bandwidths.map((n) => [n, widths[n] || n])), a.bandwidth)}
    ${select("channel", "工作信道", { "": "保持当前", ...(cap.automatic_channel === false ? {} : { 0: "自动" }), ...Object.fromEntries(cap.channels.map((n) => [n, n])) }, current.channel ?? "")}
    ${field("power", "发射功率", current.power_dbm ?? observed?.power_dbm ?? cap.default_power_dbm, "number", `min="${cap.min_power_dbm}" max="${cap.max_power_dbm}"`, "dBm")}
    ${field("max_clients", "最大客户端数", a.max_clients, "number", `min="1" max="${cap.max_clients}"`, "台")}
    ${select("antenna", "天线选择", { 0: "内置天线" }, a.antenna)}
  </div>`;

  const timing = `<div class="form-grid">
    ${field("beacon_interval", "Beacon 周期", a.beacon_interval, "number", 'min="40" max="1000"', "ms")}
    ${field("dtim", "DTIM 周期", a.dtim, "number", 'min="1" max="255"')}
    ${field("fragmentation", "分片门限", a.fragmentation, "number", 'min="256" max="2346"')}
    ${field("rts", "RTS 门限", a.rts, "number", 'min="1" max="2346"')}
    ${ap.features?.frame_rate_control ? select("management_rate", "管理帧速率", { 1: "保持当前", ...(cap.band === "5 GHz" ? { 12: "6 Mbps", 24: "12 Mbps", 48: "24 Mbps" } : { 2: "1 Mbps", 11: "5.5 Mbps", 12: "6 Mbps", 22: "11 Mbps", 48: "24 Mbps" }) }, a.management_rate) : ""}
  </div>`;

  const boolFields = [
    ["wmm", "WMM", true],
    ["short_gi", "Short GI", true],
    ["broadcast_probe", "响应广播 Probe", true],
    ["airtime", "公平调度", ap.features?.fragmentation],
    ["rssi_restrict", "弱信号接入限制", ap.features?.rssi_control],
    ["rssi_kick", "弱信号终端剔除", ap.features?.rssi_control],
    ["downlink_mumimo", "下行 MU-MIMO", cap.features?.downlink_mumimo],
    ["uplink_mumimo", "上行 MU-MIMO", cap.features?.uplink_mumimo],
    ["downlink_ofdma", "下行 OFDMA", cap.features?.downlink_ofdma],
    ["uplink_ofdma", "上行 OFDMA", cap.features?.uplink_ofdma],
    ["twt", "TWT", cap.features?.twt],
    ["enable_6g", "6 GHz 射频", cap.features?.enable_6g],
    ["psc_6g", "6 GHz PSC", cap.features?.enable_6g],
  ];

  let performance = `<div class="switch-list">${boolFields
    .filter(([, , supported]) => supported)
    .map(([k, label]) => check(k, label, a[k]))
    .join("")}</div>
    <div class="form-grid">
      ${ap.features?.rssi_control ? field("rssi_threshold", "接入 RSSI 门限", a.rssi_threshold, "number", 'min="-100" max="0"', "dBm") + field("rssi_kick_threshold", "剔除 RSSI 门限", a.rssi_kick_threshold, "number", 'min="-100" max="0"', "dBm") : ""}
      ${ap.features?.wifi6_features ? select("gi_mode", "Wi-Fi 6 GI", { "-1": "自动", 0: "默认", 1: "1.6 μs", 2: "3.2 μs" }, a.gi_mode) : ""}
    </div>`;

  if (ap.features?.channel_optimization) {
    const d = a.dcs || {
      mode: 0,
      online: false,
      interval: 8,
      occupancy: 50,
      tolerance: 20,
      reselect: false,
    };
    performance += `<h3 class="section-title">动态信道优化</h3>
      <div class="form-grid">
        ${select("dcs_mode", "动态信道切换", { 0: "自动", 1: "手动", 2: "关闭" }, d.mode)}
        ${check("dcs_online", "在线动态优化", d.online)}
        ${field("dcs_interval", "检测周期", d.interval, "number", 'min="3" max="180"')}
        ${field("dcs_occupancy", "信道占用门限", d.occupancy, "number", 'min="1" max="100"', "%")}
        ${field("dcs_tolerance", "信道容忍度", d.tolerance, "number", 'min="1" max="100"', "%")}
        ${check("dcs_reselect", "立即重新选择信道", d.reselect)}
      </div>`;
  }
  if (ap.features?.band_steering) {
    const x = a.admission || { enabled: true, threshold: -60, difference: 6 };
    performance += `<h3 class="section-title">射频 RSSI 引导</h3>
      <div class="form-grid">
        ${check("admission_enabled", "启用射频 RSSI 引导", x.enabled)}
        ${field("admission_threshold", "接入信号门限", x.threshold, "number", 'min="-100" max="0"', "dBm")}
        ${field("admission_difference", "信号差值", x.difference, "number", 'min="0" max="100"', "dB")}
      </div>`;
  }
  if (ap.features?.edca) {
    const q = a.edca?.queues || [];
    performance += `<h3 class="section-title">EDCA 参数</h3>
      <div class="form-grid">
        ${ap.features?.edca_mode ? select("edca_mode", "EDCA 模式", { 0: "静态 EDCA", 1: "动态 EDCA" }, a.edca?.mode ?? 0) : ""}
        ${check("edca_enabled", "启用 EDCA", a.edca?.enabled)}
        ${ap.edca_presets ? select("edca_preset", "预设场景", { "": "自定义队列", ...Object.fromEntries(ap.edca_presets.scenes.map((s) => [s.id, s.name || "场景 " + s.id])) }, a.edca?.preset ?? "") : ""}
      </div>
      ${edcaQueueFields(q)}`;
  }

  openDialog(
    "radio",
    `${apName(id)} · ${cap.band}`,
    `射频 ${radio}`,
    `<form id="radio-form" novalidate>
      ${tabs([
        ["rf-basic", "基本参数"],
        ["rf-timing", "时序与门限"],
        ["rf-performance", "高级与性能"],
      ])}
      ${pane("rf-basic", basic, true)}
      ${pane("rf-timing", timing)}
      ${pane("rf-performance", performance)}
      ${formEnd("保存并下发", '<button type="button" class="btn secondary" data-radio-reset-defaults>恢复默认值</button>')}
    </form>`,
  );
  updateRadioDependencies();
}

async function submitService(f) {
  const value = (n) => f.elements[n].value;
  const num = (n) => Number(value(n));
  const checked = (n) => f.elements[n].checked;
  const security = value("security");
  const radios = [...f.querySelectorAll('[name^="radio_"]')]
    .filter((x) => x.checked)
    .map((x) => Number(x.name.slice(6)));
  const bindings =
    value("binding_mode") === "explicit"
      ? $$("[data-binding-ap]")
          .filter((x) => x.querySelector(".binding-check").checked)
          .map((x) => ({
            ap_id: x.dataset.bindingAp,
            radio_id: Number(x.dataset.bindingRadio),
            vlan: Number(x.querySelector(".binding-vlan").value),
          }))
      : [];
  if (value("binding_mode") === "explicit" && !bindings.length)
    throw Error("请选择需要绑定的 AP 射频");
  if (bindings.length)
    for (const b of bindings)
      if (!radios.includes(b.radio_id)) radios.push(b.radio_id);
  const o = {
    ...optionDefaults(currentService),
    description: value("description"),
    encoding: value("encoding"),
    isolate: checked("isolate"),
    vlan_pool: num("vlan_pool"),
    mlo: checked("mlo"),
    vlan: num("vlan"),
    auth:
      security === "wpa-psk" || security === "wpa-enterprise"
        ? 1
        : security.startsWith("wpa-wpa2") || security === "wpa2-wpa3-psk"
          ? 3
          : 2,
    cipher: security === "wpa2-wpa3-psk" ? 2 : num("cipher"),
    key_update_interval: num("key_update_interval"),
    rate_limit: {
      enabled: checked("limit_enabled"),
      mode: value("limit_mode"),
      upload_kbps: num("upload"),
      download_kbps: num("download"),
    },
    multicast: {
      configure_global: checked("mc_global"),
      global_snooping: checked("mc_global_snoop"),
      snooping: checked("mc_snoop"),
      to_unicast: checked("mc_unicast"),
      drop_unknown: checked("mc_drop"),
      rate_2g: num("rate2"),
      rate_5g: num("rate5"),
      query: checked("mc_query"),
      query_interval: num("query_interval"),
      max_response: num("max_response"),
    },
  };
  const parseMinute = (v) => {
    const m = /^(\d{1,2}):(\d{2})$/.exec(v.trim());
    if (!m || Number(m[2]) > 59 || Number(m[1]) > 24)
      throw Error("定时时段格式为 HH:MM-HH:MM");
    return Number(m[1]) * 60 + Number(m[2]);
  };
  o.schedule = {
    enabled: checked("schedule_enabled"),
    timezone: value("schedule_timezone"),
    action: value("schedule_action"),
    windows: [],
    dates: [],
  };
  for (let i = 0; i < 7; i++)
    for (const range of value("schedule_day_" + i)
      .split(",")
      .map((x) => x.trim())
      .filter(Boolean)) {
      const parts = range.split("-");
      if (parts.length !== 2) throw Error("定时时段格式为 HH:MM-HH:MM");
      o.schedule.windows.push({
        days: 1 << i,
        start_minute: parseMinute(parts[0]),
        end_minute: parseMinute(parts[1]),
      });
    }
  for (const line of value("schedule_dates")
    .split("\n")
    .map((x) => x.trim())
    .filter(Boolean)) {
    const m = /^(\d{4}-\d{2}-\d{2})\s*~\s*(\d{4}-\d{2}-\d{2})$/.exec(line);
    if (!m) throw Error("日期范围格式为 YYYY-MM-DD ~ YYYY-MM-DD");
    o.schedule.dates.push({ start: m[1], end: m[2] });
  }
  delete o.radius;
  const picked = readTargetPicker(f);
  await api("services", {
    ...(value("binding_mode") === "freq"
      ? { auto_bind_frequencies: frequencyRadioMask(f) }
      : {}),
    groups: bindings.length ? [] : picked.groups,
    id: currentService?.id || "",
    ssid: value("ssid"),
    security,
    passphrase: value("passphrase"),
    enabled: checked("enabled"),
    hidden: checked("hidden"),
    radios,
    aps: bindings.length
      ? [...new Set(bindings.map((b) => b.ap_id))]
      : picked.aps,
    bindings,
    options: o,
  });
}

async function submitRadio(f) {
  const { id, radio } = currentRadio;
  const a = structuredClone(currentRadio.advanced);
  for (const [k, v] of Object.entries(a)) {
    const el = f.elements[k];
    if (el) a[k] = typeof v === "boolean" ? el.checked : Number(el.value);
  }
  if (f.elements.dcs_mode)
    a.dcs = {
      mode: Number(f.elements.dcs_mode.value),
      online: f.elements.dcs_online.checked,
      interval: Number(f.elements.dcs_interval.value),
      occupancy: Number(f.elements.dcs_occupancy.value),
      tolerance: Number(f.elements.dcs_tolerance.value),
      reselect: f.elements.dcs_reselect.checked,
    };
  if (f.elements.admission_enabled)
    a.admission = {
      enabled: f.elements.admission_enabled.checked,
      threshold: Number(f.elements.admission_threshold.value),
      difference: Number(f.elements.admission_difference.value),
    };
  if (f.elements.edca_enabled)
    a.edca = {
      enabled: f.elements.edca_enabled.checked,
      queues: readEDCAQueues(f),
    };
  if (
    a.edca &&
    f.elements.edca_preset?.value !== undefined &&
    f.elements.edca_preset.value !== ""
  )
    a.edca.preset = Number(f.elements.edca_preset.value);
  if (a.edca && f.elements.edca_mode)
    a.edca.mode = Number(f.elements.edca_mode.value);
  const body = {
    ap_id: id,
    radio_id: radio,
    advanced: a,
    power_dbm: Number(f.elements.power.value),
  };
  if (f.elements.enabled.value)
    body.enabled = f.elements.enabled.value === "on";
  if (f.elements.channel.value !== "")
    body.channel = Number(f.elements.channel.value);
  await api("radios", body);
}

function openMobileSidebar() {
  $("#sidebar").classList.add("open");
  $("#sidebar-backdrop").classList.remove("hidden");
}

function closeMobileSidebar() {
  $("#sidebar")?.classList.remove("open");
  $("#sidebar-backdrop")?.classList.add("hidden");
}

document.addEventListener("click", async (e) => {
  if (e.target === $("#editor") || e.target === $("#drawer")) {
    closeDialogs();
    return;
  }
  const closeEl = e.target.closest("[data-close]");
  if (closeEl) {
    closeDialogs();
    return;
  }
  const b = e.target.closest("button");
  if (!b) return;
  try {
    if (b.id === "menu-toggle") {
      openMobileSidebar();
      return;
    }
    if (b.id === "sync-alert") {
      showTab("aps");
      return;
    }
    if (b.id === "new-service") {
      serviceEditor(null);
      return;
    }
    if (b.dataset.apFilter) {
      apStatusFilter = b.dataset.apFilter;
      renderContent();
      return;
    }
    if (b.dataset.clientFilter) {
      clientStateFilter = b.dataset.clientFilter;
      renderContent();
      return;
    }
    if (b.dataset.radioBand) {
      radioBandFilter = b.dataset.radioBand;
      renderContent();
      return;
    }
    if (b.dataset.newPool) poolEditor(null);
    if (b.dataset.pool)
      poolEditor(
        (data.config.vlan_pools || []).find(
          (p) => p.id === Number(b.dataset.pool),
        ),
      );
    if (b.dataset.deletePool) {
      if (!confirm("删除此 VLAN 池？")) return;
      await api("vlan-pools/" + b.dataset.deletePool, undefined, "DELETE");
      toast("已删除 VLAN 池");
      await refresh();
    }
    if (b.dataset.tab || b.dataset.view) {
      showTab(b.dataset.tab || b.dataset.view);
    }
    if (b.dataset.editorTab) {
      const scope = b.closest("form, #dialog-body, #content") || document;
      scope
        .querySelectorAll("[data-editor-tab]")
        .forEach((x) => x.classList.toggle("active", x === b));
      scope
        .querySelectorAll("[data-pane]")
        .forEach((x) =>
          x.classList.toggle("hidden", x.dataset.pane !== b.dataset.editorTab),
        );
    }
    if (b.dataset.ap) {
      currentService = b.dataset.ap;
      dialogKind = "";
      renderAPDetail(b.dataset.ap);
    }
    if (b.dataset.edit)
      serviceEditor(data.config.services.find((s) => s.id === b.dataset.edit));
    if (b.dataset.radio)
      await radioEditor(b.dataset.radioAp, Number(b.dataset.radio));
    if (b.dataset.toggle) {
      const s = data.config.services.find((s) => s.id === b.dataset.toggle);
      await api("services", {
        ...s,
        enabled: !s.enabled,
        has_password: undefined,
      });
      toast("已保存，正在下发");
      await refresh();
    }
    if (b.dataset.delete) {
      const s = data.config.services.find((s) => s.id === b.dataset.delete);
      if (confirm("删除无线服务“" + s.ssid + "”？")) {
        await api("services/" + encodeURIComponent(s.id), undefined, "DELETE");
        toast("已提交删除");
        await refresh();
      }
    }
    if (b.dataset.led || b.dataset.ledOff) {
      b.disabled = true;
      await api(
        "aps/" + encodeURIComponent(b.dataset.led || b.dataset.ledOff) + "/led",
        { on: !!b.dataset.led },
      );
      toast("LED 设置已下发");
      b.disabled = false;
    }
    if (b.dataset.readback) {
      await api(
        "aps/" + encodeURIComponent(b.dataset.readback) + "/refresh",
        {},
      );
      toast("已请求 AP 刷新上报");
    }
    if (b.dataset.label) {
      const name = prompt("AP 显示名称", apName(b.dataset.label));
      if (name !== null) {
        await api("aps/" + encodeURIComponent(b.dataset.label) + "/label", {
          name,
        });
        await refresh();
      }
    }
    if (b.dataset.interface) {
      const r = await api("interface", { name: b.dataset.interface });
      toast(r.message);
    }
  } catch (err) {
    toast(err.message);
    b.disabled = false;
  }
});

document.addEventListener("input", (e) => {
  const inline = e.target.closest("form[data-inline]");
  if (inline) inline.dataset.dirty = "1";
  if (e.target.id === "search") {
    query = e.target.value.toLowerCase();
    renderContent();
  }
  if (e.target.id === "client-search") {
    clientQuery = e.target.value.toLowerCase();
    renderContent();
  }
});

document.addEventListener("change", (e) => {
  const inline = e.target.closest("form[data-inline]");
  if (inline) inline.dataset.dirty = "1";
  if (e.target.name === "ap_group_filter") {
    apGroupFilter = e.target.value;
    renderContent();
  }
  if (e.target.name === "client_ap_filter") {
    clientAPFilter = e.target.value;
    renderContent();
  }
  if (e.target.name === "radio_ap_filter") {
    radioAPFilter = e.target.value;
    renderContent();
  }
  if (e.target.closest("#service-form")) {
    const form = e.target.closest("#service-form");
    const presets = serviceFrequencyPresets;
    if (e.target.name === "band_preset") {
      const mask = presets[e.target.value];
      if (mask != null) {
        for (const box of form.querySelectorAll(
          'input[name="auto_bind_frequencies"]',
        ))
          box.checked = !!(mask & Number(box.value));
      } else {
        form.querySelector(".frequency-ranks").open = true;
      }
    }
    if (e.target.name === "auto_bind_frequencies") {
      const mask = frequencyRadioMask(form);
      form.elements.band_preset.value =
        Object.keys(presets).find((key) => presets[key] === mask) || "custom";
    }
    updateSecurity();
  }
});

document.addEventListener("submit", async (e) => {
  const f = e.target;
  if (
    ![
      "service-form",
      "radio-form",
      "pool-form",
      "band-navigation-form",
    ].includes(f.id)
  )
    return;
  e.preventDefault();
  const invalid = f.querySelector(":invalid");
  if (invalid) {
    const section = invalid.closest("[data-pane]");
    if (section) {
      const b = f.querySelector(
        '[data-editor-tab="' + section.dataset.pane + '"]',
      );
      b?.click();
    }
    invalid.reportValidity();
    return;
  }
  const btn = f.querySelector("[type=submit]");
  btn.disabled = true;
  try {
    if (f.id === "service-form") await submitService(f);
    else if (f.id === "band-navigation-form")
      await api("band-navigation", {
        enabled: f.elements.band_enabled.checked,
        threshold_5g: Number(f.elements.band_threshold.value),
        difference: Number(f.elements.band_difference.value),
        max_failures: Number(f.elements.band_failures.value),
      });
    else if (f.id === "pool-form")
      await api("vlan-pools", {
        id: Number(f.elements.pool_id.value),
        name: f.elements.pool_name.value,
        vlans: f.elements.pool_vlans.value,
      });
    else await submitRadio(f);
    delete f.dataset.dirty;
    if ($("#editor").open) {
      $("#editor").close();
      dialogKind = "";
    }
    toast("配置已保存，正在同步到 AP");
    await refresh();
  } catch (err) {
    const errEl = f.querySelector("#form-error");
    if (errEl) errEl.textContent = err.message;
    else toast(err.message);
  } finally {
    btn.disabled = false;
  }
});

$("#sidebar-backdrop").onclick = closeMobileSidebar;
$("#close-dialog").onclick = closeDialogs;
$("#close-drawer").onclick = closeDialogs;
$("#editor").addEventListener("close", () => {
  $("#dialog-body").innerHTML = "";
  if (!$("#drawer").open) dialogKind = "";
});
$("#drawer").addEventListener("close", () => {
  $("#drawer-body").innerHTML = "";
  if (!$("#editor").open) dialogKind = "";
});
$("#refresh").onclick = refresh;

window.addEventListener("hashchange", () => {
  if (location.hash.slice(1) !== tab) showTab(location.hash.slice(1));
});

initializeNavigation();
showTab(location.hash.slice(1) || "overview");

setInterval(() => {
  if (!document.hidden) void refresh();
}, 4000);

document.addEventListener("visibilitychange", () => {
  if (!document.hidden) void refresh();
});

document.addEventListener("click", async (e) => {
  if (!e.target.closest("[data-radio-reset-defaults]")) return;
  try {
    await radioEditor(currentRadio.id, currentRadio.radio, true);
  } catch (err) {
    toast(err.message);
  }
});
