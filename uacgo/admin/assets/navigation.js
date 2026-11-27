"use strict";

const navigationGroups = [
  { label: "", families: ["overview", "aps", "clients", "history"] },
  { label: "无线", families: ["services", "radios", "mobility", "protection"] },
  { label: "系统", families: ["upgrades", "interfaces"] },
];

const navigationFamilies = {
  overview: { label: "概览", icon: "overview", pages: ["overview"] },
  aps: {
    label: "AP 管理",
    icon: "aps",
    pages: ["aps", "management", "templates", "apdefaults", "mesh"],
  },
  clients: { label: "客户端", icon: "clients", pages: ["clients"] },
  history: { label: "运行统计", icon: "history", pages: ["history"] },
  services: {
    label: "无线网络",
    icon: "services",
    pages: ["services", "pools", "multicast"],
  },
  radios: {
    label: "射频管理",
    icon: "radios",
    pages: ["radios", "rrm", "rates", "edca"],
  },
  mobility: {
    label: "漫游与均衡",
    icon: "mobility",
    pages: ["mobility", "balance", "band"],
  },
  protection: { label: "网络防护", icon: "protection", pages: ["protection"] },
  upgrades: { label: "固件升级", icon: "upgrades", pages: ["upgrades"] },
  interfaces: {
    label: "系统设置",
    icon: "settings",
    pages: ["interfaces", "resources", "backup"],
  },
};

const routes = {
  overview: ["概览"],
  aps: ["设备列表"],
  management: ["分组"],
  templates: ["模板"],
  apdefaults: ["全局默认"],
  mesh: ["Mesh"],
  services: ["无线服务"],
  pools: ["VLAN 池"],
  multicast: ["组播列表"],
  radios: ["射频配置"],
  rrm: ["射频调优"],
  rates: ["速率表"],
  edca: ["EDCA"],
  mobility: ["无缝漫游"],
  balance: ["负载均衡"],
  band: ["双频优选"],
  clients: ["客户端"],
  history: ["运行统计"],
  protection: ["网络防护"],
  upgrades: ["固件升级"],
  interfaces: ["通信接口"],
  resources: ["容量配额"],
  backup: ["备份与恢复"],
};

const names = routes;

function navIcon(name) {
  const paths = {
    overview:
      '<rect x="3" y="3" width="7" height="7" rx="1.5"/><rect x="14" y="3" width="7" height="7" rx="1.5"/><rect x="3" y="14" width="7" height="7" rx="1.5"/><rect x="14" y="14" width="7" height="7" rx="1.5"/>',
    aps: '<rect x="5" y="4" width="14" height="16" rx="2"/><circle cx="12" cy="10" r="2"/><path d="M9 16h6"/>',
    clients:
      '<rect x="5" y="3" width="14" height="10" rx="1.5"/><path d="M2 18h20"/><path d="M9 13v5m6-5v5"/>',
    history:
      '<polyline points="3 17 9 11 13 15 21 7"/><polyline points="16 7 21 7 21 12"/>',
    services:
      '<path d="M5 12.55a11 11 0 0 1 14.08 0"/><path d="M8.53 16.11a6 6 0 0 1 6.95 0"/><circle cx="12" cy="19.5" r="1" fill="currentColor"/>',
    radios:
      '<path d="M12 12v8"/><circle cx="12" cy="10" r="2"/><path d="M6.34 15.66a8 8 0 0 1 0-11.32"/><path d="M17.66 4.34a8 8 0 0 1 0 11.32"/>',
    mobility:
      '<path d="M17 3l4 4-4 4"/><path d="M3 7h18"/><path d="M7 21l-4-4 4-4"/><path d="M21 17H3"/>',
    protection:
      '<path d="M12 3l8 3v6c0 4.5-3.4 7.7-8 9-4.6-1.3-8-4.5-8-9V6l8-3z"/>',
    upgrades:
      '<path d="M12 15V4"/><polyline points="7 9 12 4 17 9"/><path d="M4 17v2a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2v-2"/>',
    settings:
      '<circle cx="12" cy="12" r="3"/><path d="M19.4 15a1.65 1.65 0 0 0 .33 1.82l.06.06a2 2 0 1 1-2.83 2.83l-.06-.06a1.65 1.65 0 0 0-1.82-.33 1.65 1.65 0 0 0-1 1.51V21a2 2 0 1 1-4 0v-.09a1.65 1.65 0 0 0-1-1.51 1.65 1.65 0 0 0-1.82.33l-.06.06a2 2 0 1 1-2.83-2.83l.06-.06a1.65 1.65 0 0 0 .33-1.82 1.65 1.65 0 0 0-1.51-1H3a2 2 0 1 1 0-4h.09a1.65 1.65 0 0 0 1.51-1 1.65 1.65 0 0 0-.33-1.82l-.06-.06a2 2 0 1 1 2.83-2.83l.06.06a1.65 1.65 0 0 0 1.82.33H9a1.65 1.65 0 0 0 1-1.51V3a2 2 0 1 1 4 0v.09a1.65 1.65 0 0 0 1 1.51 1.65 1.65 0 0 0 1.82-.33l.06-.06a2 2 0 1 1 2.83 2.83l-.06.06a1.65 1.65 0 0 0-.33 1.82V9c0 .69.4 1.31 1.02 1.58.3.13.62.2.95.2H21a2 2 0 1 1 0 4h-.09a1.65 1.65 0 0 0-1.51 1z"/>',
  };
  return `<svg class="nav-icon" viewBox="0 0 24 24" width="16" height="16" fill="none" stroke="currentColor" stroke-width="1.75" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true">${paths[name] || ""}</svg>`;
}

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
        `<div class="nav-group">${g.label ? `<div class="nav-label">${esc(g.label)}</div>` : ""}${g.families
          .map((id) => {
            const f = navigationFamilies[id];
            const badge =
              id === "aps" || id === "clients"
                ? `<span class="nav-badge num hidden" id="nav-badge-${id}"></span>`
                : "";
            return `<button type="button" data-tab="${id}">${navIcon(f.icon)}<span class="nav-text">${esc(f.label)}</span>${badge}</button>`;
          })
          .join("")}</div>`,
    )
    .join("");
}

function headerActionsFor(page) {
  const map = {
    aps: '<button class="btn secondary" type="button" data-ap-batch-names="1">批量命名</button><a class="btn secondary" href="/api/aps/export" download>导出清单</a>',
    management:
      '<button class="btn primary" type="button" data-group-new="1">新建分组</button>',
    templates:
      '<button class="btn primary" type="button" data-template-new="1">新建模板</button>',
    clients:
      '<a class="btn secondary" href="/api/clients/export" download>导出 CSV</a>',
    services:
      '<button class="btn primary" id="new-service" type="button">新建无线服务</button>',
    pools:
      '<button class="btn primary" type="button" data-new-pool="1">新建 VLAN 池</button>',
    multicast:
      '<button class="btn secondary" type="button" data-multicast-bulk="1">批量编辑</button><button class="btn primary" type="button" data-multicast-new="1">添加规则</button>',
    rrm: '<button class="btn secondary" type="button" data-rrm-status="1">优化记录</button>',
    edca: '<button class="btn primary" type="button" data-edca-new="1">新建 EDCA 规则</button>',
    mobility: "",
    balance: "",
    upgrades:
      '<label class="btn primary file-btn">上传固件<input type="file" id="firmware-upload" accept=".bin" class="hidden" /></label>',
  };
  return map[page] || "";
}

function updateNavigation() {
  const family = routeFamily(tab);
  const group = navigationFamilies[family];
  $$("#navigation [data-tab]").forEach((b) =>
    b.classList.toggle("active", b.dataset.tab === family),
  );
  $("#title").textContent = group.label;
  $("#header-actions").innerHTML = headerActionsFor(tab);
  const subnav = $("#section-navigation");
  if (group.pages.length > 1) {
    subnav.classList.remove("hidden");
    subnav.innerHTML = `<nav class="subnav" aria-label="${esc(group.label)}">${group.pages
      .map(
        (id) =>
          `<button type="button" data-view="${id}" class="${id === tab ? "active" : ""}" ${id === tab ? 'aria-current="page"' : ""}>${esc(names[id][0])}</button>`,
      )
      .join("")}</nav>`;
  } else {
    subnav.classList.add("hidden");
    subnav.innerHTML = "";
  }
}
