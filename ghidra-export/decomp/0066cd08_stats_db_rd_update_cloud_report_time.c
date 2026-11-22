// func stats_db_rd_update_cloud_report_time @ 0066cd08 size=324

undefined4
stats_db_rd_update_cloud_report_time
          (uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((((int)param_1 < iVar1) && (0 < (int)param_2)) &&
     (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = *(int *)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + (param_2 - 1) * 8 + 4);
    uVar3 = 0xffffffff;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x44) = param_4;
      *(undefined4 *)(iVar1 + 0x40) = param_3;
      uVar3 = 0;
      if (stats_debug_switch != '\0') {
        printf("[STATISTICS_DEBUG]%s()/%d radio->cloud_report_last_time:%llu\n",
               "stats_db_rd_update_cloud_report_time",0x977);
      }
    }
    FUN_00407f30(l_stats_data);
  }
  else {
    uVar3 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n",
             "stats_db_rd_update_cloud_report_time",0x96d,param_1,param_2);
    }
  }
  return uVar3;
}

