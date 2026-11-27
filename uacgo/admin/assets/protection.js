"use strict";

let protectionEdit = null;
let protectionTab = "rules";
let stormDefaults = null;

function protectionConfig() {
  return structuredClone(
    data.config.protection || { servers: [], bindings: [], rules: [] },
  );
}

function renderProtection() {
  const p = protectionConfig();
  protectionTab =
    { storm: "storm", "dhcp-servers": "servers", "arp-bindings": "bindings" }[
      tab
    ] || "rules";
  const subAction =
    {
      rules:
        '<button type="button" class="btn secondary" data-defense-kind="rules">新增规则</button>',
      servers:
        '<button type="button" class="btn secondary" data-defense-kind="servers">新增服务器</button>',
      bindings:
        '<button type="button" class="btn secondary" data-defense-kind="bindings">新增条目</button>',
    }[protectionTab] || "";
  const subbar = subAction
    ? `<div class="page-toolbar">${subAction}</div>`
    : "";

  if (protectionTab === "servers") {
    return (
      subbar +
      panel(
        "DHCP 信任服务器",
        table(
          ["名称", "可信地址", "操作"],
          p.servers
            .map(
              (s) => `<tr>
                <td><strong>${esc(s.name)}</strong></td>
                <td class="mono">${esc(s.address)}</td>
                <td>
                  <div class="actions">
                    <button type="button" class="text-button" data-defense-kind="servers" data-defense-id="${esc(s.id)}">编辑</button>
                    <button type="button" class="text-button danger" data-defense-delete="servers" data-defense-id="${esc(s.id)}">删除</button>
                  </div>
                </td>
              </tr>`,
            )
            .join(""),
        ),
      )
    );
  }

  if (protectionTab === "bindings") {
    return (
      subbar +
      panel(
        "ARP / ND 静态绑定",
        table(
          ["名称", "IP / MAC", "说明", "操作"],
          p.bindings
            .map(
              (s) => `<tr>
                <td><strong>${esc(s.name)}</strong></td>
                <td class="mono">${esc(s.ip)}<small>${esc(s.mac)}</small></td>
                <td>${esc(s.description || "—")}</td>
                <td>
                  <div class="actions">
                    <button type="button" class="text-button" data-defense-kind="bindings" data-defense-id="${esc(s.id)}">编辑</button>
                    <button type="button" class="text-button danger" data-defense-delete="bindings" data-defense-id="${esc(s.id)}">删除</button>
                  </div>
                </td>
              </tr>`,
            )
            .join(""),
        ),
      )
    );
  }

  if (protectionTab === "storm") {
    if (!stormDefaults) {
      void api("storm/defaults")
        .then((res) => {
          stormDefaults = res;
          if (tab === "storm") renderContent();
        })
        .catch(() => {});
      return (
        subbar +
        panel("广播抑制与协议代理", '<div class="empty">加载配置中…</div>')
      );
    }
    const d = stormDefaults;
    const s = data.config.storm || d.defaults;
    protectionEdit = { storm: s };
    const scope = { 1: "无线", 2: "有线", 3: "全部" };
    const formHtml = `<div class="panel-body">
      <form id="storm-form" data-inline="1" novalidate>
        <div class="form-grid">
          ${toggle("enabled", "启用广播抑制", s.enabled)}
          ${field("rate", "总速率上限", s.rate, "number", 'min="1" max="1024" required', "包/秒")}
          <div class="full">${check("custom", "启用分协议速率限制", s.custom)}</div>
        </div>
        <h3 class="section-title">分协议限制</h3>
        ${table(
          ["协议", "启用", "应用范围", "速率（包/秒）"],
          d.protocols
            .map(
              (name, i) => `<tr>
                <td><strong>${esc(name)}</strong></td>
                <td>${check("protocol_" + i + "_enabled", "", s.protocols[i].enabled)}</td>
                <td>${select("protocol_" + i + "_scope", "", scope, s.protocols[i].scope)}</td>
                <td>${field("protocol_" + i + "_rate", "", s.protocols[i].rate, "number", 'min="0" max="1024" required')}</td>
              </tr>`,
            )
            .join(""),
        )}
        <div class="proxy-grid">
          ${["arp", "nd", "mdns"]
            .map(
              (k) => `<fieldset>
                <legend>${k.toUpperCase()} 代理</legend>
                ${toggle(k + "_enabled", "启用代理", s[k + "_proxy"].enabled)}
                ${k !== "mdns" ? select(k + "_scope", "范围", scope, s[k + "_proxy"].scope) : ""}
                ${check(k + "_unicast", "转为单播", s[k + "_proxy"].to_unicast)}
              </fieldset>`,
            )
            .join("")}
        </div>
        ${formEnd()}
      </form>
    </div>`;
    return subbar + panel("广播抑制与协议代理", formHtml);
  }

  return (
    subbar +
    panel(
      "AP 防护规则",
      table(
        [
          "名称",
          "应用范围",
          tab === "protection" ? "DHCP防护" : "ARP/ND防护",
          "引用",
          "设置",
        ],
        p.rules
          .map(
            (s) => `<tr>
              <td><strong>${esc(s.name)}</strong></td>
              <td>${esc(targetSummary(s))}</td>
              <td>${tab === "protection" ? (s.dhcp ? "启用" : "禁用") : s.arp ? (s.filter ? "过滤非绑定" : "仅防冒用") : "禁用"}</td>
              <td class="num">${tab === "protection" ? s.servers.length + " 个服务器" : s.bindings.length + " 个绑定"}</td>
              <td>
                <div class="actions">
                  <button type="button" class="text-button" data-defense-kind="rules" data-defense-id="${esc(s.id)}">编辑</button>
                  <button type="button" class="text-button danger" data-defense-delete="rules" data-defense-id="${esc(s.id)}">删除</button>
                </div>
              </td>
            </tr>`,
          )
          .join(""),
      ),
    ) +
    '<details class="advanced-section"><summary>设备能力与地址扫描</summary>' +
    panel(
      "设备能力与地址扫描",
      table(
        ["AP", "防护能力", "同步状态", "操作"],
        data.aps
          .map(
            (a) => `<tr>
              <td><strong>${esc(apName(a.id))}</strong></td>
              <td>
                ${
                  [
                    ["dhcp_defense", "DHCPv4"],
                    ["dhcpv6_defense", "DHCPv6"],
                    ["arp_defense", "ARP"],
                    ["nd_defense", "ND"],
                    ["storm_control", "广播抑制"],
                  ]
                    .filter(([k]) => a.features?.[k])
                    .map(([, v]) => `<span class="tag">${v}</span>`)
                    .join(" ") || '<span class="muted">未声明</span>'
                }
                ${a.protection_limits ? `<small class="num">绑定上限：ARP ${a.protection_limits.arp} / ND ${a.protection_limits.nd}</small>` : ""}
              </td>
              <td>${
                data.apply
                  .filter(
                    (x) =>
                      x.ap_id === a.id &&
                      ["protection", "storm"].includes(x.service_id),
                  )
                  .map(
                    (x) =>
                      statePill(x.state) +
                      (x.error ? `<small>${esc(x.error)}</small>` : ""),
                  )
                  .join(" ") || '<span class="muted">未下发</span>'
              }</td>
              <td>${a.online && a.features?.arp_scan ? `<div class="actions"><button type="button" class="text-button" data-arp-scan="${esc(a.id)}">地址扫描</button><button type="button" class="text-button" data-arp-results="${esc(a.id)}">扫描结果</button></div>` : '<span class="muted">—</span>'}</td>
            </tr>`,
          )
          .join(""),
      ),
    ) +
    "</details>"
  );
}

function defensePicker(name, label, rows, chosen) {
  const set = new Set(chosen || []);
  return `<div class="picker-box">
    <div class="picker-head"><span>${label}</span><span>已选 ${set.size}</span></div>
    <div class="picker-list">${
      rows
        .map(
          (x) =>
            `<label class="picker-item"><input type="checkbox" name="${name}" value="${esc(x.id)}" ${set.has(x.id) ? "checked" : ""}><span>${esc(x.name)}</span></label>`,
        )
        .join("") || '<span class="help">暂无记录</span>'
    }</div>
  </div>`;
}

document.addEventListener("click", async (e) => {
  const b = e.target.closest("button");
  if (!b) return;
  try {
    if (b.dataset.protectionTab) {
      protectionTab = b.dataset.protectionTab;
      if (protectionTab === "storm" && !stormDefaults) {
        stormDefaults = await api("storm/defaults");
      }
      renderContent();
      return;
    }
    if (b.dataset.arpScan) {
      await api(
        "aps/" + encodeURIComponent(b.dataset.arpScan) + "/arp-scan",
        {},
      );
      toast("已发送扫描请求");
      return;
    }
    if (b.dataset.arpResults) {
      const request = beginEditorRequest();
      const p = await api(
        "aps/" + encodeURIComponent(b.dataset.arpResults) + "/arp-scan",
      );
      if (!isCurrentEditorRequest(request)) return;
      openDialog(
        "arp-results",
        "AP 地址扫描结果",
        p.report
          ? "上报时间：" + new Date(p.report.at).toLocaleString("zh-CN")
          : "",
        p.report
          ? table(
              ["IP", "MAC", "操作"],
              p.report.entries
                .map(
                  (v) =>
                    `<tr><td class="mono">${esc(v.ip)}</td><td class="mono">${esc(v.mac)}</td><td><button type="button" class="text-button" data-arp-import-ip="${esc(v.ip)}" data-arp-import-mac="${esc(v.mac)}">加入静态绑定</button></td></tr>`,
                )
                .join(""),
            )
          : '<div class="empty">尚未收到扫描结果</div>',
      );
      return;
    }
    if (b.dataset.arpImportIp) {
      const p = protectionConfig();
      p.bindings.push({
        id: newID(),
        name: b.dataset.arpImportIp,
        ip: b.dataset.arpImportIp,
        mac: b.dataset.arpImportMac,
        description: "地址扫描导入",
      });
      await api("protection", p);
      closeEditorFor(b);
      await refresh();
      toast("已加入静态绑定");
      return;
    }
    if (b.dataset.defenseDelete) {
      const p = protectionConfig();
      const kind = b.dataset.defenseDelete;
      const id = b.dataset.defenseId;
      if (kind !== "rules" && p.rules.some((r) => r[kind].includes(id)))
        throw Error("该记录正在被防护规则引用");
      if (
        !confirm(
          kind === "rules"
            ? "删除整条规则，包括其中的DHCP和ARP/ND防护设置？"
            : "确认删除？",
        )
      )
        return;
      p[kind] = p[kind].filter((r) => r.id !== id);
      await api("protection", p);
      await refresh();
      return;
    }
    if (b.dataset.defenseKind) {
      const kind = b.dataset.defenseKind;
      const p = protectionConfig();
      const item = p[kind].find((x) => x.id === b.dataset.defenseId) || {
        id: newID(),
        name: "",
        ...(kind === "rules"
          ? {
              servers: [],
              bindings: [],
              wired: true,
              wireless: true,
              filter: true,
            }
          : {}),
      };
      protectionEdit = { kind, p, item };
      let body = `<div class="form-grid">${field("name", "名称", item.name, "text", 'required maxlength="50"')}`;
      if (kind === "servers")
        body += `${field("address", "可信 IP 或 MAC", item.address || "", "text", "required")}</div>`;
      if (kind === "bindings")
        body += `${field("ip", "IP 地址", item.ip || "", "text", "required")}${field("mac", "MAC 地址", item.mac || "", "text", "required")}<div class="full">${field("description", "说明", item.description || "", "text", 'maxlength="128"')}</div></div>`;
      if (kind === "rules") {
        const dhcp = tab === "protection";
        body +=
          '<p class="help">AP应用范围由此规则中的DHCP与ARP/ND防护共用。本页仅修改对应防护参数；不同范围请分别建立规则。</p>';
        body += `</div><div class="form-grid">${targetPicker(item.aps || [], item.groups || [])}
          ${dhcp ? check("dhcp", "启用DHCP防护", item.dhcp) : check("arp", "启用ARP/ND防护", item.arp) + check("filter", "仅允许静态绑定地址", item.filter) + check("wired", "保护有线端口", item.wired) + check("wireless", "保护无线客户端", item.wireless)}
          </div><div data-defense-records="${dhcp ? "servers" : "bindings"}">${dhcp ? defensePicker("servers", "合法DHCP服务器", p.servers, item.servers) : defensePicker("bindings", "ARP/ND条目", p.bindings, item.bindings)}</div>`;
      }
      const titles = {
        servers: "DHCP 信任服务器",
        bindings: "ARP / ND 静态绑定",
        rules: "AP 防护规则",
      };
      openDialog(
        "protection",
        (b.dataset.defenseId ? "编辑" : "新建") + titles[kind],
        "",
        `<form id="defense-form" novalidate>${body}${formEnd()}</form>`,
      );
    }
  } catch (err) {
    toast(err.message);
  }
});

document.addEventListener("submit", async (e) => {
  const f = e.target;
  if (!["defense-form", "storm-form"].includes(f.id)) return;
  e.preventDefault();
  if (!validateForm(f)) return;
  const btn = f.querySelector('[type="submit"]');
  btn.disabled = true;
  try {
    const n = (k) => Number(f.elements[k].value);
    if (f.id === "defense-form") {
      const { p, kind, item } = protectionEdit;
      const next = { ...item, name: f.elements.name.value };
      if (kind === "servers") next.address = f.elements.address.value.trim();
      if (kind === "bindings")
        for (const k of ["ip", "mac", "description"])
          next[k] = f.elements[k].value.trim();
      if (kind === "rules") {
        Object.assign(next, readTargetPicker(f));
        for (const k of ["arp", "dhcp", "filter", "wired", "wireless"])
          if (f.elements[k]) next[k] = f.elements[k].checked;
        for (const k of ["servers", "bindings"])
          if (f.querySelector(`[data-defense-records="${k}"]`))
            next[k] = [...f.querySelectorAll(`input[name="${k}"]:checked`)].map(
              (o) => o.value,
            );
      }
      const i = p[kind].findIndex((x) => x.id === next.id);
      if (i < 0) p[kind].push(next);
      else p[kind][i] = next;
      await api("protection", p);
    } else {
      const s = structuredClone(
        protectionEdit?.storm || data.config.storm || stormDefaults.defaults,
      );
      s.enabled = f.elements.enabled.checked;
      s.custom = f.elements.custom.checked;
      s.rate = n("rate");
      s.protocols = s.protocols.map((_, i) => ({
        enabled: f.elements["protocol_" + i + "_enabled"].checked,
        scope: n("protocol_" + i + "_scope"),
        rate: n("protocol_" + i + "_rate"),
      }));
      for (const k of ["arp", "nd", "mdns"])
        s[k + "_proxy"] = {
          enabled: f.elements[k + "_enabled"].checked,
          to_unicast: f.elements[k + "_unicast"].checked,
          scope: k === "mdns" ? 3 : n(k + "_scope"),
        };
      await api("storm", s);
    }
    delete f.dataset.dirty;
    closeEditorFor(f);
    await refresh();
    toast("防护配置已保存");
  } catch (err) {
    const errEl = f.querySelector(".form-error");
    if (errEl) errEl.textContent = err.message;
    else toast(err.message);
  } finally {
    btn.disabled = false;
  }
});
