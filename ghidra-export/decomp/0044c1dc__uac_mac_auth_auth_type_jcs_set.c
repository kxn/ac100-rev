// func _uac_mac_auth_auth_type_jcs_set @ 0044c1dc size=584

void _uac_mac_auth_auth_type_jcs_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *__s2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  iVar1 = json_object_object_get(param_1,"auth_mode");
  if (iVar1 == 0) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_auth_type_jcs_set",0x522,
             "auth_mode");
      return;
    }
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 6) {
    iVar2 = 0;
    while (iVar2 < auth_mode_map) {
      pcVar6 = *(char **)(PTR__mt_auth_mode_007313a4 + iVar2 * 0x10);
      if (pcVar6 == (char *)0x0) {
        iVar2 = iVar2 + 1;
      }
      else {
        __s2 = (char *)json_object_get_string(iVar1);
        iVar3 = strcmp(pcVar6,__s2);
        if (iVar3 == 0) {
          uVar4 = *(uint *)(PTR__mt_auth_mode_007313a4 + iVar2 * 0x10 + 0xc);
          goto LAB_0044c250;
        }
        iVar2 = iVar2 + 1;
      }
    }
    if (jcs_err_switch != 0) {
      pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0044c2f4:
      printf(pcVar6,"_uac_mac_auth_auth_type_jcs_set",0x523);
    }
  }
  else if (jcs_err_switch != 0) {
    pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
    goto LAB_0044c2f4;
  }
  if (jcs_err_switch == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
           "_uac_mac_auth_auth_type_jcs_set",0x523);
    uVar4 = 0xffffffff;
  }
LAB_0044c250:
  if (g_macauth_mode != uVar4) {
    if (1 < uVar4) {
      if (macauth_err_switch == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        printf("[MACAUTH_ERROR]%s()/%d Invalid value.\n","_uac_mac_auth_auth_type_jcs_set",0x536);
        uVar5 = 0xffffffff;
      }
      goto LAB_0044c280;
    }
    g_macauth_mode = uVar4;
    if (uVar4 != 0) {
      mac_auth_db_group_entry_del_all_for_ssid();
      uVar5 = 0;
      goto LAB_0044c280;
    }
    mac_auth_db_group_entry_del_all();
  }
  uVar5 = 0;
LAB_0044c280:
  uVar5 = json_object_new_int(uVar5);
  json_object_object_add(param_2,"result",uVar5);
  return;
}

