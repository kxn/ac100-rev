// func balance_wtp_disconnect_ac @ 004599a0 size=332

undefined4 balance_wtp_disconnect_ac(byte *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (param_1 == (byte *)0x0) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: input error.\r\n";
    uVar2 = 0x547;
  }
  else {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    memcpy(&local_20,param_1,6);
    iVar1 = balance_db_wtp_delete(&local_28);
    if (iVar1 != -1) {
      if (g_balance_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("[BALANCE_DEBUG](%32s) %05d: delete wtp(%02x:%02x:%02x:%02x:%02x:%02x) successed\r\n",
             "balance_wtp_disconnect_ac",0x554,(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
             (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
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
    uVar2 = 0x551;
  }
  printf(__format,"balance_wtp_disconnect_ac",uVar2);
  return 0xffffffff;
}

