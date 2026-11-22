// func cw_sta_info_list_create @ 00580db4 size=440

int cw_sta_info_list_create(int param_1)

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
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_sta_info_list_create",0xf0);
    return 0;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
  if (*(uint *)(param_1 + 8) == 0) {
    iVar3 = *(int *)(iVar1 + 8);
LAB_00580e0c:
    iVar3 = cw_protocol_msg_ele_create(0x34,iVar3 * 0xe + 9U & 0xffff,iVar1);
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
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n","cw_sta_info_list_create"
                 ,0x10b);
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
        __format = "[CW_ERROR]%32s():%4d rssi list is null\n";
        uVar4 = 0xfa;
LAB_00580f38:
        printf(__format,"cw_sta_info_list_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(*(int *)(param_1 + 0xc),(*(uint *)(param_1 + 8) & 0xfff) << 4);
      *(int *)(iVar1 + 0xc) = iVar3;
      if (iVar3 != 0) {
        iVar3 = *(int *)(iVar1 + 8);
        goto LAB_00580e0c;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone rssi list\n";
        uVar4 = 0x101;
        goto LAB_00580f38;
      }
    }
    FUN_00407df0(iVar1);
    iVar3 = 0;
  }
  return iVar3;
}

