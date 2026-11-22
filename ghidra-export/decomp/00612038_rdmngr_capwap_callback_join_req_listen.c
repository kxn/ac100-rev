// func rdmngr_capwap_callback_join_req_listen @ 00612038 size=640

undefined4 rdmngr_capwap_callback_join_req_listen(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  undefined4 local_2b0;
  undefined1 auStack_d8 [192];
  
  local_308 = 0;
  memset(auStack_2f0,0,0x2d8);
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  local_2f8 = 0;
  piVar1 = (int *)cw_msg_ele_val_get(param_1,0x21);
  if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
    if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d enter rdmngr_capwap_callback_join_req_listen\n",
             "rdmngr_capwap_callback_join_req_listen",0x691);
    }
    iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_2f0);
    if ((iVar2 == 0) && (iVar2 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xb2), iVar2 != 0)) {
      iVar3 = apdb_get_radio_extend_capability(local_2b0,auStack_d8,1,0xffffffff,&local_304,0x10);
      if (iVar3 != 0) {
        return 0;
      }
      iVar3 = apmngr_db_capacity_support(local_2e0,1,0x46);
      if (iVar3 == 0) {
        return 0;
      }
      if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d enter 11ax feature init,extend_capabiliry: %s\n",
               "rdmngr_capwap_callback_join_req_listen",0x69d,&local_304);
      }
      iVar5 = 1;
      iVar3 = rdmngr_db_get_ap_radio_cnt(local_2b0,auStack_d8,&local_308);
      if (-1 < iVar3) {
        for (; iVar5 <= iVar3; iVar5 = iVar5 + 1) {
          uVar6 = rdmngr_db_generate_rd_id(local_2e0,iVar5);
          rdmngr_db_init_11ax_feature(uVar6,&local_304,iVar2);
        }
        return 0;
      }
      if (rdmngr_err_switch == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
             "rdmngr_capwap_callback_join_req_listen",0x6a3,iVar3);
      return 0;
    }
    uVar6 = 0;
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[RDMNGR_DEBUG]%s()/%d the 11ax feature default val is null\n";
    uVar4 = 0x6b2;
  }
  else {
    uVar6 = 0xffffffff;
    if (rdmngr_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = 
    "[RDMNGR_DEBUG]%s()/%d Failed to join for formal callback return failed result code.\n";
    uVar4 = 0x68d;
  }
  printf(__format,"rdmngr_capwap_callback_join_req_listen",uVar4);
  return uVar6;
}

