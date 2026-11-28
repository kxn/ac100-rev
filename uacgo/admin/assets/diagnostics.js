"use strict";

function capabilitySource(source) {
  return (
    {
      "ap-report": "AP上报",
      "ap-model-db": "型号库回退",
      "model-db": "型号库回退",
    }[source] ||
    source ||
    "未上报"
  );
}
function renderRadioCapabilityDetail(c) {
  const rows = [
    ["能力来源", capabilitySource(c.source)],
    ["射频 / 频段", c.radio_id + " / " + c.band],
    ["无线模式", (c.modes || []).map((n) => modes[n] || n).join("、")],
    ["带宽", (c.bandwidths || []).map((n) => widths[n] || n).join("、")],
    ["信道", (c.channels || []).join("、")],
    [
      "功率范围",
      c.min_power_dbm == null || c.max_power_dbm == null
        ? "未上报"
        : c.min_power_dbm + "–" + c.max_power_dbm + " dBm",
    ],
    [
      "SSID / 客户端上限",
      (c.max_ssid ?? "未上报") + " / " + (c.max_clients ?? "未上报"),
    ],
    [
      "空间流（发 / 收）",
      (c.tx_streams ?? "未上报") + " / " + (c.rx_streams ?? "未上报"),
    ],
  ];
  return `<dl class="detail-grid">${rows.map(([k, v]) => `<div><dt>${esc(k)}</dt><dd>${esc(v || "未上报")}</dd></div>`).join("")}</dl>`;
}
function apCapabilitySnapshot(ap) {
  // Explicit capability-only export; telemetry, accounts and key material never
  // enter the diagnostic JSON or clipboard.
  return {
    model: ap.model,
    hardware_version: ap.hardware_version,
    general_capabilities: ap.general_capabilities,
    sub_capabilities: ap.sub_capabilities,
    features: ap.features,
    radios: ap.capabilities,
    radio_modes: ap.radio_modes,
    radio_linkage: ap.radio_linkage,
    ports: ap.ports,
  };
}
function renderAPCapabilities(ap) {
  const features = Object.entries(ap.features || {}).sort(([a], [b]) =>
    a.localeCompare(b),
  );
  const words = (ap.general_capabilities || [])
    .map(
      (w, i) =>
        `<tr><td>word ${i}</td><td class="mono">0x${(w >>> 0).toString(16).padStart(8, "0")}</td><td>${
          Array.from({ length: 32 }, (_, b) => b)
            .filter((b) => (w >>> b) & 1)
            .map((b) => i * 32 + b)
            .join(", ") || "无"
        }</td></tr>`,
    )
    .join("");
  return (
    panel(
      "AP 上报标识",
      `<dl class="detail-grid"><div><dt>上报名称（非配置）</dt><dd>${esc(ap.reported_name || "未上报")}</dd></div><div><dt>上报位置（非安装位置配置）</dt><dd>${esc(ap.reported_location || "未上报")}</dd></div></dl>`,
    ) +
    panel(
      "功能能力",
      table(
        ["功能", "能力标识", "解析结果"],
        features
          .map(
            ([k, v]) =>
              `<tr><td>${esc(featureNames[k] || k)}</td><td class="mono">${esc(k)}</td><td>${v ? "支持" : "未声明 / 不支持"}</td></tr>`,
          )
          .join(""),
      ),
    ) +
    panel("通用能力位", table(["能力字", "原始值", "置位编号"], words)) +
    panel(
      "子能力",
      table(
        ["类型", "原始值"],
        Object.entries(ap.sub_capabilities || {})
          .map(
            ([k, v]) =>
              `<tr><td class="mono">0x${Number(k).toString(16)}</td><td class="mono">0x${(v >>> 0).toString(16).padStart(8, "0")}</td></tr>`,
          )
          .join(""),
      ),
    ) +
    (ap.capabilities || [])
      .map(
        (c) =>
          `<details class="advanced-section"><summary>射频 ${c.radio_id} · ${esc(c.band)} · ${esc(capabilitySource(c.source))}</summary>${renderRadioCapabilityDetail(c)}</details>`,
      )
      .join("")
  );
}
document.addEventListener("click", async (event) => {
  const b = event.target.closest("[data-ap-diagnostic],[data-capability-copy]");
  if (!b) return;
  if (b.dataset.apDiagnostic) {
    currentService = b.dataset.apDiagnostic;
    renderAPDetail(currentService);
    $("#drawer-body [data-editor-tab='ap-cap']")?.click();
  } else {
    const ap = data.aps.find((a) => a.id === b.dataset.capabilityCopy);
    if (!ap) return;
    try {
      await navigator.clipboard.writeText(
        JSON.stringify(apCapabilitySnapshot(ap), null, 2),
      );
      toast("已复制能力数据");
    } catch {
      const pre = $("#drawer-body .raw");
      if (pre) {
        const range = document.createRange();
        range.selectNodeContents(pre);
        const sel = window.getSelection();
        sel.removeAllRanges();
        sel.addRange(range);
      }
      toast("请使用系统复制操作复制已选中的能力数据");
    }
  }
});
