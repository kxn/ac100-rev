// func stats_db_ap_global_get @ 0066ee10 size=296

undefined4 stats_db_ap_global_get(uint param_1,void *param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    if (param_2 != (void *)0x0) {
      FUN_004082d0(l_stats_data,0xffffffff);
      pbVar2 = (byte *)(DAT_007cc8ec + param_1 * 0x1e0);
      if (((*pbVar2 & 2) != 0) || (uVar3 = 1, param_3 == 1)) {
        memcpy(param_2,pbVar2 + 0x18,0x1c0);
        uVar3 = 0;
      }
      FUN_00407f30(l_stats_data);
      return uVar3;
    }
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_ap_global_get",0xdfb);
      return 0xffffffff;
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","stats_db_ap_global_get",0xdf6,param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

