'use strict';
let managementEditing=null;

function renderManagement(){
 const cfg=data.config,groups=cfg.groups||[],templates=cfg.templates||[],profiles=cfg.ap_profiles||[];
 const groupRows=groups.map(g=>`<tr><td>${esc(g.name)}</td><td>${profiles.filter(p=>p.group_id===g.id).length}</td><td><button class="text-button" data-group-edit="${esc(g.id)}">编辑</button><button class="text-button" data-group-delete="${esc(g.id)}">删除</button></td></tr>`).join('');
 const templateRows=templates.map(t=>`<tr><td>${esc(t.name)}</td><td>${esc(t.model||'通用模板')}<small>${esc(t.hardware_version||'所有硬件版本')}</small></td><td><button class="text-button" data-template-edit="${esc(t.id)}">编辑</button><button class="text-button" data-template-delete="${esc(t.id)}">删除</button></td></tr>`).join('');
 const devices=data.aps.map(a=>{const p=profiles.find(p=>p.ap_id===a.id),st=data.apply.find(s=>s.ap_id===a.id&&s.service_id==='ap-settings');return `<tr><td>${esc(apName(a.id))}<small>${esc(p?.location||a.location||'')}</small></td><td>${esc(groups.find(g=>g.id===p?.group_id)?.name||'未分组')}</td><td>${esc(templates.find(t=>t.id===p?.template_id)?.name||'未使用模板')}</td><td>${st?statePill(st.state):'等待同步'}<small>${esc(st?.error||'')}</small></td><td><button class="text-button" data-ap-settings="${esc(a.id)}">设置</button><button class="text-button" data-ap-copy="${esc(a.id)}">复制</button>${!a.online?`<button class="text-button" data-ap-replace="${esc(a.id)}">替换</button>`:''}</td></tr>`}).join('');
 const operations=Object.values(data.operations||{}).sort((a,b)=>b.started.localeCompare(a.started)).slice(0,20);
 return panel('AP 配置继承','全局默认 → 模板 → 分组 → AP 单独设置。空白项保持继承，明确停用也会覆盖上级。',`<div class="toolbar"><button class="secondary" data-ap-defaults="1">全局 AP 默认设置</button><a class="secondary" href="/api/backup" download>导出配置备份</a><label class="secondary">导入配置<input type="file" id="management-import" accept="application/json" class="hidden"></label></div><p class="help">配置备份包含无线密钥与 AP 账号；导入后在线设备会自动同步。</p>`)+panel('AP 分组','按分组绑定无线服务与管理参数。',table(['分组名称','设备数量','操作'],groupRows),'<button class="secondary" data-group-new="1">新建分组</button>')+panel('AP 模板','通用模板或指定型号和硬件的模板。',table(['模板名称','适用设备','操作'],templateRows),'<button class="secondary" data-template-new="1">新建模板</button>')+panel('设备设置','保存后的配置会在设备在线或重新接入时同步。',table(['设备 / 位置','分组','模板','同步状态','操作'],devices))+panel('设备操作','重启与复位在重新观察到 AP 接入后才标记完成。',table(['AP','操作','状态','时间'],operations.map(j=>`<tr><td>${esc(apName(j.ap_id))}</td><td>${esc(({reboot:'重启', 'factory-reset':'恢复出厂'})[j.action]||j.action)}</td><td>${esc(({sending:'发送中',waiting_reconnect:'等待重新接入',completed:'已重新接入',failed:'失败',uncertain:'结果待确认'})[j.state]||j.state)}<small>${esc(j.error||'')}</small></td><td>${esc(new Date(j.started).toLocaleString())}</td></tr>`).join('')));
}

function optionTri(name,label,value){return select('opt_'+name,label,{'':'继承 / 保持',on:'启用',off:'停用'},value==null?'':value?'on':'off')}
function planFields(prefix,label,plan){
 const clock=n=>String(Math.floor(n/60)).padStart(2,'0')+':'+String(n%60).padStart(2,'0');
 return `<fieldset><legend>${label}</legend><div class="form-grid">${select(prefix+'_state','计划状态',{'':'继承 / 保持',on:'启用计划',off:'停用计划'},plan==null?'':plan.enabled?'on':'off')}${field(prefix+'_timezone','时区',plan?.timezone||data.timezone||'Asia/Singapore','text')}${prefix==='led'?select(prefix+'_action','时段内的 LED 状态',{on:'点亮，时段外关闭',off:'关闭，时段外点亮'},plan?.action||'on'):''}${['一','二','三','四','五','六','日'].map((d,i)=>field(prefix+'_day_'+i,'周'+d,(plan?.windows||[]).filter(w=>w.days&(1<<i)).map(w=>clock(w.start_minute)+'-'+clock(w.end_minute)).join(','),'text','placeholder="08:00-18:00"')).join('')}</div><p class="help">多个时段用英文逗号分开。重启计划在每个时段开始后执行一次，程序重启不会重复执行已记录的操作。</p></fieldset>`;
}
function managementOptions(o,ap){
 const ports=ap?((ap.ports?.length?ap.ports.filter(p=>!p.uplink).map(p=>p.id):Array.from({length:ap.downlink_port_count||0},(_,i)=>i+1))):Array.from({length:16},(_,i)=>i+1);for(const p of o.ports||[])if(!ports.includes(p.id))ports.push(p.id);ports.sort((a,b)=>a-b);
 const supports=bit=>!ap||!!(ap.general_capabilities?.[Math.floor(bit/32)]&(2**(bit%32)));
 const basic=`<div class="form-grid">${field('opt_echo_seconds','AP 心跳（秒）',o.echo_seconds??'','number','min="5" max="120" placeholder="继承 / 保持"')}${field('opt_echo_misses','心跳超时次数',o.echo_misses??'','number','min="1" max="20" placeholder="继承 / 保持"')}${field('opt_client_keep_alive','客户端保活（秒）',o.client_keep_alive??'','number','min="5" max="65535" placeholder="继承 / 保持"')}${field('opt_client_idle','客户端空闲时间（秒）',o.client_idle??'','number','min="30" max="86400" placeholder="继承 / 保持"')}${optionTri('offline_self_manage','AC 离线后允许 AP 自主管理',o.offline_self_manage)}${optionTri('led','指示灯',o.led)}${supports(42)?optionTri('led_wifi_sync','指示灯随无线状态同步',o.led_wifi_sync):''}</div>`;
 const account=`<div class="form-grid">${field('opt_account_username','AP 管理账号',o.account?.username||'','text','maxlength="63" placeholder="留空继承"')}<label>AP 管理密码<input name="opt_account_password" type="password" autocomplete="new-password" maxlength="63" placeholder="${o.account?.has_password?'已设置，留空保留':'填写账号时须设置密码'}"></label></div>`;
 const advanced=`<div class="form-grid">${supports(92)?select('opt_rf_mode_enabled','整机射频模式切换',{'':'继承 / 保持',on:'启用',off:'停用'},o.rf_mode==null?'':o.rf_mode.enabled?'on':'off')+select('opt_rf_mode_id','射频工作模式（改变后 AP 可能重启）',Object.fromEntries((ap?ap.radio_modes||[]:data.aps.flatMap(a=>a.radio_modes||[])).map(m=>[m.id,m.name])),o.rf_mode?.id??ap?.radio_mode?.id??''):''}${supports(44)?optionTri('mesh','Mesh 无线组网',o.mesh):''}${supports(100)?optionTri('usb','USB 外设',o.usb):''}${supports(77)?select('opt_bluetooth','蓝牙模式',{'':'继承 / 保持','-1':'停止控制',...(supports(102)?{0:'物联网网关'}:{}),1:'电子价签',...(supports(79)?{2:'蓝牙运维'}:{})},o.bluetooth??''):''}${(!ap||ap.support_trunk)?optionTri('trunk','下联 Trunk',o.trunk):''}${supports(73)?optionTri('fit_fat_button','FIT/FAT 模式按键',o.fit_fat_button):''}${field('opt_region_code','设备地区编号',o.region_code??'','number','min="0" max="255" placeholder="保持设备地区"')}${supports(71)?select('opt_lag','链路聚合',{'':'继承 / 保持',on:'启用',off:'停用'},o.lag==null?'':o.lag.enabled?'on':'off')+select('opt_lag_mode','聚合模式',{0:'静态',1:'动态'},o.lag?.mode||0)+field('opt_lag_ports','聚合物理端口',o.lag?.ports?.join(',')||'','text','placeholder="例如 1,2"'):''}</div><h3 class="section-title">下联端口</h3><p class="help">仅填写要配置的物理端口；此列表覆盖继承的端口列表。VLAN 留空表示保持，端口范围来自设备上报的下联端口能力。</p>${table(['物理端口','VLAN ID','端口状态'],ports.map(id=>{const p=o.ports?.find(p=>p.id===id);return `<tr><td>${id}</td><td><input name="opt_port_${id}_vlan" data-physical-port="${id}" type="number" min="1" max="4094" value="${p?.vlan??''}" aria-label="端口 ${id} VLAN"></td><td>${select('opt_port_'+id+'_enabled','',{'':'保持',on:'启用',off:'停用'},p?.enabled==null?'':p.enabled?'on':'off')}</td></tr>`}).join(''))}`;
 const radios=`<p class="help">按设备射频编号继承；AP 单独配置的字段优先。高级参数可从现有 AP 射频设置复制成模板。</p>${table(['射频','状态','信道（0 自动）','功率 dBm'],[...new Set([...(ap?.capabilities?.length?ap.capabilities.map(c=>c.radio_id):[1,2,...data.aps.flatMap(a=>(a.capabilities||[]).map(c=>c.radio_id))]),...(o.radios||[]).map(r=>r.radio_id)])].sort((a,b)=>a-b).map(id=>{const r=o.radios?.find(r=>r.radio_id===id);return `<tr><td>${id}</td><td>${select('inherit_radio_'+id+'_enabled','',{'':'保持',on:'启用',off:'关闭'},r?.enabled==null?'':r.enabled?'on':'off')}</td><td><input name="inherit_radio_${id}_channel" data-inherited-radio="${id}" type="number" min="0" max="233" value="${r?.channel??''}"></td><td><input name="inherit_radio_${id}_power" type="number" min="0" max="100" value="${r?.power_dbm??''}"></td></tr>`}).join(''))}`;return {basic,account,advanced,radios,schedules:planFields('led','LED 定时',o.led_schedule)+planFields('reboot','AP 定时重启',o.reboot_schedule)};
}
function managementEditor(kind,item){
 const cfg=data.config;managementEditing={kind,item};const o=item?.options|| (kind==='defaults'?cfg.ap_defaults||{}:{}),ap=kind==='ap'?data.aps.find(a=>a.id===item.ap_id):null;
 let identity='';
 if(kind==='ap')identity=`<div class="form-grid">${field('management_name','AP 名称',item.name||apName(item.ap_id),'text','maxlength="52"')}${field('management_location','安装位置 / 备注',item.location||'','text','maxlength="200"')}${select('management_group','AP 分组',{'':'未分组',...Object.fromEntries((cfg.groups||[]).map(g=>[g.id,g.name]))},item.group_id||'')}${select('management_template','继承模板',{'':'不使用模板',...Object.fromEntries((cfg.templates||[]).map(t=>[t.id,t.name]))},item.template_id||'')}</div>`;
 else if(kind!=='defaults')identity=`<div class="form-grid">${field('management_name',kind==='group'?'分组名称':'模板名称',item?.name||'','text','required maxlength="52"')}${kind==='template'?field('management_model','适用 AP 型号',item?.model||'','text','placeholder="留空为通用模板"')+field('management_hardware','硬件版本',item?.hardware_version||'','text','placeholder="留空为所有版本"'):''}</div>`;
 const parts=managementOptions(o,ap);
 openDialog('management',kind==='ap'?apName(item.ap_id)+' · 管理设置':kind==='group'?'AP 分组':kind==='template'?'AP 模板':'全局 AP 默认设置','AP MANAGEMENT',`<form id="management-form" novalidate><div class="notice">空白参数继承上级设置；启用或停用会明确覆盖。设置按设备能力处理，失败会显示原因。</div>${tabs([['ap-basic','基本设置'],['ap-schedules','时间计划'],['ap-radios','继承射频'],['ap-account','设备账号'],['ap-advanced','下联与设备选项']])}${pane('ap-basic',identity+parts.basic,true)}${pane('ap-schedules',parts.schedules)}${pane('ap-radios',parts.radios)}${pane('ap-account',parts.account)}${pane('ap-advanced',parts.advanced)}${formEnd()}</form>`);
}
function readPlan(f,prefix){
 const v=name=>f.elements[name]?.value||'';if(!v(prefix+'_state'))return undefined;
 const plan={enabled:v(prefix+'_state')==='on',timezone:v(prefix+'_timezone'),action:prefix==='led'?v(prefix+'_action'):'on',windows:[]};
 const minute=s=>{const m=/^(\d{1,2}):(\d{2})$/.exec(s.trim());if(!m||+m[1]>24||+m[2]>59||+m[1]===24&&+m[2])throw Error('时间格式为 HH:MM');return +m[1]*60+(+m[2])};
 for(let i=0;i<7;i++)for(const window of v(prefix+'_day_'+i).split(',').map(s=>s.trim()).filter(Boolean)){const parts=window.split('-');if(parts.length!==2)throw Error('时段格式为 08:00-18:00');plan.windows.push({days:1<<i,start_minute:minute(parts[0]),end_minute:minute(parts[1])})}
 return plan;
}
function readManagementOptions(f){
 const v=n=>f.elements[n]?.value||'',o={};
 for(const k of ['echo_seconds','echo_misses','client_keep_alive','client_idle','region_code'])if(v('opt_'+k)!=='')o[k]=Number(v('opt_'+k));
 for(const k of ['offline_self_manage','led','led_wifi_sync','trunk','fit_fat_button','mesh','usb'])if(v('opt_'+k))o[k]=v('opt_'+k)==='on';
 if(v('opt_account_username'))o.account={username:v('opt_account_username'),password:v('opt_account_password')};
 const radios=[];for(const el of f.querySelectorAll("[data-inherited-radio]")){const id=Number(el.dataset.inheritedRadio);const old=managementEditing?.item?.options?.radios?.find(r=>r.radio_id===id)|| (managementEditing?.kind==='defaults'?data.config.ap_defaults?.radios?.find(r=>r.radio_id===id):null);const r={...(old||{}),radio_id:id};delete r.ap_id;for(const [key,field] of [['enabled','enabled'],['channel','channel'],['power','power_dbm']]){const val=v('inherit_radio_'+id+'_'+key);delete r[field];if(val!=='')r[field]=key==='enabled'?val==='on':Number(val)}if(Object.keys(r).some(k=>k!=='radio_id'))radios.push(r)}if(radios.length)o.radios=radios;const ports=[];for(const el of f.querySelectorAll("[data-physical-port]")){const id=Number(el.dataset.physicalPort),vlan=v('opt_port_'+id+'_vlan'),enabled=v('opt_port_'+id+'_enabled');if(vlan||enabled)ports.push({id,...(vlan?{vlan:Number(vlan)}:{}),...(enabled?{enabled:enabled==='on'}:{})})}if(ports.length)o.ports=ports;
 if(v('opt_rf_mode_enabled'))o.rf_mode={enabled:v('opt_rf_mode_enabled')==='on',id:Number(v('opt_rf_mode_id'))};
 if(v('opt_bluetooth')!=='')o.bluetooth=Number(v('opt_bluetooth'));
 if(v('opt_lag'))o.lag={enabled:v('opt_lag')==='on',mode:Number(v('opt_lag_mode')),ports:v('opt_lag_ports').split(',').filter(Boolean).map(Number)};
 const led=readPlan(f,'led'),reboot=readPlan(f,'reboot');if(led)o.led_schedule=led;if(reboot)o.reboot_schedule=reboot;
 return o;
}
document.addEventListener('click',async event=>{
 const b=event.target.closest('button');if(!b)return;
 try{
  if(b.dataset.apSettings){const p=(data.config.ap_profiles||[]).find(p=>p.ap_id===b.dataset.apSettings)||{ap_id:b.dataset.apSettings,options:{}};managementEditor('ap',p)}
  if(b.dataset.apDefaults)managementEditor('defaults',null);
  if(b.dataset.groupNew||b.dataset.groupEdit)managementEditor('group',(data.config.groups||[]).find(g=>g.id===b.dataset.groupEdit));
  if(b.dataset.templateNew||b.dataset.templateEdit)managementEditor('template',(data.config.templates||[]).find(t=>t.id===b.dataset.templateEdit));
  if(b.dataset.groupDelete&&confirm('删除此分组？仍被 AP 或无线服务引用时会拒绝删除。')){await api('groups/'+encodeURIComponent(b.dataset.groupDelete),undefined,'DELETE');await refresh()}
  if(b.dataset.templateDelete&&confirm('删除此模板？仍被 AP 引用时会拒绝删除。')){await api('templates/'+encodeURIComponent(b.dataset.templateDelete),undefined,'DELETE');await refresh()}
  if(b.dataset.apAction){if(!confirm((b.dataset.apAction==='factory-reset'?'恢复出厂会清除 AP 本机配置，设备将重新接入控制器。':'设备上的客户端将短暂断开。')+'\n确认操作 '+apName(b.dataset.actionAp)+'？'))return;await api('aps/'+encodeURIComponent(b.dataset.actionAp)+'/action',{action:b.dataset.apAction});toast('AP 已应答，等待设备重新接入');await refresh()}
  if(b.dataset.apCopy){managementEditing={kind:'copy',id:b.dataset.apCopy};openDialog('management-copy','复制 AP 设置','COPY AP',`<form id="management-copy-form"><p class="help">保留目标 AP 的名称、位置、分组和模板；未勾选射频时保留其射频配置。</p><label>目标 AP<select name="targets" multiple required>${data.aps.filter(a=>a.id!==b.dataset.apCopy).map(a=>`<option value="${esc(a.id)}">${esc(apName(a.id))}</option>`).join('')}</select></label>${check('radios','同时复制射频设置（检查目标能力）',false)}${formEnd()}</form>`)}
  if(b.dataset.apReplace){const old=data.aps.find(a=>a.id===b.dataset.apReplace);managementEditing={kind:'replace',id:old.id};openDialog('management-replace','替换离线 AP','REPLACE AP',`<form id="management-replace-form"><p>保留原设备的配置与服务绑定，重新分配目标 AP 的 WLAN 编号。原 AP 重新接入时清理其旧服务。</p>${select('target','替换设备',Object.fromEntries(data.aps.filter(a=>a.id!==old.id&&a.model===old.model&&a.hardware_version===old.hardware_version).map(a=>[a.id,apName(a.id)])),'')}${formEnd()}</form>`)}
  if(b.dataset.clientLabel){const c=data.clients.find(c=>c.mac===b.dataset.clientLabel);managementEditing={kind:'client',id:c.mac};openDialog('client-label','编辑客户端名称','WIRELESS CLIENT',`<form id="client-label-form">${field('name','名称',c.name||'','text','maxlength="64"')}${field('note','备注',c.note||'','text','maxlength="200"')}${formEnd('保存')}</form>`)}
  if(b.dataset.clientDisconnect){await api('clients/'+encodeURIComponent(b.dataset.clientDisconnect)+'/disconnect',{});toast('AP 已应答客户端下线请求，等待关联状态上报');await refresh()}
 }catch(error){toast(error.message)}
});
document.addEventListener('submit',async event=>{
 const f=event.target;if(!['management-form','management-copy-form','management-replace-form','client-label-form'].includes(f.id))return;event.preventDefault();if(!f.reportValidity())return;
 const error=f.querySelector('#form-error'),button=f.querySelector('[type=submit]');button.disabled=true;
 try{
  const edit=managementEditing;
  if(f.id==='management-form'){
   const options=readManagementOptions(f),value=n=>f.elements[n]?.value||'';
   if(edit.kind==='defaults')await api('ap-defaults',options);
   else if(edit.kind==='ap')await api('aps/'+encodeURIComponent(edit.item.ap_id)+'/settings',{name:value('management_name'),location:value('management_location'),group_id:value('management_group'),template_id:value('management_template'),options});
   else if(edit.kind==='group')await api('groups',{id:edit.item?.id||'',name:value('management_name'),options});
   else await api('templates',{id:edit.item?.id||'',name:value('management_name'),model:value('management_model'),hardware_version:value('management_hardware'),options});
  }else if(f.id==='management-copy-form')await api('aps/'+encodeURIComponent(edit.id)+'/copy',{targets:[...f.elements.targets.selectedOptions].map(o=>o.value),radios:f.elements.radios.checked});
  else if(f.id==='management-replace-form')await api('aps/'+encodeURIComponent(edit.id)+'/replace',{target_ap_id:f.elements.target.value});
  else await api('clients/'+encodeURIComponent(edit.id)+'/label',{name:f.elements.name.value,note:f.elements.note.value});
  $('#editor').close();dialogKind='';await refresh();toast('已保存，等待设备同步');
 }catch(e){error.textContent=e.message}finally{button.disabled=false}
});
document.addEventListener('change',async event=>{
 if(event.target.id!=='management-import')return;const file=event.target.files[0];if(!file)return;
 try{const backup=JSON.parse(await file.text());if(!confirm('导入备份并同步 AP？备份中没有的无线服务将进入删除流程。'))return;await api('restore',backup);toast('配置已导入，等待 AP 同步');await refresh()}catch(e){toast(e.message)}
});

let managementTab='basic';
function renderDeviceManagement(){return `<div class="editor-tabs management-tabs">${[['basic','AP 与分组'],['mesh','Mesh 组网'],['bluetooth','蓝牙与物联网']].map(([id,label])=>`<button type="button" data-management-tab="${id}" class="${managementTab===id?'active':''}">${label}</button>`).join('')}</div>`+(managementTab==='mesh'?renderMesh():managementTab==='bluetooth'?renderBluetooth():renderManagement())}
document.addEventListener('click',e=>{const b=e.target.closest('[data-management-tab]');if(!b)return;managementTab=b.dataset.managementTab;renderContent()});
