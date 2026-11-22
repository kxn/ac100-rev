// func cw_priv_ap_web_account_create @ 005a9f04 size=636

int cw_priv_ap_web_account_create(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = cw_protocol_clone(param_1,0xc);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_ap_web_account_create",0xb3);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  if (*(char *)(param_1 + 2) != '\0') {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005a9fc4;
      pcVar3 = "[CW_ERROR]%32s():%4d username is null\n";
      uVar4 = 0xbc;
    }
    else {
      iVar2 = cw_protocol_clone();
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 != 0) goto LAB_005a9f3c;
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005a9fc4;
      pcVar3 = "[CW_ERROR]%32s():%4d failed to clone username\n";
      uVar4 = 0xc3;
    }
    printf(pcVar3,"cw_priv_ap_web_account_create",uVar4);
    goto LAB_005a9fc4;
  }
LAB_005a9f3c:
  if (*(char *)(param_1 + 3) == '\0') {
LAB_005a9f64:
    uVar4 = cw_priv_ap_web_account_length(param_1);
    iVar2 = cw_protocol_msg_ele_create(0xa9,uVar4,iVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar1 + 4);
      }
      else {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_ap_web_account_create",0xe4);
        iVar2 = *(int *)(iVar1 + 4);
      }
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 8);
    }
    else {
      FUN_00407df0();
      iVar2 = *(int *)(iVar1 + 8);
    }
    if (iVar2 != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
    return 0;
  }
  if (*(int *)(param_1 + 8) == 0) {
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar1 + 4);
      }
      else {
        pcVar3 = "[CW_ERROR]%32s():%4d password is null\n";
        uVar4 = 0xcc;
LAB_005aa124:
        printf(pcVar3,"cw_priv_ap_web_account_create",uVar4);
        iVar2 = *(int *)(iVar1 + 4);
      }
    }
  }
  else {
    iVar2 = cw_protocol_clone();
    *(int *)(iVar1 + 8) = iVar2;
    if (iVar2 != 0) goto LAB_005a9f64;
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 != 0) {
        pcVar3 = "[CW_ERROR]%32s():%4d failed to clone password\n";
        uVar4 = 0xd7;
        goto LAB_005aa124;
      }
      iVar2 = *(int *)(iVar1 + 4);
    }
  }
  if (iVar2 != 0) {
    FUN_00407df0();
  }
LAB_005a9fc4:
  FUN_00407df0(iVar1);
  return 0;
}

