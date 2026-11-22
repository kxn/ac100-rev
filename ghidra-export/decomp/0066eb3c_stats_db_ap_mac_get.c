// func stats_db_ap_mac_get @ 0066eb3c size=276

uint stats_db_ap_mac_get(uint param_1,void *param_2)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  
  param_1 = param_1 & 0xffff;
  iVar2 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar2) {
    if (param_2 != (void *)0x0) {
      FUN_004082d0(l_stats_data,0xffffffff);
      pbVar3 = (byte *)(DAT_007cc8ec + param_1 * 0x1e0);
      bVar1 = (*pbVar3 & 2) != 0;
      if (bVar1) {
        memcpy(param_2,pbVar3 + 0x10,6);
      }
      FUN_00407f30(l_stats_data);
      return (uint)!bVar1;
    }
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_ap_mac_get",0xd9e);
      return 0xffffffff;
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","stats_db_ap_mac_get",0xd99,param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

