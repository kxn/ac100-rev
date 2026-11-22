// func cloud_mngt_ap_status_add_to_json @ 00494c0c size=2908

undefined4 cloud_mngt_ap_status_add_to_json(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  size_t sVar9;
  short *psVar10;
  int iVar11;
  undefined4 *puVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  char local_660 [12];
  char local_654 [16];
  undefined4 local_644;
  undefined4 local_640;
  undefined4 local_63c;
  undefined4 local_638;
  undefined2 local_634;
  char acStack_630 [40];
  char acStack_608 [52];
  undefined1 auStack_5d4 [8];
  char local_5cc;
  char local_5cb;
  char local_5aa;
  char local_5a8;
  short local_598;
  char acStack_580 [100];
  undefined1 auStack_51c [128];
  int local_49c;
  char local_484 [200];
  int local_3bc;
  int local_3b8;
  undefined1 auStack_3b0 [10];
  ushort local_3a6;
  int local_250;
  char local_248 [300];
  int local_11c;
  undefined1 auStack_118 [216];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  local_644 = 0;
  local_640 = 0;
  local_63c = 0;
  local_638 = 0;
  local_634 = 0;
  memset(acStack_630,0,0x28);
  local_654[0] = '\0';
  local_654[1] = '\0';
  local_654[2] = '\0';
  local_654[3] = '\0';
  local_654[4] = '\0';
  local_654[5] = '\0';
  local_654[6] = '\0';
  local_654[7] = '\0';
  local_654[8] = '\0';
  local_654[9] = '\0';
  local_654[10] = '\0';
  local_654[0xb] = '\0';
  local_654[0xc] = '\0';
  local_654[0xd] = '\0';
  local_654[0xe] = '\0';
  local_654[0xf] = '\0';
  memset(acStack_608,0,0x33);
  memset(acStack_580,0,100);
  memset(auStack_51c,0,0x168);
  local_660[0] = '\0';
  local_660[1] = '\0';
  local_660[2] = '\0';
  local_660[3] = '\0';
  local_660[4] = '\0';
  local_660[5] = '\0';
  local_660[6] = '\0';
  local_660[7] = '\0';
  local_660[8] = '\0';
  local_660[9] = '\0';
  memset(auStack_5d4,0,0x54);
  memset(auStack_3b0,0,0x168);
  memset(local_248,0,0x205);
  if (param_1 == 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x1c5) == '\0') {
    return 0;
  }
  if (*(int *)(param_1 + 0x3c) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0;
  }
  local_30 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
  iVar2 = check_can_direct_report_by_ac(param_1,0);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = json_object_new_object();
  snprintf((char *)&local_644,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x48),
           (uint)*(byte *)(param_1 + 0x49),(uint)*(byte *)(param_1 + 0x4a),
           (uint)*(byte *)(param_1 + 0x4b),(uint)*(byte *)(param_1 + 0x4c),
           (uint)*(byte *)(param_1 + 0x4d));
  uVar3 = json_object_new_string(&local_644);
  json_object_object_add(iVar2,"deviceMac",uVar3);
  uVar3 = json_object_new_string(param_1 + 0x4e);
  json_object_object_add(iVar2,"deviceName",uVar3);
  uVar3 = json_object_new_int(*(undefined2 *)(param_1 + 0x10));
  json_object_object_add(iVar2,&DAT_006983bc,uVar3);
  uVar3 = json_object_new_int64(0,*(undefined4 *)(param_1 + 0x40));
  json_object_object_add(iVar2,"deviceModelId",uVar3);
  FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
               *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
               *(undefined4 *)(param_1 + 0x27c),acStack_630,0x28,"0.0.0.0");
  pcVar13 = acStack_630;
  if (*(int *)(param_1 + 0x2ac) == 0) {
    pcVar13 = "0.0.0.0";
  }
  uVar3 = json_object_new_string(pcVar13);
  json_object_object_add(iVar2,&DAT_00677c24,uVar3);
  iVar11 = 1;
  if (*(int *)(param_1 + 0x2ac) - 1U < 3) {
    iVar11 = (int)"cloud_mngt_apmngr_callback_wtp_join"[*(int *)(param_1 + 0x2ac) + 0x23];
  }
  uVar3 = json_object_new_int(iVar11);
  json_object_object_add(iVar2,"status",uVar3);
  apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_51c);
  uVar3 = json_object_new_string(site_id);
  json_object_object_add(iVar2,"projectId",uVar3);
  pcVar13 = local_484;
  if (local_484[0] == '\0') {
    if (local_49c == 1) {
      pcVar13 = "WIRELESSROUTER";
      goto LAB_00495184;
    }
    if (local_49c == 3) {
      pcVar13 = "SMBWIRELESSROUTER";
      goto LAB_00495184;
    }
    uVar1 = *(ushort *)(param_1 + 0x44);
  }
  else {
LAB_00495184:
    uVar3 = json_object_new_string(pcVar13);
    json_object_object_add(iVar2,"deviceType",uVar3);
    uVar1 = *(ushort *)(param_1 + 0x44);
  }
  uVar14 = (uint)uVar1;
  uVar4 = (uint)*(ushort *)(param_1 + 0x46);
  if (uVar14 + uVar4 == 0) {
    psVar10 = (short *)(local_3b8 + (local_3bc + -1) * 0x38);
    uVar14 = (uint)*psVar10;
    uVar4 = (uint)psVar10[1];
  }
  snprintf(local_654,0x10,"%d.%d",uVar14,uVar4);
  uVar3 = json_object_new_string(local_654);
  json_object_object_add(iVar2,"hardwareVersion",uVar3);
  if (*(int *)(param_1 + 0x2ac) != 0) {
    uVar4 = *(uint *)(param_1 + 0x210);
    snprintf(acStack_608,0x33,"%d.%d.%d Build %02d%02d%02d Rel.%05d",
             (uint)*(ushort *)(param_1 + 0x208),(uint)*(ushort *)(param_1 + 0x20a),
             (uint)*(ushort *)(param_1 + 0x20c),uVar4 >> 0x10,(uVar4 << 0x10) >> 0x18,uVar4 & 0xff,
             *(undefined4 *)(param_1 + 0x214));
  }
  uVar3 = json_object_new_string(acStack_608);
  json_object_object_add(iVar2,"softwareVersion",uVar3);
  uVar4 = *(uint *)(param_1 + 0x1b8);
  if ((1 < *(uint *)(param_1 + 0x2ac)) && (*(int *)(param_1 + 0x288) != 0)) {
    uVar4 = (uint)(*(int *)(param_1 + 0x288) == 1);
  }
  if (uVar4 == 0) {
    pcVar13 = "Led off";
  }
  else {
    pcVar13 = "Led on";
  }
  uVar4 = 1;
  uVar3 = json_object_new_string(pcVar13 + 4);
  json_object_object_add(iVar2,"led",uVar3);
  iVar15 = 0;
  uVar3 = json_object_new_boolean(cloud_config_switch);
  json_object_object_add(iVar2,"syncConfig",uVar3);
  _cloud_mngt_mesh_info_add
            (iVar2,*(undefined4 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 0x18),local_49c);
  local_38 = json_object_new_array();
  iVar11 = rdmngr_profile_get_max_wlan_per_rd();
  local_250 = FUN_00408450(iVar11 << 8,0x1539);
  local_3c = 0;
  local_40 = 0;
  while ((int)uVar4 <= local_30) {
    uVar3 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),uVar4);
    if (((local_250 != 0) && (iVar11 = rdmngr_db_rd_entry_get(uVar3,auStack_5d4), iVar11 == 0)) &&
       (iVar11 = stats_db_radio_get_total
                           (*(undefined2 *)(param_1 + 0x10),uVar4 & 0xff,auStack_3b0,0), iVar11 == 0
       )) {
      if (cloud_mngt_bssid_test != 0) {
        memset(acStack_580,0,100);
        snprintf(acStack_580,100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x48),
                 (uint)*(byte *)(param_1 + 0x49),(uint)*(byte *)(param_1 + 0x4a),
                 (uint)*(byte *)(param_1 + 0x4b),(uint)*(byte *)(param_1 + 0x4c),
                 (uint)*(byte *)(param_1 + 0x4d));
        printf("\ap_mac %s\r\n",acStack_580);
        printf("\rd_index id: %u\r\n",uVar4);
        cloud_mngt_stats_db_ssid_print(local_250);
      }
      local_34 = 0;
      for (uVar14 = 1; uVar5 = rdmngr_profile_get_max_wlan_per_rd(), iVar11 = local_250,
          uVar14 <= uVar5; uVar14 = uVar14 + 1) {
        iVar6 = wserv_db_rd_get_wserv_id(uVar3,uVar14 & 0xff);
        if ((iVar6 != -1) && (iVar6 = uac_wservice_get_entry_by_id(iVar6,local_248), iVar6 == 0)) {
          iVar11 = iVar11 + local_34;
          uVar7 = json_object_new_object();
          uVar8 = json_object_new_int(uVar4);
          json_object_object_add(uVar7,"radioId",uVar8);
          uVar8 = json_object_new_int(uVar3);
          json_object_object_add(uVar7,"radioIndex",uVar8);
          if ((*(byte *)(iVar11 + 8) & 3) == 3) {
            local_644 = 0;
            local_640 = 0;
            local_63c = 0;
            local_638 = 0;
            local_634 = 0;
            snprintf((char *)&local_644,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",
                     (uint)*(byte *)(iVar11 + 9),(uint)*(byte *)(iVar11 + 10),
                     (uint)*(byte *)(iVar11 + 0xb),(uint)*(byte *)(iVar11 + 0xc),
                     (uint)*(byte *)(iVar11 + 0xd),(uint)*(byte *)(iVar11 + 0xe));
            puVar12 = &local_644;
          }
          else {
            puVar12 = (undefined4 *)&DAT_00677878;
          }
          uVar8 = json_object_new_string(puVar12);
          json_object_object_add(uVar7,"bssid",uVar8);
          uVar8 = json_object_new_int(uVar3);
          json_object_object_add(uVar7,"radioIndex",uVar8);
          uVar8 = json_object_new_int(1);
          json_object_object_add(uVar7,"vapType",uVar8);
          uVar8 = json_object_new_string(auStack_118);
          json_object_object_add(uVar7,"ssidName",uVar8);
          if (local_11c - 1U < 2) {
            pcVar13 = (&PTR_s_unknown_0069b874)[local_11c];
          }
          else {
            pcVar13 = "unknown";
          }
          uVar8 = json_object_new_string(pcVar13);
          json_object_object_add(uVar7,"ssidCodeType",uVar8);
          iVar11 = (int)local_5a8;
          if (iVar11 == 0) {
            iVar11 = -0x50;
          }
          uVar8 = json_object_new_int(iVar11);
          json_object_object_add(uVar7,"weakSigThresh",uVar8);
          uVar8 = cloud_mngt_radio_type_get((int)local_5cb);
          uVar8 = json_object_new_string(uVar8);
          json_object_object_add(uVar7,"mode",uVar8);
          uVar5 = (uint)local_3a6;
          if (uVar5 != 2) {
            if (uVar5 < 8) {
              pcVar13 = (&PTR_DAT_0069b4b4)[uVar5];
            }
            else {
              pcVar13 = "---";
            }
            uVar8 = json_object_new_string(pcVar13);
            json_object_object_add(uVar7,&DAT_00698cb4,uVar8);
          }
          uVar8 = json_object_new_int((int)local_5aa);
          json_object_object_add(uVar7,&DAT_0069974c,uVar8);
          pcVar13 = local_248;
          if (local_248[0] == '\0') {
            pcVar13 = "";
          }
          uVar8 = json_object_new_string(pcVar13);
          json_object_object_add(uVar7,"ssidId",uVar8);
          json_object_array_add(local_38,uVar7);
        }
        local_34 = local_34 + 0x100;
      }
    }
    iVar11 = rdmngr_db_rd_entry_get(uVar3,auStack_5d4);
    if (iVar11 == 0) {
      if (local_5cc == '\0') {
        uVar7 = json_object_new_object();
        iVar11 = local_40 + 1;
        pcVar13 = "2g%d";
        local_40 = iVar11;
LAB_004950e0:
        local_660[8] = '\0';
        local_660[9] = '\0';
        local_660[4] = '\0';
        local_660[5] = '\0';
        local_660[6] = '\0';
        local_660[7] = '\0';
        local_660[0] = '\0';
        local_660[1] = '\0';
        local_660[2] = '\0';
        local_660[3] = '\0';
        snprintf(local_660,10,pcVar13,iVar11);
        uVar8 = json_object_new_string(local_660);
        json_object_object_add(uVar7,"radioName",uVar8);
        if (0 < local_598) {
          uVar8 = json_object_new_int();
          json_object_object_add(uVar7,"channel",uVar8);
        }
        uVar3 = json_object_new_int(uVar3);
        json_object_object_add(uVar7,"radioIndex",uVar3);
        uVar3 = json_object_new_int(uVar4);
        json_object_object_add(uVar7,"radioId",uVar3);
        if (iVar15 == 0) {
          iVar15 = json_object_new_array();
        }
        json_object_array_add(iVar15,uVar7);
        uVar4 = uVar4 + 1;
      }
      else {
        if (local_5cc == '\x01') {
          uVar7 = json_object_new_object();
          iVar11 = local_3c + 1;
          pcVar13 = "5g%d";
          local_3c = iVar11;
          goto LAB_004950e0;
        }
        uVar4 = uVar4 + 1;
      }
    }
    else {
      uVar4 = uVar4 + 1;
    }
  }
  if (local_250 != 0) {
    FUN_00407df0();
  }
  if (iVar15 != 0) {
    json_object_object_add(iVar2,"radioStats",iVar15);
  }
  if (local_38 != 0) {
    json_object_object_add(iVar2,"vapStats",local_38);
  }
  uVar3 = json_object_new_string(param_1 + 0x1c5);
  json_object_object_add(iVar2,"configId",uVar3);
  iVar11 = param_2[0xc];
  pcVar13 = (char *)json_object_to_json_string_ext(iVar2,0);
  sVar9 = strlen(pcVar13);
  if ((int)(~sVar9 + iVar11) < 0) {
    if (param_2[1] == 0) {
      iVar11 = param_2[1];
      goto LAB_0049556c;
    }
    json_object_object_add(*param_2,param_2[5]);
    param_2[1] = 0;
    param_2[3] = 0;
    if ((ap_report_switch != 0) &&
       (iVar11 = cloud_mngt_obj_send_to_cloud(param_2[6],*param_2), iVar11 == 0)) {
      json_object_object_del(*param_2,param_2[5]);
      iVar11 = param_2[1];
      goto LAB_0049556c;
    }
LAB_004956b0:
    uVar3 = 2;
    if (iVar2 != 0) {
      json_object_put(iVar2);
    }
  }
  else {
    iVar11 = param_2[1];
LAB_0049556c:
    if (iVar11 == 0) {
      iVar11 = json_object_new_array();
      param_2[1] = iVar11;
      if (iVar11 == 0) goto LAB_004956b0;
      param_2[0xc] = 0x3f800;
      pcVar13 = (char *)json_object_to_json_string_ext(*param_2,0);
      sVar9 = strlen(pcVar13);
      param_2[0xc] = 0x3f801 - sVar9;
    }
    param_2[3] = param_2[3] + 1;
    json_object_array_add(param_2[1],iVar2);
    iVar11 = param_2[0xc];
    pcVar13 = (char *)json_object_to_json_string_ext(iVar2,0);
    sVar9 = strlen(pcVar13);
    param_2[0xc] = (iVar11 + 1) - sVar9;
    uVar3 = 0;
  }
  return uVar3;
}

