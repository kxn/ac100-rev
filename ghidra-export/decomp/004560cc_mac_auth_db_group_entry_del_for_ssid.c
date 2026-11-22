// func mac_auth_db_group_entry_del_for_ssid @ 004560cc size=356

undefined4 mac_auth_db_group_entry_del_for_ssid(uint param_1,void *param_2)

{
  void *__dest;
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_2 == (void *)0x0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid bind_vlan.\n";
      uVar2 = 0x773;
LAB_004561f8:
      printf(__format,"mac_auth_db_group_entry_del_for_ssid",uVar2);
      return 0xffffffff;
    }
  }
  else if (((int)param_1 < 0) || (DAT_00766fe8 <= param_1)) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid group id[%d].\n","mac_auth_db_group_entry_del_for_ssid"
             ,0x779,param_1);
      return 0xffffffff;
    }
  }
  else {
    if (*(int *)(DAT_00767024 + param_1 * 0x188 + 0xc) != -1) {
      FUN_004082d0(DAT_00766ff8,0xffffffff);
      FUN_00408500(DAT_00767024 + param_1 * 0x188);
      _mac_auth_db_group_entry_reset(param_1);
      __dest = DAT_0076701c;
      iVar1 = wserv_profile_get_max_wservice();
      memcpy(__dest,param_2,iVar1 << 2);
      FUN_004080f0(DAT_00767004,param_1);
      FUN_00407f30(DAT_00766ff8);
      return 0;
    }
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d group entry is not used.\n";
      uVar2 = 0x77f;
      goto LAB_004561f8;
    }
  }
  return 0xffffffff;
}

