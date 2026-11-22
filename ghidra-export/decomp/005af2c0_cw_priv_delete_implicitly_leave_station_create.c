// func cw_priv_delete_implicitly_leave_station_create @ 005af2c0 size=384

int cw_priv_delete_implicitly_leave_station_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n",
           "cw_priv_delete_implicitly_leave_station_create",0xce);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if (*(char *)(param_1 + 1) == '\x06') {
    iVar2 = *(int *)(param_1 + 4);
LAB_005af338:
    if (iVar2 == 0) {
      uVar4 = (uint)*(byte *)(iVar1 + 1);
      goto LAB_005af304;
    }
    iVar2 = cw_protocol_clone();
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone mac address\n",
               "cw_priv_delete_implicitly_leave_station_create",0xd9);
      }
      FUN_00407df0(iVar1);
      uVar4 = (uint)*(byte *)(iVar1 + 1);
      goto LAB_005af304;
    }
  }
  else if (*(char *)(param_1 + 1) == '\b') {
    iVar2 = *(int *)(param_1 + 4);
    goto LAB_005af338;
  }
  uVar4 = (uint)*(byte *)(iVar1 + 1);
LAB_005af304:
  iVar2 = cw_protocol_msg_ele_create(0x5a,uVar4 + 2,iVar1);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      iVar3 = *(int *)(iVar1 + 4);
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar1 + 4);
      }
      else {
        printf("[CW_ERROR]%32s():%4d failed to create message element\n",
               "cw_priv_delete_implicitly_leave_station_create",0xe2);
        iVar3 = *(int *)(iVar1 + 4);
      }
    }
    if (iVar3 != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
  }
  return iVar2;
}

