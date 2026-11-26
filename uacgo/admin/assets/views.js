"use strict";

function targetSummary(target) {
  const aps = (target.aps || []).map(apName);
  const groups = (target.groups || []).map(
    (id) => (data.config.groups || []).find((g) => g.id === id)?.name || id,
  );
  return (
    [...groups.map((g) => "分组 " + g), ...aps].join("、") ||
    "所有 AP（含后续接入）"
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
function renderOverview() {
  const steps = [
    ["aps", "1", "确认 AP", "查看 AP 是否上线；需要统一配置时再建立分组。"],
    [
      "services",
      "2",
      "建立无线服务",
      "填写无线名称和密码，选择应用的 AP 与频段。",
    ],
    ["radios", "3", "调整射频", "按需要修改信道、带宽和功率。"],
  ];
  const problems = data.apply.filter((s) =>
    ["failed", "failed_recovered", "blocked"].includes(s.state),
  );
  return (
    panel(
      "配置无线网络",
      "按下面的顺序完成基础配置。",
      `<div class="setup-steps">${steps.map(([route, n, title, desc]) => `<button class="setup-step" data-view="${route}"><span class="step-number">${n}</span><span><strong>${title}</strong><small>${desc}</small></span><span class="step-arrow">→</span></button>`).join("")}</div>`,
    ) +
    `<div class="overview-grid">${panel("检查配置结果", "接入客户端后，查看其 AP、频段、IP 和上报状态。", `<div class="section-body"><button class="secondary" data-view="clients">查看客户端状态</button> <button class="secondary" data-view="history">查看连接记录</button></div>`)}${panel("继续调优", "基础接入正常后，再配置 AP 之间的引导和调度。", `<div class="section-body"><button class="secondary" data-view="mobility">无缝漫游</button> <button class="secondary" data-view="balance">负载均衡</button></div>`)}</div>` +
    (problems.length
      ? panel(
          "需要处理的配置",
          "从对应 AP 进入，查看具体失败或受阻原因。",
          table(
            ["AP", "配置项目", "状态"],
            problems
              .map(
                (s) =>
                  `<tr><td><button class="text-button" data-ap="${esc(s.ap_id)}">${esc(apName(s.ap_id))}</button></td><td>${esc(configurationItemName(s.service_id))}</td><td>${statePill(s.state)}<small>${esc(s.error || "")}</small></td></tr>`,
              )
              .join(""),
          ),
        )
      : "")
  );
}
function renderAPInventory() {
  const profiles = data.config.ap_profiles || [],
    groups = data.config.groups || [];
  const inventory = data.aps.filter(
    (a) => !data.config.retired_aps?.includes(a.id),
  );
  const rows = inventory
    .filter(
      (a) =>
        !query ||
        [a.name, a.model, a.mac, a.local_ip].some((s) =>
          String(s).toLowerCase().includes(query),
        ),
    )
    .map((a) => {
      const profile = profiles.find((p) => p.ap_id === a.id),
        count = data.clients.filter(
          (c) => c.ap_id === a.id && c.state === "connected",
        ).length;
      const group =
        groups.find((g) => g.id === profile?.group_id)?.name || "未分组";
      return `<tr><td><strong>${esc(a.name || a.id)}</strong><small>${esc(a.model || "型号未上报")}</small><small class="mono">${esc(a.mac)}</small></td><td><span class="pill ${a.online ? "online" : ""}">${a.online ? "在线" : "离线"}</span><small>${ago(a.last_seen)}</small></td><td>${esc(group)}<small>${esc(profile?.location || a.location || "")}</small></td><td>${esc(a.local_ip === "0.0.0.0" ? a.address : a.local_ip)}</td><td>${count}<small>${a.radios || 0} 个射频</small></td><td><div class="actions"><button class="text-button" data-ap-settings="${esc(a.id)}">配置</button><button class="text-button" data-ap="${esc(a.id)}">状态与操作</button></div></td></tr>`;
    })
    .join("");
  return (
    panel(
      "AP 列表",
      "同一台 AP 的配置、状态和维护操作都从这里进入。",
      table(
        ["AP / 型号", "运行状态", "分组 / 位置", "管理地址", "客户端", "操作"],
        rows,
      ),
      `<div class="toolbar"><input id="search" class="search" aria-label="搜索 AP" placeholder="搜索 AP 名称、型号或地址" value="${esc(query)}"><a class="secondary" href="/api/aps/export" download>导出清单</a></div>`,
    ) +
    `<details class="advanced-section"><summary>批量修改 AP 名称</summary><p>按 MAC 地址匹配已有 AP，导入文件只修改名称。</p><div class="toolbar"><a class="secondary" href="/api/aps/names/template" download>下载名称模板</a><label class="secondary">导入名称 CSV<input type="file" id="ap-names-import" accept=".csv,text/csv" class="hidden"></label></div></details>` +
    renderAPOperations()
  );
}
function renderAPOperations() {
  const operations = Object.values(data.operations || {})
    .sort((a, b) => b.started.localeCompare(a.started))
    .slice(0, 20);
  if (!operations.length) return "";
  return panel(
    "AP 操作记录",
    "重启和复位需要观察到 AP 重新接入后才标记完成。",
    table(
      ["AP", "操作", "结果", "时间"],
      operations
        .map(
          (j) =>
            `<tr><td>${esc(apName(j.ap_id))}</td><td>${esc({ reboot: "重启", "factory-reset": "恢复出厂" }[j.action] || j.action)}</td><td>${statePill(j.state)}<small>${esc(j.error || "")}</small></td><td>${esc(new Date(j.started).toLocaleString())}</td></tr>`,
        )
        .join(""),
    ),
  );
}
function renderServices() {
  const rows = data.config.services
    .map((s) => {
      const state = serviceStates(s),
        options = s.options;
      const scope = s.bindings?.length
        ? [...new Set(s.bindings.map((b) => apName(b.ap_id)))].join("、")
        : targetSummary(s);
      return `<tr><td><strong>${esc(s.ssid)}</strong> <span class="pill ${s.enabled ? "online" : ""}">${s.deleting ? "删除中" : s.enabled ? "启用" : "停用"}</span><small>${esc(options?.description || "")}${s.hidden ? " · 隐藏 SSID" : ""}</small></td><td>${esc(securityNames[s.security])}<small>${options?.isolate ? "终端隔离" : ""}</small></td><td>${esc(scope)}<small>${esc(serviceBands(s))}</small></td><td>${options?.vlan_pool ? "VLAN 池 " + options.vlan_pool : options?.vlan ? "VLAN " + options.vlan : "不打标签"}</td><td>${s.deleting ? statePill("applying") : statePill(state?.state)}${state?.error ? `<small>${esc(state.error)}</small>` : ""}</td><td><div class="actions"><button class="text-button" data-edit="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>配置</button><button class="text-button" data-toggle="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>${s.enabled ? "停用" : "启用"}</button><button class="text-button danger" data-delete="${esc(s.id)}" ${s.deleting ? "disabled" : ""}>删除</button></div></td></tr>`;
    })
    .join("");
  return panel(
    "无线服务列表",
    "每条服务对应一个无线名称；“应用 AP / 频段”决定在哪些设备上广播。",
    table(
      ["无线名称", "安全方式", "应用 AP / 频段", "VLAN", "下发状态", "操作"],
      rows,
    ),
  );
}
function renderVLANPools() {
  return panel(
    "VLAN 池",
    "在无线服务的“AP 与频段”中引用；不使用时可保持为空。",
    table(
      ["编号 / 名称", "VLAN 列表", "状态", "操作"],
      (data.config.vlan_pools || [])
        .map(
          (p) =>
            `<tr><td>${p.id} · ${esc(p.name)}</td><td>${esc(p.vlans)}</td><td>${p.deleting ? "等待删除" : "已保存"}</td><td><button class="text-button" data-pool="${p.id}">编辑</button><button class="text-button danger" data-delete-pool="${p.id}" ${p.deleting ? "disabled" : ""}>删除</button></td></tr>`,
        )
        .join(""),
    ),
    '<button class="secondary" data-new-pool="1">新建 VLAN 池</button>',
  );
}
let radioAPFilter = "";
function renderRadios() {
  const rows = data.aps
    .filter((ap) => !radioAPFilter || ap.id === radioAPFilter)
    .flatMap((ap) =>
      (ap.capabilities || []).map((c) => {
        const stats = ap.radio_statistics?.find(
            (r) => r.radio_id === c.radio_id,
          ),
          observed = ap.radio_status?.find((r) => r.radio_id === c.radio_id),
          native = ap.wireless_telemetry?.radios?.find(
            (r) => r.radioId === c.radio_id,
          );
        const state = data.apply.find(
          (s) => s.ap_id === ap.id && s.service_id === "radio:" + c.radio_id,
        );
        const bandwidth =
          { 0: 20, 1: 40, 3: 80, 5: 160, 6: 240 }[stats?.bandwidth_code] ??
          native?.bw;
        // Resource reports carry the radio power in dBm; statistics may use an AP-specific scale.
        const power = observed?.power_dbm;
        return `<tr><td><strong>${esc(apName(ap.id))}</strong><small>${ap.online ? "AP 在线" : "AP 离线"}</small></td><td>${esc(c.band)}<small>射频 ${c.radio_id} · ${c.support_11be ? "Wi-Fi 7" : c.support_11ax ? "Wi-Fi 6" : c.support_11ac ? "Wi-Fi 5" : "802.11n"}</small></td><td>${stats?.channel ?? observed?.channel ?? native?.channel ?? "—"}</td><td>${bandwidth ? esc(bandwidth) + " MHz" : "—"}</td><td>${power != null ? esc(power) + " dBm" : "—"}</td><td>${state ? statePill(state.state) : "等待上报"}<small>${esc(state?.error || "")}</small></td><td><button class="text-button" data-radio="${c.radio_id}" data-radio-ap="${esc(ap.id)}">配置射频</button></td></tr>`;
      }),
    )
    .join("");
  return panel(
    "AP 射频设置",
    "表格展示设备实际运行值。点击“配置射频”查看当前有效配置并修改。",
    table(
      [
        "AP",
        "频段 / 射频",
        "当前信道",
        "实际带宽",
        "发射功率",
        "配置状态",
        "操作",
      ],
      rows,
    ),
    select(
      "radio_ap_filter",
      "筛选 AP",
      {
        "": "全部 AP",
        ...Object.fromEntries(data.aps.map((a) => [a.id, apName(a.id)])),
      },
      radioAPFilter,
    ),
  );
}
function renderBandNavigation() {
  const policy = data.config.band_navigation,
    states = data.apply.filter((s) => s.service_id === "band-navigation");
  return (
    panel(
      "双频优选",
      "引导双频客户端优先接入同一 AP 的 5 GHz；不同 AP 之间的切换在“无缝漫游”中配置。",
      `<div class="interface-row"><div><strong>${policy?.enabled ? "已启用" : "未启用"}</strong><p>5 GHz 客户端门限 ${policy?.threshold_5g ?? 20} · 数量差值 ${policy?.difference ?? 4} · 最多失败 ${policy?.max_failures ?? 10} 次</p></div><button class="secondary" data-band-navigation="1" ${data.aps.some((a) => a.features?.band_navigation) ? "" : "disabled"}>配置双频优选</button></div>`,
    ) +
    panel(
      "应用状态",
      "按 AP 上报能力与下发结果显示。",
      table(
        ["AP", "状态", "说明"],
        states
          .map(
            (s) =>
              `<tr><td>${esc(apName(s.ap_id))}</td><td>${statePill(s.state)}</td><td>${esc(s.error || s.reason || "")}</td></tr>`,
          )
          .join(""),
      ),
    )
  );
}
function renderBackup() {
  return panel(
    "备份与恢复",
    "备份包含无线密钥、AP 账号和策略，请妥善保管。",
    `<div class="section-body"><div class="toolbar"><a class="secondary" href="/api/backup" download>下载完整配置备份</a><label class="secondary">恢复配置备份<input type="file" id="management-import" accept="application/json" class="hidden"></label></div><p class="help">恢复后会重新同步 AP；备份中没有的无线服务将进入删除流程。</p></div>`,
  );
}
