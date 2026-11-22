// func stats_db_ap_mac_get_ignore_status @ 0066ec50 size=264

uint stats_db_ap_mac_get_ignore_status(uint param_1,void *param_2)

{
  int iVar1;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    if (param_2 != (void *)0x0) {
      FUN_004082d0(l_stats_data,0xffffffff);
      iVar1 = DAT_007cc8ec + param_1 * 0x1e0;
      if (iVar1 != 0) {
        memcpy(param_2,(void *)(iVar1 + 0x10),6);
      }
      FUN_00407f30(l_stats_data);
      return (uint)(iVar1 == 0);
    }
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_ap_mac_get_ignore_status",0xdbd);
      return 0xffffffff;
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","stats_db_ap_mac_get_ignore_status",0xdb8
           ,param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

