// func _wportal_authed_user_add @ 0041ba28 size=7128

int _wportal_authed_user_add(undefined4 param_1,int param_2)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar9;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  uint extraout_v1;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined4 extraout_v1_00;
  char *pcVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  char *local_9f4;
  undefined1 *local_9f0;
  undefined1 *local_9ec;
  undefined4 local_9d8;
  undefined2 local_9d4;
  undefined4 local_9d0;
  undefined2 local_9cc;
  char local_9c8 [16];
  ushort local_9b8;
  undefined4 local_9b4;
  undefined4 local_9b0;
  undefined4 local_9ac;
  undefined4 local_9a8;
  undefined4 local_9a4;
  undefined4 local_9a0;
  undefined4 local_99c;
  undefined4 local_998;
  undefined4 local_994;
  undefined4 local_990;
  char local_98c [16];
  uint local_97c;
  char local_978 [18];
  undefined2 uStack_966;
  char local_964 [16];
  uint local_954;
  undefined4 local_950;
  undefined1 auStack_94c [4];
  undefined1 auStack_948 [4];
  char acStack_944 [4];
  undefined1 auStack_940 [4];
  undefined1 auStack_93c [4];
  undefined4 local_938;
  undefined2 local_934;
  undefined2 local_92c;
  undefined1 local_92a;
  undefined1 local_929;
  uint local_928;
  undefined4 local_924;
  char acStack_918 [32];
  undefined1 local_8f8;
  char acStack_8f4 [32];
  undefined1 local_8d4;
  undefined1 auStack_8d0 [34];
  undefined2 uStack_8ae;
  undefined1 local_8ac;
  undefined1 local_8ab;
  char acStack_850 [128];
  undefined1 local_7d0;
  char acStack_7cc [128];
  undefined1 local_74c;
  char acStack_748 [128];
  char acStack_6c8 [129];
  char acStack_647 [33];
  char acStack_626 [34];
  undefined1 auStack_604 [364];
  undefined1 auStack_498 [308];
  int local_364;
  undefined1 auStack_328 [88];
  undefined1 auStack_2d0 [296];
  undefined1 auStack_1a8 [12];
  undefined4 local_19c;
  undefined2 local_198;
  undefined4 local_194;
  undefined1 *local_16c;
  int local_160;
  int local_15c;
  undefined1 *local_158;
  undefined1 *local_154;
  char acStack_150 [40];
  byte local_128;
  undefined1 *local_64;
  int local_60;
  int local_5c;
  
  local_9c8[0] = '\0';
  local_9c8[1] = '\0';
  local_9c8[2] = '\0';
  local_9c8[3] = '\0';
  local_9c8[4] = '\0';
  local_9c8[5] = '\0';
  local_9c8[6] = '\0';
  local_9c8[7] = '\0';
  local_9c8[8] = '\0';
  local_9c8[9] = '\0';
  local_9c8[10] = '\0';
  local_9c8[0xb] = '\0';
  local_9c8[0xc] = '\0';
  local_9c8[0xd] = '\0';
  local_9c8[0xe] = '\0';
  local_9c8[0xf] = '\0';
  local_9b8 = 0;
  local_9d0 = 0;
  local_9cc = 0;
  local_9d8 = 0;
  local_9d4 = 0;
  local_964[0] = '\0';
  local_964[1] = '\0';
  local_964[2] = '\0';
  local_964[3] = '\0';
  local_964[4] = '\0';
  local_964[5] = '\0';
  local_964[6] = '\0';
  local_964[7] = '\0';
  local_964[8] = '\0';
  local_964[9] = '\0';
  local_964[10] = '\0';
  local_964[0xb] = '\0';
  local_964[0xc] = '\0';
  local_964[0xd] = '\0';
  local_964[0xe] = '\0';
  local_964[0xf] = '\0';
  local_954 = 0;
  local_978[0] = '\0';
  local_978[1] = '\0';
  local_978[2] = '\0';
  local_978[3] = '\0';
  local_978[4] = '\0';
  local_978[5] = '\0';
  local_978[6] = '\0';
  local_978[7] = '\0';
  local_978[8] = '\0';
  local_978[9] = '\0';
  local_978[10] = '\0';
  local_978[0xb] = '\0';
  local_978[0xc] = '\0';
  local_978[0xd] = '\0';
  local_978[0xe] = '\0';
  local_978[0xf] = '\0';
  stack0xfffff698 = 0;
  memset(acStack_7cc,0,0x81);
  memset(acStack_8f4,0,0x21);
  memset(acStack_850,0,0x81);
  memset(acStack_918,0,0x21);
  local_98c[0] = '\0';
  local_98c[1] = '\0';
  local_98c[2] = '\0';
  local_98c[3] = '\0';
  local_98c[4] = '\0';
  local_98c[5] = '\0';
  local_98c[6] = '\0';
  local_98c[7] = '\0';
  local_98c[8] = '\0';
  local_98c[9] = '\0';
  local_98c[10] = '\0';
  local_98c[0xb] = '\0';
  local_98c[0xc] = '\0';
  local_98c[0xd] = '\0';
  local_98c[0xe] = '\0';
  local_98c[0xf] = '\0';
  local_97c = 0;
  memset(&local_938,0,0x20);
  memset(auStack_8d0,0,0x80);
  pvVar2 = (void *)FUN_00408450(0x180,0xb2e);
  if (pvVar2 == (void *)0x0) {
    return -1;
  }
  memset(pvVar2,0,0x180);
  *(undefined4 *)((int)pvVar2 + 0x148) = 0xffffffff;
  iVar3 = json_object_object_get(param_1,"mac");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb38);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy(local_9c8,pcVar12,0x11);
  local_9b8 = local_9b8 & 0xff00;
  if (local_9c8[0] != '\0') {
    local_9f4 = acStack_944;
    local_9f0 = auStack_940;
    local_9ec = auStack_93c;
    sscanf(local_9c8,"%2X-%2X-%2X-%2X-%2X-%2X",&local_950,auStack_94c,auStack_948);
    puVar11 = &local_950;
    iVar3 = 0;
    do {
      puVar10 = (undefined1 *)((int)&local_9d0 + iVar3);
      uVar5 = *puVar11;
      iVar3 = iVar3 + 1;
      puVar11 = puVar11 + 1;
      *puVar10 = (char)uVar5;
    } while (iVar3 != 6);
  }
  memcpy((void *)((int)pvVar2 + 0xc),&local_9d0,6);
  iVar3 = json_object_object_get(param_1,"apMac");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb48);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy(local_9c8,pcVar12,0x11);
  local_9b8 = local_9b8 & 0xff00;
  if (wportal_debug_switch == 0) {
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d get ap mac = %s\n","_wportal_authed_user_add",0xb49,local_9c8);
    }
  }
  if (local_9c8[0] != '\0') {
    local_9f4 = acStack_944;
    local_9f0 = auStack_940;
    local_9ec = auStack_93c;
    sscanf(local_9c8,"%2X-%2X-%2X-%2X-%2X-%2X",&local_950,auStack_94c,auStack_948);
    puVar11 = &local_950;
    iVar3 = 0;
    do {
      puVar10 = (undefined1 *)((int)&local_9d8 + iVar3);
      uVar5 = *puVar11;
      iVar3 = iVar3 + 1;
      puVar11 = puVar11 + 1;
      *puVar10 = (char)uVar5;
    } while (iVar3 != 6);
  }
  memcpy((void *)((int)pvVar2 + 0x34),&local_9d8,6);
  if (g_portal_auth_mode == 1) {
    iVar3 = json_object_object_get(param_1,"vlan_id");
    if (iVar3 == 0) {
LAB_0041d04c:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_authed_user_add",0xb5c);
      }
      *(undefined4 *)((int)pvVar2 + 0x14) = 0xffffffff;
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        iVar3 = json_object_get_int(iVar3);
        if (iVar3 == 0) {
          iVar3 = 0xfff;
        }
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_0041d04c;
        uVar14 = json_object_get_double(iVar3);
        iVar3 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
        if (iVar3 == 0) {
          iVar3 = 0xfff;
        }
      }
      *(int *)((int)pvVar2 + 0x14) = iVar3;
    }
  }
  else if (g_portal_auth_mode == 0) {
    iVar3 = json_object_object_get(param_1,"serv_id");
    if (iVar3 == 0) {
LAB_0041c7dc:
      if (jcs_err_switch == 0) {
        *(undefined4 *)((int)pvVar2 + 0x14) = 0xffffffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_authed_user_add",0xb62);
        *(undefined4 *)((int)pvVar2 + 0x14) = 0xffffffff;
      }
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        uVar5 = json_object_get_int(iVar3);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_0041c7dc;
        uVar14 = json_object_get_double(iVar3);
        uVar5 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
      }
      *(undefined4 *)((int)pvVar2 + 0x14) = uVar5;
    }
  }
  else {
    memset((void *)((int)pvVar2 + 0x14),0,0x20);
  }
  iVar3 = json_object_object_get(param_1,"expire_time");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb6b);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy(local_964,pcVar12,0x13);
  local_954 = local_954 & 0xffffff00;
  uVar13 = strtoull(local_964,(char **)0x0,10);
  *(int *)((int)pvVar2 + 0x3c) = (int)uVar13;
  iVar3 = json_object_object_get(param_1,"auth_type");
  if (iVar3 == 0) {
LAB_0041bd00:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb6f);
    }
    uVar9 = 0xff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar9 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041bd00;
      uVar14 = json_object_get_double(iVar3);
      uVar9 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined1 *)((int)pvVar2 + 0x80) = uVar9;
  iVar3 = json_object_object_get(param_1,"auth_server_type");
  local_98c[0] = '\0';
  local_98c[1] = '\0';
  local_98c[2] = '\0';
  local_98c[3] = '\0';
  local_98c[4] = '\0';
  local_98c[5] = '\0';
  local_98c[6] = '\0';
  local_98c[7] = '\0';
  local_98c[8] = '\0';
  local_98c[9] = '\0';
  local_98c[10] = '\0';
  local_98c[0xb] = '\0';
  local_98c[0xc] = '\0';
  local_98c[0xd] = '\0';
  local_98c[0xe] = '\0';
  local_98c[0xf] = '\0';
  local_97c = 0;
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb73);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy(local_98c,pcVar12,0x13);
  local_97c = local_97c & 0xffffff00;
  uVar9 = _wportal_auth_server_type_str2int(local_98c);
  *(undefined1 *)((int)pvVar2 + 0x81) = uVar9;
  uVar5 = json_object_object_get(param_1,"uptime");
  iVar3 = json_object_object_get(uVar5,&DAT_00678bf4);
  if (iVar3 == 0) {
LAB_0041bde0:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb78);
    }
    uVar8 = 0xffff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar8 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041bde0;
      uVar14 = json_object_get_double(iVar3);
      uVar8 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined2 *)((int)pvVar2 + 0x108) = uVar8;
  iVar3 = json_object_object_get(uVar5,"month");
  if (iVar3 == 0) {
LAB_0041be38:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb7a);
    }
    uVar9 = 0xff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar9 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041be38;
      uVar14 = json_object_get_double(iVar3);
      uVar9 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined1 *)((int)pvVar2 + 0x10a) = uVar9;
  iVar3 = json_object_object_get(uVar5,&DAT_00678c04);
  if (iVar3 == 0) {
LAB_0041be90:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb7c);
    }
    uVar9 = 0xff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar9 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041be90;
      uVar14 = json_object_get_double(iVar3);
      uVar9 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined1 *)((int)pvVar2 + 0x10b) = uVar9;
  iVar3 = json_object_object_get(uVar5,&DAT_00678c08);
  if (iVar3 == 0) {
LAB_0041bee8:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb7e);
    }
    uVar9 = 0xff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar9 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041bee8;
      uVar14 = json_object_get_double(iVar3);
      uVar9 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined1 *)((int)pvVar2 + 0x10c) = uVar9;
  iVar3 = json_object_object_get(uVar5,&DAT_00678c10);
  if (iVar3 == 0) {
LAB_0041bf40:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb80);
    }
    uVar9 = 0xff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar9 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041bf40;
      uVar14 = json_object_get_double(iVar3);
      uVar9 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined1 *)((int)pvVar2 + 0x10d) = uVar9;
  iVar3 = json_object_object_get(uVar5,&DAT_00678c14);
  if (iVar3 == 0) {
LAB_0041bf98:
    if (jcs_err_switch == 0) {
      uVar9 = 0xff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb82);
      uVar9 = 0xff;
    }
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar9 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041bf98;
      uVar14 = json_object_get_double(iVar3);
      uVar9 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined1 *)((int)pvVar2 + 0x10e) = uVar9;
  FUN_00407e70();
  *(uint *)((int)pvVar2 + 0x154) = extraout_v1;
  uVar6 = extraout_v1 + *(int *)((int)pvVar2 + 0x3c);
  *(uint *)((int)pvVar2 + 0x44) = uVar6;
  *(uint *)((int)pvVar2 + 0x40) = (uint)(uVar6 < extraout_v1) + ((int)extraout_v1 >> 0x1f);
  iVar3 = json_object_object_get(param_1,&DAT_00677c24);
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb87);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy((char *)((int)pvVar2 + 0x58),pcVar12,0x27);
  *(undefined1 *)((int)pvVar2 + 0x7f) = 0;
  iVar3 = json_object_object_get(param_1,"token");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb89);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy((char *)((int)pvVar2 + 0x82),pcVar12,0x20);
  *(undefined1 *)((int)pvVar2 + 0xa2) = 0;
  iVar3 = json_object_object_get(param_1,"username");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb8b);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy((char *)((int)pvVar2 + 0xa3),pcVar12,100);
  *(undefined1 *)((int)pvVar2 + 0x107) = 0;
  if (*(char *)((int)pvVar2 + 0xa3) == '\0') {
    *(char *)((int)pvVar2 + 0xa3) = '-';
    *(char *)((int)pvVar2 + 0xa4) = '-';
    *(char *)((int)pvVar2 + 0xa5) = '-';
  }
  iVar3 = json_object_object_get(param_1,"update_intvl");
  if (iVar3 == 0) {
LAB_0041c118:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb92);
    }
    iVar3 = -1;
    *(undefined4 *)((int)pvVar2 + 0x4c) = 0xffffffff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      iVar3 = json_object_get_int(iVar3);
      *(int *)((int)pvVar2 + 0x4c) = iVar3;
      iVar3 = iVar3 >> 0x1f;
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041c118;
      uVar14 = json_object_get_double(iVar3);
      uVar14 = __fixunsdfdi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
      iVar3 = (int)((ulonglong)uVar14 >> 0x20);
      *(int *)((int)pvVar2 + 0x4c) = (int)uVar14;
    }
  }
  *(int *)((int)pvVar2 + 0x48) = iVar3;
  iVar3 = json_object_object_get(param_1,"radius_index");
  if (iVar3 == 0) {
LAB_0041c178:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb95);
    }
    uVar5 = 0xffffffff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar5 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041c178;
      uVar14 = json_object_get_double(iVar3);
      uVar5 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x158) = uVar5;
  iVar3 = json_object_object_get(param_1,"acctSessid");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb98);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar3);
  }
  strncpy(local_978,pcVar12,0x12);
  uStack_966 = (ushort)(byte)uStack_966;
  uVar13 = strtoull(local_978,(char **)0x0,10);
  *(ulonglong *)((int)pvVar2 + 0x160) = uVar13;
  iVar3 = json_object_object_get(param_1,"up_limit");
  if (iVar3 == 0) {
LAB_0041c23c:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb9c);
    }
    uVar5 = 0xffffffff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar5 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041c23c;
      uVar14 = json_object_get_double(iVar3);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x168) = uVar5;
  iVar3 = json_object_object_get(param_1,"down_limit");
  if (iVar3 == 0) {
LAB_0041c294:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xb9f);
    }
    uVar5 = 0xffffffff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar5 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041c294;
      uVar14 = json_object_get_double(iVar3);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x16c) = uVar5;
  iVar3 = json_object_object_get(param_1,"auth_status");
  if (iVar3 == 0) {
LAB_0041c2ec:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xba2);
    }
    uVar5 = 0xffffffff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar5 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041c2ec;
      uVar14 = json_object_get_double(iVar3);
      uVar5 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x14c) = uVar5;
  iVar3 = json_object_object_get(param_1,"refresh");
  if (iVar3 == 0) {
LAB_0041c344:
    iVar3 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xba5);
    }
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      iVar3 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0041c344;
      uVar14 = json_object_get_double(iVar3);
      iVar3 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
    }
  }
  iVar4 = json_object_object_get(param_1,"openId");
  if ((iVar4 == 0) || (iVar7 = json_object_get_type(iVar4), iVar7 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xba8);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar4);
  }
  strncpy(acStack_7cc,pcVar12,0x80);
  local_74c = 0;
  iVar4 = json_object_object_get(param_1,"app_secret");
  if ((iVar4 == 0) || (iVar7 = json_object_get_type(iVar4), iVar7 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xbab);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar4);
  }
  strncpy(acStack_8f4,pcVar12,0x20);
  local_8d4 = 0;
  iVar4 = json_object_object_get(param_1,"app_id");
  if ((iVar4 == 0) || (iVar7 = json_object_get_type(iVar4), iVar7 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xbae);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar4);
  }
  strncpy(acStack_918,pcVar12,0x20);
  local_8f8 = 0;
  iVar4 = json_object_object_get(param_1,"token_server");
  if ((iVar4 == 0) || (iVar7 = json_object_get_type(iVar4), iVar7 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_authed_user_add",0xbb1);
    }
    pcVar12 = "";
  }
  else {
    pcVar12 = (char *)json_object_get_string(iVar4);
  }
  bVar1 = false;
  strncpy(acStack_850,pcVar12,0x80);
  local_7d0 = 0;
  *(undefined4 *)((int)pvVar2 + 0x50) = *(undefined4 *)((int)pvVar2 + 0x48);
  *(undefined4 *)((int)pvVar2 + 0x54) = *(undefined4 *)((int)pvVar2 + 0x4c);
  *(undefined4 *)((int)pvVar2 + 0x144) = 0x3c;
  if (iVar3 == 1) {
    if ((*(int *)((int)pvVar2 + 0xc) == 0) && ((*(uint *)((int)pvVar2 + 0x10) & 0xffff0000) == 0)) {
      if ((wportal_info_switch != 0) && (iVar4 = is_target_debug_ap((int)pvVar2 + 0x58), iVar4 != 0)
         ) {
        printf("[WPORTAL_INFO]%s()/%d mac is zero get by ip:%s\n","_wportal_authed_user_add",0xbd1,
               (int)pvVar2 + 0x58);
      }
      bVar1 = false;
      iVar4 = wportal_db_aut_get_by_ip((int)pvVar2 + 0x58,auStack_328);
      if (iVar4 != 0) {
        FUN_00407df0(pvVar2);
        iVar4 = 0;
        if (wportal_debug_switch == 0) {
          return 0;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0;
        }
        pcVar12 = "[WPORTAL_DBG]%s()/%d not exist return\n";
        uVar5 = 0xbd6;
        goto LAB_0041ca7c;
      }
    }
    else {
      iVar4 = wportal_db_aut_get((int)pvVar2 + 0xc,auStack_328);
      if (iVar4 != 0) {
        FUN_00407df0(pvVar2);
        iVar4 = 0;
        if (wportal_debug_switch == 0) {
          return 0;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0;
        }
        pcVar12 = "[WPORTAL_DBG]%s()/%d not exist return\n";
        uVar5 = 0xbbf;
        goto LAB_0041ca7c;
      }
      local_9a0 = 0;
      local_99c = 0;
      local_998 = 0;
      bVar1 = false;
      local_994 = 0;
      local_990 = 0;
      local_9b4 = 0;
      local_9b0 = 0;
      local_9ac = 0;
      local_9a8 = 0;
      local_9a4 = 0;
      iVar4 = FUN_0051a7a8(auStack_2d0,&local_9a0);
      if (iVar4 == 0) {
        uVar6 = FUN_0051a7a8((int)pvVar2 + 0x58,&local_9b4);
        bVar1 = false;
        if (uVar6 == 0) {
          for (; uVar6 < 0x14; uVar6 = uVar6 + 1) {
            *(undefined1 *)((int)&local_9f4 + uVar6) = *(undefined1 *)((int)&local_9b4 + uVar6);
          }
          bVar1 = false;
          iVar4 = FUN_004085c0(local_9a0,local_99c,local_998,local_994,local_990);
          if (((iVar4 == 0) && (bVar1 = true, wportal_info_switch != 0)) &&
             (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d ip update:[%s]->[%s]\n","_wportal_authed_user_add",0xbca,
                   (int)pvVar2 + 0x58,auStack_2d0);
          }
        }
      }
    }
  }
  if (g_portal_auth_mode == 1) {
    memset(auStack_498,0,0x16c);
    iVar4 = wportal_db_rdt_get_by_vlan(*(undefined4 *)((int)pvVar2 + 0x14),auStack_498);
    if ((iVar4 != 0) || (local_364 == 0)) {
LAB_0041cde0:
      FUN_00407df0(pvVar2);
      return 0;
    }
    iVar4 = *(int *)((int)pvVar2 + 0xc);
  }
  else if (g_portal_auth_mode == 0) {
    memset(auStack_604,0,0x16c);
    iVar4 = wportal_db_ssid_rdt_get(*(undefined4 *)((int)pvVar2 + 0x14),auStack_604);
    if (iVar4 != 0) goto LAB_0041cde0;
    iVar4 = *(int *)((int)pvVar2 + 0xc);
  }
  else {
    iVar4 = *(int *)((int)pvVar2 + 0xc);
  }
  if ((iVar4 == 0) && ((*(uint *)((int)pvVar2 + 0x10) & 0xffff0000) == 0)) {
    if ((wportal_info_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d mac is zero get by ip:%s\n","_wportal_authed_user_add",0xc03,
             (int)pvVar2 + 0x58);
    }
    memset(auStack_1a8,0,0x180);
    iVar4 = wportal_db_aut_get_by_ip((int)pvVar2 + 0x58,auStack_1a8);
    if ((iVar4 != -1) && ((local_5c == 0xf || ((iVar3 != 1 && (local_5c == 9)))))) {
      if (local_60 != -1) {
        FUN_00408060();
        local_60 = -1;
      }
      wportal_db_aut_del_by_ip((int)pvVar2 + 0x58);
    }
  }
  else {
    memset(auStack_1a8,0,0x180);
    iVar4 = wportal_db_aut_get((int)pvVar2 + 0xc,auStack_1a8);
    if ((iVar4 != -1) && ((local_5c == 0xf || ((iVar3 != 1 && (local_5c == 9)))))) {
      if (local_60 != -1) {
        FUN_00408060();
        local_60 = -1;
      }
      wportal_db_aut_del((int)pvVar2 + 0xc);
    }
  }
  iVar4 = wportal_db_aut_add(pvVar2);
  memset(auStack_1a8,0,0x180);
  memcpy(auStack_1a8,pvVar2,0x180);
  if (iVar4 == 10) {
LAB_0041ca00:
    if ((wportal_info_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d ret is not OK:%d\n","_wportal_authed_user_add",0xc20,iVar4);
    }
    FUN_00407df0(pvVar2);
    if (iVar3 != 1) goto LAB_0041c5b8;
LAB_0041ca20:
    wportal_db_aut_set(auStack_1a8);
    if (bVar1) {
      _wportal_update_entry_radius(auStack_1a8);
    }
  }
  else {
    if ((g_portal_auth_mode == 1) || (g_portal_auth_mode == 0)) {
      wportal_update_user_to_ap(auStack_1a8,0);
    }
    if (iVar4 != 0) goto LAB_0041ca00;
LAB_0041c5b8:
    if (local_60 != -1) {
      FUN_00408060();
      local_60 = -1;
    }
    pvVar2 = (void *)FUN_00408450(0x48,0xc2c);
    if (pvVar2 == (void *)0x0) {
      return -1;
    }
    memset(pvVar2,0,0x48);
    if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      local_9ec = local_154;
      local_9f0 = local_158;
      printf("[WPORTAL_DBG]%s()/%d Check timer: expire: %u, station check: %d, radius acct update: %llu\n\n"
             ,"_wportal_authed_user_add",0xc35,local_16c,local_64);
    }
    memcpy(pvVar2,&local_19c,6);
    strncpy((char *)((int)pvVar2 + 0x20),acStack_150,0x28);
    if ((g_portal_auth_mode == 1) || (g_portal_auth_mode == 0)) {
      *(undefined4 *)((int)pvVar2 + 8) = local_194;
    }
    else {
      *(undefined1 *)((int)pvVar2 + 8) = 0;
      *(undefined1 *)((int)pvVar2 + 9) = 0;
      *(undefined1 *)((int)pvVar2 + 10) = 0;
      *(undefined1 *)((int)pvVar2 + 0xb) = 0;
    }
    puVar10 = (undefined1 *)((int)local_64 >> 0x1f);
    if (local_160 == 0 && local_15c == 0) {
      *(undefined4 *)((int)pvVar2 + 0x1c) = 1;
      if (local_16c <= local_64) {
        *(undefined4 *)((int)pvVar2 + 0x18) = 0;
        goto LAB_0041c690;
      }
      *(undefined4 *)((int)pvVar2 + 0x18) = 1;
LAB_0041c974:
      *(undefined1 **)((int)pvVar2 + 0x14) = local_64;
      *(undefined1 **)((int)pvVar2 + 0x10) = puVar10;
    }
    else if (local_64 < local_16c) {
LAB_0041c948:
      if (((local_64 <= local_16c) && (puVar10 <= local_158)) &&
         ((local_158 != puVar10 || (local_64 <= local_154)))) {
        *(undefined4 *)((int)pvVar2 + 0x18) = 1;
        goto LAB_0041c974;
      }
      *(undefined4 *)((int)pvVar2 + 0x18) = 2;
      *(undefined1 **)((int)pvVar2 + 0x14) = local_154;
      *(undefined1 **)((int)pvVar2 + 0x10) = local_158;
    }
    else {
      if (local_158 == (undefined1 *)0x0) {
        if (local_154 < local_16c) goto LAB_0041c948;
        *(undefined4 *)((int)pvVar2 + 0x18) = 0;
      }
      else {
        *(undefined4 *)((int)pvVar2 + 0x18) = 0;
      }
LAB_0041c690:
      *(undefined4 *)((int)pvVar2 + 0x10) = 0;
      *(undefined1 **)((int)pvVar2 + 0x14) = local_16c;
    }
    if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      local_9f4 = *(char **)((int)pvVar2 + 0x14);
      local_9f0 = *(undefined1 **)((int)pvVar2 + 0x18);
      printf("[WPORTAL_DBG]%s()/%d Add authed user timer: %llu, type: %d\n\n",
             "_wportal_authed_user_add",0xc69);
    }
    local_9f4 = "_wportal_authed_user_add";
    local_9f0 = (undefined1 *)0xc6b;
    iVar4 = FUN_00408340(*(undefined4 *)((int)pvVar2 + 0x14),0,_wportal_authed_user_timer_handler,
                         pvVar2,_wportal_authed_user_timer_handler_free);
    if (iVar4 == -1) {
      FUN_00407df0(pvVar2);
      if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Add timer error\n","_wportal_authed_user_add",0xc73);
      }
      iVar4 = -1;
      if (iVar3 == 1) goto LAB_0041ca20;
    }
    else {
      local_60 = iVar4;
      wportal_db_aut_set(auStack_1a8);
      memset(acStack_748,0,0x143);
      strncpy(acStack_647,acStack_8f4,0x20);
      strncpy(acStack_626,acStack_918,0x20);
      strncpy(acStack_748,acStack_7cc,0x7f);
      strncpy(acStack_6c8,acStack_850,0x80);
      wportal_db_foreach_event_list(0,auStack_1a8,acStack_748);
      iVar3 = wsta_db_get_entry_by_mac(&local_19c,auStack_8d0);
      if (iVar3 != 0) {
        return 0;
      }
      memset(&local_938,0,0x20);
      local_938 = local_19c;
      local_934 = local_198;
      local_92c = uStack_8ae;
      local_92a = local_8ac;
      local_929 = local_8ab;
      local_928 = (uint)local_128;
      FUN_00407e70();
      local_924 = extraout_v1_00;
      stats_db_auth_ok_sta_add(&local_938);
      iVar4 = 0;
    }
  }
  if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d wportal add auth. send to datasync is sync:%d\n",
           "_wportal_authed_user_add",0xca1,param_2);
  }
  if (param_2 != 0) {
    return iVar4;
  }
  if (wportal_info_switch == 0) {
    return iVar4;
  }
  iVar3 = is_target_debug_ap();
  if (iVar3 == 0) {
    return iVar4;
  }
  pcVar12 = "[WPORTAL_INFO]%s()/%d dump auth list after add:\n\n";
  uVar5 = 0xcb9;
LAB_0041ca7c:
  printf(pcVar12,"_wportal_authed_user_add",uVar5);
  return iVar4;
}

