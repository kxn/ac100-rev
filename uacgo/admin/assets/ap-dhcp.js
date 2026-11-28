"use strict";

let apDHCPState = null;

function dhcpReservationRow(mac = "", ip = "") {
  return `<tr data-dhcp-reservation><td><input name="reservation_mac" aria-label="预留 MAC" value="${esc(mac)}" placeholder="02:00:00:00:00:01"></td><td><input name="reservation_ip" aria-label="预留 IP" value="${esc(ip)}" placeholder="192.0.2.250"></td><td><button type="button" class="text-button danger" data-dhcp-remove>删除</button></td></tr>`;
}

function renderAPDHCP() {
  const p = apDHCPState;
  if (!p) return panel("AP DHCP服务", '<div class="empty">加载中…</div>');
  if (p.available === false) return panel("AP DHCP服务", '<div class="empty">启动参数已禁用 DHCP 管理服务。容器需使用带 DHCP 权限的配置；普通启动可移除 --ap-dhcp off。</div>');
  const c = p.settings;
  const leases = (p.leases || []).map((l) => {
    const mac = l.mac?.length === 12 ? l.mac.match(/../g).join(":") : l.mac;
    return `<tr><td class="mono">${esc(mac || "—")}</td><td class="mono">${esc(l.ip)}</td><td>${l.bound ? "已确认 ACK" : "待确认 OFFER / 保留"}</td><td>${esc(new Date(l.expires).toLocaleString("zh-CN", { hour12: false }))}</td></tr>`;
  }).join("");
  return panel(
    "AP DHCP服务",
    `<p>运行状态：<span class="pill ${p.running ? "online" : ""}">${p.running ? "运行中" : "已停止"}</span>${p.error ? ` <span class="form-error">${esc(p.error)}</span>` : ""}</p>
    <form id="ap-dhcp-form" data-inline="1" novalidate>
      <div class="form-grid">
        <div class="full">${toggle("enabled", "启用 AP DHCP 服务", c.enabled)}</div>
        ${field("interface", "绑定接口", c.interface || "", "text", "readonly")}
        ${field("server", "DHCP服务器地址", c.server || "", "text")}
        ${field("start", "地址池起始地址", c.start || "", "text")}
        ${field("end", "地址池结束地址", c.end || "", "text")}
        ${field("netmask", "子网掩码", c.netmask || "", "text")}
        ${field("gateway", "默认网关", c.gateway || "", "text")}
        ${field("dns", "DNS地址（逗号分隔）", (c.dns || []).join(", "), "text")}
        ${field("ac", "AC发现地址（逗号分隔）", (c.ac || []).join(", "), "text")}
        ${field("lease_seconds", "租期", c.lease_seconds, "number", 'min="60" max="604800"', "秒")}
      </div>
      <h3 class="section-title">固定地址预留</h3>
      ${table(["AP MAC", "预留 IP", "操作"], Object.entries(c.reservations || {}).map(([mac, ip]) => dhcpReservationRow(mac, ip)).join(""))}
      <button type="button" class="btn secondary" data-dhcp-add>新增预留</button>
      <p class="help">仅回应 TP-LINK AP；按原 AC 携带厂商标识及 AC 发现选项。此页管理地址分配服务；DHCP防护用于下发 AP 的防护规则。</p>
      <p class="help">保存立即作用于 DHCP，不重启 AC 或 AP。已有租约及其他 DHCP 服务器分配的地址不会被强制收回；固定预留在 AP 再次选择本服务时生效。</p>
      ${formEnd("保存并应用")}
    </form>`,
  ) + panel("当前租约与待确认分配", table(["AP MAC", "地址", "状态", "到期时间"], leases));
}

document.addEventListener("click", (event) => {
  if (event.target.closest("[data-dhcp-add]")) {
    const form = $("#ap-dhcp-form");
    const body = form.querySelector("tbody");
    body.querySelector(".empty")?.closest("tr")?.remove();
    body.insertAdjacentHTML("beforeend", dhcpReservationRow());
    form.dataset.dirty = "1";
  }
  const remove = event.target.closest("[data-dhcp-remove]");
  if (remove) {
    remove.closest("form").dataset.dirty = "1";
    remove.closest("tr").remove();
  }
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (f.id !== "ap-dhcp-form") return;
  event.preventDefault();
  if (!validateForm(f)) return;
  const button = f.querySelector('[type="submit"]');
  button.disabled = true;
  try {
    const reservations = {};
    for (const row of f.querySelectorAll("[data-dhcp-reservation]")) {
      const mac = row.querySelector('[name="reservation_mac"]').value.trim();
      const ip = row.querySelector('[name="reservation_ip"]').value.trim();
      if (!mac && !ip) continue;
      if (Object.hasOwn(reservations, mac)) throw new Error("存在重复的预留 MAC");
      reservations[mac] = ip;
    }
    const split = (value) => value.split(/[\s,]+/).filter(Boolean);
    apDHCPState = await api("ap-dhcp", {
      enabled: f.elements.enabled.checked,
      interface: f.elements.interface.value,
      server: f.elements.server.value.trim(),
      start: f.elements.start.value.trim(),
      end: f.elements.end.value.trim(),
      netmask: f.elements.netmask.value.trim(),
      gateway: f.elements.gateway.value.trim(),
      dns: split(f.elements.dns.value),
      ac: split(f.elements.ac.value),
      lease_seconds: Number(f.elements.lease_seconds.value),
      reservations,
    });
    delete f.dataset.dirty;
    await refresh();
    toast("AP DHCP配置已应用");
  } catch (error) {
    f.querySelector(".form-error").textContent = error.message;
  } finally {
    button.disabled = false;
  }
});
