// func wips_event_client_threat @ 004cdfc0 size=1536

undefined4 wips_event_client_threat(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 local_f8;
  undefined2 local_f4;
  char acStack_f0 [16];
  undefined1 local_e0;
  char local_dc [16];
  ushort local_cc;
  char local_c8 [24];
  undefined1 local_b0;
  char local_ac [24];
  undefined1 local_94;
  char acStack_90 [49];
  undefined1 local_5f;
  undefined1 auStack_5c [12];
  char acStack_50 [20];
  long local_3c;
  long local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined2 local_24;
  
  local_dc[0] = '\0';
  local_dc[1] = '\0';
  local_dc[2] = '\0';
  local_dc[3] = '\0';
  local_dc[4] = '\0';
  local_dc[5] = '\0';
  local_dc[6] = '\0';
  local_dc[7] = '\0';
  local_dc[8] = '\0';
  local_dc[9] = '\0';
  local_dc[10] = '\0';
  local_dc[0xb] = '\0';
  local_dc[0xc] = '\0';
  local_dc[0xd] = '\0';
  local_dc[0xe] = '\0';
  local_dc[0xf] = '\0';
  local_cc = 0;
  local_f8 = 0;
  local_f4 = 0;
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  memset(auStack_5c,0,0x3c);
  local_ac[0] = '0';
  local_ac[1] = '\0';
  memset(local_ac + 2,0,0x17);
  local_c8[0] = '0';
  local_c8[1] = '\0';
  memset(local_c8 + 2,0,0x17);
  memset(acStack_90,0,0x32);
  iVar1 = json_object_object_get(uVar5,"attackerMac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "wips_event_client_threat",0xa5f);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_dc,pcVar3,0x11);
  local_cc = local_cc & 0xff00;
  wips_str2mac(local_dc,&local_f8);
  iVar1 = json_object_object_get(uVar5,"ssid");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    uVar7 = 0;
    strcpy(acStack_90,"");
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_event_client_threat",0xa65);
      }
      pcVar3 = "";
    }
    uVar7 = 1;
    strncpy(acStack_90,pcVar3,0x31);
    local_5f = 0;
    iVar1 = FUN_00407e60(acStack_90);
    if (iVar1 == 0) {
      uVar7 = 2;
      FUN_00408710(acStack_90,0x32);
    }
  }
  iVar1 = json_object_object_get(uVar5,"signature");
  if (iVar1 == 0) {
LAB_004ce148:
    pcVar3 = "";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_event_client_threat",0xa7a);
      }
      goto LAB_004ce148;
    }
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_f0,pcVar3,0x10);
  local_e0 = 0;
  iVar1 = json_object_object_get(uVar5,"startTime");
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
               "wips_event_client_threat",0xa7d);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_ac,pcVar3,0x18);
  local_94 = 0;
  iVar1 = json_object_object_get(uVar5,"lastTime");
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
               "wips_event_client_threat",0xa80);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_c8,pcVar3,0x18);
  local_b0 = 0;
  iVar1 = json_object_object_get(uVar5,"lastRssi");
  if (iVar1 == 0) {
LAB_004ce244:
    uVar6 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_client_threat",0xa83);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar6 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004ce244;
      uVar8 = json_object_get_double(iVar1);
      uVar6 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  iVar1 = json_object_object_get(uVar5,"state");
  if (iVar1 == 0) {
LAB_004ce294:
    uVar4 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_client_threat",0xa86);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004ce294;
      uVar8 = json_object_get_double(iVar1);
      uVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  iVar1 = json_object_object_get(uVar5,"lastCh");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
      goto LAB_004ce30c;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar8 = json_object_get_double(iVar1);
      uVar5 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      goto LAB_004ce30c;
    }
  }
  uVar5 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "wips_event_client_threat",0xa89);
  }
LAB_004ce30c:
  strcpy(acStack_50,acStack_f0);
  local_34 = param_2;
  local_3c = atol(local_ac);
  local_38 = atol(local_c8);
  local_24 = *param_1;
  local_30 = uVar4;
  local_2c = uVar6;
  local_28 = uVar5;
  wips_entry_add(&local_f8,acStack_90,uVar7,auStack_5c,local_dc);
  return 0;
}

