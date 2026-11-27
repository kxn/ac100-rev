"use strict";

let upgradeData = { images: [], jobs: {} };

const upgradeStates = {
  queued: "排队中",
  negotiating: "协商下载",
  transferring: "传输中",
  verifying: "校验中",
  waiting_reconnect: "等待重连",
  completed: "已完成",
  failed: "失败",
  interrupted: "传输中断",
  cancelled: "已取消",
};

async function refreshUpgrades() {
  upgradeData = await api("upgrades");
  if (tab === "upgrades") renderContent();
}

function renderUpgrades() {
  const imageRows = upgradeData.images
    .map(
      (im) => `<tr>
        <td><strong>${esc(im.model)}</strong><small>${esc(im.version)}</small></td>
        <td class="num">${(im.size / 1048576).toFixed(2)} MiB</td>
        <td>${(im.support || []).map((s) => esc(s.model + " " + s.hardware)).join("<br>") || (im.hardware_ids || []).map((x) => `<small class="mono">${esc(x)}</small>`).join("")}</td>
        <td>
          <div class="actions">
            <button type="button" class="text-button" data-upgrade-image="${esc(im.id)}">下发升级</button>
            <button type="button" class="text-button danger" data-upgrade-delete="${esc(im.id)}">删除</button>
          </div>
        </td>
      </tr>`,
    )
    .join("");

  const jobRows = Object.values(upgradeData.jobs || {})
    .sort((a, b) => b.updated.localeCompare(a.updated))
    .map((j) => {
      const im = upgradeData.images.find((i) => i.id === j.image_id);
      const pct = im ? Math.floor((j.bytes_sent / im.size) * 100) : 0;
      return `<tr>
        <td>${esc(apName(j.ap_id))}</td>
        <td>${esc(im?.version || j.image_id.slice(0, 12))}</td>
        <td>${statePill(j.state)} <span class="muted">${esc(upgradeStates[j.state] || j.state)}</span></td>
        <td>${im ? meterBar(pct, j.state === "failed" ? "err" : "accent") : "—"}</td>
        <td class="num">${esc(new Date(j.not_before).toLocaleString("zh-CN"))}</td>
        <td>
          ${esc(j.error || "")}
          ${j.state === "queued" ? `<button type="button" class="text-button danger" data-upgrade-cancel="${esc(j.id)}">取消</button>` : ""}
        </td>
      </tr>`;
    })
    .join("");

  return (
    panel("固件镜像", table(["型号 / 版本", "大小", "硬件兼容", "操作"], imageRows)) +
    panel("升级任务", table(["AP", "目标版本", "状态", "进度", "计划时间", "详情"], jobRows))
  );
}

function upgradeCompatible(im, ap) {
  if (im.format === "tp-container")
    return (
      !!ap.hardware_id &&
      im.hardware_ids?.some(
        (x) => x.toLowerCase() === ap.hardware_id.toLowerCase(),
      ) &&
      !(ap.blocked_firmware_ids || []).includes(im.firmware_id)
    );
  return im.support?.some(
    (s) => s.model === ap.model && s.hardware === ap.hardware_version,
  );
}

document.addEventListener("change", async (e) => {
  if (e.target.id !== "firmware-upload") return;
  const f = e.target.files[0];
  if (!f) return;
  try {
    if (f.size > 32 * 1048576) throw Error("固件大小不能超过 32 MiB");
    const r = await fetch("/api/upgrades/images", {
      method: "POST",
      headers: { "Content-Type": "application/octet-stream" },
      body: f,
    });
    const v = await r.json();
    if (!r.ok) throw Error(v.error);
    await refreshUpgrades();
    toast("固件已上传");
  } catch (err) {
    toast(err.message);
  } finally {
    e.target.value = "";
  }
});

document.addEventListener("click", async (e) => {
  const b = e.target.closest("button");
  if (!b) return;
  try {
    if (b.dataset.upgradeDelete) {
      if (!confirm("删除此固件镜像？")) return;
      await api(
        "upgrades/images/" + encodeURIComponent(b.dataset.upgradeDelete),
        undefined,
        "DELETE",
      );
      await refreshUpgrades();
      return;
    }
    if (b.dataset.upgradeCancel) {
      await api(
        "upgrades/" + encodeURIComponent(b.dataset.upgradeCancel),
        undefined,
        "DELETE",
      );
      await refreshUpgrades();
      return;
    }
    if (!b.dataset.upgradeImage) return;
    const im = upgradeData.images.find((i) => i.id === b.dataset.upgradeImage);
    const aps = data.aps.filter((a) => upgradeCompatible(im, a));
    openDialog(
      "upgrade",
      "下发固件升级",
      `${im.model} · ${im.version}`,
      `<form id="upgrade-form" data-image="${esc(im.id)}" novalidate>
        <div class="picker-box">
          <div class="picker-head"><span>兼容 AP</span><span>选择需要升级的设备</span></div>
          <div class="picker-list">${
            aps
              .map(
                (a) =>
                  `<label class="picker-item"><input type="checkbox" name="ap_${esc(a.id)}"><span>${esc(apName(a.id))} · ${a.online ? "在线" : "离线"}</span></label>`,
              )
              .join("") || '<span class="help">暂无兼容 AP</span>'
          }</div>
        </div>
        <div class="form-grid">${field("not_before", "定时执行（留空立即执行）", "", "datetime-local")}</div>
        <p class="help">升级完成后 AP 会自动重启。</p>
        ${formEnd("创建升级任务")}
      </form>`,
    );
  } catch (err) {
    toast(err.message);
  }
});

document.addEventListener("submit", async (e) => {
  const f = e.target;
  if (f.id !== "upgrade-form") return;
  e.preventDefault();
  const btn = f.querySelector('[type="submit"]');
  btn.disabled = true;
  try {
    const aps = [...f.querySelectorAll('input[type="checkbox"]:checked')].map(
      (x) => x.name.slice(3),
    );
    if (!aps.length) throw Error("请选择 AP");
    const body = { image_id: f.dataset.image, aps };
    if (f.elements.not_before.value)
      body.not_before = new Date(f.elements.not_before.value).toISOString();
    await api("upgrades", body);
    $("#editor").close();
    dialogKind = "";
    await refreshUpgrades();
    toast("升级任务已创建");
  } catch (err) {
    f.querySelector("#form-error").textContent = err.message;
  } finally {
    btn.disabled = false;
  }
});
