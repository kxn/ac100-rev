// func _stats_sta_deassoc_cb @ 00672f44 size=96

undefined4 _stats_sta_deassoc_cb(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d inputs error.\n","_stats_sta_deassoc_cb",0x57);
    }
  }
  else {
    uVar1 = 0;
    stats_db_sta_start_del_timer_by_mac(param_1 + 0x68);
  }
  return uVar1;
}

