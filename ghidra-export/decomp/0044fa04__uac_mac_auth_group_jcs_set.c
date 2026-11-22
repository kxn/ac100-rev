// func _uac_mac_auth_group_jcs_set @ 0044fa04 size=456

void _uac_mac_auth_group_jcs_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = json_object_object_get(param_1,"operation");
  if (iVar1 == 0) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_group_jcs_set",0x4dc,
             "operation");
      return;
    }
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    iVar1 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 != 2) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_mac_auth_group_jcs_set",0x4dd);
      }
      goto LAB_0044fa74;
    }
    uVar4 = json_object_get_double(iVar1);
    iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
  }
  if (-1 < iVar1) {
    if (iVar1 < 2) {
      _uac_mac_auth_group_jcs_op(param_1,param_2);
      return;
    }
    if (iVar1 == 2) {
      _uac_mac_auth_group_jcs_modify(param_1,param_2);
      return;
    }
  }
LAB_0044fa74:
  if (macauth_err_switch != 0) {
    printf("[MACAUTH_ERROR]%s()/%d Invalid operaiton.\n","_uac_mac_auth_group_jcs_set",0x4e9);
  }
  uVar3 = json_object_new_int(0xffffffff);
  json_object_object_add(param_2,"result",uVar3);
  return;
}

