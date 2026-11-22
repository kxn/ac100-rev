// func stats_db_ctl_sta_set @ 0066c178 size=96

undefined4 stats_db_ctl_sta_set(undefined1 param_1,undefined2 param_2)

{
  FUN_004082d0(l_stats_data,0xffffffff);
  stats_ctl = param_1;
  DAT_00758cf8 = param_2;
  FUN_00407f30(l_stats_data);
  return 0;
}

