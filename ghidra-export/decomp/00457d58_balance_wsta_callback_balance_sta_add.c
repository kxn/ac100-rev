// func balance_wsta_callback_balance_sta_add @ 00457d58 size=284

undefined4 balance_wsta_callback_balance_sta_add(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_2e8 [72];
  undefined1 auStack_2a0 [660];
  
  memset(auStack_2e8,0,0x2d8);
  if (param_1 == 0) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar2 = 0x35f;
  }
  else {
    iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_2e8);
    if (iVar1 == -1) {
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: get apentry by id failed.\r\n";
      uVar2 = 0x366;
    }
    else {
      iVar1 = balance_db_sta_add(param_1 + 0x68,auStack_2a0);
      if (iVar1 != -1) {
        return 0;
      }
      if (g_balance_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[BALANCE_ERROR](%32s) %05d: add station failed.\r\n";
      uVar2 = 0x36d;
    }
  }
  printf(__format,"balance_wsta_callback_balance_sta_add",uVar2);
  return 0xffffffff;
}

