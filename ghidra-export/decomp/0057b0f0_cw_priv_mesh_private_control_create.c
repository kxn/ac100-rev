// func cw_priv_mesh_private_control_create @ 0057b0f0 size=3196

int cw_priv_mesh_private_control_create(undefined4 param_1)

{
  ushort uVar1;
  short sVar8;
  int iVar2;
  int iVar3;
  short sVar9;
  ushort *puVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  char *pcVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  
  sVar8 = FUN_00407fe0();
  if (((int)sVar8 - 1U & 0xffff) < 0x1c) {
    iVar2 = cw_protocol_clone(param_1,0xc);
    if (iVar2 == 0) {
      iVar13 = 0;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_mesh_private_control_create",
               0x4ef);
      }
    }
    else {
      FUN_0051ad88(iVar2);
      sVar8 = 2;
      for (iVar13 = FUN_004081b0(param_1); iVar13 != 0; iVar13 = FUN_00408680(iVar13)) {
        iVar3 = cw_protocol_clone(iVar13,0x14);
        FUN_004086b0(iVar2,iVar3);
        *(undefined4 *)(iVar3 + 0x10) = 0;
        switch(*(undefined2 *)(iVar13 + 0xc)) {
        case 0:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),1);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x501;
            goto LAB_0057b95c;
          }
          break;
        case 1:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),8);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x50a;
            goto LAB_0057b95c;
          }
          psVar5 = *(short **)(iVar13 + 0x10);
          *(undefined4 *)(iVar7 + 4) = 0;
          sVar9 = *psVar5;
          if (sVar9 == 0) {
            sVar9 = *(short *)(iVar13 + 0xe);
            goto LAB_0057b214;
          }
          iVar3 = cw_protocol_clone(*(undefined4 *)(psVar5 + 2),sVar9 * 0x51);
          *(int *)(iVar7 + 4) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x515;
            goto LAB_0057b95c;
          }
          break;
        case 2:
        case 8:
        case 9:
        case 0xb:
        case 0x13:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),8);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x523;
            goto LAB_0057b95c;
          }
          psVar5 = *(short **)(iVar13 + 0x10);
          *(undefined4 *)(iVar7 + 4) = 0;
          sVar9 = *psVar5;
          if (sVar9 == 0) {
            sVar9 = *(short *)(iVar13 + 0xe);
            goto LAB_0057b214;
          }
          iVar3 = cw_protocol_clone(*(undefined4 *)(psVar5 + 2),sVar9 * 6);
          *(int *)(iVar7 + 4) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x52e;
            goto LAB_0057b95c;
          }
          break;
        case 3:
        case 0xd:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),0xc);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x561;
            goto LAB_0057b95c;
          }
          break;
        case 4:
        case 5:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),0x14);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x56b;
            goto LAB_0057b95c;
          }
          iVar3 = *(int *)(iVar13 + 0x10);
          FUN_0051ad88(iVar7 + 8);
          for (iVar3 = FUN_004081b0(iVar3 + 8); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
            uVar1 = *(ushort *)(iVar3 + 0xc);
            uVar12 = *(undefined4 *)(iVar3 + 0x10);
            iVar6 = cw_msg_ele_mngr_get((uint)uVar1);
            if (iVar6 == 0) {
              if ((capwap_err_switch != 0) && (iVar13 = is_target_debug_ap(), iVar13 != 0)) {
                pcVar10 = "[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n";
                uVar12 = 0x57d;
LAB_0057baec:
                printf(pcVar10,"cw_priv_mesh_private_control_create",uVar12,(uint)uVar1);
              }
              goto LAB_0057b9f4;
            }
            iVar6 = (**(code **)(iVar6 + 0x14))(uVar12);
            if (iVar6 == 0) {
              if ((capwap_err_switch != 0) && (iVar13 = is_target_debug_ap(), iVar13 != 0)) {
                pcVar10 = "[CW_ERROR]%32s():%4d failed to create message element(%d)\n";
                uVar12 = 0x585;
                goto LAB_0057baec;
              }
              goto LAB_0057b9f4;
            }
            FUN_004086b0(iVar7 + 8,iVar6);
          }
          break;
        case 6:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),8);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x593;
            goto LAB_0057b95c;
          }
          puVar4 = *(ushort **)(iVar13 + 0x10);
          *(undefined4 *)(iVar7 + 4) = 0;
          uVar11 = (uint)*puVar4;
          if (uVar11 == 0) {
            sVar9 = *(short *)(iVar13 + 0xe);
            goto LAB_0057b214;
          }
          iVar3 = cw_protocol_clone(*(undefined4 *)(puVar4 + 2),(uVar11 & 0x3ff) << 6);
          *(int *)(iVar7 + 4) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x59e;
            goto LAB_0057b95c;
          }
          break;
        case 7:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),8);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x5a9;
            goto LAB_0057b95c;
          }
          iVar3 = *(int *)(iVar13 + 0x10);
          *(undefined4 *)(iVar7 + 4) = 0;
          uVar11 = (uint)*(ushort *)(iVar3 + 2);
          if (uVar11 == 0) {
            sVar9 = *(short *)(iVar13 + 0xe);
            goto LAB_0057b214;
          }
          iVar3 = cw_protocol_clone(*(undefined4 *)(iVar3 + 4),(uVar11 & 0x3ff) << 6);
          *(int *)(iVar7 + 4) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x5b4;
            goto LAB_0057b95c;
          }
          break;
        case 10:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),0x30);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 != 0) {
            iVar3 = *(int *)(iVar13 + 0x10);
            *(undefined4 *)(iVar7 + 0x24) = 0;
            *(undefined4 *)(iVar7 + 0x2c) = 0;
            if (*(short *)(iVar3 + 0x20) < 1) {
              sVar9 = *(short *)(iVar3 + 0x28);
            }
            else {
              iVar6 = cw_protocol_clone(*(undefined4 *)(iVar3 + 0x24),*(short *)(iVar3 + 0x20));
              *(int *)(iVar7 + 0x24) = iVar6;
              if (iVar6 == 0) {
                if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
                goto LAB_0057b9f4;
                pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
                uVar12 = 0x5cb;
                goto LAB_0057b95c;
              }
              sVar9 = *(short *)(iVar3 + 0x28);
            }
            if (sVar9 < 1) {
              sVar9 = *(short *)(iVar13 + 0xe);
              goto LAB_0057b214;
            }
            iVar3 = cw_protocol_clone(*(undefined4 *)(iVar3 + 0x2c),sVar9);
            *(int *)(iVar7 + 0x2c) = iVar3;
            if (iVar3 != 0) break;
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x5d4;
            goto LAB_0057b95c;
          }
          if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
          goto LAB_0057b9f4;
          pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
          uVar12 = 0x5bf;
          goto LAB_0057b95c;
        case 0xc:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),7);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x558;
            goto LAB_0057b95c;
          }
          break;
        case 0xe:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),2);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x54f;
            goto LAB_0057b95c;
          }
          break;
        case 0xf:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),8);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x5df;
            goto LAB_0057b95c;
          }
          psVar5 = *(short **)(iVar13 + 0x10);
          *(undefined4 *)(iVar7 + 4) = 0;
          sVar9 = *psVar5;
          if (sVar9 < 1) {
            sVar9 = *(short *)(iVar13 + 0xe);
            goto LAB_0057b214;
          }
          iVar3 = cw_protocol_clone(*(undefined4 *)(psVar5 + 2),sVar9);
          *(int *)(iVar7 + 4) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x5ea;
            goto LAB_0057b95c;
          }
          break;
        case 0x10:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),7);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x5f5;
            goto LAB_0057b95c;
          }
          break;
        case 0x11:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),2);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x5ff;
            goto LAB_0057b95c;
          }
          break;
        case 0x12:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),2);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x613;
            goto LAB_0057b95c;
          }
          break;
        case 0x14:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),0xc);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x539;
            goto LAB_0057b95c;
          }
          psVar5 = *(short **)(iVar13 + 0x10);
          *(undefined4 *)(iVar7 + 4) = 0;
          sVar9 = *psVar5;
          if (sVar9 == 0) {
            sVar9 = *(short *)(iVar13 + 0xe);
            goto LAB_0057b214;
          }
          iVar3 = cw_protocol_clone(*(undefined4 *)(psVar5 + 2),sVar9 * 6);
          *(int *)(iVar7 + 4) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x544;
            goto LAB_0057b95c;
          }
          break;
        case 0x15:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),2);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x609;
            goto LAB_0057b95c;
          }
          break;
        case 0x16:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),8);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x61d;
            goto LAB_0057b95c;
          }
          puVar4 = *(ushort **)(iVar13 + 0x10);
          *(undefined4 *)(iVar7 + 4) = 0;
          uVar11 = (uint)*puVar4;
          if (uVar11 == 0) {
            sVar9 = *(short *)(iVar13 + 0xe);
            goto LAB_0057b214;
          }
          iVar3 = cw_protocol_clone(*(undefined4 *)(puVar4 + 2),(uVar11 & 0xfff) << 4);
          *(int *)(iVar7 + 4) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x628;
            goto LAB_0057b95c;
          }
          break;
        case 0x17:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),1);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x633;
            goto LAB_0057b95c;
          }
          break;
        case 0x18:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),1);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x63d;
            goto LAB_0057b95c;
          }
          break;
        default:
          if (capwap_warning_switch == 0) {
            sVar9 = *(short *)(iVar13 + 0xe);
          }
          else {
            iVar7 = is_target_debug_ap();
            if (iVar7 == 0) {
              sVar9 = *(short *)(iVar13 + 0xe);
            }
            else {
              printf("[CW_WARNING]%32s():%4d Unrecognize sub ele type(%d)\n",
                     "cw_priv_mesh_private_control_create",0x64d,(uint)*(ushort *)(iVar13 + 0xc));
              sVar9 = *(short *)(iVar13 + 0xe);
            }
          }
          if (sVar9 != 0) {
            iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10));
            *(int *)(iVar3 + 0x10) = iVar7;
            if (iVar7 == 0) {
              if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
              goto LAB_0057b9f4;
              pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
              uVar12 = 0x653;
              goto LAB_0057b95c;
            }
          }
          break;
        case 0x1b:
          iVar7 = cw_protocol_clone(*(undefined4 *)(iVar13 + 0x10),8);
          *(int *)(iVar3 + 0x10) = iVar7;
          if (iVar7 == 0) {
            if ((capwap_err_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
            goto LAB_0057b9f4;
            pcVar10 = "[CW_ERROR]%32s():%4d Malloc failed\n";
            uVar12 = 0x647;
            goto LAB_0057b95c;
          }
        }
        sVar9 = *(short *)(iVar13 + 0xe);
LAB_0057b214:
        sVar8 = sVar9 + 4 + sVar8;
      }
      iVar13 = cw_protocol_msg_ele_create(0x76,sVar8,iVar2);
      if (iVar13 == 0) {
        if ((capwap_err_switch != 0) && (iVar13 = is_target_debug_ap(), iVar13 != 0)) {
          pcVar10 = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
          uVar12 = 0x660;
LAB_0057b95c:
          printf(pcVar10,"cw_priv_mesh_private_control_create",uVar12);
        }
LAB_0057b9f4:
        cw_priv_mesh_private_control_val_destroy(iVar2);
        iVar13 = 0;
      }
    }
  }
  else {
    iVar13 = 0;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d Ele num(%d) is wrong or mac list is NULL\n",
             "cw_priv_mesh_private_control_create",0x4e8,(int)sVar8);
    }
  }
  return iVar13;
}

