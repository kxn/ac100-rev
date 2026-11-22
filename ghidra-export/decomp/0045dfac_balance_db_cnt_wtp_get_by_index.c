// func balance_db_cnt_wtp_get_by_index @ 0045dfac size=1

void * balance_db_cnt_wtp_get_by_index(undefined4 param_1,byte *param_2,void *param_3)

{
  int iVar1;
  void *__src;
  char *__format;
  undefined4 uVar2;
  
  if (((param_2 == (byte *)0x0) || (param_3 == (void *)0x0)) || (balance_dis_sta_hash == 0)) {
    if (g_balance_error == 0) {
      return (void *)0x0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_db_cnt_wtp_get_by_index",0x701);
    return (void *)0x0;
  }
  FUN_004082d0(balance_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(balance_dis_sta_hash,param_2);
  if (iVar1 == 0) {
    if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)) {
      printf("[BALANCE_DEBUG](%32s) %05d: get discovery-station(%02x:%02x:%02x:%02x:%02x:%02x) failed.\r\n"
             ,"balance_db_cnt_wtp_get_by_index",0x70b,(uint)*param_2,(uint)param_2[1],
             (uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
    }
    FUN_00407f30(balance_db_mutex);
    return (void *)0x0;
  }
  __src = (void *)balance_cnt_wtp_entry_get(iVar1,param_1);
  if (__src == (void *)0x0) {
    if ((g_balance_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto code_r0x0045e048;
    __format = "[BALANCE_DEBUG](%32s) %05d: get connect-wtp(%d) failed.\r\n";
    uVar2 = 0x713;
  }
  else {
    memcpy(param_3,__src,0x14);
    if ((g_balance_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto code_r0x0045e048;
    __format = "[BALANCE_DEBUG](%32s) %05d: get connect-wtp(%d) successed.\r\n";
    uVar2 = 0x719;
  }
  printf(__format,"balance_db_cnt_wtp_get_by_index",uVar2,param_1);
code_r0x0045e048:
  FUN_00407f30(balance_db_mutex);
  return __src;
}

