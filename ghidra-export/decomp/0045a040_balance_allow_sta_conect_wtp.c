// func balance_allow_sta_conect_wtp @ 0045a040 size=388

undefined4 balance_allow_sta_conect_wtp(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar3 = 0xffffffff;
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar2 = 0x5d0;
  }
  else {
    iVar1 = balance_db_config_get(&local_28);
    if (iVar1 == -1) {
      uVar3 = 0xffffffff;
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: get balance config failed.\r\n";
      uVar2 = 0x5d7;
    }
    else {
      if (local_28 != 0) {
        if (local_24 == 1) {
          uVar3 = balance_sta_connect_wtp_by_session(param_1,param_2);
          return uVar3;
        }
        if (g_balance_debug == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        printf("[BALANCE_DEBUG](%32s) %05d: balance mode(%d) doesn\'t support.\r\n",
               "balance_allow_sta_conect_wtp",0x5ec,local_24);
        return 0;
      }
      uVar3 = 0;
      if (g_balance_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      __format = "[BALANCE_DEBUG](%32s) %05d: state of balance is off.\r\n";
      uVar2 = 0x5de;
    }
  }
  printf(__format,"balance_allow_sta_conect_wtp",uVar2);
  return uVar3;
}

