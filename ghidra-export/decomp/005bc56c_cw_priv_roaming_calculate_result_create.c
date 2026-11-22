// func cw_priv_roaming_calculate_result_create @ 005bc56c size=988

int cw_priv_roaming_calculate_result_create(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  if (0x80 < *(uint *)(param_1 + 4)) {
LAB_005bc5b8:
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u:%u]\n",
             "cw_priv_roaming_calculate_result_create",0x180,*(undefined4 *)(param_1 + 4),
             *(undefined4 *)(param_1 + 8));
    }
    return 0;
  }
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 >= 0x81) goto LAB_005bc5b8;
  if ((*(uint *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x10) == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d ret list is null\n";
    uVar7 = 0x186;
LAB_005bc888:
    printf(pcVar5,"cw_priv_roaming_calculate_result_create",uVar7);
    return 0;
  }
  if ((uVar2 != 0) && (*(int *)(param_1 + 0xc) == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap(uVar2 < 0x81,0x14);
    if (iVar3 == 0) {
      return 0;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d ap union is null\n";
    uVar7 = 0x18b;
    goto LAB_005bc888;
  }
  iVar3 = cw_protocol_clone(param_1);
  if (iVar3 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d failed to clone value\n";
    uVar7 = 0x194;
    goto LAB_005bc888;
  }
  *(undefined4 *)(iVar3 + 0xc) = 0;
  *(undefined4 *)(iVar3 + 0x10) = 0;
  if (*(int *)(param_1 + 8) == 0) {
    iVar4 = *(int *)(param_1 + 4);
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    iVar4 = *(int *)(param_1 + 4);
  }
  else {
    iVar4 = cw_protocol_clone(*(int *)(param_1 + 0xc),*(int *)(param_1 + 8) * 6 & 0xfffe);
    *(int *)(iVar3 + 0xc) = iVar4;
    if (iVar4 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone ap union list\n",
               "cw_priv_roaming_calculate_result_create",0x1a0);
      }
      goto LAB_005bc844;
    }
    iVar4 = *(int *)(param_1 + 4);
  }
  if ((iVar4 == 0) || (*(int *)(param_1 + 0x10) == 0)) {
LAB_005bc75c:
    uVar7 = cw_priv_roaming_calculate_result_length(iVar3);
    iVar4 = cw_protocol_msg_ele_create(0x59,uVar7,iVar3);
    if (iVar4 != 0) {
      return iVar4;
    }
    if (capwap_err_switch == 0) {
      iVar4 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar3 + 0xc);
      }
      else {
        pcVar5 = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
        uVar7 = 0x1c9;
LAB_005bc7b0:
        printf(pcVar5,"cw_priv_roaming_calculate_result_create",uVar7);
        iVar4 = *(int *)(iVar3 + 0xc);
      }
    }
  }
  else {
    iVar4 = cw_protocol_clone(*(int *)(param_1 + 0x10),iVar4 * 0x1c & 0xfffc);
    *(int *)(iVar3 + 0x10) = iVar4;
    if (iVar4 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(iVar3 + 0xc);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 != 0) {
          pcVar5 = "[CW_ERROR]%32s():%4d failed to clone ret list\n";
          uVar7 = 0x1ac;
          goto LAB_005bc7b0;
        }
        iVar4 = *(int *)(iVar3 + 0xc);
      }
    }
    else {
      bVar1 = false;
      uVar2 = 0;
      while (uVar2 < *(uint *)(param_1 + 4)) {
        iVar8 = uVar2 * 0x1c;
        *(undefined4 *)(*(int *)(iVar3 + 0x10) + iVar8 + 0x18) = 0;
        iVar4 = *(int *)(param_1 + 0x10) + iVar8;
        uVar6 = (uint)*(byte *)(iVar4 + 0x16);
        if (uVar6 == 0) {
          uVar2 = uVar2 + 1;
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x18);
          if (iVar4 == 0) {
            uVar2 = uVar2 + 1;
          }
          else {
            iVar9 = *(int *)(iVar3 + 0x10);
            uVar7 = cw_protocol_clone(iVar4,uVar6 * 10);
            *(undefined4 *)(iVar9 + iVar8 + 0x18) = uVar7;
            if (*(int *)(*(int *)(iVar3 + 0x10) + iVar8 + 0x18) == 0) {
              bVar1 = true;
            }
            uVar2 = uVar2 + 1;
          }
        }
      }
      if (!bVar1) goto LAB_005bc75c;
      iVar4 = *(int *)(iVar3 + 0xc);
    }
  }
  if (iVar4 == 0) {
    iVar4 = *(int *)(iVar3 + 0x10);
  }
  else {
    FUN_00407df0();
    iVar4 = *(int *)(iVar3 + 0x10);
  }
  uVar2 = 0;
  if (iVar4 != 0) {
    do {
      uVar6 = *(uint *)(iVar3 + 4);
      while( true ) {
        if (uVar6 <= uVar2) {
          FUN_00407df0();
          goto LAB_005bc844;
        }
        iVar4 = uVar2 * 0x1c;
        uVar2 = uVar2 + 1;
        if (*(int *)(*(int *)(iVar3 + 0x10) + iVar4 + 0x18) == 0) break;
        FUN_00407df0();
        uVar6 = *(uint *)(iVar3 + 4);
      }
    } while( true );
  }
LAB_005bc844:
  FUN_00407df0(iVar3);
  return 0;
}

