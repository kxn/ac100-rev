// func balance_db_cnt_wtp_set @ 0045e2d4 size=1

undefined4 balance_db_cnt_wtp_set(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0xffffffff;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_db_cnt_wtp_set",0x759);
    }
  }
  else {
    FUN_004082d0(balance_db_mutex,0xffffffff);
    iVar1 = balance_cnt_wtp_entry_update(param_1,param_2);
    if (iVar1 == -1) {
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: update connect-wtp(%d) failed.\r\n",
               "balance_db_cnt_wtp_set",0x762,*(undefined4 *)(param_2 + 0xc));
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(balance_db_mutex);
    }
    else {
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: set connect-wtp(%d) successed.\r\n",
               "balance_db_cnt_wtp_set",0x766,*(undefined4 *)(param_2 + 0xc));
      }
      uVar2 = 0;
      FUN_00407f30(balance_db_mutex);
    }
  }
  return uVar2;
}

