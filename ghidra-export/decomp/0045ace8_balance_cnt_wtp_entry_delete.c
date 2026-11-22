// func balance_cnt_wtp_entry_delete @ 0045ace8 size=124

undefined4 balance_cnt_wtp_entry_delete(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_cnt_wtp_entry_delete",0x204);
    }
  }
  else {
    FUN_00408500();
    uVar2 = 0;
    FUN_00407df0(param_1);
  }
  return uVar2;
}

