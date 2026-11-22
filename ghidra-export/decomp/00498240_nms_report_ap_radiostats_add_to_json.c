// func nms_report_ap_radiostats_add_to_json @ 00498240 size=3296

undefined4 nms_report_ap_radiostats_add_to_json(byte *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  size_t sVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  int *piVar15;
  undefined4 *puVar16;
  longlong lVar17;
  longlong lVar18;
  undefined8 uVar19;
  longlong lVar20;
  char local_748 [12];
  char local_73c [4];
  undefined4 local_738;
  undefined2 local_734;
  char local_732;
  char local_730 [20];
  undefined4 local_71c [8];
  uint local_6fc [11];
  undefined4 local_6d0 [11];
  int local_6a4 [11];
  char acStack_678 [100];
  undefined1 auStack_614 [128];
  int local_594;
  char local_57c [212];
  int aiStack_4a8 [3];
  ushort local_49a;
  undefined4 local_468;
  undefined4 local_464;
  undefined1 auStack_458 [10];
  undefined1 auStack_44e [10];
  byte local_444;
  int local_440;
  uint local_43c;
  char acStack_354 [20];
  undefined1 auStack_340 [64];
  undefined4 local_300;
  undefined1 auStack_128 [192];
  uint local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  longlong local_38;
  undefined4 *local_30;
  undefined4 local_2c;
  
  memset(auStack_340,0,0x2d8);
  memset(local_6a4,0,0x2c);
  local_73c[0] = '\0';
  local_73c[1] = '\0';
  local_73c[2] = '\0';
  local_73c[3] = '\0';
  local_738 = 0;
  local_734 = 0;
  local_732 = '\0';
  memcpy(local_71c,&PTR_s_OBSSandNonWiFiUsage_0069b3ac,0x20);
  memcpy(local_6d0,&PTR_s_downSpeed_0069b3cc,0x2c);
  memcpy(local_6fc,&DAT_0069b3f8,0x2c);
  local_730[0] = '\0';
  local_730[1] = '\0';
  local_730[2] = '\0';
  local_730[3] = '\0';
  local_730[4] = '\0';
  local_730[5] = '\0';
  local_730[6] = '\0';
  local_730[7] = '\0';
  local_730[8] = '\0';
  local_730[9] = '\0';
  local_730[10] = '\0';
  local_730[0xb] = '\0';
  local_730[0xc] = '\0';
  local_730[0xd] = '\0';
  local_730[0xe] = '\0';
  local_730[0xf] = '\0';
  local_730[0x10] = '\0';
  local_730[0x11] = '\0';
  local_748[0] = '\0';
  local_748[1] = '\0';
  local_748[2] = '\0';
  local_748[3] = '\0';
  local_748[4] = '\0';
  local_748[5] = '\0';
  local_748[6] = '\0';
  local_748[7] = '\0';
  local_748[8] = '\0';
  local_748[9] = '\0';
  memset(auStack_614,0,0x168);
  memset(aiStack_4a8,0,0x168);
  local_5c = get_stats_sample_time(2);
  memset(acStack_678,0,100);
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  iVar4 = check_ap_can_report_by_statics(param_1,(int)(char)param_1[0x10],auStack_340);
  if (iVar4 != 0) {
    return 0;
  }
  apdb_get_ap_by_id(local_300,auStack_128,auStack_614);
  if ((param_1[0x10] & 8) == 0) {
    local_60 = apdb_radio_count_by_id(local_300,auStack_128);
    if (local_60 == -1) {
      local_60 = 0xffffffff;
      goto LAB_004983ac;
    }
  }
  else {
LAB_004983ac:
    local_60 = rdmngr_profile_get_max_rd_per_ap();
  }
  if (cloud_mngt_info_switch != '\0') {
    printf("[CLOUD_MNGT_INFO]%s()/%d rd_cnt:%d\n","nms_report_ap_radiostats_add_to_json",0x164d,
           local_60);
  }
  iVar4 = json_object_new_object();
  snprintf(local_730,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  uVar5 = json_object_new_string(local_730);
  json_object_object_add(iVar4,"deviceMac",uVar5);
  uVar5 = json_object_new_string(site_id);
  json_object_object_add(iVar4,"projectId",uVar5);
  if (local_57c[0] == '\0') {
    if (local_594 == 1) {
      pcVar14 = "WIRELESSROUTER";
      goto LAB_00498764;
    }
    if (local_594 == 3) {
      pcVar14 = "SMBWIRELESSROUTER";
      goto LAB_00498764;
    }
  }
  else {
    pcVar14 = local_57c;
LAB_00498764:
    uVar5 = json_object_new_string(pcVar14);
    json_object_object_add(iVar4,"deviceType",uVar5);
  }
  bVar3 = false;
  local_50 = 0;
  local_38 = (longlong)local_5c * 1000;
  local_54 = 0;
  local_58 = 0;
  local_64 = 0;
  local_3c = iVar4;
  local_30 = param_2;
  for (local_68 = 1; puVar16 = local_30, iVar4 = local_3c, (int)local_68 <= local_60;
      local_68 = local_68 + 1) {
    iVar4 = check_ap_can_report_by_statics
                      (param_1,(int)*(char *)(*(int *)(param_1 + 0x18) + local_50),auStack_340);
    if (iVar4 == 0) {
      memset(aiStack_4a8,0,0x168);
      iVar4 = stats_db_radio_get_total(*(undefined2 *)(param_1 + 10),local_68 & 0xff,aiStack_4a8,1);
      if (iVar4 == 0) {
        uVar5 = last_ap_stats_begin_report_time;
        uVar8 = DAT_00767634;
        uVar6 = get_report_sample_cnt
                          (local_440,local_43c,local_468,local_464,last_ap_stats_begin_report_time,
                           DAT_00767634,local_5c);
        uVar12 = (uint)local_444;
        if ((int)uVar6 <= (int)(uint)local_444) {
          uVar12 = uVar6;
        }
        if (0 < (int)uVar12) {
          lVar20 = (longlong)(int)((uVar12 - 1) * local_5c) * 1000000;
          uVar6 = local_43c - (int)lVar20;
          lVar17 = __udivdi3((local_440 - (int)((ulonglong)lVar20 >> 0x20)) -
                             (uint)(local_43c < uVar6),uVar6,0,1000);
          lVar20 = CONCAT44(uVar5,uVar8);
          if (cloud_mngt_info_switch != '\0') {
            lVar20 = lVar17;
            printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
                   "nms_report_ap_radiostats_add_to_json",0x1673);
          }
          lVar18 = FUN_00407dd0();
          uVar6 = (uint)(lVar17 + lVar18);
          uVar19 = FUN_004081f0();
          local_4c = uVar6 - (int)uVar19;
          local_40 = ((int)((ulonglong)(lVar17 + lVar18) >> 0x20) - (int)((ulonglong)uVar19 >> 0x20)
                     ) - (uint)(uVar6 < local_4c);
          if (cloud_mngt_info_switch != '\0') {
            lVar20 = FUN_00407dd0();
            printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_real_msecs()%llu\n",
                   "nms_report_ap_radiostats_add_to_json",0x1675);
          }
          if (cloud_mngt_info_switch != '\0') {
            lVar20 = FUN_004081f0();
            printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_msecs()%llu\n",
                   "nms_report_ap_radiostats_add_to_json",0x1676);
          }
          if (cloud_mngt_info_switch != '\0') {
            iVar4 = local_40;
            uVar6 = local_4c;
            printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
                   "nms_report_ap_radiostats_add_to_json",0x1677);
            lVar20 = CONCAT44(iVar4,uVar6);
          }
          if (cloud_mngt_info_switch == '\0') {
            uVar2 = *(undefined2 *)(param_1 + 10);
          }
          else {
            printf("[CLOUD_MNGT_INFO]%s()/%d stat_interval_normal%d\n",
                   "nms_report_ap_radiostats_add_to_json",0x1678,local_5c,
                   (int)((ulonglong)lVar20 >> 0x20),(int)lVar20);
            uVar2 = *(undefined2 *)(param_1 + 10);
          }
          stats_db_rd_update_cloud_report_time(uVar2,local_68,local_440,local_43c);
          if (aiStack_4a8[1] == 0) {
            uVar5 = json_object_new_object();
            pcVar14 = "2g%d";
            iVar4 = local_58 + 1;
            local_58 = iVar4;
          }
          else {
            bVar3 = true;
            if (aiStack_4a8[1] != 1) goto LAB_004984c4;
            uVar5 = json_object_new_object();
            pcVar14 = "5g%d";
            iVar4 = local_54 + 1;
            local_54 = iVar4;
          }
          snprintf(local_748,10,pcVar14,iVar4);
          uVar8 = json_object_new_string(local_748);
          json_object_object_add(uVar5,"radioName",uVar8);
          uVar8 = json_object_new_int(local_68);
          json_object_object_add(uVar5,"radioId",uVar8);
          uVar8 = json_object_new_object();
          local_48 = json_object_new_array();
          local_44 = json_object_new_array();
          for (iVar4 = local_444 - uVar12; iVar4 < (int)(uint)local_444; iVar4 = iVar4 + 1) {
            uVar1 = auStack_44e[iVar4];
            uVar9 = json_object_new_int(auStack_458[iVar4]);
            json_object_array_add(local_48,uVar9);
            uVar9 = json_object_new_int(uVar1);
            json_object_array_add(local_44,uVar9);
          }
          local_73c[0] = '\0';
          local_73c[1] = '\0';
          local_73c[2] = '\0';
          local_73c[3] = '\0';
          local_738 = 0;
          local_734 = 0;
          local_732 = '\0';
          pcVar14 = local_73c;
          memset(local_6a4,0,0x2c);
          iVar4 = 0;
          do {
            bVar3 = ((uint)local_49a & *(uint *)((int)local_6fc + iVar4)) != 0;
            *pcVar14 = bVar3;
            if (bVar3) {
              uVar9 = json_object_new_array();
              *(undefined4 *)((int)local_6a4 + iVar4) = uVar9;
            }
            iVar4 = iVar4 + 4;
            pcVar14 = pcVar14 + 1;
          } while (iVar4 != 0x2c);
          iVar4 = local_444 - uVar12;
          pcVar14 = acStack_354 + iVar4;
          piVar15 = aiStack_4a8 + iVar4 + 0x32;
          for (; iVar4 < (int)(uint)local_444; iVar4 = iVar4 + 1) {
            if (local_73c[0] == '\0') {
LAB_00498c6c:
            }
            else if (local_6a4[0] != 0) {
              FUN_00498210(local_6a4[0],piVar15[-10]);
              goto LAB_00498c6c;
            }
            if (local_73c[1] == '\0') {
LAB_00498c8c:
            }
            else if (local_6a4[1] != 0) {
              FUN_00498210(local_6a4[1],piVar15[-0x14]);
              goto LAB_00498c8c;
            }
            iVar10 = local_6a4[2];
            if (local_73c[2] != '\0') {
              if (local_6a4[2] != 0) {
                if (piVar15[10] == -1) {
                  uVar9 = json_object_new_int(0xffffffff);
                }
                else {
                  uVar9 = json_object_new_int64(0);
                }
                json_object_array_add(iVar10,uVar9);
              }
            }
            iVar10 = local_6a4[3];
            if (local_73c[3] == '\0') {
            }
            else {
              if (local_6a4[3] != 0) {
                if (*piVar15 == -1) {
                  uVar9 = json_object_new_int(0xffffffff);
                }
                else {
                  uVar9 = json_object_new_int64(0);
                }
                json_object_array_add(iVar10,uVar9);
              }
            }
            iVar10 = local_6a4[4];
            if ((local_738._0_1_ != '\0') && (local_6a4[4] != 0)) {
              uVar6 = (uint)(byte)pcVar14[-0x28];
              if (uVar6 == 0xff) {
                uVar6 = 0xffffffff;
              }
              uVar9 = json_object_new_int(uVar6);
              json_object_array_add(iVar10,uVar9);
            }
            iVar10 = local_6a4[5];
            if ((local_738._1_1_ != '\0') && (local_6a4[5] != 0)) {
              uVar6 = (uint)(byte)pcVar14[-0x32];
              if (uVar6 == 0xff) {
                uVar6 = 0xffffffff;
              }
              uVar9 = json_object_new_int(uVar6);
              json_object_array_add(iVar10,uVar9);
            }
            iVar10 = local_6a4[6];
            if ((local_738._2_1_ != '\0') && (local_6a4[6] != 0)) {
              uVar6 = (uint)(byte)pcVar14[-0x3c];
              if (uVar6 == 0xff) {
                uVar6 = 0xffffffff;
              }
              uVar9 = json_object_new_int(uVar6);
              json_object_array_add(iVar10,uVar9);
            }
            iVar10 = local_6a4[8];
            if ((local_734._0_1_ != '\0') && (local_6a4[8] != 0)) {
              iVar13 = (int)pcVar14[-0x14];
              if (iVar13 == -1) {
                iVar13 = -1;
              }
              uVar9 = json_object_new_int(iVar13);
              json_object_array_add(iVar10,uVar9);
            }
            iVar10 = local_6a4[9];
            if (((char)local_734 != '\0') && (local_6a4[9] != 0)) {
              uVar6 = (uint)(byte)pcVar14[-0x1e];
              if (uVar6 == 0xff) {
                uVar6 = 0xffffffff;
              }
              uVar9 = json_object_new_int(uVar6);
              json_object_array_add(iVar10,uVar9);
            }
            iVar10 = local_6a4[10];
            uVar6 = local_738 & 0xff;
            if ((local_732 != '\0') && (local_6a4[10] != 0)) {
              uVar6 = (uint)(byte)pcVar14[-10];
              if (uVar6 == 0xff) {
                uVar6 = 0xffffffff;
              }
              uVar9 = json_object_new_int(uVar6);
              json_object_array_add(iVar10,uVar9);
              uVar6 = local_738 & 0xff;
            }
            if ((uVar6 != 0) && (local_6a4[7] != 0)) {
              FUN_00498210(local_6a4[7],(int)*pcVar14);
            }
            pcVar14 = pcVar14 + 1;
            piVar15 = piVar15 + 1;
          }
          puVar16 = local_6d0;
          local_2c = uVar5;
          piVar15 = local_6a4;
          iVar4 = 0;
          do {
            if (local_73c[iVar4] == '\0') {
              if (iVar4 < 8) {
                uVar5 = 0xffffffff;
                if (iVar4 == 7) {
                  uVar5 = 0x7f;
                }
                uVar6 = 0;
                iVar10 = json_object_new_array();
                *piVar15 = iVar10;
                do {
                  uVar9 = json_object_new_int(uVar5);
                  uVar6 = uVar6 + 1;
                  json_object_array_add(iVar10,uVar9);
                } while (uVar6 != uVar12);
                uVar5 = *puVar16;
                goto LAB_00498d44;
              }
            }
            else {
              uVar5 = *puVar16;
              iVar10 = *piVar15;
LAB_00498d44:
              json_object_object_add(uVar8,uVar5,iVar10);
            }
            uVar5 = local_2c;
            iVar4 = iVar4 + 1;
            puVar16 = puVar16 + 1;
            piVar15 = piVar15 + 1;
          } while (iVar4 != 0xb);
          if (local_64 == 0) {
            local_64 = json_object_new_array();
          }
          iVar4 = 0;
          json_object_object_add(uVar8,"clientNum",local_48);
          json_object_object_add(uVar8,"clientLoading",local_44);
          do {
            uVar6 = 0;
            uVar9 = json_object_new_array();
            do {
              uVar6 = uVar6 + 1;
              uVar11 = json_object_new_int(0xffffffff);
              json_object_array_add(uVar9,uVar11);
            } while (uVar6 != uVar12);
            puVar16 = (undefined4 *)((int)local_71c + iVar4);
            iVar4 = iVar4 + 4;
            json_object_object_add(uVar8,*puVar16,uVar9);
          } while (iVar4 != 0x20);
          json_object_object_add(uVar5,"data",uVar8);
          memset(acStack_678,0,100);
          snprintf(acStack_678,100,"%llu");
          uVar8 = json_object_new_string(acStack_678);
          json_object_object_add(uVar5,"interval",uVar8);
          memset(acStack_678,0,100);
          bVar3 = true;
          snprintf(acStack_678,100,"%llu");
          uVar8 = json_object_new_string(acStack_678);
          json_object_object_add(uVar5,"start",uVar8);
          json_object_array_add(local_64,uVar5);
        }
      }
    }
LAB_004984c4:
    local_50 = local_50 + 0xc;
  }
  if (local_64 != 0) {
    json_object_object_add(local_3c,"radioStats",local_64);
  }
  if (!bVar3) {
    json_object_put(iVar4);
    return 0xffffffff;
  }
  iVar10 = puVar16[0xc];
  pcVar14 = (char *)json_object_to_json_string_ext(iVar4,0);
  sVar7 = strlen(pcVar14);
  if (((int)(~sVar7 + iVar10) < 0) || (puVar16[1] != 0)) {
    json_object_object_add(*puVar16,puVar16[5]);
    puVar16[1] = 0;
    puVar16[3] = 0;
    if (ap_report_switch == 0) {
      uVar5 = *puVar16;
    }
    else {
      iVar10 = nms_stat_obj_send_to_cloud(puVar16[6],*puVar16);
      uVar5 = *puVar16;
      if (iVar10 == 0) {
        json_object_object_del(uVar5,puVar16[5]);
        iVar10 = puVar16[1];
        goto LAB_004987d8;
      }
    }
    json_object_object_del(uVar5,puVar16[5]);
LAB_0049874c:
    uVar5 = 0xffffffff;
    if (iVar4 != 0) {
      json_object_put(iVar4);
    }
  }
  else {
    iVar10 = puVar16[1];
LAB_004987d8:
    if (iVar10 == 0) {
      iVar10 = json_object_new_array();
      puVar16[1] = iVar10;
      if (iVar10 == 0) goto LAB_0049874c;
      puVar16[0xc] = 0x3f800;
      pcVar14 = (char *)json_object_to_json_string_ext(*puVar16,0);
      sVar7 = strlen(pcVar14);
      puVar16[0xc] = 0x3f801 - sVar7;
    }
    puVar16[3] = puVar16[3] + 1;
    json_object_array_add(puVar16[1],iVar4);
    iVar10 = puVar16[0xc];
    pcVar14 = (char *)json_object_to_json_string_ext(iVar4,0);
    sVar7 = strlen(pcVar14);
    puVar16[0xc] = (iVar10 + 1) - sVar7;
    uVar5 = 0;
  }
  return uVar5;
}

