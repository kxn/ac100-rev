// func _wportal_search_arg_parse @ 0040e890 size=888

undefined4 _wportal_search_arg_parse(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  char local_28 [16];
  uint local_18;
  
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  local_18 = 0;
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  iVar1 = json_object_object_get(param_2,"search_name");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_search_arg_parse",0x961);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_28,pcVar4,0x13);
  iVar1 = strcmp(local_28,"username");
  uVar3 = 1;
  if (iVar1 != 0) {
    iVar1 = strcmp(local_28,"auth_type");
    uVar3 = 0;
    if (iVar1 != 0) {
      iVar1 = strcmp(local_28,"password");
      uVar3 = 2;
      if (iVar1 != 0) {
        iVar1 = strcmp(local_28,"mac");
        uVar3 = 3;
        if (iVar1 != 0) {
          iVar1 = strcmp(local_28,"vlan_id");
          uVar3 = 4;
          if (iVar1 != 0) {
            iVar1 = strcmp(local_28,"ssid");
            uVar3 = 5;
            if (iVar1 != 0) {
              uVar3 = 0xffffffff;
            }
          }
        }
      }
    }
  }
  *param_1 = uVar3;
  iVar1 = json_object_object_get(param_2,"value_type");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_search_arg_parse",0x964);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_28,pcVar4,0x13);
  local_18 = local_18 & 0xffffff00;
  iVar1 = strcmp(local_28,"number");
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = strcmp(local_28,"string");
    iVar2 = 1;
    if (iVar1 != 0) {
      iVar2 = -1;
    }
  }
  param_1[1] = iVar2;
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      iVar1 = json_object_object_get(param_2,"search_value");
      if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wportal_search_arg_parse",0x970);
        }
        pcVar4 = "";
      }
      else {
        pcVar4 = (char *)json_object_get_string(iVar1);
      }
      strncpy((char *)(param_1 + 2),pcVar4,100);
      *(undefined1 *)(param_1 + 0x1b) = 0;
      FUN_00408150(param_1 + 2);
      return 0;
    }
    return 0;
  }
  iVar1 = json_object_object_get(param_2,"search_value");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
      param_1[2] = uVar3;
      return 0;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar5 = json_object_get_double(iVar1);
      uVar3 = __fixunsdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      param_1[2] = uVar3;
      return 0;
    }
  }
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_search_arg_parse",0x96b);
  }
  param_1[2] = 0xffffffff;
  return 0;
}

