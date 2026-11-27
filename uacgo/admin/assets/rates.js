"use strict";

let ratesData = null;

function renderRates() {
  const st = data.apply.filter((s) => s.service_id === "rates");
  const p = ratesData;
  if (!p) {
    void api("rates")
      .then((res) => {
        ratesData = res;
        if (tab === "rates") renderContent();
      })
      .catch(() => {});
    return panel("速率表", '<div class="empty">加载速率配置中…</div>');
  }

  const legacy = `<div class="form-grid">${Object.entries({
    "11a": [6, 9, 12, 18, 24, 36, 48, 54],
    "11b": [1, 2, 5.5, 11],
    "11g": [1, 2, 5.5, 6, 9, 11, 12, 18, 24, 36, 48, 54],
  })
    .map(
      ([band, values]) => `<fieldset>
        <legend>802.${band}</legend>
        ${table(
          ["速率（Mbps）", "用途"],
          values
            .map(
              (v) =>
                `<tr><td class="num">${v}</td><td>${select(band + "_" + v, "", { off: "禁用", basic: "基础速率", supported: "支持速率" }, p[band].basic_mbps.includes(v) ? "basic" : p[band].supported_mbps.includes(v) ? "supported" : "off")}</td></tr>`,
            )
            .join(""),
        )}
        ${select(band + "_multicast", "组播速率", { "-1": "自动", ...Object.fromEntries(values.map((v) => [v, v + " Mbps"])) }, p[band].multicast_mbps)}
      </fieldset>`,
    )
    .join("")}</div>`;

  const mcs = `<div class="form-grid-3">${["11n", "11ac", "11ax"]
    .map(
      (b) => `<fieldset>
        <legend>802.${b}</legend>
        <div class="form-grid">
          ${["basic", "supported", "multicast"]
            .map((k, i) =>
              field(
                b + "_" + k,
                ["基础索引", "支持索引", "组播索引"][i],
                p[b][k],
                "number",
                `min="-1" max="${b === "11n" ? 31 : b === "11ac" ? 11 : 23}" required`,
              ),
            )
            .join("")}
        </div>
      </fieldset>`,
    )
    .join("")}</div><p class="help">-1 表示自动。</p>`;

  const formHtml = `<div class="panel-body">
    <form id="rates-form" data-inline="1" novalidate>
      <div class="form-grid">
        <div class="full">${toggle("enabled", "启用自定义速率表", p.enabled)}</div>
        ${targetPicker(p.aps || [], p.groups || [])}
      </div>
      ${tabs([
        ["rates-legacy", "802.11a/b/g"],
        ["rates-mcs", "802.11n/ac/ax"],
      ])}
      ${pane("rates-legacy", legacy, true)}
      ${pane("rates-mcs", mcs)}
      ${formEnd()}
    </form>
  </div>`;

  return (
    panel("速率表", formHtml) +
    panel(
      "设备同步状态",
      table(
        ["AP", "状态", "说明"],
        st
          .map(
            (s) =>
              `<tr><td>${esc(apName(s.ap_id))}</td><td>${statePill(s.state)}</td><td>${esc(s.error || "—")}</td></tr>`,
          )
          .join(""),
      ),
    )
  );
}

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (f.id !== "rates-form") return;
  event.preventDefault();
  if (!f.reportValidity()) return;
  const button = f.querySelector('[type="submit"]');
  button.disabled = true;
  try {
    const picked = readTargetPicker(f);
    const p = {
      enabled: f.elements.enabled.checked,
      aps: picked.aps,
      groups: picked.groups,
    };
    for (const b of ["11a", "11b", "11g"]) {
      p[b] = {
        basic_mbps: [],
        supported_mbps: [],
        multicast_mbps: Number(f.elements[b + "_multicast"].value),
      };
      for (const el of f.elements) {
        if (
          el.tagName === "SELECT" &&
          el.name.startsWith(b + "_") &&
          el.name !== b + "_multicast" &&
          el.value !== "off"
        )
          p[b][el.value + "_mbps"].push(Number(el.name.slice(4)));
      }
    }
    for (const b of ["11n", "11ac", "11ax"])
      p[b] = Object.fromEntries(
        ["basic", "supported", "multicast"].map((k) => [
          k,
          Number(f.elements[b + "_" + k].value),
        ]),
      );
    await api("rates", p);
    ratesData = p;
    delete f.dataset.dirty;
    await refresh();
    toast("速率表已保存并下发");
  } catch (e) {
    const errEl = f.querySelector("#form-error");
    if (errEl) errEl.textContent = e.message;
    else toast(e.message);
  } finally {
    button.disabled = false;
  }
});
