// func cw_priv_mesh_private_control_assemble @ 00578f20 size=4280

undefined4 cw_priv_mesh_private_control_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar6;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  char *pcVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  ushort *puVar13;
  short *psVar14;
  short sVar15;
  uint uVar16;
  int iVar17;
  
  uVar11 = *(undefined4 *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  uVar6 = FUN_00407fe0(uVar11);
  uVar16 = (uint)(short)uVar6;
  if (0x1b < uVar6 - 1) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[CW_ERROR]%32s():%4d Ele num(%d) is wrong\n";
    uVar11 = 0x33f;
LAB_005790a4:
    printf(pcVar7,"cw_priv_mesh_private_control_assemble",uVar11,uVar16);
    return 0xffffffff;
  }
  cw_protocol_restore16(param_1);
  iVar3 = FUN_004081b0(uVar11);
  do {
    if (iVar3 == 0) {
      uVar11 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar11 = 0;
      }
      return uVar11;
    }
    if (*(short *)(iVar3 + 0xe) == 0) {
      uVar2 = *(undefined2 *)(iVar3 + 0xc);
    }
    else {
      if (*(int *)(iVar3 + 0x10) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        pcVar7 = "[CW_ERROR]%32s():%4d Data can not be NULL for sub ele type(%d)\n";
        uVar11 = 0x348;
        goto LAB_005790a4;
      }
      uVar2 = *(undefined2 *)(iVar3 + 0xc);
    }
    cw_protocol_restore16(param_1,uVar2);
    cw_protocol_restore16(param_1,*(undefined2 *)(iVar3 + 0xe));
    switch(*(undefined2 *)(iVar3 + 0xc)) {
    case 0:
      if (*(short *)(iVar3 + 0xe) != 1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x352;
LAB_005795b8:
        printf(pcVar7,"cw_priv_mesh_private_control_assemble",uVar11,uVar10,uVar16);
        return 0xffffffff;
      }
      puVar8 = *(undefined1 **)(iVar3 + 0x10);
      goto LAB_00579238;
    case 1:
      puVar13 = *(ushort **)(iVar3 + 0x10);
      if ((uint)*puVar13 * 0x51 + 2 != (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x361;
        goto LAB_005795b8;
      }
      cw_protocol_restore16(param_1);
      iVar5 = 0;
      uVar16 = (uint)*puVar13;
      if (uVar16 != 0) {
        for (; iVar5 < (int)uVar16; iVar5 = iVar5 + 1) {
          iVar17 = *(int *)(puVar13 + 2) + iVar5 * 0x51;
          cw_protocol_restore_raw_bytes(param_1,iVar17,6);
          cw_protocol_restore8(param_1,*(undefined1 *)(iVar17 + 6));
          cw_protocol_restore8(param_1,*(undefined1 *)(iVar17 + 7));
          cw_protocol_restore_raw_bytes(param_1,iVar17 + 8,6);
          cw_protocol_restore_raw_bytes(param_1,iVar17 + 0xe,0x41);
          cw_protocol_restore8(param_1,*(undefined1 *)(iVar17 + 0x4f));
          cw_protocol_restore8(param_1,*(undefined1 *)(iVar17 + 0x50));
          uVar16 = (uint)*puVar13;
        }
      }
      break;
    case 2:
    case 8:
    case 9:
    case 0xb:
    case 0x13:
      puVar13 = *(ushort **)(iVar3 + 0x10);
      if ((uint)*puVar13 * 6 + 2 != (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x37e;
        goto LAB_005795b8;
      }
      cw_protocol_restore16(param_1);
      iVar5 = 0;
      uVar16 = (uint)*puVar13;
      if (uVar16 != 0) {
        for (; iVar5 < (int)uVar16; iVar5 = iVar5 + 1) {
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar13 + 2) + iVar5 * 6,6);
          uVar16 = (uint)*puVar13;
        }
      }
      break;
    case 3:
    case 0xd:
      if (*(short *)(iVar3 + 0xe) != 10) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x3bd;
        goto LAB_005795b8;
      }
      iVar5 = *(int *)(iVar3 + 0x10);
      cw_protocol_restore_raw_bytes(param_1,iVar5,6);
      uVar11 = *(undefined4 *)(iVar5 + 8);
      goto LAB_005790e0;
    case 4:
    case 5:
      iVar5 = *(int *)(iVar3 + 0x10);
      cw_protocol_restore_raw_bytes(param_1,iVar5,6);
      sVar15 = 6;
      for (iVar5 = FUN_004081b0(iVar5 + 8); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
        puVar13 = (ushort *)cw_msg_ele_mngr_get(*(undefined2 *)(iVar5 + 0xc));
        if (puVar13 == (ushort *)0x0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          uVar16 = (uint)*(ushort *)(iVar5 + 0xc);
          pcVar7 = "[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n";
          uVar11 = 0x3d6;
          goto LAB_005790a4;
        }
        if (*(int *)(iVar5 + 0x10) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          uVar16 = (uint)*puVar13;
          uVar10 = *(uint *)(puVar13 + 2);
          pcVar7 = "[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value \r\n\n";
          uVar11 = 0x3dc;
          goto LAB_005795b8;
        }
        if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) <
            (int)(*(ushort *)(iVar5 + 0xe) + 4)) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          printf("[CW_ERROR]%32s():%4d packet buffer isn\'t enough\n",
                 "cw_priv_mesh_private_control_assemble",0x3e2);
          return 0xffffffff;
        }
        cw_msg_ele_format_assemble(param_1,*(undefined2 *)(iVar5 + 0xc));
        iVar17 = (**(code **)(puVar13 + 8))(param_1,iVar5);
        if (iVar17 == -1) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          uVar16 = (uint)*puVar13;
          uVar10 = *(uint *)(puVar13 + 2);
          pcVar7 = "[CW_ERROR]%32s():%4d failed to assemble %s(%d)\n";
          uVar11 = 0x3ea;
          goto LAB_005795b8;
        }
        sVar15 = sVar15 + *(short *)(iVar5 + 0xe) + 4;
      }
      if (*(short *)(iVar3 + 0xe) != sVar15) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x3f1;
        goto LAB_005795b8;
      }
      break;
    case 6:
      puVar13 = *(ushort **)(iVar3 + 0x10);
      if ((uint)*puVar13 * 0x26 + 2 != (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x3fb;
        goto LAB_005795b8;
      }
      cw_protocol_restore16(param_1);
      if (*puVar13 != 0) {
        if (*(int *)(puVar13 + 2) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
          pcVar7 = "[CW_ERROR]%32s():%4d Illegal dev_info for sub ele type(%d)\n";
          uVar11 = 0x403;
          goto LAB_005790a4;
        }
        for (iVar5 = 0; iVar5 < (int)(uint)*puVar13; iVar5 = iVar5 + 1) {
          iVar17 = iVar5 * 0x40;
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar13 + 2) + iVar17,6);
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(puVar13 + 2) + iVar17 + 0xc));
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar13 + 2) + iVar17 + 0x20,0x10);
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar13 + 2) + iVar17 + 0x30));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar13 + 2) + iVar17 + 0x31));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(puVar13 + 2) + iVar17 + 0x34));
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar13 + 2) + iVar17 + 0x38,6);
        }
      }
      break;
    case 7:
      puVar8 = *(undefined1 **)(iVar3 + 0x10);
      if ((uint)*(ushort *)(puVar8 + 2) * 0x26 + 3 != (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x418;
        goto LAB_005795b8;
      }
      cw_protocol_restore8(param_1,*puVar8);
      cw_protocol_restore16(param_1,*(undefined2 *)(puVar8 + 2));
      if (*(short *)(puVar8 + 2) != 0) {
        if (*(int *)(puVar8 + 4) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
          pcVar7 = "[CW_ERROR]%32s():%4d Illegal dev_info for sub ele type(%d)\n";
          uVar11 = 0x421;
          goto LAB_005790a4;
        }
        for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(puVar8 + 2); iVar5 = iVar5 + 1) {
          iVar17 = iVar5 * 0x40;
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar8 + 4) + iVar17,6);
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(puVar8 + 4) + iVar17 + 0xc));
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar8 + 4) + iVar17 + 0x20,0x10);
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar8 + 4) + iVar17 + 0x30));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar8 + 4) + iVar17 + 0x31));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(puVar8 + 4) + iVar17 + 0x34));
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar8 + 4) + iVar17 + 0x38,6);
        }
      }
      break;
    case 10:
      iVar5 = *(int *)(iVar3 + 0x10);
      if (*(short *)(iVar5 + 0x20) + 0x24 + (int)*(short *)(iVar5 + 0x28) !=
          (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x436;
        goto LAB_005795b8;
      }
      cw_protocol_restore_raw_bytes(param_1,iVar5,0x20);
      cw_protocol_restore16(param_1,*(undefined2 *)(iVar5 + 0x20));
      if (*(short *)(iVar5 + 0x20) < 1) {
        uVar2 = *(undefined2 *)(iVar5 + 0x28);
      }
      else {
        if (*(int *)(iVar5 + 0x24) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
          pcVar7 = "[CW_ERROR]%32s():%4d Illegal key for sub ele type(%d)\n";
          uVar11 = 0x43f;
          goto LAB_005790a4;
        }
        cw_protocol_restore_raw_bytes(param_1,*(int *)(iVar5 + 0x24),*(short *)(iVar5 + 0x20));
        uVar2 = *(undefined2 *)(iVar5 + 0x28);
      }
      cw_protocol_restore16(param_1,uVar2);
      uVar16 = (uint)*(short *)(iVar5 + 0x28);
      if (0 < (int)uVar16) {
        puVar8 = *(undefined1 **)(iVar5 + 0x2c);
        if (puVar8 != (undefined1 *)0x0) {
LAB_00579560:
          uVar16 = uVar16 & 0xffff;
          goto LAB_00579060;
        }
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal key for sub ele type(%d)\n";
        uVar11 = 0x449;
        goto LAB_005790a4;
      }
      break;
    case 0xc:
      if (*(short *)(iVar3 + 0xe) != 7) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x3b0;
        goto LAB_005795b8;
      }
      iVar5 = *(int *)(iVar3 + 0x10);
      cw_protocol_restore_raw_bytes(param_1,iVar5,6);
      uVar9 = *(undefined1 *)(iVar5 + 6);
      goto LAB_00579240;
    case 0xe:
      if (*(short *)(iVar3 + 0xe) != 2) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x3a3;
        goto LAB_005795b8;
      }
      puVar8 = *(undefined1 **)(iVar3 + 0x10);
      goto LAB_00579488;
    case 0xf:
      psVar14 = *(short **)(iVar3 + 0x10);
      if ((int)*psVar14 + 2U != (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x455;
        goto LAB_005795b8;
      }
      cw_protocol_restore16(param_1,*psVar14);
      uVar16 = (uint)*psVar14;
      if (0 < (int)uVar16) {
        puVar8 = *(undefined1 **)(psVar14 + 2);
        if (puVar8 != (undefined1 *)0x0) goto LAB_00579560;
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal key for sub ele type(%d)\n";
        uVar11 = 0x45d;
        goto LAB_005790a4;
      }
      break;
    case 0x10:
      puVar8 = *(undefined1 **)(iVar3 + 0x10);
      if (*(short *)(iVar3 + 0xe) != 7) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x469;
        goto LAB_005795b8;
      }
      cw_protocol_restore8(param_1,*puVar8);
      puVar8 = puVar8 + 1;
      uVar16 = 6;
LAB_00579060:
      cw_protocol_restore_raw_bytes(param_1,puVar8,uVar16);
      break;
    case 0x11:
      if (*(short *)(iVar3 + 0xe) != 2) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x473;
        goto LAB_005795b8;
      }
      puVar4 = *(undefined2 **)(iVar3 + 0x10);
      goto LAB_005793f0;
    case 0x12:
      if (*(short *)(iVar3 + 0xe) != 2) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x489;
        goto LAB_005795b8;
      }
      puVar8 = *(undefined1 **)(iVar3 + 0x10);
LAB_00579488:
      cw_protocol_restore8(param_1,*puVar8);
      uVar9 = puVar8[1];
      goto LAB_00579240;
    case 0x14:
      puVar13 = *(ushort **)(iVar3 + 0x10);
      if ((*puVar13 + 1) * 6 != (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x391;
        goto LAB_005795b8;
      }
      cw_protocol_restore16(param_1);
      iVar5 = 0;
      uVar16 = (uint)*puVar13;
      if (uVar16 == 0) {
        uVar11 = *(undefined4 *)(puVar13 + 4);
      }
      else {
        for (; iVar5 < (int)uVar16; iVar5 = iVar5 + 1) {
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar13 + 2) + iVar5 * 6,6);
          uVar16 = (uint)*puVar13;
        }
        uVar11 = *(undefined4 *)(puVar13 + 4);
      }
      goto LAB_005790e0;
    case 0x15:
      if (*(short *)(iVar3 + 0xe) != 2) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x47e;
        goto LAB_005795b8;
      }
      puVar4 = *(undefined2 **)(iVar3 + 0x10);
LAB_005793f0:
      cw_protocol_restore16(param_1,*puVar4);
      break;
    case 0x16:
      puVar13 = *(ushort **)(iVar3 + 0x10);
      if ((uint)*puVar13 * 0xd + 2 != (uint)*(ushort *)(iVar3 + 0xe)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x497;
        goto LAB_005795b8;
      }
      cw_protocol_restore16(param_1);
      uVar16 = (uint)*puVar13;
      iVar5 = 0;
      if (uVar16 != 0) {
        for (; iVar5 < (int)uVar16; iVar5 = iVar5 + 1) {
          iVar17 = iVar5 * 0x10;
          cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar13 + 2) + iVar17,6);
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar13 + 2) + iVar17 + 6));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar13 + 2) + iVar17 + 7));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(puVar13 + 2) + iVar17 + 8));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar13 + 2) + iVar17 + 0xc));
          uVar16 = (uint)*puVar13;
        }
      }
      break;
    case 0x17:
      if (*(short *)(iVar3 + 0xe) != 1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x4ab;
        goto LAB_005795b8;
      }
      puVar8 = *(undefined1 **)(iVar3 + 0x10);
      goto LAB_00579238;
    case 0x18:
      puVar8 = *(undefined1 **)(iVar3 + 0x10);
      if (*(short *)(iVar3 + 0xe) != 1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x4b8;
        goto LAB_005795b8;
      }
LAB_00579238:
      uVar9 = *puVar8;
LAB_00579240:
      cw_protocol_restore8(param_1,uVar9);
      break;
    default:
      if (capwap_warning_switch == 0) {
        uVar16 = (uint)*(ushort *)(iVar3 + 0xe);
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          uVar16 = (uint)*(ushort *)(iVar3 + 0xe);
        }
        else {
          printf("[CW_WARNING]%32s():%4d Unrecognize sub ele type(%d)\n",
                 "cw_priv_mesh_private_control_assemble",0x4cb,(uint)*(ushort *)(iVar3 + 0xc));
          uVar16 = (uint)*(ushort *)(iVar3 + 0xe);
        }
      }
      if ((uVar16 != 0) && (puVar8 = *(undefined1 **)(iVar3 + 0x10), puVar8 != (undefined1 *)0x0))
      goto LAB_00579060;
      break;
    case 0x1b:
      puVar12 = *(undefined4 **)(iVar3 + 0x10);
      if (*(short *)(iVar3 + 0xe) != 8) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        uVar16 = (uint)*(ushort *)(iVar3 + 0xc);
        uVar10 = (uint)*(ushort *)(iVar3 + 0xe);
        pcVar7 = "[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n";
        uVar11 = 0x4c3;
        goto LAB_005795b8;
      }
      cw_protocol_restore32(param_1,*puVar12);
      uVar11 = puVar12[1];
LAB_005790e0:
      cw_protocol_restore32(param_1,uVar11);
    }
    iVar3 = FUN_00408680(iVar3);
  } while( true );
}

