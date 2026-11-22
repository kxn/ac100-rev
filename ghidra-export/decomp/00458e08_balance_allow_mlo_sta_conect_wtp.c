// func balance_allow_mlo_sta_conect_wtp @ 00458e08 size=536

undefined4 balance_allow_mlo_sta_conect_wtp(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((param_1 == (byte *)0x0) || (param_2 == 0)) {
    uVar4 = 0xffffffff;
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar3 = 0x2cc;
  }
  else {
    iVar1 = balance_db_config_get(&local_40);
    if (iVar1 == -1) {
      uVar4 = 0xffffffff;
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: get balance config failed.\r\n";
      uVar3 = 0x2d3;
    }
    else {
      if (local_40 != 0) {
        iVar1 = 0;
        if (local_3c == 1) {
          uVar4 = 0;
          while (iVar1 < (int)(uint)*param_1) {
            iVar2 = memcmp(param_1 + iVar1 * 6 + 7,param_1 + 1,6);
            if (iVar2 == 0) {
              iVar1 = iVar1 + 1;
            }
            else {
              iVar2 = balance_sta_connect_wtp_by_session(param_1 + iVar1 * 6 + 7,param_2);
              iVar1 = iVar1 + 1;
              if (iVar2 != 0) {
                uVar4 = 0xffffffff;
              }
            }
          }
          iVar1 = balance_sta_connect_wtp_by_session(param_1 + 1,param_2);
          if (iVar1 != 0) {
            return 0xffffffff;
          }
          return uVar4;
        }
        if (g_balance_warning == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        printf("[BALANCE_WARNING](%32s) %05d: balance mode(%d) doesn\'t support.\r\n",
               "balance_allow_mlo_sta_conect_wtp",0x2f6,local_3c);
        return 0;
      }
      uVar4 = 0;
      if (g_balance_warning == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      __format = "[BALANCE_WARNING](%32s) %05d: state of balance is off.\r\n";
      uVar3 = 0x2da;
    }
  }
  printf(__format,"balance_allow_mlo_sta_conect_wtp",uVar3);
  return uVar4;
}

