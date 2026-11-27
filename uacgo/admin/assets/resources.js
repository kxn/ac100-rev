"use strict";

let controllerResources = { settings: {}, defaults: {}, fields: [] };

function renderControllerResources() {
  const r = controllerResources;
  if (!r.fields?.length) {
    void api("controller/resources")
      .then((res) => {
        controllerResources = res;
        if (tab === "resources") renderContent();
      })
      .catch(() => {});
    return panel("容量配额", '<div class="empty">加载容量配置中…</div>');
  }

  const rows = r.fields
    .map(
      (f) => `<div class="resource-row">
        ${field(f.key, f.label, r.settings[f.key], "number", `min="${f.min}" max="${f.max}" step="1" required`, f.unit || "")}
        <div class="resource-meta">
          <span class="num">范围：${f.min} – ${f.max}</span>
          <span class="num">默认值：${esc(r.defaults[f.key])} ${esc(f.unit || "")}</span>
        </div>
      </div>`,
    )
    .join("");

  return panel(
    "容量配额",
    `<div class="panel-body">
      <form id="controller-resources-form" data-inline="1" novalidate>
        <div class="form-grid">${rows}</div>
        <p class="help">降低 AP 会话上限不影响已在线设备；其余配额不能低于当前已创建对象的数量。</p>
        ${formEnd("保存配置", '<button type="button" class="btn secondary" data-resource-reset>恢复默认值</button>')}
      </form>
    </div>`,
  );
}

document.addEventListener("click", (e) => {
  if (!e.target.closest("[data-resource-reset]")) return;
  const f = $("#controller-resources-form");
  if (!f) return;
  for (const p of controllerResources.fields) {
    if (f.elements[p.key]) f.elements[p.key].value = controllerResources.defaults[p.key];
  }
  f.dataset.dirty = "1";
});

document.addEventListener("submit", async (e) => {
  const f = e.target;
  if (f.id !== "controller-resources-form") return;
  e.preventDefault();
  if (!f.reportValidity()) return;
  const button = f.querySelector('[type="submit"]');
  button.disabled = true;
  try {
    const value = Object.fromEntries(
      controllerResources.fields.map((p) => [p.key, Number(f.elements[p.key].value)]),
    );
    await api("controller/resources", value);
    delete f.dataset.dirty;
    await refresh();
    toast("容量配置已保存");
  } catch (error) {
    const errEl = f.querySelector("#form-error");
    if (errEl) errEl.textContent = error.message;
    else toast(error.message);
  } finally {
    button.disabled = false;
  }
});
