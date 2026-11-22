// func wsta_db_sta_update_rssi @ 00638934 size=348

undefined4 wsta_db_sta_update_rssi(char *param_1,char param_2)

{
  int iVar1;
  undefined4 extraout_v1;
  
  if (((((*param_1 == '\0') && (param_1[1] == '\0')) && (param_1[2] == '\0')) &&
      ((param_1[3] == '\0' && (param_1[4] == '\0')))) && (param_1[5] == '\0')) {
    if (g_wsta_warning != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("<wsta>[warning]%s(): %d  -> invalid mac addr!\r\n","wsta_db_sta_update_rssi",0x8eb);
      return 0xffffffff;
    }
  }
  else {
    if (((int)param_2 + 0x5fU & 0xff) < 0x5f) {
      FUN_00407e70();
      FUN_004082d0(DAT_007cc6bc,0xffffffff);
      iVar1 = FUN_00407fa0(DAT_007cc6cc,param_1);
      if (iVar1 != 0) {
        *(char *)(iVar1 + 0x35) = param_2;
        *(undefined4 *)(iVar1 + 0x38) = extraout_v1;
      }
      FUN_00407f30(DAT_007cc6bc);
      return 0;
    }
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> invalid rssi[%d]!\r\n","wsta_db_sta_update_rssi",0x8f1,
             (int)param_2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

