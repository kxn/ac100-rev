// func cw_priv_radio_role_table_create @ 005b99c8 size=516

int cw_priv_radio_role_table_create(char *param_1)

{
  int iVar1;
  short sVar3;
  int iVar2;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d cw_priv_radio_role_table_create ENTER\n",
           "cw_priv_radio_role_table_create",0x10e);
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
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_radio_role_table_create",0x118);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if (*param_1 == '\0') {
    sVar3 = 0;
LAB_005b9a3c:
    iVar2 = cw_protocol_msg_ele_create(0x7f,sVar3 + 1,iVar1);
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
                 "cw_priv_radio_role_table_create",0x137);
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
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar5 = 0x123;
LAB_005b9b98:
        printf(__format,"cw_priv_radio_role_table_create",uVar5);
      }
    }
    else {
      sVar3 = FUN_005b9884(param_1);
      iVar2 = cw_protocol_clone(iVar2,sVar3);
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 != 0) goto LAB_005b9a3c;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar5 = 0x12d;
        goto LAB_005b9b98;
      }
    }
    FUN_00407df0(iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

