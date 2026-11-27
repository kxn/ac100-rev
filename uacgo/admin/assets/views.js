"use strict";

function targetSummary(target) {
  const aps = (target.aps || []).map(apName);
  const groups = (target.groups || []).map(
    (id) => (data.config.groups || []).find((g) => g.id === id)?.name || id,
  );
  return (
    [...groups.map((g) => "分组 " + g), ...aps].join("、") || "全部 AP"
  );
}

function serviceBands(service) {
  if (service.bindings?.length) {
    return [
      ...new Set(
        service.bindings.map(
          (b) =>
            data.aps
              .find((a) => a.id === b.ap_id)
              ?.capabilities?.find((c) => c.radio_id === b.radio_id)?.band ||
            "射频 " + b.radio_id,
        ),
      ),
    ].join("、");
  }
  if (service.auto_bind_frequencies != null) {
    return [
      service.auto_bind_frequencies & 255 ? "2.4 GHz" : "",
      service.auto_bind_frequencies & 65280 ? "5 GHz" : "",
    ]
      .filter(Boolean)
      .join("、");
  }
  return "射频 " + (service.radios || []).join("、");
}

function breakdownBar(label, count, total, swatchClass) {
  const pct = total > 0 ? Math.round((count / total) * 100) : 0;
  const fills = {
    0: "#2563eb",
    1: "#059669",
    2: "#d97706",
    3: "#dc2626",
    4: "#7c3aed",
  };
  const fill = fills[swatchClass] || "#2563eb";
  return `<div class="breakdown-row">
    <div class="breakdown-head"><span>${esc(label)}</span><span class="num">${count} (${pct}%)</span></div>
    <svg class="breakdown-svg" viewBox="0 0 100 7" preserveAspectRatio="none" aria-hidden="true">
      <rect width="100" height="7" rx="0" fill="#f1f3f6" />
      <rect width="${pct}" height="7" rx="0" fill="${fill}" />
    </svg>
  </div>`;
}

function apRadioSummary(ap) {
  return (ap.capabilities || [])
    .map((c) => {
      const stats = ap.radio_statistics?.find((r) => r.radio_id === c.radio_id);
      const obs = ap.radio_status?.find((r) => r.radio_id === c.radio_id);
      const nat = ap.wireless_telemetry?.radios?.find(
        (r) => r.radioId === c.radio_id,
      );
      const ch = stats?.channel ?? obs?.channel ?? nat?.channel;
      const load = stats?.channel_load_percent;
      const shortBand = c.band?.includes("2.4")
        ? "2.4G"
        : c.band?.includes("6")
          ? "6G"
          : c.band?.includes("5")
            ? "5G"
            : "R" + c.radio_id;
      const cls = c.band?.includes("2.4")
        ? "tag-2g"
        : c.band?.includes("6")
          ? "tag-6g"
          : "tag-5g";
      return `<span class="tag ${cls} num">${shortBand} CH${ch ?? "—"}${load != null ? " · " + load + "%" : ""}</span>`;
    })
    .join(" ");
}

function renderOverview() {
  const inventory = data.aps.filter(
    (a) => !data.config.retired_aps?.includes(a.id),
  );
  const online = inventory.filter((a) => a.online).length;
  const offline = inventory.length - online;
  const connected = data.clients.filter((c) => c.state === "connected");
  const apsById = Object.fromEntries(data.aps.map((a) => [a.id, a]));

  let c2g = 0;
  let c5g = 0;
  let c6g = 0;
  let cMlo = 0;
  let sigGood = 0;
  let sigFair = 0;
  let sigWeak = 0;
  for (const c of connected) {
    const band = apsById[c.ap_id]?.capabilities?.find(
      (r) => r.radio_id === c.radio_id,
    )?.band;
    if (c.mlo || (c.radio_entries && c.radio_entries.length > 1)) cMlo++;
    if (band?.includes("2.4")) c2g++;
    else if (band?.includes("6")) c6g++;
    else if (band?.includes("5")) c5g++;
    if (c.rssi_dbm != null) {
      if (c.rssi_dbm >= -60) sigGood++;
      else if (c.rssi_dbm >= -74) sigFair++;
      else sigWeak++;
    }
  }

  const activeServices = data.config.services.filter((s) => !s.deleting);
  const enabledServices = activeServices.filter((s) => s.enabled).length;
  const problems = data.apply.filter((s) =>
    ["failed", "failed_recovered", "blocked"].includes(s.state),
  );
  const pending = data.apply.filter((s) => s.state === "applying").length;

  const syncText = problems.length
    ? `${problems.length} 项异常`
    : pending
      ? `${pending} 项下发中`
      : !online && enabledServices > 0
        ? "等待 AP"
        : "正常";
  const syncTone = problems.length ? "err" : pending ? "warn" : "ok";

  const kpis = `<div class="kpi-grid" id="summary">
    <button type="button" class="kpi-card" data-view="aps">
      <span class="kpi-label">在线 AP</span>
      <strong class="kpi-value num" id="online">${online} / ${inventory.length}</strong>
      <span class="kpi-sub" id="total-ap">${inventory.length ? (offline ? offline + " 台离线" : "全部在线") : "暂无 AP"}</span>
    </button>
    <button type="button" class="kpi-card" data-view="clients">
      <span class="kpi-label">在线客户端</span>
      <strong class="kpi-value num" id="client-count">${connected.length}</strong>
      <span class="kpi-sub num">2.4G ${c2g} · 5G ${c5g}${c6g ? " · 6G " + c6g : ""}</span>
    </button>
    <button type="button" class="kpi-card" data-view="services">
      <span class="kpi-label">无线服务</span>
      <strong class="kpi-value num" id="service-count">${enabledServices}</strong>
      <span class="kpi-sub num" id="service-summary">共 ${activeServices.length} 项</span>
    </button>
    <button type="button" class="kpi-card" data-view="aps">
      <span class="kpi-label">配置同步</span>
      <strong class="kpi-value ${syncTone}" id="pending-count">${syncText}</strong>
      <span class="kpi-sub" id="apply-summary">${problems.length ? "点击查看异常" : pending ? "正在写入设备" : "设备已同步"}</span>
    </button>
  </div>`;

  const problemsPanel = problems.length
    ? panel(
        "配置同步异常",
        table(
          ["AP", "配置项", "状态", "说明"],
          problems
            .map(
              (s) =>
                `<tr>
                  <td><button type="button" class="link-btn" data-ap="${esc(s.ap_id)}">${esc(apName(s.ap_id))}</button></td>
                  <td>${esc(configurationItemName(s.service_id))}</td>
                  <td>${statePill(s.state)}</td>
                  <td>${esc(s.error || "—")}</td>
                </tr>`,
            )
            .join(""),
        ),
      )
    : "";

  const apRows = inventory
    .slice(0, 8)
    .map((a) => {
      const cnt = connected.filter((c) => c.ap_id === a.id).length;
      const ip = a.local_ip === "0.0.0.0" ? a.address : a.local_ip;
      return `<tr>
        <td><button type="button" class="link-btn" data-ap="${esc(a.id)}">${esc(a.name || a.id)}</button><small>${esc(a.model || "—")} · <span class="mono">${esc(ip)}</span></small></td>
        <td><span class="pill ${a.online ? "online" : ""}">${a.online ? "在线" : "离线"}</span><small class="num">${a.online ? formatUptime(a.connected_at) : ago(a.last_seen)}</small></td>
        <td>${apRadioSummary(a) || '<span class="muted">—</span>'}</td>
        <td class="num">${cnt}</td>
      </tr>`;
    })
    .join("");

  const svcRows = activeServices
    .slice(0, 8)
    .map((s) => {
      const cnt = connected.filter(
        (c) => c.service_id === s.id || (!c.service_id && c.ssid === s.ssid),
      ).length;
      return `<tr>
        <td><strong>${esc(s.ssid)}</strong><small>${esc(securityNames[s.security] || s.security)}</small></td>
        <td><span class="pill ${s.enabled ? "online" : ""}">${s.enabled ? "启用" : "停用"}</span></td>
        <td>${esc(serviceBands(s))}</td>
        <td class="num">${cnt}</td>
        <td><button type="button" class="text-button" data-edit="${esc(s.id)}">配置</button></td>
      </tr>`;
    })
    .join("");

  const totalSta = connected.length;
  const distBody = `<div class="panel-body">
    <div class="breakdown-list">
      ${breakdownBar("2.4 GHz", c2g, totalSta, 0)}
      ${breakdownBar("5 GHz", c5g, totalSta, 4)}
      ${c6g ? breakdownBar("6 GHz", c6g, totalSta, 1) : ""}
      ${cMlo ? breakdownBar("MLO 多链路", cMlo, totalSta, 2) : ""}
    </div>
    <div class="breakdown-list breakdown-sep">
      ${breakdownBar("信号强 (≥ -60 dBm)", sigGood, totalSta, 1)}
      ${breakdownBar("信号中 (-60 ~ -74 dBm)", sigFair, totalSta, 2)}
      ${breakdownBar("信号弱 (< -75 dBm)", sigWeak, totalSta, 3)}
    </div>
  </div>`;

  const recentEvents = (overviewHistory.events || []).slice(-6).reverse();
  const evRows = recentEvents
    .map(
      (ev) => `<tr>
        <td class="num">${ago(ev.at)}</td>
        <td class="mono">${esc(ev.client_mac)}</td>
        <td>${esc(({ connected: "上线", disconnected: "离线", roamed: "漫游", service_changed: "变更" })[ev.kind] || ev.kind)}</td>
        <td>${esc(apName(ev.ap_id))}</td>
      </tr>`,
    )
    .join("");

  return (
    kpis +
    problemsPanel +
    `<div class="dash-grid">
      <div class="dash-col">
        ${panel(
          "AP 状态",
          table(["设备", "状态", "射频信道 / 负载", "终端"], apRows),
          '<button type="button" class="text-button" data-view="aps">全部 AP</button>',
        )}
        ${panel(
          "无线服务",
          table(["SSID / 加密", "状态", "频段", "终端", "操作"], svcRows),
          '<button type="button" class="text-button" data-view="services">管理服务</button>',
        )}
      </div>
      <div class="dash-col">
        ${panel("客户端分布", distBody)}
        ${panel(
          "最近连接动态",
          table(["时间", "终端", "事件", "AP"], evRows),
          '<button type="button" class="text-button" data-view="history">查看统计</button>',
        )}
      </div>
    </div>`
  );
}

function renderAPInventory() {
  const profiles = data.config.ap_profiles || [];
  const groups = data.config.groups || [];
  const inventory = data.aps.filter(
    (a) => !data.config.retired_aps?.includes(a.id),
  );
  const filtered = inventory.filter((a) => {
    if (apStatusFilter === "online" && !a.online) return false;
    if (apStatusFilter === "offline" && a.online) return false;
    const profile = profiles.find((p) => p.ap_id === a.id);
    if (apGroupFilter === "__none" && profile?.group_id) return false;
    if (
      apGroupFilter &&
      apGroupFilter !== "__none" &&
      profile?.group_id !== apGroupFilter
    )
      return false;
    if (!query) return true;
    return [a.name, a.model, a.mac, a.local_ip, a.address].some((s) =>
      String(s || "")
        .toLowerCase()
        .includes(query),
    );
  });

  const filterBar = `<div class="filter-bar">
    <div class="toolbar-group">
      <input id="search" class="search" type="search" aria-label="搜索 AP" placeholder="搜索名称、型号、MAC 或 IP" value="${esc(query)}">
      <select name="ap_group_filter" aria-label="按分组筛选">${Object.entries({
        "": "全部分组",
        __none: "未分组",
        ...Object.fromEntries(groups.map((g) => [g.id, g.name])),
      })
        .map(
          ([v, l]) =>
            `<option value="${esc(v)}" ${v === apGroupFilter ? "selected" : ""}>${esc(l)}</option>`,
        )
        .join("")}</select>
    </div>
    <div class="seg-tabs" role="tablist" aria-label="状态筛选">
      ${[
        ["all", "全部"],
        ["online", "在线"],
        ["offline", "离线"],
      ]
        .map(
          ([id, label]) =>
            `<button type="button" data-ap-filter="${id}" class="${apStatusFilter === id ? "active" : ""}">${label}</button>`,
        )
        .join("")}
    </div>
  </div>`;

  const rows = filtered
    .map((a) => {
      const profile = profiles.find((p) => p.ap_id === a.id);
      const count = data.clients.filter(
        (c) => c.ap_id === a.id && c.state === "connected",
      ).length;
      const group =
        groups.find((g) => g.id === profile?.group_id)?.name || "未分组";
      const ip = a.local_ip === "0.0.0.0" ? a.address : a.local_ip;
      const ver =
        a.software_version || a.wireless_telemetry?.software_version || "";
      return `<tr>
        <td>
          <button type="button" class="link-btn" data-ap="${esc(a.id)}">${esc(a.name || a.id)}</button>
          <small>${esc(a.model || "—")} · <span class="mono">${esc(a.mac)}</span></small>
        </td>
        <td>
          <span class="pill ${a.online ? "online" : ""}">${a.online ? "在线" : "离线"}</span>
          <small class="num">${a.online ? formatUptime(a.connected_at) : ago(a.last_seen)}</small>
        </td>
        <td>${esc(group)}<small>${esc(profile?.location || a.location || "—")}</small></td>
        <td><span class="mono">${esc(ip)}</span><small>${esc(ver.split(" ")[0] || "—")}</small></td>
        <td>
          <div>${apRadioSummary(a) || '<span class="muted">—</span>'}</div>
          <small class="num">${count} 台客户端</small>
        </td>
        <td>
          <div class="actions">
            <button type="button" class="text-button" data-ap-settings="${esc(a.id)}">配置</button>
            <button type="button" class="text-button" data-ap="${esc(a.id)}">详情</button>
          </div>
        </td>
      </tr>`;
    })
    .join("");

  return (
    panel(
      `AP 列表 (${filtered.length})`,
      table(
        ["AP / 型号", "状态", "分组 / 位置", "IP / 版本", "射频 / 终端", "操作"],
        rows,
      ),
      "",
      filterBar,
    ) + renderAPOperations()
  );
}

function renderAPOperations() {
  const operations = Object.values(data.operations || {})
    .sort((a, b) => b.started.localeCompare(a.started))
    .slice(0, 20);
  if (!operations.length) return "";
  return panel(
    "操作记录",
    table(
      ["AP", "操作", "状态", "时间"],
      operations
        .map(
          (j) =>
            `<tr><td>${esc(apName(j.ap_id))}</td><td>${esc({ reboot: "重启", "reboot-device": "重启", "factory-reset": "恢复出厂" }[j.action] || j.action)}</td><td>${statePill(j.state)}<small>${esc(j.error || "")}</small></td><td class="num">${esc(new Date(j.started).toLocaleString("zh-CN"))}</td></tr>`,
        )
        .join(""),
    ),
  );
}

function renderServices() {
  const rows = data.config.services
    .map((s) => {
      const state = serviceStates(s);
      const options = s.options;
      const scope = s.bindings?.length
        ? [...new Set(s.bindings.map((b) => apName(b.ap_id)))].join("、")
        : targetSummary(s);
      return `<tr>
        <td>
          <strong>${esc(s.ssid)}</strong>
          <small>${esc(options?.description || "")}${s.hidden ? " · 隐藏 SSID" : ""}</small>
        </td>
        <td><span class="pill ${s.enabled ? "online" : ""}">${s.deleting ? "删除中" : s.enabled ? "启用" : "停用"}</span></td>
        <td>${esc(securityNames[s.security] || s.security)}<small>${[options?.isolate ? "终端隔离" : "", options?.mlo ? "MLO" : ""].filter(Boolean).join(" · ")}</small></td>
        <td>${esc(scope)}<small>${esc(serviceBands(s))}</small></td>
        <td class="num">${options?.vlan_pool ? "VLAN 池 " + options.vlan_pool : options?.vlan ? "VLAN " + options.vlan : "不打标签"}</td>
        <td>${s.deleting ? statePill("applying") : statePill(state?.state)}${state?.error ? `<small>${esc(state.error)}</small>` : ""}</td>
        <td>
          <div class="actions">
            <button type="button" class="text-button" data-edit="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>配置</button>
            <button type="button" class="text-button" data-toggle="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>${s.enabled ? "停用" : "启用"}</button>
            <button type="button" class="text-button danger" data-delete="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>删除</button>
          </div>
        </td>
      </tr>`;
    })
    .join("");

  return panel(
    "无线服务",
    table(
      ["SSID", "状态", "安全方式", "广播范围", "VLAN", "同步状态", "操作"],
      rows,
    ),
  );
}

function renderVLANPools() {
  return panel(
    "VLAN 池",
    table(
      ["编号 / 名称", "VLAN 列表", "状态", "操作"],
      (data.config.vlan_pools || [])
        .map(
          (p) =>
            `<tr>
              <td class="num"><strong>${p.id}</strong> · ${esc(p.name)}</td>
              <td class="mono">${esc(p.vlans)}</td>
              <td>${p.deleting ? "删除中" : "正常"}</td>
              <td>
                <div class="actions">
                  <button type="button" class="text-button" data-pool="${p.id}">编辑</button>
                  <button type="button" class="text-button danger" data-delete-pool="${p.id}" ${p.deleting ? "disabled" : ""}>删除</button>
                </div>
              </td>
            </tr>`,
        )
        .join(""),
    ),
  );
}

function renderRadios() {
  const has6G = data.aps.some((a) =>
    (a.capabilities || []).some((c) => c.band?.includes("6")),
  );
  const rows = data.aps
    .filter((ap) => !radioAPFilter || ap.id === radioAPFilter)
    .flatMap((ap) =>
      (ap.capabilities || [])
        .filter((c) => radioBandFilter === "all" || c.band === radioBandFilter)
        .map((c) => {
          const stats = ap.radio_statistics?.find(
            (r) => r.radio_id === c.radio_id,
          );
          const observed = ap.radio_status?.find(
            (r) => r.radio_id === c.radio_id,
          );
          const native = ap.wireless_telemetry?.radios?.find(
            (r) => r.radioId === c.radio_id,
          );
          const state = data.apply.find(
            (s) => s.ap_id === ap.id && s.service_id === "radio:" + c.radio_id,
          );
          const bandwidth =
            { 0: 20, 1: 40, 3: 80, 5: 160, 6: 240 }[stats?.bandwidth_code] ??
            native?.bw;
          const power = observed?.power_dbm;
          const wifiGen = c.support_11be
            ? "Wi-Fi 7"
            : c.support_11ax
              ? "Wi-Fi 6"
              : c.support_11ac
                ? "Wi-Fi 5"
                : "802.11n";
          const streams =
            c.tx_streams && c.rx_streams
              ? ` · ${c.tx_streams}×${c.rx_streams}`
              : "";
          return `<tr>
            <td><strong>${esc(apName(ap.id))}</strong><small>${ap.online ? "在线" : "离线"}</small></td>
            <td>${bandTag(c.band)}<small>射频 ${c.radio_id} · ${wifiGen}${streams}</small></td>
            <td class="num">${stats?.channel ?? observed?.channel ?? native?.channel ?? "—"} / ${bandwidth ? esc(bandwidth) + " MHz" : "—"}</td>
            <td class="num">${power != null ? esc(power) + " dBm" : "—"}</td>
            <td>${stats?.channel_load_percent != null ? meterBar(stats.channel_load_percent, "auto") : '<span class="muted">—</span>'}${stats?.noise_floor_dbm != null ? `<small class="num">底噪 ${esc(stats.noise_floor_dbm)} dBm</small>` : ""}</td>
            <td>${state ? statePill(state.state) : '<span class="pill">等待同步</span>'}${state?.error ? `<small>${esc(state.error)}</small>` : ""}</td>
            <td><button type="button" class="text-button" data-radio="${c.radio_id}" data-radio-ap="${esc(ap.id)}">配置</button></td>
          </tr>`;
        }),
    )
    .join("");

  const filterBar = `<div class="filter-bar">
    <div class="toolbar-group">
      ${select(
        "radio_ap_filter",
        "",
        {
          "": "全部 AP",
          ...Object.fromEntries(data.aps.map((a) => [a.id, apName(a.id)])),
        },
        radioAPFilter,
        'aria-label="筛选 AP"',
      )}
    </div>
    <div class="seg-tabs" role="tablist" aria-label="筛选频段">
      ${[
        ["all", "全部频段"],
        ["2.4 GHz", "2.4 GHz"],
        ["5 GHz", "5 GHz"],
        ...(has6G ? [["6 GHz", "6 GHz"]] : []),
      ]
        .map(
          ([id, label]) =>
            `<button type="button" data-radio-band="${id}" class="${radioBandFilter === id ? "active" : ""}">${label}</button>`,
        )
        .join("")}
    </div>
  </div>`;

  return panel(
    "射频状态与配置",
    table(
      ["AP", "频段 / 射频", "信道 / 带宽", "发射功率", "信道负载 / 底噪", "同步状态", "操作"],
      rows,
    ),
    "",
    filterBar,
  );
}

function renderBandNavigation() {
  const b = data.config.band_navigation || {
    enabled: false,
    threshold_5g: 20,
    difference: 4,
    max_failures: 10,
  };
  const supported = data.aps.some((a) => a.features?.band_navigation);
  const states = data.apply.filter((s) => s.service_id === "band-navigation");

  const formHtml = `<div class="panel-body">
    <form id="band-navigation-form" data-inline="1" novalidate>
      <div class="form-grid">
        <div class="full">${toggle("band_enabled", "启用 5 GHz 优先引导", b.enabled)}</div>
        ${field("band_threshold", "5 GHz 客户端数量门限", b.threshold_5g, "number", 'required min="2" max="40"', "台")}
        ${field("band_difference", "频段客户端数量差值", b.difference, "number", 'required min="1" max="8"', "台")}
        ${field("band_failures", "最大引导失败次数", b.max_failures, "number", 'required min="0" max="100"', "次")}
      </div>
      <p class="help">双频需使用相同 SSID 和安全配置。</p>
      ${formEnd("保存并下发")}
    </form>
  </div>`;

  return (
    (!supported && data.aps.length
      ? '<div class="notice warning">当前在线 AP 未声明支持双频优选。</div>'
      : "") +
    panel("双频优选", formHtml) +
    panel(
      "设备同步状态",
      table(
        ["AP", "状态", "说明"],
        states
          .map(
            (s) =>
              `<tr><td>${esc(apName(s.ap_id))}</td><td>${statePill(s.state)}</td><td>${esc(s.error || s.reason || "—")}</td></tr>`,
          )
          .join(""),
      ),
    )
  );
}

function renderBackup() {
  return `<div class="card-grid">
    <div class="card">
      <h3>导出配置</h3>
      <p class="help">包含无线服务、AP 参数、策略规则及设备密码。</p>
      <div><a class="btn primary" href="/api/backup" download>下载配置备份</a></div>
    </div>
    <div class="card">
      <h3>恢复配置</h3>
      <p class="help">恢复后将重新同步 AP；备份中未包含的无线服务将被删除。</p>
      <div><label class="btn secondary file-btn">选择备份文件恢复<input type="file" id="management-import" accept="application/json" class="hidden"></label></div>
    </div>
  </div>`;
}
