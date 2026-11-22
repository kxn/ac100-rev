// func stats_db_sta_update_ac_report_time @ 0066cc1c size=236

undefined4
stats_db_sta_update_ac_report_time
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d invalid para\n","stats_db_sta_update_ac_report_time",0x951);
    }
  }
  else {
    FUN_004082d0(l_stats_data,0xffffffff);
    uVar2 = 0xffffffff;
    iVar1 = FUN_00407fa0(DAT_007cc8e0,param_1);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x4c) = param_4;
      *(undefined4 *)(iVar1 + 0x48) = param_3;
      uVar2 = 0;
      if (stats_debug_switch != '\0') {
        printf("[STATISTICS_DEBUG]%s()/%d wsta_entry->cloud_report_last_time:%llu\n",
               "stats_db_sta_update_ac_report_time",0x95b);
      }
    }
    FUN_00407f30(l_stats_data);
  }
  return uVar2;
}

