"use strict";

// A single route definition drives the sidebar, section tabs and breadcrumb.
const navigationGroups = [
  { label: "", families: ["overview"] },
  {
    label: "配置无线网络",
    families: ["aps", "services", "radios", "mobility"],
  },
  { label: "查看运行状态", families: ["clients", "history"] },
  { label: "维护与程序", families: ["protection", "upgrades", "interfaces"] },
];
const navigationFamilies = {
  overview: { label: "总览", pages: ["overview"] },
  aps: {
    label: "AP 管理",
    pages: ["aps", "management", "templates", "apdefaults", "mesh"],
  },
  services: { label: "无线服务", pages: ["services", "pools", "multicast"] },
  radios: { label: "射频设置", pages: ["radios", "rates", "edca"] },
  mobility: {
    label: "无线优化",
    pages: ["mobility", "balance", "band", "rrm"],
  },
  clients: { label: "客户端状态", pages: ["clients"] },
  history: { label: "无线运行记录", pages: ["history"] },
  protection: { label: "AP 网络防护", pages: ["protection"] },
  upgrades: { label: "AP 固件升级", pages: ["upgrades"] },
  interfaces: {
    label: "程序设置",
    pages: ["interfaces", "resources", "backup"],
  },
};
const routes = {
  overview: ["总览", "先查看接入和同步情况，再从下方入口配置无线网络。"],
  aps: ["AP 列表", "在设备行进入单台 AP 的参数、分组、射频和同步状态。"],
  management: ["AP 分组", "把使用相同参数或无线服务的 AP 放到同一分组。"],
  templates: ["AP 模板", "为同型号、同硬件的 AP 复用一套配置。"],
  apdefaults: [
    "全局 AP 默认",
    "设置所有 AP 的基础参数；分组、模板和单台 AP 可覆盖这些值。",
  ],
  mesh: ["Mesh 组网", "管理 AP 的无线回传、节点配对与成员授权。"],
  services: [
    "无线服务列表",
    "建立无线名称和密码，选择在哪些 AP 与频段上广播。",
  ],
  pools: [
    "VLAN 池",
    "供无线服务引用的 VLAN 集合；不使用动态 VLAN 时无需配置。",
  ],
  multicast: ["组播地址列表", "管理无线服务使用的组播地址规则。"],
  radios: [
    "AP 射频设置",
    "选择 AP 和频段，配置无线模式、信道、带宽、功率及性能参数。",
  ],
  rates: ["速率表", "统一配置基础速率、支持速率和 MCS 索引。"],
  edca: ["EDCA 队列", "按 AP、分组和频段配置无线争用队列。"],
  mobility: [
    "无缝漫游",
    "配置 802.11k/v/r 与漫游触发门限，并按 AP 或分组应用。",
  ],
  balance: ["负载均衡", "在 AP 之间均衡新接入客户端，设置人数与拒绝次数门限。"],
  band: ["双频优选", "在同一 AP 的 2.4 GHz 与 5 GHz 之间引导双频客户端。"],
  rrm: [
    "自动射频优化",
    "协调多台 AP 的信道、带宽和功率，管理手动任务与优化计划。",
  ],
  clients: ["客户端状态", "查看终端实际连接到哪个 AP、无线服务和频段。"],
  history: [
    "无线运行记录",
    "查看无线趋势及已确认的客户端上线、离线和切换记录。",
  ],
  protection: [
    "AP 网络防护",
    "配置由 AP 执行的 DHCP/ARP/ND 防护、广播抑制与协议代理。",
  ],
  upgrades: ["AP 固件升级", "管理固件镜像、升级任务和版本确认结果。"],
  interfaces: [
    "通信接口",
    "选择程序与 AP 通信的网卡，接口调整在下次启动生效。",
  ],
  resources: ["运行容量", "配置独立 Go 控制器的对象容量和资源预算。"],
  backup: ["备份与恢复", "导出或恢复程序配置，包括无线服务、AP 参数与策略。"],
};
const names = routes;
function routeFamily(page) {
  return (
    Object.entries(navigationFamilies).find(([, f]) =>
      f.pages.includes(page),
    )?.[0] || "overview"
  );
}
function initializeNavigation() {
  $("#navigation").innerHTML = navigationGroups
    .map(
      (g) =>
        `<div class="nav-group">${g.label ? `<div class="nav-label">${esc(g.label)}</div>` : ""}${g.families.map((id) => `<button data-tab="${id}">${esc(navigationFamilies[id].label)}</button>`).join("")}</div>`,
    )
    .join("");
}
function updateNavigation() {
  const family = routeFamily(tab),
    group = navigationFamilies[family];
  $$("nav [data-tab]").forEach((b) =>
    b.classList.toggle("active", b.dataset.tab === family),
  );
  $("#breadcrumb").textContent =
    group.label + (group.pages.length > 1 ? " / " + names[tab][0] : "");
  $("#title").textContent = names[tab][0];
  $("#description").textContent = names[tab][1];
  $("#summary").classList.toggle("hidden", tab !== "overview");
  $("#new-service").classList.toggle("hidden", tab !== "services");
  $("#section-navigation").innerHTML =
    group.pages.length > 1
      ? `<nav class="section-navigation" aria-label="${esc(group.label)}的功能页">${group.pages.map((id) => `<button data-view="${id}" class="${id === tab ? "active" : ""}" ${id === tab ? 'aria-current="page"' : ""}>${esc(names[id][0])}</button>`).join("")}</nav>`
      : "";
}
