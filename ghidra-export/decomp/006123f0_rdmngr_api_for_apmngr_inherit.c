// func rdmngr_api_for_apmngr_inherit @ 006123f0 size=592

undefined4 rdmngr_api_for_apmngr_inherit(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_28 [2];
  
  local_28[0] = 0;
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_api_for_apmngr_inherit() begin.\n",
           "rdmngr_api_for_apmngr_inherit",0x115);
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar4 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d invalid args!\n";
    uVar3 = 0x119;
  }
  else if (*(int *)(param_1 + 0x40) == *(int *)(param_2 + 0x40)) {
    iVar5 = 1;
    local_28[0] = *(undefined4 *)(param_1 + 0x44);
    iVar1 = rdmngr_db_get_ap_radio_cnt(*(int *)(param_1 + 0x40),param_1 + 0x218,local_28);
    if (iVar1 < 0) {
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
             "rdmngr_api_for_apmngr_inherit",0x129,iVar1);
      return 0xffffffff;
    }
    while (iVar5 <= iVar1) {
      uVar4 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_2 + 0x10),iVar5);
      uVar3 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar5);
      iVar2 = rdmngr_db_get_rd_status(uVar4);
      if (iVar2 == 0) {
        iVar5 = iVar5 + 1;
      }
      else {
        iVar2 = rdmngr_db_rd_inherit(uVar4,uVar3,param_1);
        if (iVar2 != 0) {
          uVar4 = 0xffffffff;
          if (rdmngr_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_inherit() fail.\n";
          uVar3 = 0x137;
          goto LAB_00612504;
        }
        iVar5 = iVar5 + 1;
      }
    }
    uVar4 = 0;
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[RDMNGR_DEBUG]%s()/%d rdmngr_api_for_apmngr_inherit() finish.\n";
    uVar3 = 0x13c;
  }
  else {
    uVar4 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d model not match!!!\n";
    uVar3 = 0x11f;
  }
LAB_00612504:
  printf(__format,"rdmngr_api_for_apmngr_inherit",uVar3);
  return uVar4;
}

