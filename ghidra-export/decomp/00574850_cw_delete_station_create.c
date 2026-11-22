// func cw_delete_station_create @ 00574850 size=384

int cw_delete_station_create(int param_1)

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
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_delete_station_create",0xcd);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if (*(char *)(param_1 + 1) == '\x06') {
    iVar2 = *(int *)(param_1 + 4);
LAB_005748c8:
    if (iVar2 == 0) {
      uVar4 = (uint)*(byte *)(iVar1 + 1);
      goto LAB_00574894;
    }
    iVar2 = cw_protocol_clone();
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone mac address\n","cw_delete_station_create",0xd8)
        ;
      }
      FUN_00407df0(iVar1);
      uVar4 = (uint)*(byte *)(iVar1 + 1);
      goto LAB_00574894;
    }
  }
  else if (*(char *)(param_1 + 1) == '\b') {
    iVar2 = *(int *)(param_1 + 4);
    goto LAB_005748c8;
  }
  uVar4 = (uint)*(byte *)(iVar1 + 1);
LAB_00574894:
  iVar2 = cw_protocol_msg_ele_create(0x12,uVar4 + 2,iVar1);
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
        printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_delete_station_create",
               0xe1);
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

