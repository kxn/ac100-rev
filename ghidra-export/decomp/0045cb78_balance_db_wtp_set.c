// func balance_db_wtp_set @ 0045cb78 size=1

undefined4 balance_db_wtp_set(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_db_wtp_set",0x563);
    return 0xffffffff;
  }
  FUN_004082d0(balance_db_mutex,0xffffffff);
  iVar1 = memcmp((void *)(param_1 + 8),(void *)(param_2 + 8),6);
  if (iVar1 == 0) {
    iVar1 = balance_wtp_entry_update(param_2);
    if (iVar1 != -1) {
      if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)) {
        printf("[BALANCE_DEBUG](%32s) %05d: update wtp(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
               ,"balance_db_wtp_set",0x579,(uint)*(byte *)(param_2 + 8),(uint)*(byte *)(param_2 + 9)
               ,(uint)*(byte *)(param_2 + 10),(uint)*(byte *)(param_2 + 0xb),
               (uint)*(byte *)(param_2 + 0xc),(uint)*(byte *)(param_2 + 0xd));
      }
      FUN_00407f30(balance_db_mutex);
      return 0;
    }
    if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
    goto code_r0x0045ccb8;
    __format = "[BALANCE_ERROR](%32s) %05d: update wtp failed.\r\n";
    uVar2 = 0x575;
  }
  else {
    if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
    goto code_r0x0045ccb8;
    __format = "[BALANCE_ERROR](%32s) %05d: old wtp doesn\'t match new wtp.\r\n";
    uVar2 = 0x56d;
  }
  printf(__format,"balance_db_wtp_set",uVar2);
code_r0x0045ccb8:
  FUN_00407f30(balance_db_mutex);
  return 0xffffffff;
}

