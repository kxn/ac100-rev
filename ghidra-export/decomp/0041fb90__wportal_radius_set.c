// func _wportal_radius_set @ 0041fb90 size=1660

int _wportal_radius_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  char local_25c [16];
  uint local_24c;
  char acStack_248 [254];
  undefined1 local_14a;
  char acStack_148 [120];
  undefined1 local_d0;
  char acStack_cf [100];
  undefined1 local_6b;
  char acStack_6a [39];
  undefined1 local_43;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  memset(acStack_248,0,0xff);
  local_25c[0] = '\0';
  local_25c[1] = '\0';
  local_25c[2] = '\0';
  local_25c[3] = '\0';
  local_25c[4] = '\0';
  local_25c[5] = '\0';
  local_25c[6] = '\0';
  local_25c[7] = '\0';
  local_25c[8] = '\0';
  local_25c[9] = '\0';
  local_25c[10] = '\0';
  local_25c[0xb] = '\0';
  local_25c[0xc] = '\0';
  local_25c[0xd] = '\0';
  local_25c[0xe] = '\0';
  local_25c[0xf] = '\0';
  local_24c = 0;
  local_270 = 0;
  local_26c = 0;
  local_268 = 0;
  local_264 = 0;
  local_260 = 0;
  memset(acStack_148,0,0x134);
  iVar1 = json_object_object_get(param_1,"entry_id");
  if (iVar1 == 0) {
LAB_0041fc2c:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x136a);
    }
    local_40 = 0xffffffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_40 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041fc2c;
      uVar4 = json_object_get_double(iVar1);
      local_40 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"auth_port");
  if (iVar1 == 0) {
LAB_0041fc84:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x136d);
    }
    local_3c = 0xffffffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_3c = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041fc84;
      uVar4 = json_object_get_double(iVar1);
      local_3c = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"account_port");
  if (iVar1 == 0) {
LAB_0041fcdc:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x1370);
    }
    local_38 = 0xffffffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_38 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041fcdc;
      uVar4 = json_object_get_double(iVar1);
      local_38 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"retry_count");
  if (iVar1 == 0) {
LAB_0041fd34:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x1373);
    }
    local_34 = 0xffffffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_34 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0041fd34;
      uVar4 = json_object_get_double(iVar1);
      local_34 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    }
  }
  iVar1 = json_object_object_get(param_1,"retry_interval");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_30 = json_object_get_int(iVar1);
      goto LAB_0041fda4;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      local_30 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_0041fda4;
    }
  }
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_radius_set",0x1376);
  }
  local_30 = 0xffffffff;
LAB_0041fda4:
  iVar1 = json_object_object_get(param_1,"radius_auth_type");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x1379);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_25c,pcVar3,0x13);
  local_24c = local_24c & 0xffffff00;
  local_2c = _radius_auth_type_str2int(local_25c);
  iVar1 = json_object_object_get(param_1,"nas_identifier");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x137d);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_cf,pcVar3,100);
  local_6b = 0;
  iVar1 = json_object_object_get(param_1,"nas_ip");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x1380);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_6a,pcVar3,0x27);
  local_43 = 0;
  iVar1 = json_object_object_get(param_1,"share_key");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x1383);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_148,pcVar3,0x78);
  local_d0 = 0;
  iVar1 = json_object_object_get(param_1,"server_addr");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_radius_set",0x1386);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_248,pcVar3,0xfe);
  local_14a = 0;
  wportal_db_rds_srv_hash_del(local_40);
  wportal_db_rds_srv_set(acStack_148);
  iVar1 = FUN_0051a7a8(acStack_248,&local_270);
  if (iVar1 == 0) {
    wportal_radius_server_table_add(local_40,local_270,local_26c,local_268,local_264,local_260);
  }
  return iVar1;
}

