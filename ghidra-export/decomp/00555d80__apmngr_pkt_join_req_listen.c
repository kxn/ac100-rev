// func _apmngr_pkt_join_req_listen @ 00555d80 size=8544

/* WARNING: Type propagation algorithm not settling */

undefined4 _apmngr_pkt_join_req_listen(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  char *pcVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  byte bVar15;
  void *pvVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar16;
  uint *puVar17;
  undefined4 extraout_v1;
  char *pcVar18;
  undefined1 uVar19;
  ushort *puVar20;
  undefined4 uVar21;
  uint uVar22;
  undefined1 *__dest;
  uint uVar23;
  undefined2 uVar24;
  int local_1970 [2];
  short local_1968;
  short sStack_1966;
  undefined4 local_1964;
  undefined4 local_1960;
  undefined2 local_195c;
  undefined4 local_1958;
  undefined4 local_1954;
  undefined4 local_1950;
  undefined4 local_194c;
  undefined4 local_1948;
  undefined4 local_1944;
  undefined4 local_1940;
  undefined4 local_193c;
  undefined4 local_1938;
  undefined4 local_1934;
  undefined4 local_1930;
  undefined4 local_192c;
  undefined4 local_1928;
  undefined1 auStack_1924 [68];
  undefined4 local_18e0;
  undefined2 local_18dc;
  undefined2 local_18be;
  char local_1860 [156];
  short local_17c4 [4];
  undefined4 local_17bc;
  undefined4 local_17b8;
  undefined4 local_17b4;
  undefined2 local_176c;
  undefined2 local_1706;
  undefined1 auStack_1704 [16];
  uint local_16f4;
  int local_1690;
  int local_1688;
  uint local_1684;
  char acStack_162a [65];
  char acStack_15e9 [77];
  undefined1 auStack_159c [116];
  int local_1528;
  char local_14c2 [65];
  char local_1481 [81];
  undefined4 local_1430;
  void *local_142c;
  uint local_11d8;
  undefined1 local_115f;
  undefined1 auStack_1158 [16];
  ushort local_1148;
  undefined2 local_1146;
  int local_1144;
  undefined2 local_1140;
  undefined2 local_1130;
  int local_111c;
  uint local_1118;
  undefined4 local_1114;
  undefined1 auStack_1110 [6];
  char acStack_110a [227];
  undefined1 local_1027;
  undefined1 local_fa4;
  undefined1 local_f52;
  undefined1 local_f51;
  undefined1 local_e87;
  undefined1 auStack_e80 [18];
  undefined2 local_e6e;
  undefined1 auStack_ba8 [16];
  ushort local_b98;
  undefined2 local_b96;
  int local_b94;
  uint local_958 [34];
  undefined1 auStack_8d0 [16];
  ushort local_8c0;
  uint local_8bc;
  undefined2 local_8b8;
  uint local_890;
  int local_88c;
  undefined1 auStack_888 [233];
  char local_79f;
  char local_71c;
  char local_6ca;
  undefined2 local_6c8;
  undefined2 local_6c6;
  undefined2 local_6c4;
  undefined4 local_6c0;
  undefined4 local_6bc;
  undefined1 auStack_6b8 [16];
  byte local_6a8;
  undefined1 auStack_6a7 [33];
  undefined2 local_686;
  undefined2 local_684;
  uint local_680 [4];
  undefined1 auStack_670 [11];
  byte local_665;
  undefined4 local_664;
  undefined4 local_660;
  undefined4 local_65c;
  undefined4 local_658;
  undefined4 local_654;
  ushort local_650;
  undefined4 local_640;
  int local_624;
  undefined1 auStack_5f8 [728];
  undefined4 local_320;
  undefined1 auStack_318 [728];
  undefined4 local_40;
  undefined1 *local_38;
  int local_34;
  void *local_30;
  
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d got a join req packet.\n","_apmngr_pkt_join_req_listen",0x221);
  }
  memset(auStack_8d0,0,0x2d8);
  memset(auStack_ba8,0,0x2d8);
  local_1964 = 0;
  sStack_1966 = 0;
  local_1968 = 0;
  local_1948 = 0;
  local_1944 = 0;
  local_1940 = 0;
  local_193c = 0;
  local_1938 = 0;
  local_1934 = 0;
  local_1930 = 0;
  local_192c = 0;
  local_1928 = 0;
  local_1970[1] = 0;
  local_1960 = 0;
  local_195c = 0;
  memset(auStack_159c,0,0x168);
  memset(auStack_1704,0,0x168);
  memset(auStack_1924,0,0x42);
  memset(auStack_318,0,0x2e0);
  memset(local_1860,0,0x9a);
  piVar1 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    if (apmngr_debug_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar18 = 
    "[APMNGR_DEBUG]%s()/%d Failed to join for formal callback return failed result code.\n";
    uVar21 = 0x24c;
    goto LAB_00556854;
  }
  iVar2 = cw_sub_msg_ele_get(param_1,0x26,0);
  iVar3 = cw_sub_msg_ele_get(param_1,0x27,0);
  if ((((iVar2 == 0) || (iVar3 == 0)) || (*(short *)(iVar2 + 0xe) != 4)) ||
     (*(ushort *)(iVar3 + 0x12) < 4)) {
    if ((apmngr_warning_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_00555fa0;
    pcVar18 = 
    "[APMNGR_WARNING]%s()/%d Failed to find element that desribe AP\'s model or hardware version.\n"
    ;
    uVar21 = 0x255;
    goto LAB_005562f0;
  }
  iVar4 = apmngr_db_sync_device_ready();
  if (iVar4 == 0) {
    if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar18 = 
      "[APMNGR_WARNING]%s()/%d Not allowed to join when device is synchronizing configuration.\n";
      uVar21 = 0x25b;
      goto LAB_005562f0;
    }
  }
  else {
    psVar5 = *(short **)(iVar3 + 0x14);
    local_1968 = *psVar5;
    sStack_1966 = psVar5[1];
    local_1964 = *(undefined4 *)psVar5;
    uVar12 = **(uint **)(iVar2 + 0x10);
    if (**(uint **)(iVar2 + 0x10) != 0) goto LAB_00555ff0;
    iVar2 = cw_sub_msg_ele_get(param_1,0x26,9);
    if (iVar2 == 0) {
LAB_00556304:
      iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_8d0);
      uVar12 = local_890;
      if (iVar2 != 0) {
        if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar18 = "[APMNGR_WARNING]%s()/%d apmngr_db_entry_get_by_mac failed.\n";
          uVar21 = 0x26d;
          goto LAB_005562f0;
        }
        goto LAB_00555fa0;
      }
    }
    else {
      if (*(ushort *)(iVar2 + 0xe) == 0) goto LAB_00556304;
      if (0x41 < *(ushort *)(iVar2 + 0xe)) {
        if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar18 = "[APMNGR_WARNING]%s()/%d Illegal AP\'s model name.\n";
          uVar21 = 0x275;
          goto LAB_005562f0;
        }
        goto LAB_00555fa0;
      }
      iVar3 = apmngr_db_entry_get_by_mac(param_2,auStack_8d0);
      uVar12 = local_890;
      if (iVar3 != 0) {
        memcpy(auStack_1924,*(void **)(iVar2 + 0x10),(uint)*(ushort *)(iVar2 + 0xe));
        iVar2 = apdb_get_ap_by_name_and_hwver(auStack_1924,&local_1968,auStack_1704);
        uVar12 = local_16f4;
        if (iVar2 != 0) {
          if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APMNGR_WARNING]%s()/%d Failed to find apdb for model:%s %d.%d.\n",
                   "_apmngr_pkt_join_req_listen",0x285,auStack_1924,(int)local_1968,(int)sStack_1966
                  );
          }
          goto LAB_00555fa0;
        }
      }
    }
LAB_00555ff0:
    iVar2 = cw_sub_msg_ele_get(param_1,0x26,7);
    iVar3 = cw_sub_msg_ele_get(param_1,0x26,8);
    local_30 = (void *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x5b);
    if (local_30 == (void *)0x0) {
      local_1958 = 0xffffffff;
      local_1954 = 0xffffffff;
      local_1950 = 0xffffffff;
      local_194c = 0xffffffff;
    }
    else {
      memcpy(&local_1958,local_30,0x10);
    }
    if (iVar2 == 0) {
      local_34 = 1;
    }
    else if (iVar3 == 0) {
      local_34 = 1;
    }
    else {
      uVar21 = **(undefined4 **)(iVar3 + 0x10);
      memcpy(&local_1960,*(void **)(iVar2 + 0x10),6);
      iVar2 = apmngr_hdap_check(uVar21,param_2,&local_1960);
      local_34 = 2;
      if (iVar2 == 0) {
        if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar18 = "[APMNGR_ERROR]%s()/%d Join failed because hd_ap has an INVALID direction.\n";
          uVar21 = 0x2a6;
          goto LAB_005562f0;
        }
        goto LAB_00555fa0;
      }
    }
    iVar2 = apdb_get_ap_by_id(uVar12,&local_1958,auStack_1704);
    if (iVar2 == 0) {
      if (param_2[0xc] == 0) {
        if (local_1684 == 2) {
          uVar23 = 0xffff;
          local_34 = 3;
          uVar16 = 7;
          uVar24 = 0;
        }
        else if (local_1688 == 0) {
          uVar23 = 0xffff;
          uVar16 = 0;
          uVar24 = 0;
        }
        else {
          uVar16 = 3;
          if ((local_1684 != 1) && (uVar16 = 2, local_1684 != 3)) {
            uVar16 = 1;
          }
          iVar2 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
          local_1970[0] = 0;
          if ((iVar2 != 0) &&
             (pcVar6 = (char *)cw_priv_mesh_private_control_get(iVar2,0x10), pcVar6 != (char *)0x0))
          {
            if (*pcVar6 == '\x01') {
              iVar2 = mesh_db_mesh_enable_get(local_1970);
              if ((((iVar2 == 0) && (local_1970[0] != 0)) &&
                  (iVar2 = apmngr_db_entry_get_by_mac(pcVar6 + 1,auStack_ba8), iVar2 == 0)) &&
                 (((local_b94 == 1 || (local_b94 == 3)) || (local_b94 == 2)))) {
                uVar24 = local_b96;
                if (local_1684 == 1) {
                  uVar16 = 6;
                  uVar23 = (uint)local_b98;
                }
                else if (local_1684 == 0) {
                  uVar16 = 4;
                  uVar23 = (uint)local_b98;
                }
                else {
                  uVar23 = (uint)local_b98;
                  if (local_1684 == 3) {
                    uVar16 = 8;
                  }
                }
                goto LAB_00556198;
              }
              if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                uVar12 = (uint)(byte)pcVar6[2];
                uVar22 = (uint)(byte)pcVar6[1];
                pcVar18 = 
                "[APMNGR_WARNING]%s()/%d Join failed because can not find parent AP(%02X-%02X-%02X-%02X-%02X-%02X) or role not match or mesh(%d) is closed.\n"
                ;
                uVar23 = (uint)(byte)pcVar6[3];
                uVar21 = 0x2f3;
                uVar16 = (uint)(byte)pcVar6[4];
                uVar13 = (uint)(byte)pcVar6[5];
                uVar14 = (uint)(byte)pcVar6[6];
                goto LAB_00557138;
              }
            }
            else {
              if (*pcVar6 == '\0') goto LAB_00556bf4;
              if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar18 = "[APMNGR_WARNING]%s()/%d Illegal role %d\n";
                uVar21 = 0x308;
                uVar12 = (int)*pcVar6;
                goto LAB_00556144;
              }
            }
            goto LAB_00555fa0;
          }
LAB_00556bf4:
          uVar23 = 0xffff;
          uVar24 = 0;
        }
LAB_00556198:
        iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_8d0);
        if (iVar2 == 0) {
          if ((param_2[0xc] != 0) && (local_8bc != 5)) {
            if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar18 = "[APMNGR_ERROR]%s()/%d Illegal device type %d for child.\n";
              uVar21 = 0x31d;
              uVar12 = local_8bc;
              goto LAB_00556144;
            }
            goto LAB_00555fa0;
          }
          if (local_624 != 0) {
            if (local_8bc != 5) {
              _apmngr_delete_wtp_session
                        (local_664,local_660,local_65c,local_658,local_654,local_650,auStack_888);
              memset(local_17c4,0,0x40);
              memset(&local_1430,0,0x40);
              FUN_00408190(*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                           *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                           *(undefined4 *)(param_2 + 0x20),local_17c4,0x40,"---");
              FUN_00408190(local_664,local_660,local_65c,local_658,local_654,&local_1430,0x40,"---")
              ;
              if ((apmngr_warning_switch == '\0') ||
                 (iVar2 = is_target_debug_ap(param_3), iVar2 == 0)) {
                uVar21 = 7;
              }
              else {
                printf("[APMNGR_WARNING]%s()/%d Join failed because MAC address conflict,new AP[%s:%d],old AP[%s:%d].\n"
                       ,"_apmngr_pkt_join_req_listen",0x329,local_17c4,
                       (uint)*(ushort *)(param_2 + 0x24),&local_1430,(uint)local_650);
                uVar21 = 7;
              }
              goto LAB_00555fa4;
            }
            serv_ent_handle(2,param_2,0,0);
          }
          if (local_890 == uVar12) {
            if ((local_88c != 0) && (iVar2 = memcmp(&local_88c,&local_1964,4), iVar2 != 0)) {
              apmngr_ap_errno_set(local_8c0,1);
              if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar18 = 
                "[APMNGR_WARNING]%s()/%d Join failed because hardware type does not matched.\n";
                uVar21 = 0x351;
                goto LAB_005562f0;
              }
              goto LAB_00555fa0;
            }
LAB_00556360:
            if ((local_34 == 2) && (iVar2 = apmngr_db_entry_get_by_mac(&local_1960,0), iVar2 != 0))
            {
              apmngr_ap_errno_set(local_8c0,2);
              if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar18 = "[APMNGR_WARNING]%s()/%d Join failed because peer entry does not exist.\n"
                ;
                uVar21 = 0x35a;
                goto LAB_005562f0;
              }
            }
            else {
              memcpy(auStack_318,auStack_8d0,0x2d8);
              local_40 = 0;
              iVar2 = apmngr_check_evt_notify(1,auStack_318);
              if (iVar2 == 0) {
                if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  pcVar18 = "[APMNGR_WARNING]%s()/%d Join failed because join check failed.\n";
                  uVar21 = 0x362;
                  goto LAB_005562f0;
                }
              }
              else {
                if (local_88c == 0) {
                  iVar2 = apdb_hwver_exist_by_id(uVar12,&local_1968);
                  if (iVar2 != 1) {
                    if ((apmngr_warning_switch != '\0') &&
                       (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                      pcVar18 = 
                      "[APMNGR_WARNING]%s()/%d Join failed because hardware type does not matched.\n"
                      ;
                      uVar21 = 0x36b;
                      goto LAB_005562f0;
                    }
                    goto LAB_00555fa0;
                  }
                  apmngr_db_ap_hwver_update(local_8c0,&local_1964,0);
                  apmngr_db_sync_ap_hwver(local_8c0,&local_1964,0);
                  apmngr_db_datasync_ap_hwver(local_8c0,&local_1964,0);
                }
                if (((uVar16 != local_8bc) &&
                    (apmngr_db_ap_role_update(local_8c0,uVar16,local_8b8),
                    apmngr_debug_switch != '\0')) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[APMNGR_DEBUG]%s()/%d ap(%u) update role from %d to %d.\n",
                         "_apmngr_pkt_join_req_listen",0x37b,(uint)local_8c0,local_8bc,uVar16);
                }
                pvVar9 = (void *)cw_msg_ele_val_get(param_1,0x32);
                if (pvVar9 != (void *)0x0) {
                  memcpy(local_680,pvVar9,0x10);
                }
                if (((local_680[2] & 0x20) != 0) && (local_6ca == -1)) {
                  local_6ca = '\0';
                  apmngr_ap_telnet_status_default_update(local_8c0,0);
                }
                if (((local_680[2] & 0x200) != 0) && (local_71c == -1)) {
                  local_71c = '\0';
                  apmngr_db_fit_fat_status_update(local_8c0,0);
                }
                if (((local_680[2] & 0x2000) != 0) && (local_79f == -1)) {
                  local_79f = '\0';
                  apmngr_db_bluetooth_enable_update(local_8c0,0);
                }
                uVar23 = (uint)local_8c0;
                if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[APMNGR_DEBUG]%s()/%d Matched exist ap entry(%u).\n",
                         "_apmngr_pkt_join_req_listen",0x397,uVar23);
                }
                apmngr_evt_notify(0,auStack_8d0);
LAB_0055645c:
                local_640 = 0xffffffff;
                if (param_2[0xc] == 0) {
                  memcpy(&local_664,param_2 + 0x10,0x14);
                  local_650 = *(ushort *)(param_2 + 0x24);
                }
                else {
                  local_650 = *(ushort *)(param_2 + 0x24);
                }
                iVar2 = cw_sub_msg_ele_get(param_1,0x27,1);
                if (iVar2 != 0) {
                  local_6c8 = **(undefined2 **)(iVar2 + 0x14);
                  local_6c6 = *(undefined2 *)(*(int *)(iVar2 + 0x14) + 2);
                  local_6c4 = *(undefined2 *)(*(int *)(iVar2 + 0x14) + 4);
                  local_6c0 = *(undefined4 *)(*(int *)(iVar2 + 0x14) + 6);
                  local_6bc = *(undefined4 *)(*(int *)(iVar2 + 0x14) + 10);
                }
                pvVar9 = (void *)cw_msg_ele_val_get(param_1,0x32);
                if ((pvVar9 != (void *)0x0) && (memcpy(local_680,pvVar9,0x10), param_2[0xc] != 0)) {
                  puVar17 = local_680;
                  iVar2 = 0;
                  do {
                    iVar3 = iVar2 + 4;
                    *puVar17 = *puVar17 & *(uint *)((int)local_958 + iVar2);
                    puVar17 = puVar17 + 1;
                    iVar2 = iVar3;
                  } while (iVar3 != 0x10);
                  if ((local_958[0] & 0x10) == 0) {
                    local_680[0] = local_680[0] & 0xffffffef;
                  }
                  else {
                    local_680[0] = local_680[0] | 0x10;
                  }
                }
                puVar7 = (undefined2 *)cw_msg_ele_priv_val_get_from_pkt(param_1,0);
                if (puVar7 != (undefined2 *)0x0) {
                  local_686 = *puVar7;
                  local_684 = puVar7[1];
                }
                if (local_30 != (void *)0x0) {
                  memcpy(auStack_6b8,local_30,0x10);
                  local_6a8 = *(byte *)((int)local_30 + 0x10);
                  if (2 < local_6a8) {
                    local_6a8 = 2;
                  }
                  __dest = auStack_6a7;
                  for (iVar2 = 0; iVar2 < (int)(uint)local_6a8; iVar2 = iVar2 + 1) {
                    memcpy(__dest,(void *)(*(int *)((int)local_30 + 0x14) + iVar2 * 0x10),0x10);
                    __dest = __dest + 0x10;
                  }
                }
                puVar8 = (ushort *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x8f);
                if (puVar8 != (ushort *)0x0) {
                  iVar2 = 0;
                  memset(local_17c4,0,0xc0);
                  memset(local_17c4,-1,0xc0);
                  local_176c = 0;
                  local_17c4[2] = 1;
                  local_1706 = 2;
                  while (iVar2 < (int)(uint)*puVar8) {
                    puVar20 = (ushort *)(*(int *)(puVar8 + 2) + iVar2 * 8);
                    uVar16 = (uint)*puVar20;
                    if (uVar16 < 0x60) {
                      if (local_17c4[uVar16] != -1) {
                        memcpy(auStack_670 + local_17c4[uVar16] * 4,puVar20 + 2,4);
                      }
                      iVar2 = iVar2 + 1;
                    }
                    else {
                      iVar2 = iVar2 + 1;
                    }
                  }
                }
                iVar2 = apmngr_ap_runinfo_update(uVar23,&local_6c8);
                if ((((iVar2 != 0) || (iVar2 = apmngr_ap_run_state_update(uVar23,1), iVar2 != 0)) ||
                    (iVar2 = apmngr_db_entry_get_by_id(uVar23,auStack_8d0), iVar2 != 0)) ||
                   (iVar2 = apmngr_checksum_update(auStack_8d0,0), iVar2 != 0)) {
                  if (apmngr_err_switch == '\0') {
                    bVar15 = param_2[0xc];
                  }
                  else {
                    iVar2 = is_target_debug_ap();
                    if (iVar2 == 0) {
                      bVar15 = param_2[0xc];
                    }
                    else {
                      printf("[APMNGR_ERROR]%s()/%d Failed to update AP\'s run info.\n",
                             "_apmngr_pkt_join_req_listen",0x485);
                      bVar15 = param_2[0xc];
                    }
                  }
                  if (bVar15 == 0) {
                    _apmngr_delete_wtp_session
                              (*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                               *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                               *(undefined4 *)(param_2 + 0x20),*(undefined2 *)(param_2 + 0x24),
                               param_2);
                  }
                  _apmngr_pkt_result_code_set_err(param_3,1);
                }
                add_standby_ap(auStack_8d0);
                apmngr_support_capacity_get(&local_1948,4);
                iVar2 = cw_service_msg_add(param_3,0x32,&local_1948,0);
                if (iVar2 != 0) {
                  if (apmngr_err_switch == '\0') {
                    return 0xffffffff;
                  }
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    return 0xffffffff;
                  }
                  pcVar18 = "[APMNGR_ERROR]%s()/%d add msg element failed.\n";
                  uVar21 = 0x493;
LAB_00556854:
                  printf(pcVar18,"_apmngr_pkt_join_req_listen",uVar21);
                  return 0xffffffff;
                }
                if ((int)(local_680[2] << 0xe) < 0) {
                  apdb_update_support_large_fw_upgrade(uVar12,&local_1958,1);
                }
                if ((int)(local_680[1] << 5) < 0) {
                  local_1430 = 0;
                  local_142c = (void *)0x0;
                  local_17c4[0] = 0;
                  local_17c4[1] = 0;
                  local_17c4[2] = 0;
                  local_17c4[3] = 0;
                  local_17bc = 0;
                  local_17b8 = 0;
                  local_17b4 = 0;
                  local_142c = (void *)FUN_00408450(0x300,0x49e);
                  if (local_142c == (void *)0x0) {
                    if (apmngr_err_switch == '\0') {
                      return 0xffffffff;
                    }
                    iVar2 = is_target_debug_ap();
                    if (iVar2 == 0) {
                      return 0xffffffff;
                    }
                    pcVar18 = "[APMNGR_ERROR]%s()/%d Malloc failed.\n";
                    uVar21 = 0x4a1;
                    goto LAB_00556854;
                  }
                  memset(local_142c,0,0x300);
                  apmngr_support_sub_capacity_get(&local_1430,local_142c);
                  FUN_0051ad88(&local_17bc);
                  iVar2 = cw_service_msg_add(param_3,0x25,local_17c4,1,0x8f,&local_1430);
                  if (iVar2 != 0) {
                    if ((apmngr_err_switch != '\0') &&
                       (iVar2 = is_target_debug_ap(local_142c), iVar2 != 0)) {
                      printf("[APMNGR_ERROR]%s()/%d add msg element failed.\n",
                             "_apmngr_pkt_join_req_listen",0x4a9);
                    }
                    FUN_00407df0(local_142c);
                    return 0xffffffff;
                  }
                  FUN_00407df0(local_142c);
                }
                FUN_0051ad88(&local_1930);
                local_1970[1] = 2;
                uVar21 = 0x1d;
                iVar2 = cw_service_msg_add(param_3,0x25,&local_1938,1,0x1d,local_1970 + 1);
                if (iVar2 != 0) {
                  if (apmngr_err_switch == '\0') {
                    return 0xffffffff;
                  }
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    return 0xffffffff;
                  }
                  pcVar18 = "[APMNGR_ERROR]%s()/%d add msg element failed.\n";
                  uVar21 = 0x4b5;
                  goto LAB_00556854;
                }
                if ((local_680[2] & 0x400) != 0) {
                  local_1430 = 0;
                  local_142c = (void *)((uint)local_142c & 0xffff);
                  local_17c4[0] = 0;
                  local_17c4[1] = 0;
                  local_17c4[2] = 0;
                  local_17c4[3] = 0;
                  local_17bc = 0;
                  local_17b8 = 0;
                  local_17b4 = 0;
                  local_18e0 = 0;
                  local_18dc = 0;
                  iVar2 = FUN_005135a8(&local_18e0);
                  if (iVar2 != 0) {
                    if (apmngr_err_switch == '\0') {
                      return 0xffffffff;
                    }
                    iVar2 = is_target_debug_ap();
                    if (iVar2 == 0) {
                      return 0xffffffff;
                    }
                    pcVar18 = "[APMNGR_ERROR]%s()/%d Get dev mac failed\n";
                    uVar21 = 0x4c1;
                    goto LAB_00556854;
                  }
                  local_1430 = local_18e0;
                  local_142c = (void *)CONCAT22(local_18dc,local_142c._2_2_);
                  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    printf("[APMNGR_DEBUG]%s()/%d support ac info.\n","_apmngr_pkt_join_req_listen",
                           0x4c5);
                  }
                  FUN_0051ad88(&local_17bc);
                  uVar21 = 0x1b;
                  iVar2 = cw_service_msg_add(param_3,0x25,local_17c4,1,0x1b,&local_1430);
                  if (iVar2 != 0) {
                    if (apmngr_err_switch == '\0') {
                      return 0xffffffff;
                    }
                    iVar2 = is_target_debug_ap();
                    if (iVar2 == 0) {
                      return 0xffffffff;
                    }
                    pcVar18 = "[APMNGR_ERROR]%s()/%d add msg element failed.\n";
                    uVar21 = 0x4c9;
                    goto LAB_00556854;
                  }
                }
                if ((int)(local_680[2] << 0xc) < 0) {
                  iVar2 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xb5);
                  if (iVar2 == 0) {
                    return 0;
                  }
                  apmngr_db_features_update(local_8c0);
                }
                iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_8d0);
                if (iVar2 == 0) {
                  if ((int)(local_680[1] << 4) < 0) {
                    iVar2 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x90);
                    if (iVar2 == 0) {
                      return 0;
                    }
                    puVar11 = (undefined4 *)cw_priv_radio_role_table_control_tlv_ele_get(iVar2,1);
                    if (puVar11 != (undefined4 *)0x0) {
                      if (apmngr_debug_switch == '\0') {
                        uVar19 = *(undefined1 *)((int)puVar11 + 3);
                      }
                      else {
                        iVar2 = is_target_debug_ap();
                        if (iVar2 == 0) {
                          uVar19 = *(undefined1 *)((int)puVar11 + 3);
                        }
                        else {
                          uVar21 = *puVar11;
                          printf("[APMNGR_DEBUG]%s()/%d get ap_id=%d, param_capability=%d\n",
                                 "_apmngr_pkt_join_req_listen",0x4eb,(uint)local_8c0,uVar21);
                          uVar19 = *(undefined1 *)((int)puVar11 + 3);
                        }
                      }
                      iVar2 = apmngr_db_set_cur_using_rrst_idx(uVar19,local_8c0);
                      if (((iVar2 == -1) && (apmngr_err_switch != '\0')) &&
                         (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                        printf("[APMNGR_ERROR]%s()/%d apmngr_db_set_cur_using_rrst_idx fail, ap_id=%d\n"
                               ,"_apmngr_pkt_join_req_listen",0x4ee,(uint)local_8c0,uVar21);
                      }
                    }
                  }
                  if ((local_665 & 2) == 0) {
                    return 0;
                  }
                  if ((apmngr_debug_switch != '\0') &&
                     (iVar2 = is_target_debug_ap(local_8c0), iVar2 != 0)) {
                    printf("[APMNGR_DEBUG]%s()/%d Support ssid mlo feature.\n",
                           "_apmngr_pkt_join_req_listen",0x4f6);
                  }
                  apmngr_db_ssid_mlo_support_update(local_8c0,1);
                  return 0;
                }
                if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  pcVar18 = "[APMNGR_WARNING]%s()/%d apmngr_db_entry_get_by_mac failed.\n";
                  uVar21 = 0x4dd;
                  goto LAB_005562f0;
                }
              }
            }
          }
          else {
            iVar2 = apdb_get_ap_by_id(local_890,&local_1958,auStack_159c);
            if (((iVar2 == 0) && (local_1528 == 0)) && (local_1690 != 0)) {
              if (local_14c2[0] != '\0') {
                iVar2 = strcmp(local_14c2,acStack_162a);
                if ((iVar2 != 0) && (iVar2 = strcmp(local_14c2,acStack_15e9), iVar2 != 0))
                goto LAB_0055624c;
LAB_00556320:
                apmngr_db_ap_hwver_and_model_update(local_8c0,&local_1964,uVar12);
                if ((local_8bc == 5) && (uVar16 == 6)) {
                  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(0xc), iVar2 != 0)
                     ) {
                    printf("[APMNGR_DEBUG]%s()/%d ap(%u) notify model update event \n",
                           "_apmngr_pkt_join_req_listen",0x344,(uint)local_8c0);
                  }
                  local_890 = uVar12;
                  apmngr_evt_notify(0xc,auStack_8d0);
                }
                apmngr_db_sync_ap_hwver_and_model(local_8c0,&local_1964,uVar12);
                apmngr_db_datasync_ap_hwver_and_model(local_8c0,&local_1964,uVar12);
                goto LAB_00556360;
              }
LAB_0055624c:
              if (local_1481[0] != '\0') {
                iVar2 = strcmp(local_1481,acStack_162a);
                if ((iVar2 == 0) || (iVar2 = strcmp(local_1481,acStack_15e9), iVar2 == 0))
                goto LAB_00556320;
              }
            }
            apmngr_ap_errno_set(local_8c0,1);
            if ((apmngr_warning_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_00555fa0;
            pcVar18 = 
            "[APMNGR_WARNING]%s()/%d Join failed because hardware type does not matched.\n";
            uVar21 = 0x338;
LAB_005562f0:
            printf(pcVar18,"_apmngr_pkt_join_req_listen",uVar21);
          }
        }
        else {
          iVar2 = apmngr_db_is_ap_exceed(local_34,0);
          if (iVar2 != 0) {
            if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[APMNGR_WARNING]%s()/%d Failed to join for too many AP.\n",
                     "_apmngr_pkt_join_req_listen",0x39d);
            }
            FUN_00407e70();
            apmngr_exceed_time_set(extraout_v1);
            _apmngr_pkt_result_code_set_err(param_3,1);
            memset(&local_1430,0,0x40);
            FUN_00408190(*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                         *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                         *(undefined4 *)(param_2 + 0x20),&local_1430,0x40,"---");
            local_17c4[0] = 0;
            local_17c4[1] = 0;
            local_17c4[2] = 0;
            local_17c4[3] = 0;
            local_17bc = 0;
            local_17b8 = 0;
            local_17b4 = 0;
            snprintf((char *)local_17c4,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_2,
                     (uint)param_2[1],(uint)param_2[2],(uint)param_2[3],(uint)param_2[4],
                     (uint)param_2[5]);
            if (local_34 == 3) {
              pcVar18 = "Sensor";
            }
            else {
              pcVar18 = "AP";
            }
            uVar21 = apmngr_db_product_type_str_by_ap_role(uVar16);
            pcVar6 = (char *)&local_1430;
            if (param_2[0xc] != 0) {
              pcVar6 = "---";
            }
            loggerk_reg(0x53,0x3d01,1,pcVar18,1,uVar21,1,pcVar6,1,local_17c4,0);
            return 0xffffffff;
          }
          iVar2 = apdb_get_ap_by_id(uVar12,&local_1958,auStack_1704);
          if (iVar2 == 0) {
            if (param_2[0xc] == 0) {
              if (((local_1684 < 2) || (local_1684 == 3)) || (local_1684 == 2)) {
                if (local_1688 == 0) {
                  iVar2 = 0;
                  if (local_1684 == 2) {
                    local_38 = auStack_e80;
                    memset(local_38,0,0x2d8);
                    memset(&local_18e0,0,0x80);
                    pbVar10 = (byte *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x8c);
                    local_34 = 0;
                    if (pbVar10 == (byte *)0x0) {
                      iVar2 = 7;
                    }
                    else {
                      for (; local_34 < (int)(uint)*pbVar10; local_34 = local_34 + 1) {
                        iVar2 = *(int *)(pbVar10 + 4) + local_34 * 0x20;
                        if ((((*(uint *)(iVar2 + 0xc) & 0x40) != 0) &&
                            (iVar2 = wsta_db_get_entry_by_mac(iVar2,&local_18e0), iVar2 == 0)) &&
                           (iVar2 = apmngr_db_entry_get_by_id(local_18be,auStack_e80), iVar2 == 0))
                        {
                          uVar24 = local_e6e;
                        }
                      }
                      iVar2 = 7;
                    }
                  }
                  goto LAB_00556a34;
                }
                iVar2 = 3;
                if ((local_1684 != 1) && (iVar2 = 2, local_1684 != 3)) {
                  iVar2 = 1;
                }
                iVar3 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
                local_1970[0] = 0;
                if ((iVar3 == 0) ||
                   (pcVar6 = (char *)cw_priv_mesh_private_control_get(iVar3,0x10),
                   pcVar6 == (char *)0x0)) {
LAB_00556a20:
                  local_1430 = 0;
                  local_142c = (void *)((uint)local_142c & 0xffff);
                  if (((iVar2 == 2) && (iVar3 = FUN_005135a8(&local_1430), iVar3 == 0)) &&
                     (iVar3 = memcmp(&local_1430,param_2,6), iVar3 == 0)) {
                    FUN_00408350(local_1860,0x9a);
                  }
                  goto LAB_00556a34;
                }
                local_34 = (int)*pcVar6;
                if (local_34 == 1) {
                  iVar3 = mesh_db_mesh_enable_get(local_1970);
                  if ((((iVar3 == 0) && (local_1970[0] != 0)) &&
                      (iVar3 = apmngr_db_entry_get_by_mac(pcVar6 + 1,auStack_ba8), iVar3 == 0)) &&
                     (((local_b94 == local_34 || (local_b94 == 3)) || (local_b94 == 2)))) {
                    uVar24 = local_b96;
                    if (local_1684 == 1) {
                      iVar2 = 6;
                      uVar23 = (uint)local_b98;
                    }
                    else if (local_1684 == 0) {
                      iVar2 = 4;
                      uVar23 = (uint)local_b98;
                    }
                    else {
                      uVar23 = (uint)local_b98;
                      if (local_1684 == 3) {
                        iVar2 = 8;
                      }
                    }
                    goto LAB_00556a20;
                  }
                  if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0))
                  {
                    uVar12 = (uint)(byte)pcVar6[2];
                    uVar22 = (uint)(byte)pcVar6[1];
                    pcVar18 = 
                    "[APMNGR_WARNING]%s()/%d Join failed because can not find parent AP(%02X-%02X-%02X-%02X-%02X-%02X) or role not match or mesh(%d) is closed.\n"
                    ;
                    uVar23 = (uint)(byte)pcVar6[3];
                    uVar21 = 0x3ec;
                    uVar16 = (uint)(byte)pcVar6[4];
                    uVar13 = (uint)(byte)pcVar6[5];
                    uVar14 = (uint)(byte)pcVar6[6];
                    goto LAB_00557138;
                  }
                }
                else {
                  if (local_34 == 0) goto LAB_00556a20;
                  if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0))
                  {
                    pcVar18 = "[APMNGR_WARNING]%s()/%d Illegal role %d\n";
                    uVar21 = 0x401;
                    uVar12 = (int)*pcVar6;
                    goto LAB_00556144;
                  }
                }
              }
              else if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar18 = "[APMNGR_ERROR]%s()/%d Illegal product type %d for root device.\n";
                uVar21 = 0x3ce;
                uVar12 = local_1684;
                goto LAB_00556144;
              }
            }
            else {
              if (local_1684 == 1) {
                iVar2 = 5;
              }
              else {
                iVar2 = 8;
                if (local_1684 != 3) {
                  if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    pcVar18 = "[APMNGR_ERROR]%s()/%d Illegal product type %d for child.\n";
                    uVar21 = 0x3c4;
                    uVar12 = local_1684;
                    goto LAB_00556144;
                  }
                  goto LAB_00555fa0;
                }
              }
LAB_00556a34:
              pvVar9 = (void *)cw_msg_ele_val_get(param_1,0x32);
              if (pvVar9 != (void *)0x0) {
                memcpy(local_680,pvVar9,0x10);
              }
              memset(auStack_1158,0,0x2d8);
              memset(auStack_5f8,0,0x2e0);
              local_1970[0] = 0;
              apmngr_db_entry_init(auStack_1158,&local_1958,uVar12,iVar2);
              if ((local_680[2] & 0x2000) == 0) {
                if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
                  local_1027 = 0xff;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d nonsupport bluetooth enable\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x18a);
                  local_1027 = 0xff;
                }
              }
              else if (apmngr_debug_switch == '\0') {
                local_1027 = 0;
              }
              else {
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  local_1027 = 0;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d support bluetooth enable\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x185);
                  local_1027 = 0;
                }
              }
              if ((local_680[2] & 0x20) == 0) {
                if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
                  local_f52 = 0xff;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d nonsupport telnet\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x196);
                  local_f52 = 0xff;
                }
              }
              else if (apmngr_debug_switch == '\0') {
                local_f52 = 0;
              }
              else {
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  local_f52 = 0;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d support telnet\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x191);
                  local_f52 = 0;
                }
              }
              if ((local_680[2] & 0x200) == 0) {
                if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
                  local_fa4 = 0xff;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d nonsupport fit/fat button status\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x1a0);
                  local_fa4 = 0xff;
                }
              }
              else if (apmngr_debug_switch == '\0') {
                local_fa4 = 0;
              }
              else {
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  local_fa4 = 0;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d support fit/fat button status\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x19b);
                  local_fa4 = 0;
                }
              }
              if ((local_680[2] & 2) == 0) {
                if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
                  local_e87 = 0xff;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d nonsupport region code\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x1aa);
                  local_e87 = 0xff;
                }
              }
              else if (apmngr_debug_switch == '\0') {
                local_e87 = 0;
              }
              else {
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  local_e87 = 0;
                }
                else {
                  printf("[APMNGR_DEBUG]%s()/%d support region code\n",
                         "_apmngr_try_create_ap_entry_by_template_or_db",0x1a5);
                  local_e87 = 0;
                }
              }
              local_1140 = (undefined2)uVar23;
              local_1130 = 0;
              local_1146 = uVar24;
              local_1118 = uVar12;
              iVar2 = mesh_db_mesh_enable_get(local_1970);
              if (iVar2 == 0) {
                if (local_1970[0] == 0) {
                  local_f51 = 0;
                }
                else if (local_1144 - 2U < 2) {
                  if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
                    local_f51 = 1;
                  }
                  else {
                    printf("[APMNGR_DEBUG]%s()/%d ap(%u) role %d ap mesh witch open \n",
                           "_apmngr_try_create_ap_entry_by_template_or_db",0x1b8,(uint)local_1148,
                           local_1144);
                    local_f51 = 1;
                  }
                }
                else {
                  local_f51 = 0;
                }
              }
              else {
                local_f51 = 0;
              }
              memcpy(auStack_1110,param_2,6);
              local_1114 = local_1964;
              memset(&local_1430,0,0x2d8);
              uVar19 = local_e87;
              if (uVar23 == 0xffff) {
LAB_00557360:
                local_e87 = uVar19;
                memcpy(auStack_5f8,auStack_1158,0x2d8);
                local_320 = 1;
                iVar2 = apmngr_check_evt_notify(1,auStack_5f8);
                if (iVar2 == 0) {
                  if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0))
                  {
                    pcVar18 = "[APMNGR_WARNING]%s()/%d Join failed because join check failed.\n";
                    uVar21 = 0x1cd;
LAB_005573c0:
                    printf(pcVar18,"_apmngr_try_create_ap_entry_by_template_or_db",uVar21);
                  }
                }
                else {
                  if (local_1860[0] != '\0') {
                    strncpy(acStack_110a,local_1860,0x99);
                  }
                  FUN_00407e80("_apmngr_try_create_ap_entry_by_template_or_db");
                  iVar2 = apdb_is_hdap_by_id(uVar12,&local_1958);
                  if (iVar2 == 0) {
                    uVar23 = apmngr_ap_add(auStack_1158,&local_1958,1,local_1860[0] != '\0',1);
                  }
                  else {
                    uVar23 = apmngr_hdap_add(auStack_1158,&local_1958,&local_1960,1,1);
                  }
                  FUN_004082b0(uVar23 != 0xffff && local_111c != 0,
                               "_apmngr_try_create_ap_entry_by_template_or_db");
                  if (uVar23 != 0xffff) {
                    if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0))
                    {
                      printf("[APMNGR_DEBUG]%s()/%d Create an ap entry(%u).\n\n",
                             "_apmngr_pkt_join_req_listen",0x43f,uVar23);
                    }
                    apmngr_db_entry_get_by_id(uVar23,auStack_8d0);
                    goto LAB_0055645c;
                  }
                }
              }
              else {
                iVar2 = apmngr_db_entry_get_by_id(uVar23,&local_1430);
                if (iVar2 == 0) {
                  uVar19 = local_e87;
                  if (((((local_680[2] & 2) != 0) && ((local_11d8 & 2) != 0)) &&
                      (uVar19 = local_115f, apmngr_debug_switch != '\0')) &&
                     (iVar2 = is_target_debug_ap(), uVar19 = local_115f, iVar2 != 0)) {
                    printf("[APMNGR_DEBUG]%s()/%d re region code follow cap\n",
                           "_apmngr_pkt_re_config_follow_cap",0x16b);
                    uVar19 = local_115f;
                  }
                  goto LAB_00557360;
                }
                if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[APMNGR_ERROR]%s()/%d get cap entry failed id:%d\n",
                         "_apmngr_pkt_re_config_follow_cap",0x166,uVar23);
                }
                if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  pcVar18 = "[APMNGR_ERROR]%s()/%d _apmngr_pkt_re_config_follow_cap fail\n";
                  uVar21 = 0x1c5;
                  goto LAB_005573c0;
                }
              }
              if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar18 = 
                "[APMNGR_WARNING]%s()/%d Cannot find or create an entry, maybe an unsupported device or join check failed.\n"
                ;
                uVar21 = 0x43b;
                goto LAB_005562f0;
              }
            }
          }
          else if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar18 = "[APMNGR_ERROR]%s()/%d Cannot find apdb of model %d.\n";
            uVar21 = 0x3b3;
            goto LAB_00556144;
          }
        }
      }
      else {
        iVar2 = apmngr_db_entry_get_by_mac(param_2 + 6,auStack_ba8);
        if ((iVar2 == 0) && (((local_b94 == 1 || (local_b94 == 3)) || (local_b94 == 2)))) {
          uVar23 = (uint)local_b98;
          uVar24 = local_b96;
          if (local_1684 == 1) {
            uVar16 = 5;
          }
          else {
            uVar16 = 8;
            if (local_1684 != 3) {
              if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar18 = "[APMNGR_ERROR]%s()/%d Illegal product type %d for child.\n";
                uVar21 = 0x2cb;
                uVar12 = local_1684;
                goto LAB_00556144;
              }
              goto LAB_00555fa0;
            }
          }
          goto LAB_00556198;
        }
        if ((apmngr_warning_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_00555fa0;
        uVar12 = (uint)param_2[7];
        uVar22 = (uint)param_2[6];
        pcVar18 = 
        "[APMNGR_WARNING]%s()/%d Join failed because can not find parent AP(%02X-%02X-%02X-%02X-%02X-%02X) or role not match.\n"
        ;
        uVar23 = (uint)param_2[8];
        uVar21 = 0x2ba;
        uVar16 = (uint)param_2[9];
        uVar13 = (uint)param_2[10];
        uVar14 = (uint)param_2[0xb];
LAB_00557138:
        printf(pcVar18,"_apmngr_pkt_join_req_listen",uVar21,uVar22,uVar12,uVar23,uVar16,uVar13,
               uVar14);
      }
    }
    else {
      if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_00555fa0;
      pcVar18 = "[APMNGR_ERROR]%s()/%d Cannot find apdb of model %d.\n";
      uVar21 = 0x2af;
LAB_00556144:
      printf(pcVar18,"_apmngr_pkt_join_req_listen",uVar21,uVar12);
    }
  }
LAB_00555fa0:
  uVar21 = 1;
LAB_00555fa4:
  _apmngr_pkt_result_code_set_err(param_3,uVar21);
  return 0xffffffff;
}

