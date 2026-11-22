// func balance_cnt_wtp_entry_update @ 0045b368 size=968

undefined4 balance_cnt_wtp_entry_update(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  void *__s;
  uint uVar4;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  char *pcVar5;
  undefined4 uVar6;
  byte *pbVar7;
  undefined4 uVar8;
  
  if (((param_1 == (byte *)0x0) || (param_2 == 0)) || (balance_dis_sta_hash == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[BALANCE_ERROR](%32s) %05d: input error.\r\n";
    uVar6 = 0x352;
LAB_0045b454:
    uVar8 = 0xffffffff;
    printf(pcVar5,"balance_cnt_wtp_entry_update",uVar6);
  }
  else {
    pbVar1 = (byte *)FUN_00407fa0(balance_dis_sta_hash,param_1);
    if (pbVar1 == (byte *)0x0) {
      pbVar1 = (byte *)balance_dis_sta_entry_add(param_1);
      if (pbVar1 == (byte *)0x0) {
        if (g_balance_warning == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        printf("[BALANCE_WARNING](%32s) %05d: add discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n"
               ,"balance_cnt_wtp_entry_update",0x35d,(uint)*param_1,(uint)param_1[1],
               (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
        return 0xffffffff;
      }
      if (g_balance_debug == 0) {
        uVar6 = *(undefined4 *)(param_2 + 0xc);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          uVar6 = *(undefined4 *)(param_2 + 0xc);
        }
        else {
          printf("[BALANCE_DEBUG](%32s) %05d: discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) isn\'t existent, add it successed.\r\n"
                 ,"balance_cnt_wtp_entry_update",0x360,(uint)*param_1,(uint)param_1[1],
                 (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
          uVar6 = *(undefined4 *)(param_2 + 0xc);
        }
      }
    }
    else {
      uVar6 = *(undefined4 *)(param_2 + 0xc);
    }
    iVar2 = balance_cnt_wtp_entry_get(pbVar1,uVar6);
    if (iVar2 == 0) {
      __s = (void *)FUN_00408450(0x14,0x2ff);
      if (__s == (void *)0x0) {
        if (g_balance_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 != 0) {
          printf("[BALANCE_ERROR](%32s) %05d: malloc connect-wtp failed.\r\n",
                 "balance_cnt_wtp_entry_add",0x302);
        }
        if (g_balance_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[BALANCE_ERROR](%32s) %05d: add new connect-wtp failed.\r\n";
        uVar6 = 0x36a;
        goto LAB_0045b454;
      }
      memset(__s,0,0x14);
      pbVar7 = pbVar1 + 0x10;
      *(undefined4 *)((int)__s + 0xc) = *(undefined4 *)(param_2 + 0xc);
      FUN_00407e70();
      *(undefined4 *)((int)__s + 0x10) = extraout_v1_00;
      uVar4 = FUN_00407fe0(pbVar7);
      if (9 < uVar4) {
        uVar6 = FUN_004081b0(pbVar7);
        balance_cnt_wtp_entry_delete(uVar6);
      }
      FUN_004086b0(pbVar7,__s);
      if ((g_balance_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[BALANCE_DEBUG](%32s) %05d: add connect-wtp(%d) to discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) successed\r\n"
               ,"balance_cnt_wtp_entry_add",0x318,*(undefined4 *)((int)__s + 0xc),(uint)*pbVar1,
               (uint)pbVar1[1],(uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5]);
      }
      if (g_balance_debug == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      pcVar5 = "[BALANCE_DEBUG](%32s) %05d: connect-wtp(%d) isn\'t existent, add it successed.\r\n";
      uVar6 = 0x36d;
    }
    else {
      FUN_00407e70();
      uVar6 = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(iVar2 + 0x10) = extraout_v1;
      FUN_00408500(iVar2);
      FUN_004086b0(uVar6,iVar2);
      if ((g_balance_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[BALANCE_DEBUG](%32s) %05d: reset connect-wtp(%d) successed.\r\n",
               "balance_cnt_wtp_entry_reset",0x339,*(undefined4 *)(iVar2 + 0xc));
      }
      if (g_balance_debug == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      pcVar5 = "[BALANCE_DEBUG](%32s) %05d: connect-wtp(%d) is existent, reset it successed.\r\n";
      uVar6 = 0x378;
    }
    uVar8 = 0;
    printf(pcVar5,"balance_cnt_wtp_entry_update",uVar6,*(undefined4 *)(param_2 + 0xc));
  }
  return uVar8;
}

