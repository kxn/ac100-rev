// func wips_event_dev_threat @ 004cd580 size=1296

undefined4 wips_event_dev_threat(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 local_c8;
  undefined2 local_c4;
  char acStack_c0 [16];
  undefined1 local_b0;
  char local_ac [16];
  ushort local_9c;
  char local_98 [24];
  undefined1 local_80;
  char local_7c [24];
  undefined1 local_64;
  undefined1 auStack_60 [12];
  char acStack_54 [20];
  long local_40;
  long local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  
  local_ac[0] = '\0';
  local_ac[1] = '\0';
  local_ac[2] = '\0';
  local_ac[3] = '\0';
  local_ac[4] = '\0';
  local_ac[5] = '\0';
  local_ac[6] = '\0';
  local_ac[7] = '\0';
  local_ac[8] = '\0';
  local_ac[9] = '\0';
  local_ac[10] = '\0';
  local_ac[0xb] = '\0';
  local_ac[0xc] = '\0';
  local_ac[0xd] = '\0';
  local_ac[0xe] = '\0';
  local_ac[0xf] = '\0';
  local_9c = 0;
  local_c8 = 0;
  local_c4 = 0;
  uVar4 = *(undefined4 *)(param_1 + 0xc);
  memset(auStack_60,0,0x3c);
  local_7c[0] = '0';
  local_7c[1] = '\0';
  memset(local_7c + 2,0,0x17);
  local_98[0] = '0';
  local_98[1] = '\0';
  memset(local_98 + 2,0,0x17);
  iVar1 = json_object_object_get(uVar4,"targetMac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "wips_event_dev_threat",0x9f1);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_ac,pcVar3,0x11);
  local_9c = local_9c & 0xff00;
  wips_str2mac(local_ac,&local_c8);
  iVar1 = json_object_object_get(uVar4,"signature");
  if (iVar1 == 0) {
LAB_004cd6ac:
    pcVar3 = "";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_event_dev_threat",0x9f6);
      }
      goto LAB_004cd6ac;
    }
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_c0,pcVar3,0x10);
  local_b0 = 0;
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
               "wips_event_dev_threat",0x9f9);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_7c,pcVar3,0x18);
  local_64 = 0;
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
               "wips_event_dev_threat",0x9fc);
      }
      pcVar3 = "";
    }
  }
  strncpy(local_98,pcVar3,0x18);
  local_80 = 0;
  iVar1 = json_object_object_get(uVar4,"lastRssi");
  if (iVar1 == 0) {
LAB_004cd7a8:
    uVar6 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_dev_threat",0x9ff);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar6 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004cd7a8;
      uVar7 = json_object_get_double(iVar1);
      uVar6 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(uVar4,"state");
  if (iVar1 == 0) {
LAB_004cd7f8:
    uVar5 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "wips_event_dev_threat",0xa02);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004cd7f8;
      uVar7 = json_object_get_double(iVar1);
      uVar5 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(uVar4,"lastCh");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
      goto LAB_004cd870;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar7 = json_object_get_double(iVar1);
      uVar4 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
      goto LAB_004cd870;
    }
  }
  uVar4 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "wips_event_dev_threat",0xa05);
  }
LAB_004cd870:
  strcpy(acStack_54,acStack_c0);
  local_38 = param_2;
  local_40 = atol(local_7c);
  local_3c = atol(local_98);
  local_28 = *param_1;
  local_34 = uVar5;
  local_30 = uVar6;
  local_2c = uVar4;
  wips_entry_add(&local_c8,&DAT_00688af8,0,auStack_60,local_ac);
  return 0;
}

