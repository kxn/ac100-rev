"use strict";

let edcaEdit = null;

function edcaQueueFields(rows) {
  return table(
    ["队列", "AIFS", "CW Min", "CW Max", "TXOP"],
    rows
      .map(
        (x, i) => `<tr>
          <td><strong>${["AP VO", "AP VI", "AP BE", "AP BK", "STA VO", "STA VI", "STA BE", "STA BK"][i]}</strong></td>
          ${["aifs", "cw_min", "cw_max", "txop"]
            .map(
              (k) =>
                `<td><input name="edca_${i}_${k}" aria-label="EDCA ${i} ${k}" type="number" required min="${k === "aifs" ? (i < 4 ? 1 : 2) : k === "txop" ? 0 : 1}" max="${k === "txop" ? 255 : k === "aifs" ? 15 : 10}" value="${x[k]}"></td>`,
            )
            .join("")}
        </tr>`,
      )
      .join(""),
  );
}

function readEDCAQueues(f) {
  return [...Array(8)].map((_, i) =>
    Object.fromEntries(
      ["aifs", "cw_min", "cw_max", "txop"].map((k) => [
        k,
        Number(f.elements[`edca_${i}_${k}`].value),
      ]),
    ),
  );
}

function formatEDCAFrequency(mask) {
  return (
    [...Array(16)]
      .map((_, i) =>
        mask & (1 << i) ? `${i < 8 ? "2.4" : "5"} GHz 第${(i % 8) + 1}路` : "",
      )
      .filter(Boolean)
      .join("、") || "未选择"
  );
}

function renderEDCA() {
  return panel(
    "EDCA 争用规则",
    table(
      ["规则", "应用范围", "频段", "模式 / 场景", "状态", "操作"],
      (data.config.edca_rules || [])
        .map(
          (r) => `<tr>
            <td><strong>${esc(r.name)}</strong></td>
            <td>${esc(targetSummary(r))}</td>
            <td>${esc(formatEDCAFrequency(r.frequency_mask))}</td>
            <td>${r.configuration.mode === 1 ? "动态" : "静态"} · ${r.custom ? "自定义队列" : ["自定义", "办公", "高密低流量", "高密高流量"][r.scene]}</td>
            <td><span class="pill ${r.configuration.enabled ? "online" : ""}">${r.configuration.enabled ? "启用" : "停用"}</span></td>
            <td>
              <div class="actions">
                <button type="button" class="text-button" data-edca-edit="${esc(r.id)}">编辑</button>
                <button type="button" class="text-button danger" data-edca-delete="${esc(r.id)}">删除</button>
              </div>
            </td>
          </tr>`,
        )
        .join(""),
    ),
  );
}

document.addEventListener("click", async (event) => {
  const b = event.target.closest("button");
  if (!b || (!b.dataset.edcaNew && !b.dataset.edcaEdit && !b.dataset.edcaDelete))
    return;
  try {
    const p = await api("edca");
    if (b.dataset.edcaDelete) {
      if (!confirm("删除此 EDCA 规则？")) return;
      await api(
        "edca/rules",
        (p.rules || []).filter((r) => r.id !== b.dataset.edcaDelete),
      );
      await refresh();
      return;
    }
    const item = (p.rules || []).find((r) => r.id === b.dataset.edcaEdit) || {
      ...p.defaults,
      id: newID(),
      name: "",
    };
    edcaEdit = { p, item };

    const freq2g = Array.from(
      { length: 8 },
      (_, i) =>
        `<label class="picker-item"><input type="checkbox" name="frequency_mask" value="${1 << i}" ${item.frequency_mask & (1 << i) ? "checked" : ""}><span>2.4 GHz · 第 ${i + 1} 路</span></label>`,
    ).join("");
    const freq5g = Array.from(
      { length: 8 },
      (_, i) =>
        `<label class="picker-item"><input type="checkbox" name="frequency_mask" value="${1 << (i + 8)}" ${item.frequency_mask & (1 << (i + 8)) ? "checked" : ""}><span>5 GHz · 第 ${i + 1} 路</span></label>`,
    ).join("");

    openDialog(
      "edca",
      b.dataset.edcaEdit ? "编辑 EDCA 规则" : "新建 EDCA 规则",
      "",
      `<form id="edca-form" novalidate>
        <div class="form-grid">
          ${field("name", "规则名称", item.name, "text", 'maxlength="127" required')}
          ${toggle("enabled", "启用 EDCA", item.configuration.enabled)}
          ${targetPicker(item.aps || [], item.groups || [])}
          <div class="picker-box full">
            <div class="picker-head"><span>应用频段</span><span>至少选择一项</span></div>
            <div class="picker-grid"><div>${freq2g}</div><div>${freq5g}</div></div>
          </div>
          ${check("wmm", "启用 WMM", item.wmm)}
          ${select("mode", "EDCA 模式", { 0: "静态", 1: "动态" }, item.configuration.mode ?? 0)}
          ${select("custom", "队列来源", { 1: "自定义队列", 0: "AP 场景" }, item.custom ? 1 : 0)}
          ${select("scene", "AP 场景", { 0: "自定义", 1: "办公", 2: "高密低流量", 3: "高密高流量" }, item.scene)}
        </div>
        <h3 class="section-title">队列参数</h3>
        ${edcaQueueFields(item.configuration.queues)}
        ${formEnd("保存规则")}
      </form>`,
    );
  } catch (e) {
    toast(e.message);
  }
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (f.id !== "edca-form") return;
  event.preventDefault();
  if (!f.reportValidity()) return;
  const btn = f.querySelector('[type="submit"]');
  btn.disabled = true;
  try {
    const { p, item } = edcaEdit;
    const freqMask = [
      ...f.querySelectorAll('input[name="frequency_mask"]:checked'),
    ].reduce((mask, x) => mask | Number(x.value), 0);
    if (!freqMask) throw Error("请至少选择一个频段");
    const r = {
      ...item,
      ...readTargetPicker(f),
      name: f.elements.name.value,
      frequency_mask: freqMask,
      wmm: f.elements.wmm.checked,
      custom: f.elements.custom.value === "1",
      scene: Number(f.elements.scene.value),
      configuration: {
        enabled: f.elements.enabled.checked,
        mode: Number(f.elements.mode.value),
        queues: readEDCAQueues(f),
      },
    };
    const rows = p.rules || [];
    const i = rows.findIndex((x) => x.id === r.id);
    if (i < 0) rows.push(r);
    else rows[i] = r;
    await api("edca/rules", rows);
    $("#editor").close();
    dialogKind = "";
    await refresh();
    toast("EDCA 规则已保存");
  } catch (e) {
    f.querySelector("#form-error").textContent = e.message;
  } finally {
    btn.disabled = false;
  }
});
