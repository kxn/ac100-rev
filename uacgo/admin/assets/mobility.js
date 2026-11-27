"use strict";

let mobilityEdit = null;
let mobilityStatus = {};

function currentRoamingVersion() {
  return data.config.mobility?.mode_source === "tl-ac100-v4-1.4.3"
    ? "v4"
    : "v6";
}

function currentNetworkMode() {
  const p = data.config.mobility;
  return p?.network_mode === 0
    ? p.current_network_mode || 1
    : (p?.network_mode ?? 2);
}

function renderMobility(view) {
  const p = data.config.mobility;
  const kinds =
    view === "balance"
      ? ["balance"]
      : ["roaming", "roaming-mode", "roaming-result", "automatic-mode"];

  let headerCard = "";
  let mainPanel = "";

  if (view === "balance") {
    mainPanel = panel(
      "负载均衡规则",
      table(
        ["规则", "应用范围", "客户端门限 / 差值", "状态", "操作"],
        (p?.balance || [])
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
      ),
    );
  } else {
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

    headerCard = panel(
      "调度策略概览",
      `<div class="strategy-summary">
        <div class="strategy-items">
          <div class="strategy-kv"><span>策略版本</span><strong>${currentRoamingVersion().toUpperCase()}</strong></div>
          <div class="strategy-kv"><span>网络模式</span><strong>${esc(modeLabel)}</strong></div>
          ${p?.network_mode === 0 ? `<div class="strategy-kv"><span>自动回退门限</span><strong class="num">${p.automatic_limits?.aps ?? 5} AP / ${p.automatic_limits?.stations ?? 30} 客户端</strong></div>` : ""}
          ${
            currentNetworkMode() === 1
              ? `<div class="strategy-kv"><span>共同信道</span><strong class="num">${["2.4G", "5G低", "5G高"].map((l, i) => `${l} ${hp?.channels?.[i] || "—"}`).join(" · ")}${hpStateLabel ? " (" + hpStateLabel + ")" : ""}</strong></div>`
              : ""
          }
        </div>
        <div class="actions">
          ${currentNetworkMode() === 1 ? '<button type="button" class="btn secondary sm" data-mobility-scan>重新协调共同信道</button>' : ""}
          <button type="button" class="btn secondary sm" data-mobility-kind="default">策略与默认参数</button>
        </div>
      </div>${
        currentNetworkMode() === 1 && mobilityStatus.unsupported_aps?.length
          ? `<div class="panel-body"><p class="help">以下 AP 不支持共同信道扫描：${mobilityStatus.unsupported_aps.map((id) => esc(apName(id))).join("、")}</p></div>`
          : ""
      }`,
    );

    mainPanel = panel(
      "漫游规则",
      table(
        ["规则", "应用范围", "802.11 k / v / r", "门限 (2.4 / 5 GHz)", "状态", "操作"],
        (p?.roaming || [])
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
      ),
    );
  }

  return (
    headerCard +
    mainPanel +
    panel(
      "设备同步状态",
      table(
        ["AP", "策略项", "状态", "说明"],
        data.apply
          .filter((s) => kinds.includes(s.service_id))
          .map(
            (s) =>
              `<tr><td>${esc(apName(s.ap_id))}</td><td>${esc(configurationItemName(s.service_id))}</td><td>${statePill(s.state)}</td><td>${esc(s.error || "—")}</td></tr>`,
          )
          .join(""),
      ),
    )
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
  if (f.id !== "mobility-form") return;
  event.preventDefault();
  if (!f.reportValidity()) return;
  const button = f.querySelector("[type=submit]");
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
  if (
    event.target.form?.id === "mobility-form" &&
    event.target.name === "mode_source"
  )
    updateMobilityVersionForm();
});
