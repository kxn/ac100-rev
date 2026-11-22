// func cw_priv_roaming_trigger_create @ 005bd9fc size=748

int cw_priv_roaming_trigger_create(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  if (200 < *(uint *)(param_1 + 4)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_roaming_trigger_create",0x149,
           *(undefined4 *)(param_1 + 4));
    return 0;
  }
  if ((*(uint *)(param_1 + 4) != 0) && (*(int *)(param_1 + 8) == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap(param_1,0xc);
    if (iVar2 == 0) {
      return 0;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d station list is null\n";
    uVar4 = 0x14f;
LAB_005bdc6c:
    printf(pcVar5,"cw_priv_roaming_trigger_create",uVar4);
    return 0;
  }
  iVar2 = cw_protocol_clone(param_1);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d failed to clone value\n";
    uVar4 = 0x157;
    goto LAB_005bdc6c;
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  if ((*(uint *)(param_1 + 4) == 0) || (*(int *)(param_1 + 8) == 0)) {
LAB_005bdb5c:
    uVar4 = cw_priv_roaming_trigger_length(iVar2);
    iVar3 = cw_protocol_msg_ele_create(0x58,uVar4,iVar2);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (capwap_err_switch == 0) {
      iVar3 = *(int *)(iVar2 + 8);
      goto LAB_005bdb90;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      iVar3 = *(int *)(iVar2 + 8);
      goto LAB_005bdb90;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
    uVar4 = 0x17f;
  }
  else {
    iVar3 = cw_protocol_clone(*(int *)(param_1 + 8),(*(uint *)(param_1 + 4) & 0xfff) << 4);
    *(int *)(iVar2 + 8) = iVar3;
    if (iVar3 != 0) {
      bVar1 = false;
      uVar8 = 0;
      while (uVar8 < *(uint *)(param_1 + 4)) {
        iVar7 = uVar8 * 0x10;
        *(undefined4 *)(*(int *)(iVar2 + 8) + iVar7 + 0xc) = 0;
        iVar3 = *(int *)(param_1 + 8) + iVar7;
        uVar6 = (uint)*(byte *)(iVar3 + 9);
        if (uVar6 == 0) {
          uVar8 = uVar8 + 1;
        }
        else {
          iVar3 = *(int *)(iVar3 + 0xc);
          if (iVar3 == 0) {
            uVar8 = uVar8 + 1;
          }
          else {
            iVar9 = *(int *)(iVar2 + 8);
            uVar4 = cw_protocol_clone(iVar3,uVar6 * 9);
            *(undefined4 *)(iVar9 + iVar7 + 0xc) = uVar4;
            if (*(int *)(*(int *)(iVar2 + 8) + iVar7 + 0xc) == 0) {
              bVar1 = true;
            }
            uVar8 = uVar8 + 1;
          }
        }
      }
      if (bVar1) {
        iVar3 = *(int *)(iVar2 + 8);
        goto LAB_005bdb90;
      }
      goto LAB_005bdb5c;
    }
    if (capwap_err_switch == 0) {
      iVar3 = *(int *)(iVar2 + 8);
      goto LAB_005bdb90;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      iVar3 = *(int *)(iVar2 + 8);
      goto LAB_005bdb90;
    }
    pcVar5 = "[CW_ERROR]%32s():%4d failed to clone station list\n";
    uVar4 = 0x162;
  }
  printf(pcVar5,"cw_priv_roaming_trigger_create",uVar4);
  iVar3 = *(int *)(iVar2 + 8);
LAB_005bdb90:
  uVar8 = 0;
  if (iVar3 == 0) {
LAB_005bdbf4:
    FUN_00407df0(iVar2);
    return 0;
  }
  do {
    uVar6 = *(uint *)(iVar2 + 4);
    while( true ) {
      if (uVar6 <= uVar8) {
        FUN_00407df0();
        goto LAB_005bdbf4;
      }
      iVar3 = uVar8 * 0x10;
      uVar8 = uVar8 + 1;
      if (*(int *)(*(int *)(iVar2 + 8) + iVar3 + 0xc) == 0) break;
      FUN_00407df0();
      uVar6 = *(uint *)(iVar2 + 4);
    }
  } while( true );
}

