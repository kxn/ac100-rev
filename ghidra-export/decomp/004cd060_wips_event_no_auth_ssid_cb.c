// func wips_event_no_auth_ssid_cb @ 004cd060 size=1312

undefined4 wips_event_no_auth_ssid_cb(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  char acStack_e0 [16];
  undefined1 local_d0;
  char local_cc [24];
  undefined1 local_b4;
  char local_b0 [24];
  undefined1 local_98;
  char acStack_94 [49];
  undefined1 local_63;
  undefined1 auStack_60 [12];
  char acStack_54 [20];
  long local_40;
  long local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  
  uVar4 = *(undefined4 *)(param_1 + 0xc);
  memset(acStack_94,0,0x32);
  memset(auStack_60,0,0x3c);
  local_b0[0] = '0';
  local_b0[1] = '\0';
  memset(local_b0 + 2,0,0x17);
  local_cc[0] = '0';
  local_cc[1] = '\0';
  memset(local_cc + 2,0,0x17);
  iVar1 = json_object_object_get(uVar4,"ssid");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "wips_event_no_auth_ssid_cb",0x9b2);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  uVar7 = 1;
  strncpy(acStack_94,pcVar3,0x31);
  local_63 = 0;
  iVar1 = FUN_00407e60(acStack_94);
  if (iVar1 == 0) {
    uVar7 = 2;
    FUN_00408710(acStack_94,0x32);
  }
  iVar1 = json_object_object_get(uVar4,"signature");
  if (iVar1 == 0) {
LAB_004cd184:
    pcVar3 = "";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_event_no_auth_ssid_cb",0x9c1);
      }
      goto LAB_004cd184;
    }
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_e0,pcVar3,0x10);
  local_d0 = 0;
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
               "wips_event_no_auth_ssid_cb",0x9c4);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_b0,pcVar3,0x18);
  local_98 = 0;
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
               "wips_event_no_auth_ssid_cb",0x9c7);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_cc,pcVar3,0x18);
  local_b4 = 0;
  iVar1 = json_object_object_get(uVar4,"lastRssi");
  if (iVar1 == 0) {
LAB_004cd280:
    uVar6 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_no_auth_ssid_cb",0x9ca);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar6 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004cd280;
      uVar8 = json_object_get_double(iVar1);
      uVar6 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  iVar1 = json_object_object_get(uVar4,"state");
  if (iVar1 == 0) {
LAB_004cd2d0:
    uVar5 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_no_auth_ssid_cb",0x9cd);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004cd2d0;
      uVar8 = json_object_get_double(iVar1);
      uVar5 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  iVar1 = json_object_object_get(uVar4,"lastCh");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
      goto LAB_004cd348;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar8 = json_object_get_double(iVar1);
      uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      goto LAB_004cd348;
    }
  }
  uVar4 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "wips_event_no_auth_ssid_cb",0x9d0);
  }
LAB_004cd348:
  strcpy(acStack_54,acStack_e0);
  local_38 = 0x13157f9;
  local_40 = atol(local_b0);
  local_3c = atol(local_cc);
  local_28 = *param_1;
  local_34 = uVar5;
  local_30 = uVar6;
  local_2c = uVar4;
  wips_entry_add(&DAT_006a81e4,acStack_94,uVar7,auStack_60,acStack_94);
  return 0;
}

