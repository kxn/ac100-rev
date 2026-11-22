// func balance_roam_strategy_get @ 00457f90 size=156

undefined4 balance_roam_strategy_get(undefined4 param_1)

{
  int iVar1;
  int local_20 [6];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = balance_db_config_get(local_20);
  if (iVar1 == 0) {
    if (local_20[0] == 1) {
      param_1 = 1;
    }
  }
  else if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[BALANCE_ERROR](%32s) %05d: balance_db_config_get failed.\r\n",
           "balance_roam_strategy_get",0x4b3);
  }
  return param_1;
}

