"use strict";

function targetSummary(target) {
  const aps = (target.aps || []).map(apName);
  const groups = (target.groups || []).map(
    (id) => (data.config.groups || []).find((g) => g.id === id)?.name || id,
  );
  return [...groups.map((g) => "分组 " + g), ...aps].join("、") || "全部 AP";
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

function renderAPSettings() {
  const global = `<form id="ap-global-form" data-inline="1" novalidate>${globalRebootFields(data.config.ap_defaults?.reboot_schedule)}${formEnd("设置")}</form>`;
  return (
    panel("全局设置", global) +
    renderManagement("management") +
    renderAPInventory(true)
  );
}

function renderAPInventory(configure = false) {
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
    return (
      !query ||
      [a.name, a.model, a.mac, a.local_ip, a.address].some((v) =>
        String(v || "")
          .toLowerCase()
          .includes(query),
      )
    );
  });
  const filters = `<div class="filter-bar"><label>选择AP分组：<select name="ap_group_filter" aria-label="选择AP分组">${Object.entries(
    {
      "": "全部分组",
      __none: "未分组",
      ...Object.fromEntries(groups.map((g) => [g.id, g.name])),
    },
  )
    .map(
      ([v, l]) =>
        `<option value="${esc(v)}" ${v === apGroupFilter ? "selected" : ""}>${esc(l)}</option>`,
    )
    .join(
      "",
    )}</select></label><label>选择AP状态：<select name="ap_status_filter" aria-label="选择AP状态">${Object.entries(
    { all: "全部状态", online: "在线", offline: "离线" },
  )
    .map(
      ([v, l]) =>
        `<option value="${v}" ${v === apStatusFilter ? "selected" : ""}>${l}</option>`,
    )
    .join(
      "",
    )}</select></label><input id="search" class="search" type="search" aria-label="搜索AP" placeholder="名称 / 型号 / MAC / IP" value="${esc(query)}"></div>`;
  const rows = filtered
    .map((a) => {
      const profile = profiles.find((p) => p.ap_id === a.id);
      const group =
        groups.find((g) => g.id === profile?.group_id)?.name || "未分组";
      const count = data.clients.filter(
        (c) => c.ap_id === a.id && c.state === "connected",
      ).length;
      const ip = a.local_ip === "0.0.0.0" ? a.address : a.local_ip || a.address;
      return `<tr><td><button type="button" class="link-btn" data-ap="${esc(a.id)}">${esc(apName(a.id))}</button><small>${esc(group)}</small></td><td>${esc(a.model || "未上报")}<small>硬件 ${esc(a.hardware_version || "未上报")}</small></td><td>${esc(ip || "未上报")}<small class="mono">${esc(a.mac)}</small></td><td><span class="pill ${a.online ? "online" : ""}">${a.online ? "在线" : "离线"}</span><small>${esc(a.state || "未上报")}</small></td><td class="num">${count}</td><td>${apRadioSummary(a) || "未上报"}</td><td><div class="actions">${configure ? `<button type="button" class="text-button" data-ap-settings="${esc(a.id)}">编辑</button>` : ""}<button type="button" class="text-button" data-ap="${esc(a.id)}">详情</button><button type="button" class="text-button" data-ap-diagnostic="${esc(a.id)}">能力详情</button></div></td></tr>`;
    })
    .join("");
  const tools = configure
    ? '<button type="button" class="btn secondary" data-ap-batch-names="1">批量命名</button>'
    : "";
  return (
    panel(
      "AP列表",
      (configure
        ? '<div class="editor-slot" data-editor-slot="management"></div>'
        : "") +
        table(
          [
            "AP名称",
            "AP型号",
            "IP / MAC地址",
            "连接状态",
            "客户端数",
            "射频信息",
            "设置",
          ],
          rows,
        ),
      tools,
      filters,
    ) + (configure ? renderAPOperations() : "")
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
        <td>${s.deleting ? statePill("applying") : statePill(state?.state)}${state?.error || state?.reason ? `<small>${esc(state.error || state.reason)}</small>` : ""}</td>
        <td>
          <div class="actions">
            <button type="button" class="text-button" data-edit="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>配置</button>
            <button type="button" class="text-button" data-bind-service="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>绑定AP</button>
            <button type="button" class="text-button" data-toggle="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>${s.enabled ? "停用" : "启用"}</button>
            <button type="button" class="text-button danger" data-delete="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>删除</button>
          </div>
        </td>
      </tr>`;
    })
    .join("");

  return panel(
    "无线服务列表",
    '<div class="page-toolbar"><button type="button" class="btn secondary" id="new-service">新增</button></div><div class="editor-slot" data-editor-slot="service"></div>' +
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
            <td>${state ? statePill(state.state) : '<span class="pill">等待同步</span>'}${state?.error || state?.reason ? `<small>${esc(state.error || state.reason)}</small>` : ""}</td>
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
    '<div class="editor-slot" data-editor-slot="radio"></div>' +
      table(
        [
          "AP",
          "频段 / 射频",
          "信道 / 带宽",
          "发射功率",
          "信道负载 / 底噪",
          "同步状态",
          "操作",
        ],
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
  const bad = states.filter((s) =>
    ["failed", "failed_recovered", "blocked"].includes(s.state),
  ).length;
  const pending = states.filter((s) => s.state === "applying").length;
  const ok = states.filter((s) =>
    ["acknowledged", "verified"].includes(s.state),
  ).length;
  const syncSummary = !states.length
    ? "设备同步状态（暂无待同步项）"
    : bad > 0
      ? `设备同步状态（存在 ${bad} 项异常）`
      : pending > 0
        ? `设备同步状态（${pending} 项下发中）`
        : `设备同步状态（${ok}/${states.length} 已同步）`;

  const formHtml = `<form id="band-navigation-form" data-inline="1" novalidate><div class="form-grid">
    ${check("band_enabled", "频谱导航", b.enabled)}
    ${field("band_threshold", "5G客户端数门限", b.threshold_5g, "number", 'required min="2" max="40"', "个")}
    ${field("band_difference", "客户端数差值门限", b.difference, "number", 'required min="1" max="8"', "个")}
    ${field("band_failures", "最大拒绝次数", b.max_failures, "number", 'required min="0" max="100"', "次")}
    </div>${formEnd("保存")}</form>`;

  const syncDetails = `<details class="advanced-section sync-details"${bad > 0 || pending > 0 ? " open" : ""}>
    <summary>${syncSummary}</summary>
    ${table(
      ["AP", "状态", "说明"],
      states
        .map(
          (s) =>
            `<tr><td>${esc(apName(s.ap_id))}</td><td>${statePill(s.state)}</td><td>${esc(s.error || s.reason || "—")}</td></tr>`,
        )
        .join(""),
    )}
  </details>`;

  return (
    (!supported && data.aps.length
      ? '<div class="notice warning">当前在线 AP 未声明支持双频优选。</div>'
      : "") +
    panel("频谱导航设置", formHtml) +
    syncDetails
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
