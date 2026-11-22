// func wips_event_env_threat @ 004cdacc size=1232

undefined4 wips_event_env_threat(ushort *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  char acStack_380 [16];
  undefined1 local_370;
  char local_36c [24];
  undefined1 local_354;
  char local_350 [24];
  undefined1 local_338;
  undefined1 auStack_334 [12];
  char acStack_328 [20];
  long local_314;
  long local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  ushort local_2fc;
  undefined1 auStack_2f8 [72];
  undefined1 auStack_2b0 [6];
  undefined1 auStack_2aa [654];
  
  uVar4 = *(undefined4 *)(param_1 + 0xc);
  local_350[0] = '0';
  local_350[1] = '\0';
  memset(local_350 + 2,0,0x17);
  local_36c[0] = '0';
  local_36c[1] = '\0';
  memset(local_36c + 2,0,0x17);
  memset(auStack_334,0,0x3c);
  memset(auStack_2f8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(*param_1,auStack_2f8);
  if (iVar1 != 0) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d ap[id=%d] not found\n","wips_event_env_threat",0xa27,
           (uint)*param_1);
    return 0xffffffff;
  }
  iVar1 = json_object_object_get(uVar4,"signature");
  if (iVar1 == 0) {
LAB_004cdbd8:
    pcVar3 = "";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_event_env_threat",0xa2d);
      }
      goto LAB_004cdbd8;
    }
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_380,pcVar3,0x10);
  local_370 = 0;
  iVar1 = json_object_object_get(uVar4,"startTime");
  if (iVar1 == 0) {
    pcVar3 = "0";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_event_env_threat",0xa30);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_350,pcVar3,0x18);
  local_338 = 0;
  iVar1 = json_object_object_get(uVar4,"lastTime");
  if (iVar1 == 0) {
    pcVar3 = "0";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_event_env_threat",0xa33);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_36c,pcVar3,0x18);
  local_354 = 0;
  iVar1 = json_object_object_get(uVar4,"lastRssi");
  if (iVar1 == 0) {
LAB_004cdcd4:
    uVar6 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_env_threat",0xa36);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar6 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004cdcd4;
      uVar7 = json_object_get_double(iVar1);
      uVar6 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(uVar4,"state");
  if (iVar1 == 0) {
LAB_004cdd24:
    uVar5 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_env_threat",0xa39);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004cdd24;
      uVar7 = json_object_get_double(iVar1);
      uVar5 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(uVar4,"lastCh");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
      goto LAB_004cdd88;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar7 = json_object_get_double(iVar1);
      uVar4 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
      goto LAB_004cdd88;
    }
  }
  uVar4 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "wips_event_env_threat",0xa3c);
  }
LAB_004cdd88:
  strcpy(acStack_328,acStack_380);
  local_30c = param_2;
  local_314 = atol(local_350);
  local_310 = atol(local_36c);
  local_2fc = *param_1;
  local_308 = uVar5;
  local_304 = uVar6;
  local_300 = uVar4;
  wips_entry_add(auStack_2b0,&DAT_00688af8,0,auStack_334,auStack_2aa);
  return 0;
}

