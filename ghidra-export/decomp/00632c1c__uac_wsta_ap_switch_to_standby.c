// func _uac_wsta_ap_switch_to_standby @ 00632c1c size=348

undefined4 _uac_wsta_ap_switch_to_standby(uint param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if (iVar1 <= (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((int)param_1 < iVar1 + iVar2) {
      return 0;
    }
  }
  if ((49999 < param_1) && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000)) {
    return 0;
  }
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_ap_switch_to_standby() begin.\r\n",
           "_uac_wsta_ap_switch_to_standby",0x51b);
  }
  iVar1 = uac_wstation_free_all_sta_in_ap(param_1,0);
  if (iVar1 == 0) {
    uVar4 = 0;
    if (g_wsta_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wsta>[debug]%s(): %d  -> _uac_wsta_ap_switch_to_standby() success.\r\n";
    uVar3 = 0x522;
  }
  else {
    uVar4 = 0xffffffff;
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> _uac_wsta_ap_switch_to_standby() fail\r\n";
    uVar3 = 0x51f;
  }
  printf(__format,"_uac_wsta_ap_switch_to_standby",uVar3);
  return uVar4;
}

