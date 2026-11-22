// func _uac_mac_auth_mac_jcs_del @ 00450ecc size=428

void _uac_mac_auth_mac_jcs_del(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  iVar1 = json_object_object_get(param_1,"id");
  if (iVar1 == 0) {
    uVar4 = 0xffffffff;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_mac_jcs_del",0x135,"id");
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar5 = json_object_get_double(iVar1);
        uVar3 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      }
      else {
        uVar3 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_mac_jcs_del",0x136);
        }
      }
    }
    if (macauth_debug_switch != 0) {
      printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_mac_jcs_del() begin, id=%d.\n",
             "_uac_mac_auth_mac_jcs_del",0x138,uVar3);
    }
    iVar1 = mac_auth_db_mac_entry_del(uVar3);
    uVar4 = 0xffffffff;
    if (iVar1 == 0) {
      uVar4 = uVar3;
    }
    _uac_mac_auth_sta_check_trigger();
  }
  uVar3 = json_object_new_int(uVar4);
  json_object_object_add(param_2,"id",uVar3);
  if (macauth_debug_switch == 0) {
    return;
  }
  printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_mac_jcs_del() finish, id=%d.\n",
         "_uac_mac_auth_mac_jcs_del",0x141,uVar4);
  return;
}

