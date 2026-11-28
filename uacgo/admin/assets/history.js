"use strict";

let historyData = { ap_counts: [], radios: [], events: [] };
let historyAP = "";
let historyRadio = "";
let historyMetric = "clients";
let historyEventFilter = "all";

const metricLabels = {
  clients: "无线客户端数",
  channel: "工作信道",
  power_dbm: "发射功率（dBm）",
  channelUsage: "信道利用率（%）",
  channelUpUsage: "上行信道占用（%）",
  channelDownUsage: "下行信道占用（%）",
  channelInterference: "信道干扰（%）",
  OBSSandNonWiFiUsage: "邻区与非 Wi-Fi 占用（%）",
  nonWiFiUsage: "非 Wi-Fi 占用（%）",
  noiseFloor: "底噪（dBm）",
  clientNum: "AP 上报客户端数",
  clientLoading: "客户端负载（%）",
  packetRetryRate: "报文重传率（%）",
  weakSignalStationRate: "弱信号终端占比（%）",
  weakSigStaCnt: "弱信号终端数",
  upSpeed: "上行速率（kbps）",
  downSpeed: "下行速率（kbps）",
  upFlow: "上行流量",
  downFlow: "下行流量",
  rxPkts: "接收报文",
  txPkts: "发送报文",
  txRetryPkts: "重传报文",
  txFailPkts: "发送失败报文",
};

async function refreshHistory() {
  const q = new URLSearchParams({ limit: "1440" });
  if (historyAP) q.set("ap", historyAP);
  if (historyRadio) q.set("radio", historyRadio);
  const [h, ev] = await Promise.all([
    api("history?" + q),
    api("mobility/events").catch(() => mobilityEvents),
  ]);
  historyData = h;
  mobilityEvents = Array.isArray(ev) ? ev : [];
  if (tab === "history") renderContent();
}

function historyPlot(rows, metricKey = historyMetric, gap = 300000) {
  if (!rows.length) return '<div class="empty">暂无统计采样</div>';
  const value = (r) =>
    metricKey === "clients"
      ? r.clients
      : metricKey === "channel"
        ? r.channel
        : metricKey === "power_dbm"
          ? r.power_dbm
          : r.metrics?.[metricKey];
  const groups = new Map();
  for (const r of rows) {
    const v = value(r);
    if (!Number.isFinite(v)) continue;
    const k = r.ap_id + "/" + r.radio_id;
    if (!groups.has(k)) groups.set(k, []);
    groups.get(k).push([Date.parse(r.at), v]);
  }
  const all = [...groups.values()].flat();
  if (!all.length) return '<div class="empty">暂无该指标采样</div>';
  let x0 = Math.min(...all.map((p) => p[0]));
  let x1 = Math.max(...all.map((p) => p[0]));
  let y0 = Math.min(...all.map((p) => p[1]));
  let y1 = Math.max(...all.map((p) => p[1]));
  if (y0 > 0) y0 = 0;
  if (x1 === x0) x1 = x0 + 60000;
  if (y1 === y0) y1 = y0 + 1;
  const colors = [
    "#2563eb",
    "#059669",
    "#d97706",
    "#7c3aed",
    "#db2777",
    "#0891b2",
  ];
  const gridY = [0, 0.25, 0.5, 0.75, 1].map((t) => {
    const y = 20 + t * 195;
    const val = y1 - t * (y1 - y0);
    const label =
      Math.abs(val - Math.round(val)) < 0.05
        ? String(Math.round(val))
        : val.toFixed(1);
    return `<line x1="52" y1="${y}" x2="880" y2="${y}" stroke="#f1f3f6" stroke-width="1"/><text x="46" y="${y + 4}" text-anchor="end">${label}</text>`;
  });
  const series = [...groups.values()].map((points, i) => {
    const stroke = colors[i % colors.length];
    const d = points
      .map(
        ([x, y], j) =>
          `${j === 0 || x - points[j - 1][0] > gap ? "M" : "L"}${(52 + ((x - x0) / (x1 - x0)) * 828).toFixed(1)},${(215 - ((y - y0) / (y1 - y0)) * 195).toFixed(1)}`,
      )
      .join(" ");
    return `<path fill="none" stroke="${stroke}" stroke-width="2" stroke-linejoin="round" stroke-linecap="round" d="${d}"/>`;
  });

  return `<svg class="trend-svg" viewBox="0 0 900 245" role="img" aria-label="无线运行统计趋势">
      ${gridY.join("")}
      <line x1="52" y1="20" x2="52" y2="215" stroke="#d1d5db"/>
      <line x1="52" y1="215" x2="880" y2="215" stroke="#d1d5db"/>
      ${series.join("")}
      <text x="52" y="236">${esc(new Date(x0).toLocaleTimeString("zh-CN", { hour12: false }))}</text>
      <text x="880" y="236" text-anchor="end">${esc(new Date(x1).toLocaleTimeString("zh-CN", { hour12: false }))}</text>
    </svg>
    <div class="chips">${[...groups.keys()].map((k, i) => `<span class="chip"><span class="swatch swatch-${i % 6}"></span>${esc(k)}</span>`).join("")}</div>`;
}

function renderHistory() {
  const metrics = {
    clients: metricLabels.clients,
    channel: metricLabels.channel,
    power_dbm: metricLabels.power_dbm,
  };
  for (const r of historyData.radios) {
    for (const k of Object.keys(r.metrics || {})) {
      metrics[k] = metricLabels[k] || k;
    }
  }
  const latestAP = (historyData.ap_counts || []).at(-1);
  const apChartBody = `<div class="panel-body">
    ${historyPlot(
      (historyData.ap_counts || []).map((r) => ({
        ...r,
        ap_id: "在线 AP",
        radio_id: "数量",
        clients: r.online,
      })),
      "clients",
    )}
  </div>`;
  const apTools = latestAP
    ? `<span class="tag num">在线 ${latestAP.online} · 离线 ${latestAP.offline} · 共 ${latestAP.total}</span>`
    : "";

  const radioFilterBar = `<div class="filter-bar">
    <div class="toolbar-group">
      ${select("history_ap", "", { "": "全部 AP", ...Object.fromEntries(data.aps.map((a) => [a.id, apName(a.id)])) }, historyAP, 'aria-label="AP"')}
      ${select(
        "history_radio",
        "",
        {
          "": "全部射频",
          ...Object.fromEntries(
            [
              ...new Set([
                ...data.aps
                  .filter((a) => !historyAP || a.id === historyAP)
                  .flatMap((a) =>
                    (a.capabilities || []).map((c) => c.radio_id),
                  ),
                ...historyData.radios.map((r) => r.radio_id),
              ]),
            ]
              .sort((a, b) => a - b)
              .map((id) => [id, "射频 " + id]),
          ),
        },
        historyRadio,
        'aria-label="射频"',
      )}
      ${select("history_metric", "", metrics, historyMetric, 'aria-label="指标"')}
    </div>
  </div>`;

  const eventsFiltered = historyData.events
    .slice()
    .reverse()
    .filter(
      (e) => historyEventFilter === "all" || e.kind === historyEventFilter,
    );

  const eventFilterBar = `<div class="filter-bar">
    <div class="seg-tabs" role="tablist" aria-label="事件类型">
      ${[
        ["all", "全部"],
        ["connected", "上线"],
        ["disconnected", "离线"],
        ["roamed", "切换"],
      ]
        .map(
          ([id, label]) =>
            `<button type="button" data-history-event="${id}" class="${historyEventFilter === id ? "active" : ""}">${label}</button>`,
        )
        .join("")}
    </div>
  </div>`;

  const eventRows = eventsFiltered
    .slice(0, 200)
    .map(
      (e) => `<tr>
        <td class="num">${esc(new Date(e.at).toLocaleString("zh-CN"))}</td>
        <td class="mono">${esc(e.client_mac)}</td>
        <td>${esc({ connected: "上线", disconnected: "离线", roamed: "切换", service_changed: "服务变更" }[e.kind] || e.kind)}${e.from_ap ? `<small>原位置 ${esc(apName(e.from_ap))} / 射频 ${e.from_radio}</small>` : ""}</td>
        <td>${esc(e.ssid || "—")}</td>
        <td>${esc(apName(e.ap_id))} / 射频 ${e.radio_id}</td>
        <td>${e.source === "wireless_snapshot" ? "实时表" : "连接事件"}</td>
      </tr>`,
    )
    .join("");

  const roamDecisionRows = (mobilityEvents || [])
    .slice(-50)
    .reverse()
    .map(
      (d) => `<tr>
        <td class="num">${esc(new Date(d.at).toLocaleString("zh-CN"))}</td>
        <td class="mono">${esc(d.mac)}</td>
        <td>${esc(apName(d.ap_id))}</td>
        <td>${(d.candidates || []).map((c) => esc(apName(c))).join("、") || "—"}</td>
        <td>${esc(d.reason || "—")}</td>
      </tr>`,
    )
    .join("");

  return (
    panel("在线 AP 数量趋势", apChartBody, apTools) +
    panel(
      "无线运行趋势",
      `<div class="panel-body">${historyPlot(historyData.radios)}</div>`,
      "",
      radioFilterBar,
    ) +
    panel(
      "客户端连接记录",
      table(
        ["时间", "客户端 MAC", "事件", "SSID", "所在 AP / 射频", "来源"],
        eventRows,
      ),
      "",
      eventFilterBar,
    ) +
    panel(
      "漫游触发记录",
      table(
        ["时间", "客户端 MAC", "当前 AP", "候选 AP", "结果"],
        roamDecisionRows,
      ),
    )
  );
}

document.addEventListener("click", (e) => {
  const b = e.target.closest("[data-history-event]");
  if (!b) return;
  historyEventFilter = b.dataset.historyEvent;
  renderContent();
});

document.addEventListener("change", async (e) => {
  if (
    !["history_ap", "history_radio", "history_metric"].includes(e.target.name)
  )
    return;
  try {
    if (e.target.name === "history_ap") historyAP = e.target.value;
    if (e.target.name === "history_radio") historyRadio = e.target.value;
    if (e.target.name === "history_metric") {
      historyMetric = e.target.value;
      renderContent();
    } else await refreshHistory();
  } catch (err) {
    toast(err.message);
  }
});

let clientHistoryMAC = "";
let clientHistoryDuration = 300;

async function showClientSignalHistory(mac, duration = 300) {
  const request = beginEditorRequest();
  const result = await api(
    "clients/" + encodeURIComponent(mac) + "/history?duration=" + duration,
  );
  if (!isCurrentEditorRequest(request)) return;
  const rows = result.samples || [];
  clientHistoryMAC = mac;
  clientHistoryDuration = duration;
  const chart = rows.map((r) => ({ ...r, metrics: { rssi_dbm: r.rssi_dbm } }));
  const client = data.clients.find((c) => c.mac === mac);
  const native = client?.native_signal;
  const rates = client?.native_rates;
  const diagnostics = native || rates ? `<details class="client-report-diagnostics">
    <summary>AP 原始上报（调试）</summary>
    <p class="muted">以下是 wireless.sta_list 的接口原值，固件之间含义可能不同，不作为统一 dBm 或协商 Mbps，也不用于漫游候选计算。</p>
    ${native ? `<p>原生 rssi：<span class="num">${esc(native.value)}</span>（接口原值）<small>采样 ${ago(native.at)}</small></p>` : ""}
    ${rates ? `<p>原生 TX/RX：<span class="num">${esc(rates.tx || "—")} / ${esc(rates.rx || "—")}</span>（接口原值）<small>采样 ${ago(rates.at)}</small></p>` : ""}
  </details>` : "";
  openDialog(
    "client-history",
    "客户端信号详情",
    mac,
    `<p>当前信号：${client?.rssi_dbm == null ? "未上报" : signalMeter(client.rssi_dbm)}${client?.rssi_dbm != null && client.rssi_at ? ` · 采样 ${ago(client.rssi_at)}` : ""}</p>
    <p class="muted">信号列表和历史统一采用 CAPWAP 的 dBm 数据。漫游使用当次触发、邻居报告或独立 RSSI 邻居表；不是直接用这条展示缓存作决策。</p>
    ${diagnostics}
    <div class="toolbar">
      ${select("client_history_duration", "", { 300: "最近 5 分钟", 900: "最近 15 分钟", 3600: "最近 1 小时" }, duration, 'aria-label="时间范围"')}
      <button type="button" class="btn secondary sm" data-client-history="${esc(mac)}">刷新</button>
    </div>
    ${historyPlot(chart, "rssi_dbm", 90000)}
    ${table(
      ["时间", "信号", "AP / 射频", "SSID"],
      rows
        .slice(-20)
        .reverse()
        .map(
          (r) =>
            `<tr><td class="num">${esc(new Date(r.at).toLocaleTimeString("zh-CN", { hour12: false }))}</td><td class="num">${r.rssi_dbm} dBm</td><td>${esc(apName(r.ap_id))} / 射频 ${r.radio_id}</td><td>${esc(r.ssid || "—")}</td></tr>`,
        )
        .join(""),
    )}`,
  );
}

document.addEventListener("click", async (e) => {
  const b = e.target.closest("[data-client-history]");
  if (!b) return;
  try {
    await showClientSignalHistory(
      b.dataset.clientHistory,
      b.dataset.clientHistory === clientHistoryMAC
        ? clientHistoryDuration
        : 300,
    );
  } catch (error) {
    toast(error.message);
  }
});

document.addEventListener("change", async (e) => {
  if (e.target.name !== "client_history_duration") return;
  try {
    await showClientSignalHistory(clientHistoryMAC, Number(e.target.value));
  } catch (error) {
    toast(error.message);
  }
});
