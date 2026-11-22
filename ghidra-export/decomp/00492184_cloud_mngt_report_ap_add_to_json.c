// func cloud_mngt_report_ap_add_to_json @ 00492184 size=2492

undefined4 cloud_mngt_report_ap_add_to_json(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  short *psVar6;
  void *__s;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
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
  undefined1 auStack_19c [128];
  int local_11c;
  char local_104 [66];
  char acStack_c2 [65];
  char local_81 [69];
  int local_3c;
  int local_38;
  int local_30;
  undefined4 local_2c;
  
  local_284 = 0;
  local_280 = 0;
  local_27c = 0;
  local_278 = 0;
  local_274 = 0;
  memset(acStack_24c,0,0x28);
  memset(auStack_19c,0,0x168);
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
  iVar1 = json_object_new_object();
  snprintf((char *)&local_284,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x48),
           (uint)*(byte *)(param_1 + 0x49),(uint)*(byte *)(param_1 + 0x4a),
           (uint)*(byte *)(param_1 + 0x4b),(uint)*(byte *)(param_1 + 0x4c),
           (uint)*(byte *)(param_1 + 0x4d));
  uVar2 = json_object_new_string(&local_284);
  json_object_object_add(iVar1,"deviceMac",uVar2);
  uVar2 = json_object_new_string(param_1 + 0x4e);
  json_object_object_add(iVar1,"deviceName",uVar2);
  uVar2 = json_object_new_int(*(undefined2 *)(param_1 + 0x10));
  json_object_object_add(iVar1,&DAT_006983bc,uVar2);
  FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
               *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
               *(undefined4 *)(param_1 + 0x27c),acStack_24c,0x28,"0.0.0.0");
  pcVar8 = acStack_24c;
  if (*(int *)(param_1 + 0x2ac) == 0) {
    pcVar8 = "0.0.0.0";
  }
  uVar2 = json_object_new_string(pcVar8);
  json_object_object_add(iVar1,&DAT_00677c24,uVar2);
  iVar7 = 1;
  if (*(int *)(param_1 + 0x2ac) - 1U < 3) {
    iVar7 = (int)"cloud_mngt_apmngr_callback_wtp_join"[*(int *)(param_1 + 0x2ac) + 0x23];
  }
  iVar12 = param_1 + 0x218;
  uVar2 = json_object_new_int(iVar7);
  json_object_object_add(iVar1,"status",uVar2);
  apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),iVar12,auStack_19c);
  pcVar8 = local_81;
  if (local_81[0] == '\0') {
    pcVar8 = acStack_c2;
  }
  uVar2 = json_object_new_string(pcVar8);
  json_object_object_add(iVar1,"model",uVar2);
  pcVar8 = local_104;
  if (local_104[0] == '\0') {
    if (local_11c == 1) {
      pcVar8 = "WIRELESSROUTER";
      goto LAB_0049280c;
    }
    if (local_11c == 3) {
      pcVar8 = "SMBWIRELESSROUTER";
      goto LAB_0049280c;
    }
  }
  else {
LAB_0049280c:
    uVar2 = json_object_new_string(pcVar8);
    json_object_object_add(iVar1,"deviceType",uVar2);
  }
  _cloud_mngt_mesh_info_add
            (iVar1,*(undefined4 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 0x18),local_11c);
  uVar10 = *(undefined4 *)(param_1 + 0x40);
  uVar2 = json_object_new_int64(0,uVar10);
  json_object_object_add(iVar1,"deviceModelId",uVar2);
  uVar9 = (uint)*(ushort *)(param_1 + 0x44);
  uVar3 = (uint)*(ushort *)(param_1 + 0x46);
  if (uVar9 + uVar3 == 0) {
    psVar6 = (short *)(local_38 + (local_3c + -1) * 0x38);
    uVar9 = (uint)*psVar6;
    uVar3 = (uint)psVar6[1];
  }
  snprintf(local_294,0x10,"%d.%d",uVar9,uVar3);
  if (*(int *)(param_1 + 0x2ac) != 0) {
    uVar3 = *(uint *)(param_1 + 0x210);
    snprintf(acStack_224,0x33,"%d.%d.%d Build %02d%02d%02d Rel.%05d",
             (uint)*(ushort *)(param_1 + 0x208),(uint)*(ushort *)(param_1 + 0x20a),
             (uint)*(ushort *)(param_1 + 0x20c),uVar3 >> 0x10,(uVar3 << 0x10) >> 0x18,uVar3 & 0xff,
             *(undefined4 *)(param_1 + 0x214));
  }
  uVar2 = json_object_new_string(local_294);
  json_object_object_add(iVar1,"hardwareVersion",uVar2);
  uVar2 = json_object_new_string(acStack_224);
  json_object_object_add(iVar1,"softwareVersion",uVar2);
  FUN_004084f0(iVar12,0x10,auStack_270);
  uVar2 = json_object_new_string(auStack_270);
  json_object_object_add(iVar1,"firmwareId",uVar2);
  uVar3 = *(uint *)(param_1 + 0x1b8);
  if ((1 < *(uint *)(param_1 + 0x2ac)) && (*(int *)(param_1 + 0x288) != 0)) {
    uVar3 = (uint)(*(int *)(param_1 + 0x288) == 1);
  }
  if (uVar3 == 0) {
    pcVar8 = "Led off";
  }
  else {
    pcVar8 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar8 + 4);
  json_object_object_add(iVar1,"led",uVar2);
  uVar2 = json_object_new_boolean(cloud_config_switch);
  json_object_object_add(iVar1,"syncConfig",uVar2);
  uVar2 = json_object_new_string(&DAT_00688af8);
  json_object_object_add(iVar1,"configId",uVar2);
  if ((*(int *)(param_1 + 600) << 0xc < 0) && (iVar7 = json_object_new_object(), iVar7 != 0)) {
    uVar2 = json_object_new_int(*(undefined4 *)(param_1 + 0x2cc));
    json_object_object_add(iVar7,"features",uVar2);
    json_object_object_add(iVar1,"extendedInfo",iVar7);
  }
  local_30 = apdb_radio_count_by_id(uVar10,iVar12);
  iVar7 = 0;
  if (0 < local_30) {
    iVar7 = json_object_new_array();
  }
  iVar11 = 1;
  iVar13 = 0;
  iVar14 = 0;
  while (iVar11 <= local_30) {
    local_2c = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar11);
    iVar4 = rdmngr_db_rd_entry_get(local_2c,auStack_1f0);
    if (iVar4 == 0) {
      if (local_1e8 == '\0') {
        iVar4 = iVar14 + 1;
        uVar2 = json_object_new_object();
        pcVar8 = "2g%d";
        iVar14 = iVar4;
LAB_0049262c:
        snprintf(local_2a0,10,pcVar8,iVar4);
        uVar10 = json_object_new_string(local_2a0);
        json_object_object_add(uVar2,"radioName",uVar10);
        uVar10 = json_object_new_int(iVar11);
        json_object_object_add(uVar2,"radioId",uVar10);
        uVar10 = json_object_new_int(local_2c);
        json_object_object_add(uVar2,"radioIndex",uVar10);
        json_object_array_add(iVar7,uVar2);
        iVar11 = iVar11 + 1;
      }
      else {
        if (local_1e8 == '\x01') {
          iVar4 = iVar13 + 1;
          uVar2 = json_object_new_object();
          pcVar8 = "5g%d";
          iVar13 = iVar4;
          goto LAB_0049262c;
        }
        iVar11 = iVar11 + 1;
      }
    }
    else if (cloud_mngt_err_switch == '\0') {
      iVar11 = iVar11 + 1;
    }
    else {
      printf("[CLOUD_MNGT_ERROR]%s()/%d rdmngr_db_rd_entry_get failed.\n",
             "cloud_mngt_report_ap_add_to_json",0x1086);
      iVar11 = iVar11 + 1;
    }
  }
  if (iVar7 != 0) {
    json_object_object_add(iVar1,"radioStats",iVar7);
  }
  if (*(int *)(param_1 + 0x254) << 0xe < 0) {
    uVar2 = json_object_new_object();
    uVar10 = json_object_new_string("0");
    json_object_object_add(uVar2,"stats_report",uVar10);
    uVar10 = json_object_new_string("0");
    json_object_object_add(uVar2,"event_report",uVar10);
    json_object_object_add(iVar1,"moduleConfigSyncId",uVar2);
    iVar7 = param_2[7];
  }
  else {
    iVar7 = param_2[7];
  }
  if (iVar7 == 0) {
    iVar13 = 0;
  }
  else {
    iVar13 = 0;
    iVar7 = FUN_00407fa0(iVar7,param_1 + 0x40);
    if (iVar7 == 0) {
      __s = (void *)FUN_00408450(0x10,0x10ae);
      if (__s == (void *)0x0) goto LAB_004928bc;
      memset(__s,0,0x10);
      *(undefined4 *)((int)__s + 0xc) = *(undefined4 *)(param_1 + 0x40);
      FUN_00408380(param_2[7],__s);
      FUN_004086b0(param_2 + 8,__s);
      iVar13 = cloud_mngt_get_ap_model_obj_by_id(*(undefined4 *)(param_1 + 0x40),iVar12);
    }
  }
  iVar7 = param_2[0xc];
  pcVar8 = (char *)json_object_to_json_string_ext(iVar1,0);
  sVar5 = strlen(pcVar8);
  iVar7 = (iVar7 + 1) - sVar5;
  if (iVar13 != 0) {
    pcVar8 = (char *)json_object_to_json_string_ext(iVar13,0);
    sVar5 = strlen(pcVar8);
    iVar7 = (iVar7 + 1) - sVar5;
  }
  if (iVar7 < 0) {
    iVar7 = param_2[1];
LAB_00492830:
    if (iVar7 == 0) {
      iVar7 = param_2[1];
      goto LAB_00492738;
    }
    if (param_2[2] != 0) {
      if (cloud_mngt_apdb_report_switch == '\0') {
        json_object_put(param_2[2]);
        param_2[2] = 0;
      }
      else {
        json_object_object_add(*param_2,&DAT_00699510);
        iVar7 = param_2[0xc];
        pcVar8 = (char *)json_object_to_json_string_ext(param_2[2],0);
        sVar5 = strlen(pcVar8);
        param_2[2] = 0;
        param_2[0xc] = (iVar7 + 1) - sVar5;
      }
    }
    json_object_object_add(*param_2,param_2[5],param_2[1]);
    param_2[1] = 0;
    param_2[3] = 0;
    if (ap_report_switch != 0) {
      iVar7 = cloud_mngt_obj_send_to_cloud(param_2[6],*param_2);
      if (iVar7 == 0) {
        json_object_object_del(*param_2,param_2[5]);
        json_object_object_del(*param_2,&DAT_00699510);
        if (param_2[7] == 0) {
          iVar7 = param_2[1];
        }
        else {
          while (iVar7 = FUN_004081b0(param_2 + 8), iVar7 != 0) {
            FUN_00407f40(param_2[7],iVar7);
            FUN_00408500(iVar7);
            FUN_00407df0(iVar7);
          }
          iVar7 = param_2[1];
        }
        goto LAB_00492738;
      }
    }
  }
  else {
    iVar7 = param_2[1];
    if (param_2[3] == param_2[4]) goto LAB_00492830;
LAB_00492738:
    if (iVar7 != 0) {
LAB_00492740:
      param_2[3] = param_2[3] + 1;
      json_object_array_add(param_2[1],iVar1);
      iVar7 = param_2[0xc];
      pcVar8 = (char *)json_object_to_json_string_ext(iVar1,0);
      sVar5 = strlen(pcVar8);
      param_2[0xc] = (iVar7 + 1) - sVar5;
      if (iVar13 == 0) {
        return 0;
      }
      if (param_2[2] == 0) {
        iVar1 = json_object_new_array();
        param_2[2] = iVar1;
        if (iVar1 == 0) {
          json_object_put(iVar13);
          return 2;
        }
      }
      json_object_array_add(param_2[2],iVar13);
      iVar1 = param_2[0xc];
      pcVar8 = (char *)json_object_to_json_string_ext(iVar13,0);
      sVar5 = strlen(pcVar8);
      param_2[0xc] = (iVar1 + 1) - sVar5;
      return 0;
    }
    iVar7 = json_object_new_array();
    param_2[1] = iVar7;
    if (iVar7 != 0) {
      param_2[0xc] = 0x3f800;
      pcVar8 = (char *)json_object_to_json_string_ext(*param_2,0);
      sVar5 = strlen(pcVar8);
      param_2[0xc] = 0x3f801 - sVar5;
      goto LAB_00492740;
    }
  }
  if (iVar13 != 0) {
    json_object_put(iVar13);
  }
LAB_004928bc:
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  return 2;
}

