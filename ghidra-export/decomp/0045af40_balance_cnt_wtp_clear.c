// func balance_cnt_wtp_clear @ 0045af40 size=488

void balance_cnt_wtp_clear(byte *param_1,undefined4 *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  uVar2 = *param_2;
  iVar1 = balance_cnt_wtp_entry_get(param_1,uVar2);
  if (iVar1 == 0) {
    if ((g_balance_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_WARNING](%32s) %05d: get connect-wtp(%d) from discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n"
             ,"balance_cnt_wtp_clear",0x255,uVar2,(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
             (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    }
  }
  else {
    iVar1 = balance_cnt_wtp_entry_delete(iVar1);
    if (iVar1 == -1) {
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: delete connect-wtp(%d) failed.\r\n",
               "balance_cnt_wtp_clear",0x25c,uVar2);
        return;
      }
    }
    else {
      if (g_balance_debug == 0) {
        iVar1 = *(int *)(param_1 + 0x18);
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_1 + 0x18);
        }
        else {
          printf("[BALANCE_DEBUG](%32s) %05d: delete connect-wtp(%d) successed.\r\n",
                 "balance_cnt_wtp_clear",0x25f,uVar2);
          iVar1 = *(int *)(param_1 + 0x18);
        }
      }
      if (iVar1 == 0) {
        iVar1 = balance_dis_sta_entry_delete(param_1);
        if (iVar1 == -1) {
          if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            __format = "[BALANCE_ERROR](%32s) %05d: delete discovery-station failed.\r\n";
            uVar2 = 0x267;
            goto LAB_0045b064;
          }
        }
        else if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          __format = "[BALANCE_DEBUG](%32s) %05d: delete discovery-station successed.\r\n";
          uVar2 = 0x26a;
LAB_0045b064:
          printf(__format,"balance_cnt_wtp_clear",uVar2);
          return;
        }
      }
    }
  }
  return;
}

