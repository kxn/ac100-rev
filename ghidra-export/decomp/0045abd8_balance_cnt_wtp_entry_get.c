// func balance_cnt_wtp_entry_get @ 0045abd8 size=272

int balance_cnt_wtp_entry_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
    if ((g_balance_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: input error.\r\n","balance_cnt_wtp_entry_get",0x1e0);
    }
  }
  else {
    for (iVar1 = FUN_004081b0(param_1 + 0x10); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      if (*(int *)(iVar1 + 0xc) == param_2) {
        if (g_balance_debug == 0) {
          return iVar1;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return iVar1;
        }
        __format = "[BALANCE_DEBUG](%32s) %05d: get connect-wtp(%d) successed.\r\n";
        uVar3 = 0x1ea;
        goto LAB_0045acd8;
      }
    }
    if ((g_balance_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      __format = "[BALANCE_DEBUG](%32s) %05d: get connect-wtp(%d) failed.\r\n";
      uVar3 = 0x1ef;
LAB_0045acd8:
      printf(__format,"balance_cnt_wtp_entry_get",uVar3,param_2);
    }
  }
  return iVar1;
}

