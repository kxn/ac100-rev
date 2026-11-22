// func balance_capwap_callback_cfg_status_request_listen @ 00458cb4 size=340

undefined4 balance_capwap_callback_cfg_status_request_listen(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int local_20 [6];
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar2 = 0x407;
  }
  else {
    local_20[0] = 0;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    local_20[4] = 0;
    local_20[5] = 0;
    iVar1 = balance_db_config_get(local_20);
    if (iVar1 == -1) {
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: get balance config failed.\r\n";
      uVar2 = 0x411;
    }
    else {
      iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_3,0x26);
      if (iVar1 != 0) {
        if (local_20[0] != 1) {
          *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xfffffffe;
          return 0;
        }
        *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 1;
        return 0;
      }
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: get message of msg sw failed.\r\n";
      uVar2 = 0x416;
    }
  }
  printf(__format,"balance_capwap_callback_cfg_status_request_listen",uVar2);
  return 0xffffffff;
}

