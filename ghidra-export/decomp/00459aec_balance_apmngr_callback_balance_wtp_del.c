// func balance_apmngr_callback_balance_wtp_del @ 00459aec size=320

undefined4 balance_apmngr_callback_balance_wtp_del(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0xffffffff;
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar2 = 0x284;
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    uVar3 = 0;
    if (g_balance_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[BALANCE_DEBUG](%32s) %05d: wtp is template, don\'t delete it.\r\n";
    uVar2 = 0x28b;
  }
  else {
    iVar1 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10));
    if (iVar1 == 0) {
      uVar3 = 0;
      if (g_balance_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      __format = "[BALANCE_DEBUG](%32s) %05d: ap isn\'t master link.\r\n";
      uVar2 = 0x292;
    }
    else {
      iVar1 = balance_wtp_disconnect_ac(param_1 + 0x48);
      if (iVar1 != -1) {
        return 0;
      }
      uVar3 = 0xffffffff;
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: delete wtp failed.\r\n";
      uVar2 = 0x299;
    }
  }
  printf(__format,"balance_apmngr_callback_balance_wtp_del",uVar2);
  return uVar3;
}

