// func cw_priv_mesh_private_control_parse @ 0057bd6c size=7156

undefined4 cw_priv_mesh_private_control_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  void *__s_00;
  undefined2 uVar7;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined1 uVar9;
  uint uVar5;
  short sVar8;
  undefined1 *puVar6;
  undefined4 *puVar10;
  undefined2 *puVar11;
  undefined1 *puVar12;
  short *psVar13;
  int iVar14;
  ushort *puVar15;
  int iVar16;
  short local_40;
  undefined2 local_3e [3];
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
  local_30 = (uint)*(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0xc,0xb8);
  if (__s == (void *)0x0) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_mesh_private_control_parse",0xbb);
    }
  }
  else {
    memset(__s,0,0xc);
    FUN_0051ad88(__s);
    local_34 = cw_protocol_retrieve16(param_1);
    if ((local_34 - 1U & 0xffff) < 0x1c) {
      local_38 = 0;
      if (5 < *(ushort *)(param_2 + 0xe)) {
        do {
          if (local_34 <= local_38) {
            *(void **)(param_2 + 0x10) = __s;
            if (*(ushort *)(param_1 + 6) - local_30 != (uint)*(ushort *)(param_2 + 0xe)) {
              return 0xffffffff;
            }
            return 0;
          }
          __s_00 = (void *)FUN_00408450(0x14,0xcf);
          if (__s_00 == (void *)0x0) {
            if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_ERROR]%32s():%4d Malloc sub ele failed\n",
                     "cw_priv_mesh_private_control_parse",0xd2);
            }
            goto LAB_0057bf94;
          }
          memset(__s_00,0,0x14);
          FUN_004086b0(__s,__s_00);
          uVar7 = cw_protocol_retrieve16(param_1);
          *(undefined2 *)((int)__s_00 + 0xc) = uVar7;
          iVar2 = cw_protocol_retrieve16(param_1);
          *(short *)((int)__s_00 + 0xe) = (short)iVar2;
          switch(*(undefined2 *)((int)__s_00 + 0xc)) {
          case 0:
            if (iVar2 == 1) {
              puVar6 = (undefined1 *)FUN_00408450(1,0xe1);
              *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
              if (puVar6 != (undefined1 *)0x0) goto LAB_0057bf24;
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0xe4);
              }
            }
            else if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                     "cw_priv_mesh_private_control_parse",0xde,(uint)*(ushort *)((int)__s_00 + 0xe),
                     (uint)*(ushort *)((int)__s_00 + 0xc));
            }
            goto LAB_0057bf94;
          case 1:
            pvVar3 = (void *)FUN_00408450(8,0xee);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0xf1);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,8);
            puVar15 = *(ushort **)((int)__s_00 + 0x10);
            iVar2 = cw_protocol_retrieve16(param_1);
            *puVar15 = (ushort)iVar2;
            if (iVar2 == 0) {
              uVar1 = *puVar15;
            }
            else {
              pvVar3 = (void *)FUN_00408450(iVar2 * 0x51,0xfb);
              *(void **)(puVar15 + 2) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0xfe);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(uint)*puVar15 * 0x51);
              uVar1 = *puVar15;
              for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
                iVar14 = *(int *)(puVar15 + 2) + iVar2 * 0x51;
                cw_protocol_retrieve_bytes(param_1,iVar14,6);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + 6) = uVar9;
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + 7) = uVar9;
                cw_protocol_retrieve_bytes(param_1,iVar14 + 8,6);
                cw_protocol_retrieve_bytes(param_1,iVar14 + 0xe,0x41);
                *(undefined1 *)(iVar14 + 0x4e) = 0;
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + 0x4f) = uVar9;
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + 0x50) = uVar9;
                uVar1 = *puVar15;
              }
              uVar1 = *puVar15;
            }
            if ((uint)uVar1 * 0x51 + 2 != (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x111,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 2:
          case 8:
          case 9:
          case 0xb:
          case 0x13:
            pvVar3 = (void *)FUN_00408450(8,0x11b);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x11e);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,8);
            puVar15 = *(ushort **)((int)__s_00 + 0x10);
            iVar2 = cw_protocol_retrieve16(param_1);
            *puVar15 = (ushort)iVar2;
            if (iVar2 == 0) {
              uVar1 = *puVar15;
            }
            else {
              pvVar3 = (void *)FUN_00408450(iVar2 * 6,0x127);
              *(void **)(puVar15 + 2) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x12a);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(uint)*puVar15 * 6);
              uVar1 = *puVar15;
              for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar15 + 2) + iVar2 * 6,6);
                uVar1 = *puVar15;
              }
              uVar1 = *puVar15;
            }
            if ((uint)uVar1 * 6 + 2 != (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x135,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 3:
          case 0xd:
            if (iVar2 != 10) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x185,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            pvVar3 = (void *)FUN_00408450(0xc,0x188);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x18b);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,0xc);
            iVar2 = *(int *)((int)__s_00 + 0x10);
            cw_protocol_retrieve_bytes(param_1,iVar2,6);
            uVar4 = cw_protocol_retrieve32(param_1);
            *(undefined4 *)(iVar2 + 8) = uVar4;
            break;
          case 4:
          case 5:
            pvVar3 = (void *)FUN_00408450(0x14,0x197);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x19a);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,0x14);
            iVar2 = *(int *)((int)__s_00 + 0x10);
            iVar14 = iVar2 + 8;
            FUN_0051ad88(iVar14);
            local_2c = (uint)*(ushort *)(param_1 + 6);
            cw_protocol_retrieve_bytes(param_1,iVar2,6);
            while( true ) {
              uVar5 = *(ushort *)(param_1 + 6) - local_2c;
              if ((int)(uint)*(ushort *)((int)__s_00 + 0xe) <= (int)uVar5) break;
              local_3e[0] = 0;
              local_40 = 0;
              iVar2 = cw_msg_ele_format_parse(param_1,local_3e,&local_40);
              if (iVar2 == -1) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d failed to parse type and length of message element\n"
                         ,"cw_priv_mesh_private_control_parse",0x1ae);
                }
                goto LAB_0057bf94;
              }
              puVar15 = (ushort *)cw_msg_ele_mngr_get(local_3e[0]);
              if (puVar15 == (ushort *)0x0) {
                if (capwap_err_switch == 0) {
                  sVar8 = *(short *)(param_1 + 6);
                }
                else {
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    sVar8 = *(short *)(param_1 + 6);
                  }
                  else {
                    printf("[CW_ERROR]%32s():%4d message element doesn\'t have manager, ignore it\n"
                           ,"cw_priv_mesh_private_control_parse",0x1b6);
                    sVar8 = *(short *)(param_1 + 6);
                  }
                }
                *(short *)(param_1 + 6) = local_40 + sVar8;
              }
              else {
                pvVar3 = (void *)FUN_00408450(0x18,0x1bd);
                if (pvVar3 == (void *)0x0) {
                  if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    printf("[CW_ERROR]%32s():%4d out of memory\n",
                           "cw_priv_mesh_private_control_parse",0x1c0);
                  }
                  goto LAB_0057bf94;
                }
                memset(pvVar3,0,0x18);
                FUN_004086b0(iVar14,pvVar3);
                *(undefined2 *)((int)pvVar3 + 0xc) = local_3e[0];
                *(short *)((int)pvVar3 + 0xe) = local_40;
                *(undefined4 *)((int)pvVar3 + 0x14) = *(undefined4 *)(param_2 + 0x14);
                iVar2 = (**(code **)(puVar15 + 6))(param_1,pvVar3);
                if (iVar2 == -1) {
                  if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    printf("[CW_ERROR]%32s():%4d failed to parse %s(%d)\n",
                           "cw_priv_mesh_private_control_parse",0x1cc,*(undefined4 *)(puVar15 + 2),
                           (uint)*puVar15);
                  }
                  goto LAB_0057bf94;
                }
              }
            }
            if (*(ushort *)((int)__s_00 + 0xe) != uVar5) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x1d2,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 6:
            pvVar3 = (void *)FUN_00408450(8,0x1d8);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x1db);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,8);
            puVar15 = *(ushort **)((int)__s_00 + 0x10);
            iVar2 = cw_protocol_retrieve16(param_1);
            *puVar15 = (ushort)iVar2;
            if (iVar2 == 0) {
              uVar1 = *puVar15;
            }
            else {
              pvVar3 = (void *)FUN_00408450(iVar2 << 6,0x1e4);
              *(void **)(puVar15 + 2) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x1e7);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(uint)*puVar15 << 6);
              uVar1 = *puVar15;
              for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
                iVar16 = iVar2 * 0x40;
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar15 + 2) + iVar16,6);
                *(undefined1 *)(*(int *)(puVar15 + 2) + iVar16 + 8) = 1;
                iVar14 = *(int *)(puVar15 + 2);
                uVar4 = cw_protocol_retrieve32(param_1);
                *(undefined4 *)(iVar14 + iVar16 + 0xc) = uVar4;
                *(undefined1 *)(*(int *)(puVar15 + 2) + iVar16 + 0x1c) = 2;
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar15 + 2) + iVar16 + 0x20,0x10);
                iVar14 = *(int *)(puVar15 + 2);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + iVar16 + 0x30) = uVar9;
                iVar14 = *(int *)(puVar15 + 2);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + iVar16 + 0x31) = uVar9;
                iVar14 = *(int *)(puVar15 + 2);
                uVar4 = cw_protocol_retrieve32(param_1);
                *(undefined4 *)(iVar14 + iVar16 + 0x34) = uVar4;
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar15 + 2) + iVar16 + 0x38,6);
                uVar1 = *puVar15;
              }
              uVar1 = *puVar15;
            }
            if ((uint)uVar1 * 0x26 + 2 != (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x1fa,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 7:
            pvVar3 = (void *)FUN_00408450(8,0x200);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x203);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,8);
            puVar6 = *(undefined1 **)((int)__s_00 + 0x10);
            uVar9 = cw_protocol_retrieve8(param_1);
            *puVar6 = uVar9;
            iVar2 = cw_protocol_retrieve16(param_1);
            *(short *)(puVar6 + 2) = (short)iVar2;
            if (iVar2 == 0) {
              uVar1 = *(ushort *)(puVar6 + 2);
            }
            else {
              pvVar3 = (void *)FUN_00408450(iVar2 << 6,0x20d);
              *(void **)(puVar6 + 4) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x210);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(uint)*(ushort *)(puVar6 + 2) << 6);
              uVar1 = *(ushort *)(puVar6 + 2);
              for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
                iVar16 = iVar2 * 0x40;
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar6 + 4) + iVar16,6);
                *(undefined1 *)(*(int *)(puVar6 + 4) + iVar16 + 8) = 1;
                iVar14 = *(int *)(puVar6 + 4);
                uVar4 = cw_protocol_retrieve32(param_1);
                *(undefined4 *)(iVar14 + iVar16 + 0xc) = uVar4;
                *(undefined1 *)(*(int *)(puVar6 + 4) + iVar16 + 0x1c) = 2;
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar6 + 4) + iVar16 + 0x20,0x10);
                iVar14 = *(int *)(puVar6 + 4);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + iVar16 + 0x30) = uVar9;
                iVar14 = *(int *)(puVar6 + 4);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + iVar16 + 0x31) = uVar9;
                iVar14 = *(int *)(puVar6 + 4);
                uVar4 = cw_protocol_retrieve32(param_1);
                *(undefined4 *)(iVar14 + iVar16 + 0x34) = uVar4;
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar6 + 4) + iVar16 + 0x38,6);
                uVar1 = *(ushort *)(puVar6 + 2);
              }
              uVar1 = *(ushort *)(puVar6 + 2);
            }
            if ((uint)uVar1 * 0x26 + 3 != (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x223,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 10:
            pvVar3 = (void *)FUN_00408450(0x30,0x229);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x22c);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,0x30);
            iVar2 = *(int *)((int)__s_00 + 0x10);
            cw_protocol_retrieve_bytes(param_1,iVar2,0x20);
            sVar8 = cw_protocol_retrieve16(param_1);
            *(short *)(iVar2 + 0x20) = sVar8;
            if (0 < sVar8) {
              pvVar3 = (void *)FUN_00408450((int)sVar8,0x236);
              *(void **)(iVar2 + 0x24) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x239);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(int)*(short *)(iVar2 + 0x20));
              cw_protocol_retrieve_bytes
                        (param_1,*(undefined4 *)(iVar2 + 0x24),*(undefined2 *)(iVar2 + 0x20));
            }
            sVar8 = cw_protocol_retrieve16(param_1);
            *(short *)(iVar2 + 0x28) = sVar8;
            if (0 < sVar8) {
              pvVar3 = (void *)FUN_00408450((int)sVar8,0x242);
              *(void **)(iVar2 + 0x2c) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x245);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(int)*(short *)(iVar2 + 0x28));
              cw_protocol_retrieve_bytes
                        (param_1,*(undefined4 *)(iVar2 + 0x2c),*(undefined2 *)(iVar2 + 0x28));
            }
            if (*(short *)(iVar2 + 0x20) + 0x24 + (int)*(short *)(iVar2 + 0x28) !=
                (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x24d,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 0xc:
            if (iVar2 != 7) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x171,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            puVar6 = (undefined1 *)FUN_00408450(7,0x174);
            *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
            if (puVar6 == (undefined1 *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x177);
              }
              goto LAB_0057bf94;
            }
            *puVar6 = 0;
            puVar6[1] = 0;
            puVar6[2] = 0;
            puVar6[3] = 0;
            puVar6[4] = 0;
            puVar6[5] = 0;
            puVar6[6] = 0;
            iVar2 = *(int *)((int)__s_00 + 0x10);
            cw_protocol_retrieve_bytes(param_1,iVar2,6);
            uVar9 = cw_protocol_retrieve8(param_1);
            *(undefined1 *)(iVar2 + 6) = uVar9;
            break;
          case 0xe:
            if (iVar2 == 2) {
              puVar6 = (undefined1 *)FUN_00408450(2,0x161);
              *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
              if (puVar6 != (undefined1 *)0x0) goto LAB_0057c1d4;
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x164);
              }
            }
            else if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                     "cw_priv_mesh_private_control_parse",0x15e,(uint)*(ushort *)((int)__s_00 + 0xe)
                     ,(uint)*(ushort *)((int)__s_00 + 0xc));
            }
            goto LAB_0057bf94;
          case 0xf:
            pvVar3 = (void *)FUN_00408450(8,0x253);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x256);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,8);
            psVar13 = *(short **)((int)__s_00 + 0x10);
            sVar8 = cw_protocol_retrieve16(param_1);
            *psVar13 = sVar8;
            if (0 < sVar8) {
              pvVar3 = (void *)FUN_00408450((int)sVar8,0x25f);
              *(void **)(psVar13 + 2) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x262);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(int)*psVar13);
              cw_protocol_retrieve_bytes(param_1,*(undefined4 *)(psVar13 + 2),*psVar13);
            }
            if ((int)*psVar13 + 2U != (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x26a,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 0x10:
            if (iVar2 != 7) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x272,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            puVar6 = (undefined1 *)FUN_00408450(7,0x275);
            *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
            if (puVar6 == (undefined1 *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x278);
              }
              goto LAB_0057bf94;
            }
            *puVar6 = 0;
            puVar6[1] = 0;
            puVar6[2] = 0;
            puVar6[3] = 0;
            puVar6[4] = 0;
            puVar6[5] = 0;
            puVar6[6] = 0;
            puVar12 = *(undefined1 **)((int)__s_00 + 0x10);
            uVar9 = cw_protocol_retrieve8(param_1);
            uVar7 = 6;
            puVar6 = puVar12 + 1;
            *puVar12 = uVar9;
LAB_0057c658:
            cw_protocol_retrieve_bytes(param_1,puVar6,uVar7);
            break;
          case 0x11:
            if (iVar2 == 2) {
              puVar6 = (undefined1 *)FUN_00408450(2,0x288);
              *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
              if (puVar6 != (undefined1 *)0x0) goto LAB_0057c08c;
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x28b);
              }
            }
            else if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                     "cw_priv_mesh_private_control_parse",0x285,(uint)*(ushort *)((int)__s_00 + 0xe)
                     ,(uint)*(ushort *)((int)__s_00 + 0xc));
            }
            goto LAB_0057bf94;
          case 0x12:
            if (iVar2 != 2) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x2a9,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            puVar6 = (undefined1 *)FUN_00408450(2,0x2ac);
            *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
            if (puVar6 == (undefined1 *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x2af);
              }
              goto LAB_0057bf94;
            }
LAB_0057c1d4:
            *puVar6 = 0;
            puVar6[1] = 0;
            puVar6 = *(undefined1 **)((int)__s_00 + 0x10);
            uVar9 = cw_protocol_retrieve8(param_1);
            *puVar6 = uVar9;
            uVar9 = cw_protocol_retrieve8(param_1);
            puVar6[1] = uVar9;
            break;
          case 0x14:
            pvVar3 = (void *)FUN_00408450(0xc,0x13b);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x13e);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,0xc);
            puVar15 = *(ushort **)((int)__s_00 + 0x10);
            iVar2 = cw_protocol_retrieve16(param_1);
            *puVar15 = (ushort)iVar2;
            if (iVar2 != 0) {
              pvVar3 = (void *)FUN_00408450(iVar2 * 6,0x147);
              *(void **)(puVar15 + 2) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x14a);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(uint)*puVar15 * 6);
              uVar1 = *puVar15;
              for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar15 + 2) + iVar2 * 6,6);
                uVar1 = *puVar15;
              }
            }
            uVar4 = cw_protocol_retrieve32(param_1);
            *(undefined4 *)(puVar15 + 4) = uVar4;
            if ((*puVar15 + 1) * 6 != (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x156,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 0x15:
            if (iVar2 != 2) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x297,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            puVar6 = (undefined1 *)FUN_00408450(2,0x29a);
            *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
            if (puVar6 == (undefined1 *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x29d);
              }
              goto LAB_0057bf94;
            }
LAB_0057c08c:
            *puVar6 = 0;
            puVar6[1] = 0;
            puVar11 = *(undefined2 **)((int)__s_00 + 0x10);
            uVar7 = cw_protocol_retrieve16(param_1);
            *puVar11 = uVar7;
            break;
          case 0x16:
            pvVar3 = (void *)FUN_00408450(8,0x2ba);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x2bd);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,8);
            puVar15 = *(ushort **)((int)__s_00 + 0x10);
            iVar2 = cw_protocol_retrieve16(param_1);
            *puVar15 = (ushort)iVar2;
            if (iVar2 == 0) {
              uVar1 = *puVar15;
            }
            else {
              pvVar3 = (void *)FUN_00408450(iVar2 << 4,0x2c6);
              *(void **)(puVar15 + 2) = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse"
                         ,0x2c9);
                }
                goto LAB_0057bf94;
              }
              memset(pvVar3,0,(uint)*puVar15 << 4);
              uVar1 = *puVar15;
              for (iVar2 = 0; iVar2 < (int)(uint)uVar1; iVar2 = iVar2 + 1) {
                iVar16 = iVar2 * 0x10;
                cw_protocol_retrieve_bytes(param_1,*(int *)(puVar15 + 2) + iVar16,6);
                iVar14 = *(int *)(puVar15 + 2);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + iVar16 + 6) = uVar9;
                iVar14 = *(int *)(puVar15 + 2);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + iVar16 + 7) = uVar9;
                iVar14 = *(int *)(puVar15 + 2);
                uVar4 = cw_protocol_retrieve32(param_1);
                *(undefined4 *)(iVar14 + iVar16 + 8) = uVar4;
                iVar14 = *(int *)(puVar15 + 2);
                uVar9 = cw_protocol_retrieve8(param_1);
                *(undefined1 *)(iVar14 + iVar16 + 0xc) = uVar9;
                uVar1 = *puVar15;
              }
              uVar1 = *puVar15;
            }
            if ((uint)uVar1 * 0xd + 2 != (uint)*(ushort *)((int)__s_00 + 0xe)) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x2d8,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            break;
          case 0x17:
            if (iVar2 == 1) {
              puVar6 = (undefined1 *)FUN_00408450(1,0x2e3);
              *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
              if (puVar6 != (undefined1 *)0x0) goto LAB_0057bf24;
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x2e6);
              }
            }
            else if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                     "cw_priv_mesh_private_control_parse",0x2e0,(uint)*(ushort *)((int)__s_00 + 0xe)
                     ,(uint)*(ushort *)((int)__s_00 + 0xc));
            }
            goto LAB_0057bf94;
          case 0x18:
            if (iVar2 != 1) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x2f2,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            puVar6 = (undefined1 *)FUN_00408450(1,0x2f5);
            *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
            if (puVar6 == (undefined1 *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x2f8);
              }
              goto LAB_0057bf94;
            }
LAB_0057bf24:
            *puVar6 = 0;
            puVar6 = *(undefined1 **)((int)__s_00 + 0x10);
            uVar9 = cw_protocol_retrieve8(param_1);
            *puVar6 = uVar9;
            break;
          default:
            if (capwap_warning_switch == 0) {
              sVar8 = *(short *)((int)__s_00 + 0xe);
            }
            else {
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                sVar8 = *(short *)((int)__s_00 + 0xe);
              }
              else {
                printf("[CW_WARNING]%32s():%4d Unrecognize sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x315,
                       (uint)*(ushort *)((int)__s_00 + 0xc));
                sVar8 = *(short *)((int)__s_00 + 0xe);
              }
            }
            if (sVar8 != 0) {
              puVar6 = (undefined1 *)FUN_00408450(sVar8,0x318);
              *(undefined1 **)((int)__s_00 + 0x10) = puVar6;
              if (puVar6 != (undefined1 *)0x0) {
                *puVar6 = 0;
                puVar6[1] = 0;
                puVar6 = *(undefined1 **)((int)__s_00 + 0x10);
                uVar7 = *(undefined2 *)((int)__s_00 + 0xe);
                goto LAB_0057c658;
              }
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x31b);
              }
              goto LAB_0057bf94;
            }
            break;
          case 0x1b:
            if (iVar2 != 8) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Illegal length(%d) for sub ele type(%d)\n",
                       "cw_priv_mesh_private_control_parse",0x304,
                       (uint)*(ushort *)((int)__s_00 + 0xe),(uint)*(ushort *)((int)__s_00 + 0xc));
              }
              goto LAB_0057bf94;
            }
            pvVar3 = (void *)FUN_00408450(8,0x307);
            *(void **)((int)__s_00 + 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_priv_mesh_private_control_parse",
                       0x30a);
              }
              goto LAB_0057bf94;
            }
            memset(pvVar3,0,8);
            puVar10 = *(undefined4 **)((int)__s_00 + 0x10);
            uVar4 = cw_protocol_retrieve32(param_1);
            *puVar10 = uVar4;
            uVar4 = cw_protocol_retrieve32(param_1);
            puVar10[1] = uVar4;
          }
          local_38 = local_38 + 1;
        } while( true );
      }
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d Length(%d) of private message element(%d) is wrong\n",
               "cw_priv_mesh_private_control_parse",0xca,(uint)*(ushort *)(param_2 + 0xe),
               (uint)*(ushort *)(param_2 + 0xc));
      }
    }
    else if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d Ele num(%d) is wrong\n","cw_priv_mesh_private_control_parse",0xc4
             ,local_34);
    }
LAB_0057bf94:
    cw_priv_mesh_private_control_val_destroy(__s);
  }
  return 0xffffffff;
}

