// func cloud_mngt_ap_object_add @ 0048d04c size=1452

undefined4 cloud_mngt_ap_object_add(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char local_388 [12];
  undefined1 auStack_37c [36];
  undefined1 auStack_358 [8];
  char local_350;
  undefined1 auStack_300 [536];
  undefined1 auStack_e8 [60];
  int local_ac;
  int local_a8;
  undefined4 local_34;
  
  memset(auStack_358,0,0x54);
  local_388[0] = '\0';
  local_388[1] = '\0';
  local_388[2] = '\0';
  local_388[3] = '\0';
  local_388[4] = '\0';
  local_388[5] = '\0';
  local_388[6] = '\0';
  local_388[7] = '\0';
  local_388[8] = '\0';
  local_388[9] = '\0';
  memset(auStack_300,0,0x2d8);
  memset(auStack_37c,0,0x21);
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  iVar1 = json_object_new_object();
  if (param_3 != 0) {
    iVar3 = apmngr_db_entry_get_by_id(**(undefined2 **)(param_2 + 0x1c),auStack_300);
    if (iVar3 == -1) {
      if (cloud_mngt_err_switch != '\0') {
        printf("[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n","cloud_mngt_ap_object_add",
               0x6ec);
      }
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      json_object_put(iVar1);
      return 0xffffffff;
    }
    uVar2 = json_object_new_string(param_2 + 4);
    json_object_object_add(iVar1,"deviceMac",uVar2);
    uVar2 = json_object_new_string(*(int *)(param_2 + 0x1c) + 8);
    json_object_object_add(iVar1,"deviceName",uVar2);
    uVar2 = json_object_new_int(**(undefined2 **)(param_2 + 0x1c));
    json_object_object_add(iVar1,&DAT_006983bc,uVar2);
    uVar2 = json_object_new_string(*(int *)(param_2 + 0x1c) + 0xa4);
    json_object_object_add(iVar1,&DAT_00677c24,uVar2);
    uVar2 = json_object_new_string(*(int *)(param_2 + 0x1c) + 0xcc);
    json_object_object_add(iVar1,"model",uVar2);
    iVar3 = *(int *)(param_2 + 0x1c);
    if (*(char *)(iVar3 + 0x10d) == '\0') {
      if (*(int *)(iVar3 + 0x174) == 1) {
        pcVar6 = "WIRELESSROUTER";
      }
      else {
        if (*(int *)(iVar3 + 0x174) != 3) {
          iVar3 = *(int *)(param_2 + 0x1c);
          goto LAB_0048d254;
        }
        pcVar6 = "SMBWIRELESSROUTER";
      }
    }
    else {
      pcVar6 = (char *)(iVar3 + 0x10d);
    }
    uVar2 = json_object_new_string(pcVar6);
    json_object_object_add(iVar1,"deviceType",uVar2);
    iVar3 = *(int *)(param_2 + 0x1c);
LAB_0048d254:
    uVar7 = *(undefined4 *)(iVar3 + 0x178);
    _cloud_mngt_mesh_info_add
              (iVar1,*(undefined4 *)(iVar3 + 4),*(undefined2 *)(iVar3 + 2),
               *(undefined4 *)(iVar3 + 0x174));
    uVar2 = json_object_new_int64(0,uVar7);
    json_object_object_add(iVar1,"deviceModelId",uVar2);
    uVar2 = json_object_new_string(*(int *)(param_2 + 0x1c) + 0x12e);
    json_object_object_add(iVar1,"hardwareVersion",uVar2);
    uVar2 = json_object_new_string(*(int *)(param_2 + 0x1c) + 0x13e);
    json_object_object_add(iVar1,"softwareVersion",uVar2);
    FUN_004084f0(auStack_e8,0x10,auStack_37c);
    uVar2 = json_object_new_string(auStack_37c);
    json_object_object_add(iVar1,"firmwareId",uVar2);
    uVar2 = json_object_new_int(*(undefined4 *)(*(int *)(param_2 + 0x1c) + 0x17c));
    json_object_object_add(iVar1,"status",uVar2);
    if (*(int *)(*(int *)(param_2 + 0x1c) + 0x180) == 0) {
      pcVar6 = "Led off";
    }
    else {
      pcVar6 = "Led on";
    }
    uVar2 = json_object_new_string(pcVar6 + 4);
    json_object_object_add(iVar1,"led",uVar2);
    uVar2 = json_object_new_boolean(cloud_config_switch);
    json_object_object_add(iVar1,"syncConfig",uVar2);
    uVar2 = json_object_new_string(&DAT_00688af8);
    json_object_object_add(iVar1,"configId",uVar2);
    if ((local_a8 << 0xc < 0) && (iVar3 = json_object_new_object(), iVar3 != 0)) {
      uVar2 = json_object_new_int(local_34);
      json_object_object_add(iVar3,"features",uVar2);
      json_object_object_add(iVar1,"extendedInfo",iVar3);
    }
    iVar3 = apdb_radio_count_by_id(uVar7,auStack_e8);
    iVar9 = 0;
    if (0 < iVar3) {
      iVar9 = json_object_new_array();
    }
    iVar8 = 1;
    iVar10 = 0;
    iVar11 = 0;
LAB_0048d3cc:
    do {
      if (iVar3 < iVar8) goto LAB_0048d518;
      uVar2 = rdmngr_db_generate_rd_id(**(undefined2 **)(param_2 + 0x1c),iVar8);
      iVar4 = rdmngr_db_rd_entry_get(uVar2,auStack_358);
      if (iVar4 == 0) {
        if (local_350 == '\0') {
          iVar4 = iVar11 + 1;
          uVar7 = json_object_new_object();
          pcVar6 = "2g%d";
          iVar11 = iVar4;
        }
        else {
          if (local_350 != '\x01') {
            iVar8 = iVar8 + 1;
            goto LAB_0048d3cc;
          }
          iVar4 = iVar10 + 1;
          uVar7 = json_object_new_object();
          pcVar6 = "5g%d";
          iVar10 = iVar4;
        }
        snprintf(local_388,10,pcVar6,iVar4);
        uVar5 = json_object_new_string(local_388);
        json_object_object_add(uVar7,"radioName",uVar5);
      }
      else {
        uVar7 = 0;
      }
      uVar2 = json_object_new_int(uVar2);
      json_object_object_add(uVar7,"radioIndex",uVar2);
      uVar2 = json_object_new_int(iVar8);
      json_object_object_add(uVar7,"radioId",uVar2);
      json_object_array_add(iVar9,uVar7);
      iVar8 = iVar8 + 1;
    } while( true );
  }
  uVar2 = json_object_new_string(param_2 + 4);
  pcVar6 = "deviceMac";
LAB_0048d100:
  json_object_object_add(iVar1,pcVar6,uVar2);
LAB_0048d10c:
  json_object_array_add(param_1,iVar1);
  return 0;
LAB_0048d518:
  if (iVar9 != 0) {
    json_object_object_add(iVar1,"radioStats",iVar9);
  }
  if (-1 < local_ac << 0xe) goto LAB_0048d10c;
  uVar2 = json_object_new_object();
  uVar7 = json_object_new_string("0");
  json_object_object_add(uVar2,"stats_report",uVar7);
  uVar7 = json_object_new_string("0");
  json_object_object_add(uVar2,"event_report",uVar7);
  pcVar6 = "moduleConfigSyncId";
  goto LAB_0048d100;
}

