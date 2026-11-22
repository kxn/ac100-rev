// func balance_dis_sta_entry_delete @ 0045ad64 size=476

undefined4 balance_dis_sta_entry_delete(byte *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((param_1 == (byte *)0x0) || (balance_dis_sta_hash == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error\r\n";
    uVar2 = 0x224;
  }
  else {
    do {
      iVar1 = FUN_004081b0(param_1 + 0x10);
      if (iVar1 == 0) {
        iVar1 = FUN_00407f40(balance_dis_sta_hash,param_1);
        if (iVar1 == 0) {
          if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[BALANCE_DEBUG](%32s) %05d: delete discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
                   ,"balance_dis_sta_entry_delete",0x23a,(uint)*param_1,(uint)param_1[1],
                   (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
          }
          FUN_00407df0(param_1);
          return 0;
        }
        if (g_balance_error == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        printf("[BALANCE_ERROR](%32s) %05d: remove discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) from hash failed.\r\n"
               ,"balance_dis_sta_entry_delete",0x236,(uint)*param_1,(uint)param_1[1],
               (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
        return 0;
      }
      iVar1 = balance_cnt_wtp_entry_delete(iVar1);
    } while (iVar1 != -1);
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: delete connect-wtp faield.\r\n";
    uVar2 = 0x22e;
  }
  printf(__format,"balance_dis_sta_entry_delete",uVar2);
  return 0xffffffff;
}

