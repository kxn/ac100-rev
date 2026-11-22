// func _uac_mac_auth_wservice_del_callback @ 0044c9c4 size=380

undefined4 _uac_mac_auth_wservice_del_callback(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *__s;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_wservice_del_callback() begin.\n",
           "_uac_mac_auth_wservice_del_callback",0xdd);
  }
  if (g_macauth_mode != 0) {
    return 0;
  }
  if ((int)param_1 < 0) {
    return 0xffffffff;
  }
  uVar1 = wserv_profile_get_max_wservice();
  if (uVar1 <= param_1) {
    return 0xffffffff;
  }
  uVar2 = wserv_profile_get_max_wservice();
  __s = (void *)FUN_004082a0(uVar2,4,0xe4);
  iVar3 = wserv_profile_get_max_wservice();
  memset(__s,-1,iVar3 << 2);
  if (__s == (void *)0x0) {
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_wservice_del_callback",0xe8);
    return 0xffffffff;
  }
  iVar3 = mac_auth_db_get_bind_ssid(__s);
  if (iVar3 == 0) {
    *(undefined4 *)((int)__s + param_1 * 4) = 0xffffffff;
    uVar2 = 0;
    iVar3 = mac_auth_db_set_bind_ssid(__s);
    if ((iVar3 == 0) || (uVar2 = 0xffffffff, macauth_err_switch == 0)) goto LAB_0044ca68;
    __format = "[MACAUTH_ERROR]%s()/%d mac_auth_db_set_bind_ssid() failed.\n";
    uVar4 = 0xf3;
  }
  else {
    uVar2 = 0xffffffff;
    if (macauth_err_switch == 0) goto LAB_0044ca68;
    __format = "[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_ssid() failed.\n";
    uVar4 = 0xed;
  }
  uVar2 = 0xffffffff;
  printf(__format,"_uac_mac_auth_wservice_del_callback",uVar4);
LAB_0044ca68:
  FUN_00407df0(__s);
  return uVar2;
}

