"use strict";

let managementEditing = null;

function renderManagement(view) {
  const cfg = data.config;
  const groups = cfg.groups || [];
  const templates = cfg.templates || [];
  const profiles = cfg.ap_profiles || [];

  if (view === "management") {
    return panel(
      "AP 分组",
      table(
        ["分组名称", "AP 数量", "自动分组规则", "操作"],
        groups
          .map(
            (g) =>
              `<tr>
                <td><strong>${esc(g.name)}</strong></td>
                <td class="num">${profiles.filter((p) => p.group_id === g.id).length}</td>
                <td class="num">${g.strategy?.enabled ? esc(g.strategy.start_ip) + " – " + esc(g.strategy.end_ip) : "手动"}</td>
                <td>
                  <div class="actions">
                    <button type="button" class="text-button" data-group-edit="${esc(g.id)}">编辑</button>
                    <button type="button" class="text-button danger" data-group-delete="${esc(g.id)}">删除</button>
                  </div>
                </td>
              </tr>`,
          )
          .join(""),
      ),
    );
  }

  if (view === "templates") {
    return panel(
      "AP 模板",
      table(
        ["模板名称", "适用型号", "硬件版本", "操作"],
        templates
          .map(
            (t) =>
              `<tr>
                <td><strong>${esc(t.name)}</strong></td>
                <td>${esc(t.model || "通用")}</td>
                <td>${esc(t.hardware_version || "全部版本")}</td>
                <td>
                  <div class="actions">
                    <button type="button" class="text-button" data-template-edit="${esc(t.id)}">编辑</button>
                    <button type="button" class="text-button danger" data-template-delete="${esc(t.id)}">删除</button>
                  </div>
                </td>
              </tr>`,
          )
          .join(""),
      ),
    );
  }

  managementEditing = { kind: "defaults", item: null };
  const defaults = cfg.ap_defaults || {};
  const parts = managementOptions(defaults, null);
  return panel(
    "全局默认参数",
    `<div class="panel-body">
      <form id="management-form" data-kind="defaults" data-inline="1" novalidate>
        ${tabs([
          ["ap-basic", "基本设置"],
          ["ap-schedules", "时间计划"],
          ["ap-radios", "默认射频"],
          ["ap-account", "设备账号"],
          ["ap-advanced", "端口与设备选项"],
        ])}
        ${pane("ap-basic", parts.basic, true)}
        ${pane("ap-schedules", parts.schedules)}
        ${pane("ap-radios", parts.radios)}
        ${pane("ap-account", parts.account)}
        ${pane("ap-advanced", parts.advanced)}
        <p class="help">优先级：单台 AP &gt; 分组 &gt; 模板 &gt; 全局默认。</p>
        ${formEnd()}
      </form>
    </div>`,
  );
}

function optionTri(name, label, value) {
  return select(
    "opt_" + name,
    label,
    { "": "继承 / 保持", on: "启用", off: "停用" },
    value == null ? "" : value ? "on" : "off",
  );
}

function planFields(prefix, label, plan) {
  const clock = (n) =>
    String(Math.floor(n / 60)).padStart(2, "0") +
    ":" +
    String(n % 60).padStart(2, "0");
  return `<fieldset>
    <legend>${label}</legend>
    <div class="form-grid">
      ${select(prefix + "_state", "计划状态", { "": "继承 / 保持", on: "启用", off: "停用" }, plan == null ? "" : plan.enabled ? "on" : "off")}
      ${field(prefix + "_timezone", "时区", plan?.timezone || data.timezone || "Asia/Singapore", "text")}
      ${prefix === "led" ? select(prefix + "_action", "时段内 LED 状态", { on: "点亮，时段外关闭", off: "关闭，时段外点亮" }, plan?.action || "on") : ""}
      ${["一", "二", "三", "四", "五", "六", "日"]
        .map((d, i) =>
          field(
            prefix + "_day_" + i,
            "周" + d,
            (plan?.windows || [])
              .filter((w) => w.days & (1 << i))
              .map((w) => clock(w.start_minute) + "-" + clock(w.end_minute))
              .join(","),
            "text",
            'placeholder="08:00-18:00"',
          ),
        )
        .join("")}
    </div>
    <p class="help">多个时段用英文逗号分隔。</p>
  </fieldset>`;
}

function managementOptions(o, ap) {
  const ports = ap
    ? ap.ports?.length
      ? ap.ports.filter((p) => !p.uplink).map((p) => p.id)
      : Array.from({ length: ap.downlink_port_count || 0 }, (_, i) => i + 1)
    : Array.from({ length: 16 }, (_, i) => i + 1);
  for (const p of o.ports || []) if (!ports.includes(p.id)) ports.push(p.id);
  ports.sort((a, b) => a - b);

  const supports = (bit) =>
    !ap ||
    !!(ap.general_capabilities?.[Math.floor(bit / 32)] & (2 ** (bit % 32)));

  const basic = `<div class="form-grid">
    ${field("opt_echo_seconds", "AP 心跳间隔", o.echo_seconds ?? "", "number", 'min="5" max="120" placeholder="继承"', "秒")}
    ${field("opt_echo_misses", "心跳超时次数", o.echo_misses ?? "", "number", 'min="1" max="20" placeholder="继承"', "次")}
    ${field("opt_client_keep_alive", "客户端保活", o.client_keep_alive ?? "", "number", 'min="5" max="65535" placeholder="继承"', "秒")}
    ${field("opt_client_idle", "客户端空闲超时", o.client_idle ?? "", "number", 'min="30" max="86400" placeholder="继承"', "秒")}
    ${optionTri("offline_self_manage", "离线自主管理", o.offline_self_manage)}
    ${optionTri("led", "指示灯", o.led)}
    ${supports(42) ? optionTri("led_wifi_sync", "指示灯随无线状态同步", o.led_wifi_sync) : ""}
  </div>`;

  const account = `<div class="form-grid">
    ${field("opt_account_username", "AP 管理账号", o.account?.username || "", "text", 'maxlength="63" placeholder="留空继承"')}
    <label><span>AP 管理密码</span><input name="opt_account_password" type="password" autocomplete="new-password" maxlength="63" placeholder="${o.account?.has_password ? "留空不修改密码" : "填写账号时须设置密码"}"></label>
  </div>`;

  const advanced = `<div class="form-grid">
    ${supports(92) ? select("opt_rf_mode_enabled", "整机射频模式切换", { "": "继承 / 保持", on: "启用", off: "停用" }, o.rf_mode == null ? "" : o.rf_mode.enabled ? "on" : "off") + select("opt_rf_mode_id", "射频工作模式（修改后 AP 可能重启）", Object.fromEntries((ap ? ap.radio_modes || [] : data.aps.flatMap((a) => a.radio_modes || [])).map((m) => [m.id, m.name])), o.rf_mode?.id ?? ap?.radio_mode?.id ?? "") : ""}
    ${supports(44) ? optionTri("mesh", "Mesh 无线组网", o.mesh) : ""}
    ${supports(100) ? optionTri("usb", "USB 外设", o.usb) : ""}
    ${!ap || ap.support_trunk ? optionTri("trunk", "下联 Trunk", o.trunk) : ""}
    ${supports(73) ? optionTri("fit_fat_button", "FIT/FAT 按键", o.fit_fat_button) : ""}
    ${field("opt_region_code", "地区编号", o.region_code ?? "", "number", 'min="0" max="255" placeholder="保持设备地区"')}
    ${supports(71) ? select("opt_lag", "链路聚合", { "": "继承 / 保持", on: "启用", off: "停用" }, o.lag == null ? "" : o.lag.enabled ? "on" : "off") + select("opt_lag_mode", "聚合模式", { 0: "静态", 1: "动态" }, o.lag?.mode || 0) + field("opt_lag_ports", "聚合端口", o.lag?.ports?.join(",") || "", "text", 'placeholder="1,2"') : ""}
  </div>
  <h3 class="section-title">下联端口</h3>
  ${table(
    ["端口", "VLAN ID", "状态"],
    ports
      .map((id) => {
        const p = o.ports?.find((p) => p.id === id);
        return `<tr>
          <td class="num">端口 ${id}</td>
          <td><input name="opt_port_${id}_vlan" data-physical-port="${id}" type="number" min="1" max="4094" value="${p?.vlan ?? ""}" aria-label="端口 ${id} VLAN" placeholder="保持"></td>
          <td>${select("opt_port_" + id + "_enabled", "", { "": "保持", on: "启用", off: "停用" }, p?.enabled == null ? "" : p.enabled ? "on" : "off")}</td>
        </tr>`;
      })
      .join(""),
  )}`;

  const radioIds = [
    ...new Set([
      ...(ap?.capabilities?.length
        ? ap.capabilities.map((c) => c.radio_id)
        : [
            1,
            2,
            ...data.aps.flatMap((a) =>
              (a.capabilities || []).map((c) => c.radio_id),
            ),
          ]),
      ...(o.radios || []).map((r) => r.radio_id),
    ]),
  ].sort((a, b) => a - b);

  const radioRows = radioIds
    .map((id) => {
      const r = o.radios?.find((r) => r.radio_id === id);
      return `<tr>
        <td class="num">射频 ${id}</td>
        <td>${select("inherit_radio_" + id + "_enabled", "", { "": "保持", on: "启用", off: "关闭" }, r?.enabled == null ? "" : r.enabled ? "on" : "off")}</td>
        <td><input name="inherit_radio_${id}_channel" data-inherited-radio="${id}" type="number" min="0" max="233" value="${r?.channel ?? ""}" placeholder="继承"></td>
        <td><input name="inherit_radio_${id}_power" type="number" min="0" max="100" value="${r?.power_dbm ?? ""}" placeholder="继承"></td>
      </tr>`;
    })
    .join("");

  return {
    basic,
    account,
    advanced,
    radios: table(
      ["射频", "状态", "信道（0 自动）", "功率（dBm）"],
      radioRows,
    ),
    schedules:
      planFields("led", "LED 定时", o.led_schedule) +
      planFields("reboot", "定时重启", o.reboot_schedule),
  };
}

function managementEditor(kind, item) {
  const cfg = data.config;
  managementEditing = { kind, item };
  const o =
    item?.options || (kind === "defaults" ? cfg.ap_defaults || {} : {});
  const ap = kind === "ap" ? data.aps.find((a) => a.id === item.ap_id) : null;
  let identity = "";
  if (kind === "ap") {
    identity = `<div class="form-grid">
      ${field("management_name", "AP 名称", item.name || apName(item.ap_id), "text", 'maxlength="52"')}
      ${field("management_location", "安装位置", item.location || "", "text", 'maxlength="200"')}
      ${select("management_group", "所属分组", { "": "未分组", ...Object.fromEntries((cfg.groups || []).map((g) => [g.id, g.name])) }, item.group_id || "")}
      ${select("management_template", "应用模板", { "": "不使用模板", ...Object.fromEntries((cfg.templates || []).map((t) => [t.id, t.name])) }, item.template_id || "")}
    </div>`;
  } else if (kind !== "defaults") {
    identity = `<div class="form-grid">
      ${field("management_name", kind === "group" ? "分组名称" : "模板名称", item?.name || "", "text", 'required maxlength="52"')}
      ${kind === "template" ? field("management_model", "适用 AP 型号", item?.model || "", "text", 'placeholder="留空为通用"') + field("management_hardware", "硬件版本", item?.hardware_version || "", "text", 'placeholder="留空为全部版本"') : ""}
    </div>`;
  }
  if (kind === "group") {
    const strategy = item?.strategy;
    identity += `<fieldset>
      <legend>按 IP 范围自动分组</legend>
      ${toggle("group_strategy_enabled", "启用自动分组", strategy?.enabled ?? !item)}
      <div class="form-grid">
        ${field("group_start_ip", "起始 IPv4", strategy?.start_ip || "", "text", 'placeholder="192.168.1.10"')}
        ${field("group_end_ip", "结束 IPv4", strategy?.end_ip || "", "text", 'placeholder="192.168.1.100"')}
      </div>
    </fieldset>`;
  }
  const parts = managementOptions(o, ap);
  const title =
    kind === "ap"
      ? apName(item.ap_id) + " · 参数配置"
      : kind === "group"
        ? item
          ? "编辑分组 · " + item.name
          : "新建分组"
        : kind === "template"
          ? item
            ? "编辑模板 · " + item.name
            : "新建模板"
          : "全局默认参数";

  openDialog(
    "management",
    title,
    "",
    `<form id="management-form" data-kind="${kind}" novalidate>
      ${tabs([
        ["ap-basic", "基本设置"],
        ["ap-schedules", "时间计划"],
        ["ap-radios", "继承射频"],
        ["ap-account", "设备账号"],
        ["ap-advanced", "端口与设备选项"],
      ])}
      ${pane("ap-basic", identity + parts.basic, true)}
      ${pane("ap-schedules", parts.schedules)}
      ${pane("ap-radios", parts.radios)}
      ${pane("ap-account", parts.account)}
      ${pane("ap-advanced", parts.advanced)}
      ${formEnd()}
    </form>`,
  );
}

function readPlan(f, prefix) {
  const v = (name) => f.elements[name]?.value || "";
  if (!v(prefix + "_state")) return undefined;
  const plan = {
    enabled: v(prefix + "_state") === "on",
    timezone: v(prefix + "_timezone"),
    action: prefix === "led" ? v(prefix + "_action") : "on",
    windows: [],
  };
  const minute = (s) => {
    const m = /^(\d{1,2}):(\d{2})$/.exec(s.trim());
    if (!m || +m[1] > 24 || +m[2] > 59 || (+m[1] === 24 && +m[2]))
      throw Error("时间格式为 HH:MM");
    return +m[1] * 60 + +m[2];
  };
  for (let i = 0; i < 7; i++)
    for (const window of v(prefix + "_day_" + i)
      .split(",")
      .map((s) => s.trim())
      .filter(Boolean)) {
      const parts = window.split("-");
      if (parts.length !== 2) throw Error("时段格式为 08:00-18:00");
      plan.windows.push({
        days: 1 << i,
        start_minute: minute(parts[0]),
        end_minute: minute(parts[1]),
      });
    }
  return plan;
}

function readManagementOptions(f) {
  const v = (n) => f.elements[n]?.value || "";
  const o = {};
  for (const k of [
    "echo_seconds",
    "echo_misses",
    "client_keep_alive",
    "client_idle",
    "region_code",
  ])
    if (v("opt_" + k) !== "") o[k] = Number(v("opt_" + k));
  for (const k of [
    "offline_self_manage",
    "led",
    "led_wifi_sync",
    "trunk",
    "fit_fat_button",
    "mesh",
    "usb",
  ])
    if (v("opt_" + k)) o[k] = v("opt_" + k) === "on";
  if (v("opt_account_username"))
    o.account = {
      username: v("opt_account_username"),
      password: v("opt_account_password"),
    };
  const kind = f.dataset.kind || managementEditing?.kind;
  const radios = [];
  for (const el of f.querySelectorAll("[data-inherited-radio]")) {
    const id = Number(el.dataset.inheritedRadio);
    const old =
      managementEditing?.item?.options?.radios?.find(
        (r) => r.radio_id === id,
      ) ||
      (kind === "defaults"
        ? data.config.ap_defaults?.radios?.find((r) => r.radio_id === id)
        : null);
    const r = { ...(old || {}), radio_id: id };
    delete r.ap_id;
    for (const [key, fieldName] of [
      ["enabled", "enabled"],
      ["channel", "channel"],
      ["power", "power_dbm"],
    ]) {
      const val = v("inherit_radio_" + id + "_" + key);
      delete r[fieldName];
      if (val !== "")
        r[fieldName] = key === "enabled" ? val === "on" : Number(val);
    }
    if (Object.keys(r).some((k) => k !== "radio_id")) radios.push(r);
  }
  if (radios.length) o.radios = radios;
  const ports = [];
  for (const el of f.querySelectorAll("[data-physical-port]")) {
    const id = Number(el.dataset.physicalPort);
    const vlan = v("opt_port_" + id + "_vlan");
    const enabled = v("opt_port_" + id + "_enabled");
    if (vlan || enabled)
      ports.push({
        id,
        ...(vlan ? { vlan: Number(vlan) } : {}),
        ...(enabled ? { enabled: enabled === "on" } : {}),
      });
  }
  if (ports.length) o.ports = ports;
  if (v("opt_rf_mode_enabled"))
    o.rf_mode = {
      enabled: v("opt_rf_mode_enabled") === "on",
      id: Number(v("opt_rf_mode_id")),
    };
  if (v("opt_lag"))
    o.lag = {
      enabled: v("opt_lag") === "on",
      mode: Number(v("opt_lag_mode")),
      ports: v("opt_lag_ports").split(",").filter(Boolean).map(Number),
    };
  const led = readPlan(f, "led");
  const reboot = readPlan(f, "reboot");
  if (led) o.led_schedule = led;
  if (reboot) o.reboot_schedule = reboot;
  return o;
}

document.addEventListener("click", async (event) => {
  const b = event.target.closest("button");
  if (!b) return;
  try {
    if (b.dataset.apBatchNames) {
      openDialog(
        "ap-names",
        "批量修改 AP 名称",
        "按 MAC 地址匹配已有 AP",
        `<div class="toolbar">
          <a class="btn secondary" href="/api/aps/names/template" download>下载 CSV 模板</a>
          <label class="btn primary file-btn">导入名称 CSV<input type="file" id="ap-names-import" accept=".csv,text/csv" class="hidden"></label>
        </div>
        <p class="help">导入只修改对应 MAC 的显示名称，保留其余参数。</p>`,
      );
      return;
    }
    if (b.dataset.apSettings) {
      const p = (data.config.ap_profiles || []).find(
        (p) => p.ap_id === b.dataset.apSettings,
      ) || { ap_id: b.dataset.apSettings, options: {} };
      managementEditor("ap", p);
    }
    if (b.dataset.apDefaults) managementEditor("defaults", null);
    if (b.dataset.groupNew || b.dataset.groupEdit)
      managementEditor(
        "group",
        (data.config.groups || []).find((g) => g.id === b.dataset.groupEdit),
      );
    if (b.dataset.templateNew || b.dataset.templateEdit)
      managementEditor(
        "template",
        (data.config.templates || []).find(
          (t) => t.id === b.dataset.templateEdit,
        ),
      );
    if (b.dataset.groupDelete && confirm("删除此分组？")) {
      await api(
        "groups/" + encodeURIComponent(b.dataset.groupDelete),
        undefined,
        "DELETE",
      );
      await refresh();
    }
    if (b.dataset.templateDelete && confirm("删除此模板？")) {
      await api(
        "templates/" + encodeURIComponent(b.dataset.templateDelete),
        undefined,
        "DELETE",
      );
      await refresh();
    }
    if (b.dataset.apAction) {
      if (
        !confirm(
          (b.dataset.apAction === "factory-reset"
            ? "恢复出厂将清除 AP 本机配置并重新接入。"
            : "AP 重启期间客户端会短暂断开。") +
            "\n确认操作 " +
            apName(b.dataset.actionAp) +
            "？",
        )
      )
        return;
      await api("aps/" + encodeURIComponent(b.dataset.actionAp) + "/action", {
        action: b.dataset.apAction,
      });
      toast("指令已下发");
      await refresh();
    }
    if (b.dataset.apCopy) {
      managementEditing = { kind: "copy", id: b.dataset.apCopy };
      const otherAPs = data.aps.filter((a) => a.id !== b.dataset.apCopy);
      openDialog(
        "management-copy",
        "复制 AP 配置",
        "源设备：" + apName(b.dataset.apCopy),
        `<form id="management-copy-form">
          <div class="picker-box">
            <div class="picker-head"><span>目标 AP</span><span>保留目标原有名称与分组</span></div>
            <div class="picker-list">${
              otherAPs
                .map(
                  (a) =>
                    `<label class="picker-item"><input type="checkbox" name="targets" value="${esc(a.id)}"><span>${esc(apName(a.id))}</span></label>`,
                )
                .join("") || '<span class="help">暂无其他 AP</span>'
            }</div>
          </div>
          <div class="form-grid">${check("radios", "同时复制射频参数", false)}</div>
          ${formEnd()}
        </form>`,
      );
    }
    if (b.dataset.apReplace) {
      const old = data.aps.find((a) => a.id === b.dataset.apReplace);
      managementEditing = { kind: "replace", id: old.id };
      const candidates = Object.fromEntries(
        data.aps
          .filter(
            (a) =>
              a.id !== old.id &&
              a.model === old.model &&
              a.hardware_version === old.hardware_version,
          )
          .map((a) => [a.id, apName(a.id)]),
      );
      openDialog(
        "management-replace",
        "替换离线 AP",
        "原设备：" + apName(old.id),
        `<form id="management-replace-form">
          ${select("target", "替换为同型号 AP", candidates, "")}
          <p class="help">保留原设备配置与无线服务绑定。</p>
          ${formEnd()}
        </form>`,
      );
    }
    if (b.dataset.clientLabel) {
      const c = data.clients.find((c) => c.mac === b.dataset.clientLabel);
      managementEditing = { kind: "client", id: c.mac };
      openDialog(
        "client-label",
        "编辑客户端名称",
        c.mac,
        `<form id="client-label-form">
          <div class="form-grid">
            ${field("name", "名称", c.name || "", "text", 'maxlength="64"')}
            ${field("note", "备注", c.note || "", "text", 'maxlength="200"')}
          </div>
          ${formEnd("保存")}
        </form>`,
      );
    }
    if (b.dataset.clientDisconnect) {
      await api(
        "clients/" +
          encodeURIComponent(b.dataset.clientDisconnect) +
          "/disconnect",
        {},
      );
      toast("已发送下线指令");
      await refresh();
    }
  } catch (error) {
    toast(error.message);
  }
});

document.addEventListener("submit", async (event) => {
  const f = event.target;
  if (
    ![
      "management-form",
      "management-copy-form",
      "management-replace-form",
      "client-label-form",
    ].includes(f.id)
  )
    return;
  event.preventDefault();
  if (!f.reportValidity()) return;
  const error = f.querySelector("#form-error");
  const button = f.querySelector("[type=submit]");
  button.disabled = true;
  try {
    const edit = managementEditing;
    if (f.id === "management-form") {
      const kind = f.dataset.kind || edit?.kind;
      const options = readManagementOptions(f);
      const value = (n) => f.elements[n]?.value || "";
      if (kind === "defaults") await api("ap-defaults", options);
      else if (kind === "ap")
        await api("aps/" + encodeURIComponent(edit.item.ap_id) + "/settings", {
          name: value("management_name"),
          location: value("management_location"),
          group_id: value("management_group"),
          template_id: value("management_template"),
          options,
        });
      else if (kind === "group")
        await api("groups", {
          id: edit.item?.id || "",
          name: value("management_name"),
          options,
          strategy: {
            enabled: f.elements.group_strategy_enabled.checked,
            type: "ip_range",
            start_ip: value("group_start_ip"),
            end_ip: value("group_end_ip"),
          },
        });
      else
        await api("templates", {
          id: edit.item?.id || "",
          name: value("management_name"),
          model: value("management_model"),
          hardware_version: value("management_hardware"),
          options,
        });
    } else if (f.id === "management-copy-form") {
      const targets = [
        ...f.querySelectorAll('input[name="targets"]:checked'),
      ].map((x) => x.value);
      if (!targets.length) throw Error("请选择至少一台目标 AP");
      await api("aps/" + encodeURIComponent(edit.id) + "/copy", {
        targets,
        radios: f.elements.radios.checked,
      });
    } else if (f.id === "management-replace-form")
      await api("aps/" + encodeURIComponent(edit.id) + "/replace", {
        target_ap_id: f.elements.target.value,
      });
    else
      await api("clients/" + encodeURIComponent(edit.id) + "/label", {
        name: f.elements.name.value,
        note: f.elements.note.value,
      });
    delete f.dataset.dirty;
    if ($("#editor").open) {
      $("#editor").close();
      dialogKind = "";
    }
    await refresh();
    toast("已保存并下发");
  } catch (e) {
    if (error) error.textContent = e.message;
    else toast(e.message);
  } finally {
    button.disabled = false;
  }
});

document.addEventListener("change", async (event) => {
  if (event.target.id === "ap-names-import") {
    const file = event.target.files[0];
    if (!file) return;
    try {
      const result = await api("aps/names/import", { csv: await file.text() });
      toast(
        `已更新 ${result.updated} 条，跳过 ${result.skipped} 条${result.errors?.length ? "；错误：" + result.errors.map((e) => `第 ${e.row} 行 ${e.error}`).join("；") : ""}`,
      );
      if ($("#editor").open) {
        $("#editor").close();
        dialogKind = "";
      }
      await refresh();
    } catch (e) {
      toast(e.message);
    } finally {
      event.target.value = "";
    }
    return;
  }
  if (event.target.id !== "management-import") return;
  const file = event.target.files[0];
  if (!file) return;
  try {
    const backup = JSON.parse(await file.text());
    if (!confirm("导入配置备份并同步到 AP？")) return;
    await api("restore", backup);
    toast("配置已恢复");
    await refresh();
  } catch (e) {
    toast(e.message);
  } finally {
    event.target.value = "";
  }
});
