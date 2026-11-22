// func nms_report_ap_devstats_add_to_json @ 00496bf4 size=2120

undefined4 nms_report_ap_devstats_add_to_json(byte *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  size_t sVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  longlong lVar15;
  longlong lVar16;
  undefined8 uVar17;
  longlong lVar18;
  char local_6b8 [20];
  char acStack_6a4 [100];
  undefined1 auStack_640 [128];
  int local_5c0;
  char local_5a8 [208];
  byte local_4d8 [4];
  undefined4 uStack_4d4;
  ushort local_4ce;
  undefined4 local_498;
  undefined4 local_494;
  uint local_490;
  int local_488;
  uint local_484;
  undefined1 auStack_324 [12];
  undefined1 auStack_318 [64];
  undefined4 local_2d8;
  undefined1 auStack_100 [192];
  int local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  byte *local_2c;
  
  memset(auStack_318,0,0x2d8);
  local_6b8[0] = '\0';
  local_6b8[1] = '\0';
  local_6b8[2] = '\0';
  local_6b8[3] = '\0';
  local_6b8[4] = '\0';
  local_6b8[5] = '\0';
  local_6b8[6] = '\0';
  local_6b8[7] = '\0';
  local_6b8[8] = '\0';
  local_6b8[9] = '\0';
  local_6b8[10] = '\0';
  local_6b8[0xb] = '\0';
  local_6b8[0xc] = '\0';
  local_6b8[0xd] = '\0';
  local_6b8[0xe] = '\0';
  local_6b8[0xf] = '\0';
  local_6b8[0x10] = '\0';
  local_6b8[0x11] = '\0';
  memset(auStack_640,0,0x168);
  memset(local_4d8,0,0x1c0);
  local_40 = get_stats_sample_time(1);
  memset(acStack_6a4,0,100);
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  iVar2 = check_ap_can_report_by_statics(param_1,(int)(char)param_1[0x10],auStack_318);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = stats_db_ap_global_get(*(undefined2 *)(param_1 + 10),local_4d8,1);
  if (iVar2 != 0) {
    return 0;
  }
  lVar18 = CONCAT44(last_ap_stats_begin_report_time,DAT_00767634);
  uVar3 = get_report_sample_cnt
                    (local_488,local_484,local_498,local_494,last_ap_stats_begin_report_time,
                     DAT_00767634,local_40);
  uVar12 = local_490;
  if (uVar3 <= local_490) {
    uVar12 = uVar3;
  }
  if ((int)uVar12 < 1) {
    return 0;
  }
  lVar15 = (longlong)(int)((uVar12 - 1) * local_40) * 1000000;
  uVar3 = local_484 - (int)lVar15;
  lVar15 = __udivdi3((local_488 - (int)((ulonglong)lVar15 >> 0x20)) - (uint)(local_484 < uVar3),
                     uVar3,0,1000);
  if (cloud_mngt_info_switch != '\0') {
    lVar18 = lVar15;
    printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
           "nms_report_ap_devstats_add_to_json",0x1862);
  }
  lVar16 = FUN_00407dd0();
  uVar3 = (uint)(lVar15 + lVar16);
  uVar17 = FUN_004081f0();
  local_3c = uVar3 - (int)uVar17;
  local_30 = ((int)((ulonglong)(lVar15 + lVar16) >> 0x20) - (int)((ulonglong)uVar17 >> 0x20)) -
             (uint)(uVar3 < local_3c);
  if (cloud_mngt_info_switch != '\0') {
    lVar18 = FUN_00407dd0();
    printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_real_msecs()%llu\n",
           "nms_report_ap_devstats_add_to_json",0x1864);
  }
  if (cloud_mngt_info_switch != '\0') {
    lVar18 = FUN_004081f0();
    printf("[CLOUD_MNGT_INFO]%s()/%d uac_time_msecs()%llu\n","nms_report_ap_devstats_add_to_json",
           0x1865);
  }
  if (cloud_mngt_info_switch != '\0') {
    lVar18 = CONCAT44(local_30,local_3c);
    printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_report_time%llu\n",
           "nms_report_ap_devstats_add_to_json",0x1866);
  }
  if (cloud_mngt_info_switch == '\0') {
    uVar1 = *(undefined2 *)(param_1 + 10);
  }
  else {
    printf("[CLOUD_MNGT_INFO]%s()/%d stat_interval_normal%d\n","nms_report_ap_devstats_add_to_json",
           0x1867,local_40,lVar18);
    uVar1 = *(undefined2 *)(param_1 + 10);
  }
  stats_db_ap_update_cloud_report_time(uVar1);
  iVar2 = json_object_new_object();
  snprintf(local_6b8,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  uVar4 = json_object_new_string(local_6b8);
  json_object_object_add(iVar2,"deviceMac",uVar4);
  uVar4 = json_object_new_string(site_id);
  json_object_object_add(iVar2,"projectId",uVar4);
  apdb_get_ap_by_id(local_2d8,auStack_100,auStack_640);
  pcVar9 = local_5a8;
  if (local_5a8[0] == '\0') {
    if (local_5c0 == 1) {
      pcVar9 = "WIRELESSROUTER";
      goto LAB_00497098;
    }
    if (local_5c0 == 3) {
      pcVar9 = "SMBWIRELESSROUTER";
      goto LAB_00497098;
    }
  }
  else {
LAB_00497098:
    uVar4 = json_object_new_string(pcVar9);
    json_object_object_add(iVar2,"deviceType",uVar4);
  }
  iVar13 = 0;
  uVar4 = json_object_new_object();
  local_38 = json_object_new_array();
  iVar14 = 0;
  uVar5 = json_object_new_object();
  uVar12 = local_490 - uVar12;
  puVar10 = &uStack_4d4 + uVar12 + 0x4e;
  for (; uVar12 < local_490; uVar12 = uVar12 + 1) {
    uVar6 = json_object_new_array();
    uVar8 = 0xffffffff;
    if ((local_4ce & 1) != 0) {
      uVar8 = puVar10[-0x32];
    }
    uVar8 = json_object_new_int(uVar8);
    json_object_array_add(uVar6,uVar8);
    uVar8 = 0xffffffff;
    if ((local_4ce & 8) != 0) {
      uVar8 = puVar10[-0x14];
    }
    uVar8 = json_object_new_int(uVar8);
    json_object_array_add(uVar6,uVar8);
    uVar8 = 0xffffffff;
    if ((local_4ce & 2) != 0) {
      uVar8 = puVar10[-0x28];
    }
    uVar8 = json_object_new_int(uVar8);
    json_object_array_add(uVar6,uVar8);
    uVar8 = 0xffffffff;
    if ((local_4ce & 4) != 0) {
      uVar8 = puVar10[-0x1e];
    }
    uVar8 = json_object_new_int(uVar8);
    json_object_array_add(uVar6,uVar8);
    uVar8 = 0xffffffff;
    if ((local_4ce & 0x10) != 0) {
      uVar8 = puVar10[-10];
    }
    uVar8 = json_object_new_int(uVar8);
    json_object_array_add(uVar6,uVar8);
    uVar8 = json_object_new_int(*puVar10);
    json_object_array_add(uVar6,uVar8);
    json_object_array_add(local_38,uVar6);
    if ((short)local_4ce < 0) {
      if (iVar13 == 0) {
        iVar13 = json_object_new_array();
      }
      uVar6 = json_object_new_int(auStack_324[uVar12]);
      json_object_array_add(iVar13,uVar6);
    }
    if ((local_4ce & 0x4000) != 0) {
      if (iVar14 == 0) {
        iVar14 = json_object_new_array();
      }
      local_34 = json_object_new_array();
      local_2c = local_4d8 + uVar12 * 8;
      for (iVar11 = 0; iVar11 < (int)(uint)local_4d8[0]; iVar11 = iVar11 + 1) {
        uVar6 = json_object_new_int(local_2c[iVar11 + 0x164]);
        json_object_array_add(local_34,uVar6);
      }
      json_object_array_add(iVar14,local_34);
    }
    puVar10 = puVar10 + 1;
  }
  if ((short)local_4ce < 0) {
    json_object_object_add(uVar4,"memoryUsage",iVar13);
  }
  if ((local_4ce & 0x4000) != 0) {
    json_object_object_add(uVar4,"cpuUsage",iVar14);
  }
  json_object_object_add(uVar4,"wirelessConnStats",local_38);
  json_object_object_add(uVar5,"data",uVar4);
  memset(acStack_6a4,0,100);
  snprintf(acStack_6a4,100,"%llu");
  uVar4 = json_object_new_string(acStack_6a4);
  json_object_object_add(uVar5,"interval",uVar4);
  memset(acStack_6a4,0,100);
  snprintf(acStack_6a4,100,"%llu");
  uVar4 = json_object_new_string(acStack_6a4);
  json_object_object_add(uVar5,"start",uVar4);
  json_object_object_add(iVar2,"devStats",uVar5);
  iVar14 = param_2[0xc];
  pcVar9 = (char *)json_object_to_json_string_ext(iVar2,0);
  sVar7 = strlen(pcVar9);
  if ((-1 < (int)(~sVar7 + iVar14)) && (param_2[1] == 0)) {
    iVar14 = param_2[1];
LAB_00497378:
    if (iVar14 == 0) {
      iVar14 = json_object_new_array();
      param_2[1] = iVar14;
      if (iVar14 == 0) {
        uVar5 = 2;
        goto LAB_00497258;
      }
      param_2[0xc] = 0x3f800;
      pcVar9 = (char *)json_object_to_json_string_ext(*param_2,0);
      sVar7 = strlen(pcVar9);
      param_2[0xc] = 0x3f801 - sVar7;
    }
    param_2[3] = param_2[3] + 1;
    json_object_array_add(param_2[1],iVar2);
    iVar14 = param_2[0xc];
    pcVar9 = (char *)json_object_to_json_string_ext(iVar2,0);
    sVar7 = strlen(pcVar9);
    param_2[0xc] = (iVar14 + 1) - sVar7;
    return 0;
  }
  json_object_object_add(*param_2,param_2[5]);
  param_2[1] = 0;
  param_2[3] = 0;
  if (ap_report_switch == 0) {
    uVar4 = *param_2;
  }
  else {
    iVar14 = nms_stat_obj_send_to_cloud(param_2[6],*param_2);
    uVar4 = *param_2;
    if (iVar14 == 0) {
      json_object_object_del(uVar4,param_2[5]);
      iVar14 = param_2[1];
      goto LAB_00497378;
    }
  }
  uVar5 = 0xffffffff;
  json_object_object_del(uVar4,param_2[5]);
LAB_00497258:
  if (iVar2 != 0) {
    json_object_put(iVar2);
    return uVar5;
  }
  return uVar5;
}

