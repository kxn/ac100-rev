// func _uac_wsta_wlan_disable @ 00632904 size=380

undefined4 _uac_wsta_wlan_disable(uint param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_wlan_disable() begin.\r\n","_uac_wsta_wlan_disable",
           0x503);
  }
  iVar1 = rdmngr_db_generate_ap_id(param_1);
  iVar2 = apmngr_db_get_ap_max();
  if (iVar2 <= iVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if (iVar1 < iVar2 + iVar3) {
      return 0;
    }
  }
  if ((49999 < iVar1) && (iVar2 = apmngr_db_get_sensor_max(), iVar1 < iVar2 + 50000)) {
    return 0;
  }
  iVar1 = uac_wstation_free_all_sta_in_wlan(iVar1,param_1 & 0xf,param_2,0);
  if (iVar1 == 0) {
    uVar5 = 0;
    if (g_wsta_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wsta>[debug]%s(): %d  -> _uac_wsta_wlan_disable() success.\r\n";
    uVar4 = 0x510;
  }
  else {
    uVar5 = 0xffffffff;
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> uac_wstation_free_all_sta_in_wlan() fail\r\n";
    uVar4 = 0x50d;
  }
  printf(__format,"_uac_wsta_wlan_disable",uVar4);
  return uVar5;
}

