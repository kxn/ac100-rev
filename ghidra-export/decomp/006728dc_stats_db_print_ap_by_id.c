// func stats_db_print_ap_by_id @ 006728dc size=1

void stats_db_print_ap_by_id(undefined2 param_1,undefined4 param_2)

{
  FUN_004082d0(l_stats_data,0xffffffff);
  _stats_db_print_ap_by_id(param_1,param_2);
  uac_mutex_give(l_stats_data);
  return;
}

