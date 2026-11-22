// func _wportal_radius_add @ 0042020c size=1716

int _wportal_radius_add(undefined4 param_1)

{
  char *__dest;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  char local_138 [16];
  uint local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  char acStack_110 [254];
  undefined1 local_12;
  
  memset(acStack_110,0,0xff);
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_138[0] = '\0';
  local_138[1] = '\0';
  local_138[2] = '\0';
  local_138[3] = '\0';
  local_138[4] = '\0';
  local_138[5] = '\0';
  local_138[6] = '\0';
  local_138[7] = '\0';
  local_138[8] = '\0';
  local_138[9] = '\0';
  local_138[10] = '\0';
  local_138[0xb] = '\0';
  local_138[0xc] = '\0';
  local_138[0xd] = '\0';
  local_138[0xe] = '\0';
  local_138[0xf] = '\0';
  local_128 = 0;
  __dest = (char *)FUN_00408450(0x134,0x12e7);
  if (__dest == (char *)0x0) {
    return -1;
  }
  memset(__dest,0,0x134);
  iVar1 = json_object_object_get(param_1,"entry_id");
  if (iVar1 == 0) {
LAB_004202c4:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x12ef);
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
      if (iVar2 != 2) goto LAB_004202c4;
      uVar5 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
    }
  }
  *(undefined4 *)(__dest + 0x108) = uVar3;
  iVar1 = json_object_object_get(param_1,"auth_port");
  if (iVar1 == 0) {
LAB_0042031c:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x12f2);
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
      if (iVar2 != 2) goto LAB_0042031c;
      uVar5 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
    }
  }
  *(undefined4 *)(__dest + 0x10c) = uVar3;
  iVar1 = json_object_object_get(param_1,"account_port");
  if (iVar1 == 0) {
LAB_00420374:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x12f5);
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
      if (iVar2 != 2) goto LAB_00420374;
      uVar5 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
    }
  }
  *(undefined4 *)(__dest + 0x110) = uVar3;
  iVar1 = json_object_object_get(param_1,"retry_count");
  if (iVar1 == 0) {
LAB_004203cc:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x12f8);
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
      if (iVar2 != 2) goto LAB_004203cc;
      uVar5 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
    }
  }
  *(undefined4 *)(__dest + 0x114) = uVar3;
  iVar1 = json_object_object_get(param_1,"retry_interval");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
      goto LAB_0042043c;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar5 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      goto LAB_0042043c;
    }
  }
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_radius_add",0x12fb);
  }
  uVar3 = 0xffffffff;
LAB_0042043c:
  *(undefined4 *)(__dest + 0x118) = uVar3;
  iVar1 = json_object_object_get(param_1,"radius_auth_type");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x12fe);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_138,pcVar4,0x13);
  local_128 = local_128 & 0xffffff00;
  uVar3 = _radius_auth_type_str2int(local_138);
  *(undefined4 *)(__dest + 0x11c) = uVar3;
  iVar1 = json_object_object_get(param_1,"nas_identifier");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x1302);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(__dest + 0x79,pcVar4,100);
  __dest[0xdd] = '\0';
  iVar1 = json_object_object_get(param_1,"nas_ip");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x1305);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(__dest + 0xde,pcVar4,0x27);
  __dest[0x105] = '\0';
  iVar1 = json_object_object_get(param_1,"share_key");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x1308);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(__dest,pcVar4,0x78);
  __dest[0x78] = '\0';
  iVar1 = json_object_object_get(param_1,"server_addr");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_add",0x130b);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_110,pcVar4,0xfe);
  local_12 = 0;
  iVar1 = wportal_db_rds_srv_add(__dest);
  if (iVar1 == 0) {
    iVar1 = FUN_0051a7a8(acStack_110,&local_124);
    if (iVar1 == 0) {
      wportal_radius_server_table_add
                (*(undefined4 *)(__dest + 0x108),local_124,local_120,local_11c,local_118,local_114);
    }
  }
  else {
    FUN_00407df0(__dest);
  }
  return iVar1;
}

