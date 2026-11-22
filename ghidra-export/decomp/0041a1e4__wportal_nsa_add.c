// func _wportal_nsa_add @ 0041a1e4 size=4596

int _wportal_nsa_add(undefined4 param_1,int param_2)

{
  void *__s;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar5;
  undefined2 uVar4;
  undefined4 *puVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined4 local_88;
  undefined2 local_84;
  char local_80 [16];
  ushort local_70;
  char local_6c [16];
  uint local_5c;
  undefined4 local_58;
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  char acStack_40 [39];
  undefined1 local_19;
  
  local_80[0] = '\0';
  local_80[1] = '\0';
  local_80[2] = '\0';
  local_80[3] = '\0';
  local_80[4] = '\0';
  local_80[5] = '\0';
  local_80[6] = '\0';
  local_80[7] = '\0';
  local_80[8] = '\0';
  local_80[9] = '\0';
  local_80[10] = '\0';
  local_80[0xb] = '\0';
  local_80[0xc] = '\0';
  local_80[0xd] = '\0';
  local_80[0xe] = '\0';
  local_80[0xf] = '\0';
  local_70 = 0;
  memset(acStack_40,0,0x28);
  local_88 = 0;
  local_84 = 0;
  local_6c[0] = '\0';
  local_6c[1] = '\0';
  local_6c[2] = '\0';
  local_6c[3] = '\0';
  local_6c[4] = '\0';
  local_6c[5] = '\0';
  local_6c[6] = '\0';
  local_6c[7] = '\0';
  local_6c[8] = '\0';
  local_6c[9] = '\0';
  local_6c[10] = '\0';
  local_6c[0xb] = '\0';
  local_6c[0xc] = '\0';
  local_6c[0xd] = '\0';
  local_6c[0xe] = '\0';
  local_6c[0xf] = '\0';
  local_5c = 0;
  __s = (void *)FUN_00408450(0x168,0x105d);
  if (__s == (void *)0x0) {
    return -1;
  }
  memset(__s,0,0x168);
  iVar1 = json_object_object_get(param_1,"mac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x1065);
    }
    pcVar7 = "";
  }
  else {
    pcVar7 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_80,pcVar7,0x11);
  local_70 = local_70 & 0xff00;
  if (local_80[0] != '\0') {
    sscanf(local_80,"%2X-%2X-%2X-%2X-%2X-%2X",&local_58,auStack_54,auStack_50,auStack_4c,auStack_48,
           auStack_44);
    puVar6 = &local_58;
    iVar1 = 0;
    do {
      puVar8 = (undefined1 *)((int)&local_88 + iVar1);
      uVar3 = *puVar6;
      iVar1 = iVar1 + 1;
      puVar6 = puVar6 + 1;
      *puVar8 = (char)uVar3;
    } while (iVar1 != 6);
  }
  memcpy((void *)((int)__s + 0x74),&local_88,6);
  if (g_portal_auth_mode == 1) {
    iVar1 = json_object_object_get(param_1,"vlan_id");
    if (iVar1 == 0) {
LAB_0041acd8:
      if (jcs_err_switch != 0) {
        uVar3 = 0x1078;
        goto LAB_0041ad80;
      }
      iVar1 = -1;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
        if (iVar1 == 0) {
          iVar1 = 0xfff;
        }
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041acd8;
        uVar9 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
        if (iVar1 == 0) {
          iVar1 = 0xfff;
        }
      }
    }
  }
  else {
    iVar1 = json_object_object_get(param_1,"serv_id");
    if (iVar1 == 0) {
LAB_0041a32c:
      if (jcs_err_switch == 0) {
        iVar1 = -1;
      }
      else {
        uVar3 = 0x107e;
LAB_0041ad80:
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",uVar3);
        iVar1 = -1;
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041a32c;
        uVar9 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
  }
  *(int *)((int)__s + 0x128) = iVar1;
  iVar1 = json_object_object_get(param_1,"auth_type");
  if (iVar1 == 0) {
LAB_0041a384:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x1082);
    }
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a384;
      uVar9 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined4 *)((int)__s + 0x148) = uVar3;
  iVar1 = json_object_object_get(param_1,"auth_server_type");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x1085);
    }
    pcVar7 = "";
  }
  else {
    pcVar7 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_6c,pcVar7,0x13);
  local_5c = local_5c & 0xffffff00;
  uVar3 = _wportal_auth_server_type_str2int(local_6c);
  *(undefined4 *)((int)__s + 0x14c) = uVar3;
  uVar3 = json_object_object_get(param_1,"uptime");
  iVar1 = json_object_object_get(uVar3,&DAT_00678bf4);
  if (iVar1 == 0) {
LAB_0041a450:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x108a);
    }
    uVar4 = 0xffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a450;
      uVar9 = json_object_get_double(iVar1);
      uVar4 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined2 *)((int)__s + 0x108) = uVar4;
  iVar1 = json_object_object_get(uVar3,"month");
  if (iVar1 == 0) {
LAB_0041a4a8:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x108c);
    }
    uVar5 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a4a8;
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined1 *)((int)__s + 0x10a) = uVar5;
  iVar1 = json_object_object_get(uVar3,&DAT_00678c04);
  if (iVar1 == 0) {
LAB_0041a500:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x108e);
    }
    uVar5 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a500;
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined1 *)((int)__s + 0x10b) = uVar5;
  iVar1 = json_object_object_get(uVar3,&DAT_00678c08);
  if (iVar1 == 0) {
LAB_0041a558:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x1090);
    }
    uVar5 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a558;
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined1 *)((int)__s + 0x10c) = uVar5;
  iVar1 = json_object_object_get(uVar3,&DAT_00678c10);
  if (iVar1 == 0) {
LAB_0041a5b0:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x1092);
    }
    uVar5 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a5b0;
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined1 *)((int)__s + 0x10d) = uVar5;
  iVar1 = json_object_object_get(uVar3,&DAT_00678c14);
  if (iVar1 == 0) {
LAB_0041a608:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x1094);
    }
    uVar5 = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a608;
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined1 *)((int)__s + 0x10e) = uVar5;
  iVar1 = json_object_object_get(param_1,"username");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x1097);
    }
    pcVar7 = "";
  }
  else {
    pcVar7 = (char *)json_object_get_string(iVar1);
  }
  strncpy((char *)((int)__s + 0x7a),pcVar7,100);
  *(undefined1 *)((int)__s + 0xde) = 0;
  iVar1 = json_object_object_get(param_1,"useChap");
  if (iVar1 == 0) {
LAB_0041a6b4:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x109a);
    }
    *(undefined1 *)((int)__s + 0x166) = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
      *(undefined1 *)((int)__s + 0x166) = uVar5;
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041a6b4;
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      *(undefined1 *)((int)__s + 0x166) = uVar5;
    }
  }
  if (*(char *)((int)__s + 0x166) == '\0') {
    iVar1 = json_object_object_get(param_1,"password");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x109f);
      }
      pcVar7 = "";
    }
    else {
      pcVar7 = (char *)json_object_get_string(iVar1);
    }
    strncpy((char *)((int)__s + 0xc),pcVar7,100);
    *(undefined1 *)((int)__s + 0x70) = 0;
  }
  else {
    iVar1 = json_object_object_get(param_1,"challenge1");
    if (iVar1 == 0) {
LAB_0041a840:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10a4);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041a840;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0xc) = uVar3;
    iVar1 = json_object_object_get(param_1,"challenge2");
    if (iVar1 == 0) {
LAB_0041a898:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10a6);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041a898;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0x10) = uVar3;
    iVar1 = json_object_object_get(param_1,"challenge3");
    if (iVar1 == 0) {
LAB_0041a8f0:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10a8);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041a8f0;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0x14) = uVar3;
    iVar1 = json_object_object_get(param_1,"challenge4");
    if (iVar1 == 0) {
LAB_0041a948:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10aa);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041a948;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0x18) = uVar3;
    iVar1 = json_object_object_get(param_1,"chapPassword1");
    if (iVar1 == 0) {
LAB_0041a9a0:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10ad);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041a9a0;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0x1c) = uVar3;
    iVar1 = json_object_object_get(param_1,"chapPassword2");
    if (iVar1 == 0) {
LAB_0041a9f8:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10af);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041a9f8;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0x20) = uVar3;
    iVar1 = json_object_object_get(param_1,"chapPassword3");
    if (iVar1 == 0) {
LAB_0041aa50:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10b1);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041aa50;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0x24) = uVar3;
    iVar1 = json_object_object_get(param_1,"chapPassword4");
    if (iVar1 == 0) {
LAB_0041aaa8:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10b3);
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041aaa8;
        uVar9 = json_object_get_double(iVar1);
        uVar3 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    *(undefined4 *)((int)__s + 0x28) = uVar3;
    iVar1 = json_object_object_get(param_1,"chapid");
    if (iVar1 == 0) {
LAB_0041ab00:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_add",0x10b6);
      }
      *(undefined1 *)((int)__s + 0x2c) = 0xff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar5 = json_object_get_int(iVar1);
        *(undefined1 *)((int)__s + 0x2c) = uVar5;
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0041ab00;
        uVar9 = json_object_get_double(iVar1);
        uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
        *(undefined1 *)((int)__s + 0x2c) = uVar5;
      }
    }
  }
  iVar1 = json_object_object_get(param_1,&DAT_00677c24);
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x10ba);
    }
    pcVar7 = "";
  }
  else {
    pcVar7 = (char *)json_object_get_string(iVar1);
  }
  strncpy((char *)((int)__s + 0xdf),pcVar7,0x28);
  *(undefined1 *)((int)__s + 0x107) = 0;
  if (*(int *)((int)__s + 0x148) != 0x20) goto LAB_0041a788;
  iVar1 = json_object_object_get(param_1,"serialNo");
  if (iVar1 == 0) {
LAB_0041af30:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x10c0);
    }
    uVar4 = 0xffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041af30;
      uVar9 = json_object_get_double(iVar1);
      uVar4 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  *(undefined2 *)((int)__s + 0x164) = uVar4;
  iVar1 = json_object_object_get(param_1,"cmccServerIp");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_nsa_add",0x10c4);
    }
    pcVar7 = "";
  }
  else {
    pcVar7 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_40,pcVar7,0x27);
  local_19 = 0;
  FUN_0051a7a8(acStack_40,(int)__s + 0x150);
LAB_0041a788:
  iVar1 = wportal_db_nsa_add(__s);
  if (iVar1 != 0) {
    if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Add error or exist\n\n","_wportal_nsa_add",0x10cc);
    }
    FUN_00407df0(__s);
  }
  if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d wportal add nsa %d. send to datasync is sync:%d \n",
           "_wportal_nsa_add",0x10d4,iVar1,param_2);
  }
  if (((param_2 == 0) && (wportal_info_switch != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0))
  {
    printf("[WPORTAL_INFO]%s()/%d dump nas list after add:\n\n","_wportal_nsa_add",0x10ec);
  }
  return iVar1;
}

