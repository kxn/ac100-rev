// func cw_priv_mesh_public_control_assemble @ 005b60c0 size=836

undefined4 cw_priv_mesh_public_control_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int iVar8;
  
  puVar7 = *(ushort **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*puVar7 - 1 < 100) && (*(int *)(puVar7 + 2) != 0)) {
    cw_protocol_restore16();
    for (iVar8 = 0; iVar8 < (int)(uint)*puVar7; iVar8 = iVar8 + 1) {
      cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar7 + 2) + iVar8 * 6,6);
    }
    cw_protocol_restore16(param_1,puVar7[4]);
    for (iVar8 = FUN_004081b0(puVar7 + 6); iVar8 != 0; iVar8 = FUN_00408680(iVar8)) {
      puVar7 = (ushort *)cw_msg_ele_mngr_get(*(undefined2 *)(iVar8 + 0xc));
      if (puVar7 == (ushort *)0x0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        uVar1 = *(ushort *)(iVar8 + 0xc);
        pcVar4 = "[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n";
        uVar6 = 0x119;
        goto LAB_005b6254;
      }
      uVar5 = (uint)*(ushort *)(iVar8 + 0xe);
      if (uVar5 < puVar7[4]) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        uVar5 = (uint)*puVar7;
        uVar6 = *(undefined4 *)(puVar7 + 2);
        pcVar4 = "[CW_ERROR]%32s():%4d the length of %s(%d) is too short\n";
        uVar3 = 0x11e;
LAB_005b62f8:
        printf(pcVar4,"cw_priv_mesh_public_control_assemble",uVar3,uVar6,uVar5);
        return 0xffffffff;
      }
      if (puVar7[5] < uVar5) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        uVar5 = (uint)*puVar7;
        uVar6 = *(undefined4 *)(puVar7 + 2);
        pcVar4 = "[CW_ERROR]%32s():%4d the length of %s(%d) is too long\n";
        uVar3 = 0x123;
        goto LAB_005b62f8;
      }
      if (*(int *)(iVar8 + 0x10) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        uVar5 = (uint)*puVar7;
        uVar6 = *(undefined4 *)(puVar7 + 2);
        pcVar4 = "[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value \r\n\n";
        uVar3 = 0x129;
        goto LAB_005b62f8;
      }
      if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) < (int)(uVar5 + 4)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d packet buffer isn\'t enough\n",
               "cw_priv_mesh_public_control_assemble",0x12f);
        return 0xffffffff;
      }
      cw_msg_ele_format_assemble(param_1,*(undefined2 *)(iVar8 + 0xc));
      iVar2 = (**(code **)(puVar7 + 8))(param_1,iVar8);
      if (iVar2 == -1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        uVar5 = (uint)*puVar7;
        uVar6 = *(undefined4 *)(puVar7 + 2);
        pcVar4 = "[CW_ERROR]%32s():%4d failed to assemble %s(%d)\n";
        uVar3 = 0x137;
        goto LAB_005b62f8;
      }
    }
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      uVar1 = *puVar7;
      pcVar4 = "[CW_ERROR]%32s():%4d ap count(%d) is wrong or mac list is NULL\n";
      uVar6 = 0x106;
LAB_005b6254:
      uVar3 = 0xffffffff;
      printf(pcVar4,"cw_priv_mesh_public_control_assemble",uVar6,(uint)uVar1);
    }
  }
  return uVar3;
}

