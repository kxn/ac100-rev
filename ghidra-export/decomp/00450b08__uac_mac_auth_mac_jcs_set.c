// func _uac_mac_auth_mac_jcs_set @ 00450b08 size=964

void _uac_mac_auth_mac_jcs_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined8 uVar6;
  char local_e0 [16];
  uint local_d0;
  undefined4 local_cc;
  char acStack_c8 [155];
  undefined1 local_2d;
  undefined1 auStack_2c [16];
  
  local_e0[0] = '\0';
  local_e0[1] = '\0';
  local_e0[2] = '\0';
  local_e0[3] = '\0';
  local_e0[4] = '\0';
  local_e0[5] = '\0';
  local_e0[6] = '\0';
  local_e0[7] = '\0';
  local_e0[8] = '\0';
  local_e0[9] = '\0';
  local_e0[10] = '\0';
  local_e0[0xb] = '\0';
  local_e0[0xc] = '\0';
  local_e0[0xd] = '\0';
  local_e0[0xe] = '\0';
  local_e0[0xf] = '\0';
  local_d0 = 0;
  memset(&local_cc,0,0xa8);
  memset(&local_cc,0,0xa8);
  local_cc = 0xffffffff;
  iVar1 = json_object_object_get(param_1,"id");
  if (iVar1 == 0) {
    iVar1 = -1;
    if (macauth_err_switch == 0) goto LAB_00450be0;
    uVar3 = 0x169;
    pcVar5 = "id";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar6 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_mac_jcs_set",0x16a);
        }
      }
    }
    iVar2 = mac_auth_db_mac_entry_get(iVar1,&local_cc);
    if (iVar2 != 0) {
      iVar2 = -1;
      iVar1 = iVar2;
      if (macauth_err_switch == 0) goto LAB_00450be0;
      pcVar5 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_entry_get() failed.\n";
      uVar3 = 0x16e;
LAB_00450d5c:
      printf(pcVar5,"_uac_mac_auth_mac_jcs_set",uVar3);
      iVar1 = iVar2;
      goto LAB_00450be0;
    }
    iVar2 = json_object_object_get(param_1,"name");
    if (iVar2 == 0) {
      iVar1 = -1;
      if (macauth_err_switch == 0) goto LAB_00450be0;
      uVar3 = 0x173;
      pcVar5 = "name";
    }
    else {
      iVar4 = json_object_get_type(iVar2);
      if (iVar4 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar2);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_mac_jcs_set",0x174);
        }
        pcVar5 = "";
      }
      strncpy(acStack_c8,pcVar5,0x9b);
      local_2d = 0;
      iVar2 = json_object_object_get(param_1,"mac");
      if (iVar2 != 0) {
        iVar4 = json_object_get_type(iVar2);
        if (iVar4 == 6) {
          pcVar5 = (char *)json_object_get_string(iVar2);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_mac_auth_mac_jcs_set",0x178);
          }
          pcVar5 = "";
        }
        strncpy(local_e0,pcVar5,0x13);
        local_d0 = local_d0 & 0xffffff00;
        iVar2 = mac_auth_mac_parse(local_e0,auStack_2c);
        if (iVar2 == 0) {
          iVar2 = mac_auth_db_mac_entry_set(&local_cc);
          if (iVar2 == 0) {
            _uac_mac_auth_sta_check_trigger();
            goto LAB_00450be0;
          }
          iVar1 = iVar2;
          if (macauth_err_switch == 0) goto LAB_00450be0;
          pcVar5 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_set() failed.\n";
          uVar3 = 0x181;
        }
        else {
          iVar2 = -1;
          iVar1 = iVar2;
          if (macauth_err_switch == 0) goto LAB_00450be0;
          pcVar5 = "[MACAUTH_ERROR]%s()/%d mac_auth_mac_parse() failed.\n";
          uVar3 = 0x17b;
        }
        goto LAB_00450d5c;
      }
      iVar1 = -1;
      if (macauth_err_switch == 0) goto LAB_00450be0;
      uVar3 = 0x177;
      pcVar5 = "mac";
    }
  }
  iVar1 = -1;
  printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_mac_jcs_set",uVar3,pcVar5);
LAB_00450be0:
  uVar3 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"id",uVar3);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_mac_jcs_set() finish, id=%d.\n",
           "_uac_mac_auth_mac_jcs_set",0x189,iVar1);
  }
  return;
}

