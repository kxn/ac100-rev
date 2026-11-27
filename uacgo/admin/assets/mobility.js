"use strict";

let mobilityEdit = null;
let mobilityStatus = {};
let mobilityData = null;

function defaultMobilityFallback() {
  return {
    mode_source: "tl-ac100-v6-1.0.3",
    network_mode: 2,
    balance: [],
    roaming: [],
    default_roaming: {
      "11k": true,
      "11v": true,
      "11r": false,
      "2g": {
        threshold_type: 1,
        rssi_trigger: -75,
        rssi_kick: false,
        rssi_kick_threshold: -80,
        rate_trigger: 20,
        rate_kick: false,
        rate_kick_threshold: 10,
      },
      "5g": {
        threshold_type: 1,
        rssi_trigger: -80,
        rssi_kick: false,
        rssi_kick_threshold: -85,
        rate_trigger: 20,
        rate_kick: false,
        rate_kick_threshold: 10,
      },
      check_interval: 1,
      difference: 8,
      blacklist_time: 2,
      high_performance_rssi: -65,
      statistics: false,
      statistics_interval: 30,
    },
  };
}

function currentMobilityConfig() {
  return mobilityData || data.config.mobility || defaultMobilityFallback();
}

const roamSensitivityPresets = {
  gentle: {
    label: "温和（信号较弱时切换）",
    rssi2g: -80,
    kick2g: -85,
    rssi5g: -84,
    kick5g: -89,
    diff: 10,
  },
  standard: {
    label: "标准（推荐）",
    rssi2g: -75,
    kick2g: -80,
    rssi5g: -80,
    kick5g: -85,
    diff: 8,
  },
  aggressive: {
    label: "积极（移动时更快切换）",
    rssi2g: -70,
    kick2g: -75,
    rssi5g: -75,
    kick5g: -80,
    diff: 6,
  },
};

function currentRoamingVersion() {
  return currentMobilityConfig().mode_source === "tl-ac100-v4-1.4.3"
    ? "v4"
    : "v6";
}

function currentNetworkMode() {
  const p = currentMobilityConfig();
  return p?.network_mode === 0
    ? p.current_network_mode || 1
    : (p?.network_mode ?? 2);
}

function isDefaultRoamingEnabled(s) {
  return Boolean(
    s &&
      (s["11k"] ||
        s["11v"] ||
        s["11r"] ||
        s["2g"]?.rssi_kick ||
        s["2g"]?.rate_kick ||
        s["5g"]?.rssi_kick ||
        s["5g"]?.rate_kick),
  );
}

function isRoamingEnabled(p) {
  return (
    isDefaultRoamingEnabled(p?.default_roaming) ||
    Boolean((p?.roaming || []).some((r) => r.enabled))
  );
}

function isBalanceEnabled(p) {
  return Boolean((p?.balance || []).some((r) => r.enabled));
}

function detectRoamSensitivity(s) {
  for (const [key, preset] of Object.entries(roamSensitivityPresets)) {
    if (
      s?.["2g"]?.rssi_trigger === preset.rssi2g &&
      s?.["5g"]?.rssi_trigger === preset.rssi5g &&
      s?.difference === preset.diff
    ) {
      return key;
    }
  }
  return "custom";
}

function renderSyncDetails(kinds) {
  const rows = data.apply.filter((s) => kinds.includes(s.service_id));
  const bad = rows.filter((s) =>
    ["failed", "failed_recovered", "blocked"].includes(s.state),
  ).length;
  const pending = rows.filter((s) => s.state === "applying").length;
  const ok = rows.filter((s) =>
    ["acknowledged", "verified"].includes(s.state),
  ).length;
  const summary = !rows.length
    ? "设备同步状态（暂无待同步项）"
    : bad > 0
      ? `设备同步状态（存在 ${bad} 项异常）`
      : pending > 0
        ? `设备同步状态（${pending} 项下发中）`
        : `设备同步状态（${ok}/${rows.length} 已同步）`;
  const tableHtml = table(
    ["AP", "策略项", "状态", "说明"],
    rows
      .map(
        (s) =>
          `<tr><td>${esc(apName(s.ap_id))}</td><td>${esc(configurationItemName(s.service_id))}</td><td>${statePill(s.state)}</td><td>${esc(s.error || "—")}</td></tr>`,
      )
      .join(""),
  );
  return `<details class="advanced-section sync-details"${bad > 0 || pending > 0 ? " open" : ""}>
    <summary>${summary}</summary>
    ${tableHtml}
  </details>`;
}

function renderMobility(view) {
  const p = currentMobilityConfig();
  const kinds =
    view === "balance"
      ? ["balance"]
      : ["roaming", "roaming-mode", "roaming-result", "automatic-mode"];

  if (view === "balance") {
    const rules = p?.balance || [];
    const globalRule = rules.find(
      (r) => !(r.aps?.length) && !(r.groups?.length),
    );
    const customRules = rules.filter(
      (r) => (r.aps?.length || 0) + (r.groups?.length || 0) > 0,
    );
    const isGlobalMode = customRules.length === 0;
    const balanceOn = isGlobalMode
      ? Boolean(globalRule?.enabled)
      : customRules.some((r) => r.enabled);
    const roamOn = isRoamingEnabled(p);

    const conflictBanner = `<div class="notice warning" data-balance-conflict${balanceOn && roamOn ? "" : " hidden"}>当前已同时开启智能漫游。负载均衡会在 AP 负载较高时拒绝终端接入，可能与漫游切换冲突；家庭或终端较少时建议关闭，仅在多终端密集区域开启。</div>`;

    const globalFields = isGlobalMode
      ? `<p class="help" data-balance-off-hint${balanceOn ? " hidden" : ""}>家庭或终端较少时建议保持关闭，以免影响无缝漫游。</p>
        <div class="setting-stack" data-balance-simple-options${balanceOn ? "" : " hidden"}>
          <div class="form-grid">
            ${field("client_threshold", "单 AP 触发终端数", globalRule?.client_threshold ?? 20, "number", 'min="1" max="100" required' + (balanceOn ? "" : " disabled"), "台")}
            ${field("difference", "AP 间人数差值", globalRule?.difference ?? 4, "number", 'min="1" max="15" required' + (balanceOn ? "" : " disabled"), "台")}
          </div>
          <details class="advanced-section">
            <summary>更多均衡参数</summary>
            <div class="form-grid">
              ${field("max_failures", "最大拒绝次数", globalRule?.max_failures ?? 10, "number", 'min="1" max="100" required' + (balanceOn ? "" : " disabled"), "次")}
              ${field("rssi_threshold", "探测信号门限", globalRule?.rssi_threshold ?? -75, "number", 'min="-95" max="0" required' + (balanceOn ? "" : " disabled"), "dBm")}
            </div>
          </details>
        </div>`
      : `<p class="help">当前使用 ${customRules.length} 条按 AP / 分组自定义的均衡规则，上方开关将统一启用或停用这些规则；详细参数请在下方规则列表中编辑。</p>`;

    const mainPanel = panel(
      "负载均衡",
      `<div class="panel-body">
        <form id="balance-simple-form" data-inline="1" novalidate>
          <div class="setting-hero">
            <div class="setting-copy">
              <span class="setting-title">启用负载均衡</span>
              <span class="setting-desc">同一区域有多台 AP 且终端较多时，拒绝高负载 AP 的新接入以分流到空闲 AP。</span>
            </div>
            <label class="toggle"><input type="checkbox" name="balance_enabled" aria-label="启用负载均衡" ${balanceOn ? "checked" : ""}></label>
          </div>
          ${globalFields}
          ${formEnd("保存设置")}
        </form>
      </div>`,
    );

    const rulesTable = table(
      ["规则", "应用范围", "客户端门限 / 差值", "状态", "操作"],
      rules
        .map(
          (r) => `<tr>
            <td><strong>${esc(r.name)}</strong></td>
            <td>${esc(targetSummary(r))}</td>
            <td class="num">${r.client_threshold} 台 / ${r.difference} 台</td>
            <td><span class="pill ${r.enabled ? "online" : ""}">${r.enabled ? "启用" : "停用"}</span></td>
            <td>
              <div class="actions">
                <button type="button" class="text-button" data-mobility-kind="balance" data-mobility-id="${esc(r.id)}">编辑</button>
                <button type="button" class="text-button danger" data-policy-delete="balance" data-policy-id="${esc(r.id)}">删除</button>
              </div>
            </td>
          </tr>`,
        )
        .join(""),
    );

    const advancedRules = `<details class="advanced-section" data-mobility-advanced="balance"${customRules.length ? " open" : ""}>
      <summary>按 AP / 分组自定义规则${rules.length ? `（${rules.length}）` : ""}</summary>
      <div class="advanced-panel-head">
        <p class="help">如需按不同 AP 分组设置不同阈值，请先关闭上方全局开关，再新建分组规则。</p>
        <button type="button" class="btn secondary sm" data-mobility-kind="balance">新建自定义规则</button>
      </div>
      ${rulesTable}
    </details>`;

    return conflictBanner + mainPanel + advancedRules + renderSyncDetails(kinds);
  }

  const def = p?.default_roaming;
  const roamOn = isDefaultRoamingEnabled(def);
  const customRoamRules = p?.roaming || [];
  const roamAnyOn = roamOn || customRoamRules.some((r) => r.enabled);
  const balanceOn = isBalanceEnabled(p);
  const sensitivity = detectRoamSensitivity(def);
  const kickOn = Boolean(def?.["2g"]?.rssi_kick || def?.["5g"]?.rssi_kick);

  const conflictBanner =
    roamAnyOn && balanceOn
      ? '<div class="notice warning notice-inline-action"><span>负载均衡当前已开启，可能与智能漫游相互干扰。终端不多时建议关闭负载均衡，仅在多终端密集场景启用。</span><button type="button" class="btn secondary sm" data-view="balance">前往负载均衡</button></div>'
      : "";

  const modeLabel =
    p?.network_mode === 0
      ? `自动模式（当前：${currentNetworkMode() === 1 ? "高性能" : "兼容"}）`
      : currentNetworkMode() === 1
        ? "高性能模式"
        : "兼容模式";
  const hp = mobilityStatus.high_performance;
  const hpStateLabel =
    {
      waiting: "等待同步",
      collecting: "扫描中",
      completed: "已协调",
      failed: "失败",
      idle: "待扫描",
    }[hp?.state] || "";

  const highPerfNotice =
    currentNetworkMode() === 1
      ? `<div class="notice notice-inline-action">
          <span>当前处于高性能模式 · 共同信道：${["2.4G", "5G低", "5G高"].map((l, i) => `${l} ${hp?.channels?.[i] || "—"}`).join(" · ")}${hpStateLabel ? " (" + hpStateLabel + ")" : ""}${mobilityStatus.unsupported_aps?.length ? " · 不支持共同信道扫描：" + mobilityStatus.unsupported_aps.map((id) => esc(apName(id))).join("、") : ""}</span>
          <button type="button" class="btn secondary sm" data-mobility-scan>重新协调共同信道</button>
        </div>`
      : "";

  const sensitivityOptions = Object.entries(roamSensitivityPresets)
    .map(([k, v]) => [k, v.label])
    .concat(sensitivity === "custom" ? [["custom", "自定义（已在高级参数修改）"]] : [])
    .map(
      ([k, label]) =>
        `<option value="${esc(k)}" ${k === sensitivity ? "selected" : ""}>${esc(label)}</option>`,
    )
    .join("");

  const mainPanel = panel(
    "无缝漫游",
    `<div class="panel-body">
      <form id="roam-simple-form" data-inline="1" novalidate>
        <div class="setting-hero">
          <div class="setting-copy">
            <span class="setting-title">启用智能漫游</span>
            <span class="setting-desc">多台 AP 覆盖时，自动引导终端切换到信号更好的 AP（802.11k/v）。</span>
          </div>
          <label class="toggle"><input type="checkbox" name="roam_enabled" aria-label="启用智能漫游" ${roamOn ? "checked" : ""}></label>
        </div>
        <div class="setting-stack" data-roam-simple-options${roamOn ? "" : " hidden"}>
          <div class="setting-row">
            <div class="setting-copy">
              <span class="setting-title">漫游灵敏度</span>
              <span class="setting-desc">决定信号衰减到什么程度时开始引导切换。</span>
            </div>
            <div class="setting-control">
              <select name="roam_sensitivity" aria-label="漫游灵敏度">${sensitivityOptions}</select>
            </div>
          </div>
          <div class="setting-row">
            <div class="setting-copy">
              <span class="setting-title">快速漫游 (802.11r)</span>
              <span class="setting-desc">加快切换认证速度，少数老旧或智能家居设备可能不兼容。</span>
            </div>
            <div class="setting-control">
              <label class="toggle"><input type="checkbox" name="roam_11r" aria-label="快速漫游 802.11r" ${def?.["11r"] ? "checked" : ""}></label>
            </div>
          </div>
          <div class="setting-row">
            <div class="setting-copy">
              <span class="setting-title">弱信号强制切换</span>
              <span class="setting-desc">终端停留在远端弱信号 AP 时，主动断开并引导重连。</span>
            </div>
            <div class="setting-control">
              <label class="toggle"><input type="checkbox" name="roam_rssi_kick" aria-label="弱信号强制切换" ${kickOn ? "checked" : ""}></label>
            </div>
          </div>
        </div>
        ${customRoamRules.length ? `<p class="help">另有 ${customRoamRules.length} 条按 AP / 分组自定义的漫游规则，可在下方高级设置中管理。</p>` : ""}
        ${formEnd("保存设置")}
      </form>
    </div>`,
  );

  const roamRulesTable = table(
    ["规则", "应用范围", "802.11 k / v / r", "门限 (2.4 / 5 GHz)", "状态", "操作"],
    customRoamRules
      .map(
        (r) => `<tr>
          <td><strong>${esc(r.name)}</strong></td>
          <td>${esc(targetSummary(r))}</td>
          <td>${["11k", "11v", "11r"].map((k) => (r.settings[k] ? "开" : "关")).join(" / ")}</td>
          <td class="num">${r.settings["2g"].rssi_trigger} / ${r.settings["5g"].rssi_trigger} dBm</td>
          <td><span class="pill ${r.enabled ? "online" : ""}">${r.enabled ? "启用" : "停用"}</span></td>
          <td>
            <div class="actions">
              <button type="button" class="text-button" data-mobility-kind="roaming" data-mobility-id="${esc(r.id)}">编辑</button>
              <button type="button" class="text-button danger" data-policy-delete="roaming" data-policy-id="${esc(r.id)}">删除</button>
            </div>
          </td>
        </tr>`,
      )
      .join(""),
  );

  const advTags = [];
  if (currentRoamingVersion() === "v4") advTags.push("V4");
  if (customRoamRules.length > 0)
    advTags.push(`${customRoamRules.length} 条自定义规则`);
  const advSummary = advTags.length
    ? `高级参数与自定义规则（${advTags.join(" · ")}）`
    : "高级参数与自定义规则";

  const advancedPanel = `<details class="advanced-section" data-mobility-advanced="roaming">
    <summary>${advSummary}</summary>
    <div class="strategy-summary">
      <div class="strategy-items">
        <div class="strategy-kv"><span>策略版本</span><strong>${currentRoamingVersion().toUpperCase()}</strong></div>
        <div class="strategy-kv"><span>网络模式</span><strong>${esc(modeLabel)}</strong></div>
        <div class="strategy-kv"><span>触发门限 (2.4G / 5G)</span><strong class="num">${def?.["2g"]?.rssi_trigger ?? -75} / ${def?.["5g"]?.rssi_trigger ?? -80} dBm</strong></div>
        <div class="strategy-kv"><span>信号差值</span><strong class="num">${def?.difference ?? 8} dB</strong></div>
      </div>
      <button type="button" class="btn secondary sm" data-mobility-kind="default">编辑高级参数</button>
    </div>
    <div class="advanced-panel-head">
      <h3 class="section-title">按 AP / 分组自定义规则</h3>
      <button type="button" class="btn secondary sm" data-mobility-kind="roaming">新建自定义规则</button>
    </div>
    ${roamRulesTable}
  </details>`;

  return (
    conflictBanner +
    highPerfNotice +
    mainPanel +
    advancedPanel +
    renderSyncDetails(kinds)
  );
}

function roamSettingsFields(s) {
  return `<div class="switch-list">
      ${check("11k", "802.11k 邻居测量", s["11k"])}
      ${check("11v", "802.11v BSS 转换", s["11v"])}
      ${check("11r", "802.11r 快速切换", s["11r"])}
    </div>
    ${["2g", "5g"]
      .map(
        (b) => `<fieldset>
          <legend>${b === "2g" ? "2.4" : "5"} GHz 漫游门限</legend>
          <div class="form-grid">
            ${select(b + "_threshold_type", "触发条件", { 1: "信号强度", 2: "协商速率", 3: "信号与速率" }, s[b].threshold_type)}
            ${field(b + "_rssi_trigger", "信号触发门限", s[b].rssi_trigger, "number", 'min="-95" max="-60" required', "dBm")}
            ${check(b + "_rssi_kick", "允许低信号踢除", s[b].rssi_kick)}
            ${field(b + "_rssi_kick_threshold", "低信号踢除门限", s[b].rssi_kick_threshold, "number", 'min="-95" max="-60" required', "dBm")}
            ${field(b + "_rate_trigger", "速率触发门限", s[b].rate_trigger, "number", 'min="1" max="40" required', "Mbps")}
            ${check(b + "_rate_kick", "允许低速率踢除", s[b].rate_kick)}
            ${field(b + "_rate_kick_threshold", "低速率踢除门限", s[b].rate_kick_threshold, "number", 'min="1" max="20" required', "Mbps")}
          </div>
        </fieldset>`,
      )
      .join("")}
    <div class="form-grid">
      ${field("high_performance_rssi", "高性能模式信号门限", s.high_performance_rssi, "number", 'min="-70" max="-50" required', "dBm")}
      ${field("check_interval", "检查间隔", s.check_interval, "number", 'min="1" max="10" required', "秒")}
      ${field("difference", "漫游信号差值", s.difference, "number", 'min="5" max="15" required', "dB")}
      ${field("blacklist_time", "限制回连时间", s.blacklist_time, "number", 'min="0" max="10" required', "秒")}
      ${check("statistics", "上报漫游统计", s.statistics)}
      ${field("statistics_interval", "统计间隔", s.statistics_interval, "number", 'min="1" max="65535" required', "秒")}
    </div>`;
}

document.addEventListener("click", async (event) => {
  const b = event.target.closest("button");
  if (!b) return;
  try {
    if (b.hasAttribute("data-mobility-scan")) {
      if (!confirm("扫描并协调共同信道？无线连接可能短暂中断。")) return;
      await api("mobility/scan", {});
      toast("共同信道扫描已启动");
      return;
    }
    if (b.dataset.policyDelete) {
      if (!confirm("删除此规则？")) return;
      const p = await api("mobility");
      p[b.dataset.policyDelete] = p[b.dataset.policyDelete].filter(
        (r) => r.id !== b.dataset.policyId,
      );
      await api("mobility", p);
      mobilityData = p;
      await refresh();
      return;
    }
    if (!b.dataset.mobilityKind) return;
    const p = await api("mobility");
    const kind = b.dataset.mobilityKind;
    let item =
      kind === "default"
        ? null
        : p[kind].find((r) => r.id === b.dataset.mobilityId);
    if (!item && kind !== "default")
      item = {
        id: newID(),
        name: "",
        enabled: true,
        aps: [],
        groups: [],
        client_threshold: 20,
        difference: 4,
        max_failures: 10,
        rssi_threshold: -75,
        settings: p.default_roaming,
      };
    mobilityEdit = { p, kind, item };
    const identity =
      kind === "default"
        ? `<div class="form-grid">
            ${select("mode_source", "漫游与客户端调度策略", { "tl-ac100-v4-1.4.3": "V4 · 1.4.3", "tl-ac100-v6-1.0.3": "V6 · 1.0.3" }, p.mode_source || "tl-ac100-v6-1.0.3")}
            ${select("network_mode", "网络模式", { 0: "自动模式", 2: "兼容模式", 1: "高性能模式" }, p.network_mode)}
          </div>
          <fieldset data-v4-mode>
            <legend>自动模式门限</legend>
            <div class="form-grid">
              ${field("auto_aps", "高性能 AP 数上限", p.automatic_limits?.aps ?? 5, "number", 'min="1" max="2147483647" required', "台")}
              ${field("auto_stations", "高性能客户端数上限", p.automatic_limits?.stations ?? 30, "number", 'min="0" max="2147483647" required', "台")}
            </div>
            <p class="help">超过任一门限时回退至兼容模式。</p>
          </fieldset>`
        : `<div class="form-grid">
            ${field("name", "规则名称", item.name, "text", 'required maxlength="50"')}
            ${toggle("enabled", "启用规则", item.enabled)}
            ${targetPicker(item.aps || [], item.groups || [])}
          </div>`;

    const fields =
      kind === "balance"
        ? `<div class="form-grid">
            ${field("client_threshold", "客户端数量门限", item.client_threshold, "number", 'min="1" max="100" required', "台")}
            ${field("difference", "AP 客户端数量差值", item.difference, "number", 'min="1" max="15" required', "台")}
            ${field("max_failures", "最大拒绝次数", item.max_failures, "number", 'min="1" max="100" required', "次")}
            ${field("rssi_threshold", "探测信号门限", item.rssi_threshold, "number", 'min="-95" max="0" required', "dBm")}
          </div>`
        : roamSettingsFields(
            kind === "default" ? p.default_roaming : item.settings,
          ) +
          (kind === "default"
            ? `<fieldset>
                <legend>AP 漫游静默控制</legend>
                <div class="form-grid">
                  ${field("silence_count", "漫游次数门限", p.silence?.count ?? 3, "number", 'min="0" max="255" required', "次")}
                  ${field("silence_seconds", "静默时间", p.silence?.seconds ?? 30, "number", 'min="0" max="65535" required', "秒")}
                  ${field("high_silence_count", "高性能模式漫游次数门限", p.high_performance_silence?.count ?? 3, "number", 'min="0" max="255" required', "次")}
                  ${field("high_silence_seconds", "高性能模式静默时间", p.high_performance_silence?.seconds ?? 30, "number", 'min="0" max="65535" required', "秒")}
                  ${field("acs_timeout", "共同信道扫描等待（0 为默认 5 秒）", p.acs_timeout ?? 0, "number", 'min="0" max="255" required', "秒")}
                </div>
              </fieldset>`
            : "");

    openDialog(
      "mobility",
      kind === "balance"
        ? item.name
          ? "编辑均衡规则"
          : "新建均衡规则"
        : kind === "default"
          ? "策略与默认漫游参数"
          : item.name
            ? "编辑漫游规则"
            : "新建漫游规则",
      "",
      `<form id="mobility-form" novalidate>${identity}${fields}${formEnd()}</form>`,
    );
    if (kind === "default") updateMobilityVersionForm();
  } catch (e) {
    toast(e.message);
  }
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (f.id === "roam-simple-form") {
    event.preventDefault();
    const button = f.querySelector('[type="submit"]');
    button.disabled = true;
    try {
      const p = await api("mobility");
      const s = structuredClone(p.default_roaming);
      if (!f.elements.roam_enabled.checked) {
        s["11k"] = false;
        s["11v"] = false;
        s["11r"] = false;
        s["2g"].rssi_kick = false;
        s["2g"].rate_kick = false;
        s["5g"].rssi_kick = false;
        s["5g"].rate_kick = false;
      } else {
        if (!s["11k"] && !s["11v"]) {
          s["11k"] = true;
          s["11v"] = true;
        }
        s["11r"] = f.elements.roam_11r.checked;
        const kick = f.elements.roam_rssi_kick.checked;
        s["2g"].rssi_kick = kick;
        s["5g"].rssi_kick = kick;
        if (kick) {
          s["2g"].threshold_type |= 1;
          s["5g"].threshold_type |= 1;
        }
        const preset =
          roamSensitivityPresets[f.elements.roam_sensitivity.value];
        if (preset) {
          s["2g"].threshold_type |= 1;
          s["5g"].threshold_type |= 1;
          s["2g"].rssi_trigger = preset.rssi2g;
          s["2g"].rssi_kick_threshold = preset.kick2g;
          s["5g"].rssi_trigger = preset.rssi5g;
          s["5g"].rssi_kick_threshold = preset.kick5g;
          s.difference = preset.diff;
        }
      }
      p.default_roaming = s;
      await api("mobility", p);
      mobilityData = p;
      delete f.dataset.dirty;
      await refresh();
      toast("漫游设置已保存并下发");
    } catch (e) {
      const errEl = f.querySelector("#form-error");
      if (errEl) errEl.textContent = e.message;
      else toast(e.message);
    } finally {
      button.disabled = false;
    }
    return;
  }

  if (f.id === "balance-simple-form") {
    event.preventDefault();
    const enabled = f.elements.balance_enabled.checked;
    if (enabled && !f.reportValidity()) return;
    const button = f.querySelector('[type="submit"]');
    button.disabled = true;
    try {
      const p = await api("mobility");
      const rules = p.balance || [];
      const customRules = rules.filter(
        (r) => (r.aps?.length || 0) + (r.groups?.length || 0) > 0,
      );
      if (customRules.length > 0) {
        p.balance = rules.map((r) => ({ ...r, enabled }));
      } else if (!enabled) {
        p.balance = [];
      } else {
        const existing = rules.find(
          (r) => !(r.aps?.length) && !(r.groups?.length),
        );
        const n = (k) => Number(f.elements[k].value);
        p.balance = [
          {
            id: existing?.id || newID(),
            name: existing?.name || "默认负载均衡",
            enabled: true,
            aps: [],
            groups: [],
            client_threshold: n("client_threshold"),
            difference: n("difference"),
            max_failures: n("max_failures"),
            rssi_threshold: n("rssi_threshold"),
          },
        ];
      }
      await api("mobility", p);
      mobilityData = p;
      delete f.dataset.dirty;
      await refresh();
      toast("负载均衡设置已保存并下发");
    } catch (e) {
      const errEl = f.querySelector("#form-error");
      if (errEl) errEl.textContent = e.message;
      else toast(e.message);
    } finally {
      button.disabled = false;
    }
    return;
  }

  if (f.id !== "mobility-form") return;
  event.preventDefault();
  if (!f.reportValidity()) return;
  const button = f.querySelector('[type="submit"]');
  button.disabled = true;
  try {
    const { p, kind, item } = mobilityEdit;
    const n = (k) => Number(f.elements[k].value);
    const c = (k) => f.elements[k].checked;
    let row;
    if (kind !== "default")
      row = {
        ...item,
        ...readTargetPicker(f),
        name: f.elements.name.value,
        enabled: c("enabled"),
      };
    if (kind === "balance") {
      for (const k of [
        "client_threshold",
        "difference",
        "max_failures",
        "rssi_threshold",
      ])
        row[k] = n(k);
    } else {
      const s = { high_performance_rssi: n("high_performance_rssi") };
      for (const k of ["11k", "11v", "11r", "statistics"]) s[k] = c(k);
      for (const k of [
        "check_interval",
        "difference",
        "blacklist_time",
        "statistics_interval",
      ])
        s[k] = n(k);
      for (const b of ["2g", "5g"]) {
        s[b] = {};
        for (const k of [
          "threshold_type",
          "rssi_trigger",
          "rssi_kick_threshold",
          "rate_trigger",
          "rate_kick_threshold",
        ])
          s[b][k] = n(b + "_" + k);
        for (const k of ["rssi_kick", "rate_kick"]) s[b][k] = c(b + "_" + k);
      }
      if (kind === "default") {
        p.default_roaming = s;
        p.network_mode = n("network_mode");
        p.mode_source = f.elements.mode_source.value;
        p.acs_timeout = n("acs_timeout");
        p.automatic_limits = {
          aps: n("auto_aps"),
          stations: n("auto_stations"),
        };
        if (p.network_mode !== 0) p.current_network_mode = 0;
        p.high_performance_silence = {
          count: n("high_silence_count"),
          seconds: n("high_silence_seconds"),
        };
        p.silence = {
          count: n("silence_count"),
          seconds: n("silence_seconds"),
        };
      } else row.settings = s;
    }
    if (row) {
      const i = p[kind].findIndex((r) => r.id === row.id);
      if (i < 0) p[kind].push(row);
      else p[kind][i] = row;
    }
    await api("mobility", p);
    mobilityData = p;
    $("#editor").close();
    dialogKind = "";
    await refresh();
    toast("策略已保存并下发");
  } catch (e) {
    f.querySelector("#form-error").textContent = e.message;
  } finally {
    button.disabled = false;
  }
});

function updateMobilityVersionForm() {
  const f = document.querySelector("#mobility-form");
  if (!f?.elements.mode_source) return;
  const v4 = f.elements.mode_source.value === "tl-ac100-v4-1.4.3";
  for (const o of f.elements.network_mode.options)
    o.disabled = !v4 && o.value !== "2";
  if (!v4) f.elements.network_mode.value = "2";
  f.querySelectorAll("[data-v4-mode]").forEach((e) => {
    e.hidden = !v4;
  });
}

document.addEventListener("change", (event) => {
  const t = event.target;
  if (t.form?.id === "roam-simple-form" && t.name === "roam_enabled") {
    const opts = t.form.querySelector("[data-roam-simple-options]");
    if (opts) opts.hidden = !t.checked;
  }
  if (t.form?.id === "balance-simple-form" && t.name === "balance_enabled") {
    const opts = t.form.querySelector("[data-balance-simple-options]");
    const hint = t.form.querySelector("[data-balance-off-hint]");
    const conflict = document.querySelector("[data-balance-conflict]");
    if (opts) {
      opts.hidden = !t.checked;
      opts.querySelectorAll("input").forEach((el) => {
        el.disabled = !t.checked;
      });
    }
    if (hint) hint.hidden = t.checked;
    if (conflict)
      conflict.hidden = !(
        t.checked && isRoamingEnabled(currentMobilityConfig())
      );
  }
  if (t.form?.id === "mobility-form" && t.name === "mode_source")
    updateMobilityVersionForm();
});
