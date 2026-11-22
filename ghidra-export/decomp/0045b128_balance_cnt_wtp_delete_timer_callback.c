// func balance_cnt_wtp_delete_timer_callback @ 0045b128 size=576

void balance_cnt_wtp_delete_timer_callback(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint extraout_v1;
  char *__format;
  undefined4 uVar9;
  
  if ((param_1 == (byte *)0x0) || (balance_dis_sta_hash == 0)) {
    if ((g_balance_error != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: timer - inputs error.\r\n",
             "balance_cnt_wtp_delete_timer_callback",0x391);
      return;
    }
  }
  else {
    FUN_00407e70();
    while( true ) {
      iVar7 = FUN_004081b0(param_1 + 0x10);
      if ((iVar7 == 0) ||
         ((*(uint *)(iVar7 + 0x10) <= extraout_v1 && (extraout_v1 - *(uint *)(iVar7 + 0x10) < 900)))
         ) break;
      iVar8 = balance_cnt_wtp_entry_delete(iVar7);
      if (((iVar8 == -1) && (g_balance_error != 0)) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: timer - delete connect-wtp(%d) failed.\r\n",
               "balance_cnt_wtp_delete_timer_callback",0x39e,*(undefined4 *)(iVar7 + 0xc));
      }
    }
    iVar7 = FUN_00407fe0(param_1 + 0x10);
    if (iVar7 == 0) {
      iVar7 = balance_dis_sta_entry_delete(param_1);
      if (iVar7 == -1) {
        if (g_balance_error == 0) {
          return;
        }
        iVar7 = is_target_debug_ap();
        if (iVar7 == 0) {
          return;
        }
        bVar1 = param_1[1];
        bVar2 = *param_1;
        __format = 
        "[BALANCE_ERROR](%32s) %05d: timer - delete discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n"
        ;
        bVar3 = param_1[2];
        uVar9 = 0x3ad;
        bVar4 = param_1[3];
        bVar5 = param_1[4];
        bVar6 = param_1[5];
      }
      else {
        if (g_balance_debug == 0) {
          return;
        }
        iVar7 = is_target_debug_ap();
        if (iVar7 == 0) {
          return;
        }
        bVar1 = param_1[1];
        bVar2 = *param_1;
        __format = 
        "[BALANCE_DEBUG](%32s) %05d: timer - delete discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
        ;
        bVar3 = param_1[2];
        uVar9 = 0x3b0;
        bVar4 = param_1[3];
        bVar5 = param_1[4];
        bVar6 = param_1[5];
      }
      printf(__format,"balance_cnt_wtp_delete_timer_callback",uVar9,(uint)bVar2,(uint)bVar1,
             (uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar6);
    }
  }
  return;
}

