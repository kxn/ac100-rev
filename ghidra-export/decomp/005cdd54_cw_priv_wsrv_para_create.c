// func cw_priv_wsrv_para_create @ 005cdd54 size=1292

int cw_priv_wsrv_para_create(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  char *__format;
  short sVar9;
  
  iVar2 = cw_protocol_clone(param_1,0xd);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_wsrv_para_create",0x19b);
    return 0;
  }
  *(undefined4 *)(iVar2 + 9) = 0;
  switch(*(undefined1 *)(param_1 + 8)) {
  case 0:
    sVar9 = 9;
LAB_005cde60:
    iVar5 = cw_protocol_msg_ele_create(9,sVar9,iVar2);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (capwap_err_switch == 0) {
      uVar6 = (uint)*(byte *)(param_1 + 8);
    }
    else {
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        uVar6 = (uint)*(byte *)(param_1 + 8);
      }
      else {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n","cw_priv_wsrv_para_create",
               0x20e);
        uVar6 = (uint)*(byte *)(param_1 + 8);
      }
    }
    if (uVar6 == 2) {
      uVar8 = *(undefined4 *)(*(int *)(iVar2 + 9) + 0x1b);
LAB_005ce024:
      FUN_00407df0(uVar8);
    }
    else {
      uVar7 = 1;
      if ((uVar6 < 3) || (uVar7 = 4, uVar6 != 3)) {
        if (uVar6 != uVar7) goto LAB_005ce008;
        uVar7 = iVar2 + 9U & 3;
        uVar1 = iVar2 + 0xcU & 3;
        uVar8 = *(undefined4 *)
                 (((*(int *)((iVar2 + 9U) - uVar7) << uVar7 * 8 |
                   uVar6 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar1 + 1) * 8 |
                  *(uint *)((iVar2 + 0xcU) - uVar1) >> (3 - uVar1) * 8) + 8);
        goto LAB_005ce024;
      }
    }
    FUN_00407df0(*(undefined4 *)(iVar2 + 9));
LAB_005ce008:
    FUN_00407df0(iVar2);
    return 0;
  case 1:
  case 4:
    iVar5 = *(int *)(param_1 + 9);
    if ((iVar5 == 0) || (*(int *)(iVar5 + 8) == 0)) {
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cdda8;
      __format = "[CW_ERROR]%32s():%4d psk is null or psk\'s key is null\n";
      uVar8 = 0x1af;
    }
    else {
      iVar3 = cw_protocol_clone(iVar5,0xc);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 8) = 0;
        *(int *)(iVar2 + 9) = iVar3;
        iVar4 = cw_protocol_clone(*(undefined4 *)(iVar5 + 8),*(undefined2 *)(iVar5 + 6));
        if (iVar4 == 0) {
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_ERROR]%32s():%4d faield to clone key\n","cw_priv_wsrv_para_create",0x1bf);
          }
          FUN_00407df0(iVar2);
          iVar2 = iVar3;
          goto LAB_005cdda8;
        }
        *(int *)(iVar3 + 8) = iVar4;
        sVar9 = *(short *)(iVar5 + 6) + 0x11;
        goto LAB_005cde60;
      }
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cdda8;
      __format = "[CW_ERROR]%32s():%4d failed to clone psk\n";
      uVar8 = 0x1b6;
    }
    break;
  case 2:
    iVar5 = *(int *)(param_1 + 9);
    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x1b) == 0)) {
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cdda8;
      __format = "[CW_ERROR]%32s():%4d wpa is null or wpa\'s key is null\n";
      uVar8 = 0x1cf;
    }
    else {
      iVar3 = cw_protocol_clone(iVar5,0x1f);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x1b) = 0;
        *(int *)(iVar2 + 9) = iVar3;
        iVar4 = cw_protocol_clone(*(undefined4 *)(iVar5 + 0x1b),*(undefined2 *)(iVar5 + 0x19));
        if (iVar4 == 0) {
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to clone wpa\n","cw_priv_wsrv_para_create",0x1df);
          }
          FUN_00407df0(iVar3);
          goto LAB_005cdda8;
        }
        *(int *)(iVar3 + 0x1b) = iVar4;
        sVar9 = *(short *)(iVar5 + 0x19) + 0x17;
        if (*(char *)(iVar5 + 6) != '\0') {
          sVar9 = *(short *)(iVar5 + 0x19) + 0x23;
        }
        goto LAB_005cde60;
      }
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cdda8;
      __format = "[CW_ERROR]%32s():%4d failed to clone wpa\n";
      uVar8 = 0x1d6;
    }
    break;
  case 3:
    if (*(int *)(param_1 + 9) == 0) {
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cdda8;
      __format = "[CW_ERROR]%32s():%4d wep is null\n";
      uVar8 = 0x1f2;
    }
    else {
      iVar5 = cw_protocol_clone(*(int *)(param_1 + 9),0x86);
      if (iVar5 != 0) {
        *(int *)(iVar2 + 9) = iVar5;
        sVar9 = 0x8f;
        goto LAB_005cde60;
      }
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cdda8;
      __format = "[CW_ERROR]%32s():%4d failed to clone wep\n";
      uVar8 = 0x1f9;
    }
    break;
  default:
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(iVar2), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n","cw_priv_wsrv_para_create",0x203,
             (uint)*(byte *)(param_1 + 8));
    }
    goto LAB_005cdda8;
  }
  printf(__format,"cw_priv_wsrv_para_create",uVar8);
LAB_005cdda8:
  FUN_00407df0(iVar2);
  return 0;
}

