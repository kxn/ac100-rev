// func stats_db_ap_update_cloud_report_time @ 0066cfcc size=268

undefined4
stats_db_ap_update_cloud_report_time
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = DAT_007cc8ec + param_1 * 0x1e0;
    uVar2 = 0xffffffff;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x5c) = param_4;
      *(undefined4 *)(iVar1 + 0x58) = param_3;
      uVar2 = 0;
      if (stats_debug_switch != '\0') {
        printf("[STATISTICS_DEBUG]%s()/%d ap_entry->global.cloud_report_last_time:%llu\n",
               "stats_db_ap_update_cloud_report_time",0x9ab);
      }
    }
    FUN_00407f30(l_stats_data);
  }
  else {
    uVar2 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","stats_db_ap_update_cloud_report_time",
             0x9a2,param_1);
    }
  }
  return uVar2;
}

