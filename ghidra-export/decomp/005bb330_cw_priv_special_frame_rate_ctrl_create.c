// func cw_priv_special_frame_rate_ctrl_create @ 005bb330 size=428

int cw_priv_special_frame_rate_ctrl_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_special_frame_rate_ctrl_create",
           0xe3);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  uVar4 = (uint)*(byte *)(param_1 + 2);
  if (uVar4 == 0) {
LAB_005bb388:
    iVar2 = cw_protocol_msg_ele_create(0x8e,(uVar4 + 1) * 4,iVar1);
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
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_special_frame_rate_ctrl_create",0xfe);
          iVar3 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d mac list is null\n";
        uVar5 = 0xed;
LAB_005bb4a8:
        printf(__format,"cw_priv_special_frame_rate_ctrl_create",uVar5);
      }
    }
    else {
      iVar2 = cw_protocol_clone(*(int *)(param_1 + 4),uVar4 << 2);
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 != 0) {
        uVar4 = (uint)*(byte *)(param_1 + 2);
        goto LAB_005bb388;
      }
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone mac list\n";
        uVar5 = 0xf4;
        goto LAB_005bb4a8;
      }
    }
    FUN_00407df0(iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

