// func cw_priv_two_way_passthrough_general_info_request_create @ 005ca0bc size=428

int cw_priv_two_way_passthrough_general_info_request_create(int param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = cw_protocol_clone(param_1,0x10);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n",
           "cw_priv_two_way_passthrough_general_info_request_create",0xca);
    return 0;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
  if (*(uint *)(param_1 + 8) == 0) {
    iVar3 = *(int *)(iVar1 + 8);
LAB_005ca110:
    iVar3 = cw_protocol_msg_ele_create(0xa5,iVar3 + 0xcU & 0xffff,iVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(iVar1 + 0xc);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 0xc);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_two_way_passthrough_general_info_request_create",0xe5);
          iVar2 = *(int *)(iVar1 + 0xc);
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 0xc) == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar4 = 0xd4;
LAB_005ca234:
        printf(__format,"cw_priv_two_way_passthrough_general_info_request_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(*(int *)(param_1 + 0xc),*(uint *)(param_1 + 8) & 0xffff);
      *(int *)(iVar1 + 0xc) = iVar3;
      if (iVar3 != 0) {
        iVar3 = *(int *)(iVar1 + 8);
        goto LAB_005ca110;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar4 = 0xdb;
        goto LAB_005ca234;
      }
    }
    FUN_00407df0(iVar1);
    iVar3 = 0;
  }
  return iVar3;
}

