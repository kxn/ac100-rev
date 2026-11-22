// func balance_db_dis_sta_add @ 0045d3ac size=1

undefined4 balance_db_dis_sta_add(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  char *__format;
  undefined4 uVar8;
  
  if ((param_1 == (byte *)0x0) || (balance_dis_sta_hash == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    printf("[BALANCE_ERROR](%32s) %05d: inputs error\r\n","balance_db_dis_sta_add",0x619);
    return 0xffffffff;
  }
  FUN_004082d0(balance_db_mutex,0xffffffff);
  iVar7 = FUN_00407fa0(balance_dis_sta_hash,param_1);
  if (iVar7 == 0) {
    iVar7 = balance_dis_sta_entry_add(param_1);
    if (iVar7 == 0) {
      if ((g_balance_error != 0) && (iVar7 = is_target_debug_ap(balance_db_mutex), iVar7 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: add discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n"
               ,"balance_db_dis_sta_add",0x629,(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
               (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
      }
      FUN_00407f30(balance_db_mutex);
      return 0xffffffff;
    }
    if ((g_balance_debug == 0) || (iVar7 = is_target_debug_ap(balance_db_mutex), iVar7 == 0))
    goto code_r0x0045d408;
    bVar1 = param_1[1];
    bVar2 = *param_1;
    __format = 
    "[BALANCE_DEBUG](%32s) %05d: add discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
    ;
    bVar3 = param_1[2];
    uVar8 = 0x62d;
    bVar4 = param_1[3];
    bVar5 = param_1[4];
    bVar6 = param_1[5];
  }
  else {
    if ((g_balance_debug == 0) || (iVar7 = is_target_debug_ap(balance_db_mutex), iVar7 == 0))
    goto code_r0x0045d408;
    bVar1 = param_1[1];
    bVar2 = *param_1;
    __format = 
    "[BALANCE_DEBUG](%32s) %05d: discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) is existent.\r\n";
    bVar3 = param_1[2];
    uVar8 = 0x623;
    bVar4 = param_1[3];
    bVar5 = param_1[4];
    bVar6 = param_1[5];
  }
  printf(__format,"balance_db_dis_sta_add",uVar8,(uint)bVar2,(uint)bVar1,(uint)bVar3,(uint)bVar4,
         (uint)bVar5,(uint)bVar6);
code_r0x0045d408:
  FUN_00407f30(balance_db_mutex);
  return 0;
}

