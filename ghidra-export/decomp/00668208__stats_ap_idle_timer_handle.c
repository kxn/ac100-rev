// func _stats_ap_idle_timer_handle @ 00668208 size=212

void _stats_ap_idle_timer_handle(void)

{
  int iVar1;
  
  if (stats_debug_switch != '\0') {
    printf("[STATISTICS_DEBUG]%s()/%d stats sta idle time start\n","_stats_ap_idle_timer_handle",
           0x1f0);
  }
  apmngr_db_foreach_proc(0xff7fffff,_stats_db_ap_stat_idle_clear,0);
  iVar1 = FUN_00408340(0x3c,0,_stats_ap_idle_timer_handle,0,0,"_stats_ap_idle_timer_handle",0x1f5);
  if ((iVar1 == -1) && (stats_err_switch != '\0')) {
    printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","_stats_ap_idle_timer_handle",0x1f8);
  }
  DAT_007cc8fc = iVar1;
  return;
}

