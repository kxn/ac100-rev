// func _stats_sta_assoc_cb @ 00672eac size=152

undefined4 _stats_sta_assoc_cb(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d inputs error.\n","_stats_sta_assoc_cb",0x46);
    }
  }
  else {
    memcpy(&local_18,(void *)(param_1 + 0x68),6);
    local_14 = CONCAT22(local_14._0_2_,(short)*(undefined4 *)(param_1 + 0x20));
    local_10 = *(undefined2 *)(param_1 + 0x24);
    uVar1 = 0;
    stats_db_sta_update_cnt_target(&local_18);
  }
  return uVar1;
}

