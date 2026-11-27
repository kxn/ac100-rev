"use strict";

let rrmEdit = null;

let rrmData = null;
let primaryRRMID = "";

function rrmFormFields(item, primary = false) {
  return `<div class="form-grid">
    ${check("optimize_channel", "信道优化", item.optimize_channel)}
    ${select("frequency", "优化频段", { 0: "双频", 1: "2.4G", 2: "5G" }, item.frequency ?? 0)}
    </div>${rrmBandFields("2g", item["2g"])}${rrmBandFields("5g", item["5g"])}
    <div class="form-grid">${check("optimize_power", "功率优化", item.optimize_power)}</div>
    <fieldset data-v4-rrm><legend>共用功率设置（V4）</legend><div class="form-grid">${rrmPowerFields("rrm_common", item["2g"])}</div></fieldset>
    <div data-rrm-band-power>${["2g", "5g"].map((b) => `<fieldset><legend>${b === "2g" ? "2.4G" : "5G"}功率设置</legend><div class="form-grid">${rrmPowerFields("rrm_" + b, item[b])}</div></fieldset>`).join("")}</div>
    <div class="form-grid">${check("enabled", "定时优化", item.enabled && item.schedule?.enabled)}</div>
    <details class="advanced-section" data-rrm-schedule ${item.enabled ? "open" : ""}><summary>优化日期与时间</summary>${planFields("rrmplan", "自动优化计划", item.schedule, false)}</details>
    <details class="advanced-section" ${primary ? "" : "open"}><summary>应用范围与控制器策略</summary><div class="form-grid">
      ${field("name", "规则名称", item.name || "默认射频优化", "text", 'required maxlength="64"')}
      ${targetPicker(item.aps || [], item.groups || [])}
      ${select("strategy_version", "射频优化策略", { v4: "V4 · DCA / TPC", v6: "V6 · SCA / TPC" }, item.strategy_version || "v6")}
    </div><p class="help" data-rrm-version-help></p></details>`;
}
function renderRRM() {
  if (!rrmData)
    return panel("射频调优", '<div class="empty">正在读取射频优化配置…</div>');
  const rules = rrmData.rules || [];
  const found =
    rules.find((r) => r.id === primaryRRMID) ||
    rules.find((r) => !r.aps?.length && !r.groups?.length) ||
    rules[0];
  primaryRRMID = found?.id || "";
  const item = found
    ? structuredClone(found)
    : { ...structuredClone(rrmData.defaults), id: "", name: "默认射频优化" };
  for (const band of ["2g", "5g"]) {
    if (!item[band]?.channels?.length)
      item[band] = {
        ...item[band],
        bandwidth: band === "2g" ? 0 : 3,
        channels: band === "2g" ? [1, 6, 11] : [36, 44, 149, 157],
      };
  }
  return (
    (currentNetworkMode() === 1
      ? '<p class="notice">当前为高性能模式；V4使用共同信道优化，V6规则须在兼容模式运行。</p>'
      : "") +
    panel(
      "射频调优",
      `<form id="rrm-primary-form" data-rule-id="${esc(item.id)}" data-inline="1" novalidate>${rrmFormFields(item, true)}${formEnd("保存", "", '<button type="submit" name="rrm_action" value="run" class="btn secondary">立即优化</button>')}</form>`,
    ) +
    `<details class="advanced-section"><summary>多组优化规则</summary><div class="page-toolbar"><button type="button" class="btn secondary" data-rrm-new="1">新增规则</button></div>${table(["规则", "应用范围", "策略", "设置"], rules.map((r) => `<tr><td>${esc(r.name)}</td><td>${esc(targetSummary(r))}</td><td>${esc((r.strategy_version || "v6").toUpperCase())}</td><td><div class="actions"><button type="button" class="text-button" data-rrm-edit="${esc(r.id)}">编辑</button><button type="button" class="text-button" data-rrm-run="${esc(r.id)}">立即优化</button><button type="button" class="text-button danger" data-rrm-delete="${esc(r.id)}">删除</button></div></td></tr>`).join(""))}</details>`
  );
}

function rrmPowerFields(p, b) {
  return `${field(p + "_power_threshold", "邻居信号目标", b.power_threshold, "number", 'min="-80" max="-50" required', "dBm")}${field(p + "_max_power_dbm", "最大发射功率", b.max_power_dbm, "number", 'min="10" max="50" required', "dBm")}${field(p + "_min_power_dbm", "最小发射功率", b.min_power_dbm, "number", 'min="3" max="30" required', "dBm")}`;
}

function rrmBandFields(band, b) {
  const p = "rrm_" + band;
  return `<fieldset>
    <legend>${band === "2g" ? "2.4" : "5"} GHz</legend>
    <div class="form-grid">
      ${select(p + "_bandwidth", "优化后带宽", band === "2g" ? { 0: "20 MHz" } : { 0: "20 MHz", 1: "40 MHz", 3: "80 MHz", 5: "160 MHz" }, b.bandwidth)}
      ${field(p + "_channels", "候选信道（英文逗号分隔）", (b.channels || []).join(","), "text", 'required placeholder="1,6,11"')}
      ${band === "5g" ? `<div class="full" data-v4-rrm>${field(p + "_secondary_channels", "第二 5 GHz 射频候选信道", (b.secondary_channels || []).join(","), "text", 'placeholder="149,157"')}</div>` : ""}

    </div>
  </fieldset>`;
}

document.addEventListener("click", async (event) => {
  const b = event.target.closest("button");
  if (!b) return;
  try {
    if (b.dataset.rrmRun) {
      if (!confirm("立即执行射频测量与优化？测量期间连接可能短暂中断。"))
        return;
      await api("rrm/run", { rule_id: b.dataset.rrmRun });
      toast("优化任务已启动");
      return;
    }
    if (b.dataset.rrmStatus) {
      const request = beginEditorRequest();
      const p = await api("rrm");
      if (!isCurrentEditorRequest(request)) return;
      const jobRows = Object.values(p.jobs || {})
        .sort((a, b) => b.started.localeCompare(a.started))
        .map(
          (j) => `<tr>
            <td><strong>${esc(j.rule.name)}</strong><small>${(j.rule.strategy_version || "v6").toUpperCase()}</small></td>
            <td>${statePill(j.state)}</td>
            <td class="num">${esc(new Date(j.started).toLocaleString("zh-CN"))}</td>
            <td>
              ${j.common_channel_cancelled ? "<small>网络模式回退，共同信道阶段结束</small>" : ""}
              ${j.channel_collection_failed ? "<small>信道测量不足，保留原信道与带宽</small>" : ""}
              ${j.power_collection_failed ? "<small>功率测量不足，保留原功率</small>" : ""}
              ${j.power_skipped ? "<small>高性能模式跳过功率优化</small>" : ""}
              ${j.phase ? `<small>${j.phase === "channel" ? "信道" : "功率"}测量 · 第 ${j.round} 轮</small>` : ""}
              ${esc(j.error || "")}
              ${(j.changes || []).map((c) => `<small class="num">${esc(apName(c.ap_id))} 射频 ${c.radio_id}：信道 ${c.old_channel} → ${c.channel}，功率 ${c.old_power_dbm} → ${c.power_dbm} dBm</small>`).join("")}
            </td>
          </tr>`,
        )
        .join("");
      openDialog(
        "rrm-status",
        "射频优化任务记录",
        "",
        table(["规则", "状态", "开始时间", "测量与应用结果"], jobRows),
      );
      return;
    }
    if (b.dataset.rrmDelete) {
      if (!confirm("删除此优化规则？")) return;
      const p = await api("rrm");
      await api(
        "rrm/rules",
        (p.rules || []).filter((r) => r.id !== b.dataset.rrmDelete),
      );
      await refresh();
      return;
    }
    if (!b.dataset.rrmNew && !b.dataset.rrmEdit) return;
    const request = beginEditorRequest();
    const p = await api("rrm");
    if (!isCurrentEditorRequest(request)) return;
    const found = (p.rules || []).find((r) => r.id === b.dataset.rrmEdit);
    const item = found
      ? structuredClone(found)
      : {
          ...structuredClone(p.defaults),
          id: newID(),
          name: "",
        };
    if (!item["5g"]?.channels?.length) {
      item["5g"] = {
        ...item["5g"],
        bandwidth: 3,
        channels: [36, 44, 149, 157],
        secondary_channels: [149, 157],
      };
    }
    rrmEdit = { p, item };
    openDialog(
      "rrm",
      b.dataset.rrmEdit ? "编辑优化规则" : "新建优化规则",
      "",
      `<form id="rrm-form" novalidate>${rrmFormFields(item)}${formEnd("保存规则")}</form>`,
    );
    updateRRMVersionForm();
  } catch (e) {
    toast(e.message);
  }
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (!["rrm-form", "rrm-primary-form"].includes(f.id)) return;
  event.preventDefault();
  if (!validateForm(f)) return;
  const runAfter = event.submitter?.value === "run";
  if (
    runAfter &&
    !confirm("保存当前配置并立即执行射频优化？测量期间连接可能短暂中断。")
  )
    return;
  const buttons = f.querySelectorAll('[type="submit"]');
  buttons.forEach((b) => (b.disabled = true));
  const editedItem = rrmEdit?.item;
  try {
    const p = await api("rrm");
    const item =
      f.id === "rrm-primary-form"
        ? (p.rules || []).find((r) => r.id === f.dataset.ruleId) || {
            ...p.defaults,
            id: f.dataset.ruleId || newID(),
          }
        : editedItem;
    const n = (k) => Number(f.elements[k].value);
    const r = {
      ...item,
      strategy_version: f.elements.strategy_version.value,
      ...readTargetPicker(f),
      name: f.elements.name.value,
      frequency: n("frequency"),
      enabled: f.elements.enabled.checked,
      optimize_channel: f.elements.optimize_channel.checked,
      optimize_power: f.elements.optimize_power.checked,
      schedule: readPlan(f, "rrmplan", f.elements.enabled.checked),
    };
    for (const band of ["2g", "5g"]) {
      r[band] = {};
      for (const key of [
        "bandwidth",
        "power_threshold",
        "min_power_dbm",
        "max_power_dbm",
      ])
        r[band][key] = n("rrm_" + band + "_" + key);
      for (const key of band === "5g"
        ? ["channels", "secondary_channels"]
        : ["channels"])
        r[band][key] = f.elements["rrm_" + band + "_" + key].value
          .split(",")
          .map((s) => s.trim())
          .filter(Boolean)
          .map(Number);
    }
    if (r.strategy_version === "v4") {
      for (const key of ["power_threshold", "min_power_dbm", "max_power_dbm"])
        r["5g"][key] = r["2g"][key] = n("rrm_common_" + key);
    }
    const rows = p.rules || [];
    const i = rows.findIndex((row) => row.id === r.id);
    if (i < 0) rows.push(r);
    else rows[i] = r;
    await api("rrm/rules", rows);
    if (f.id === "rrm-primary-form") {
      primaryRRMID = r.id;
      f.dataset.ruleId = r.id;
    }
    if (runAfter) await api("rrm/run", { rule_id: r.id });
    delete f.dataset.dirty;
    closeEditorFor(f);
    await refresh();
    toast("射频优化规则已保存");
  } catch (e) {
    f.querySelector(".form-error").textContent = e.message;
  } finally {
    buttons.forEach((b) => (b.disabled = false));
  }
});

function updateRRMVersionForm(
  f = document.querySelector("#rrm-form") ||
    document.querySelector("#rrm-primary-form"),
) {
  if (!f) return;
  const v4 = f.elements.strategy_version.value === "v4";
  f.querySelector("[data-rrm-version-help]").textContent = v4
    ? "V4：先 DCA 信道测量后 TPC 功率测量，每组 1–4 个候选信道，各频段共用功率门限。"
    : "V6：SCA / TPC，三射频设备按高低频段分次测量。";
  f.querySelectorAll("[data-v4-rrm]").forEach((e) => {
    e.hidden = !v4;
  });
  f.querySelectorAll("[data-rrm-band-power]").forEach((e) => {
    e.hidden = v4;
  });
  for (const key of ["power_threshold", "min_power_dbm", "max_power_dbm"]) {
    for (const band of ["2g", "5g"])
      f.elements["rrm_" + band + "_" + key].disabled = v4;
    f.elements["rrm_common_" + key].disabled = !v4;
  }
}

document.addEventListener("change", (event) => {
  if (
    ["rrm-form", "rrm-primary-form"].includes(event.target.form?.id) &&
    event.target.name === "enabled" &&
    event.target.checked
  )
    event.target.form.querySelector("[data-rrm-schedule]").open = true;
  if (
    ["rrm-form", "rrm-primary-form"].includes(event.target.form?.id) &&
    event.target.name === "strategy_version"
  )
    updateRRMVersionForm(event.target.form);
});
