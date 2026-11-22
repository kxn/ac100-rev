// func cw_add_station_create @ 0056ff1c size=484

int cw_add_station_create(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = cw_protocol_clone(param_1,0x10);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_add_station_create",0x102);
    return 0;
  }
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  if ((*(int *)(param_1 + 4) == 0) ||
     ((*(char *)(param_1 + 1) != '\x06' && (*(char *)(param_1 + 1) != '\b')))) {
LAB_0056ff68:
    if (*(int *)(param_1 + 0xc) == 0) {
      sVar1 = *(short *)(iVar2 + 8);
    }
    else {
      if (*(short *)(param_1 + 8) != 0) {
        iVar3 = cw_protocol_duplicate_string();
        *(int *)(iVar2 + 0xc) = iVar3;
        if (iVar3 == 0) {
          if (*(int *)(iVar2 + 4) != 0) {
            FUN_00407df0();
          }
          goto LAB_0056ffe0;
        }
      }
      sVar1 = *(short *)(iVar2 + 8);
    }
    iVar3 = cw_protocol_msg_ele_create(8,sVar1 + 2 + (ushort)*(byte *)(iVar2 + 1),iVar2);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(iVar2 + 4);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar2 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_add_station_create",
                 0x127);
          iVar4 = *(int *)(iVar2 + 4);
        }
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar2 + 0xc);
      }
      else {
        FUN_00407df0();
        iVar4 = *(int *)(iVar2 + 0xc);
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar2);
    }
  }
  else {
    iVar3 = cw_protocol_clone();
    *(int *)(iVar2 + 4) = iVar3;
    if (iVar3 != 0) goto LAB_0056ff68;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d faild to clone mac address\n","cw_add_station_create",0x10e);
    }
LAB_0056ffe0:
    FUN_00407df0(iVar2);
    iVar3 = 0;
  }
  return iVar3;
}

