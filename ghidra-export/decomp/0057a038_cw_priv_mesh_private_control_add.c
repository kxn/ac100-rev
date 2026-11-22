// func cw_priv_mesh_private_control_add @ 0057a038 size=3656

undefined4 cw_priv_mesh_private_control_add(int param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  void *__s;
  short *psVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  if ((param_1 == 0) || (0x1b < param_2)) {
    uVar7 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_priv_mesh_private_control_add",
             0x7eb);
    }
  }
  else {
    __s = (void *)FUN_00408450(0x14,0x7ee);
    if (__s == (void *)0x0) {
      uVar7 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x7f1);
      }
    }
    else {
      memset(__s,0,0x14);
      FUN_004086b0(param_1,__s);
      *(short *)((int)__s + 0xc) = (short)param_2;
      switch(param_2 & 0xffff) {
      case 0:
        iVar3 = cw_protocol_clone(param_3,1);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x7fe);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 1;
        }
        break;
      case 1:
        psVar4 = (short *)cw_protocol_clone(param_3,8);
        *(short **)((int)__s + 0x10) = psVar4;
        if (psVar4 == (short *)0x0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x809);
          }
        }
        else {
          psVar4[2] = 0;
          psVar4[3] = 0;
          if (*param_3 != 0) {
            iVar3 = cw_protocol_clone(*(undefined4 *)(param_3 + 2),*param_3 * 0x51);
            *(int *)(psVar4 + 2) = iVar3;
            if (iVar3 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x814
                    );
              return 0xffffffff;
            }
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = *psVar4 * 0x51 + 2;
        }
        break;
      case 2:
      case 8:
      case 9:
      case 0xb:
      case 0x13:
        psVar4 = (short *)cw_protocol_clone(param_3,8);
        *(short **)((int)__s + 0x10) = psVar4;
        if (psVar4 == (short *)0x0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x824);
          }
        }
        else {
          psVar4[2] = 0;
          psVar4[3] = 0;
          if (*param_3 != 0) {
            iVar3 = cw_protocol_clone(*(undefined4 *)(param_3 + 2),*param_3 * 6);
            *(int *)(psVar4 + 2) = iVar3;
            if (iVar3 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x82f
                    );
              return 0xffffffff;
            }
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = *psVar4 * 6 + 2;
        }
        break;
      case 3:
      case 0xd:
        iVar3 = cw_protocol_clone(param_3,0xc);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x866);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 10;
        }
        break;
      case 4:
      case 5:
        iVar3 = cw_protocol_clone(param_3,0x14);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x871);
          }
        }
        else {
          FUN_0051ad88(iVar3 + 8);
          *(undefined2 *)((int)__s + 0xe) = 6;
          for (iVar5 = FUN_004081b0(param_3 + 4); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
            uVar8 = (uint)*(ushort *)(iVar5 + 0xc);
            uVar7 = *(undefined4 *)(iVar5 + 0x10);
            iVar6 = cw_msg_ele_mngr_get(uVar8);
            if (iVar6 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                     "cw_priv_mesh_private_control_add",0x885,uVar8);
              return 0xffffffff;
            }
            iVar6 = (**(code **)(iVar6 + 0x14))(uVar7);
            if (iVar6 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d failed to create message element(%d)\n",
                     "cw_priv_mesh_private_control_add",0x88d,uVar8);
              return 0xffffffff;
            }
            FUN_004086b0(iVar3 + 8,iVar6);
            *(short *)((int)__s + 0xe) = *(short *)((int)__s + 0xe) + *(short *)(iVar6 + 0xe) + 4;
          }
          uVar7 = 0;
        }
        break;
      case 6:
        psVar4 = (short *)cw_protocol_clone(param_3,8);
        *(short **)((int)__s + 0x10) = psVar4;
        if (psVar4 == (short *)0x0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x89c);
          }
        }
        else {
          psVar4[2] = 0;
          psVar4[3] = 0;
          if (*param_3 != 0) {
            iVar3 = cw_protocol_clone(*(undefined4 *)(param_3 + 2),(*param_3 & 0x3ff) << 6);
            *(int *)(psVar4 + 2) = iVar3;
            if (iVar3 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8a7
                    );
              return 0xffffffff;
            }
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = *psVar4 * 0x26 + 2;
        }
        break;
      case 7:
        iVar3 = cw_protocol_clone(param_3,8);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8b3);
          }
        }
        else {
          *(undefined4 *)(iVar3 + 4) = 0;
          if (param_3[1] != 0) {
            iVar5 = cw_protocol_clone(*(undefined4 *)(param_3 + 2),(param_3[1] & 0x3ff) << 6);
            *(int *)(iVar3 + 4) = iVar5;
            if (iVar5 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8be
                    );
              return 0xffffffff;
            }
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = *(short *)(iVar3 + 2) * 0x26 + 3;
        }
        break;
      case 10:
        iVar3 = cw_protocol_clone(param_3,0x30);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8ca);
          }
        }
        else {
          *(undefined4 *)(iVar3 + 0x24) = 0;
          *(undefined4 *)(iVar3 + 0x2c) = 0;
          if ((short)param_3[0x10] < 1) {
            uVar1 = param_3[0x14];
          }
          else {
            iVar5 = cw_protocol_clone(*(undefined4 *)(param_3 + 0x12),param_3[0x10]);
            *(int *)(iVar3 + 0x24) = iVar5;
            if (iVar5 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8d6
                    );
              return 0xffffffff;
            }
            uVar1 = param_3[0x14];
          }
          if ((short)uVar1 < 1) {
            sVar2 = *(short *)(iVar3 + 0x20);
          }
          else {
            iVar5 = cw_protocol_clone(*(undefined4 *)(param_3 + 0x16),uVar1);
            *(int *)(iVar3 + 0x2c) = iVar5;
            if (iVar5 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8df
                    );
              return 0xffffffff;
            }
            sVar2 = *(short *)(iVar3 + 0x20);
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = sVar2 + *(short *)(iVar3 + 0x28) + 0x24;
        }
        break;
      case 0xc:
        iVar3 = cw_protocol_clone(param_3,7);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x85c);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 7;
        }
        break;
      case 0xe:
        iVar3 = cw_protocol_clone(param_3,2);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x852);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 2;
        }
        break;
      case 0xf:
        psVar4 = (short *)cw_protocol_clone(param_3,8);
        *(short **)((int)__s + 0x10) = psVar4;
        if (psVar4 == (short *)0x0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8eb);
          }
        }
        else {
          psVar4[2] = 0;
          psVar4[3] = 0;
          if ((short)*param_3 < 1) {
            sVar2 = *psVar4;
          }
          else {
            iVar3 = cw_protocol_clone(*(undefined4 *)(param_3 + 2),*param_3);
            *(int *)(psVar4 + 2) = iVar3;
            if (iVar3 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x8f6
                    );
              return 0xffffffff;
            }
            sVar2 = *psVar4;
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = sVar2 + 2;
        }
        break;
      case 0x10:
        iVar3 = cw_protocol_clone(param_3,7);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x902);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 7;
        }
        break;
      case 0x11:
        iVar3 = cw_protocol_clone(param_3,2);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x90d);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 2;
        }
        break;
      case 0x12:
        iVar3 = cw_protocol_clone(param_3,2);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x923);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 2;
        }
        break;
      case 0x14:
        psVar4 = (short *)cw_protocol_clone(param_3,0xc);
        *(short **)((int)__s + 0x10) = psVar4;
        if (psVar4 == (short *)0x0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x83b);
          }
        }
        else {
          psVar4[2] = 0;
          psVar4[3] = 0;
          if (*param_3 != 0) {
            iVar3 = cw_protocol_clone(*(undefined4 *)(param_3 + 2),*param_3 * 6);
            *(int *)(psVar4 + 2) = iVar3;
            if (iVar3 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x846
                    );
              return 0xffffffff;
            }
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = (*psVar4 + 1) * 6;
        }
        break;
      case 0x15:
        iVar3 = cw_protocol_clone(param_3,2);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x918);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 2;
        }
        break;
      case 0x16:
        psVar4 = (short *)cw_protocol_clone(param_3,8);
        *(short **)((int)__s + 0x10) = psVar4;
        if (psVar4 == (short *)0x0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x92e);
          }
        }
        else {
          psVar4[2] = 0;
          psVar4[3] = 0;
          if (*param_3 != 0) {
            iVar3 = cw_protocol_clone(*(undefined4 *)(param_3 + 2),(*param_3 & 0xfff) << 4);
            *(int *)(psVar4 + 2) = iVar3;
            if (iVar3 == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x939
                    );
              return 0xffffffff;
            }
          }
          uVar7 = 0;
          *(short *)((int)__s + 0xe) = *psVar4 * 0xd + 2;
        }
        break;
      case 0x17:
        iVar3 = cw_protocol_clone(param_3,1);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x945);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 1;
        }
        break;
      case 0x18:
        iVar3 = cw_protocol_clone(param_3,1);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x950);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 1;
        }
        break;
      default:
        uVar7 = 0;
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d Unrecognize sub ele type(%d)\n",
                 "cw_priv_mesh_private_control_add",0x962,param_2);
        }
        break;
      case 0x1b:
        iVar3 = cw_protocol_clone(param_3,8);
        *(int *)((int)__s + 0x10) = iVar3;
        if (iVar3 == 0) {
          uVar7 = 0xffffffff;
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_add",0x95b);
          }
        }
        else {
          uVar7 = 0;
          *(undefined2 *)((int)__s + 0xe) = 8;
        }
      }
    }
  }
  return uVar7;
}

