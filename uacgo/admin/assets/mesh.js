"use strict";

const meshActionNames = {
  discover: "扫描节点",
  "stop-discovery": "停止扫描",
  pair: "配对节点",
  unpair: "解除配对",
  add: "添加节点",
  delete: "移除节点",
};

function renderMesh() {
  const p = data.config.mesh || {
    enabled: false,
    auto_add: false,
    ssid: "",
    backhaul_mode: 0,
  };
  const apRows = data.aps
    .filter((a) => a.features?.mesh)
    .map(
      (a) => `<tr>
        <td><strong>${esc(apName(a.id))}</strong><small>${a.online ? "在线" : "离线"}${a.mesh_policy_enabled == null ? "" : a.mesh_policy_enabled ? " · 允许组网" : " · 配置停用"}</small></td>
        <td>${(a.mesh?.discoveries || []).map((n) => `<div class="mono">${esc(n.mac)} · ${esc(n.model)} · ${n.rssi} dBm</div>`).join("") || '<span class="muted">无</span>'}</td>
        <td>${(a.mesh?.nodes || []).map((n) => `<div class="mono">${esc(n.mac)} · ${esc(n.ipv4)} · ${n.wireless ? "无线" : "有线"} · 父 ${esc(n.parent)}</div>`).join("") || '<span class="muted">无</span>'}</td>
        <td><button type="button" class="text-button" data-mesh-ap="${esc(a.id)}" ${p.enabled && a.online ? "" : "disabled"}>管理节点</button></td>
      </tr>`,
    )
    .join("");

  const memberRows = (p.members || [])
    .slice(0, 200)
    .map(
      (m) =>
        `<tr><td>${esc(apName(m.parent_ap_id))}</td><td class="mono">${esc(m.mac)}</td><td><span class="pill ${m.allowed ? "online" : ""}">${m.allowed ? "已授权" : "已撤销"}</span></td></tr>`,
    )
    .join("");

  return (
    panel(
      "设备列表",
      table(["父 AP", "发现节点", "已接入节点", "操作"], apRows),
    ) +
    panel(
      "节点授权记录",
      table(["父 AP", "节点 MAC", "授权状态"], memberRows),
    ) +
    panel(
      "操作记录",
      '<div id="mesh-jobs"><div class="empty">加载中…</div></div>',
    )
  );
}

async function loadMeshJobs() {
  const el = $("#mesh-jobs");
  if (!el) return;
  try {
    const p = await api("mesh");
    if (!el.isConnected) return;
    el.innerHTML = table(
      ["父 AP", "操作", "节点", "状态", "说明"],
      Object.values(p.jobs || {})
        .sort((a, b) => b.started.localeCompare(a.started))
        .slice(0, 100)
        .map(
          (j) =>
            `<tr><td>${esc(apName(j.ap_id))}</td><td>${esc(meshActionNames[j.action] || j.action)}</td><td class="mono">${esc(j.macs.join(", ") || "—")}</td><td>${statePill(j.state)}</td><td>${esc(j.error || "—")}</td></tr>`,
        )
        .join(""),
    );
  } catch (e) {
    el.textContent = e.message;
  }
}

document.addEventListener("click", (e) => {
  const pick = e.target.closest("[data-mesh-pick-mac]");
  if (pick) {
    const f = $("#mesh-form");
    if (!f?.elements.macs) return;
    const mac = pick.dataset.meshPickMac;
    const list = f.elements.macs.value.split(/[\s,]+/).filter(Boolean);
    if (!list.includes(mac)) list.push(mac);
    f.elements.macs.value = list.join("\n");
    return;
  }
  const t = e.target.closest("[data-mesh-config],[data-mesh-ap]");
  if (!t) return;
  const id = t.dataset.meshAp;
  const p = data.config.mesh || {
    enabled: false,
    auto_add: false,
    ssid: "",
    backhaul_mode: 0,
  };
  let body;
  if (id) {
    const ap = data.aps.find((a) => a.id === id);
    const macSuggestions = [
      ...(ap?.mesh?.discoveries || []).map((n) => ({
        mac: n.mac,
        info: `${n.model || "发现"} · ${n.rssi} dBm`,
      })),
      ...(ap?.mesh?.nodes || []).map((n) => ({
        mac: n.mac,
        info: n.wireless ? "无线节点" : "有线节点",
      })),
    ];
    const quickChips = macSuggestions.length
      ? `<div class="full"><span class="help">点击快速填入 MAC：</span><div class="chips">${macSuggestions
          .map(
            (m) =>
              `<button type="button" class="chip mono" data-mesh-pick-mac="${esc(m.mac)}">${esc(m.mac)} (${esc(m.info)})</button>`,
          )
          .join("")}</div></div>`
      : "";
    body = `<input type="hidden" name="ap_id" value="${esc(id)}">
      ${select("action", "操作", meshActionNames, "discover")}
      ${quickChips}
      <label class="full"><span>节点 MAC（配对、添加、移除时填写，每行一个）</span><textarea name="macs" rows="4" placeholder="aa:bb:cc:dd:ee:ff"></textarea></label>`;
  } else {
    body = meshSettingsFields(p);
  }

  openDialog(
    "mesh",
    id ? "管理 Mesh 节点 · " + apName(id) : "Mesh 组网设置",
    "",
    `<form id="mesh-form" novalidate>
      <div class="form-grid">${body}</div>
      ${formEnd(id ? "发送操作" : "保存并下发", '<button type="button" class="btn secondary" data-close="1">取消</button>')}
    </form>`,
  );
});

document.addEventListener("submit", async (e) => {
  const f = e.target;
  if (f.id !== "mesh-form") return;
  e.preventDefault();
  if (!validateForm(f)) return;
  const b = f.querySelector('[type="submit"]');
  b.disabled = true;
  try {
    if (f.elements.ap_id) {
      await api("aps/" + encodeURIComponent(f.elements.ap_id.value) + "/mesh", {
        action: f.elements.action.value,
        macs: f.elements.macs.value.split(/[\s,]+/).filter(Boolean),
      });
    } else {
      await api("mesh", {
        enabled: f.elements.enabled.checked,
        auto_add: f.elements.auto_add.checked,
        ssid: f.elements.ssid.value,
        key: f.elements.key.value,
        web_password: f.elements.web_password.value,
        backhaul_mode: Number(f.elements.backhaul_mode.value),
      });
    }
    delete f.dataset.dirty;
    closeEditorFor(f);
    await refresh();
    toast("Mesh 设置已提交");
  } catch (err) {
    f.querySelector(".form-error").textContent = err.message;
  } finally {
    b.disabled = false;
  }
});

function meshSettingsFields(p) {
  return `<div class="full">${toggle("enabled", "启用 Mesh 组网", p.enabled)}</div>
      <div class="full">${toggle("auto_add", "自动接入已知 AP", p.auto_add)}</div>
      ${field("ssid", "回传名称", p.ssid, "text", 'maxlength="32"')}
      ${select("backhaul_mode", "回传模式", { 0: "设备默认", 1: "高带机量（5 GHz）", 2: "双链路（2.4 / 5 GHz）" }, p.backhaul_mode)}
      <label><span>回传密钥</span><input type="password" name="key" minlength="8" maxlength="63" autocomplete="new-password" placeholder="${p.has_key ? "留空不修改密钥" : "8–63 字节"}"></label>
      <label><span>Mesh 管理密码</span><input type="password" name="web_password" minlength="6" maxlength="15" autocomplete="new-password" placeholder="${p.has_web_password ? "留空不修改密码" : "6–15 字节"}"></label>`;
}
function renderMeshSettings() {
  const p = data.config.mesh || {
    enabled: false,
    auto_add: false,
    ssid: "",
    backhaul_mode: 0,
  };
  return panel(
    "高级设置",
    `<form id="mesh-form" data-inline="1" novalidate><div class="form-grid">${meshSettingsFields(p)}</div><p class="help">全局开关与单台 AP 的开关共同生效；AP 模板、分组或单台设置停用时，该 AP 不启用组网。支持易展能力不代表已启用。</p>${formEnd("保存")}</form>`,
  );
}
function renderMeshTopology() {
  const aps = data.aps.filter((a) => a.features?.mesh);
  return panel(
    "拓扑结构",
    `<div class="mesh-tree">${aps.map((a) => `<div><button type="button" class="link-btn" data-ap="${esc(a.id)}">${esc(apName(a.id))}</button><small>${a.mesh_parent ? "上联：" + esc(a.mesh_parent) : "上联未上报"}</small>${(a.mesh?.nodes || []).map((n) => `<div class="mesh-node"><span class="mono">${esc(n.mac)}</span> · ${esc(n.ipv4 || "IP未上报")}<small>${n.wireless ? "无线回传" : "有线连接"} · 父节点 ${esc(n.parent || "未上报")}</small></div>`).join("")}</div>`).join("") || '<div class="empty">暂无易展拓扑上报</div>'}</div>`,
  );
}
