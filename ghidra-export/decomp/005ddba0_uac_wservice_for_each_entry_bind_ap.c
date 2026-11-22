// func uac_wservice_for_each_entry_bind_ap @ 005ddba0 size=296

undefined4 uac_wservice_for_each_entry_bind_ap(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  undefined2 local_2f8;
  undefined2 local_2f6;
  undefined1 auStack_2f0 [64];
  undefined4 local_2b0;
  undefined2 local_2ac;
  undefined2 local_2aa;
  undefined1 auStack_d8 [192];
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f0);
  if (iVar1 == 0) {
    local_2f8 = local_2ac;
    local_2f6 = local_2aa;
    uVar2 = uac_wservice_get_ap_radio_cnt(local_2b0,auStack_d8,&local_2f8);
    if (-1 < (int)uVar2) {
      uVar3 = wserv_db_for_each_entry_bind_ap(param_1,uVar2,param_2,param_3);
      return uVar3;
    }
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n";
    uVar3 = 0x1638;
  }
  else {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[error]%s(): %d  -> apmngr_db_entry_get_by_id() fail.ap_id=%d\r\n";
    uVar3 = 0x162e;
    uVar2 = param_1;
  }
  printf(__format,"uac_wservice_for_each_entry_bind_ap",uVar3,uVar2);
  return 0xffffffff;
}

