// func cw_priv_trans_data_request_create @ 005c9b10 size=428

int cw_priv_trans_data_request_create(int param_1)

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
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_trans_data_request_create",0xba);
    return 0;
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  if (*(uint *)(param_1 + 4) == 0) {
    iVar3 = *(int *)(iVar1 + 4);
LAB_005c9b64:
    iVar3 = cw_protocol_msg_ele_create(0x14,iVar3 + 4U & 0xffff,iVar1);
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
                 "cw_priv_trans_data_request_create",0xd5);
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
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar4 = 0xc4;
LAB_005c9c88:
        printf(__format,"cw_priv_trans_data_request_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(*(int *)(param_1 + 8),*(uint *)(param_1 + 4) & 0xffff);
      *(int *)(iVar1 + 8) = iVar3;
      if (iVar3 != 0) {
        iVar3 = *(int *)(iVar1 + 4);
        goto LAB_005c9b64;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar4 = 0xcb;
        goto LAB_005c9c88;
      }
    }
    FUN_00407df0(iVar1);
    iVar3 = 0;
  }
  return iVar3;
}

