// func cw_priv_wtp_sub_capability_create @ 005d03ec size=432

int cw_priv_wtp_sub_capability_create(ushort *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *__format;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_wtp_sub_capability_create",0xe1);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if (*param_1 == 0) {
LAB_005d0440:
    uVar3 = cw_priv_wtp_sub_capability_length(iVar1);
    iVar2 = cw_protocol_msg_ele_create(0x8f,uVar3,iVar1);
    if (iVar2 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(iVar1 + 4);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_wtp_sub_capability_create",0xfc);
          iVar4 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 2) == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d mac list is null\n";
        uVar3 = 0xeb;
LAB_005d0568:
        printf(__format,"cw_priv_wtp_sub_capability_create",uVar3);
      }
    }
    else {
      iVar2 = cw_protocol_clone(*(int *)(param_1 + 2),(*param_1 & 0x1fff) << 3);
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 != 0) goto LAB_005d0440;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone mac list\n";
        uVar3 = 0xf2;
        goto LAB_005d0568;
      }
    }
    FUN_00407df0(iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

