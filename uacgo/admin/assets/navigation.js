"use strict";

// The menu and page tabs share one hierarchy. Internal extension routes keep
// old bookmarks usable without adding implementation modules to the sidebar.
const navigationGroups = [
  { id: "status", label: "运行状态", pages: ["clients", "aps"] },
  {
    id: "ap",
    label: "AP管理",
    pages: [
      "apsettings",
      "upgrades",
      "balance",
      "mobility",
      "networkmode",
      "multicast",
    ],
  },
  { id: "radio", label: "射频管理", pages: ["radios", "rates", "band"] },
  { id: "wireless", label: "无线管理", pages: ["services"] },
  {
    id: "mesh",
    label: "易展设备管理",
    pages: ["mesh-topology", "mesh", "mesh-clients", "mesh-settings"],
  },
  { id: "security", label: "安全管理", pages: ["storm", "protection", "arp"] },
];
const pageGroups = {
  aps: ["AP状态", "status", ["aps", "history"]],
  clients: ["客户端状态", "status"],
  history: ["无线运行记录", "status", ["aps", "history"]],
  apsettings: ["AP设置", "ap", ["apsettings", "templates", "apdefaults"]],
  templates: ["AP模板", "ap", ["apsettings", "templates", "apdefaults"]],
  apdefaults: ["全局默认参数", "ap", ["apsettings", "templates", "apdefaults"]],
  upgrades: ["AP升级", "ap"],
  balance: ["负载均衡", "ap"],
  mobility: ["智能漫游", "ap"],
  networkmode: ["无线网络模式", "ap"],
  multicast: [
    "组播侦听",
    "ap",
    ["multicast", "multicast-query", "multicast-list"],
  ],
  "multicast-query": [
    "组播查询",
    "ap",
    ["multicast", "multicast-query", "multicast-list"],
  ],
  "multicast-list": [
    "组播白名单",
    "ap",
    ["multicast", "multicast-query", "multicast-list"],
  ],
  radios: ["射频设置", "radio", ["radios", "rrm", "edca"]],
  rrm: ["射频调优", "radio", ["radios", "rrm", "edca"]],
  edca: ["EDCA队列", "radio", ["radios", "rrm", "edca"]],
  rates: ["速率设置", "radio"],
  band: ["频谱导航", "radio"],
  services: ["无线服务设置", "wireless", ["services", "pools"]],
  pools: ["VLAN池", "wireless", ["services", "pools"]],
  "mesh-topology": ["拓扑结构", "mesh"],
  mesh: ["设备列表", "mesh", ["mesh", "mesh-upgrades"]],
  "mesh-upgrades": ["设备升级", "mesh", ["mesh", "mesh-upgrades"]],
  "mesh-clients": ["客户端列表", "mesh"],
  "mesh-settings": ["高级设置", "mesh"],
  storm: ["广播风暴抑制", "security"],
  protection: ["DHCP防护", "security", ["protection", "dhcp-servers"]],
  "dhcp-servers": ["DHCP服务器", "security", ["protection", "dhcp-servers"]],
  arp: ["ARP/ND防护", "security", ["arp", "arp-bindings"]],
  "arp-bindings": ["ARP/ND条目", "security", ["arp", "arp-bindings"]],
  interfaces: ["通信接口", "program", ["interfaces", "resources", "backup"]],
  resources: ["程序容量", "program", ["interfaces", "resources", "backup"]],
  backup: ["备份与恢复", "program", ["interfaces", "resources", "backup"]],
};
const routes = pageGroups;
const names = routes;
const routeAliases = { overview: "aps", management: "apsettings" };
const expandedNavigation = new Set(["status"]);
function resolveRoute(page) {
  return Object.hasOwn(routeAliases, page)
    ? routeAliases[page]
    : Object.hasOwn(routes, page)
      ? page
      : "aps";
}
function routeFamily(page) {
  return routes[resolveRoute(page)][1];
}
function initializeNavigation() {
  updateNavigation();
}
function headerActionsFor(page) {
  const map = {
    aps: '<a class="btn secondary" href="/api/aps/export" download>导出清单</a>',
    clients:
      '<a class="btn secondary" href="/api/clients/export" download>导出CSV</a>',
    templates:
      '<button class="btn secondary" type="button" data-template-new="1">新增模板</button>',
    pools:
      '<button class="btn secondary" type="button" data-new-pool="1">新增VLAN池</button>',
    "multicast-list":
      '<button class="btn secondary" type="button" data-multicast-bulk="1">批量编辑</button><button class="btn secondary" type="button" data-multicast-new="1">新增</button>',
    rrm: '<button class="btn secondary" type="button" data-rrm-status="1">优化记录</button>',
    edca: '<button class="btn secondary" type="button" data-edca-new="1">新增EDCA规则</button>',
    upgrades:
      '<label class="btn secondary file-btn">上传固件<input type="file" id="firmware-upload" accept=".bin" class="hidden" /></label>',
  };
  return map[page === "mesh-upgrades" ? "upgrades" : page] || "";
}
function updateNavigation() {
  const family = routeFamily(tab);
  expandedNavigation.add(family);
  $("#navigation").innerHTML = navigationGroups
    .map(
      (g) => `<section class="nav-group">
    <button type="button" class="nav-heading" data-nav-group="${g.id}" aria-expanded="${expandedNavigation.has(g.id)}">${g.label}<span aria-hidden="true">${expandedNavigation.has(g.id) ? "⌄" : "›"}</span></button>
    <div class="nav-children" ${expandedNavigation.has(g.id) ? "" : "hidden"}>${g.pages
      .map((id) => {
        const active = id === tab || routes[id][2]?.includes(tab);
        const label =
          { multicast: "组播管理", services: "无线服务" }[id] || names[id][0];
        return `<button type="button" data-view="${id}" class="${active ? "active" : ""}" ${active ? 'aria-current="page"' : ""}>${esc(label)}</button>`;
      })
      .join("")}</div></section>`,
    )
    .join("");
  const label =
    navigationGroups.find((g) => g.id === family)?.label || "程序设置";
  $("#title").textContent = names[tab][0];
  $("#breadcrumb").textContent = label + "　›　" + names[tab][0];
  $("#header-actions").innerHTML = headerActionsFor(tab);
  const pages = routes[tab][2] || [tab];
  $("#section-navigation").innerHTML =
    `<nav class="subnav" aria-label="${esc(label)}">${pages.map((id) => `<button type="button" data-view="${id}" class="${id === tab ? "active" : ""}" ${id === tab ? 'aria-current="page"' : ""}>${esc(names[id][0])}</button>`).join("")}</nav>`;
}
document.addEventListener("click", (event) => {
  const b = event.target.closest("[data-nav-group]");
  if (!b) return;
  const id = b.dataset.navGroup;
  if (expandedNavigation.has(id)) expandedNavigation.delete(id);
  else expandedNavigation.add(id);
  b.setAttribute("aria-expanded", String(expandedNavigation.has(id)));
  b.querySelector("span").textContent = expandedNavigation.has(id) ? "⌄" : "›";
  b.nextElementSibling.hidden = !expandedNavigation.has(id);
});
