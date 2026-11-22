// func cw_msg_ele_priv_add_with_create @ 00582cc8 size=300

undefined4 cw_msg_ele_priv_add_with_create(int param_1,uint param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  param_2 = param_2 & 0xffff;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    return 0xffffffff;
  }
  iVar1 = cw_msg_ele_priv_size();
  if (iVar1 + -1 < (int)param_2) {
    return 0xffffffff;
  }
  iVar1 = cw_msg_ele_priv_mngr_get(param_2);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d private message element(%d)\'s manager is NULL\n";
    uVar2 = 0x2a7;
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x14))(param_3);
    if (iVar1 != 0) {
      FUN_004086b0(param_1 + 8,iVar1);
      *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + *(short *)(iVar1 + 0xe) + 4;
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d create message element(%d) failed\n";
    uVar2 = 0x2ad;
  }
  printf(__format,"cw_msg_ele_priv_add_with_create",uVar2,param_2);
  return 0xffffffff;
}

