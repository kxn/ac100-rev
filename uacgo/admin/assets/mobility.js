"use strict";
let mobilityEdit = null,
  mobilityStatus = {};
function currentRoamingVersion() {
  return data.config.mobility?.mode_source === "tl-ac100-v4-1.4.3" ? "v4" : "v6";
}
function currentNetworkMode() {
  const p = data.config.mobility;
  return p?.network_mode === 0 ? p.current_network_mode || 1 : p?.network_mode ?? 2;
}
function policyTargetFields(p) {
  return `<div class="form-grid"><label>AP（与分组都留空时应用全部）<select name="aps" multiple>${data.aps.map((a) => `<option value="${esc(a.id)}" ${p.aps?.includes(a.id) ? "selected" : ""}>${esc(apName(a.id))}</option>`).join("")}</select></label><label>AP 分组<select name="groups" multiple>${(data.config.groups || []).map((g) => `<option value="${esc(g.id)}" ${p.groups?.includes(g.id) ? "selected" : ""}>${esc(g.name)}</option>`).join("")}</select></label></div>`;
}
function readPolicyTarget(f) {
  return {
    aps: [...f.elements.aps.selectedOptions].map((o) => o.value),
    groups: [...f.elements.groups.selectedOptions].map((o) => o.value),
  };
}
function renderMobility(view) {
  const p = data.config.mobility;
  const content =
    view === "balance"
      ? panel(
          "客户端负载均衡",
          "达到客户端数量和差值门限后，引导新客户端选择发现表中记录过它、负载较低的 AP。达到失败次数上限后允许接入。",
          table(
            ["规则", "应用范围", "门限 / 差值", "状态", "操作"],
            (p?.balance || [])
              .map(
                (r) =>
                  `<tr><td>${esc(r.name)}</td><td>${r.aps?.length || 0} 台 AP · ${r.groups?.length || 0} 个分组${!r.aps?.length && !r.groups?.length ? " · 全部" : ""}</td><td>${r.client_threshold} / ${r.difference}</td><td>${r.enabled ? "启用" : "停用"}</td><td><button class="text-button" data-mobility-kind="balance" data-mobility-id="${esc(r.id)}">编辑</button><button class="text-button danger" data-policy-delete="balance" data-policy-id="${esc(r.id)}">删除</button></td></tr>`,
              )
              .join(""),
          ),
          '<button class="secondary" data-mobility-kind="balance">新建均衡规则</button>',
        )
      : panel(
          "无缝漫游",
          "默认参数用于没有命中规则的 AP；规则按列表顺序匹配。AP 必须声明智能漫游能力，客户端仍需支持相应协议。",
          table(
            [
              "规则",
              "802.11 k / v / r",
              "信号门限 2.4 / 5 GHz",
              "状态",
              "操作",
            ],
            (p?.roaming || [])
              .map(
                (r) =>
                  `<tr><td>${esc(r.name)}</td><td>${["11k", "11v", "11r"].map((k) => (r.settings[k] ? "开" : "关")).join(" / ")}</td><td>${r.settings["2g"].rssi_trigger} / ${r.settings["5g"].rssi_trigger} dBm</td><td>${r.enabled ? "启用" : "停用"}</td><td><button class="text-button" data-mobility-kind="roaming" data-mobility-id="${esc(r.id)}">编辑</button><button class="text-button danger" data-policy-delete="roaming" data-policy-id="${esc(r.id)}">删除</button></td></tr>`,
              )
              .join(""),
          ),
          `<div class="toolbar"><button class="secondary" data-mobility-kind="default">策略版本与默认漫游</button><button class="secondary" data-mobility-kind="roaming">新建漫游规则</button>${currentNetworkMode()===1?'<button class="secondary" data-mobility-scan>重新协调共同信道</button>':''}</div>${currentNetworkMode()===1?`<p class="help">高性能模式 · 共同信道 ${["2.4 GHz","5 GHz 低段","5 GHz 高段"].map((label,i)=>`${label}：${mobilityStatus.high_performance?.channels?.[i]||"待确定"}`).join("，")}。${esc(({waiting:"等待 AP 参数同步",collecting:"正在扫描",completed:"已计算，设备同步结果见下表",failed:"协调失败",idle:"暂无支持扫描的 AP"})[mobilityStatus.high_performance?.state]||"")}${mobilityStatus.high_performance?.error?" · "+esc(mobilityStatus.high_performance.error):""}</p>${mobilityStatus.unsupported_aps?.length?`<p class="help">以下 AP 未声明共同信道扫描控制能力：${mobilityStatus.unsupported_aps.map(id=>esc(apName(id))).join("、")}</p>`:""}`:""}`,
        );
  const kinds =
    view === "balance"
      ? ["balance"]
      : ["roaming", "roaming-mode", "roaming-result", "automatic-mode"];
  return (
    `<p class="help">漫游与客户端调度：${currentRoamingVersion().toUpperCase()} · 射频优化版本在每条优化规则中单独选择。</p>`+(p?.network_mode===0?`<p class="help">自动模式 · 当前为${currentNetworkMode()===1?"高性能模式":"兼容模式"}；AP / 客户端门限：${p.automatic_limits?.aps??5} / ${p.automatic_limits?.stations??30}。</p>`:"")+content +
    panel(
      "应用状态",
      "按设备显示此策略的下发结果。",
      table(
        ["AP", "策略", "状态"],
        data.apply
          .filter((s) => kinds.includes(s.service_id))
          .map(
            (s) =>
              `<tr><td>${esc(apName(s.ap_id))}</td><td>${esc(s.service_id)}</td><td>${statePill(s.state)}<small>${esc(s.error || "")}</small></td></tr>`,
          )
          .join(""),
      ),
    )
  );
}
function roamSettingsFields(s) {
  return `<div class="switch-list">${check("11k", "802.11k 邻居测量", s["11k"])}${check("11v", "802.11v BSS 转换", s["11v"])}${check("11r", "802.11r 快速切换", s["11r"])}</div>${["2g", "5g"].map((b) => `<fieldset><legend>${b === "2g" ? "2.4" : "5"} GHz 门限</legend><div class="form-grid">${select(b + "_threshold_type", "触发条件", { 1: "信号", 2: "速率", 3: "信号与速率" }, s[b].threshold_type)}${field(b + "_rssi_trigger", "信号触发（dBm）", s[b].rssi_trigger, "number", 'min="-95" max="-60" required')}${check(b + "_rssi_kick", "允许低信号踢除", s[b].rssi_kick)}${field(b + "_rssi_kick_threshold", "低信号踢除门限", s[b].rssi_kick_threshold, "number", 'min="-95" max="-60" required')}${field(b + "_rate_trigger", "速率触发（Mbps）", s[b].rate_trigger, "number", 'min="1" max="40" required')}${check(b + "_rate_kick", "允许低速率踢除", s[b].rate_kick)}${field(b + "_rate_kick_threshold", "低速率踢除门限", s[b].rate_kick_threshold, "number", 'min="1" max="20" required')}</div></fieldset>`).join("")}<div class="form-grid">${field("high_performance_rssi", "高性能模式信号门限（dBm）", s.high_performance_rssi, "number", 'min="-70" max="-50" required')}${field("check_interval", "检查间隔（秒）", s.check_interval, "number", 'min="1" max="10" required')}${field("difference", "漫游信号差值（dB）", s.difference, "number", 'min="5" max="15" required')}${field("blacklist_time", "限制回连时间（秒）", s.blacklist_time, "number", 'min="0" max="10" required')}${check("statistics", "记录漫游统计", s.statistics)}${field("statistics_interval", "统计间隔（秒）", s.statistics_interval, "number", 'min="1" max="65535" required')}</div>`;
}
document.addEventListener("click", async (event) => {
  const b = event.target.closest("button");
  if (!b) return;
  try {
    if (b.hasAttribute("data-mobility-scan")) {
      if (!confirm("扫描并协调所有 AP 的共同信道？无线连接可能短暂中断。")) return;
      await api("mobility/scan",{});toast("共同信道扫描已开始");return;
    }
    if (b.dataset.policyDelete) {
      if (!confirm("删除该策略？设备将恢复匹配其它规则或默认设置。")) return;
      const p = await api("mobility");
      p[b.dataset.policyDelete] = p[b.dataset.policyDelete].filter(
        (r) => r.id !== b.dataset.policyId,
      );
      await api("mobility", p);
      await refresh();
      return;
    }
    if (!b.dataset.mobilityKind) return;
    const p = await api("mobility"),
      kind = b.dataset.mobilityKind;
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
        ? `<div class="form-grid">${select("mode_source","漫游与客户端调度策略",{"tl-ac100-v4-1.4.3":"V4 · 1.4.3","tl-ac100-v6-1.0.3":"V6 · 1.0.3"},p.mode_source||"tl-ac100-v6-1.0.3")}${select('network_mode','网络模式',{0:'自动模式',2:'兼容模式',1:'高性能模式'},p.network_mode)}</div><p class="help">V4：优先 5 GHz，按信号差值筛选；V6：统一排序，正常候选要求估计速率提高至少 20% 且增加至少 20 Mbps，并识别 EHT。选择只影响漫游、均衡、估速和网络模式；射频优化单独选择。</p><fieldset data-v4-mode><legend>自动模式门限</legend><p class="help">仅在自动模式使用；超过任一门限进入兼容模式，负载回落不会自动切回高性能模式。</p><div class="form-grid">${field("auto_aps","高性能 AP 数门限",p.automatic_limits?.aps??5,"number",'min="1" max="2147483647" required')}${field("auto_stations","高性能客户端数门限",p.automatic_limits?.stations??30,"number",'min="0" max="2147483647" required')}</div></fieldset><p class="help">高性能模式使用共同信道和自动带宽；切换时可能中断无线连接。</p>`
        : field(
            "name",
            "规则名称",
            item.name,
            "text",
            'required maxlength="50"',
          ) +
          check("enabled", "启用规则", item.enabled) +
          policyTargetFields(item);
    const fields =
      kind === "balance"
        ? `<div class="form-grid">${field("client_threshold", "客户端数量门限", item.client_threshold, "number", 'min="1" max="100" required')}${field("difference", "AP 客户端数量差值", item.difference, "number", 'min="1" max="15" required')}${field("max_failures", "最多拒绝次数", item.max_failures, "number", 'min="1" max="100" required')}${field("rssi_threshold", "探测信号门限（dBm）", item.rssi_threshold, "number", 'min="-95" max="0" required')}</div>`
        : roamSettingsFields(
            kind === "default" ? p.default_roaming : item.settings,
          ) + (kind === "default" ? `<fieldset><legend>AP 漫游静默控制</legend><p>按当前网络模式，下发对应参数给支持此控制的 AP。</p><div class="form-grid">${field("silence_count", "漫游次数门限", p.silence?.count ?? 3, "number", 'min="0" max="255" required')}${field("silence_seconds", "静默时间（秒）", p.silence?.seconds ?? 30, "number", 'min="0" max="65535" required')}${field("high_silence_count", "高性能模式漫游次数门限", p.high_performance_silence?.count ?? 3, "number", 'min="0" max="255" required')}${field("high_silence_seconds", "高性能模式静默时间（秒）", p.high_performance_silence?.seconds ?? 30, "number", 'min="0" max="65535" required')}${field("acs_timeout", "共同信道扫描等待（秒，0 使用原逻辑5秒）", p.acs_timeout ?? 0, "number", 'min="0" max="255" required')}</div></fieldset>` : "");
    openDialog(
      "mobility",
      kind === "balance"
        ? "负载均衡"
        : kind === "default"
          ? "默认漫游设置"
          : "漫游规则",
      "WIRELESS MOBILITY",
      `<form id="mobility-form">${identity}${fields}${formEnd()}</form>`,
    );
    if(kind === "default") updateMobilityVersionForm();
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
    const { p, kind, item } = mobilityEdit,
      n = (k) => Number(f.elements[k].value),
      c = (k) => f.elements[k].checked;
    let row;
    if (kind !== "default")
      row = {
        ...item,
        ...readPolicyTarget(f),
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
      const s = {high_performance_rssi:n("high_performance_rssi")};
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
        p.acs_timeout=n("acs_timeout");
        p.automatic_limits={aps:n("auto_aps"),stations:n("auto_stations")};
        if(p.network_mode!==0)p.current_network_mode=0;
        p.high_performance_silence={count:n("high_silence_count"),seconds:n("high_silence_seconds")};
        p.silence = {count: n("silence_count"), seconds: n("silence_seconds")};
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
    toast("策略已保存，等待设备同步");
  } catch (e) {
    f.querySelector("#form-error").textContent = e.message;
  } finally {
    button.disabled = false;
  }
});

function updateMobilityVersionForm() {
  const f=document.querySelector('#mobility-form');
  if(!f?.elements.mode_source)return;
  const v4=f.elements.mode_source.value==='tl-ac100-v4-1.4.3';
  for(const o of f.elements.network_mode.options)o.disabled=!v4&&o.value!=='2';
  if(!v4)f.elements.network_mode.value='2';
  f.querySelectorAll('[data-v4-mode]').forEach(e=>{e.hidden=!v4;});
}
document.addEventListener('change',event=>{
  if(event.target.form?.id==='mobility-form'&&event.target.name==='mode_source')updateMobilityVersionForm();
});
