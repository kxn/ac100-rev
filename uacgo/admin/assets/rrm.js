"use strict";

let rrmEdit = null;

function findQuickRRMRule(rules) {
  return (
    (rules || []).find((r) => !(r.aps?.length) && !(r.groups?.length)) || null
  );
}

function defaultQuickRRMBands(defaults) {
  const d = defaults || {};
  return {
    "2g": {
      bandwidth: 0,
      channels: d["2g"]?.channels?.length ? d["2g"].channels : [1, 6, 11],
      power_threshold: d["2g"]?.power_threshold ?? -65,
      min_power_dbm: d["2g"]?.min_power_dbm ?? 10,
      max_power_dbm: d["2g"]?.max_power_dbm ?? 50,
    },
    "5g": {
      bandwidth: d["5g"]?.bandwidth === 0 || d["5g"]?.bandwidth === 1 || d["5g"]?.bandwidth === 3 || d["5g"]?.bandwidth === 5 ? (d["5g"]?.channels?.length ? d["5g"].bandwidth : 3) : 3,
      channels: d["5g"]?.channels?.length
        ? d["5g"].channels
        : [36, 40, 44, 48, 149, 153, 157, 161],
      power_threshold: d["5g"]?.power_threshold ?? -65,
      min_power_dbm: d["5g"]?.min_power_dbm ?? 10,
      max_power_dbm: d["5g"]?.max_power_dbm ?? 50,
    },
  };
}

function buildQuickRRMRule(existing, defaults, frequency, optChannel, optPower) {
  const bands = defaultQuickRRMBands(defaults);
  const base = existing || {
    id: newID(),
    name: "默认射频优化",
    strategy_version: "v6",
    enabled: false,
    aps: [],
    groups: [],
    "2g": bands["2g"],
    "5g": bands["5g"],
  };
  return {
    ...base,
    id: base.id || newID(),
    name: base.name || "默认射频优化",
    strategy_version: base.strategy_version || "v6",
    aps: [],
    groups: [],
    frequency,
    optimize_channel: optChannel,
    optimize_power: optPower,
    "2g": base["2g"]?.channels?.length ? base["2g"] : bands["2g"],
    "5g": base["5g"]?.channels?.length ? base["5g"] : bands["5g"],
  };
}

function renderRRM() {
  const highPerf = currentNetworkMode() === 1;
  const rules = data.config.rrm || [];
  const quick = findQuickRRMRule(rules);
  const qFreq = quick ? (quick.frequency ?? 0) : 0;
  const qChannel = quick ? Boolean(quick.optimize_channel) : true;
  const qPower = quick ? Boolean(quick.optimize_power) : true;
  const showAdvancedOpen =
    rules.length > 1 ||
    rules.some(
      (r) =>
        (r.aps?.length || 0) + (r.groups?.length || 0) > 0 ||
        r.strategy_version === "v4" ||
        (r.enabled && r.schedule?.enabled),
    );

  const quickCard = panel(
    "一键射频调优",
    `<div class="panel-body">
      <form id="rrm-quick-form" data-inline="1" novalidate>
        <p class="help">自动检测周边无线干扰，为 AP 分配干扰更小的信道和合适的发射功率。测量优化约需 1–3 分钟，期间无线可能短暂中断。</p>
        <div class="setting-stack">
          <div class="setting-row">
            <div class="setting-copy">
              <span class="setting-title">优化频段</span>
              <span class="setting-desc">选择需要自动调整的无线频段。</span>
            </div>
            <div class="setting-control">
              <select name="rrm_quick_frequency" aria-label="优化频段">
                <option value="0" ${qFreq === 0 ? "selected" : ""}>双频（推荐）</option>
                <option value="1" ${qFreq === 1 ? "selected" : ""}>仅 2.4 GHz</option>
                <option value="2" ${qFreq === 2 ? "selected" : ""}>仅 5 GHz</option>
              </select>
            </div>
          </div>
          <div class="setting-row">
            <div class="setting-copy">
              <span class="setting-title">优化信道</span>
              <span class="setting-desc">避开拥挤信道，降低同频干扰。</span>
            </div>
            <div class="setting-control">
              <label class="toggle"><input type="checkbox" name="rrm_quick_channel" aria-label="优化信道" ${qChannel ? "checked" : ""}></label>
            </div>
          </div>
          <div class="setting-row">
            <div class="setting-copy">
              <span class="setting-title">优化发射功率</span>
              <span class="setting-desc">根据相邻 AP 信号强度自动调节功率，减少重叠覆盖。</span>
            </div>
            <div class="setting-control">
              <label class="toggle"><input type="checkbox" name="rrm_quick_power" aria-label="优化发射功率" ${qPower ? "checked" : ""}></label>
            </div>
          </div>
        </div>
        <div class="form-footer">
          <span class="form-error" id="form-error" role="status"></span>
          <div class="form-actions">
            <button type="submit" class="btn secondary">保存设置</button>
            <button type="button" class="btn primary" data-rrm-quick-run="1">立即优化</button>
          </div>
        </div>
      </form>
    </div>`,
  );

  const rows = rules
    .map(
      (r) => `<tr>
        <td><strong>${esc(r.name)}</strong><small>${esc(targetSummary(r))}</small></td>
        <td><span class="tag">${(r.strategy_version || "v6").toUpperCase()}</span></td>
        <td>${[r.optimize_channel ? "信道 / 带宽" : "", r.optimize_power ? "发射功率" : ""].filter(Boolean).join("、") || "—"}</td>
        <td>${["双频", "2.4 GHz", "5 GHz"][r.frequency] || "双频"}</td>
        <td><span class="pill ${r.enabled && r.schedule?.enabled ? "online" : ""}">${r.enabled && r.schedule?.enabled ? "自动计划" : "手动"}</span></td>
        <td>
          <div class="actions">
            <button type="button" class="text-button" data-rrm-edit="${esc(r.id)}">编辑</button>
            <button type="button" class="text-button" data-rrm-run="${esc(r.id)}">立即优化</button>
            <button type="button" class="text-button danger" data-rrm-delete="${esc(r.id)}">删除</button>
          </div>
        </td>
      </tr>`,
    )
    .join("");

  const advancedRules = `<details class="advanced-section" data-rrm-advanced${showAdvancedOpen ? " open" : ""}>
    <summary>高级规则与定时计划${rules.length ? `（${rules.length}）` : ""}</summary>
    <div class="advanced-panel-head">
      <p class="help">可按 AP / 分组配置定时自动优化、自定义候选信道或 V4/V6 策略。</p>
      <button type="button" class="btn secondary sm" data-rrm-new="1">新建自定义规则</button>
    </div>
    ${table(["规则", "策略版本", "优化项", "频段", "定时", "操作"], rows)}
  </details>`;

  return (
    (highPerf
      ? '<div class="notice warning">当前处于高性能网络模式，仅支持共同信道优化；V6 优化规则需在兼容模式下运行。</div>'
      : "") +
    quickCard +
    advancedRules
  );
}

function rrmPowerFields(p, b) {
  return `${field(p + "_power_threshold", "邻居信号目标", b.power_threshold, "number", 'min="-80" max="-50" required', "dBm")}${field(p + "_min_power_dbm", "最小发射功率", b.min_power_dbm, "number", 'min="3" max="30" required', "dBm")}${field(p + "_max_power_dbm", "最大发射功率", b.max_power_dbm, "number", 'min="10" max="50" required', "dBm")}`;
}

function rrmBandFields(band, b) {
  const p = "rrm_" + band;
  return `<fieldset>
    <legend>${band === "2g" ? "2.4" : "5"} GHz</legend>
    <div class="form-grid">
      ${select(p + "_bandwidth", "优化后带宽", band === "2g" ? { 0: "20 MHz" } : { 0: "20 MHz", 1: "40 MHz", 3: "80 MHz", 5: "160 MHz" }, b.bandwidth)}
      ${field(p + "_channels", "候选信道（英文逗号分隔）", (b.channels || []).join(","), "text", 'required placeholder="1,6,11"')}
      ${band === "5g" ? `<div class="full" data-v4-rrm>${field(p + "_secondary_channels", "第二 5 GHz 射频候选信道", (b.secondary_channels || []).join(","), "text", 'placeholder="149,157"')}</div>` : ""}
      <div class="form-grid full" data-rrm-band-power>${rrmPowerFields(p, b)}</div>
    </div>
  </fieldset>`;
}

async function saveQuickRRM(f, runAfter) {
  const optChannel = f.elements.rrm_quick_channel.checked;
  const optPower = f.elements.rrm_quick_power.checked;
  const errEl = f.querySelector("#form-error");
  if (errEl) errEl.textContent = "";
  if (!optChannel && !optPower) {
    toast("请至少开启优化信道或优化发射功率");
    return;
  }
  if (
    runAfter &&
    !confirm("立即执行射频测量与优化？测量期间连接可能短暂中断。")
  ) {
    return;
  }
  const freq = Number(f.elements.rrm_quick_frequency.value);
  const p = await api("rrm");
  const rows = [...(p.rules || [])];
  const existing = findQuickRRMRule(rows);
  const nextRule = buildQuickRRMRule(
    existing,
    p.defaults,
    freq,
    optChannel,
    optPower,
  );
  const idx = rows.findIndex((r) => r.id === nextRule.id);
  if (idx < 0) rows.push(nextRule);
  else rows[idx] = nextRule;
  await api("rrm/rules", rows);
  if (runAfter) {
    await api("rrm/run", { rule_id: nextRule.id });
    toast("优化任务已启动");
  } else {
    toast("射频调优设置已保存");
  }
  delete f.dataset.dirty;
  await refresh();
}

document.addEventListener("click", async (event) => {
  const b = event.target.closest("button");
  if (!b) return;
  try {
    if (b.hasAttribute("data-rrm-quick-run")) {
      const f = b.closest("#rrm-quick-form");
      if (!f) return;
      b.disabled = true;
      try {
        await saveQuickRRM(f, true);
      } finally {
        b.disabled = false;
      }
      return;
    }
    if (b.dataset.rrmRun) {
      if (!confirm("立即执行射频测量与优化？测量期间连接可能短暂中断。"))
        return;
      await api("rrm/run", { rule_id: b.dataset.rrmRun });
      toast("优化任务已启动");
      return;
    }
    if (b.dataset.rrmStatus) {
      const p = await api("rrm");
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
    const p = await api("rrm");
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
      `<form id="rrm-form" novalidate>
        <div class="form-grid">
          ${field("name", "规则名称", item.name, "text", 'required maxlength="64"')}
          ${select("strategy_version", "优化策略", { v4: "V4 · DCA / TPC", v6: "V6 · SCA / TPC" }, item.strategy_version || "v6")}
          ${targetPicker(item.aps || [], item.groups || [])}
          ${select("frequency", "优化频段", { 0: "双频", 1: "2.4 GHz", 2: "5 GHz" }, item.frequency || 0)}
          <div class="switch-list full">
            ${check("optimize_channel", "优化信道与带宽", item.optimize_channel)}
            ${check("optimize_power", "优化发射功率", item.optimize_power)}
            ${check("enabled", "启用自动计划", item.enabled)}
          </div>
        </div>
        <p class="help" data-rrm-version-help></p>
        <fieldset data-v4-rrm>
          <legend>共用功率设置（V4）</legend>
          <div class="form-grid">${rrmPowerFields("rrm_common", item["2g"])}</div>
        </fieldset>
        ${rrmBandFields("2g", item["2g"])}
        ${rrmBandFields("5g", item["5g"])}
        ${planFields("rrmplan", "自动优化时段", item.schedule)}
        ${formEnd("保存规则")}
      </form>`,
    );
    updateRRMVersionForm();
  } catch (e) {
    toast(e.message);
  }
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (f.id === "rrm-quick-form") {
    event.preventDefault();
    const btn = f.querySelector('[type="submit"]');
    btn.disabled = true;
    try {
      await saveQuickRRM(f, false);
    } catch (e) {
      const errEl = f.querySelector("#form-error");
      if (errEl) errEl.textContent = e.message;
      else toast(e.message);
    } finally {
      btn.disabled = false;
    }
    return;
  }
  if (f.id !== "rrm-form") return;
  event.preventDefault();
  if (!f.reportValidity()) return;
  const btn = f.querySelector('[type="submit"]');
  btn.disabled = true;
  try {
    const { p, item } = rrmEdit;
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
      schedule: readPlan(f, "rrmplan"),
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
    $("#editor").close();
    dialogKind = "";
    await refresh();
    toast("射频优化规则已保存");
  } catch (e) {
    f.querySelector("#form-error").textContent = e.message;
  } finally {
    btn.disabled = false;
  }
});

function updateRRMVersionForm() {
  const f = document.querySelector("#rrm-form");
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
    event.target.form?.id === "rrm-form" &&
    event.target.name === "strategy_version"
  )
    updateRRMVersionForm();
});
