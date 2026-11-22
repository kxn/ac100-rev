// func stats_db_ctl_ap_dsi_set @ 0066c3f4 size=136

undefined4 stats_db_ctl_ap_dsi_set(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 < 1) || (param_1 < (int)(uint)PTR_DAT_00758cfc._0_2_)) ||
     (ap_normal_sample_interval <= param_1)) {
    uVar1 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d interval error.\n","stats_db_ctl_ap_dsi_set",0x825);
    }
  }
  else {
    uVar1 = 0;
    ap_dense_sample_interval = param_1;
  }
  return uVar1;
}

