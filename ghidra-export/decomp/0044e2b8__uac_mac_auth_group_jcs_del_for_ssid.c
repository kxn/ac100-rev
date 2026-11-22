// func _uac_mac_auth_group_jcs_del_for_ssid @ 0044e2b8 size=936

void _uac_mac_auth_group_jcs_del_for_ssid(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 local_5b0;
  undefined1 auStack_5ac [16];
  int local_59c;
  char acStack_424 [1025];
  undefined1 local_23;
  
  local_5b0 = 0;
  memset(acStack_424,0,0x402);
  memset(auStack_5ac,0,0x188);
  iVar1 = json_object_object_get(param_1,"id");
  if (iVar1 == 0) {
    if (macauth_err_switch == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_group_jcs_del_for_ssid",0x30e,
             "id");
      uVar3 = 0xffffffff;
    }
    goto LAB_0044e3f8;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    uVar7 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar8 = json_object_get_double(iVar1);
      uVar7 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
    else {
      uVar7 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_mac_auth_group_jcs_del_for_ssid",0x30f);
      }
    }
  }
  uVar3 = wserv_profile_get_max_wservice();
  iVar1 = FUN_004082a0(uVar3,4,0x310);
  if (iVar1 == 0) {
    if (macauth_err_switch == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_del_for_ssid",0x313);
      uVar3 = 0xffffffff;
    }
    goto LAB_0044e3f8;
  }
  iVar2 = json_object_object_get(param_1,"serv_id_map");
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
    if (macauth_err_switch != 0) {
      pcVar5 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
      uVar7 = 0x317;
      pcVar6 = "serv_id_map";
LAB_0044e5a4:
      uVar3 = 0xffffffff;
      printf(pcVar5,"_uac_mac_auth_group_jcs_del_for_ssid",uVar7,pcVar6);
    }
  }
  else {
    iVar4 = json_object_get_type(iVar2);
    if (iVar4 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_mac_auth_group_jcs_del_for_ssid",0x318);
      }
      pcVar5 = "";
    }
    strncpy(acStack_424,pcVar5,0x401);
    local_23 = 0;
    iVar2 = mac_auth_db_get_bind_ssid(iVar1);
    if (iVar2 == 0) {
      iVar2 = mac_auth_bind_ssid(acStack_424,iVar1,1,&local_5b0,0xffffffff,1);
      if (iVar2 == 0) {
        if (macauth_debug_switch != 0) {
          printf("[MACAUTH_DEBUG]%s()/%d mac_auth_db_group_entry_del_for_ssid() begin, id=%d.\n",
                 "_uac_mac_auth_group_jcs_del_for_ssid",0x323,uVar7);
        }
        iVar2 = mac_auth_db_group_entry_get(uVar7,auStack_5ac);
        uVar3 = 0xffffffff;
        if ((iVar2 == 0) && (iVar2 = mac_auth_db_group_entry_del_for_ssid(uVar7,iVar1), iVar2 == 0))
        {
          uVar3 = uVar7;
        }
        if (local_59c != 0) {
          _uac_mac_auth_sta_check_trigger();
        }
      }
      else {
        uVar3 = 0xffffffff;
        if (macauth_err_switch != 0) {
          pcVar5 = "[MACAUTH_ERROR]%s()/%d parse ssid str %s failed.\n";
          uVar7 = 800;
          pcVar6 = acStack_424;
          goto LAB_0044e5a4;
        }
      }
    }
    else {
      uVar3 = 0xffffffff;
      if (macauth_err_switch != 0) {
        printf("[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_ssid() failed.\n",
               "_uac_mac_auth_group_jcs_del_for_ssid",0x31b);
      }
    }
  }
  FUN_00407df0(iVar1);
LAB_0044e3f8:
  uVar7 = json_object_new_int(uVar3);
  json_object_object_add(param_2,"id",uVar7);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_del() finish, id=%d.\n",
           "_uac_mac_auth_group_jcs_del_for_ssid",0x333,uVar3);
  }
  return;
}

