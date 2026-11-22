// func cw_priv_bw_ctrl_create @ 005aca5c size=816

int cw_priv_bw_ctrl_create(char *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint *puVar9;
  
  if ((param_1 == (char *)0x0) || (*(int *)(param_1 + 0xc) == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d ctrl_val is null.\n";
    uVar8 = 300;
LAB_005acb80:
    printf(pcVar7,"cw_priv_bw_ctrl_create",uVar8);
    return 0;
  }
  iVar2 = cw_protocol_clone(param_1,0x10);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d failed to clone value\n";
    uVar8 = 0x134;
    goto LAB_005acb80;
  }
  puVar9 = *(uint **)(param_1 + 0xc);
  if (*param_1 == '\0') {
    uVar3 = *puVar9;
LAB_005acaa8:
    if (0x80 < uVar3) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d mac_num(%d) is too big, shouldn\'t bigger then %d\n",
               "cw_priv_bw_ctrl_create",0x13d,*puVar9,0x80);
      }
      goto LAB_005acac4;
    }
    iVar5 = cw_protocol_clone(puVar9,uVar3 * 6 + 4 & 0xfffe);
    if (iVar5 == 0) {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005acac4;
      uVar8 = 0x143;
LAB_005acd48:
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_bw_ctrl_create",uVar8);
      goto LAB_005acac4;
    }
    uVar3 = *puVar9;
    iVar4 = 0;
    *(int *)(iVar2 + 0xc) = iVar5;
    uVar3 = uVar3 * 6 + 0xd;
  }
  else {
    if (*param_1 == '\x04') {
      uVar3 = *puVar9;
      goto LAB_005acaa8;
    }
    if (0x1f < *(byte *)puVar9) {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005acac4;
      bVar1 = *(byte *)puVar9;
      pcVar7 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
      uVar8 = 0x14e;
LAB_005acb3c:
      printf(pcVar7,"cw_priv_bw_ctrl_create",uVar8,(uint)bVar1);
      goto LAB_005acac4;
    }
    if (0x10 < *(byte *)((int)puVar9 + 1)) {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005acac4;
      bVar1 = *(byte *)((int)puVar9 + 1);
      pcVar7 = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar8 = 0x154;
      goto LAB_005acb3c;
    }
    iVar4 = cw_protocol_clone(puVar9,2);
    if (iVar4 == 0) {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005acac4;
      uVar8 = 0x15b;
      goto LAB_005acd48;
    }
    *(int *)(iVar2 + 0xc) = iVar4;
    uVar3 = 0xb;
    iVar5 = 0;
  }
  iVar6 = cw_protocol_msg_ele_create(0x45,uVar3 & 0xffff,iVar2);
  if (iVar6 != 0) {
    return iVar6;
  }
  if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n","cw_priv_bw_ctrl_create",0x166)
    ;
  }
  if (iVar5 != 0) {
    FUN_00407df0(iVar5);
  }
  if (iVar4 != 0) {
    FUN_00407df0(iVar4);
  }
LAB_005acac4:
  FUN_00407df0(iVar2);
  return 0;
}

