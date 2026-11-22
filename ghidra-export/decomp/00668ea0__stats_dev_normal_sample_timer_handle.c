// func _stats_dev_normal_sample_timer_handle @ 00668ea0 size=132

void _stats_dev_normal_sample_timer_handle(void)

{
  int iVar1;
  
  iVar1 = normal_sample_timer_handle(1);
  if (iVar1 != -1) {
    DAT_007cc904 = iVar1;
    apmngr_db_foreach_proc(0xff7fffff,_stats_db_ap_dev_stat_sample,&DAT_007cc950);
    FUN_00668d10(1);
    return;
  }
  if (stats_err_switch == '\0') {
    return;
  }
  printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","_stats_dev_normal_sample_timer_handle"
         ,0x47b);
  return;
}

