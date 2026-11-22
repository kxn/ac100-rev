// func _apdb_parse_radio @ 005fc774 size=1324

undefined4 _apdb_parse_radio(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  void *__s;
  char *pcVar4;
  undefined *puVar5;
  
  if (param_1 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : input json data null.\n";
    uVar2 = 0x555;
LAB_005fc920:
    printf(pcVar4,"_apdb_parse_radio",uVar2);
    return 0xffffffff;
  }
  iVar1 = cJSON_GetObjectItem(param_1,"support_11ac");
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 1)) {
    param_2[1] = 1;
  }
  iVar1 = cJSON_GetObjectItem(param_1,"support_11ax");
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 1)) {
    param_2[2] = 1;
  }
  iVar1 = cJSON_GetObjectItem(param_1,"support_11be");
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 1)) {
    param_2[5] = 1;
  }
  iVar1 = cJSON_GetObjectItem(param_1,"support_240M");
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 1)) {
    param_2[6] = 1;
  }
  iVar1 = cJSON_GetObjectItem(param_1,"support_160M");
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 1)) {
    param_2[3] = 1;
  }
  iVar1 = cJSON_GetObjectItem(param_1,"support_80M_80M");
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 1)) {
    param_2[4] = 1;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"max_ssid");
  iVar1 = FUN_00408330(uVar2,param_2 + 7);
  if (iVar1 != 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed to get max_ssid from json.\n";
    uVar2 = 0x580;
    goto LAB_005fc920;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"max_stations");
  iVar1 = FUN_00408330(uVar2,(int)param_2 + 0x1e);
  if (iVar1 != 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed to get max_stations from json.\n";
    uVar2 = 0x587;
    goto LAB_005fc920;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"max_tx_power");
  iVar1 = FUN_00408330(uVar2,param_2 + 8);
  if (iVar1 != 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed to get max_tx_power from json.\n";
    uVar2 = 0x58e;
    goto LAB_005fc920;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"min_tx_power");
  iVar1 = FUN_00408330(uVar2,(int)param_2 + 0x22);
  if (iVar1 != 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed to get min_tx_power from json.\n";
    uVar2 = 0x595;
    goto LAB_005fc920;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"dft_tx_power");
  iVar1 = FUN_00408330(uVar2,param_2 + 9);
  if (iVar1 != 0) {
    *(undefined2 *)(param_2 + 9) = 0;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"real_max_tx_power");
  iVar1 = FUN_00408330(uVar2,(int)param_2 + 0x26);
  if (iVar1 != 0) {
    *(undefined2 *)((int)param_2 + 0x26) = 0;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"real_min_tx_power");
  iVar1 = FUN_00408330(uVar2,param_2 + 10);
  if (iVar1 != 0) {
    *(undefined2 *)(param_2 + 10) = 0;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"real_dft_tx_power");
  iVar1 = FUN_00408330(uVar2,(int)param_2 + 0x2a);
  if (iVar1 != 0) {
    *(undefined2 *)((int)param_2 + 0x2a) = 0;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"dft_bw_mode");
  iVar1 = FUN_00407e10(uVar2,param_2 + 0xc);
  if (iVar1 != 0) {
    param_2[0xc] = -1;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"max_tx_stream");
  iVar1 = FUN_00674968(uVar2,param_2 + 0xb);
  if (iVar1 != 0) {
    *(undefined1 *)(param_2 + 0xb) = 0;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"max_rx_stream");
  iVar1 = FUN_00674968(uVar2,(int)param_2 + 0x2d);
  if (iVar1 != 0) {
    *(undefined1 *)((int)param_2 + 0x2d) = 0;
  }
  iVar1 = cJSON_GetObjectItem(param_1,"support_WPA3");
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 1)) {
    param_2[0xd] = 1;
  }
  uVar2 = cJSON_GetObjectItem(param_1,"mutex_channel");
  iVar1 = FUN_00407ef0(uVar2,param_2 + 0xe,99);
  if (iVar1 == 0) {
    *(undefined1 *)((int)param_2 + 0x9b) = 0;
  }
  else {
    memset(param_2 + 0xe,0,100);
  }
  iVar1 = cJSON_GetObjectItem(param_1,"extend_capability");
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 4)) {
    memset(param_2 + 0x40,0,0x10);
    iVar1 = *param_2;
  }
  else {
    pcVar4 = *(char **)(iVar1 + 0x10);
    sVar3 = strlen(pcVar4);
    _apdb_extend_str_transfer_to_cap(pcVar4,sVar3,param_2 + 0x40,0x10);
    iVar1 = *param_2;
  }
  if (iVar1 == 0) {
    puVar5 = &DAT_006fcd40;
  }
  else {
    if (iVar1 != 1) {
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar4 = "[APDB_ERROR]%s()/line %d : Illegal freq type %d.\n";
      uVar2 = 0x5e7;
      goto LAB_005fcb9c;
    }
    puVar5 = &DAT_00693fd4;
  }
  iVar1 = cJSON_GetObjectItem(param_1,puVar5);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(iVar1 + 0xc) == 6) {
    __s = (void *)FUN_00408450(0x114,0x5f1);
    param_2[0x44] = (int)__s;
    if (__s == (void *)0x0) {
      return 0xffffffff;
    }
    memset(__s,0,0x114);
    *(uint *)param_2[0x44] = (uint)(*param_2 == 0);
    iVar1 = _apdb_parse_radio(iVar1,param_2[0x44]);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_00407df0(param_2[0x44]);
    param_2[0x44] = 0;
    return 0xffffffff;
  }
  if (apdb_err_switch == 0) {
    return 0xffffffff;
  }
  pcVar4 = "[APDB_ERROR]%s()/line %d : Illegal json type %d for radio object.\n";
  uVar2 = 0x5ee;
LAB_005fcb9c:
  printf(pcVar4,"_apdb_parse_radio",uVar2);
  return 0xffffffff;
}

