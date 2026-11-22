// func wips_jcs_callback_whitelist_add @ 004cc14c size=736

void wips_jcs_callback_whitelist_add(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 local_168;
  undefined2 local_164;
  char local_160 [16];
  ushort local_150;
  char acStack_14c [49];
  undefined1 local_11b;
  char acStack_118 [256];
  
  local_160[0] = '\0';
  local_160[1] = '\0';
  local_160[2] = '\0';
  local_160[3] = '\0';
  local_160[4] = '\0';
  local_160[5] = '\0';
  local_160[6] = '\0';
  local_160[7] = '\0';
  local_160[8] = '\0';
  local_160[9] = '\0';
  local_160[10] = '\0';
  local_160[0xb] = '\0';
  local_160[0xc] = '\0';
  local_160[0xd] = '\0';
  local_160[0xe] = '\0';
  local_160[0xf] = '\0';
  local_150 = 0;
  local_168 = 0;
  local_164 = 0;
  memset(acStack_14c,0,0x32);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d inputs error.\n","wips_jcs_callback_whitelist_add",0x7d2);
    }
    memset(acStack_118,0,0x100);
    uVar4 = 0xffffffff;
    goto LAB_004cc2f4;
  }
  iVar1 = json_object_object_get(param_1,"mac");
  if (iVar1 == 0) {
LAB_004cc1f4:
    pcVar3 = "";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_jcs_callback_whitelist_add",0x7d7);
      }
      goto LAB_004cc1f4;
    }
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_160,pcVar3,0x11);
  local_150 = local_150 & 0xff00;
  wips_str2mac(local_160,&local_168);
  iVar1 = json_object_object_get(param_1,"ssid");
  if (iVar1 == 0) {
LAB_004cc254:
    pcVar3 = "";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "wips_jcs_callback_whitelist_add",0x7db);
      }
      goto LAB_004cc254;
    }
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_14c,pcVar3,0x31);
  local_11b = 0;
  uVar4 = 0;
  iVar1 = json_object_object_get(param_1,"ssid_encode");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar5 = json_object_get_double(iVar1);
        uVar4 = __fixunsdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      }
      else {
        uVar4 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "wips_jcs_callback_whitelist_add",0x7dd);
        }
      }
    }
  }
  uVar4 = whitelist_entry_add(&local_168,acStack_14c,uVar4,0);
  memset(acStack_118,0,0x100);
LAB_004cc2f4:
  snprintf(acStack_118,0x100,"%d",uVar4);
  uVar4 = json_object_new_string(acStack_118);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  return;
}

