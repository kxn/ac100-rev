// func cw_priv_lldp_report_create @ 005b5018 size=444

int cw_priv_lldp_report_create(int *param_1)

{
  int *piVar1;
  int iVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)cw_protocol_clone(param_1,8);
  if (piVar1 == (int *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_lldp_report_create",0xbb);
    return 0;
  }
  piVar1[1] = 0;
  *piVar1 = 0;
  iVar3 = *param_1;
  if (iVar3 == 0) {
LAB_005b5080:
    iVar3 = cw_protocol_msg_ele_create(0x68,iVar3 + 4U & 0xffff,piVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = piVar1[1];
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = piVar1[1];
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_lldp_report_create",0xd6);
          iVar2 = piVar1[1];
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(piVar1);
    }
  }
  else {
    if (param_1[1] == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar4 = 0xc5;
LAB_005b51a0:
        printf(__format,"cw_priv_lldp_report_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(param_1[1],iVar3 + 1U & 0xffff);
      piVar1[1] = iVar3;
      if (iVar3 != 0) {
        *piVar1 = *param_1;
        iVar3 = *param_1;
        goto LAB_005b5080;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar4 = 0xcc;
        goto LAB_005b51a0;
      }
    }
    FUN_00407df0(piVar1);
    iVar3 = 0;
  }
  return iVar3;
}

