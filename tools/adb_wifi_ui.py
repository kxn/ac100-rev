"""ADB Wi-Fi settings helpers scoped to the requested lab SSID.
Never alter other saved networks. UI coordinates come from fresh XML bounds.
"""
import re,shlex,subprocess,time,xml.etree.ElementTree as ET
class WiFiUI:
 def __init__(self,serial):self.serial=serial
 def shell(self,*words):
  p=subprocess.run(['adb','-s',self.serial,'shell',shlex.join(words)],capture_output=True,text=True,timeout=35)
  if p.returncode:raise RuntimeError(p.stderr or p.stdout)
  return p.stdout
 def nodes(self):
  self.shell('uiautomator','dump','--compressed','/sdcard/goac-ui.xml')
  return list(ET.fromstring(self.shell('cat','/sdcard/goac-ui.xml')).iter('node'))
 def tap(self,node):
  x1,y1,x2,y2=map(int,re.findall(r'\d+',node.get('bounds','')));self.shell('input','tap',str((x1+x2)//2),str((y1+y2)//2))
 def is_connected(self,ssid):
  s=self.shell('cmd','wifi','status');ip=re.search(r'IP: /([0-9.]+)',s)
  return f'SSID: "{ssid}"'in s and 'Supplicant state: COMPLETED'in s and ip is not None and 'inet '+ip[1]+'/'in self.shell('ip','-4','addr','show','dev','wlan0')
 def saved_network_ids(self,ssid):
  ids=set()
  for line in self.shell('cmd','wifi','list-networks').splitlines():
   m=re.match(r'^\s*(\d+)\s+(.*?)\s{2,}\S+\s*$',line)
   if m and m[2]==ssid:ids.add(int(m[1]))
  return ids
 def connect(self,ssid,password=None):
  if not ssid.startswith('GoAC-'):raise RuntimeError('Only lab SSIDs are allowed')
  self.shell('am','start','-a','android.settings.WIFI_SETTINGS');time.sleep(1)
  for attempt in range(12):
   if self.is_connected(ssid):return
   nodes=self.nodes();passwords=[n for n in nodes if n.get('class')=='android.widget.EditText'and 'password'in n.get('resource-id','').lower()]
   if passwords:
    if password is None:raise RuntimeError('Unexpected password prompt for open lab network')
    self.tap(passwords[0]);self.shell('input','keyevent','123',*(['67']*128));self.shell('input','text',password)
    for n in self.nodes():
     if (n.get('text')or n.get('content-desc'))in ('连接','连接网络','Connect','确定','完成')and n.get('enabled')=='true':self.tap(n);break
   else:
    target=next((n for n in nodes if n.get('text')==ssid),None)
    if target is not None:self.tap(target)
    else:
     refresh=next((n for n in nodes if n.get('resource-id')=='com.android.settings:id/refresh_text'),None)
     if refresh is not None:self.tap(refresh)
     self.shell('input','swipe','1800','650','1800','1500','300')
   time.sleep(2)
  raise RuntimeError('Could not join requested lab SSID via Settings; '+self.shell('cmd','wifi','status').splitlines()[3])
 def forget(self,ssid):
  if not ssid.startswith('GoAC-')or ssid=='GoAC-Lab':raise RuntimeError('Refusing to forget the baseline or a non-lab network')
  try:
   for network in self.saved_network_ids(ssid):self.shell('cmd','wifi','forget-network',str(network))
   if not self.saved_network_ids(ssid):return True
  except RuntimeError:pass
  self.shell('am','start','-a','android.settings.WIFI_SETTINGS');time.sleep(1)
  target=next((n for n in self.nodes()if n.get('content-desc')==ssid+' 网络详情'),None)
  if target is None:return False
  self.tap(target)
  for _ in range(7):
   target=next((n for n in self.nodes()if n.get('text')in ('删除网络','忘记网络','删除此网络','Forget')),None)
   if target is not None:
    self.tap(target)
    for n in self.nodes():
     if n.get('text')in ('删除网络','忘记网络','删除','确定','Forget')and n.get('clickable')=='true':self.tap(n);break
    return True
   self.shell('input','swipe','1800','1550','1800','600','300')
  self.shell('input','keyevent','4');return False
 def add_hidden(self,ssid,password,activate=None):
  if not ssid.startswith('GoAC-'):raise RuntimeError('Only lab SSIDs are allowed')
  self.shell('input','keyevent','4');self.shell('input','keyevent','4');self.shell('am','start','-a','android.settings.WIFI_SETTINGS')
  for _ in range(8):
   target=next((n for n in self.nodes()if any(s in n.get('text','')for s in ('添加网络','手动添加','添加其他网络'))),None)
   if target is not None:self.tap(target);break
   self.shell('input','swipe','1800','1550','1800','600','300')
  else:raise RuntimeError('Add-network action unavailable')
  target=next(n for n in self.nodes()if n.get('resource-id')=='com.android.settings:id/ssid');self.tap(target);self.shell('input','text',ssid)
  self.tap(next(n for n in self.nodes()if n.get('text')=='无'))
  self.tap(next(n for n in self.nodes()if n.get('text')=='WPA/WPA2-Personal'))
  nodes=self.nodes();target=next(n for n in nodes if n.get('class')=='android.widget.EditText'and 'password'in n.get('resource-id','').lower());self.tap(target);self.shell('input','text',password)
  nodes=self.nodes()
  if not any(n.get('text')=='是'for n in nodes):raise RuntimeError('Hidden-network setting is not enabled')
  self.tap(next(n for n in nodes if n.get('resource-id')=='android:id/button2'and n.get('enabled')=='true'))
  if activate is not None:activate()
  self.shell('cmd','wifi','set-wifi-enabled','disabled');time.sleep(2);self.shell('cmd','wifi','set-wifi-enabled','enabled')
  end=time.monotonic()+75
  while time.monotonic()<end:
   if self.is_connected(ssid):return
   time.sleep(1)
  raise RuntimeError('Hidden lab network association failed')
