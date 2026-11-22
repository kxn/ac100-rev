// func _stats_wlan_disable @ 00672e04 size=168

undefined4 _stats_wlan_disable(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = rdmngr_db_generate_ap_id();
  uVar1 = uVar1 & 0xffff;
  iVar2 = uac_wservice_is_wlanid_bind(uVar1,param_1 & 0xf,param_2);
  iVar3 = apmngr_db_get_ap_max();
  if (iVar3 <= (int)uVar1) {
    iVar3 = apmngr_db_get_ap_max(uVar1);
    iVar4 = apmngr_db_get_template_max();
    if ((int)uVar1 < iVar3 + iVar4) {
      return 0;
    }
  }
  stats_db_ssid_reset(uVar1,param_1 & 0xf,param_2,iVar2 == 0);
  return 0;
}

