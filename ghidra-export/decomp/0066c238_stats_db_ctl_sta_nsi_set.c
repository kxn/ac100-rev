// func stats_db_ctl_sta_nsi_set @ 0066c238 size=136

undefined4 stats_db_ctl_sta_nsi_set(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 < 1) || (param_1 < (int)(uint)DAT_00758cf8)) ||
     (param_1 <= sta_dense_sample_interval)) {
    uVar1 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d interval error.\n","stats_db_ctl_sta_nsi_set",0x7e8);
    }
  }
  else {
    uVar1 = 0;
    sta_normal_sample_interval = param_1;
  }
  return uVar1;
}

