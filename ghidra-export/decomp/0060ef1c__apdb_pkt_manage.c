// func _apdb_pkt_manage @ 0060ef1c size=11276

/* WARNING: Removing unreachable block (ram,0x0061188c) */
/* WARNING: Type propagation algorithm not settling */

byte * _apdb_pkt_manage(byte *param_1,int param_2,int param_3,byte *param_4,int param_5)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  short sVar6;
  int iVar7;
  void *pvVar8;
  undefined1 *puVar9;
  uint uVar10;
  void *pvVar11;
  uint *puVar12;
  int iVar13;
  char *pcVar14;
  short sVar18;
  int iVar15;
  undefined2 uVar19;
  short *psVar16;
  int *piVar17;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  undefined4 extraout_v1_01;
  char *pcVar20;
  char *pcVar21;
  uint uVar22;
  byte *pbVar23;
  size_t sVar24;
  char cVar27;
  int iVar25;
  int iVar26;
  byte *pbVar28;
  uint uVar29;
  byte *pbVar30;
  byte *pbVar31;
  int iVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 local_330;
  char *local_32c;
  int local_328;
  undefined4 local_324;
  undefined4 local_320;
  undefined4 local_31c;
  undefined2 local_318;
  undefined1 local_316;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  char acStack_2c0 [64];
  char acStack_280 [66];
  ushort local_23e;
  ushort local_23c;
  undefined1 auStack_200 [16];
  undefined4 local_1f0;
  byte *local_98;
  void *local_94;
  int local_90;
  byte *local_8c;
  int local_88;
  byte *local_84;
  byte *local_80;
  void *local_7c;
  void *local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  byte *local_68;
  byte *local_64;
  byte *local_60;
  uint local_5c;
  uint local_58;
  byte *local_54;
  uint local_50;
  int local_4c;
  int local_48;
  int local_44;
  void *local_40;
  uint local_3c;
  uint local_38;
  byte *local_34;
  int local_30;
  
  local_324 = 0;
  memset(auStack_200,0,0x168);
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  local_328 = 0;
  iVar7 = isLearning();
  if ((iVar7 == 0) || (iVar7 = apdb_sync_device_ready(param_5), iVar7 == 0)) {
    FUN_0060ee8c(param_5);
    return (byte *)0x0;
  }
  pvVar8 = (void *)cw_msg_ele_priv_val_get_from_pkt(param_3,0x5b);
  local_78 = (void *)FUN_00408450(0x10,0x5f3);
  if (local_78 == (void *)0x0) {
    if (apdb_err_switch == 0) {
      return (byte *)0xffffffff;
    }
    printf("[APDB_ERROR]%s()/line %d : malloc error\n","_apdb_pkt_manage",0x5f5);
    return (byte *)0xffffffff;
  }
  if (pvVar8 == (void *)0x0) {
    memset(local_78,0xff,0x10);
    local_7c = (void *)0x0;
  }
  else {
    memcpy(local_78,pvVar8,0x10);
    local_7c = (void *)FUN_00408450(0x10,0x5fd);
    if (local_7c == (void *)0x0) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : malloc error\n","_apdb_pkt_manage",0x5ff);
      }
      FUN_00407df0(local_78);
      return (byte *)0xffffffff;
    }
    memset(local_7c,0xff,0x10);
  }
  uVar22 = (uint)*param_1;
  if (uVar22 < 2) {
    iVar7 = is_same_vendor(param_1[1]);
    if (iVar7 == 0) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : vendor not supported, act:%d\n","_apdb_pkt_manage",0x620,
               (uint)param_1[1]);
      }
      local_88 = 0;
      bVar5 = true;
      pbVar30 = (byte *)0x0;
      goto LAB_0060f068;
    }
    if (apdb_debug_switch == 0) {
      uVar10 = *(uint *)(param_1 + 8);
    }
    else {
      uVar10 = (uint)(param_1 + 8) & 3;
      uVar29 = (uint)(param_1 + 0xb) & 3;
      uVar22 = (*(int *)(param_1 + 8 + -uVar10) << uVar10 * 8 |
               uVar22 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar29 + 1) * 8 |
               *(uint *)(param_1 + 0xb + -uVar29) >> (3 - uVar29) * 8;
      printf("[APDB_DEBUG]%s()/line %d : Support flags: %x\n\n","_apdb_pkt_manage",0x626,uVar22);
      uVar10 = *(uint *)(param_1 + 8);
    }
    if ((uVar10 & 0xfffffff0) != 0) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : Exist not supported bit: support: %x, flags: %x\n\n",
               "_apdb_pkt_manage",0x62b,0xf,uVar10);
      }
      FUN_004082d0(apdb_pkt_mutex,0xffffffff);
      local_300 = 0;
      local_2fc = 0;
      local_2f8 = 0;
      local_2f4 = 0;
      local_2f0 = 0;
      memset(acStack_280,0,0x4c);
      local_320 = 0;
      local_31c = 0;
      local_318 = 0;
      local_316 = 0;
      if (unsupport_ap_root != 0) {
        param_2 = param_2 + -0x10;
        pbVar30 = param_1 + 0x10;
        local_23e = (ushort)param_1[2];
        local_23c = (ushort)param_1[3];
        iVar7 = 0;
LAB_0060f528:
        if ((int)(uint)param_1[0xf] <= iVar7) goto LAB_0060f53c;
        sVar24 = (size_t)pbVar30[1];
        if (param_2 < (int)(sVar24 + 2)) {
          if (apdb_err_switch == 0) goto LAB_0060f53c;
          pcVar20 = "[APDB_ERROR]%s()/line %d : Tlv len error\n\n";
          uVar34 = 0x10a;
        }
        else {
          if (*pbVar30 != 1) {
            pbVar30 = pbVar30 + sVar24 + 2;
            iVar7 = iVar7 + 1;
            param_2 = param_2 + (-2 - (uint)pbVar30[1]);
            goto LAB_0060f528;
          }
          if (0x40 < sVar24) {
            sVar24 = 0x40;
          }
          strncpy(acStack_280,(char *)(pbVar30 + 2),sVar24);
          FUN_00408710(acStack_280,0x41);
          iVar7 = FUN_00407fa0(unsupport_hash,acStack_280);
          if (iVar7 != 0) {
            FUN_00407e70();
            *(undefined4 *)(iVar7 + 0x48) = extraout_v1_00;
            goto LAB_0060f53c;
          }
          pvVar8 = (void *)FUN_00408450(0x4c,299);
          if (pvVar8 == (void *)0x0) goto LAB_0060f53c;
          memcpy(pvVar8,acStack_280,0x4c);
          FUN_00407e70();
          uVar34 = unsupport_hash;
          *(undefined4 *)((int)pvVar8 + 0x48) = extraout_v1_01;
          iVar7 = FUN_00408380(uVar34,pvVar8);
          if (iVar7 != 0) {
            FUN_00407df0(pvVar8);
            goto LAB_0060f53c;
          }
          iVar7 = cJSON_CreateObject();
          if (iVar7 == 0) {
            if (apdb_err_switch == 0) goto LAB_0060f53c;
            pcVar20 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
            uVar34 = 0x141;
          }
          else {
            iVar32 = cJSON_CreateString(acStack_280);
            if (iVar32 == 0) {
              if (apdb_err_switch != 0) {
                pcVar20 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                uVar34 = 0x149;
                goto LAB_0060f688;
              }
              goto LAB_0060f53c;
            }
            cJSON_AddItemToObject(iVar7,"model_name",iVar32);
            sprintf((char *)&local_320,"%d.%d",(int)(short)local_23e,(int)(short)local_23c);
            iVar32 = cJSON_CreateString(&local_320);
            if (iVar32 != 0) {
              cJSON_AddItemToObject(iVar7,"hardware_ver",iVar32);
              cJSON_AddItemToArray(unsupport_ap_root,iVar7);
              snprintf((char *)&local_300,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_4,
                       (uint)param_4[1],(uint)param_4[2],(uint)param_4[3],(uint)param_4[4],
                       (uint)param_4[5]);
              memset(acStack_2c0,0,0x40);
              FUN_00408190(*(undefined4 *)(param_4 + 0x10),*(undefined4 *)(param_4 + 0x14),
                           *(undefined4 *)(param_4 + 0x18),*(undefined4 *)(param_4 + 0x1c),
                           *(undefined4 *)(param_4 + 0x20),acStack_2c0,0x40,"---");
              pcVar20 = acStack_2c0;
              if (param_4[0xc] != 0) {
                pcVar20 = "---";
              }
              loggerk_reg(0x53,0x3cf6,1,pcVar20,1,&local_300,1,acStack_280,2,(int)(short)local_23e,2
                          ,(int)(short)local_23c,0);
              goto LAB_0060f53c;
            }
            if (apdb_err_switch == 0) goto LAB_0060f53c;
            pcVar20 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
            uVar34 = 0x154;
          }
        }
LAB_0060f688:
        printf(pcVar20,"_apdb_add_unsupport_ap_list",uVar34);
      }
LAB_0060f53c:
      if (unknown_ap_flag == 0) {
        _apdb_unknown_ap_record();
        unknown_ap_flag = 1;
      }
      bVar5 = true;
      FUN_00407f30(apdb_pkt_mutex);
      local_88 = 0;
      goto LAB_0060f064;
    }
    local_324 = (uint)CONCAT12(param_1[2],(ushort)param_1[3]);
    if (*(int *)(param_1 + 4) == 0) {
      uVar22 = *(uint *)(param_1 + 8);
    }
    else {
      iVar7 = _apdb_hw_exist(*(int *)(param_1 + 4),local_78);
      if (iVar7 != 0) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : AP hw entry existed, no need to manage.\n\n",
                 "_apdb_pkt_manage",0x63f);
        }
        local_88 = 0;
        bVar5 = false;
        pbVar30 = (byte *)0x0;
        goto LAB_0060f068;
      }
      uVar10 = (uint)(param_1 + 8) & 3;
      uVar22 = *(int *)(param_1 + 8 + -uVar10) << uVar10 * 8 |
               uVar22 & 0xffffffffU >> (4 - uVar10) * 8;
    }
    if (apdb_debug_switch == 0) {
      bVar2 = param_1[0xf];
    }
    else {
      printf("[APDB_DEBUG]%s()/line %d : Is multi freq ap: %d\n\n","_apdb_pkt_manage",0x646,
             (uVar22 << 0x1e) >> 0x1f);
      bVar2 = param_1[0xf];
    }
    local_84 = (byte *)(uint)bVar2;
    if (local_84 == (byte *)0x0) {
      if (apdb_err_switch != 0) {
        pcVar20 = "[APDB_ERROR]%s()/line %d : Para num error: %d\n";
        uVar34 = 0x64b;
        pbVar30 = (byte *)0x0;
LAB_0060f658:
        printf(pcVar20,"_apdb_pkt_manage",uVar34,pbVar30);
      }
LAB_0060f5a4:
      local_88 = 0;
      bVar5 = false;
      local_328 = 1;
      goto LAB_0060f064;
    }
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : Para num: %d\n","_apdb_pkt_manage",0x651,local_84);
    }
    pbVar30 = (byte *)(param_2 + -0x10);
    local_98 = pbVar30;
    if (pbVar30 < (byte *)0x3) {
      if (apdb_err_switch != 0) {
        pcVar20 = "[APDB_ERROR]%s()/line %d : pkt len error, not include tlv: %d\n\n";
        uVar34 = 0x656;
        goto LAB_0060f658;
      }
      goto LAB_0060f5a4;
    }
    pvVar8 = (void *)FUN_00408450(0x168,0x65d);
    if (pvVar8 == (void *)0x0) {
      if (apdb_err_switch != 0) {
        uVar34 = 0x660;
LAB_0060fdf0:
        printf("[APDB_ERROR]%s()/line %d : Failed to malloc memory for apdb_ap.\n",
               "_apdb_pkt_manage",uVar34);
      }
LAB_0060fdbc:
      local_88 = 0;
      bVar5 = false;
      pbVar30 = (byte *)0xffffffff;
      local_90 = 0;
      local_94 = (void *)0x0;
      goto LAB_0060f074;
    }
    memset(pvVar8,0,0x168);
    *(undefined4 *)((int)pvVar8 + 0x10) = *(undefined4 *)(param_1 + 4);
    bVar2 = param_1[1];
    *(undefined4 *)((int)pvVar8 + 0x94) = 1;
    *(uint *)((int)pvVar8 + 0x18) = (uint)bVar2;
    pvVar11 = (void *)FUN_00408450(0x38,0x66a);
    *(void **)((int)pvVar8 + 0x164) = pvVar11;
    if (pvVar11 == (void *)0x0) {
      if (apdb_err_switch != 0) {
        uVar34 = 0x66d;
        goto LAB_0060fdf0;
      }
      goto LAB_0060fdbc;
    }
    memset(pvVar11,0,0x38);
    pbVar31 = param_1 + 0x10;
    *(undefined4 *)((int)pvVar8 + 0x160) = 1;
    pbVar30 = (byte *)0x0;
    local_88 = 0;
    local_90 = 0;
    **(ushort **)((int)pvVar8 + 0x164) = (ushort)param_1[2];
    local_94 = (void *)0x0;
    local_8c = (byte *)0x0;
    *(ushort *)(*(int *)((int)pvVar8 + 0x164) + 2) = (ushort)param_1[3];
    *(uint *)((int)pvVar8 + 0x15c) = (uint)param_1[0xe];
    local_80 = param_1;
    for (; pbVar28 = local_80, (int)local_8c < (int)local_84; local_8c = local_8c + 1) {
      uVar22 = (uint)pbVar31[1];
      if ((int)local_98 < (int)(uVar22 + 2)) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : Tlv len error %d, pkt_len: %d, tlv len: %d\n\n",
                 "_apdb_pkt_manage",0x67e,local_8c,local_98,uVar22);
        }
        pbVar30 = (byte *)0xffffffff;
        local_328 = 1;
        break;
      }
      switch(*pbVar31 - 1) {
      case 0:
        sVar24 = 0x40;
        if (uVar22 < 0x41) {
          sVar24 = uVar22;
        }
        strncpy((char *)((int)pvVar8 + 0xda),(char *)(pbVar31 + 2),sVar24);
        FUN_00408710((char *)((int)pvVar8 + 0xda),0x41);
        goto switchD_0060f8ac_default;
      case 1:
        pvVar11 = (void *)FUN_00408450(uVar22 + 1,0x698);
        if (pvVar11 == (void *)0x0) {
          pbVar30 = (byte *)0xffffffff;
          if (apdb_err_switch == 0) break;
          pcVar20 = 
          "[APDB_ERROR]%s()/line %d : Failed to malloc memory for APDB_MSG_TYPE_LINKED_MODIFY_2_4G.\n"
          ;
          uVar34 = 0x69b;
LAB_006100bc:
          pbVar30 = (byte *)0xffffffff;
          printf(pcVar20,"_apdb_pkt_manage",uVar34);
        }
        else {
          memset(pvVar11,0,uVar22 + 1);
          memcpy(pvVar11,pbVar31 + 2,(uint)pbVar31[1]);
          iVar7 = (int)pvVar8 + 0x20;
          *(undefined1 *)((int)pvVar11 + (uint)pbVar31[1]) = 0;
LAB_0060fb00:
          _apdb_parse_linked_modify_items(pvVar11,iVar7);
          FUN_00407df0(pvVar11);
        }
        goto switchD_0060f8ac_default;
      case 2:
        pvVar11 = (void *)FUN_00408450(uVar22 + 1,0x6a9);
        if (pvVar11 != (void *)0x0) {
          memset(pvVar11,0,uVar22 + 1);
          memcpy(pvVar11,pbVar31 + 2,(uint)pbVar31[1]);
          iVar7 = (int)pvVar8 + 0x48;
          *(undefined1 *)((int)pvVar11 + (uint)pbVar31[1]) = 0;
          goto LAB_0060fb00;
        }
        pbVar30 = (byte *)0xffffffff;
        if (apdb_err_switch != 0) {
          pcVar20 = 
          "[APDB_ERROR]%s()/line %d : Failed to malloc memory for APDB_MSG_TYPE_LINKED_MODIFY_5G.\n"
          ;
          uVar34 = 0x6ac;
          goto LAB_006100bc;
        }
        break;
      case 3:
        if (uVar22 == 1) {
          *(uint *)((int)pvVar8 + 0x14) = (uint)pbVar31[2];
          break;
        }
        if (apdb_err_switch != 0) {
          pcVar20 = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_EXT_WIRE_PHY len error: %d\n\n";
          uVar34 = 0x6bc;
LAB_0060f978:
          printf(pcVar20,"_apdb_pkt_manage",uVar34);
        }
LAB_0060f948:
        local_328 = 1;
        pbVar30 = (byte *)0xffffffff;
        goto switchD_0060f8ac_default;
      case 4:
        if (uVar22 != 1) {
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_SUPPORT_AP_TRUNK len error: %d\n\n";
            uVar34 = 0x6c8;
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        *(uint *)((int)pvVar8 + 0x70) = (uint)(pbVar31[2] != 0);
        break;
      case 5:
        if (uVar22 != 1) {
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_IS_HDAP len error: %d\n\n";
            uVar34 = 0x70e;
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        *(uint *)((int)pvVar8 + 0x1c) = (uint)(pbVar31[2] != 0);
        break;
      case 6:
        if (uVar22 < 7) {
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_RADIOS len error: %d\n\n";
            uVar34 = 0x71a;
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        if (*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x10) < 9) {
          if (local_94 == (void *)0x0) {
            pbVar30 = (byte *)0xffffffff;
            local_94 = (void *)FUN_00408450(0x8a0,0x728);
            if (local_94 == (void *)0x0) break;
            memset(local_94,0,0x8a0);
          }
          piVar17 = (int *)((int)local_94 + local_90 * 0x114);
          iVar7 = _apdb_pkt_parse_radio(pbVar31 + 2,piVar17,&local_328);
          if (iVar7 == 0) {
            iVar32 = *piVar17;
            iVar7 = *(int *)((int)pvVar8 + 0x164);
            if (iVar32 == 0) {
              *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 1;
              *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x1c) = 1;
            }
            else if (iVar32 == 1) {
              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;
              *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x18) = 1;
            }
            local_90 = local_90 + 1;
            *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x24) = 1;
            pbVar30 = (byte *)0x0;
          }
          else {
            pbVar30 = (byte *)0xffffffff;
            if (apdb_err_switch != 0) {
              uVar34 = 0x733;
              pcVar20 = "[APDB_ERROR]%s()/line %d : _apdb_pkt_parse_radio failed\n\n";
              goto LAB_006100bc;
            }
          }
        }
        else if (apdb_err_switch == 0) {
          pbVar30 = (byte *)0xffffffff;
          local_88 = 1;
        }
        else {
          printf("[APDB_ERROR]%s()/line %d : Radio cnt exceeds\n","_apdb_pkt_manage",0x722);
          pbVar30 = (byte *)0xffffffff;
          local_88 = 1;
        }
        break;
      case 7:
        if (uVar22 != 1) {
          if (apdb_err_switch != 0) {
            uVar34 = 0x6d4;
            pcVar20 = 
            "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_SUPPORT_CLOUD_UPGRADE len error: %d\n\n";
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        *(uint *)((int)pvVar8 + 0x74) = (uint)(pbVar31[2] != 0);
        break;
      case 8:
        if (uVar22 != 0x20) {
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_HARDWARE_ID len error: %d\n\n";
            uVar34 = 0x702;
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        FUN_00408280((int)pvVar8 + 0x84,pbVar31 + 2,0x20);
        goto switchD_0060f8ac_default;
      case 9:
        sVar24 = 0x20;
        if (uVar22 < 0x21) {
          sVar24 = uVar22;
        }
        pcVar20 = (char *)((int)pvVar8 + 0x98);
        goto LAB_0060faa4;
      case 10:
        sVar24 = 0x20;
        if (uVar22 < 0x21) {
          sVar24 = uVar22;
        }
        pcVar20 = (char *)((int)pvVar8 + 0xb9);
LAB_0060faa4:
        strncpy(pcVar20,(char *)(pbVar31 + 2),sVar24);
        goto switchD_0060f8ac_default;
      case 0xb:
        if (uVar22 != 1) {
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_IS_MESH_DEVICE len error: %d\n\n";
            uVar34 = 0x6eb;
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        *(uint *)((int)pvVar8 + 0x7c) = (uint)(pbVar31[2] != 0);
        break;
      case 0xc:
        if (uVar22 != 1) {
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_PRODUCT_TYPE len error: %d\n\n";
            uVar34 = 0x6f7;
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        *(uint *)((int)pvVar8 + 0x80) = (uint)pbVar31[2];
        break;
      case 0xd:
      case 0xe:
        break;
      case 0xf:
        if (uVar22 != 1) {
          if (apdb_err_switch != 0) {
            pcVar20 = 
            "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_SUPPORT_LARGE_FW_UPGRADE len error: %d\n\n";
            uVar34 = 0x6e0;
            goto LAB_0060f978;
          }
          goto LAB_0060f948;
        }
        *(uint *)((int)pvVar8 + 0x78) = (uint)(pbVar31[2] != 0);
        break;
      default:
        goto switchD_0060f8ac_default;
      }
switchD_0060f8ac_default:
      if (pbVar30 == (byte *)0xffffffff) {
        bVar5 = true;
        goto LAB_0060f074;
      }
      local_98 = local_98 + (-2 - (uint)pbVar31[1]);
      pbVar31 = pbVar31 + pbVar31[1] + 2;
    }
    if ((0 < (int)local_98) && (pbVar30 = (byte *)0xffffffff, apdb_err_switch != 0)) {
      printf("[APDB_ERROR]%s()/line %d : Msg remain len %d after managed\n\n","_apdb_pkt_manage",
             0x757,local_98);
    }
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : ENTER INTO _apdb_pkt_parse\n","_apdb_pkt_parse",0x573);
    }
    if (((param_3 == 0) || (param_4 == (byte *)0x0)) || (param_5 == 0)) {
      if (apdb_err_switch != 0) {
        pcVar20 = "[APDB_ERROR]%s()/line %d : input invalid\n";
        uVar34 = 0x57f;
LAB_0060ffa8:
        printf(pcVar20,"_apdb_pkt_parse",uVar34);
      }
LAB_0060ff70:
      if (apdb_err_switch == 0) {
LAB_0060ff7c:
        bVar5 = false;
        pbVar30 = (byte *)0xffffffff;
      }
      else {
        bVar5 = false;
        printf("[APDB_ERROR]%s()/line %d : parse pkt failed!\n","_apdb_pkt_manage",0x75d);
        pbVar30 = (byte *)0xffffffff;
      }
      goto LAB_0060f074;
    }
    if (*(int *)((int)pvVar8 + 0x160) < 1) {
      if (apdb_err_switch != 0) {
        pcVar20 = "[APDB_ERROR]%s()/line %d :  model_found_flag = 0\n";
        uVar34 = 0x58e;
        goto LAB_0060ffa8;
      }
      goto LAB_0060ff70;
    }
    pbVar31 = (byte *)cw_msg_ele_priv_val_get_from_pkt(param_3,0xa2);
    if (pbVar31 != (byte *)0x0) {
      if (*(int *)((int)pvVar8 + 0x160) < 1) {
        if (apdb_err_switch != 0) {
          pcVar20 = "[APDB_ERROR]%s()/line %d :  model_found_flag = 0\n";
          uVar34 = 0x32e;
LAB_0061031c:
          printf(pcVar20,"_apdb_pkt_parse_phy_info",uVar34);
        }
      }
      else {
        *(undefined1 *)(*(int *)((int)pvVar8 + 0x164) + 0x14) = 0;
        if (*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x2c) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x2c) = 0;
        }
        bVar2 = *pbVar31;
        uVar22 = (uint)bVar2;
        puVar9 = *(undefined1 **)(pbVar31 + 4);
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : phy_num=%d\n","_apdb_pkt_parse_phy_info",0x335,uVar22);
        }
        if ((puVar9 == (undefined1 *)0x0) || (uVar22 == 0)) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : phy_info_value->phy_info_item is null or phy_num(%d) invalid\n"
                   ,"_apdb_pkt_parse_phy_info",0x339,uVar22);
          }
        }
        else {
          *(byte *)(*(int *)((int)pvVar8 + 0x164) + 0x14) = bVar2;
          iVar7 = *(int *)((int)pvVar8 + 0x164);
          uVar34 = FUN_00408450(uVar22 << 3,0x340);
          *(undefined4 *)(iVar7 + 0x2c) = uVar34;
          pvVar11 = *(void **)(*(int *)((int)pvVar8 + 0x164) + 0x2c);
          if (pvVar11 != (void *)0x0) {
            memset(pvVar11,0,uVar22 << 3);
            for (uVar10 = 0; (uVar10 & 0xff) < uVar22; uVar10 = uVar10 + 1) {
              iVar7 = uVar10 * 8;
              *(undefined1 *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x2c) + iVar7) = *puVar9;
              *(undefined1 *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x2c) + iVar7 + 1) =
                   puVar9[1];
              puVar1 = (undefined4 *)(puVar9 + 4);
              puVar9 = puVar9 + 8;
              *(undefined4 *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x2c) + iVar7 + 4) = *puVar1;
            }
            goto LAB_00610358;
          }
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : phy_info mem malloc fail\n";
            uVar34 = 0x343;
            goto LAB_0061031c;
          }
        }
      }
      if (apdb_err_switch != 0) {
        pcVar20 = "[APDB_ERROR]%s()/line %d : parse phy info failed!\n";
        uVar34 = 0x595;
        goto LAB_0060ffa8;
      }
      goto LAB_0060ff70;
    }
    if (apdb_warning_switch != 0) {
      printf("[APDB_WARNING]%s()/line %d : phy_info_value is null \n","_apdb_pkt_parse_phy_info",
             0x319);
    }
LAB_00610358:
    pbVar31 = (byte *)cw_msg_ele_priv_val_get_from_pkt(param_3,0x97);
    memset(&local_300,0,0x40);
    memset(acStack_280,0,0x80);
    if (pbVar31 == (byte *)0x0) {
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : region_list val is null\n",
               "_apdb_pkt_parse_region_list",0x538);
      }
    }
    else {
      bVar2 = *pbVar31;
      pbVar23 = (byte *)(uint)bVar2;
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : region_count=%d\n","_apdb_pkt_parse_region_list",0x53d,
               pbVar23);
      }
      if ((*(int *)(pbVar31 + 4) == 0) || (pbVar23 == (byte *)0x0)) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : region_list_val->region_list_items is null or region_count(%d) invalid\n"
                 ,"_apdb_pkt_parse_region_list",0x540,pbVar23);
        }
      }
      else {
        *(byte *)(*(int *)((int)pvVar8 + 0x164) + 0x15) = bVar2;
        if (*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x30) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x30) = 0;
        }
        iVar7 = *(int *)((int)pvVar8 + 0x164);
        uVar34 = FUN_00408450((int)pbVar23 * 0xc3,0x54b);
        *(undefined4 *)(iVar7 + 0x30) = uVar34;
        pvVar11 = *(void **)(*(int *)((int)pvVar8 + 0x164) + 0x30);
        if (pvVar11 == (void *)0x0) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : region_list mem malloc fail\n",
                   "_apdb_pkt_parse_region_list",0x54e);
          }
          if (apdb_err_switch != 0) {
            pcVar20 = "[APDB_ERROR]%s()/line %d : parse reginon info failed!\n";
            uVar34 = 0x59e;
            goto LAB_0060ffa8;
          }
          goto LAB_0060ff70;
        }
        memset(pvVar11,0,(int)pbVar23 * 0xc3);
        iVar32 = *(int *)(pbVar31 + 4);
        iVar7 = 0;
        local_84 = pbVar28;
        local_98 = pbVar30;
        local_8c = pbVar23;
        local_80 = param_4;
        for (uVar22 = 0; pbVar28 = local_84, param_4 = local_80, pbVar30 = local_98,
            (byte *)(uVar22 & 0xff) < local_8c; uVar22 = uVar22 + 1) {
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : table_row_loop i=%d\n","_apdb_pkt_parse_region_list",
                   0x559,uVar22);
          }
          bVar2 = ((byte *)(iVar32 + iVar7))[1];
          uVar10 = (uint)bVar2;
          bVar3 = *(byte *)(iVar32 + iVar7);
          strncpy((char *)&local_300,(char *)(iVar32 + iVar7 + 2),uVar10);
          bVar4 = *(byte *)(iVar32 + uVar10 + iVar7 + 2);
          uVar29 = (uint)bVar4;
          strncpy(acStack_280,(char *)(iVar32 + uVar10 + iVar7 + 3),uVar29);
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : code=%d, name_len=%d, ch_lst_len=%d\n",
                   "_apdb_pkt_parse_region_list",0x560,(uint)bVar3,uVar10,uVar29);
          }
          iVar26 = uVar22 * 0xc3;
          *(byte *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x30) + iVar26) = bVar3;
          *(byte *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x30) + iVar26 + 1) = bVar2;
          *(byte *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x30) + iVar26 + 2) = bVar4;
          iVar7 = iVar7 + uVar10 + 3 + uVar29;
          strncpy((char *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x30) + iVar26 + 3),
                  (char *)&local_300,0x40);
          strncpy((char *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x30) + iVar26 + 0x43),
                  acStack_280,0x80);
          memset(acStack_280,0,0x80);
        }
      }
    }
    pbVar31 = (byte *)cw_msg_ele_priv_val_get_from_pkt(param_3,0x7f);
    iVar7 = cw_msg_ele_priv_val_get_from_pkt(param_3,0x90);
    memset(&local_300,0,0x20);
    if ((pbVar31 == (byte *)0x0) || (iVar7 == 0)) {
      iVar7 = (int)pvVar8 + 0xb9;
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : rrst_val or rrt_control_val is null\n",
               "_apdb_pkt_parse_rrst",0x434);
        iVar7 = (int)pvVar8 + 0xb9;
      }
    }
    else {
      apdb_init_region_code_list(&local_300);
      puVar12 = (uint *)cw_priv_radio_role_table_control_tlv_ele_get(iVar7,1);
      local_70 = 0;
      if ((puVar12 != (uint *)0x0) && (local_70 = *puVar12, apdb_debug_switch != 0)) {
        printf("[APDB_DEBUG]%s()/line %d : rrt_control_param_capability_val->param_capability:%d\n",
               "_apdb_pkt_parse_rrst",0x440,local_70);
      }
      if (apdb_debug_switch == 0) {
        bVar2 = *pbVar31;
      }
      else {
        printf("[APDB_DEBUG]%s()/line %d : ap_rrt_support_row:%d\n","_apdb_pkt_parse_rrst",0x446,
               local_70);
        bVar2 = *pbVar31;
      }
      local_80 = (byte *)(uint)bVar2;
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : table_row_cnt=%d\n","_apdb_pkt_parse_rrst",0x449,local_80
              );
      }
      if ((*(int *)(pbVar31 + 4) == 0) || (local_80 == (byte *)0x0)) {
        local_98 = (byte *)0x0;
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : rrst_val->table_list is null or table_row_cnt(%d) invalid\n"
                 ,"_apdb_pkt_parse_rrst",0x44c,local_80);
        }
      }
      else {
        *(byte **)(*(int *)((int)pvVar8 + 0x164) + 4) = local_80;
        if (*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x34) = 0;
        }
        iVar7 = *(int *)((int)pvVar8 + 0x164);
        sVar24 = (int)local_80 * 0x1fc;
        uVar34 = FUN_00408450(sVar24,0x457);
        *(undefined4 *)(iVar7 + 0x34) = uVar34;
        pvVar11 = *(void **)(*(int *)((int)pvVar8 + 0x164) + 0x34);
        if (pvVar11 == (void *)0x0) {
          local_98 = (byte *)0xffffffff;
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : rrst mem malloc fail\n","_apdb_pkt_parse_rrst",0x45a)
            ;
          }
        }
        else {
          memset(pvVar11,0,sVar24);
          pcVar20 = (char *)0x0;
          local_8c = *(byte **)(pbVar31 + 4);
          local_98 = (byte *)0x0;
          local_54 = (byte *)0x0;
          local_84 = (byte *)0x0;
          local_68 = pbVar30;
          local_64 = pbVar28;
          local_60 = param_4;
          for (local_6c = 0; pbVar28 = local_64, param_4 = local_60, pbVar30 = local_68,
              (int)local_6c < (int)local_80; local_6c = local_6c + 1 & 0xff) {
            if (apdb_debug_switch != 0) {
              printf("[APDB_DEBUG]%s()/line %d : table_row_loop i=%d\n","_apdb_pkt_parse_rrst",0x467
                     ,local_6c);
            }
            local_58 = (uint)local_8c[4];
            local_3c = (uint)local_8c[9];
            uVar33 = *(undefined4 *)local_8c;
            uVar34 = *(undefined4 *)(local_8c + 5);
            local_34 = local_8c + 10;
            local_38 = local_70 & 1;
            if (local_38 != 0) {
              local_84 = (byte *)(uint)local_8c[10];
              local_54 = local_8c + 0xb;
              local_34 = local_34 + (int)(local_84 + 1);
              memset(acStack_280,0,0x80);
              param_4 = local_60;
              pbVar28 = local_64;
              pbVar30 = local_68;
              local_32c = (char *)0x0;
              if ((local_54 == (byte *)0x0) || (local_84 == (byte *)0x0)) {
                if (apdb_err_switch != 0) {
                  printf("[APDB_ERROR]%s()/line %d :  input string data null.\n",
                         "_apdb_pkt_parse_rrst_region_code_list",0x365);
                }
                local_98 = (byte *)0xffffffff;
                if (apdb_err_switch != 0) {
                  printf("[APDB_ERROR]%s()/line %d : _apdb_pkt_parse_rrst_region_code_list failed\n"
                         ,"_apdb_pkt_parse_rrst",0x47a);
                }
                break;
              }
              pbVar30 = (byte *)0x80;
              if (local_84 < (byte *)0x81) {
                pbVar30 = local_84;
              }
              iVar7 = 0;
              memcpy(acStack_280,local_54,(size_t)pbVar30);
              pcVar21 = strtok_r(acStack_280," ",&local_32c);
              while ((pcVar21 != (char *)0x0 && (iVar7 < 0x20))) {
                uVar22 = atoi(pcVar21);
                if (uVar22 < 0x20) {
                  iVar7 = iVar7 + 1;
                  *(undefined1 *)((int)&local_300 + uVar22) = 1;
                }
                pcVar21 = strtok_r((char *)0x0," ",&local_32c);
              }
            }
            if (apdb_debug_switch != 0) {
              printf("[APDB_DEBUG]%s()/line %d : feature_involved=%d, radio_num=%d, sub_type_num=%d region_list_len=%d region_list:%s\n"
                     ,"_apdb_pkt_parse_rrst",0x47f,uVar34,local_58,local_3c,local_84,local_54);
            }
            param_4 = local_60;
            pbVar28 = local_64;
            pbVar30 = local_68;
            if (local_58 == 0) {
              local_98 = (byte *)0xffffffff;
              if (apdb_err_switch != 0) {
                pcVar21 = "[APDB_ERROR]%s()/line %d : radio_num=%d invalid\n";
                uVar34 = 0x483;
LAB_00610f00:
                local_98 = (byte *)0xffffffff;
                printf(pcVar21,"_apdb_pkt_parse_rrst",uVar34,0);
              }
              break;
            }
            if (local_3c == 0) {
              local_98 = (byte *)0xffffffff;
              if (apdb_err_switch != 0) {
                pcVar21 = "[APDB_ERROR]%s()/line %d : sub_type_num=%d invalid\n";
                uVar34 = 0x48a;
                goto LAB_00610f00;
              }
              break;
            }
            iVar7 = local_6c * 0x1fc;
            *(undefined4 *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) + iVar7) = uVar34;
            *(char *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) + iVar7 + 8) = (char)local_58;
            *(undefined4 *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) + iVar7 + 4) = uVar33;
            if (local_38 != 0) {
              memcpy((void *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) + iVar7 + 9),&local_300
                     ,0x20);
            }
            local_50 = 0;
            local_4c = 0;
            do {
              uVar22 = local_50 & 0xff;
              if (local_58 <= uVar22) break;
              if (apdb_debug_switch != 0) {
                printf("[APDB_DEBUG]%s()/line %d :     radio_num_loop j=%d\n","_apdb_pkt_parse_rrst"
                       ,0x49d,local_50);
              }
              local_48 = 0;
              for (local_5c = 0; (local_5c & 0xff) < local_3c; local_5c = local_5c + 1) {
                if (apdb_debug_switch != 0) {
                  printf("[APDB_DEBUG]%s()/line %d :         sub_type_num_loop k=%d\n",
                         "_apdb_pkt_parse_rrst",0x4a2,local_5c);
                }
                pbVar30 = local_34 + local_48 + local_4c;
                uVar10 = (uint)pbVar30[1];
                local_48 = local_48 + uVar10 + 2;
                if (apdb_debug_switch == 0) {
                  bVar2 = *pbVar30;
                }
                else {
                  printf("[APDB_DEBUG]%s()/line %d : thr sub_type is:%d\n","_apdb_pkt_parse_rrst",
                         0x4a6,(uint)*pbVar30);
                  bVar2 = *pbVar30;
                }
                switch(bVar2 - 1) {
                case 0:
                  if (uVar10 == 1) {
                    *(byte *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) + iVar7 + uVar22 * 0x74
                             + 0x98) = pbVar30[2];
                  }
                  else {
                    local_98 = (byte *)0xffffffff;
                    if (apdb_err_switch != 0) {
                      pcVar21 = 
                      "[APDB_ERROR]%s()/line %d : APDB_RRST_SUB_TYPE_RADIO_ID len error: %d\n\n";
                      uVar34 = 0x4ac;
LAB_006108c8:
                      local_98 = (byte *)0xffffffff;
                      printf(pcVar21,"_apdb_pkt_parse_rrst",uVar34,uVar10);
                    }
                  }
                  break;
                case 1:
                  if (uVar10 == 4) {
                    *(undefined4 *)
                     (*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) + iVar7 + uVar22 * 0x74 + 0x2c)
                         = *(undefined4 *)(pbVar30 + 2);
                  }
                  else {
                    local_98 = (byte *)0xffffffff;
                    if (apdb_err_switch != 0) {
                      pcVar21 = 
                      "[APDB_ERROR]%s()/line %d : APDB_RRST_SUB_TYPE_RADIO_STATUS len error: %d\n\n"
                      ;
                      uVar34 = 0x4b5;
                      goto LAB_006108c8;
                    }
                  }
                  break;
                case 2:
                  if (apdb_debug_switch != 0) {
                    printf("[APDB_DEBUG]%s()/line %d : enter APDB_RRST_SUB_TYPE_BIND_ID\n",
                           "_apdb_pkt_parse_rrst",0x4be);
                  }
                  if (uVar10 == 1) {
                    if (apdb_debug_switch != 0) {
                      printf("[APDB_DEBUG]%s()/line %d : the bind id is %d\n","_apdb_pkt_parse_rrst"
                             ,0x4c5,(uint)pbVar30[2]);
                    }
                    if ((local_70 & 2) != 0) {
                      *(byte *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) + iVar7 +
                                uVar22 * 0x74 + 0x9a) = pbVar30[2];
                    }
                  }
                  else {
                    if (apdb_err_switch != 0) {
                      printf("[APDB_ERROR]%s()/line %d : APDB_RRST_SUB_TYPE_BIND_ID len error: %d\n\n"
                             ,"_apdb_pkt_parse_rrst",0x4c1,uVar10);
                    }
                    if (apdb_err_switch != 0) {
                      pcVar21 = 
                      "[APDB_ERROR]%s()/line %d : Cannot return error because some ap report error\n\n"
                      ;
                      uVar34 = 0x4c2;
                      goto LAB_00610cb0;
                    }
                  }
                  break;
                case 3:
                  pcVar20 = (char *)FUN_00408450(uVar10 + 1,0x4cb);
                  if (pcVar20 == (char *)0x0) {
                    local_98 = (byte *)0xffffffff;
                    if (apdb_err_switch != 0) {
                      pcVar21 = 
                      "[APDB_ERROR]%s()/line %d : Failed to malloc memory for APDB_RRST_SUB_TYPE_BANDWIDTH\n"
                      ;
                      uVar34 = 0x4ce;
LAB_00610cb0:
                      printf(pcVar21,"_apdb_pkt_parse_rrst",uVar34);
                    }
                  }
                  else {
                    memset(pcVar20,0,uVar10 + 1);
                    strncpy(pcVar20,(char *)(pbVar30 + 2),(uint)pbVar30[1]);
                    if (apdb_debug_switch == 0) {
                      iVar32 = *(int *)((int)pvVar8 + 0x164);
                    }
                    else {
                      printf("[APDB_DEBUG]%s()/line %d : bandwidth str=%s\n","_apdb_pkt_parse_rrst",
                             0x4d4,pcVar20);
                      iVar32 = *(int *)((int)pvVar8 + 0x164);
                    }
                    local_32c = (char *)0x0;
                    local_74 = *(int *)(iVar32 + 0x34) + iVar7;
                    if (local_74 + uVar22 * 0x74 == -0x99) {
                      if (apdb_err_switch != 0) {
                        printf("[APDB_ERROR]%s()/line %d : _apdb_parse_rrst_sub_type_bandwidth, input string data null.\n"
                               ,"_apdb_pkt_parse_rrst_bandwidth",900);
                      }
                      local_98 = (byte *)0xffffffff;
                      if (apdb_err_switch != 0) {
                        pcVar21 = "[APDB_ERROR]%s()/line %d : failed to parse rrst bandwidth\n";
                        uVar34 = 0x4d7;
                        goto LAB_00610cb0;
                      }
                    }
                    else {
                      cVar27 = '\a';
                      uVar10 = 0;
                      pcVar21 = strtok_r(pcVar20," ",&local_32c);
                      while ((pcVar21 != (char *)0x0 && (cVar27 = cVar27 + -1, cVar27 != '\0'))) {
                        uVar29 = get_apdb_flag_bit(pcVar21);
                        if (uVar29 == 0xffffffff) {
                          if (apdb_warning_switch != 0) {
                            printf("[APDB_WARNING]%s()/line %d : parse bandwidth:undefined number.\n\n"
                                   ,"_apdb_pkt_parse_rrst_bandwidth",0x392);
                          }
                        }
                        else {
                          uVar10 = 1 << (uVar29 & 0x1f) & 0xffU | uVar10;
                        }
                        pcVar21 = strtok_r((char *)0x0," ",&local_32c);
                      }
                      *(char *)(local_74 + uVar22 * 0x74 + 0x99) = (char)uVar10;
LAB_00610c04:
                      FUN_00407df0(pcVar20);
                      pcVar20 = (char *)0x0;
                    }
                  }
                  break;
                case 4:
                  pcVar20 = (char *)FUN_00408450(uVar10 + 1,0x4e2);
                  if (pcVar20 == (char *)0x0) {
                    local_98 = (byte *)0xffffffff;
                    if (apdb_err_switch != 0) {
                      pcVar21 = 
                      "[APDB_ERROR]%s()/line %d : Failed to malloc memory for APDB_RRST_SUB_TYPE_CHANNEL\n"
                      ;
                      uVar34 = 0x4e5;
                      goto LAB_00610cb0;
                    }
                  }
                  else {
                    memset(pcVar20,0,uVar10 + 1);
                    strncpy(pcVar20,(char *)(pbVar30 + 2),(uint)pbVar30[1]);
                    if (apdb_debug_switch == 0) {
                      iVar32 = *(int *)((int)pvVar8 + 0x164);
                    }
                    else {
                      printf("[APDB_DEBUG]%s()/line %d : chnl str=%s\n","_apdb_pkt_parse_rrst",0x4eb
                             ,pcVar20);
                      iVar32 = *(int *)((int)pvVar8 + 0x164);
                    }
                    local_32c = (char *)0x0;
                    iVar32 = *(int *)(iVar32 + 0x34) + iVar7 + uVar22 * 0x74;
                    iVar26 = iVar32 + 0x2c;
                    local_330 = (char *)0x0;
                    if (iVar26 != 0) {
                      pcVar21 = strtok_r(pcVar20," ",&local_32c);
                      local_40 = pvVar8;
LAB_00610978:
                      pvVar8 = local_40;
                      if (pcVar21 == (char *)0x0) goto LAB_00610c04;
                      iVar13 = strcmp(pcVar21,"equal");
                      if (iVar13 == 0) {
                        *(undefined4 *)(iVar32 + 0x9c) = 1;
                      }
                      else {
                        pcVar14 = strstr(pcVar21,"default");
                        if (pcVar14 == (char *)0x0) {
                          pcVar14 = strchr(pcVar21,0x2d);
                          if (pcVar14 == (char *)0x0) {
                            pcVar14 = strchr(pcVar21,0x3a);
                            if (pcVar14 == (char *)0x0) {
                              iVar25 = 0;
                              iVar13 = iVar26;
                              do {
                                if (*(short *)(iVar13 + 6) == 0) {
                                  iVar13 = atoi(pcVar21);
                                  uVar19 = 0xffff;
                                  if ((short)iVar13 == 0) {
                                    iVar25 = iVar25 * 2;
                                  }
                                  else {
                                    if (((short)iVar13 < 1) ||
                                       (iVar13 = _apdb_is_chnl_legal(), iVar13 != 1)) break;
                                    iVar25 = iVar25 << 1;
                                    iVar13 = atoi(pcVar21);
                                    uVar19 = (undefined2)iVar13;
                                  }
                                  *(undefined2 *)(iVar26 + iVar25 + 6) = uVar19;
                                  break;
                                }
                                iVar25 = iVar25 + 1;
                                iVar13 = iVar13 + 2;
                              } while (iVar25 != 0x33);
                            }
                            else if (apdb_debug_switch != 0) {
                              printf("[APDB_DEBUG]%s()/line %d : the p_token is %s\n",
                                     "_apdb_pkt_parse_rrst_channel",0x3f4,pcVar21);
                            }
                          }
                          else {
                            local_330 = (char *)0x0;
                            pcVar21 = strtok_r(pcVar21,"-",(char **)&local_330);
                            local_30 = atoi(pcVar21);
                            local_74 = (int)(short)local_30;
                            pcVar21 = strtok_r((char *)0x0,"-",(char **)&local_330);
                            iVar13 = atoi(pcVar21);
                            pvVar8 = local_40;
                            local_44 = (int)(short)iVar13;
                            if (((local_44 < local_74) || (local_74 < 0)) || (local_44 < 0)) {
                              if (apdb_err_switch != 0) {
                                printf("[APDB_ERROR]%s()/line %d : input channel error %d-%d when parse from msgele.\n\n"
                                       ,"_apdb_pkt_parse_rrst_channel",0x3d2,local_74,local_44);
                              }
                              goto LAB_00610d7c;
                            }
                            iVar25 = 0;
                            iVar13 = iVar26;
                            do {
                              if (*(short *)(iVar13 + 6) == 0) {
                                iVar13 = 0;
                                goto LAB_00610b50;
                              }
                              iVar25 = iVar25 + 1;
                              iVar13 = iVar13 + 2;
                            } while (iVar25 != 0x33);
                          }
                        }
                        else {
                          local_330 = (char *)0x0;
                          strtok_r(pcVar21,":",(char **)&local_330);
                          pcVar21 = strtok_r((char *)0x0,":",(char **)&local_330);
                          iVar13 = atoi(pcVar21);
                          pvVar8 = local_40;
                          sVar18 = (short)iVar13;
                          if (sVar18 == 0) {
                            *(undefined2 *)(iVar32 + 0x30) = 0xffff;
                            goto LAB_006109a4;
                          }
                          if (sVar18 < 1) {
                            if (apdb_err_switch != 0) {
                              printf("[APDB_ERROR]%s()/line %d : default channel parse error,the defalut channel is:%d.\n"
                                     ,"_apdb_pkt_parse_rrst_channel",0x3c7);
                            }
                            goto LAB_00610d7c;
                          }
                          *(short *)(iVar32 + 0x30) = sVar18;
                        }
                      }
                      goto LAB_006109a4;
                    }
                    if (apdb_err_switch != 0) {
                      printf("[APDB_ERROR]%s()/line %d : input invalid\n",
                             "_apdb_pkt_parse_rrst_channel",0x3a9);
                    }
LAB_00610d7c:
                    local_98 = (byte *)0xffffffff;
                    if (apdb_err_switch != 0) {
                      pcVar21 = "[APDB_ERROR]%s()/line %d : failed to parse rrst channel\n";
                      uVar34 = 0x4ee;
                      goto LAB_00610cb0;
                    }
                  }
                }
              }
              local_4c = local_4c + local_48;
              local_50 = local_50 + 1;
            } while (local_98 == (byte *)0x0);
            local_8c = local_8c + local_4c + 10;
            if (local_38 != 0) {
              local_8c = local_8c + (int)(local_84 + 1);
              apdb_init_region_code_list(&local_300);
            }
            pbVar28 = local_64;
            param_4 = local_60;
            pbVar30 = local_68;
            if (local_98 != (byte *)0x0) break;
          }
          if (pcVar20 != (char *)0x0) {
            FUN_00407df0(pcVar20);
          }
        }
      }
      if (local_98 != (byte *)0x0) {
        if (*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x34) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 4) = 0;
          *(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x34) = 0;
        }
        if (apdb_err_switch != 0) {
          pcVar20 = "[APDB_ERROR]%s()/line %d : parse rrst info failed!\n";
          uVar34 = 0x5a8;
          goto LAB_0060ffa8;
        }
        goto LAB_0060ff70;
      }
      iVar7 = (int)pvVar8 + 0xb9;
    }
    iVar32 = _apdb_sales_method_match(iVar7);
    if (iVar32 == 0) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : sales method not supported, act:%s\n\n",
               "_apdb_pkt_manage",0x765,iVar7);
      }
LAB_006110fc:
      bVar5 = true;
      pbVar30 = (byte *)0x0;
      goto LAB_0060f074;
    }
    iVar7 = _apdb_product_type_match(*(undefined4 *)((int)pvVar8 + 0x80));
    if (iVar7 == 0) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : product type not supported, act:%d, support:(%d.%d)\n\n",
               "_apdb_pkt_manage",0x76c,*(undefined4 *)((int)pvVar8 + 0x80),0xffffffff,4);
      }
      goto LAB_006110fc;
    }
    if (*(char *)((int)pvVar8 + 0xda) == '\0') {
      if ((param_4[0xc] == 0) || (bVar5 = false, *(int *)((int)pvVar8 + 0x80) == 0)) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : Not include apname\n\n","_apdb_pkt_manage",0x77a);
        }
        local_328 = 1;
LAB_006111f0:
        bVar5 = true;
        pbVar30 = (byte *)0xffffffff;
      }
      goto LAB_0060f074;
    }
    if (*(int *)((int)pvVar8 + 0x10) == 0) {
      iVar7 = _apdb_name_and_hw_exist
                        ((int)pvVar8 + 0xda,*(undefined4 *)((int)pvVar8 + 0x164),pbVar28[0xe]);
      if (iVar7 != 0) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : AP name and hw entry existed, no need to manage.\n\n",
                 "_apdb_pkt_manage",0x785);
        }
        bVar5 = false;
        pbVar30 = (byte *)0x0;
        goto LAB_0060f074;
      }
      iVar7 = *(int *)((int)pvVar8 + 0x10);
    }
    else {
      iVar7 = *(int *)((int)pvVar8 + 0x10);
    }
    pcVar20 = (char *)((int)pvVar8 + 0xda);
    if (iVar7 == 0) {
      iVar7 = apdb_get_ap_by_name_and_hwver
                        (pcVar20,*(undefined4 *)((int)pvVar8 + 0x164),auStack_200);
      if (iVar7 == 0) {
        *(undefined4 *)((int)pvVar8 + 0x10) = local_1f0;
      }
      else {
        iVar7 = *(int *)((int)pvVar8 + 0x164);
        if (iVar7 == 0) {
LAB_00611318:
          iVar7 = 1;
          do {
            iVar32 = apdb_id_valid(iVar7);
            if (iVar32 == 0) goto LAB_0061133c;
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x65);
          iVar7 = 0;
        }
        else {
          sVar24 = strlen(pcVar20);
          uVar34 = FUN_004083d0(pcVar20,sVar24,0);
          uVar22 = FUN_004083d0(iVar7,4,uVar34);
          iVar7 = apdb_id_valid(uVar22);
          if (iVar7 == 0) goto LAB_00611318;
          iVar7 = uVar22 % 100 + 1;
        }
LAB_0061133c:
        *(int *)((int)pvVar8 + 0x10) = iVar7;
        if (iVar7 == 0) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : Alloca id failed\n","_apdb_pkt_manage",0x791);
          }
          goto LAB_006111f0;
        }
      }
    }
    if ((pbVar30 == (byte *)0x0) && (local_90 != 0)) {
      iVar7 = *(int *)((int)pvVar8 + 0x164);
      sVar24 = local_90 * 0x114;
      uVar34 = FUN_00408450(sVar24,0x79e);
      *(undefined4 *)(iVar7 + 0x28) = uVar34;
      pvVar11 = *(void **)(*(int *)((int)pvVar8 + 0x164) + 0x28);
      if (pvVar11 != (void *)0x0) {
        memset(pvVar11,0,sVar24);
        *(int *)(*(int *)((int)pvVar8 + 0x164) + 0x10) = local_90;
        _apdb_radio_copy(*(undefined4 *)(*(int *)((int)pvVar8 + 0x164) + 0x28),local_94,local_90);
        goto LAB_00611274;
      }
      goto LAB_0060ff7c;
    }
LAB_00611274:
    if (apdb_debug_switch != 0) {
      printf("Add new ap: %s, id: %x, vendor: %d\n",(int)pvVar8 + 0xda,
             *(undefined4 *)((int)pvVar8 + 0x10),*(undefined4 *)((int)pvVar8 + 0x18));
      iVar7 = 0;
      printf("  ext_phy: %d, is_hd: %d, ap_trunk: %d\n",*(undefined4 *)((int)pvVar8 + 0x14),
             *(undefined4 *)((int)pvVar8 + 0x1c),*(undefined4 *)((int)pvVar8 + 0x70));
      puts("  linked modified 2.4G:");
      pvVar11 = pvVar8;
      do {
        pcVar20 = "1 ";
        if (*(int *)((int)pvVar11 + 0x20) != 1) {
          pcVar20 = "0 ";
        }
        iVar7 = iVar7 + 4;
        printf(pcVar20);
        pvVar11 = (void *)((int)pvVar8 + iVar7);
      } while (iVar7 != 0x28);
      putchar(10);
      iVar7 = 0;
      puts("  linked modified 5G:");
      pvVar11 = pvVar8;
      do {
        pcVar20 = "1 ";
        if (*(int *)((int)pvVar11 + 0x48) != 1) {
          pcVar20 = "0 ";
        }
        iVar7 = iVar7 + 4;
        printf(pcVar20);
        pvVar11 = (void *)((int)pvVar8 + iVar7);
      } while (iVar7 != 0x28);
      putchar(10);
      psVar16 = *(short **)((int)pvVar8 + 0x164);
      printf("  hwver: %d.%d, model cnt :%d, radios cnt: %d\n",(int)*psVar16,(int)psVar16[1],
             *(undefined4 *)((int)pvVar8 + 0x160),*(undefined4 *)(psVar16 + 8));
      local_98 = param_4;
      for (iVar7 = 0; iVar32 = *(int *)((int)pvVar8 + 0x164), param_4 = local_98,
          iVar7 < *(int *)(iVar32 + 0x10); iVar7 = iVar7 + 1) {
        iVar26 = iVar7 * 0x114;
        memset(&local_300,0,0x21);
        _apdb_extend_cap_transfer_to_str
                  (*(int *)(iVar32 + 0x28) + iVar26 + 0x100,0x10,&local_300,0x21);
        piVar17 = (int *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x28) + iVar26);
        printf("    Radios %s: maxssid: %d, maxstation: %d, max_txpower: %d, min_txpower: %d, real_max_txpower: %d, real_min_txpower: %d, dftbwmode: %d, dft_txpower: %d, real_dft_txpower: %d, mutex_ch: %s, max_tx_stream:%d, max_rx_stream:%d, extend_cap:%s\n"
               ,(&PTR_s_2_4GHz_00704e00)[*piVar17],(int)*(short *)(piVar17 + 7),
               (int)*(short *)((int)piVar17 + 0x1e),(int)*(short *)(piVar17 + 8),
               (int)*(short *)((int)piVar17 + 0x22),(int)*(short *)((int)piVar17 + 0x26),
               (int)*(short *)(piVar17 + 10),piVar17[0xc],(int)*(short *)(piVar17 + 9),
               (int)*(short *)((int)piVar17 + 0x2a),piVar17 + 0xe,(uint)*(byte *)(piVar17 + 0xb),
               (uint)*(byte *)((int)piVar17 + 0x2d),&local_300);
        iVar32 = *(int *)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x28) + iVar26 + 0x110);
        if (iVar32 != 0) {
          _apdb_extend_cap_transfer_to_str(iVar32 + 0x100,0x10,&local_300,0x21);
          piVar17 = *(int **)(*(int *)(*(int *)((int)pvVar8 + 0x164) + 0x28) + iVar26 + 0x110);
          printf("        Radios %s: maxssid: %d, maxstation: %d, max_txpower: %d, min_txpower: %d, real_max_txpower: %d, real_min_txpower: %d, dftbwmode: %d, dft_txpower: %d, real_dft_txpower: %d, mutex_ch: %s, max_tx_stream:%d, max_rx_stream:%d, extend_cap:%s\n"
                 ,(&PTR_s_2_4GHz_00704e00)[*piVar17],(int)*(short *)(piVar17 + 7),
                 (int)*(short *)((int)piVar17 + 0x1e),(int)*(short *)(piVar17 + 8),
                 (int)*(short *)((int)piVar17 + 0x22),(int)*(short *)((int)piVar17 + 0x26),
                 (int)*(short *)(piVar17 + 10),piVar17[0xc],(int)*(short *)(piVar17 + 9),
                 (int)*(short *)((int)piVar17 + 0x2a),piVar17 + 0xe,(uint)*(byte *)(piVar17 + 0xb),
                 (uint)*(byte *)((int)piVar17 + 0x2d),&local_300);
        }
      }
    }
    if (pbVar30 == (byte *)0x0) {
      FUN_004082d0(apdb_pkt_mutex,0xffffffff);
      iVar7 = _apdb_add_ap_to_item_list(*(undefined4 *)((int)pvVar8 + 0x10),local_78,pvVar8,0);
      if ((iVar7 == -1) && (pbVar30 = (byte *)0xffffffff, apdb_err_switch != 0)) {
        printf("[APDB_ERROR]%s()/line %d : add ap to item list failed\n","_apdb_pkt_manage",0x7f0);
      }
      if ((local_7c != (void *)0x0) &&
         (iVar7 = _apdb_hw_exist(*(undefined4 *)((int)pvVar8 + 0x10),local_7c), iVar7 == 0)) {
        if (apdb_debug_switch == 0) {
          uVar34 = *(undefined4 *)((int)pvVar8 + 0x10);
        }
        else {
          printf("[APDB_DEBUG]%s()/line %d : need to ensure having default fwid hash node.\n",
                 "_apdb_pkt_manage",0x7f6);
          uVar34 = *(undefined4 *)((int)pvVar8 + 0x10);
        }
        iVar7 = _apdb_add_ap_to_item_list(uVar34,local_7c,pvVar8,0);
        if ((iVar7 == -1) && (pbVar30 = (byte *)0xffffffff, apdb_err_switch != 0)) {
          printf("[APDB_ERROR]%s()/line %d : add ap to item list failed\n","_apdb_pkt_manage",0x7fa)
          ;
        }
      }
      FUN_00407f30(apdb_pkt_mutex);
    }
    else {
      pbVar30 = (byte *)0xffffffff;
    }
    bVar5 = false;
    if (apdb_debug_switch == 0) goto LAB_0060f074;
    printf("[APDB_DEBUG]%s()/line %d : Manage msg done!\n","_apdb_pkt_manage",0x801);
    bVar2 = param_4[1];
  }
  else {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : version not supported, act:%d, support:%d\n\n",
             "_apdb_pkt_manage",0x60d,uVar22,1);
    }
    FUN_004082d0(apdb_pkt_mutex,0xffffffff);
    unrecognize_ap = 1;
    FUN_00407e70();
    unrecognize_ap_lastest_time = extraout_v1;
    if (unknown_ap_flag == 0) {
      _apdb_unknown_ap_record();
      unknown_ap_flag = 1;
    }
    bVar5 = true;
    FUN_00407f30(apdb_pkt_mutex);
    local_88 = 1;
LAB_0060f064:
    pbVar30 = (byte *)0xffffffff;
LAB_0060f068:
    pvVar8 = (void *)0x0;
    local_90 = 0;
    local_94 = (void *)0x0;
LAB_0060f074:
    bVar2 = param_4[1];
  }
  snprintf((char *)&local_314,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_4,(uint)bVar2,
           (uint)param_4[2],(uint)param_4[3],(uint)param_4[4],(uint)param_4[5]);
  if (local_88 == 0) goto LAB_0060f1e0;
  if ((pvVar8 == (void *)0x0) || (*(char *)((int)pvVar8 + 0xda) == '\0')) {
    local_32c = (char *)0x0;
    local_330 = (char *)((uint)local_330 & 0xffff);
    iVar7 = cw_sub_msg_ele_get(param_3,0x26,0);
    if (iVar7 == 0) goto LAB_0060f1e0;
    memcpy(&local_32c,*(void **)(iVar7 + 0x10),(uint)*(ushort *)(iVar7 + 0xe));
    iVar7 = cw_sub_msg_ele_get(param_3,0x27,0);
    if (iVar7 == 0) goto LAB_0060f1e0;
    puVar9 = *(undefined1 **)(iVar7 + 0x14);
    local_330._1_3_ = CONCAT12(puVar9[1],local_330._2_2_);
    local_330 = (char *)CONCAT13(*puVar9,local_330._1_3_);
    sVar18 = local_330._0_2_;
    local_330._1_3_ = CONCAT12(puVar9[3],local_330._2_2_);
    local_330 = (char *)CONCAT13(puVar9[2],local_330._1_3_);
    sVar6 = local_330._0_2_;
    memset(acStack_2c0,0,0x40);
    FUN_00408190(*(undefined4 *)(param_4 + 0x10),*(undefined4 *)(param_4 + 0x14),
                 *(undefined4 *)(param_4 + 0x18),*(undefined4 *)(param_4 + 0x1c),
                 *(undefined4 *)(param_4 + 0x20),acStack_2c0,0x40,"---");
    bVar2 = param_4[0xc];
    uVar34 = 4;
    pcVar20 = local_32c;
  }
  else {
    memset(acStack_2c0,0,0x40);
    FUN_00408190(*(undefined4 *)(param_4 + 0x10),*(undefined4 *)(param_4 + 0x14),
                 *(undefined4 *)(param_4 + 0x18),*(undefined4 *)(param_4 + 0x1c),
                 *(undefined4 *)(param_4 + 0x20),acStack_2c0,0x40,"---");
    bVar2 = param_4[0xc];
    uVar34 = 1;
    pcVar20 = (char *)((int)pvVar8 + 0xda);
    sVar18 = local_324._0_2_;
    sVar6 = local_324._2_2_;
  }
  pcVar21 = acStack_2c0;
  if (bVar2 != 0) {
    pcVar21 = "---";
  }
  loggerk_reg(0x53,0x3cf6,1,pcVar21,1,&local_314,uVar34,pcVar20,2,(int)sVar18,2,(int)sVar6,0);
LAB_0060f1e0:
  if (local_328 != 0) {
    memset(acStack_2c0,0,0x40);
    FUN_00408190(*(undefined4 *)(param_4 + 0x10),*(undefined4 *)(param_4 + 0x14),
                 *(undefined4 *)(param_4 + 0x18),*(undefined4 *)(param_4 + 0x1c),
                 *(undefined4 *)(param_4 + 0x20),acStack_2c0,0x40,"---");
    pcVar20 = acStack_2c0;
    if (param_4[0xc] != 0) {
      pcVar20 = "---";
    }
    loggerk_reg(0x53,0x3cfa,1,pcVar20,1,&local_314,0);
  }
  if (bVar5) {
    FUN_0060ee8c(param_5);
  }
  if (pvVar8 != (void *)0x0) {
    _apdb_ap_free(pvVar8,1);
  }
  if (local_94 != (void *)0x0) {
    _apdb_radio_free(local_94,local_90);
  }
  FUN_00407df0(local_78);
  if (local_7c != (void *)0x0) {
    FUN_00407df0();
  }
  return pbVar30;
LAB_00610b50:
  pvVar8 = local_40;
  if (iVar13 + local_74 <= local_44) {
    if (iVar25 == 0x33) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : channel counts invalid, more than max when parse from msgele.\n\n"
               ,"_apdb_pkt_parse_rrst_channel",0x3df);
      }
      goto LAB_00610c04;
    }
    if (iVar13 + local_74 == 0) {
      *(undefined2 *)(iVar26 + iVar25 * 2 + 6) = 0xffff;
LAB_00610b8c:
      iVar25 = iVar25 + 1;
      iVar13 = iVar13 + 1;
    }
    else {
      iVar15 = _apdb_is_chnl_legal();
      if (iVar15 == 1) {
        *(short *)(iVar26 + iVar25 * 2 + 6) = (short)iVar13 + (short)local_30;
        goto LAB_00610b8c;
      }
      iVar13 = iVar13 + 1;
    }
    goto LAB_00610b50;
  }
LAB_006109a4:
  pcVar21 = strtok_r((char *)0x0," ",&local_32c);
  goto LAB_00610978;
}

