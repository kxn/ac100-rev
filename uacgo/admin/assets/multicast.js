"use strict";

let multicastEditIndex = -1;

function renderMulticastGroups() {
  const rows = (data.config.multicast_groups || [])
    .map(
      (r, idx) => `<tr>
        <td class="mono">${esc(r.ip)}</td>
        <td>${r.relay ? "允许转发" : "阻止转发"}</td>
        <td><span class="pill ${r.enabled ? "online" : ""}">${r.enabled ? "启用" : "停用"}</span></td>
        <td>
          <div class="actions">
            <button type="button" class="text-button" data-multicast-edit="${idx}">编辑</button>
            <button type="button" class="text-button danger" data-multicast-delete="${idx}">删除</button>
          </div>
        </td>
      </tr>`,
    )
    .join("");
  return panel(
    "组播地址列表",
    table(["组播 IP", "策略", "状态", "操作"], rows),
  );
}

function openMulticastItemModal(idx) {
  const list = data.config.multicast_groups || [];
  const item =
    idx >= 0 && list[idx] ? list[idx] : { ip: "", relay: true, enabled: true };
  multicastEditIndex = idx;
  openDialog(
    "multicast-item",
    idx >= 0 ? "编辑组播规则" : "添加组播规则",
    "",
    `<form id="multicast-item-form" novalidate>
      <div class="form-grid">
        ${field("ip", "组播 IP 地址", item.ip, "text", 'required placeholder="239.1.2.3"')}
        ${select("relay", "转发策略", { 1: "允许转发", 0: "阻止转发" }, item.relay ? "1" : "0")}
        <div class="full">${toggle("enabled", "启用规则", item.enabled)}</div>
      </div>
      ${formEnd()}
    </form>`,
  );
}

document.addEventListener("click", async (event) => {
  const b = event.target.closest("button");
  if (!b) return;
  try {
    if (b.dataset.multicastNew) {
      openMulticastItemModal(-1);
      return;
    }
    if (b.dataset.multicastEdit != null) {
      openMulticastItemModal(Number(b.dataset.multicastEdit));
      return;
    }
    if (b.dataset.multicastDelete != null) {
      const idx = Number(b.dataset.multicastDelete);
      const next = (data.config.multicast_groups || []).filter(
        (_, i) => i !== idx,
      );
      await api("multicast-groups", next);
      await refresh();
      toast("已删除组播规则");
      return;
    }
    if (b.dataset.multicastBulk) {
      openDialog(
        "multicast-groups",
        "批量编辑组播列表",
        "",
        `<form id="multicast-groups-form" novalidate>
          <p class="help">每行一条：IP,允许转发(1/0),启用(1/0)，最多 32 条。</p>
          <label><span>组播列表</span><textarea name="entries" rows="12" placeholder="239.1.2.3,1,1">${esc((data.config.multicast_groups || []).map((r) => [r.ip, r.relay ? 1 : 0, r.enabled ? 1 : 0].join(",")).join("\n"))}</textarea></label>
          ${formEnd()}
        </form>`,
      );
    }
  } catch (e) {
    toast(e.message);
  }
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (f.id === "multicast-item-form") {
    event.preventDefault();
    if (!validateForm(f)) return;
    const btn = f.querySelector('[type="submit"]');
    btn.disabled = true;
    try {
      const next = structuredClone(data.config.multicast_groups || []);
      const row = {
        ip: f.elements.ip.value.trim(),
        relay: f.elements.relay.value === "1",
        enabled: f.elements.enabled.checked,
      };
      if (multicastEditIndex >= 0 && multicastEditIndex < next.length)
        next[multicastEditIndex] = row;
      else next.push(row);
      await api("multicast-groups", next);
      closeEditorFor(f);
      await refresh();
      toast("组播策略已保存");
    } catch (e) {
      f.querySelector(".form-error").textContent = e.message;
    } finally {
      btn.disabled = false;
    }
    return;
  }
  if (f.id !== "multicast-groups-form") return;
  event.preventDefault();
  const btn = f.querySelector('[type="submit"]');
  btn.disabled = true;
  try {
    const rows = f.elements.entries.value
      .split("\n")
      .map((s) => s.trim())
      .filter(Boolean)
      .map((s) => {
        const a = s.split(",").map((x) => x.trim());
        if (
          a.length !== 3 ||
          !["0", "1"].includes(a[1]) ||
          !["0", "1"].includes(a[2])
        )
          throw Error("格式为 IP,转发(1/0),启用(1/0)");
        return { ip: a[0], relay: a[1] === "1", enabled: a[2] === "1" };
      });
    await api("multicast-groups", rows);
    closeEditorFor(f);
    await refresh();
    toast("组播策略已保存");
  } catch (e) {
    f.querySelector(".form-error").textContent = e.message;
  } finally {
    btn.disabled = false;
  }
});

let multicastServiceID = "";
function renderMulticastSettings(view) {
  const services = data.config.services.filter((s) => !s.deleting);
  const service =
    services.find((s) => s.id === multicastServiceID) || services[0];
  if (!service)
    return panel(
      view === "query" ? "组播查询" : "组播侦听",
      '<p class="help">请先在无线管理中创建无线服务。</p>',
    );
  multicastServiceID = service.id;
  const m = optionDefaults(service).multicast;
  const options = Object.fromEntries(services.map((s) => [s.id, s.ssid]));
  const targets = service.bindings?.length
    ? data.aps.filter((a) => service.bindings.some((b) => b.ap_id === a.id))
    : selectedAPs(service);
  const global = targets.every((a) => a.features?.multicast);
  const ssid = targets.every((a) => a.features?.multicast_per_ssid);
  const unicast =
    global && targets.every((a) => a.features?.multicast_to_unicast);
  const editable = global || ssid;
  return panel(
    view === "query" ? "组播查询设置" : "组播侦听设置",
    `<form id="multicast-settings-form" data-inline="1" data-kind="${view}" data-service-id="${esc(service.id)}" novalidate><div class="form-grid">
    ${select("multicast_service", "无线服务", options, service.id)}
    ${view === "query" ? `${ssid ? check("query", "组播查询", m.query) : ""}${global ? field("query_interval", "查询间隔", m.query_interval, "number", 'min="1" max="65535" required', "秒") : ""}${global ? field("max_response", "最大响应时间", m.max_response, "number", 'min="1" max="255" required', "秒") : ""}` : `${ssid ? check("snooping", "组播侦听", m.snooping) : ""}${global ? check("configure_global", "配置AP全局组播", m.configure_global) : ""}${global ? check("global_snooping", "AP全局组播侦听", m.global_snooping) : ""}${unicast ? check("to_unicast", "组播转单播", m.to_unicast) : ""}${global ? check("drop_unknown", "丢弃未知组播", m.drop_unknown) : ""}`}
    ${view !== "query" && global ? multicastRateFields(m, targets.every((a) => a.features?.multicast_mcs_rate)) : ""}</div><p class="help">本页设置对应无线服务的AP侧组播参数，与无线服务编辑页共用配置。</p>${editable ? formEnd("保存") : '<p class="help">所选无线服务的目标AP未声明此项组播能力，请调整绑定范围或查看AP能力详情。</p>'}</form>`,
  );
}
document.addEventListener("change", (event) => {
  if (event.target.name !== "multicast_service") return;
  multicastServiceID = event.target.value;
  renderContent();
});
document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (f.id !== "multicast-settings-form") return;
  event.preventDefault();
  if (!validateForm(f)) return;
  const b = f.querySelector("[type=submit]");
  b.disabled = true;
  try {
    const cfg = await api("config");
    const service = cfg.config.services.find(
      (s) => s.id === f.dataset.serviceId && !s.deleting,
    );
    if (!service) throw Error("无线服务已不存在，请刷新页面");
    const options = optionDefaults(service);
    const m = { ...options.multicast };
    for (const key of f.dataset.kind === "query"
      ? ["query"]
      : [
          "snooping",
          "configure_global",
          "global_snooping",
          "to_unicast",
          "drop_unknown",
        ])
      if (f.elements[key]) m[key] = f.elements[key].checked;
    if (f.dataset.kind === "query")
      for (const key of ["query_interval", "max_response"])
        if (f.elements[key]) m[key] = Number(f.elements[key].value);
    if (f.dataset.kind !== "query")
      for (const band of [2, 5]) {
        if (f.elements[`rate${band}`]) m[`rate_${band}g`] = Number(f.elements[`rate${band}`].value);
        if (f.elements[`rate_type${band}`]) m[`rate_type_${band}g`] = Number(f.elements[`rate_type${band}`].value);
      }
    await api("services", {
      ...service,
      has_password: undefined,
      options: { ...options, multicast: m },
    });
    delete f.dataset.dirty;
    await refresh();
    toast("组播设置已保存并下发");
  } catch (e) {
    f.querySelector(".form-error").textContent = e.message;
  } finally {
    b.disabled = false;
  }
});
