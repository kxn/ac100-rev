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

function mobilityRuleTable(kind, rules) {
  return `<details class="advanced-section" ${rules.some((r) => r.aps?.length || r.groups?.length) ? "open" : ""}><summary>按AP / 分组配置规则</summary><div class="page-toolbar"><button type="button" class="btn secondary" data-mobility-kind="${kind}">新增规则</button></div>${table(["规则", "应用范围", "状态", "设置"], rules.map((r) => `<tr><td>${esc(r.name)}</td><td>${esc(targetSummary(r))}</td><td>${r.enabled ? "启用" : "禁用"}</td><td><div class="actions"><button type="button" class="text-button" data-mobility-kind="${kind}" data-mobility-id="${esc(r.id)}">编辑</button><button type="button" class="text-button danger" data-policy-delete="${kind}" data-policy-id="${esc(r.id)}">删除</button></div></td></tr>`).join(""))}</details>`;
}
function renderMobility(view) {
  const p = currentMobilityConfig();
  if (!p.default_roaming) return panel("加载中", "正在读取漫游设置…");
  if (view === "balance") {
    const rule = (p.balance || []).find(
      (r) => !r.aps?.length && !r.groups?.length,
    );
    return (
      panel(
        "负载均衡设置",
        `<form id="balance-default-form" data-inline="1" novalidate><div class="form-grid">
      ${check("enabled", "启用负载均衡", rule?.enabled)}
      ${select("balance_mode", "均衡模式", { clients: "基于客户端数" }, "clients", "disabled")}
      ${field("client_threshold", "客户端数门限", rule?.client_threshold ?? 20, "number", 'min="1" max="100" required', "个")}
      ${field("difference", "负载差值门限", rule?.difference ?? 4, "number", 'min="1" max="15" required', "个")}
      ${field("max_failures", "最大拒绝次数", rule?.max_failures ?? 10, "number", 'min="1" max="100" required', "次")}
      ${field("rssi_threshold", "探测信号门限", rule?.rssi_threshold ?? -75, "number", 'min="-95" max="0" required', "dBm")}
      </div>${formEnd("保存")}</form>`,
      ) +
      mobilityRuleTable("balance", p.balance || []) +
      renderSyncDetails(["balance"])
    );
  }
  return `<form id="roaming-default-form" data-inline="1" novalidate>${roamSettingsFields(p.default_roaming)}
    <details class="advanced-section"><summary>控制器策略与调试</summary><div class="form-grid">
      ${select("mode_source", "漫游与客户端调度策略", { "tl-ac100-v4-1.4.3": "V4 · 1.4.3", "tl-ac100-v6-1.0.3": "V6 · 1.0.3" }, p.mode_source)}
      ${field("silence_count", "漫游次数门限", p.silence?.count ?? 3, "number", 'min="0" max="255" required', "次")}
      ${field("silence_seconds", "静默时间", p.silence?.seconds ?? 30, "number", 'min="0" max="65535" required', "秒")}
      ${field("high_silence_count", "高性能漫游次数门限", p.high_performance_silence?.count ?? 3, "number", 'min="0" max="255" required', "次")}
      ${field("high_silence_seconds", "高性能静默时间", p.high_performance_silence?.seconds ?? 30, "number", 'min="0" max="65535" required', "秒")}
      </div><p class="help">V6调度仅支持兼容模式；切换至V6时，无线网络模式将同步设为兼容模式。</p></details>
    ${formEnd("保存")}</form>${mobilityRuleTable("roaming", p.roaming || [])}${renderSyncDetails(["roaming", "roaming-mode", "roaming-result"])}`;
}
function renderNetworkMode() {
  const p = currentMobilityConfig();
  const v4 = currentRoamingVersion() === "v4";
  const hp = mobilityStatus.high_performance;
  return (
    panel(
      "无线网络模式",
      `<form id="network-mode-form" data-inline="1" novalidate><div class="form-grid">
    ${select("network_mode", "无线网络模式", v4 ? { 0: "自动模式", 1: "高性能模式", 2: "兼容模式" } : { 2: "兼容模式" }, p.network_mode)}
    </div><p class="help">${v4 ? "自动模式超过AP数或客户端数门限时回退为兼容模式。" : "当前选择V6客户端调度策略，固件此入口仅支持兼容模式。"}</p>
    <details class="advanced-section" ${p.network_mode === 0 ? "open" : ""}><summary>自动模式门限</summary><div class="form-grid">
    ${field("auto_aps", "高性能AP数上限", p.automatic_limits?.aps ?? 5, "number", 'min="1" max="2147483647" required', "台")}
    ${field("auto_stations", "高性能客户端数上限", p.automatic_limits?.stations ?? 30, "number", 'min="0" max="2147483647" required', "台")}
    </div></details>
    <details class="advanced-section"><summary>共同信道与调试</summary><div class="form-grid">
    ${field("acs_timeout", "共同信道扫描等待", p.acs_timeout ?? 0, "number", 'min="0" max="255" required', "秒（0使用默认值）")}
    </div><dl class="detail-grid"><div><dt>实际网络模式</dt><dd>${currentNetworkMode() === 1 ? "高性能模式" : "兼容模式"}</dd></div><div><dt>共同信道</dt><dd>${esc(hp?.channels?.join(" / ") || "未上报")}</dd></div><div><dt>扫描状态</dt><dd>${esc(hp?.state || "未扫描")}</dd></div></dl><button type="button" class="btn secondary" data-mobility-scan>重新协调共同信道</button></details>
    ${formEnd("保存")}</form>`,
    ) + renderSyncDetails(["automatic-mode", "roaming-mode"])
  );
}

function roamSettingsFields(s) {
  const band = (b) => `<div class="form-grid">
    ${select(b + "_threshold_type", "漫游触发条件", { 1: "信号强度", 2: "速率", 3: "信号强度与速率" }, s[b].threshold_type)}
    ${field(b + "_rssi_trigger", "信号强度门限", s[b].rssi_trigger, "number", 'min="-95" max="-60" required', "dBm")}
    ${check(b + "_rssi_kick", "低信号强制踢除", s[b].rssi_kick)}
    ${field(b + "_rssi_kick_threshold", "低信号踢除门限", s[b].rssi_kick_threshold, "number", 'min="-95" max="-60" required', "dBm")}
    ${field(b + "_rate_trigger", "速率门限", s[b].rate_trigger, "number", 'min="1" max="40" required', "%")}
    ${check(b + "_rate_kick", "低速率强制踢除", s[b].rate_kick)}
    ${field(b + "_rate_kick_threshold", "低速率踢除门限", s[b].rate_kick_threshold, "number", 'min="1" max="20" required', "%")}
    </div>`;
  return (
    panel(
      "基本设置",
      `<div class="form-grid">${["11k", "11v", "11r"].map((k) => check(k, "802." + k, s[k])).join("")}</div>${tabs(
        [
          ["roam-2g", "2.4G"],
          ["roam-5g", "5G"],
        ],
      )}${pane("roam-2g", band("2g"), true)}${pane("roam-5g", band("5g"))}`,
    ) +
    panel(
      "高级设置",
      `<div class="form-grid">
    ${field("check_interval", "门限检查间隔", s.check_interval, "number", 'min="1" max="10" required', "秒")}
    ${field("difference", "漫游信号差值", s.difference, "number", 'min="5" max="15" required', "dB")}
    ${field("blacklist_time", "限制回连时间", s.blacklist_time, "number", 'min="0" max="10" required', "秒")}
    </div><details class="advanced-section"><summary>高性能模式与统计参数</summary><div class="form-grid">
    ${field("high_performance_rssi", "高性能模式信号门限", s.high_performance_rssi, "number", 'min="-70" max="-50" required', "dBm")}
    ${check("statistics", "上报漫游统计", s.statistics)}
    ${field("statistics_interval", "统计间隔", s.statistics_interval, "number", 'min="1" max="65535" required', "秒")}
    </div></details>`,
    )
  );
}
function readRoamSettings(f) {
  const n = (k) => Number(f.elements[k].value),
    c = (k) => f.elements[k].checked;
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
  return s;
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
    const request = beginEditorRequest();
    const p = await api("mobility");
    if (!isCurrentEditorRequest(request)) return;
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
  if (f.id !== "mobility-form") return;
  event.preventDefault();
  if (!validateForm(f)) return;
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
      const s = readRoamSettings(f);
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
    closeEditorFor(f);
    await refresh();
    toast("策略已保存并下发");
  } catch (e) {
    f.querySelector(".form-error").textContent = e.message;
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
  if (
    event.target.form?.id === "mobility-form" &&
    event.target.name === "mode_source"
  )
    updateMobilityVersionForm();
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (
    ![
      "roaming-default-form",
      "balance-default-form",
      "network-mode-form",
    ].includes(f.id)
  )
    return;
  event.preventDefault();
  if (!validateForm(f)) return;
  const button = f.querySelector("[type=submit]");
  button.disabled = true;
  try {
    const p = await api("mobility");
    const n = (k) => Number(f.elements[k].value);
    if (f.id === "roaming-default-form") {
      p.default_roaming = readRoamSettings(f);
      p.mode_source = f.elements.mode_source.value;
      if (p.mode_source === "tl-ac100-v6-1.0.3") {
        p.network_mode = 2;
        p.current_network_mode = 0;
      }
      p.silence = { count: n("silence_count"), seconds: n("silence_seconds") };
      p.high_performance_silence = {
        count: n("high_silence_count"),
        seconds: n("high_silence_seconds"),
      };
    } else if (f.id === "network-mode-form") {
      p.network_mode = n("network_mode");
      if (p.network_mode !== 0) p.current_network_mode = 0;
      p.automatic_limits = { aps: n("auto_aps"), stations: n("auto_stations") };
      p.acs_timeout = n("acs_timeout");
    } else {
      const rules = p.balance || [];
      const index = rules.findIndex((r) => !r.aps?.length && !r.groups?.length);
      const item = {
        ...(rules[index] || {
          id: newID(),
          name: "默认负载均衡",
          aps: [],
          groups: [],
        }),
        enabled: f.elements.enabled.checked,
      };
      for (const k of [
        "client_threshold",
        "difference",
        "max_failures",
        "rssi_threshold",
      ])
        item[k] = n(k);
      if (index < 0) rules.push(item);
      else rules[index] = item;
      p.balance = rules;
    }
    await api("mobility", p);
    mobilityData = p;
    delete f.dataset.dirty;
    await refresh();
    toast("设置已保存并下发");
  } catch (e) {
    f.querySelector(".form-error").textContent = e.message;
  } finally {
    button.disabled = false;
  }
});
