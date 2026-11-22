// func cw_image_identifier_create @ 00576f98 size=376

int cw_image_identifier_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  iVar1 = cw_protocol_clone(param_1,0xc);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone vlaue\n","cw_image_identifier_create",0xae);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0;
    if (*(short *)(param_1 + 4) == 0) {
      sVar4 = *(short *)(iVar1 + 4);
    }
    else if (*(int *)(param_1 + 8) == 0) {
      sVar4 = *(short *)(iVar1 + 4);
    }
    else {
      iVar2 = cw_protocol_clone();
      *(int *)(iVar1 + 8) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone data\n","cw_image_identifier_create",0xb9);
        }
        FUN_00407df0(iVar1);
        return 0;
      }
      sVar4 = *(short *)(iVar1 + 4);
    }
    iVar2 = cw_protocol_msg_ele_create(0x19,sVar4 + 4,iVar1);
    if (iVar2 == 0) {
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(iVar1 + 8);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar1 + 8);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n",
                 "cw_image_identifier_create",0xc3);
          iVar3 = *(int *)(iVar1 + 8);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

