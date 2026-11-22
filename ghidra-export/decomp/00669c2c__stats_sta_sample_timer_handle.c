// func _stats_sta_sample_timer_handle @ 00669c2c size=184

void _stats_sta_sample_timer_handle(void)

{
  int iVar1;
  
  iVar1 = normal_sample_timer_handle(0);
  if (iVar1 != -1) {
    DAT_007cc900 = iVar1;
    FUN_004082d0(l_stats_data,0xffffffff);
    FUN_00408570(DAT_007cc8e0,_stats_sta_sample_handle,&g_sta_cur_time);
    FUN_00407f30(l_stats_data);
    FUN_00668d10(0);
    return;
  }
  if (stats_err_switch == '\0') {
    return;
  }
  printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","_stats_sta_sample_timer_handle",0x28c)
  ;
  return;
}

