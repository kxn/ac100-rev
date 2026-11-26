"use strict";
const $ = (s) => document.querySelector(s),
  $$ = (s) => [...document.querySelectorAll(s)],
  esc = (s) =>
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
  },
  tab = "overview",
  query = "",
  dialogKind = "",
  currentService = null,
  currentRadio = null,
  refreshing = false,
  interfaces = [],
  refreshAgain = false;

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
// Preserve the existing draft frequency mask; the shortcut only selects its bits.
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
  mlo: "MLO 无线服务",
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
  ssid_rate_limit: "无线服务限速",
  new_security_format: "新版无线安全协议",
  frame_rate_control: "管理帧速率",
  edca: "EDCA 队列",
  wifi6_features: "Wi-Fi 6 性能控制",
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
  $("#toast").textContent = s;
  $("#toast").classList.remove("hidden");
  clearTimeout(toast.timer);
  toast.timer = setTimeout(() => $("#toast").classList.add("hidden"), 5000);
}
function ago(t) {
  const n = Math.floor((Date.now() - Date.parse(t)) / 1000);
  return !Number.isFinite(n) || n > 1e8
    ? "未上报"
    : n < 5
      ? "刚刚"
      : n < 60
        ? n + " 秒前"
        : n < 3600
          ? Math.floor(n / 60) + " 分钟前"
          : Math.floor(n / 3600) + " 小时前";
}
function apName(id) {
  return data.aps.find((a) => a.id === id)?.name || id || "未上报";
}
function metric(v) {
  if (Array.isArray(v)) return metric(v.at(-1));
  return v == null ? "—" : v;
}
function table(headers, rows) {
  return `<div class="table-wrap"><table><thead><tr>${headers.map((x) => `<th>${x}</th>`).join("")}</tr></thead><tbody>${rows || `<tr><td class="empty" colspan="${headers.length}">暂无记录</td></tr>`}</tbody></table></div>`;
}
function panel(title, description, body, tools = "") {
  return `<div class="panel"><div class="panel-heading"><div><h2>${title}</h2><p>${description}</p></div>${tools}</div>${body}</div>`;
}
function statePill(state) {
  const info = {
    not_applicable: ["offline", "本设备不适用"],
    idle: ["offline", "未开始"],
    collecting: ["pending", "测量中"],
    planning: ["pending", "正在计算"],
    completed: ["online", "已完成"],
    uncertain: ["failed", "结果未确认"],
    timed_out: ["failed", "等待超时"],
    stopped: ["offline", "已停止"],
    waiting_report: ["pending", "等待节点报告"],
    sending: ["pending", "正在发送"],
    interrupted: ["failed", "已中断"],
    queued: ["pending", "等待执行"],
    transferring: ["pending", "正在传输"],
    verifying: ["pending", "校验中"],
    waiting_reconnect: ["pending", "等待重新接入"],
    cancelled: ["offline", "已取消"],
    verified: ["online", "配置回读一致"],
    acknowledged: ["online", "设备已应答"],
    applying: ["pending", "正在下发"],
    failed: ["failed", "下发失败"],
    blocked: ["failed", "配置受阻"],
    failed_recovered: ["failed", "配置失败，射频已恢复"],
  };
  const [cl, label] = info[state] || ["pending", "等待同步"];
  return `<span class="pill ${cl}">${label}</span>`;
}
function serviceStates(s) {
  const states = data.apply.filter((x) => x.service_id === s.id),
    bad = states.find((x) =>
      ["failed", "failed_recovered", "blocked"].includes(x.state),
    ),
    pending = states.find((x) => x.state === "applying");
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
function showTab(next) {
  tab = names[next] ? next : "overview";
  location.hash = tab;
  query = "";
  updateNavigation();
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

function render() {
  const inventory = data.aps.filter(
      (a) => !data.config.retired_aps?.includes(a.id),
    ),
    online = inventory.filter((a) => a.online).length,
    clients = data.clients.filter((c) => c.state === "connected");
  $("#online").textContent = online;
  $("#total-ap").textContent =
    `${inventory.length} 台已发现 · ${inventory.length - online} 台离线`;
  $("#client-count").textContent = clients.length;
  $("#service-count").textContent = data.config.services.filter(
    (s) => s.enabled && !s.deleting,
  ).length;
  $("#service-summary").textContent =
    `共 ${data.config.services.filter((s) => !s.deleting).length} 项无线服务`;
  const bad = data.apply.filter((a) =>
      ["failed", "failed_recovered", "blocked"].includes(a.state),
    ).length,
    pending = data.apply.filter((a) => a.state === "applying").length;
  $("#pending-count").textContent =
    bad ||
    pending ||
    (!online && data.config.services.some((s) => s.enabled)
      ? "等待 AP"
      : "正常");
  $("#apply-summary").textContent = bad
    ? `${bad} 项配置需处理，请查看设备同步结果`
    : pending
      ? `${pending} 项配置正在下发`
      : !online
        ? "等待设备上线并确认配置"
        : "当前配置均无失败记录";
  renderContent(true);
}
function renderClients() {
  return (
    '<div class="toolbar"><a class="secondary" href="/api/clients/export" download>导出客户端 CSV</a></div>' +
    panel(
      "无线客户端",
      "连接、信号和运行信息来自 AP 上报，未上报的字段显示为 —。",
      table(
        [
          "客户端",
          "连接状态",
          "所在 AP",
          "SSID / 射频",
          "信号",
          "IP 地址",
          "协商 / 实时速率",
          "最近上报",
        ],
        data.clients
          .map((c) => {
            const a = data.aps.find((a) => a.id === c.ap_id),
              v = a?.wireless_telemetry?.vaps?.find(
                (v) => v.radioId === c.radio_id,
              ),
              s = data.config.services.find(
                (s) =>
                  Number(data.assignments?.[c.ap_id]?.[s.id]?.[c.radio_id]) ===
                  c.wlan_id,
              );
            return `<tr><td class="mono">${esc(c.name || c.device?.device_name || c.device?.hostname || c.mac)}<small>${esc(c.note || c.mac)}</small><small>${esc([c.device?.brand, c.device?.system].filter(Boolean).join(" · "))}</small><button class="text-button" data-client-label="${esc(c.mac)}">编辑</button><button class="text-button" data-client-history="${esc(c.mac)}">信号记录</button><button class="text-button" data-client-disconnect="${esc(c.mac)}" ${c.state === "connected" ? "" : "disabled"}>下线</button></td><td><span class="pill ${c.state === "connected" ? "online" : ""}">${esc({ connected: "已连接", disconnected: "已离线", observed: "已上报", ap_offline: "AP 离线" }[c.state] || c.state)}</span></td><td>${esc(apName(c.ap_id))}</td><td>${esc(c.ssid || (c.state === "connected" ? s?.ssid || v?.ssidName : "") || "—")}<small>射频 ${c.radio_id || "—"} · WLAN ${c.wlan_id || "—"} · VLAN ${c.vlan_id ?? "—"}</small></td><td>${c.rssi_dbm == null ? "—" : esc(c.rssi_dbm) + " dBm"}</td><td>${esc(c.ip || "—")}</td><td>${c.statistics ? esc(c.statistics.negotiated_mbps) + " Mbps" : "—"}<small>↑ ${c.statistics?.upstream_kbps ?? "—"} / ↓ ${c.statistics?.downstream_kbps ?? "—"} kbps</small>${(c.radio_entries || []).map((r) => `<small>MLO 射频 ${esc(r.radio_id)} · ${r.statistics ? esc(r.statistics.negotiated_mbps) + " Mbps" : "—"} · ${r.rssi_dbm == null ? "—" : esc(r.rssi_dbm) + " dBm"}</small>`).join("")}</td><td>${ago(c.last_seen)}</td></tr>`;
          })
          .join(""),
      ),
    )
  );
}
function renderInterfaces() {
  return panel(
    "控制通信接口",
    "绑定接口的修改在程序下次启动时生效。",
    interfaces
      .map(
        (i) =>
          `<div class="interface-row"><div><strong>${esc(i.name)}</strong> <span class="pill ${i.bound ? "online" : ""}">${i.bound ? "当前绑定" : i.up ? "已启用" : "未启用"}</span><p>${esc(i.addresses.join(" · ") || "未配置地址")}</p></div><button class="secondary" data-interface="${esc(i.name)}" ${i.bound ? "disabled" : ""}>绑定此接口</button></div>`,
      )
      .join("") || '<div class="empty">读取接口中…</div>',
  );
}
function renderContent(background = false) {
  if (
    background &&
    $("#content").contains(document.activeElement) &&
    ["INPUT", "SELECT", "TEXTAREA"].includes(document.activeElement.tagName)
  )
    return;
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
    rates: renderRates,
    edca: renderEDCA,
    mobility: () => renderMobility("mobility"),
    balance: () => renderMobility("balance"),
    band: renderBandNavigation,
    rrm: renderRRM,
    clients: renderClients,
    history: renderHistory,
    protection: renderProtection,
    upgrades: renderUpgrades,
    interfaces: renderInterfaces,
    resources: renderControllerResources,
    backup: renderBackup,
  };
  const focused = $("#search") === document.activeElement,
    pos = focused ? $("#search").selectionStart : 0;
  $("#content").innerHTML = (renderers[tab] || renderOverview)();
  if (tab === "mesh") loadMeshJobs();
  if (focused && $("#search")) {
    $("#search").focus();
    $("#search").setSelectionRange(pos, pos);
  }
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
    if (tab === "interfaces") interfaces = await api("interfaces");
    if (tab === "resources")
      controllerResources = await api("controller/resources");
    if (["mobility", "balance"].includes(tab))
      mobilityStatus = await api("mobility/status");
    if (tab === "upgrades") upgradeData = await api("upgrades");
    if (tab === "history") {
      const q = new URLSearchParams({ limit: "1440" });
      if (historyAP) q.set("ap", historyAP);
      if (historyRadio) q.set("radio", historyRadio);
      historyData = await api("history?" + q);
    }
    render();
    $("#sync").textContent = "更新于 " + new Date().toLocaleTimeString("zh-CN");
    $("#connection").textContent = "控制器已连接";
    if (dialogKind === "ap") {
      const details = [...$("#dialog-body").querySelectorAll("details")];
      const open = details.map((d) => d.open);
      const scroll = $("#editor").scrollTop;
      renderAPDetail(currentService);
      $("#dialog-body")
        .querySelectorAll("details")
        .forEach((d, i) => {
          d.open = open[i] || false;
        });
      $("#editor").scrollTop = scroll;
    }
  } catch (e) {
    $("#connection").textContent = "控制器连接中断";
    $("#sync").textContent = e.message;
  } finally {
    refreshing = false;
    if (refreshAgain) {
      refreshAgain = false;
      void refresh();
    }
  }
}
function openDialog(kind, title, caption, body) {
  dialogKind = kind;
  $("#dialog-title").textContent = title;
  $("#dialog-caption").textContent = caption;
  $("#dialog-body").innerHTML = body;
  if (!$("#editor").open) $("#editor").showModal();
}
function tabs(items) {
  return `<div class="editor-tabs">${items.map(([id, label], i) => `<button type="button" data-editor-tab="${id}" class="${i ? "" : "active"}">${label}</button>`).join("")}</div>`;
}
function pane(id, body, first = false) {
  return `<section data-pane="${id}" class="${first ? "" : "hidden"}">${body}</section>`;
}
function field(name, label, value, type = "number", extra = "") {
  return `<label>${label}<input name="${name}" type="${type}" value="${esc(value)}" ${extra}></label>`;
}
function select(name, label, values, value) {
  return `<label>${label}<select name="${name}">${Object.entries(values)
    .map(
      ([v, l]) =>
        `<option value="${esc(v)}" ${String(v) === String(value) ? "selected" : ""}>${esc(l)}</option>`,
    )
    .join("")}</select></label>`;
}
function check(name, label, value, extra = "") {
  return `<label class="check"><input type="checkbox" name="${name}" ${value ? "checked" : ""} ${extra}>${label}</label>`;
}
function formEnd(label = "保存并下发") {
  return `<div class="form-footer"><span class="form-error" id="form-error" role="status"></span><button class="primary" type="submit">${label}</button></div>`;
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
      ?.name || "未使用模板";
  const settings = data.apply.filter((s) => s.ap_id === id);
  const body = `<div class="device-context"><strong>${esc(ap.model || "AP")}</strong><span class="pill ${ap.online ? "online" : ""}">${ap.online ? "在线" : "离线"}</span><p>${esc(ap.local_ip || ap.address)} · ${esc(ap.mac)}</p></div>
 <section class="device-section"><h3>配置此 AP</h3><p>分组：${esc(group)}　模板：${esc(template)}</p><div class="actions"><button class="primary" data-ap-settings="${esc(id)}">AP 参数与所属分组</button><button class="secondary" data-ap-copy="${esc(id)}">复制配置到其它 AP</button>${!ap.online ? `<button class="secondary" data-ap-replace="${esc(id)}">替换此 AP</button>` : ""}</div><p class="help">参数按全局默认 → 模板 → 分组 → 单台 AP 的顺序覆盖。</p></section>
 <section class="device-section"><h3>射频设置</h3>${table(["频段", "射频", "操作"], (ap.capabilities || []).map((c) => `<tr><td>${esc(c.band)}</td><td>${c.radio_id}</td><td><button class="text-button" data-radio="${c.radio_id}" data-radio-ap="${esc(id)}">配置射频</button></td></tr>`).join(""))}</section>
 <section class="device-section"><h3>实际广播的无线服务</h3>${table(["无线名称", "射频 / 带宽", "BSSID"], (ap.wireless_telemetry?.vaps || []).map((v) => `<tr><td>${esc(v.ssidName)}</td><td>射频 ${v.radioId} · ${esc(v.bw)} MHz</td><td class="mono">${esc(v.bssid)}</td></tr>`).join(""))}</section>
 <details class="advanced-section"><summary>配置同步结果</summary>${table(["配置项目", "结果", "说明"], settings.map((item) => `<tr><td>${esc(configurationItemName(item.service_id))}</td><td>${statePill(item.state)}</td><td>${esc(item.error || "")}</td></tr>`).join(""))}</details>
 <details class="advanced-section"><summary>设备信息与能力</summary><dl class="detail-grid"><div><dt>硬件版本</dt><dd>${esc(ap.hardware_version || "—")}</dd></div><div><dt>软件版本</dt><dd>${esc(ap.software_version || ap.wireless_telemetry?.software_version || "—")}</dd></div><div><dt>序列号</dt><dd>${esc(ap.serial || "—")}</dd></div></dl><div class="chips">${Object.entries(
   ap.features || {},
 )
   .filter(([, enabled]) => enabled)
   .map(([key]) => `<span class="chip">${esc(featureNames[key] || key)}</span>`)
   .join(
     "",
   )}</div><details><summary>原始能力上报</summary><pre class="raw">${esc(JSON.stringify({ general: ap.general_capabilities, sub: ap.sub_capabilities, radios: ap.capabilities }, null, 2))}</pre></details></details>
 <details class="advanced-section"><summary>设备维护操作</summary><div class="actions"><button class="secondary" data-label="${esc(id)}">修改名称</button><button class="secondary" data-led="${esc(id)}" ${ap.online ? "" : "disabled"}>打开 LED</button><button class="secondary" data-led-off="${esc(id)}" ${ap.online ? "" : "disabled"}>关闭 LED</button><button class="secondary" data-readback="${esc(id)}" ${ap.online ? "" : "disabled"}>重新读取状态</button><button class="secondary" data-ap-action="reboot" data-action-ap="${esc(id)}" ${ap.online ? "" : "disabled"}>重启 AP</button><button class="secondary danger" data-ap-action="factory-reset" data-action-ap="${esc(id)}" ${ap.online ? "" : "disabled"}>恢复 AP 出厂</button></div></details>`;
  if (dialogKind === "ap" && $("#editor").open) {
    $("#dialog-body").innerHTML = body;
    return;
  }
  currentService = id;
  openDialog("ap", apName(id), "AP 管理 / 状态与操作", body);
}
function configurationItemName(id) {
  const labels = {
    "ap-settings": "AP 参数",
    rates: "速率表",
    roaming: "无缝漫游",
    balance: "负载均衡",
    "roaming-mode": "漫游网络模式",
    "roaming-result": "漫游候选下发",
    "band-navigation": "双频优选",
    reporting: "设备状态上报",
    "wireless-reporting": "无线状态上报",
    protection: "AP 网络防护",
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
  const o = optionDefaults(s),
    l = o.rate_limit || {
      enabled: false,
      mode: "client",
      upload_kbps: 1000,
      download_kbps: 1000,
    },
    m = o.multicast || {
      snooping: true,
      to_unicast: true,
      drop_unknown: false,
      rate_2g: 1,
      rate_5g: 6,
      query: false,
      query_interval: 60,
      max_response: 10,
    },
    radios = [
      ...new Set([
        1,
        2,
        ...data.aps.flatMap((a) =>
          (a.capabilities || []).map((c) => c.radio_id),
        ),
      ]),
    ];
  const basics = `<div class="form-grid">${field("ssid", "无线名称（SSID）", s?.ssid || "", "text", 'required maxlength="96"')}${check("enabled", "启用此无线服务", s?.enabled ?? true)}</div>`;
  const security = `<div class="form-grid">${select("security", "安全方式", securityNames, s?.security || "wpa2-psk")}<label id="password-field">无线密码<input name="passphrase" type="password" autocomplete="new-password" placeholder="${s?.has_password ? "已设置，留空保留原密码" : "填写 8–63 个字符"}"></label></div><p class="help" id="security-compat">安全方式按所选 AP 和频段的能力显示。</p><details class="advanced-section"><summary>更多无线参数</summary><div class="form-grid">${select("encoding", "SSID 编码", { "utf-8": "UTF-8", gbk: "GBK" }, o.encoding)}${select("cipher", "加密算法", { 2: "AES", 1: "TKIP", 0: "自动" }, o.cipher)}${field("key_update_interval", "组密钥更新周期（秒）", o.key_update_interval, "number", 'min="0" max="604800"')}<label class="full">服务描述<textarea name="description" maxlength="150" rows="2">${esc(o.description)}</textarea></label></div><div class="switch-list">${check("hidden", "隐藏无线名称", s?.hidden)}${check("isolate", "无线终端隔离", o.isolate)}${check("mlo", "启用 MLO 多链路无线服务", o.mlo, 'id="mlo-check"')}</div></details>`;
  const frequencyMask = s?.auto_bind_frequencies ?? 32639;
  const frequencyPresets = serviceFrequencyPresets;
  const frequencyPreset =
    Object.keys(frequencyPresets).find(
      (key) => frequencyPresets[key] === frequencyMask,
    ) || "custom";
  const binds = `<div class="notice">先选择 AP 或分组，再选择广播频段。AP 和分组均留空时，应用到全部 AP（含后续接入）。</div><div class="form-grid"><label>应用 AP<select name="aps" multiple size="4"><option value="" ${s?.aps?.length ? "" : "selected"}>不单独指定 AP</option>${data.aps.map((ap) => `<option value="${esc(ap.id)}" ${s?.aps?.includes(ap.id) ? "selected" : ""}>${esc(apName(ap.id))}</option>`).join("")}</select></label><label>应用 AP 分组<select name="groups" multiple size="4">${(data.config.groups || []).map((group) => `<option value="${esc(group.id)}" ${s?.groups?.includes(group.id) ? "selected" : ""}>${esc(group.name)}</option>`).join("")}</select><small>与所选 AP 合并应用。</small></label>${select("binding_mode", "频段绑定方式", { freq: "按频段自动绑定", auto: "按射频编号绑定", explicit: "逐台选择 AP / 射频" }, s?.bindings?.length ? "explicit" : s ? (s.auto_bind_frequencies != null ? "freq" : "auto") : "freq")}<fieldset class="full"><legend>广播频段</legend>${select("band_preset", "使用频段", { dual: "2.4 GHz 和 5 GHz（双频）", band2: "仅 2.4 GHz", band5: "仅 5 GHz", custom: "按同频段射频序号自定义" }, frequencyPreset)}<details class="frequency-ranks" ${frequencyPreset === "custom" ? "open" : ""}><summary>多射频 AP：精确选择频段序号</summary><label>频段与序号（可多选）<select name="auto_bind_frequencies" multiple size="6">${Array.from({ length: 16 }, (_, i) => `<option value="${2 ** i}" ${(s?.auto_bind_frequencies ?? 32639) & (2 ** i) ? "selected" : ""}>${i < 8 ? "2.4 GHz" : "5 GHz"} · 第 ${(i % 8) + 1} 路</option>`).join("")}</select></label><p class="help">普通双频 AP 使用各频段第 1 路；多射频 AP 可选择同频段的其它路。默认勾选适用于后续接入的多射频设备。</p></details></fieldset><fieldset class="full"><legend>按射频编号绑定</legend><div class="switch-list">${radios.map((n) => check("radio_" + n, "射频 " + n, s ? s.radios.includes(n) : n <= 2)).join("")}</div></fieldset></div><details class="advanced-section" ${s?.bindings?.length || o.vlan || o.vlan_pool ? "open" : ""}><summary>VLAN 与精确射频绑定</summary><div class="form-grid">${field("vlan", "默认 VLAN ID（0 为不打标签）", o.vlan, "number", 'min="0" max="4094"')}${select("vlan_pool", "VLAN 池（需设备支持）", { 0: "不使用 VLAN 池", ...Object.fromEntries((data.config.vlan_pools || []).filter((p) => !p.deleting).map((p) => [p.id, p.name + " · " + p.vlans])) }, o.vlan_pool || 0)}</div><h3 class="section-title">精确选择 AP / 射频</h3><div class="table-wrap"><table class="binding-table"><thead><tr><th>使用</th><th>AP / 频段</th><th>VLAN ID</th><th>设备能力</th></tr></thead><tbody>${data.aps
    .flatMap((ap) =>
      (ap.capabilities || [])
        .filter((c) => c.function_type !== 1)
        .map((c) => {
          const bound = s?.bindings?.find(
            (b) => b.ap_id === ap.id && b.radio_id === c.radio_id,
          );
          return `<tr data-binding-ap="${esc(ap.id)}" data-binding-radio="${c.radio_id}"><td><input aria-label="绑定 ${esc(apName(ap.id))} 射频 ${c.radio_id}" type="checkbox" class="binding-check" ${bound ? "checked" : ""}></td><td>${esc(apName(ap.id))}<small>${esc(c.band)} · 射频 ${c.radio_id}</small></td><td><input class="binding-vlan" aria-label="VLAN ID" type="number" min="0" max="4094" value="${bound?.vlan ?? o.vlan}"></td><td>${c.support_wpa3 ? "WPA3 · " : ""}最多 ${c.max_ssid} 个无线服务</td></tr>`;
        }),
    )
    .join("")}</tbody></table></div></details>`;
  const qos = `<fieldset><legend>无线限速</legend><div class="form-grid">${check("limit_enabled", "启用无线限速", l.enabled)}${select("limit_mode", "限速对象", { client: "每个无线终端", ssid: "整个无线服务" }, l.mode)}${field("upload", "上行速率（kbps）", l.upload_kbps, "number", 'min="8" max="8000000" step="8"')}${field("download", "下行速率（kbps）", l.download_kbps, "number", 'min="8" max="8000000" step="8"')}</div><p class="help">每台设备单独执行限速；速率为 8 的倍数。</p></fieldset><h3 class="section-title">组播管理</h3><div id="mc-fields" class="form-grid">${check("mc_global", "同时配置 AP 全局组播参数", m.configure_global)}${check("mc_global_snoop", "AP 全局 IGMP Snooping", m.global_snooping)}<div class="switch-list full">${check("mc_snoop", "IGMP Snooping", m.snooping)}${check("mc_unicast", "组播转单播", m.to_unicast)}${check("mc_drop", "丢弃未知组播", m.drop_unknown)}${check("mc_query", "启用 IGMP 查询", m.query)}</div>${select("rate2", "2.4 GHz 组播速率（Mbps）", Object.fromEntries([1, 2, 5, 6, 9, 11, 12, 18, 24, 36, 48, 54].map((n) => [n, n])), m.rate_2g)}${select("rate5", "5 GHz 组播速率（Mbps）", Object.fromEntries([6, 9, 12, 18, 24, 36, 48, 54].map((n) => [n, n])), m.rate_5g)}${field("query_interval", "查询周期（秒）", m.query_interval, "number", 'min="1" max="65535"')}${field("max_response", "最大响应时间（秒）", m.max_response, "number", 'min="1" max="255"')}</div><p class="help">组播处理与查询周期是 AP 级参数；共享同一 AP 的服务应使用相同设置。</p>`;
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
  const scheduleBody = `<div class="notice">控制器按指定时区启停服务。多个时段用英文逗号分隔，例如 08:00-12:00,13:00-18:00；24:00 表示当天结束。未填写日期范围时每周重复。</div><div class="form-grid">${check("schedule_enabled", "启用无线服务定时", schedule.enabled)}${select("schedule_action", "时段内的行为", { on: "时段内启用，其余时间停用", off: "时段内停用，其余时间启用" }, schedule.action)}${field("schedule_timezone", "规则时区", schedule.timezone, "text")}<label class="full">限制日期范围（可选，每行一个范围）<textarea name="schedule_dates" rows="2" placeholder="2026-12-01 ~ 2026-12-31">${esc((schedule.dates || []).map((d) => d.start + " ~ " + d.end).join("\n"))}</textarea></label></div><h3 class="section-title">每周时段</h3><div class="form-grid">${[
    "星期一",
    "星期二",
    "星期三",
    "星期四",
    "星期五",
    "星期六",
    "星期日",
  ]
    .map((day, i) =>
      field(
        "schedule_day_" + i,
        day,
        schedule.windows
          .filter((w) => w.days & (1 << i))
          .map((w) => clock(w.start_minute) + "-" + clock(w.end_minute))
          .join(","),
        "text",
        'placeholder="08:00-18:00"',
      ),
    )
    .join("")}</div>`;
  openDialog(
    "service",
    s ? "配置 " + s.ssid : "新建无线服务",
    "无线服务 / 名称与密码 → 应用 AP 与频段",
    `<form id="service-form" novalidate>${tabs([
      ["basic", "名称与安全"],
      ["binding", "AP 与频段"],
      ["qos", "高级策略"],
      ["schedule", "无线定时"],
    ])}${pane("basic", basics + security, true)}${pane("binding", binds)}${pane("qos", qos)}${pane("schedule", scheduleBody)}${formEnd()}</form>`,
  );
  updateSecurity();
}
function bandNavigationEditor() {
  const b = data.config.band_navigation || {
    enabled: false,
    threshold_5g: 20,
    difference: 4,
    max_failures: 10,
  };
  openDialog(
    "band-navigation",
    "双频优选",
    "BAND NAVIGATION",
    `<form id="band-navigation-form" novalidate><div class="notice">双频需使用相同 SSID 和安全配置。客户端是否切换需通过实际连接频段确认；这与多 AP 漫游分别配置。</div><div class="form-grid">${check("band_enabled", "启用 5 GHz 优先引导", b.enabled)}${field("band_threshold", "5 GHz 客户端数量门限", b.threshold_5g, "number", 'required min="2" max="40"')}${field("band_difference", "频段客户端数量差值", b.difference, "number", 'required min="1" max="8"')}${field("band_failures", "最大引导失败次数", b.max_failures, "number", 'required min="0" max="100"')}</div>${formEnd()}</form>`,
  );
}
function poolEditor(p) {
  openDialog(
    "pool",
    p ? "编辑 VLAN 池" : "新建 VLAN 池",
    "VLAN POOL",
    `<form id="pool-form" novalidate><div class="form-grid">${field("pool_id", "编号", p?.id || 1, "number", 'required min="1" max="255" ' + (p ? "readonly" : ""))}${field("pool_name", "名称", p?.name || "", "text", 'required maxlength="64"')}<label class="full">VLAN 列表<input name="pool_vlans" required value="${esc(p?.vlans || "")}" placeholder="例如 100-110,200,300-310"></label></div><p class="help">绑定此池时固定 VLAN ID 须设为 0。删除前须先解除无线服务绑定。</p>${formEnd()}</form>`,
  );
}
function frequencyRadioBits(ap) {
  const caps = [...(ap.capabilities || [])].sort(
      (a, b) => a.radio_id - b.radio_id,
    ),
    out = {};
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
function frequencyRadioSelected(f, ap, c) {
  const mask = [...f.elements.auto_bind_frequencies.selectedOptions].reduce(
    (n, o) => n | Number(o.value),
    0,
  );
  return !!(mask & (frequencyRadioBits(ap)[c.radio_id] || 0));
}
function updateBindingMode(f) {
  const mode = f.elements.binding_mode.value;
  f.elements.auto_bind_frequencies
    .closest("fieldset")
    .classList.toggle("hidden", mode !== "freq");
  const radio = f.querySelector('[name^="radio_"]');
  if (radio)
    radio.closest("fieldset").classList.toggle("hidden", mode !== "auto");
  const table = f.querySelector(".binding-table")?.closest(".table-wrap");
  if (table) {
    table.classList.toggle("hidden", mode !== "explicit");
    if (mode === "explicit") table.closest("details").open = true;
    table.previousElementSibling?.classList.toggle(
      "hidden",
      mode !== "explicit",
    );
  }
}
function updateSecurity() {
  const f = $("#service-form");
  if (!f) return;
  updateBindingMode(f);
  const sec = f.elements.security.value;
  $("#password-field").classList.toggle("hidden", sec === "open");
  f.elements.cipher.disabled = sec === "wpa2-wpa3-psk";
  if (sec === "wpa2-wpa3-psk") f.elements.cipher.value = "2";
  const aps = [...f.elements.aps.selectedOptions]
      .map((o) => o.value)
      .filter(Boolean),
    bindings = [...f.querySelectorAll("[data-binding-ap]")].filter(
      (x) => x.querySelector(".binding-check").checked,
    ),
    explicit = f.elements.binding_mode.value === "explicit",
    targets = explicit
      ? data.aps.filter((a) =>
          bindings.some((b) => b.dataset.bindingAp === a.id),
        )
      : selectedAPs({
          aps,
          groups: [...f.elements.groups.selectedOptions].map((x) => x.value),
        }),
    compatible = targets.every((a) =>
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
  option.disabled = !compatible;
  const mcGlobal = targets.every((a) => a.features?.multicast),
    mcSSID = targets.every((a) => a.features?.multicast_per_ssid),
    mcUnicast = targets.every((a) => a.features?.multicast_to_unicast);
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
    const el = f.elements[name],
      ok = name === "mc_unicast" ? mcGlobal && mcUnicast : mcGlobal;
    el.disabled = !ok;
    el.closest("label").classList.toggle("hidden", !ok);
    if (!ok && el.type === "checkbox") el.checked = false;
  }
  for (const name of ["mc_snoop", "mc_query"]) {
    const el = f.elements[name];
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
    ? "绑定设备上报支持 WPA3，可配置 WPA2/WPA3 混合或传统 WPA/WPA2。"
    : "部分绑定设备未声明支持 WPA3，请调整设备绑定或使用 WPA/WPA2。";
}
function inheritedAPOptions(ap) {
  const cfg = data.config,
    p = (cfg.ap_profiles || []).find((p) => p.ap_id === ap.id) || {},
    t = (cfg.templates || []).find((t) => t.id === p.template_id),
    g = (cfg.groups || []).find((g) => g.id === p.group_id);
  return { ...cfg.ap_defaults, ...t?.options, ...g?.options, ...p.options };
}
function effectiveRadioEditorRow(ap, id) {
  const inherited =
      inheritedAPOptions(ap).radios?.find((r) => r.radio_id === id) || {},
    direct =
      (data.config.radios || []).find(
        (r) => r.ap_id === ap.id && r.radio_id === id,
      ) || {};
  return { ...inherited, ...direct };
}
function constrainedRadioCapability(ap, cap) {
  if (cap) cap = { ...cap, features: cap.control_features || cap.features };
  if (!cap || !ap.radio_linkage?.rows?.length) return cap;
  const p = ap.radio_linkage,
    rawRegion = inheritedAPOptions(ap).region_code ?? 0,
    region = rawRegion === 255 ? 0 : rawRegion,
    rows = p.rows
      .filter(
        (r) =>
          r.table_mask & (1 << p.table_id) &&
          r.feature_mask & 1 &&
          (!r.regions.length || r.regions.includes(region)),
      )
      .flatMap((r) => r.radios.filter((m) => m.radio_id === cap.radio_id)),
    channels = new Set(rows.flatMap((m) => m.channels)),
    bandwidths = new Set(rows.flatMap((m) => m.bandwidths));
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
  const mode = Number(f.elements.mode.value),
    legacy = [0, 1, 2, 5].includes(mode),
    nOnly = [3, 4, 6, 7, 10, 12].includes(mode);
  f.elements.wmm.disabled = !legacy;
  if (!legacy) f.elements.wmm.checked = true;
  f.elements.wmm.title = legacy ? "" : "当前模式要求启用 WMM";
  f.elements.fragmentation.disabled = !legacy;
  f.elements.fragmentation.title = legacy ? "" : "当前无线模式不使用此分片门限";
  f.elements.short_gi.disabled = legacy;
  const old = f.elements.bandwidth.value,
    allowed = currentRadio.cap.bandwidths.filter((b) =>
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
  const ap = data.aps.find((a) => a.id === id),
    cap = constrainedRadioCapability(
      ap,
      ap?.capabilities?.find((c) => c.radio_id === radio),
    );
  if (!cap) throw Error("未收到射频能力");
  const effective = await api(
      "aps/" + encodeURIComponent(id) + "/effective-radios",
    ),
    current =
      effective.find((r) => r.radio_id === radio) ||
      effectiveRadioEditorRow(ap, radio),
    a =
      (!reset && current.advanced) ||
      (await api(
        "radios/defaults?ap_id=" +
          encodeURIComponent(id) +
          "&radio_id=" +
          radio,
      )),
    observed = ap.radio_status?.find((r) => r.radio_id === radio);
  currentRadio = { id, radio, advanced: a, cap };
  const basic = `<div class="notice">配置范围来自本台 AP 的能力上报，已有值包括继承的设置。首次编辑使用控制器默认值，保存前可调整。${ap.radio_linkage ? " 此设备的关联射频可能随本次修改一起调整，保存时按设备上报的顺序执行联动策略。" : ""}</div><div class="form-grid">${select("enabled", "射频状态", { "": "保持当前", on: "启用", off: "停用" }, current.enabled == null ? "" : current.enabled ? "on" : "off")}${select("mode", "无线模式", Object.fromEntries(cap.modes.map((n) => [n, modes[n] || n])), a.mode)}${select("bandwidth", "信道带宽", Object.fromEntries(cap.bandwidths.map((n) => [n, widths[n] || n])), a.bandwidth)}${select("channel", "工作信道", { "": "保持当前", ...(cap.automatic_channel === false ? {} : { 0: "自动" }), ...Object.fromEntries(cap.channels.map((n) => [n, n])) }, current.channel ?? "")}${field("power", "发射功率（dBm）", current.power_dbm ?? observed?.power_dbm ?? cap.default_power_dbm, "number", `min="${cap.min_power_dbm}" max="${cap.max_power_dbm}"`)}${field("max_clients", "最大客户端数", a.max_clients, "number", `min="1" max="${cap.max_clients}"`)}${select("antenna", "天线选择", { 0: "内置天线" }, a.antenna)}</div>`;
  const timing = `<div class="form-grid">${field("beacon_interval", "Beacon 周期（ms）", a.beacon_interval, "number", 'min="40" max="1000"')}${field("dtim", "DTIM 周期", a.dtim, "number", 'min="1" max="255"')}${field("fragmentation", "分片门限", a.fragmentation, "number", 'min="256" max="2346"')}${field("rts", "RTS 门限", a.rts, "number", 'min="1" max="2346"')}${ap.features?.frame_rate_control ? select("management_rate", "管理帧速率", { 1: "保持当前", ...(cap.band === "5 GHz" ? { 12: "6 Mbps", 24: "12 Mbps", 48: "24 Mbps" } : { 2: "1 Mbps", 11: "5.5 Mbps", 12: "6 Mbps", 22: "11 Mbps", 48: "24 Mbps" }) }, a.management_rate) : ""}</div>`;
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
    .join(
      "",
    )}</div><div class="form-grid">${ap.features?.rssi_control ? field("rssi_threshold", "接入 RSSI 门限（dBm）", a.rssi_threshold, "number", 'min="-100" max="0"') + field("rssi_kick_threshold", "剔除 RSSI 门限（dBm）", a.rssi_kick_threshold, "number", 'min="-100" max="0"') : ""}${ap.features?.wifi6_features ? select("gi_mode", "Wi-Fi 6 GI", { "-1": "自动", 0: "默认", 1: "1.6 μs", 2: "3.2 μs" }, a.gi_mode) : ""}</div>`;
  if (ap.features?.channel_optimization) {
    const d = a.dcs || {
      mode: 0,
      online: false,
      interval: 8,
      occupancy: 50,
      tolerance: 20,
      reselect: false,
    };
    performance += `<h3 class="section-title">动态信道优化</h3><div class="form-grid">${select("dcs_mode", "动态信道切换", { 0: "自动", 1: "手动", 2: "关闭" }, d.mode)}${check("dcs_online", "在线动态优化", d.online)}${field("dcs_interval", "检测周期", d.interval, "number", 'min="3" max="180"')}${field("dcs_occupancy", "信道占用门限（%）", d.occupancy, "number", 'min="1" max="100"')}${field("dcs_tolerance", "信道容忍度（%）", d.tolerance, "number", 'min="1" max="100"')}${check("dcs_reselect", "立即重新选择信道", d.reselect)}</div>`;
  }
  if (ap.features?.band_steering) {
    const x = a.admission || { enabled: true, threshold: -60, difference: 6 };
    performance += `<h3 class="section-title">射频 RSSI 引导</h3><div class="form-grid">${check("admission_enabled", "启用射频 RSSI 引导", x.enabled)}${field("admission_threshold", "接入信号门限（dBm）", x.threshold, "number", 'min="-100" max="0"')}${field("admission_difference", "信号差值（dB）", x.difference, "number", 'min="0" max="100"')}</div>`;
  }
  if (ap.features?.edca) {
    const q = a.edca?.queues || [];
    performance += `<h3 class="section-title">EDCA 争用参数</h3>${ap.features?.edca_mode ? select("edca_mode", "EDCA 模式", { 0: "静态 EDCA", 1: "动态 EDCA" }, a.edca?.mode ?? 0) : ""}${check("edca_enabled", "启用 EDCA", a.edca?.enabled)}${ap.edca_presets ? select("edca_preset", "预设场景", { "": "自定义队列", ...Object.fromEntries(ap.edca_presets.scenes.map((s) => [s.id, s.name || "场景 " + s.id])) }, a.edca?.preset ?? "") : ""}${edcaQueueFields(q)}`;
  }
  openDialog(
    "radio",
    apName(id) + " · " + cap.band,
    "射频设置 / 射频 " + radio,
    `<form id="radio-form" novalidate><button type="button" class="secondary" data-radio-reset-defaults>使用此设备的高级默认值</button>${tabs(
      [
        ["rf-basic", "射频设置"],
        ["rf-timing", "时序与门限"],
        ["rf-performance", "无线性能"],
      ],
    )}${pane("rf-basic", basic, true)}${pane("rf-timing", timing)}${pane("rf-performance", performance)}${formEnd()}</form>`,
  );
  updateRadioDependencies();
}
async function submitService(f) {
  const value = (n) => f.elements[n].value,
    num = (n) => Number(value(n)),
    checked = (n) => f.elements[n].checked,
    security = value("security");
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
  await api("services", {
    ...(value("binding_mode") === "freq"
      ? {
          auto_bind_frequencies: [
            ...f.elements.auto_bind_frequencies.selectedOptions,
          ].reduce((n, x) => n | Number(x.value), 0),
        }
      : {}),
    groups: bindings.length
      ? []
      : [...f.elements.groups.selectedOptions].map((x) => x.value),
    id: currentService?.id || "",
    ssid: value("ssid"),
    security,
    passphrase: value("passphrase"),
    enabled: checked("enabled"),
    hidden: checked("hidden"),
    radios,
    aps: bindings.length
      ? [...new Set(bindings.map((b) => b.ap_id))]
      : [...f.elements.aps.selectedOptions].map((o) => o.value).filter(Boolean),
    bindings,
    options: o,
  });
}
async function submitRadio(f) {
  const { id, radio } = currentRadio,
    a = structuredClone(currentRadio.advanced);
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
document.addEventListener("click", async (e) => {
  const b = e.target.closest("button");
  if (!b) return;
  try {
    if (b.dataset.bandNavigation) bandNavigationEditor();
    if (b.dataset.newPool) poolEditor(null);
    if (b.dataset.pool)
      poolEditor(
        (data.config.vlan_pools || []).find(
          (p) => p.id === Number(b.dataset.pool),
        ),
      );
    if (b.dataset.deletePool) {
      await api("vlan-pools/" + b.dataset.deletePool, undefined, "DELETE");
      toast("已保存 VLAN 池删除任务");
      await refresh();
    }
    if (b.dataset.tab || b.dataset.view) {
      showTab(b.dataset.tab || b.dataset.view);
      if (tab === "history") await refreshHistory();
      if (tab === "upgrades") await refreshUpgrades();
      if (tab === "interfaces") {
        interfaces = await api("interfaces");
        renderContent();
      }
      if (tab === "resources") {
        controllerResources = await api("controller/resources");
        renderContent();
      }
    }
    if (b.dataset.editorTab) {
      $$("[data-editor-tab]").forEach((x) =>
        x.classList.toggle("active", x === b),
      );
      $$("[data-pane]").forEach((x) =>
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
      toast("已保存，等待设备应答");
      await refresh();
    }
    if (b.dataset.delete) {
      const s = data.config.services.find((s) => s.id === b.dataset.delete);
      if (
        confirm(
          "删除无线服务“" + s.ssid + "”？绑定 AP 上的对应 SSID 将停止广播。",
        )
      ) {
        await api("services/" + encodeURIComponent(s.id), undefined, "DELETE");
        toast("删除任务已保存，等待 AP 确认");
        await refresh();
      }
    }
    if (b.dataset.led || b.dataset.ledOff) {
      b.disabled = true;
      await api(
        "aps/" + encodeURIComponent(b.dataset.led || b.dataset.ledOff) + "/led",
        { on: !!b.dataset.led },
      );
      toast("设备已应答 LED 设置");
      b.disabled = false;
    }
    if (b.dataset.readback) {
      await api(
        "aps/" + encodeURIComponent(b.dataset.readback) + "/refresh",
        {},
      );
      toast("已请求 AP 重新上报无线运行状态");
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
  if (e.target.id === "search") {
    query = e.target.value.toLowerCase();
    renderContent();
  }
});
document.addEventListener("change", (e) => {
  if (e.target.name === "radio_ap_filter") {
    radioAPFilter = e.target.value;
    renderContent();
  }
  if (e.target.closest("#service-form")) {
    const form = e.target.closest("#service-form");
    const presets = serviceFrequencyPresets;
    if (e.target.name === "band_preset") {
      const mask = presets[e.target.value];
      if (mask != null)
        for (const option of form.elements.auto_bind_frequencies.options)
          option.selected = !!(mask & Number(option.value));
      else form.querySelector(".frequency-ranks").open = true;
    }
    if (e.target.name === "auto_bind_frequencies") {
      const mask = [...e.target.selectedOptions].reduce(
        (mask, option) => mask | Number(option.value),
        0,
      );
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
    $("#editor").close();
    dialogKind = "";
    toast("配置已保存，正在等待设备应答");
    await refresh();
  } catch (err) {
    $("#form-error").textContent = err.message;
  } finally {
    btn.disabled = false;
  }
});
$("#close-dialog").onclick = () => {
  $("#editor").close();
  dialogKind = "";
};
$("#editor").addEventListener("close", () => {
  dialogKind = "";
});
$("#new-service").onclick = () => serviceEditor(null);
$("#refresh").onclick = refresh;
window.addEventListener("hashchange", () => {
  if (location.hash.slice(1) !== tab) showTab(location.hash.slice(1));
});
initializeNavigation();
showTab(location.hash.slice(1) || "overview");
setInterval(refresh, 4000);

document.addEventListener("click", async (e) => {
  if (!e.target.closest("[data-radio-reset-defaults]")) return;
  try {
    await radioEditor(currentRadio.id, currentRadio.radio, true);
  } catch (err) {
    toast(err.message);
  }
});
