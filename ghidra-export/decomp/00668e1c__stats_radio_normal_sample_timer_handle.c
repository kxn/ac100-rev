// func _stats_radio_normal_sample_timer_handle @ 00668e1c size=132

void _stats_radio_normal_sample_timer_handle(void)

{
  int iVar1;
  
  iVar1 = normal_sample_timer_handle(2);
  if (iVar1 != -1) {
    DAT_007cc908 = iVar1;
    apmngr_db_foreach_proc(0xff7fffff,_stats_db_ap_radio_stat_sample,&DAT_007cc958);
    FUN_00668d10(2);
    return;
  }
  if (stats_err_switch == '\0') {
    return;
  }
  printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n",
         "_stats_radio_normal_sample_timer_handle",0x45b);
  return;
}

