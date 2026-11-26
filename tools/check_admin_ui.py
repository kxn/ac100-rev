#!/usr/bin/env python3
"""Exercise capability-dependent admin forms using real and synthetic AP data.
Uses mocked HTTP writes so no lab AP configuration changes during UI checks.
Requires the optional local Playwright environment, not a runtime dependency.
"""
import copy,json,pathlib,threading,http.server,urllib.request
from playwright.sync_api import sync_playwright
ROOT=pathlib.Path(__file__).resolve().parents[1];OUT=ROOT/'.local/ac100/ui-check';OUT.mkdir(parents=True,exist_ok=True)
def live(p):return json.load(urllib.request.urlopen('http://127.0.0.1:8090/api/'+p))
aps=live('aps');cfg=live('config');defaults=live('radios/defaults?ap_id='+aps[0]['id']+'&radio_id=1');clients=[{'mac':'02:03:04:05:06:07','ap_id':aps[0]['id'],'radio_id':1,'wlan_id':1,'ssid':'GoAC-Lab','state':'connected','rssi_dbm':-60,'ip':'192.0.2.20','last_seen':'2026-11-26T12:00:00Z'}];rates=live('rates');mobility=live('mobility');mobility['network_mode']=2;rrm=live('rrm');upgrades={'images':[{'id':'synthetic-image','format':'tp-container','model':aps[0]['model'],'version':'1.2.3 Build 20250317 Rel.43192','size':4096,'hardware_ids':[aps[0].get('hardware_id','fixture-hardware')],'firmware_id':'test-firmware'}],'jobs':{}};storm={'defaults':{'enabled':False,'rate':64,'custom':False,'arp_proxy':{'enabled':False,'scope':3,'to_unicast':False},'nd_proxy':{'enabled':False,'scope':3,'to_unicast':False},'mdns_proxy':{'enabled':False,'scope':3,'to_unicast':False},'protocols':[{'enabled':False,'scope':3,'rate':64}for _ in range(8)]},'protocols':['ARP','NS','RS','DHCP','DHCPv6','IGMP','Broadcast','Multicast']}
edca_queues=[{'aifs':a,'cw_min':lo,'cw_max':hi,'txop':tx}for a,lo,hi,tx in [(1,2,3,47),(1,3,4,94),(2,4,6,0),(3,4,10,0),(2,2,3,47),(2,3,4,94),(2,4,10,0),(3,4,10,0)]]
edca={'rules':[],'defaults':{'frequency_mask':0,'wmm':True,'custom':True,'scene':1,'configuration':{'enabled':True,'mode':0,'queues':edca_queues}}}
resource_values={'max_ap_sessions':1024,'command_queue_depth':1024,'max_services':1024,'max_groups':1024,'max_templates':1024,'max_policy_rules':1024,'max_trusted_servers':10000,'max_address_bindings':10000,'max_firmware_images':32,'firmware_storage_mib':512}
resources={'settings':resource_values,'defaults':resource_values,'fields':[{'key':k,'label':k,'min':16 if k=='firmware_storage_mib'else 1,'max':1000000}for k in resource_values]}


class Handler(http.server.SimpleHTTPRequestHandler):
 def __init__(self,*a,**k):super().__init__(*a,directory=str(ROOT/'uacgo/admin/assets'),**k)
 def log_message(self,*a):pass
server=http.server.ThreadingHTTPServer(('127.0.0.1',0),Handler);threading.Thread(target=server.serve_forever,daemon=True).start()
with sync_playwright() as p:
 browser=p.chromium.launch(headless=True,executable_path='/home/dl/.cache/ms-playwright/chromium-1255/chrome-linux64/chrome')
 errors=[];writes=[];signal_queries=[]
 for full in (False,True):
  profile=copy.deepcopy(aps);conf=copy.deepcopy(cfg);rf_defaults=copy.deepcopy(defaults)
  conf['config']['protection']={'servers':[{'id':'srv','name':'Router','address':'192.0.2.1'}],'bindings':[{'id':'bind','name':'Client','ip':'192.0.2.2','mac':'02:03:04:05:06:07','description':''}],'rules':[]}
  conf['config']['ap_defaults']['radios']=[{'radio_id':8,'channel':11,'advanced':{'rts':2000}}]
  conf['config']['groups']=[{'id':'floor','name':'Floor','options':{'echo_seconds':30}}]
  conf['config']['templates']=[{'id':'template','name':'Model','model':profile[0]['model'],'hardware_version':profile[0]['hardware_version'],'options':{}}]
  conf['config']['ap_profiles']=[{'ap_id':profile[0]['id'],'group_id':'floor','template_id':'template','name':'','location':'','options':{}}]
  if full:
   a=profile[0];a['general_capabilities']=[4294967295]*4;a['features']={k:True for k in ['rssi_control','channel_optimization','fragmentation','ssid_rate_limit','frame_rate_control','edca','edca_mode','wifi6_features','mlo','multicast','multicast_per_ssid','multicast_to_unicast','vlan_pool','band_steering','band_navigation']}
   conf['config']['mesh']={'enabled':True,'auto_add':False,'ssid':'ExistingBackhaul','members':[{'parent_ap_id':a['id'],'mac':'02:00:00:00:00:09','allowed':False,'at':'2026-11-26T12:00:00Z'}],'has_key':True,'has_token':True,'has_web_password':True,'backhaul_mode':1};a['features']['mesh']=True;a['ports']=[{'id':12,'uplink':True},{'id':103,'uplink':False,'lag':True},{'id':104,'uplink':False,'lag':True}];a['downlink_port_count']=2
   conf['config']['ap_profiles'][0]['options']['lag']={'enabled':True,'mode':0,'ports':[103,104]}
   a['radio_linkage']={'table_id':1,'rows':[{'table_mask':2,'feature_mask':1,'regions':[0],'radios':[{'radio_id':1,'channels':[0,1,6],'bandwidths':[0,2],'status_mask':3}]}]}
   a['radio_modes']=[{'id':7,'name':'Dual','rf_mode':16387,'radios':[1,2]}];a['radio_mode']={'enabled':False,'id':7}
   rf_defaults['edca']={'enabled':False,'mode':0,'queues':edca_queues};
   for row in conf['config']['radios']:
    if row.get('advanced') is not None:row['advanced']['edca']=copy.deepcopy(rf_defaults['edca'])
   a['edca_presets']={'version':1,'scenes':[{'id':2,'name':'Office','description':'Other AP model','bands':[{'band_id':1,'queues':[{'aifs':2,'cw_min':3,'cw_max':4,'txop':47}]*8}]}]}
   conf['config']['vlan_pools']=[{'id':1,'name':'Guests','vlans':'100-110'}]
  spare=copy.deepcopy(profile[0]);spare.update(id='02:00:00:00:00:aa',mac='02:00:00:00:00:aa',name='Fixture spare',online=True,state='RUN');offline=copy.deepcopy(spare);offline.update(id='02:00:00:00:00:ab',mac='02:00:00:00:00:ab',name='Fixture offline',online=False,state='OFFLINE');profile.extend([spare,offline])
  page=browser.new_page(viewport={'width':1440,'height':960});page.on('pageerror',lambda e:errors.append(str(e)));page.on('dialog',lambda d:d.accept())
  def route(r):
   path=r.request.url.split('/api/')[1]
   if r.request.method!='GET':writes.append({'path':path,'body':r.request.post_data_json});r.fulfill(json={'status':'saved'});return
   if path.startswith('clients/')and'/history?'in path:
    signal_queries.append(path);r.fulfill(json={'samples':[{'at':'2026-11-26T12:00:00Z','ap_id':profile[0]['id'],'radio_id':1,'wlan_id':1,'ssid':'GoAC-Lab','rssi_dbm':-60},{'at':'2026-11-26T12:00:30Z','ap_id':profile[0]['id'],'radio_id':1,'wlan_id':1,'ssid':'GoAC-Lab','rssi_dbm':-48}]});return
   value=resources if path=='controller/resources' else profile if path=='aps' else conf if path=='config' else clients if path=='clients' else [r for r in conf['config']['radios']if r['ap_id']==profile[0]['id']]if path.endswith('/effective-radios')else rf_defaults if path.startswith('radios/defaults') else rates if path=='rates' else mobility if path=='mobility' else edca if path=='edca' else rrm if path=='rrm' else upgrades if path=='upgrades' else {'config':conf['config'].get('mesh'),'jobs':{}} if path=='mesh' else {'configured_mode':2,'actual_mode':2,'mode_writable':False,'unsupported_aps':[]} if path=='mobility/status' else storm if path=='storm/defaults' else {'ap_counts':[{'at':'2026-11-26T12:00:00Z','online':1,'offline':2,'total':3},{'at':'2026-11-26T12:01:00Z','online':2,'offline':1,'total':3}],'radios':[{'at':'2026-11-26T12:00:00Z','ap_id':profile[0]['id'],'radio_id':1,'clients':1,'channel':6,'power_dbm':15,'metrics':{'channelUsage':20}},{'at':'2026-11-26T12:01:00Z','ap_id':profile[0]['id'],'radio_id':1,'clients':2,'channel':6,'power_dbm':15,'metrics':{'channelUsage':30}}],'events':[]} if path.startswith('history?') else []
   r.fulfill(json=value)
  page.route('**/api/**',route);page.goto('http://127.0.0.1:'+str(server.server_port));page.wait_for_selector('[data-ap]');assert page.locator('a[href="/api/aps/export"]').is_visible()
  for tab in ['aps','services','radios','clients','management','mobility','history','protection','upgrades','interfaces','resources']:
   page.locator('[data-tab="'+tab+'"]').click();page.wait_for_timeout(40)
  page.locator('[data-tab="resources"]').click();page.locator('[data-resource-edit]').click();page.locator('[name="max_ap_sessions"]').fill('2048');assert page.locator('#controller-resources-form input[type="number"]').count()==len(resource_values)
  page.locator('#controller-resources-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path']=='controller/resources'and writes[-1]['body']['max_ap_sessions']==2048 and writes[-1]['body']['max_policy_rules']==1024
  page.locator('[data-tab="services"]').click();page.locator('#new-service').click();page.locator('[name="ssid"]').fill('UI-Parity');page.locator('[data-editor-tab="security"]').click();page.locator('[name="passphrase"]').fill('synthetic-ui-key');assert page.locator('[name="radius_ip"]').count()==0
  for pane in ['security','binding','qos','schedule','basic']:page.locator('[data-editor-tab="'+pane+'"]').click()
  if not full:
   assert not page.locator('[name="mc_global"]').is_visible()
  else:
   page.locator('[data-editor-tab="binding"]').click();page.locator('[name="vlan_pool"]').select_option('1')
  page.locator('[data-editor-tab="binding"]').click();page.locator('[name="auto_bind_frequencies"]').select_option('256')
  page.locator('#service-form [type="submit"]').click();page.wait_for_timeout(80);assert not page.locator('#editor').evaluate('(e)=>e.open'),page.locator('#form-error').inner_text();assert writes[-1]['body']['auto_bind_frequencies']==256
  page.locator('[data-tab="radios"]').click();page.locator('[data-radio="1"]').first.click();page.wait_for_selector('#radio-form')
  original_mode=page.locator('#radio-form [name="mode"]').input_value();assert page.locator('[name="wmm"]').is_disabled();assert page.locator('[name="fragmentation"]').is_disabled()
  page.locator('[name="mode"]').select_option('1');assert page.locator('[name="wmm"]').is_enabled();page.locator('[data-editor-tab="rf-performance"]').click();page.locator('[name="wmm"]').uncheck();page.locator('[data-editor-tab="rf-basic"]').click();page.locator('[name="mode"]').select_option(original_mode);assert page.locator('[name="wmm"]').is_disabled() and page.locator('[name="wmm"]').is_checked()
  for pane in ['rf-timing','rf-performance','rf-basic']:page.locator('[data-editor-tab="'+pane+'"]').click()
  if full:
   page.locator('[data-editor-tab="rf-performance"]').click();assert page.locator('[name="dcs_mode"]').count()==1;assert page.locator('[name="edca_7_txop"]').count()==1;page.locator('[name="edca_preset"]').select_option('2')
  page.locator('#radio-form [type="submit"]').click();page.wait_for_timeout(80);assert not page.locator('#editor').evaluate('(e)=>e.open'),page.locator('#form-error').inner_text()
  page.locator('[data-band-navigation]').click();page.locator('[name="band_threshold"]').fill('22');page.locator('#band-navigation-form [type="submit"]').click();page.wait_for_timeout(80)
  assert writes[-1]['path']=='band-navigation' and writes[-1]['body']['threshold_5g']==22
  if full:
   page.locator('[data-tab="services"]').click();page.locator('[data-new-pool]').click();page.locator('[name="pool_name"]').fill('UI Pool');page.locator('[name="pool_vlans"]').fill('100-110');page.locator('#pool-form [type="submit"]').click();page.wait_for_timeout(80)
   assert writes[-1]['path']=='vlan-pools' and writes[-1]['body']['vlans']=='100-110'
  page.locator('[data-tab="radios"]').click();page.locator('[data-rrm-new]').click();page.wait_for_selector('#rrm-form');page.locator('[name="name"]').fill('UI RRM');page.locator('[name="rrm_5g_channels"]').fill('36,44,149,157');page.locator('[name="optimize_channel"]').check();page.locator('#rrm-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path']=='rrm/rules' and writes[-1]['body'][0]['name']=='UI RRM';page.locator('[data-rates]').click();page.wait_for_selector('#rates-form');page.locator('[data-editor-tab="rates-mcs"]').click();page.locator('[name="11ax_supported"]').fill('15');page.locator('#rates-form [type="submit"]').click();page.wait_for_timeout(80)
  assert writes[-1]['path']=='rates' and writes[-1]['body']['11ax']['supported']==15
  page.locator('[data-edca-new]').click();page.wait_for_selector('#edca-form');page.locator('#edca-form [name="name"]').fill('UI EDCA');page.locator('#edca-form [name="frequency_mask"]').select_option(['1','256']);page.locator('#edca-form [name="edca_0_txop"]').fill('47');page.locator('#edca-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path']=='edca/rules' and writes[-1]['body'][0]['frequency_mask']==257

  page.locator('[data-tab="mobility"]').click();page.locator('[data-mobility-kind="balance"]').click();page.wait_for_selector('#mobility-form');page.locator('[name="name"]').fill('UI Balance');page.locator('#mobility-form [type="submit"]').click();page.wait_for_timeout(80)
  assert writes[-1]['path']=='mobility' and writes[-1]['body']['balance'][0]['name']=='UI Balance'
  page.locator('[data-mobility-kind="default"]').click();page.wait_for_selector('#mobility-form');page.locator('#mobility-form [type="submit"]').click();page.wait_for_timeout(80)
  assert writes[-1]['path']=='mobility' and writes[-1]['body']['default_roaming']['2g']['rssi_trigger']==-75
  page.locator('[data-tab="protection"]').click()
  for kind in ['servers','bindings','rules']:
   page.locator('[data-defense-kind="'+kind+'"]').last.click();page.wait_for_selector('#defense-form');page.locator('#defense-form [name="name"]').fill('UI '+kind)
   if kind=='servers':page.locator('[name="address"]').fill('192.0.2.3')
   if kind=='bindings':page.locator('[name="ip"]').fill('2001:db8::3');page.locator('[name="mac"]').fill('02:03:04:05:06:08')
   if kind=='rules':page.locator('[name="dhcp"]').check();page.locator('[name="servers"]').select_option('srv');page.locator('[name="bindings"]').select_option('bind')
   page.locator('#defense-form [type="submit"]').click();page.wait_for_timeout(80);assert not page.locator('#editor').evaluate('(e)=>e.open'),page.locator('#form-error').inner_text();assert writes[-1]['path']=='protection'
  page.locator('[data-storm-edit]').click();page.wait_for_selector('#storm-form');page.locator('[name="enabled"]').check();page.locator('[name="protocol_0_rate"]').fill('200');page.locator('#storm-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path']=='storm' and writes[-1]['body']['protocols'][0]['rate']==200
  page.locator('[data-tab="upgrades"]').click();page.wait_for_selector('[data-upgrade-image]');page.locator('[data-upgrade-image]').first.click();page.wait_for_selector('#upgrade-form');page.locator('#upgrade-form input[type="checkbox"]').first.check();page.locator('#upgrade-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path']=='upgrades' and writes[-1]['body']['image_id']=='synthetic-image'
  page.locator('[data-tab="history"]').click();page.wait_for_selector('svg path[stroke-width="2"]');assert page.locator('svg[aria-label="无线运行统计趋势"]').count()==2
  page.locator('[data-tab="clients"]').click();page.locator('[data-client-history]').first.click();page.wait_for_selector('#dialog-body svg');assert page.locator('#dialog-body').get_by_text('-60 dBm',exact=True).is_visible();before_signals=len(signal_queries);page.locator('[name="client_history_duration"]').select_option('3600');page.wait_for_timeout(100);assert len(signal_queries)>before_signals and signal_queries[-1].endswith('duration=3600');page.locator('#close-dialog').click()
  page.locator('[data-tab="management"]').click()
  page.locator('[data-management-tab="mesh"]').click();page.locator('[data-mesh-config]').click();page.wait_for_selector('#mesh-form');page.locator('#mesh-form [name="enabled"]').check();page.locator('#mesh-form [name="ssid"]').fill('UI Backhaul');page.locator('#mesh-form [name="key"]').fill('MeshKey123');page.locator('#mesh-form [name="web_password"]').fill('Mesh123456');page.locator('#mesh-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path']=='mesh' and writes[-1]['body']['ssid']=='UI Backhaul'
  if full:
   page.locator('[data-mesh-ap]').first.click();page.wait_for_selector('#mesh-form');page.locator('#mesh-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path'].endswith('/mesh') and writes[-1]['body']['action']=='discover'
  page.locator('[data-management-tab="basic"]').click();page.locator('[data-group-new]').click();page.locator('[name="management_name"]').fill('UI Group');page.locator('[name="group_start_ip"]').fill('192.0.2.10');page.locator('[name="group_end_ip"]').fill('192.0.2.20');page.locator('[name="opt_echo_seconds"]').fill('25');page.locator('#management-form [type="submit"]').click();page.wait_for_timeout(80)
  assert writes[-1]['path']=='groups' and writes[-1]['body']['options']['echo_seconds']==25 and writes[-1]['body']['strategy']=={'enabled':True,'type':'ip_range','start_ip':'192.0.2.10','end_ip':'192.0.2.20'}
  page.locator('[data-template-new]').click();page.locator('[name="management_name"]').fill('UI Template');page.locator('#management-form [type="submit"]').click();page.wait_for_timeout(80)
  assert writes[-1]['path']=='templates'
  page.locator('[data-ap-defaults]').click();page.locator('[name="opt_offline_self_manage"]').select_option('on');page.locator('#management-form [type="submit"]').click();page.wait_for_timeout(80)
  assert writes[-1]['path']=='ap-defaults' and writes[-1]['body']['offline_self_manage'] is True;assert next(r for r in writes[-1]['body']['radios']if r['radio_id']==8)=={'radio_id':8,'channel':11,'advanced':{'rts':2000}}
  page.locator('[data-ap-settings]').first.click();page.locator('[name="opt_echo_seconds"]').fill('31');page.locator('[name="opt_led"]').select_option('off')
  if full:page.locator('[data-editor-tab="ap-advanced"]').click();page.locator('[name="opt_rf_mode_enabled"]').select_option('on');page.locator('[name="opt_rf_mode_id"]').select_option('7');page.locator('[name="opt_port_103_vlan"]').fill('100');assert page.locator('[name="opt_port_12_vlan"]').count()==0
  page.locator('#management-form [type="submit"]').click();page.wait_for_timeout(80)
  if full:assert writes[-1]['body']['options']['rf_mode']=={'enabled':True,'id':7};assert writes[-1]['body']['options']['lag']['ports']==[103,104]
  assert writes[-1]['path'].endswith('/settings') and writes[-1]['body']['options']['led'] is False
  assert not page.locator('#editor').evaluate('(e)=>e.open'),page.locator('#form-error').inner_text()
  for copy_radios in (False,True):
   page.locator('[data-ap-copy="'+profile[0]['id']+'"]').click();page.locator('#management-copy-form [name="targets"]').select_option(spare['id']);page.locator('#management-copy-form [name="radios"]').set_checked(copy_radios);page.locator('#management-copy-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path'].endswith('/copy') and writes[-1]['body']=={'targets':[spare['id']],'radios':copy_radios}
  page.locator('[data-ap-replace="'+offline['id']+'"]').click();page.locator('#management-replace-form [name="target"]').select_option(spare['id']);page.locator('#management-replace-form [type="submit"]').click();page.wait_for_timeout(80);assert writes[-1]['path'].endswith('/replace') and writes[-1]['body']=={'target_ap_id':spare['id']}
  restore={'format':'go-ac-configuration','schema':1,'config':{'services':[]}}
  page.locator('#management-import').set_input_files({'name':'go-ac-ui-test.json','mimeType':'application/json','buffer':json.dumps(restore).encode()});page.wait_for_timeout(100);assert writes[-1]['path']=='restore' and writes[-1]['body']==restore
  page.evaluate('window.scrollTo(0,0)');page.screenshot(path=str(OUT/('all-capabilities-desktop.png'if full else 'real-capabilities-desktop.png')),full_page=True)
  page.set_viewport_size({'width':390,'height':844});page.screenshot(path=str(OUT/('all-capabilities-mobile.png'if full else 'real-capabilities-mobile.png')),full_page=True);page.close()
 browser.close()
server.shutdown()
assert not errors,errors
assert len(writes)==48,len(writes)
assert next(w for w in reversed(writes) if w['path']=='radios')['body']['advanced']['edca']['preset']==2
print(json.dumps({'profiles':2,'pages_per_profile':11,'forms_submitted':len(writes),'javascript_errors':errors,'screenshots':str(OUT)},ensure_ascii=False))
