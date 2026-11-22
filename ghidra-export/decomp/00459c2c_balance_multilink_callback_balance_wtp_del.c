// func balance_multilink_callback_balance_wtp_del @ 00459c2c size=244

undefined4 balance_multilink_callback_balance_wtp_del(undefined2 param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_2e8 [72];
  undefined1 auStack_2a0 [660];
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: get ap entry by id failed.\r\n";
    uVar2 = 0x482;
  }
  else {
    iVar1 = balance_wtp_disconnect_ac(auStack_2a0);
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
    __format = "[BALANCE_ERROR](%32s) %05d: delete wtp failed.\r\n";
    uVar2 = 0x489;
  }
  printf(__format,"balance_multilink_callback_balance_wtp_del",uVar2);
  return 0xffffffff;
}

