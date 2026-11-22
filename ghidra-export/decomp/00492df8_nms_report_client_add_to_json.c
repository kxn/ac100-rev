// func nms_report_client_add_to_json @ 00492df8 size=2504

/* WARNING: Type propagation algorithm not settling */

undefined4 nms_report_client_add_to_json(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  ushort *puVar13;
  undefined8 uVar14;
  longlong lVar15;
  undefined8 uVar16;
  int local_3a8;
  int local_3a4 [2];
  undefined2 local_39c;
  char local_398 [20];
  char acStack_384 [68];
  undefined1 auStack_340 [20];
  undefined4 local_32c;
  undefined1 auStack_2f8 [381];
  char local_17b;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  uVar9 = 0xffffffff;
  local_3a4[0] = 0;
  local_398[0] = '\0';
  local_398[1] = '\0';
  local_398[2] = '\0';
  local_398[3] = '\0';
  local_398[4] = '\0';
  local_398[5] = '\0';
  local_398[6] = '\0';
  local_398[7] = '\0';
  local_398[8] = '\0';
  local_398[9] = '\0';
  local_398[10] = '\0';
  local_398[0xb] = '\0';
  local_398[0xc] = '\0';
  local_398[0xd] = '\0';
  local_398[0xe] = '\0';
  local_398[0xf] = '\0';
  local_398[0x10] = '\0';
  local_398[0x11] = '\0';
  memset(auStack_340,0,0x2d8);
  local_60 = get_stats_sample_time(0);
  memset(acStack_384,0,0x40);
  local_3a4[1] = 0;
  local_39c = 0;
  local_3a8 = 0;
  if (param_1 != 0) {
    uVar9 = 0;
    iVar1 = stats_db_radio_sample_mask_check(*(undefined2 *)(param_1 + 8),0);
    if (iVar1 != 0) {
      iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 8),auStack_340);
      if ((iVar1 == -1) && ((*(byte *)(param_1 + 0xc) & 8) == 0)) {
        uVar9 = 0xffffffff;
        if (cloud_mngt_info_switch != '\0') {
          printf("[CLOUD_MNGT_INFO]%s()/%d get ap entry by id failed.\n",
                 "nms_report_client_add_to_json",0x1290);
        }
      }
      else if (((local_17b == '\0') &&
               (iVar1 = is_stats_db_ap_config_id_set(*(undefined2 *)(param_1 + 8)), iVar1 != 0)) ||
              (iVar1 = _cloud_mngt_role_match(local_32c), iVar1 == 0)) {
        uVar9 = 0;
        if (cloud_mngt_info_switch != '\0') {
          printf("[CLOUD_MNGT_INFO]%s()/%d sta_stat->info_state:%d\n",
                 "nms_report_client_add_to_json",0x1297,(int)*(char *)(param_1 + 0xc));
        }
      }
      else {
        uVar9 = 0;
        uVar2 = get_report_sample_cnt
                          (*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                           *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),
                           client_stats_begin_report_time,DAT_00767624,local_60);
        uVar6 = (uint)*(byte *)(param_1 + 0x55);
        if ((int)uVar2 <= (int)(uint)*(byte *)(param_1 + 0x55)) {
          uVar6 = uVar2;
        }
        if (0 < (int)uVar6) {
          iVar10 = 0;
          iVar1 = FUN_00407fa0(*(undefined4 *)(param_2 + 0x2c),auStack_2f8);
          uVar9 = 0xffffffff;
          if (iVar1 == 0) {
            iVar10 = -1;
          }
          local_3a8 = 0;
          iVar1 = stats_db_ap_mac_get_ignore_status(*(undefined2 *)(param_1 + 8),local_3a4 + 1);
          if (iVar1 == 0) {
            uVar16 = 0;
            iVar1 = _find_client_object_hash_node
                              (*(undefined4 *)(param_2 + 0x2c),local_3a4 + 1,local_3a4,"clientStats"
                               ,0,0);
            if ((iVar1 == 0) && (local_3a4[0] != 0)) {
              local_50 = 0;
              if (iVar10 == -1) {
                iVar1 = FUN_00407fa0(*(undefined4 *)(param_2 + 0x2c),auStack_2f8);
                local_50 = *(undefined4 *)(iVar1 + 0xc);
                local_3a8 = 0;
              }
              iVar1 = json_object_new_object();
              uVar9 = json_object_new_object();
              lVar15 = (longlong)(int)((uVar6 - 1) * local_60) * 1000000;
              uVar2 = *(uint *)(param_1 + 0x5c) - (int)lVar15;
              uVar14 = __udivdi3((*(int *)(param_1 + 0x58) - (int)((ulonglong)lVar15 >> 0x20)) -
                                 (uint)(*(uint *)(param_1 + 0x5c) < uVar2),uVar2,0,1000);
              local_68 = (undefined4)((ulonglong)uVar14 >> 0x20);
              uVar8 = (undefined4)uVar14;
              if (cloud_mngt_info_switch != '\0') {
                printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
                       "nms_report_client_add_to_json",0x12b9);
                uVar16 = uVar14;
              }
              lVar15 = FUN_00407dd0();
              uVar14 = FUN_004081f0();
              lVar15 = lVar15 + CONCAT44(local_68,uVar8);
              uVar2 = (uint)lVar15;
              local_54 = uVar2 - (int)uVar14;
              local_40 = ((int)((ulonglong)lVar15 >> 0x20) - (int)((ulonglong)uVar14 >> 0x20)) -
                         (uint)(uVar2 < local_54);
              if (cloud_mngt_info_switch != '\0') {
                uVar16 = FUN_00407dd0();
                printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_real_msecs()%llu\n",
                       "nms_report_client_add_to_json",0x12bb);
              }
              if (cloud_mngt_info_switch != '\0') {
                uVar16 = FUN_004081f0();
                printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_msecs()%llu\n",
                       "nms_report_client_add_to_json",0x12bc);
              }
              if (cloud_mngt_info_switch != '\0') {
                uVar16 = CONCAT44(local_40,local_54);
                printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
                       "nms_report_client_add_to_json",0x12bd);
              }
              if (cloud_mngt_info_switch != '\0') {
                printf("[CLOUD_MNGT_INFO]%s()/%d stat_interval_normal%d\n",
                       "nms_report_client_add_to_json",0x12be,local_60,uVar16);
              }
              stats_db_sta_update_ac_report_time(param_1 + 2);
              local_30 = (uint)*(ushort *)(param_1 + 0x20);
              local_3c = local_30 & 8;
              local_38 = local_30 & 4;
              local_34 = local_30 & 0x20;
              local_30 = local_30 & 0x10;
              local_4c = json_object_new_array();
              local_48 = json_object_new_array();
              local_68 = json_object_new_array();
              local_64 = json_object_new_array();
              local_44 = json_object_new_array();
              iVar10 = json_object_new_array();
              local_5c = json_object_new_array();
              local_58 = json_object_new_array();
              iVar11 = *(byte *)(param_1 + 0x55) - uVar6;
              puVar13 = (ushort *)(param_1 + (iVar11 + 0x88) * 2);
              piVar12 = (int *)(param_1 + (iVar11 + 0x2e) * 4);
              while( true ) {
                puVar13 = puVar13 + 1;
                if ((int)(uint)*(byte *)(param_1 + 0x55) <= iVar11) break;
                iVar7 = -1;
                if (local_3c != 0) {
                  iVar7 = piVar12[-10];
                }
                uVar8 = json_object_new_int(iVar7);
                json_object_array_add(local_4c,uVar8);
                iVar7 = -1;
                if (local_38 != 0) {
                  iVar7 = piVar12[-0x14];
                }
                uVar8 = json_object_new_int(iVar7);
                json_object_array_add(local_48,uVar8);
                if ((local_34 == 0) || (piVar12[10] == -1)) {
                  uVar8 = json_object_new_int(0xffffffff);
                }
                else {
                  uVar8 = json_object_new_int64(0);
                }
                json_object_array_add(local_68,uVar8);
                if ((local_30 == 0) || (*piVar12 == -1)) {
                  uVar8 = json_object_new_int(0xffffffff);
                }
                else {
                  uVar8 = json_object_new_int64(0);
                }
                json_object_array_add(local_64,uVar8);
                uVar8 = json_object_new_int((int)*(char *)(param_1 + iVar11 + 0x108));
                json_object_array_add(local_44,uVar8);
                if (*puVar13 == 0xffff) {
                  uVar8 = json_object_new_int(0xffffffff);
                  json_object_array_add(local_5c,uVar8);
                  uVar8 = json_object_new_int(0xffffffff);
                }
                else {
                  uVar8 = json_object_new_int64(0,(uint)*puVar13 << 10);
                  json_object_array_add(local_5c,uVar8);
                  uVar8 = json_object_new_int64(0,(uint)*puVar13 << 10);
                }
                iVar11 = iVar11 + 1;
                piVar12 = piVar12 + 1;
                json_object_array_add(local_58,uVar8);
              }
              for (iVar11 = *(byte *)(param_1 + 0x55) - uVar6;
                  iVar11 < (int)(uint)*(byte *)(param_1 + 0x55); iVar11 = iVar11 + 1) {
                iVar7 = (int)*(char *)(param_1 + iVar11 + 0x108);
                if (iVar7 == 0x7f) {
                  uVar8 = 0x100;
                }
                else {
                  uVar8 = estimate_snr_from_rssi(iVar7,0);
                }
                uVar8 = json_object_new_int(uVar8);
                json_object_array_add(iVar10,uVar8);
              }
              if (iVar10 != 0) {
                json_object_object_add(uVar9,"lastSNR",iVar10);
              }
              uVar2 = 0;
              json_object_object_add(uVar9,"downSpeed",local_4c);
              json_object_object_add(uVar9,"upSpeed",local_48);
              json_object_object_add(uVar9,"downFlow",local_68);
              json_object_object_add(uVar9,"upFlow",local_64);
              json_object_object_add(uVar9,"lastRSSI",local_44);
              json_object_object_add(uVar9,"upDataRate",local_5c);
              json_object_object_add(uVar9,"downDataRate",local_58);
              uVar8 = json_object_new_array();
              uVar3 = json_object_new_array();
              uVar4 = json_object_new_array();
              local_68 = json_object_new_array();
              local_64 = json_object_new_array();
              do {
                uVar2 = uVar2 + 1;
                uVar5 = json_object_new_int(0xffffffff);
                json_object_array_add(uVar8,uVar5);
                uVar5 = json_object_new_int(0xffffffff);
                json_object_array_add(uVar3,uVar5);
                uVar5 = json_object_new_int(0xffffffff);
                json_object_array_add(uVar4,uVar5);
                uVar5 = json_object_new_int(0xffffffff);
                json_object_array_add(local_68,uVar5);
                uVar5 = json_object_new_int(0xffffffff);
                json_object_array_add(local_64,uVar5);
              } while (uVar2 != uVar6);
              json_object_object_add(uVar9,"oneWayDly",uVar8);
              json_object_object_add(uVar9,"upPkts",uVar3);
              json_object_object_add(uVar9,"upRetryPkts",uVar4);
              json_object_object_add(uVar9,"downPkts",local_68);
              json_object_object_add(uVar9,&DAT_006996e4,local_64);
              local_398[0] = '\0';
              local_398[1] = '\0';
              local_398[2] = '\0';
              local_398[3] = '\0';
              local_398[4] = '\0';
              local_398[5] = '\0';
              local_398[6] = '\0';
              local_398[7] = '\0';
              local_398[8] = '\0';
              local_398[9] = '\0';
              local_398[10] = '\0';
              local_398[0xb] = '\0';
              local_398[0xc] = '\0';
              local_398[0xd] = '\0';
              local_398[0xe] = '\0';
              local_398[0xf] = '\0';
              local_398[0x10] = '\0';
              local_398[0x11] = '\0';
              snprintf(local_398,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 2),
                       (uint)*(byte *)(param_1 + 3),(uint)*(byte *)(param_1 + 4),
                       (uint)*(byte *)(param_1 + 5),(uint)*(byte *)(param_1 + 6),
                       (uint)*(byte *)(param_1 + 7));
              uVar8 = json_object_new_string(local_398);
              json_object_object_add(iVar1,"clientMac",uVar8);
              json_object_object_add(iVar1,"data",uVar9);
              memset(acStack_384,0,0x40);
              snprintf(acStack_384,0x40,"%llu");
              uVar9 = json_object_new_string(acStack_384);
              json_object_object_add(iVar1,"interval",uVar9);
              memset(acStack_384,0,0x40);
              snprintf(acStack_384,0x40,"%llu");
              uVar9 = json_object_new_string(acStack_384);
              json_object_object_add(iVar1,"start",uVar9);
              if (*(int *)(param_2 + 0xc) == 0) {
                iVar10 = json_object_new_array();
                *(int *)(param_2 + 4) = iVar10;
                if (iVar10 == 0) {
                  json_object_put(iVar1);
                  return 2;
                }
              }
              uVar9 = 0;
              iVar10 = after_handle_client_json
                                 (param_2,local_50,&local_3a8,auStack_340,local_3a4[0],iVar1);
              if (iVar10 != 0) {
                if (iVar1 != 0) {
                  json_object_put(iVar1);
                }
                uVar9 = 0;
                if (local_3a8 != 0) {
                  if (*(int *)(local_3a8 + 8) != 0) {
                    json_object_put();
                  }
                  uVar9 = 0;
                  FUN_00407df0(local_3a8);
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar9;
}

