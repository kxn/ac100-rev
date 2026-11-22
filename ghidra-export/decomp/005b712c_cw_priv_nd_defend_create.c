// func cw_priv_nd_defend_create @ 005b712c size=444

int cw_priv_nd_defend_create(int param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = cw_protocol_clone(param_1,0xc);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_nd_defend_create",0xe1);
    return 0;
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  if (*(int *)(param_1 + 4) == 0) {
    iVar3 = *(int *)(iVar1 + 4);
LAB_005b7188:
    iVar3 = cw_protocol_msg_ele_create(0x62,iVar3 * 0x16 + 6U & 0xfffe,iVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(iVar1 + 8);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 8);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_nd_defend_create",0xfb);
          iVar2 = *(int *)(iVar1 + 8);
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d nd info is null\n";
        uVar4 = 0xea;
LAB_005b72b4:
        printf(__format,"cw_priv_nd_defend_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(*(int *)(param_1 + 8),*(int *)(param_1 + 4) * 0x16 & 0xfffe);
      *(int *)(iVar1 + 8) = iVar3;
      if (iVar3 != 0) {
        iVar3 = *(int *)(iVar1 + 4);
        goto LAB_005b7188;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone nd info\n";
        uVar4 = 0xf1;
        goto LAB_005b72b4;
      }
    }
    FUN_00407df0(iVar1);
    iVar3 = 0;
  }
  return iVar3;
}

