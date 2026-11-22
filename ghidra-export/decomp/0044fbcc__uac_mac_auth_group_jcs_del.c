// func _uac_mac_auth_group_jcs_del @ 0044fbcc size=944

void _uac_mac_auth_group_jcs_del(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 local_1e0;
  char acStack_1dc [50];
  undefined1 local_1aa;
  undefined1 auStack_1a8 [16];
  int local_198;
  
  local_1e0 = 0;
  memset(acStack_1dc,0,0x33);
  memset(auStack_1a8,0,0x188);
  iVar1 = json_object_object_get(param_1,"id");
  if (iVar1 == 0) {
    if (macauth_err_switch == 0) {
      uVar4 = 0xffffffff;
      goto LAB_0044fd04;
    }
    uVar5 = 0x2d3;
    pcVar3 = "id";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar6 = json_object_get_double(iVar1);
        uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
      else {
        uVar5 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_group_jcs_del",0x2d4);
        }
      }
    }
    iVar1 = json_object_object_get(param_1,"vlan");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar3 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_group_jcs_del",0x2d8);
        }
        pcVar3 = "";
      }
      strncpy(acStack_1dc,pcVar3,0x32);
      local_1aa = 0;
      iVar1 = mac_auth_profile_get_max_vlan();
      iVar1 = FUN_004082a0(iVar1 + 1,4,0x2da);
      if (iVar1 == 0) {
        if (macauth_err_switch == 0) {
          uVar4 = 0xffffffff;
        }
        else {
          printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_del",0x2dd);
          uVar4 = 0xffffffff;
        }
      }
      else {
        iVar2 = mac_auth_db_get_bind_vlan(iVar1);
        if (iVar2 == 0) {
          iVar2 = mac_auth_bind_vlan(acStack_1dc,iVar1,1,&local_1e0,0xffffffff,1);
          if (iVar2 == 0) {
            if (macauth_debug_switch != 0) {
              printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_del() begin, id=%d.\n",
                     "_uac_mac_auth_group_jcs_del",0x2ed,uVar5);
            }
            iVar2 = mac_auth_db_group_entry_get(uVar5,auStack_1a8);
            uVar4 = 0xffffffff;
            if (((iVar2 == 0) &&
                (iVar2 = mac_auth_db_group_entry_get(uVar5,auStack_1a8), iVar2 == 0)) &&
               (iVar2 = mac_auth_db_group_entry_del(uVar5,iVar1), iVar2 == 0)) {
              uVar4 = uVar5;
            }
            if (local_198 != 0) {
              _uac_mac_auth_sta_check_trigger();
            }
          }
          else {
            uVar4 = 0xffffffff;
            if (macauth_err_switch != 0) {
              printf("[MACAUTH_ERROR]%s()/%d parse vlan str %s failed.\n",
                     "_uac_mac_auth_group_jcs_del",0x2e9,acStack_1dc);
            }
          }
        }
        else {
          uVar4 = 0xffffffff;
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_vlan() failed.\n",
                   "_uac_mac_auth_group_jcs_del",0x2e2);
          }
        }
        FUN_00407df0(iVar1);
      }
      goto LAB_0044fd04;
    }
    if (macauth_err_switch == 0) {
      uVar4 = 0xffffffff;
      goto LAB_0044fd04;
    }
    uVar5 = 0x2d7;
    pcVar3 = "vlan";
  }
  uVar4 = 0xffffffff;
  printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_group_jcs_del",uVar5,pcVar3);
LAB_0044fd04:
  uVar5 = json_object_new_int(uVar4);
  json_object_object_add(param_2,"id",uVar5);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_del() finish, id=%d.\n",
           "_uac_mac_auth_group_jcs_del",0x2fe,uVar4);
  }
  return;
}

