// func balance_sta_want_connect_wtp @ 00459d30 size=560

undefined4 balance_sta_want_connect_wtp(void *param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48 [14];
  
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_48[0xc] = 0;
  if ((param_1 == (void *)0x0) || (param_2 == 0)) {
    uVar3 = 0xffffffff;
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar2 = 0x594;
  }
  else {
    iVar1 = balance_db_config_get(local_48);
    if (iVar1 == -1) {
      uVar3 = 0xffffffff;
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: get balance\'s config failed.\r\n";
      uVar2 = 0x59b;
    }
    else if (local_48[0] == 0) {
      uVar3 = 0;
      if (g_balance_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      __format = 
      "[BALANCE_DEBUG](%32s) %05d: balance is off, then don\'t add discovery-station.\r\n";
      uVar2 = 0x5a2;
    }
    else {
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      iVar1 = balance_db_wtp_get_by_mac(param_2,&local_5c);
      if (iVar1 == 0) {
        uVar3 = 0xffffffff;
        if (g_balance_debug == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[BALANCE_DEBUG](%32s) %05d: get wtp failed.\r\n";
        uVar2 = 0x5aa;
      }
      else {
        memcpy(local_48 + 6,param_1,6);
        local_64 = local_5c;
        iVar1 = balance_db_cnt_wtp_add(local_48 + 6,&local_70);
        if (iVar1 != -1) {
          return 0;
        }
        uVar3 = 0xffffffff;
        if (g_balance_warning == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[BALANCE_WARNING](%32s) %05d: add connect-wtp failed.\r\n";
        uVar2 = 0x5b3;
      }
    }
  }
  printf(__format,"balance_sta_want_connect_wtp",uVar2);
  return uVar3;
}

