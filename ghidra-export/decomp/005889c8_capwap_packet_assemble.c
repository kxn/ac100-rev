// func capwap_packet_assemble @ 005889c8 size=1380

undefined4 capwap_packet_assemble(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  if (((param_1 == (int *)0x0) || (param_2 == 0)) || (*param_1 == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[CW_ERROR]%32s():%4d input parameter is wrong\n";
    uVar9 = 0x6da;
  }
  else {
    uVar1 = *(ushort *)(param_2 + 0x16);
    iVar2 = cw_msg_eles_length_count(param_2);
    if ((uint)uVar1 != iVar2 + 3U) {
      uVar9 = 0xffffffff;
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_eles_length_count(param_2);
      uVar5 = (uint)*(ushort *)(param_2 + 0x16);
      pcVar6 = 
      "[CW_ERROR]%32s():%4d message elements\' total length[%d] is not equal to control header\'s length[%d]\n"
      ;
      uVar7 = 0x6e2;
      iVar2 = iVar2 + 3;
LAB_00588b60:
      printf(pcVar6,"capwap_packet_assemble",uVar7,iVar2,uVar5);
      return uVar9;
    }
    iVar2 = (*(byte *)(param_2 + 2) + 2) * 4 + (uint)*(ushort *)(param_2 + 0x16) + -3;
    if (param_1[2] < iVar2) {
      FUN_00407df0(*param_1);
      iVar3 = FUN_00408450(iVar2,0x6eb);
      *param_1 = iVar3;
      if (iVar3 == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar6 = "[CW_ERROR]%32s():%4d malloc failed.\n";
        uVar9 = 0x6ee;
        goto LAB_00588a90;
      }
      param_1[2] = iVar2;
    }
    iVar2 = cw_header_assemble(param_1,param_2);
    if (iVar2 == -1) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[CW_ERROR]%32s():%4d failed to assemble capwap header\n";
      uVar9 = 0x6f7;
    }
    else {
      iVar2 = cw_control_header_assemble(param_1,param_2 + 0x10);
      if (iVar2 != -1) {
        for (iVar2 = FUN_004081b0(param_2 + 0x1c); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
          puVar4 = (ushort *)cw_msg_ele_mngr_get(*(undefined2 *)(iVar2 + 0xc));
          if (puVar4 == (ushort *)0x0) {
            if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                     "cw_msg_eles_assemble",0x109,(uint)*(ushort *)(iVar2 + 0xc));
            }
            goto LAB_00588bf8;
          }
          if (*puVar4 != *(ushort *)(iVar2 + 0xc)) {
            if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              uVar5 = (uint)*puVar4;
              uVar8 = (uint)*(ushort *)(iVar2 + 0xc);
              pcVar6 = 
              "[CW_ERROR]%32s():%4d capwap message type(%d) doesn\'t match manager\'s type(%d)\n";
              uVar9 = 0x61;
LAB_00588cb4:
              printf(pcVar6,"cw_msg_ele_check",uVar9,uVar8,uVar5);
            }
LAB_00588bd8:
            if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar6 = "[CW_ERROR]%32s():%4d capwap message element doesn\'t match manager\n";
              uVar9 = 0x10f;
LAB_00588e7c:
              printf(pcVar6,"cw_msg_eles_assemble",uVar9);
            }
LAB_00588bf8:
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              return 0xffffffff;
            }
            pcVar6 = "[CW_ERROR]%32s():%4d failed to assemble capwap message elements\n";
            uVar9 = 0x705;
            goto LAB_00588a90;
          }
          uVar5 = (uint)*(ushort *)(iVar2 + 0xe);
          if (uVar5 < puVar4[4]) {
            if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar5 = (uint)*puVar4;
              uVar8 = *(uint *)(puVar4 + 2);
              pcVar6 = "[CW_ERROR]%32s():%4d the length of %s(%d) is too short\n";
              uVar9 = 0x67;
              goto LAB_00588cb4;
            }
            goto LAB_00588bd8;
          }
          if (puVar4[5] < uVar5) {
            if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar5 = (uint)*puVar4;
              uVar8 = *(uint *)(puVar4 + 2);
              pcVar6 = "[CW_ERROR]%32s():%4d the length of %s(%d) is too long\n";
              uVar9 = 0x6c;
              goto LAB_00588cb4;
            }
            goto LAB_00588bd8;
          }
          if (*(int *)(iVar2 + 0x10) == 0) {
            if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar1 = *puVar4;
              uVar7 = *(undefined4 *)(puVar4 + 2);
              pcVar6 = "[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value \r\n\n";
              uVar9 = 0x115;
LAB_00588ec8:
              printf(pcVar6,"cw_msg_eles_assemble",uVar9,uVar7,(uint)uVar1);
            }
            goto LAB_00588bf8;
          }
          if ((int)(param_1[2] - (uint)*(ushort *)(param_1 + 1)) < (int)(uVar5 + 4)) {
            if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_00588bf8;
            pcVar6 = "[CW_ERROR]%32s():%4d packet buffer isn\'t enough\n";
            uVar9 = 0x11b;
            goto LAB_00588e7c;
          }
          cw_msg_ele_format_assemble(param_1);
          iVar3 = (**(code **)(puVar4 + 8))(param_1,iVar2);
          if (iVar3 == -1) {
            if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar1 = *puVar4;
              uVar7 = *(undefined4 *)(puVar4 + 2);
              pcVar6 = "[CW_ERROR]%32s():%4d failed to assemble %s(%d)\n";
              uVar9 = 0x123;
              goto LAB_00588ec8;
            }
            goto LAB_00588bf8;
          }
        }
        uVar9 = 0;
        if (capwap_debug_switch == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = cw_control_msg_name(*(undefined4 *)(param_2 + 0x10));
        uVar5 = *(uint *)(param_2 + 0x10);
        pcVar6 = "[CW_DEBUG]%32s():%4d success to assemble %s(%d)\n";
        uVar7 = 0x70a;
        goto LAB_00588b60;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[CW_ERROR]%32s():%4d failed to assemble capwap control header\n";
      uVar9 = 0x6fe;
    }
  }
LAB_00588a90:
  printf(pcVar6,"capwap_packet_assemble",uVar9);
  return 0xffffffff;
}

