// func cloud_mngt_ap_add_to_json @ 00493f60 size=1996

undefined4 cloud_mngt_ap_add_to_json(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  size_t sVar8;
  short *psVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  char local_2a0 [12];
  char local_294 [16];
  undefined4 local_284;
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined2 local_274;
  undefined1 auStack_270 [36];
  char acStack_24c [40];
  char acStack_224 [52];
  undefined1 auStack_1f0 [8];
  char local_1e8;
  short local_1b4;
  undefined1 auStack_19c [128];
  int local_11c;
  char local_104 [200];
  int local_3c;
  int local_38;
  int local_30;
  
  local_284 = 0;
  local_280 = 0;
  local_27c = 0;
  local_278 = 0;
  local_274 = 0;
  memset(acStack_24c,0,0x28);
  local_294[0] = '\0';
  local_294[1] = '\0';
  local_294[2] = '\0';
  local_294[3] = '\0';
  local_294[4] = '\0';
  local_294[5] = '\0';
  local_294[6] = '\0';
  local_294[7] = '\0';
  local_294[8] = '\0';
  local_294[9] = '\0';
  local_294[10] = '\0';
  local_294[0xb] = '\0';
  local_294[0xc] = '\0';
  local_294[0xd] = '\0';
  local_294[0xe] = '\0';
  local_294[0xf] = '\0';
  memset(acStack_224,0,0x33);
  memset(auStack_270,0,0x21);
  memset(auStack_1f0,0,0x54);
  local_2a0[0] = '\0';
  local_2a0[1] = '\0';
  local_2a0[2] = '\0';
  local_2a0[3] = '\0';
  local_2a0[4] = '\0';
  local_2a0[5] = '\0';
  local_2a0[6] = '\0';
  local_2a0[7] = '\0';
  local_2a0[8] = '\0';
  local_2a0[9] = '\0';
  memset(auStack_19c,0,0x168);
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
  iVar2 = json_object_new_object();
  snprintf((char *)&local_284,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x48),
           (uint)*(byte *)(param_1 + 0x49),(uint)*(byte *)(param_1 + 0x4a),
           (uint)*(byte *)(param_1 + 0x4b),(uint)*(byte *)(param_1 + 0x4c),
           (uint)*(byte *)(param_1 + 0x4d));
  uVar3 = json_object_new_string(&local_284);
  json_object_object_add(iVar2,"deviceMac",uVar3);
  uVar3 = json_object_new_string(param_1 + 0x4e);
  json_object_object_add(iVar2,"deviceName",uVar3);
  uVar3 = json_object_new_int(*(undefined2 *)(param_1 + 0x10));
  json_object_object_add(iVar2,&DAT_006983bc,uVar3);
  uVar3 = json_object_new_int64(0,*(undefined4 *)(param_1 + 0x40));
  json_object_object_add(iVar2,"deviceModelId",uVar3);
  FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
               *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
               *(undefined4 *)(param_1 + 0x27c),acStack_24c,0x28,"0.0.0.0");
  pcVar11 = acStack_24c;
  if (*(int *)(param_1 + 0x2ac) == 0) {
    pcVar11 = "0.0.0.0";
  }
  uVar3 = json_object_new_string(pcVar11);
  json_object_object_add(iVar2,&DAT_00677c24,uVar3);
  iVar10 = 1;
  if (*(int *)(param_1 + 0x2ac) - 1U < 3) {
    iVar10 = (int)"cloud_mngt_apmngr_callback_wtp_join"[*(int *)(param_1 + 0x2ac) + 0x23];
  }
  iVar13 = param_1 + 0x218;
  uVar3 = json_object_new_int(iVar10);
  json_object_object_add(iVar2,"status",uVar3);
  apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),iVar13,auStack_19c);
  pcVar11 = local_104;
  if (local_104[0] == '\0') {
    if (local_11c == 1) {
      pcVar11 = "WIRELESSROUTER";
      goto LAB_004945dc;
    }
    if (local_11c == 3) {
      pcVar11 = "SMBWIRELESSROUTER";
      goto LAB_004945dc;
    }
    uVar1 = *(undefined2 *)(param_1 + 0x18);
  }
  else {
LAB_004945dc:
    uVar3 = json_object_new_string(pcVar11);
    json_object_object_add(iVar2,"deviceType",uVar3);
    uVar1 = *(undefined2 *)(param_1 + 0x18);
  }
  _cloud_mngt_mesh_info_add(iVar2,*(undefined4 *)(param_1 + 0x14),uVar1,local_11c);
  uVar12 = (uint)*(ushort *)(param_1 + 0x44);
  uVar4 = (uint)*(ushort *)(param_1 + 0x46);
  if (uVar12 + uVar4 == 0) {
    psVar9 = (short *)(local_38 + (local_3c + -1) * 0x38);
    uVar12 = (uint)*psVar9;
    uVar4 = (uint)psVar9[1];
  }
  snprintf(local_294,0x10,"%d.%d",uVar12,uVar4);
  uVar3 = json_object_new_string(local_294);
  json_object_object_add(iVar2,"hardwareVersion",uVar3);
  if (*(int *)(param_1 + 0x2ac) != 0) {
    uVar4 = *(uint *)(param_1 + 0x210);
    snprintf(acStack_224,0x33,"%d.%d.%d Build %02d%02d%02d Rel.%05d",
             (uint)*(ushort *)(param_1 + 0x208),(uint)*(ushort *)(param_1 + 0x20a),
             (uint)*(ushort *)(param_1 + 0x20c),uVar4 >> 0x10,(uVar4 << 0x10) >> 0x18,uVar4 & 0xff,
             *(undefined4 *)(param_1 + 0x214));
  }
  uVar3 = json_object_new_string(acStack_224);
  json_object_object_add(iVar2,"softwareVersion",uVar3);
  FUN_004084f0(iVar13,0x10,auStack_270);
  uVar3 = json_object_new_string(auStack_270);
  json_object_object_add(iVar2,"firmwareId",uVar3);
  uVar4 = *(uint *)(param_1 + 0x1b8);
  if ((1 < *(uint *)(param_1 + 0x2ac)) && (*(int *)(param_1 + 0x288) != 0)) {
    uVar4 = (uint)(*(int *)(param_1 + 0x288) == 1);
  }
  if (uVar4 == 0) {
    pcVar11 = "Led off";
  }
  else {
    pcVar11 = "Led on";
  }
  uVar3 = json_object_new_string(pcVar11 + 4);
  json_object_object_add(iVar2,"led",uVar3);
  uVar3 = 0;
  if (*(int *)(param_1 + 0x2ac) != 0) {
    uVar3 = wsta_db_get_ap_sta_num(*(undefined2 *)(param_1 + 0x10));
  }
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(iVar2,"clientNum",uVar3);
  if ((*(int *)(param_1 + 600) << 0xc < 0) && (iVar10 = json_object_new_object(), iVar10 != 0)) {
    uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x2cc));
    json_object_object_add(iVar10,"features",uVar3);
    json_object_object_add(iVar2,"extendedInfo",iVar10);
    uVar3 = *(undefined4 *)(param_1 + 0x40);
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x40);
  }
  iVar10 = 0;
  local_30 = apdb_radio_count_by_id(uVar3,iVar13);
  if (0 < local_30) {
    iVar10 = json_object_new_array();
  }
  iVar14 = 1;
  iVar13 = 0;
  iVar15 = 0;
  while (iVar14 <= local_30) {
    uVar3 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar14);
    iVar5 = rdmngr_db_rd_entry_get(uVar3,auStack_1f0);
    if (iVar5 == 0) {
      if (local_1e8 == '\0') {
        iVar5 = iVar15 + 1;
        uVar6 = json_object_new_object();
        pcVar11 = "2g%d";
        iVar15 = iVar5;
LAB_004943d8:
        snprintf(local_2a0,10,pcVar11,iVar5);
        uVar7 = json_object_new_string(local_2a0);
        json_object_object_add(uVar6,"radioName",uVar7);
        if (0 < local_1b4) {
          uVar7 = json_object_new_int();
          json_object_object_add(uVar6,"channel",uVar7);
        }
        uVar3 = json_object_new_int(uVar3);
        json_object_object_add(uVar6,"radioIndex",uVar3);
        uVar3 = json_object_new_int(iVar14);
        json_object_object_add(uVar6,"radioId",uVar3);
        json_object_array_add(iVar10,uVar6);
        iVar14 = iVar14 + 1;
      }
      else {
        if (local_1e8 == '\x01') {
          iVar5 = iVar13 + 1;
          uVar6 = json_object_new_object();
          pcVar11 = "5g%d";
          iVar13 = iVar5;
          goto LAB_004943d8;
        }
        iVar14 = iVar14 + 1;
      }
    }
    else {
      iVar14 = iVar14 + 1;
    }
  }
  if (iVar10 != 0) {
    json_object_object_add(iVar2,"radioStats",iVar10);
  }
  uVar3 = json_object_new_boolean(cloud_config_switch);
  json_object_object_add(iVar2,"syncConfig",uVar3);
  uVar3 = json_object_new_string(param_1 + 0x1c5);
  json_object_object_add(iVar2,"configId",uVar3);
  iVar10 = param_2[0xc];
  pcVar11 = (char *)json_object_to_json_string_ext(iVar2,0);
  sVar8 = strlen(pcVar11);
  if ((int)((iVar10 + 1) - sVar8) < 0) {
    iVar10 = param_2[1];
LAB_00494578:
    if (iVar10 == 0) {
      iVar10 = param_2[1];
      goto LAB_00494524;
    }
    json_object_object_add(*param_2,param_2[5]);
    param_2[1] = 0;
    param_2[3] = 0;
    if (ap_report_switch == 0) {
      uVar3 = *param_2;
    }
    else {
      iVar10 = cloud_mngt_obj_send_to_cloud(param_2[6],*param_2);
      uVar3 = *param_2;
      if (iVar10 == 0) {
        json_object_object_del(uVar3,param_2[5]);
        iVar10 = param_2[1];
        goto LAB_00494524;
      }
    }
    json_object_object_del(uVar3,param_2[5]);
LAB_004945c0:
    uVar3 = 2;
    if (iVar2 != 0) {
      json_object_put(iVar2);
    }
  }
  else {
    if (param_2[3] == param_2[4]) {
      iVar10 = param_2[1];
      goto LAB_00494578;
    }
    iVar10 = param_2[1];
LAB_00494524:
    if (iVar10 == 0) {
      iVar10 = json_object_new_array();
      param_2[1] = iVar10;
      if (iVar10 == 0) goto LAB_004945c0;
      param_2[0xc] = 0x3f800;
      pcVar11 = (char *)json_object_to_json_string_ext(*param_2,0);
      sVar8 = strlen(pcVar11);
      param_2[0xc] = 0x3f801 - sVar8;
    }
    uVar3 = 0;
    param_2[3] = param_2[3] + 1;
    json_object_array_add(param_2[1],iVar2);
    iVar10 = param_2[0xc];
    pcVar11 = (char *)json_object_to_json_string_ext(iVar2,0);
    sVar8 = strlen(pcVar11);
    param_2[0xc] = (iVar10 + 1) - sVar8;
  }
  return uVar3;
}

