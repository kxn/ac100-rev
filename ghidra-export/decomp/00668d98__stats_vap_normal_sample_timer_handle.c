// func _stats_vap_normal_sample_timer_handle @ 00668d98 size=132

void _stats_vap_normal_sample_timer_handle(void)

{
  int iVar1;
  
  iVar1 = normal_sample_timer_handle(3);
  if (iVar1 != -1) {
    DAT_007cc90c = iVar1;
    apmngr_db_foreach_proc(0xff7fffff,_stats_db_ap_vap_stat_sample,&DAT_007cc960);
    FUN_00668d10(3);
    return;
  }
  if (stats_err_switch == '\0') {
    return;
  }
  printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","_stats_vap_normal_sample_timer_handle"
         ,0x46b);
  return;
}

