// func cw_priv_region_list_create @ 005babb4 size=516

int cw_priv_region_list_create(char *param_1)

{
  int iVar1;
  short sVar3;
  int iVar2;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d cw_priv_region_list_create ENTER\n","cw_priv_region_list_create",
           0xf9);
  }
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_region_list_create",0x103);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  sVar3 = 0;
  if (*param_1 == '\0') {
LAB_005bac28:
    iVar2 = cw_protocol_msg_ele_create(0x97,sVar3 + 1,iVar1);
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
          printf("[CW_ERROR]%32s():%4d failed to create message element\n",
                 "cw_priv_region_list_create",0x122);
          iVar4 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 4) = 0;
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar5 = 0x10e;
LAB_005bad84:
        printf(__format,"cw_priv_region_list_create",uVar5);
      }
    }
    else {
      sVar3 = _calculate_region_list_length(param_1);
      iVar2 = cw_protocol_clone(*(undefined4 *)(param_1 + 4),sVar3);
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 != 0) goto LAB_005bac28;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar5 = 0x118;
        goto LAB_005bad84;
      }
    }
    FUN_00407df0(iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

