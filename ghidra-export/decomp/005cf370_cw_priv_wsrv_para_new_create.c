// func cw_priv_wsrv_para_new_create @ 005cf370 size=1236

int cw_priv_wsrv_para_new_create(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *__format;
  
  iVar2 = cw_protocol_clone(param_1,0xd);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_wsrv_para_new_create",399);
    return 0;
  }
  *(undefined4 *)(iVar2 + 9) = 0;
  switch(*(undefined1 *)(param_1 + 8)) {
  case 0:
switchD_005cf3e4_caseD_0:
    uVar3 = cw_priv_wsrv_para_new_len_get(iVar2);
    iVar5 = cw_protocol_msg_ele_create(99,uVar3,iVar2);
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
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_wsrv_para_new_create",0x1fa);
        uVar6 = (uint)*(byte *)(param_1 + 8);
      }
    }
    if (uVar6 == 2) {
      uVar3 = *(undefined4 *)(*(int *)(iVar2 + 9) + 0x4a);
LAB_005cf608:
      FUN_00407df0(uVar3);
    }
    else {
      uVar7 = 1;
      if ((uVar6 < 3) || (uVar7 = 4, uVar6 != 3)) {
        if (uVar6 != uVar7) goto LAB_005cf5ec;
        uVar7 = iVar2 + 9U & 3;
        uVar1 = iVar2 + 0xcU & 3;
        uVar3 = *(undefined4 *)
                 (((*(int *)((iVar2 + 9U) - uVar7) << uVar7 * 8 |
                   uVar6 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar1 + 1) * 8 |
                  *(uint *)((iVar2 + 0xcU) - uVar1) >> (3 - uVar1) * 8) + 8);
        goto LAB_005cf608;
      }
    }
    FUN_00407df0(*(undefined4 *)(iVar2 + 9));
LAB_005cf5ec:
    FUN_00407df0(iVar2);
    return 0;
  case 1:
  case 4:
    iVar5 = *(int *)(param_1 + 9);
    if ((iVar5 == 0) || (*(int *)(iVar5 + 8) == 0)) {
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cf3c4;
      __format = "[CW_ERROR]%32s():%4d psk is null or psk\'s key is null\n";
      uVar3 = 0x1a2;
    }
    else {
      iVar4 = cw_protocol_clone(iVar5,0xc);
      if (iVar4 != 0) {
        *(undefined4 *)(iVar4 + 8) = 0;
        *(int *)(iVar2 + 9) = iVar4;
        iVar5 = cw_protocol_clone(*(undefined4 *)(iVar5 + 8),*(undefined2 *)(iVar5 + 6));
        if (iVar5 == 0) {
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_ERROR]%32s():%4d faield to clone key\n","cw_priv_wsrv_para_new_create",0x1b2
                  );
          }
          FUN_00407df0(iVar2);
          iVar2 = iVar4;
          goto LAB_005cf3c4;
        }
        *(int *)(iVar4 + 8) = iVar5;
        goto switchD_005cf3e4_caseD_0;
      }
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cf3c4;
      __format = "[CW_ERROR]%32s():%4d failed to clone psk\n";
      uVar3 = 0x1a9;
    }
    break;
  case 2:
    iVar5 = *(int *)(param_1 + 9);
    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x4a) == 0)) {
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cf3c4;
      __format = "[CW_ERROR]%32s():%4d wpa is null or wpa\'s key is null\n";
      uVar3 = 0x1c1;
    }
    else {
      iVar4 = cw_protocol_clone(iVar5,0x4e);
      if (iVar4 != 0) {
        *(undefined4 *)(iVar4 + 0x4a) = 0;
        *(int *)(iVar2 + 9) = iVar4;
        iVar5 = cw_protocol_clone(*(undefined4 *)(iVar5 + 0x4a),*(undefined2 *)(iVar5 + 0x48));
        if (iVar5 == 0) {
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to clone wpa\n","cw_priv_wsrv_para_new_create",0x1d1
                  );
          }
          FUN_00407df0(iVar4);
          goto LAB_005cf3c4;
        }
        *(int *)(iVar4 + 0x4a) = iVar5;
        goto switchD_005cf3e4_caseD_0;
      }
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cf3c4;
      __format = "[CW_ERROR]%32s():%4d failed to clone wpa\n";
      uVar3 = 0x1c8;
    }
    break;
  case 3:
    if (*(int *)(param_1 + 9) == 0) {
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cf3c4;
      __format = "[CW_ERROR]%32s():%4d wep is null\n";
      uVar3 = 0x1df;
    }
    else {
      iVar5 = cw_protocol_clone(*(int *)(param_1 + 9),0x86);
      if (iVar5 != 0) {
        *(int *)(iVar2 + 9) = iVar5;
        goto switchD_005cf3e4_caseD_0;
      }
      if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(iVar2), iVar5 == 0))
      goto LAB_005cf3c4;
      __format = "[CW_ERROR]%32s():%4d failed to clone wep\n";
      uVar3 = 0x1e6;
    }
    break;
  default:
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(iVar2), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d Security Option(%d) is wrong\n","cw_priv_wsrv_para_new_create",
             0x1ef,(uint)*(byte *)(param_1 + 8));
    }
    goto LAB_005cf3c4;
  }
  printf(__format,"cw_priv_wsrv_para_new_create",uVar3);
LAB_005cf3c4:
  FUN_00407df0(iVar2);
  return 0;
}

