// func uac_wstation_rd_disable @ 00633e40 size=8

undefined4 uac_wstation_rd_disable(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_rd_disable() begin.\r\n","_uac_wsta_rd_disable",
           0x4ed);
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
  iVar1 = uac_wstation_free_all_sta_in_radio(iVar1,param_1 & 0xf,0);
  if (iVar1 == 0) {
    uVar5 = 0;
    if (g_wsta_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wsta>[debug]%s(): %d  -> _uac_wsta_rd_disable() success.\r\n";
    uVar4 = 0x4fa;
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
    __format = "<wsta>[warning]%s(): %d  -> uac_wstation_free_all_sta_in_radio() fail\r\n";
    uVar4 = 0x4f7;
  }
  printf(__format,"_uac_wsta_rd_disable",uVar4);
  return uVar5;
}

