// func _stats_wlan_enable @ 00672d80 size=132

undefined4 _stats_wlan_enable(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = rdmngr_db_generate_ap_id();
  uVar1 = uVar1 & 0xffff;
  iVar2 = apmngr_db_get_ap_max();
  if (iVar2 <= (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max(uVar1);
    iVar3 = apmngr_db_get_template_max();
    if ((int)uVar1 < iVar2 + iVar3) {
      return 0;
    }
  }
  stats_db_ssid_active(uVar1,param_1 & 0xf,param_2);
  return 0;
}

