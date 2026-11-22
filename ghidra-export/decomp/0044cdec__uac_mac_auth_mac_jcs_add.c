// func _uac_mac_auth_mac_jcs_add @ 0044cdec size=724

void _uac_mac_auth_mac_jcs_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char local_d8 [16];
  uint local_c8;
  int local_c4;
  char acStack_c0 [155];
  undefined1 local_25;
  undefined1 auStack_24 [12];
  
  memset(&local_c4,0,0xa8);
  local_d8[0] = '\0';
  local_d8[1] = '\0';
  local_d8[2] = '\0';
  local_d8[3] = '\0';
  local_d8[4] = '\0';
  local_d8[5] = '\0';
  local_d8[6] = '\0';
  local_d8[7] = '\0';
  local_d8[8] = '\0';
  local_d8[9] = '\0';
  local_d8[10] = '\0';
  local_d8[0xb] = '\0';
  local_d8[0xc] = '\0';
  local_d8[0xd] = '\0';
  local_d8[0xe] = '\0';
  local_d8[0xf] = '\0';
  local_c8 = 0;
  local_c4 = -1;
  iVar1 = json_object_object_get(param_1,"name");
  if (iVar1 == 0) {
    if (macauth_err_switch == 0) {
      iVar1 = -1;
      goto LAB_0044cf0c;
    }
    uVar3 = 0x10f;
    pcVar4 = "name";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_mac_auth_mac_jcs_add",0x110);
      }
      pcVar4 = "";
    }
    strncpy(acStack_c0,pcVar4,0x9b);
    local_25 = 0;
    iVar1 = json_object_object_get(param_1,"mac");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar4 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_mac_jcs_add",0x114);
        }
        pcVar4 = "";
      }
      strncpy(local_d8,pcVar4,0x13);
      local_c8 = local_c8 & 0xffffff00;
      iVar1 = mac_auth_mac_parse(local_d8,auStack_24);
      if (iVar1 == 0) {
        iVar2 = mac_auth_db_mac_entry_add(&local_c4);
        iVar1 = local_c4;
        if ((iVar2 != 0) && (iVar1 = iVar2, macauth_debug_switch != 0)) {
          printf("[MACAUTH_DEBUG]%s()/%d mac_auth_db_mac_entry_add() failed.\n",
                 "_uac_mac_auth_mac_jcs_add",0x11d);
        }
        if (iVar1 == -2) {
          uVar3 = json_object_new_int(local_c4);
          json_object_object_add(param_2,"result",uVar3);
        }
      }
      else if (macauth_err_switch == 0) {
        iVar1 = -1;
      }
      else {
        printf("[MACAUTH_ERROR]%s()/%d mac_auth_mac_parse() failed.\n","_uac_mac_auth_mac_jcs_add",
               0x117);
        iVar1 = -1;
      }
      goto LAB_0044cf0c;
    }
    if (macauth_err_switch == 0) {
      iVar1 = -1;
      goto LAB_0044cf0c;
    }
    uVar3 = 0x113;
    pcVar4 = "mac";
  }
  iVar1 = -1;
  printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_mac_jcs_add",uVar3,pcVar4);
LAB_0044cf0c:
  uVar3 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"id",uVar3);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_mac_jcs_add() finish, id=%d.\n",
           "_uac_mac_auth_mac_jcs_add",0x129,iVar1);
  }
  return;
}

