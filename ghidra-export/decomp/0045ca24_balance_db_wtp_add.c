// func balance_db_wtp_add @ 0045ca24 size=340

undefined4 balance_db_wtp_add(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error\r\n","balance_db_wtp_add",0x53c);
    }
  }
  else {
    FUN_004082d0(balance_db_mutex,0xffffffff);
    iVar1 = balance_wtp_entry_update(param_1);
    if (iVar1 == -1) {
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: update wtp failed.\r\n","balance_db_wtp_add",0x546);
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(balance_db_mutex);
    }
    else {
      if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)) {
        printf("[BALANCE_DEBUG](%32s) %05d: add wtp(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n",
               "balance_db_wtp_add",0x54a,(uint)*(byte *)(param_1 + 8),(uint)*(byte *)(param_1 + 9),
               (uint)*(byte *)(param_1 + 10),(uint)*(byte *)(param_1 + 0xb),
               (uint)*(byte *)(param_1 + 0xc),(uint)*(byte *)(param_1 + 0xd));
      }
      uVar2 = 0;
      FUN_00407f30(balance_db_mutex);
    }
  }
  return uVar2;
}

