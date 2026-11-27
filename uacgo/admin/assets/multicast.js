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
    idx >= 0 && list[idx]
      ? list[idx]
      : { ip: "", relay: true, enabled: true };
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
    if (!f.reportValidity()) return;
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
      $("#editor").close();
      dialogKind = "";
      await refresh();
      toast("组播策略已保存");
    } catch (e) {
      f.querySelector("#form-error").textContent = e.message;
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
    $("#editor").close();
    dialogKind = "";
    await refresh();
    toast("组播策略已保存");
  } catch (e) {
    f.querySelector("#form-error").textContent = e.message;
  } finally {
    btn.disabled = false;
  }
});
