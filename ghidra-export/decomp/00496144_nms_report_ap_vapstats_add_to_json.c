// func nms_report_ap_vapstats_add_to_json @ 00496144 size=2736

undefined4 nms_report_ap_vapstats_add_to_json(byte *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  size_t sVar10;
  char *pcVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 uVar18;
  longlong lVar19;
  char local_6f8 [20];
  undefined1 auStack_6e4 [8];
  undefined4 local_6dc [6];
  undefined1 auStack_6c4 [84];
  char acStack_670 [100];
  undefined1 auStack_60c [128];
  int local_58c;
  char local_574 [212];
  undefined1 auStack_4a0 [352];
  int local_340;
  undefined1 auStack_338 [64];
  undefined4 local_2f8;
  undefined1 auStack_120 [192];
  int local_60;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  longlong local_38;
  undefined4 *local_30;
  
  memset(auStack_338,0,0x2d8);
  local_6f8[0] = '\0';
  local_6f8[1] = '\0';
  local_6f8[2] = '\0';
  local_6f8[3] = '\0';
  local_6f8[4] = '\0';
  local_6f8[5] = '\0';
  local_6f8[6] = '\0';
  local_6f8[7] = '\0';
  local_6f8[8] = '\0';
  local_6f8[9] = '\0';
  local_6f8[10] = '\0';
  local_6f8[0xb] = '\0';
  local_6f8[0xc] = '\0';
  local_6f8[0xd] = '\0';
  local_6f8[0xe] = '\0';
  local_6f8[0xf] = '\0';
  local_6f8[0x10] = '\0';
  local_6f8[0x11] = '\0';
  memset(auStack_6c4,0,0x54);
  iVar3 = rdmngr_profile_get_max_rd_per_ap();
  memset(auStack_60c,0,0x168);
  memset(auStack_4a0,0,0x168);
  local_54 = get_stats_sample_time(3);
  memset(acStack_670,0,100);
  memcpy(auStack_6e4,&PTR_s_OBSSandNonWiFiUsage_0069b3ac,0x20);
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  iVar4 = check_ap_can_report_by_statics(param_1,(int)(char)param_1[0x10],auStack_338);
  if (iVar4 != 0) {
    return 0;
  }
  apdb_get_ap_by_id(local_2f8,auStack_120,auStack_60c);
  local_58 = iVar3;
  if ((param_1[0x10] & 8) == 0) {
    local_58 = apdb_radio_count_by_id(local_2f8,auStack_120);
  }
  if (local_58 == -1) {
    local_58 = rdmngr_profile_get_max_rd_per_ap();
  }
  iVar3 = json_object_new_object();
  snprintf(local_6f8,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  uVar5 = json_object_new_string(local_6f8);
  json_object_object_add(iVar3,"deviceMac",uVar5);
  uVar5 = json_object_new_string(site_id);
  json_object_object_add(iVar3,"projectId",uVar5);
  pcVar11 = local_574;
  if (local_574[0] == '\0') {
    if (local_58c == 1) {
      pcVar11 = "WIRELESSROUTER";
      goto LAB_00496a00;
    }
    if (local_58c == 3) {
      pcVar11 = "SMBWIRELESSROUTER";
      goto LAB_00496a00;
    }
  }
  else {
LAB_00496a00:
    uVar5 = json_object_new_string(pcVar11);
    json_object_object_add(iVar3,"deviceType",uVar5);
  }
  iVar4 = rdmngr_profile_get_max_wlan_per_rd();
  local_340 = FUN_00408450(iVar4 << 8,0x1774);
  bVar1 = false;
  local_50 = 0;
  local_38 = (longlong)local_54 * 1000;
  local_60 = 0;
  local_3c = iVar3;
  local_30 = param_2;
  for (uVar15 = 1; puVar2 = local_30, iVar3 = local_3c, (int)uVar15 <= local_58; uVar15 = uVar15 + 1
      ) {
    iVar3 = check_ap_can_report_by_statics
                      (param_1,(int)*(char *)(*(int *)(param_1 + 0x18) + local_50),auStack_338);
    if (iVar3 == 0) {
      uVar5 = rdmngr_db_generate_rd_id(*(undefined4 *)(param_1 + 8),uVar15);
      iVar3 = rdmngr_db_rd_entry_get(uVar5,auStack_6c4);
      if (((iVar3 == 0) && (local_340 != 0)) &&
         (iVar3 = stats_db_radio_get_total
                            (*(undefined2 *)(param_1 + 10),uVar15 & 0xff,auStack_4a0,1), iVar3 == 0)
         ) {
        if (cloud_mngt_bssid_test != 0) {
          printf("\rd_index id: %u\r\n",uVar15);
          cloud_mngt_stats_db_ssid_print(local_340);
        }
        local_5c = 1;
        local_40 = uVar15;
        while (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), iVar3 = local_340, uVar15 = local_40,
              local_5c <= uVar6) {
          iVar12 = local_5c - 1;
          iVar4 = check_ap_can_report_by_statics
                            (param_1,(int)*(char *)(*(int *)(*(int *)(param_1 + 0x18) + local_50 + 8
                                                            ) + iVar12 * 8),auStack_338);
          if (iVar4 == 0) {
            iVar3 = iVar3 + iVar12 * 0x100;
            iVar4 = memcmp((void *)(iVar3 + 9),&bssid_empty,6);
            if (iVar4 != 0) {
              uVar5 = last_ap_stats_begin_report_time;
              uVar7 = DAT_00767634;
              uVar6 = get_report_sample_cnt
                                (*(undefined4 *)(iVar3 + 0x50),*(undefined4 *)(iVar3 + 0x54),
                                 *(undefined4 *)(iVar3 + 0x40),*(undefined4 *)(iVar3 + 0x44),
                                 last_ap_stats_begin_report_time,DAT_00767634,local_54);
              uVar15 = (uint)*(byte *)(iVar3 + 0x48);
              if ((int)uVar6 <= (int)(uint)*(byte *)(iVar3 + 0x48)) {
                uVar15 = uVar6;
              }
              if (0 < (int)uVar15) {
                lVar19 = (longlong)(int)((uVar15 - 1) * local_54) * 1000000;
                uVar6 = *(uint *)(iVar3 + 0x54) - (int)lVar19;
                lVar16 = __udivdi3((*(int *)(iVar3 + 0x50) - (int)((ulonglong)lVar19 >> 0x20)) -
                                   (uint)(*(uint *)(iVar3 + 0x54) < uVar6),uVar6,0,1000);
                lVar19 = CONCAT44(uVar5,uVar7);
                if (cloud_mngt_info_switch != '\0') {
                  lVar19 = lVar16;
                  printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
                         "nms_report_ap_vapstats_add_to_json",0x1799);
                }
                lVar17 = FUN_00407dd0();
                uVar14 = (uint)(lVar16 + lVar17);
                uVar18 = FUN_004081f0();
                uVar6 = uVar14 - (int)uVar18;
                iVar4 = ((int)((ulonglong)(lVar16 + lVar17) >> 0x20) -
                        (int)((ulonglong)uVar18 >> 0x20)) - (uint)(uVar14 < uVar6);
                if (cloud_mngt_info_switch != '\0') {
                  lVar19 = FUN_00407dd0();
                  printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_real_msecs()%llu\n",
                         "nms_report_ap_vapstats_add_to_json",0x179b);
                }
                if (cloud_mngt_info_switch != '\0') {
                  lVar19 = FUN_004081f0();
                  printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_msecs()%llu\n",
                         "nms_report_ap_vapstats_add_to_json",0x179c);
                }
                if (cloud_mngt_info_switch != '\0') {
                  printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
                         "nms_report_ap_vapstats_add_to_json",0x179d);
                  lVar19 = CONCAT44(iVar4,uVar6);
                }
                if (cloud_mngt_info_switch != '\0') {
                  printf("[CLOUD_MNGT_INFO]%s()/%d stat_interval_normal%d\n",
                         "nms_report_ap_vapstats_add_to_json",0x179e,local_54,
                         (int)((ulonglong)lVar19 >> 0x20),(int)lVar19);
                }
                stats_db_ssid_update_cloud_report_time
                          (*(undefined2 *)(param_1 + 10),local_40,local_5c);
                uVar5 = json_object_new_object();
                uVar7 = json_object_new_object();
                memset(acStack_670,0,100);
                snprintf(acStack_670,100,"%llu");
                uVar8 = json_object_new_string(acStack_670);
                json_object_object_add(uVar5,"interval",uVar8);
                memset(acStack_670,0,100);
                snprintf(acStack_670,100,"%llu");
                uVar8 = json_object_new_string(acStack_670);
                json_object_object_add(uVar5,"start",uVar8);
                uVar8 = json_object_new_int(local_40);
                json_object_object_add(uVar5,"radioId",uVar8);
                local_6f8[0] = '\0';
                local_6f8[1] = '\0';
                local_6f8[2] = '\0';
                local_6f8[3] = '\0';
                local_6f8[4] = '\0';
                local_6f8[5] = '\0';
                local_6f8[6] = '\0';
                local_6f8[7] = '\0';
                local_6f8[8] = '\0';
                local_6f8[9] = '\0';
                local_6f8[10] = '\0';
                local_6f8[0xb] = '\0';
                local_6f8[0xc] = '\0';
                local_6f8[0xd] = '\0';
                local_6f8[0xe] = '\0';
                local_6f8[0xf] = '\0';
                local_6f8[0x10] = '\0';
                local_6f8[0x11] = '\0';
                snprintf(local_6f8,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar3 + 9),
                         (uint)*(byte *)(iVar3 + 10),(uint)*(byte *)(iVar3 + 0xb),
                         (uint)*(byte *)(iVar3 + 0xc),(uint)*(byte *)(iVar3 + 0xd),
                         (uint)*(byte *)(iVar3 + 0xe));
                uVar8 = json_object_new_string(local_6f8);
                json_object_object_add(uVar5,"bssid",uVar8);
                uVar8 = json_object_new_array();
                local_4c = json_object_new_array();
                local_48 = json_object_new_array();
                local_44 = json_object_new_array();
                iVar4 = *(byte *)(iVar3 + 0x48) - uVar15;
                piVar13 = (int *)(iVar3 + (iVar4 + 0x36) * 4);
                for (; iVar4 < (int)(uint)*(byte *)(iVar3 + 0x48); iVar4 = iVar4 + 1) {
                  iVar12 = piVar13[-0x1e];
                  if (iVar12 == -1) {
                    iVar12 = -1;
                  }
                  uVar9 = json_object_new_int(iVar12);
                  json_object_array_add(uVar8,uVar9);
                  iVar12 = piVar13[-0x14];
                  if (iVar12 == -1) {
                    iVar12 = -1;
                  }
                  uVar9 = json_object_new_int(iVar12);
                  json_object_array_add(local_4c,uVar9);
                  if (piVar13[-10] == -1) {
                    uVar9 = json_object_new_int(0xffffffff);
                  }
                  else {
                    uVar9 = json_object_new_int64(0);
                  }
                  json_object_array_add(local_48,uVar9);
                  if (*piVar13 == -1) {
                    uVar9 = json_object_new_int(0xffffffff);
                  }
                  else {
                    uVar9 = json_object_new_int64(0);
                  }
                  piVar13 = piVar13 + 1;
                  json_object_array_add(local_44,uVar9);
                }
                json_object_object_add(uVar7,"upSpeed",uVar8);
                uVar6 = 0;
                json_object_object_add(uVar7,"downSpeed",local_4c);
                json_object_object_add(uVar7,"upFlow",local_48);
                json_object_object_add(uVar7,"downFlow",local_44);
                uVar8 = json_object_new_array();
                do {
                  uVar6 = uVar6 + 1;
                  uVar9 = json_object_new_int(0xffffffff);
                  json_object_array_add(uVar8,uVar9);
                } while (uVar6 != uVar15);
                json_object_object_add(uVar7,"clientNum",uVar8);
                iVar3 = 0;
                do {
                  uVar6 = 0;
                  uVar8 = json_object_new_array();
                  do {
                    uVar6 = uVar6 + 1;
                    uVar9 = json_object_new_int(0xffffffff);
                    json_object_array_add(uVar8,uVar9);
                  } while (uVar6 != uVar15);
                  iVar4 = iVar3 + 4;
                  json_object_object_add(uVar7,*(undefined4 *)((int)local_6dc + iVar3),uVar8);
                  iVar3 = iVar4;
                } while (iVar4 != 0x14);
                json_object_object_add(uVar5,"data",uVar7);
                if (local_60 == 0) {
                  local_60 = json_object_new_array();
                }
                bVar1 = true;
                json_object_array_add(local_60,uVar5);
              }
            }
          }
          local_5c = local_5c + 1;
        }
      }
    }
    local_50 = local_50 + 0xc;
  }
  if (local_340 != 0) {
    FUN_00407df0();
  }
  if (!bVar1) {
    json_object_put(iVar3);
    return 0xffffffff;
  }
  if (local_60 != 0) {
    json_object_object_add(iVar3,"vapStats",local_60);
  }
  iVar4 = puVar2[0xc];
  pcVar11 = (char *)json_object_to_json_string_ext(iVar3,0);
  sVar10 = strlen(pcVar11);
  if (((int)(~sVar10 + iVar4) < 0) || (puVar2[1] != 0)) {
    json_object_object_add(*puVar2,puVar2[5]);
    puVar2[1] = 0;
    puVar2[3] = 0;
    if (ap_report_switch == 0) {
      uVar5 = *puVar2;
    }
    else {
      iVar4 = nms_stat_obj_send_to_cloud(puVar2[6],*puVar2);
      uVar5 = *puVar2;
      if (iVar4 == 0) {
        json_object_object_del(uVar5,puVar2[5]);
        iVar4 = puVar2[1];
        goto LAB_00496a40;
      }
    }
    uVar7 = 0xffffffff;
    json_object_object_del(uVar5,puVar2[5]);
LAB_004968c0:
    if (iVar3 != 0) {
      json_object_put(iVar3);
    }
  }
  else {
    iVar4 = puVar2[1];
LAB_00496a40:
    if (iVar4 == 0) {
      iVar4 = json_object_new_array();
      puVar2[1] = iVar4;
      if (iVar4 == 0) {
        uVar7 = 2;
        goto LAB_004968c0;
      }
      puVar2[0xc] = 0x3f800;
      pcVar11 = (char *)json_object_to_json_string_ext(*puVar2,0);
      sVar10 = strlen(pcVar11);
      puVar2[0xc] = 0x3f801 - sVar10;
    }
    puVar2[3] = puVar2[3] + 1;
    json_object_array_add(puVar2[1],iVar3);
    iVar4 = puVar2[0xc];
    pcVar11 = (char *)json_object_to_json_string_ext(iVar3,0);
    sVar10 = strlen(pcVar11);
    puVar2[0xc] = (iVar4 + 1) - sVar10;
    uVar7 = 0;
  }
  return uVar7;
}

