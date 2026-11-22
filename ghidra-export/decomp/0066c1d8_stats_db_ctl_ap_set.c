// func stats_db_ctl_ap_set @ 0066c1d8 size=96

undefined4 stats_db_ctl_ap_set(undefined1 param_1,undefined2 param_2)

{
  FUN_004082d0(l_stats_data,0xffffffff);
  DAT_00758cf6 = param_1;
  PTR_DAT_00758cfc._0_2_ = param_2;
  FUN_00407f30(l_stats_data);
  return 0;
}

