// func balance_db_dis_sta_delete @ 0045d5b8 size=1

undefined4 balance_db_dis_sta_delete(byte *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *__format;
  undefined4 uVar7;
  uint uVar8;
  
  if ((param_1 == (byte *)0x0) || (balance_dis_sta_hash == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[BALANCE_ERROR](%32s) %05d: input error.\r\n","balance_db_dis_sta_delete",0x648);
    return 0xffffffff;
  }
  FUN_004082d0(balance_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(balance_dis_sta_hash,param_1);
  if (iVar1 == 0) {
    if ((g_balance_debug == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
    goto code_r0x0045d628;
    uVar2 = (uint)param_1[1];
    uVar8 = (uint)*param_1;
    __format = 
    "[BALANCE_DEBUG](%32s) %05d: get discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n";
    uVar3 = (uint)param_1[2];
    uVar7 = 0x652;
    uVar4 = (uint)param_1[3];
    uVar5 = (uint)param_1[4];
    uVar6 = (uint)param_1[5];
  }
  else if (*(int *)(iVar1 + 0x18) == 0) {
    iVar1 = balance_dis_sta_entry_delete(iVar1);
    if (iVar1 == -1) {
      if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
      goto code_r0x0045d628;
      uVar2 = (uint)param_1[1];
      uVar8 = (uint)*param_1;
      __format = 
      "[BALANCE_ERROR](%32s) %05d: delete discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n"
      ;
      uVar3 = (uint)param_1[2];
      uVar7 = 0x662;
      uVar4 = (uint)param_1[3];
      uVar5 = (uint)param_1[4];
      uVar6 = (uint)param_1[5];
    }
    else {
      if ((g_balance_debug == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
      goto code_r0x0045d628;
      uVar2 = (uint)param_1[1];
      uVar8 = (uint)*param_1;
      __format = 
      "[BALANCE_DEBUG](%32s) %05d: delete discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
      ;
      uVar3 = (uint)param_1[2];
      uVar7 = 0x666;
      uVar4 = (uint)param_1[3];
      uVar5 = (uint)param_1[4];
      uVar6 = (uint)param_1[5];
    }
  }
  else {
    if ((g_balance_debug == 0) || (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 == 0))
    goto code_r0x0045d628;
    uVar2 = (uint)param_1[1];
    uVar8 = (uint)*param_1;
    __format = 
    "[BALANCE_DEBUG](%32s) %05d: connect-wtp isn\'t null, so discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) cann\'t delete.\r\n"
    ;
    uVar3 = (uint)param_1[2];
    uVar7 = 0x65a;
    uVar4 = (uint)param_1[3];
    uVar5 = (uint)param_1[4];
    uVar6 = (uint)param_1[5];
  }
  printf(__format,"balance_db_dis_sta_delete",uVar7,uVar8,uVar2,uVar3,uVar4,uVar5,uVar6);
code_r0x0045d628:
  FUN_00407f30(balance_db_mutex);
  return 0;
}

