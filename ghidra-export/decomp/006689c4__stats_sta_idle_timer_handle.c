// func _stats_sta_idle_timer_handle @ 006689c4 size=252

void _stats_sta_idle_timer_handle(void)

{
  int iVar1;
  undefined4 extraout_v1;
  undefined4 local_18 [2];
  
  FUN_00407e70();
  local_18[0] = extraout_v1;
  if (stats_debug_switch != '\0') {
    printf("[STATISTICS_DEBUG]%s()/%d stats sta idle time start\n","_stats_sta_idle_timer_handle",
           0x1dc);
  }
  FUN_004082d0(l_stats_data,0xffffffff);
  FUN_00408570(DAT_007cc8e0,_stats_sta_idle_entry_delete,local_18);
  FUN_00407f30(l_stats_data);
  iVar1 = FUN_00408340(0x3c,0,_stats_sta_idle_timer_handle,0,0,"_stats_sta_idle_timer_handle",0x1e3)
  ;
  if ((iVar1 == -1) && (stats_err_switch != '\0')) {
    printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","_stats_sta_idle_timer_handle",0x1e6)
    ;
  }
  DAT_007cc8e8 = iVar1;
  return;
}

