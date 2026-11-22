// func mac_auth_db_group_entry_del @ 00455db8 size=368

undefined4 mac_auth_db_group_entry_del(uint param_1,void *param_2)

{
  char *__format;
  undefined4 uVar1;
  
  if (param_2 == (void *)0x0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid bind_vlan.\n";
      uVar1 = 0x732;
LAB_00455ef0:
      printf(__format,"mac_auth_db_group_entry_del",uVar1);
      return 0xffffffff;
    }
  }
  else if (((int)param_1 < 0) || (DAT_00766fe8 <= param_1)) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid group id[%d].\n","mac_auth_db_group_entry_del",0x738,
             param_1);
      return 0xffffffff;
    }
  }
  else {
    if (*(int *)(DAT_00767024 + param_1 * 0x188 + 0xc) != -1) {
      FUN_004082d0(DAT_00766ff8,0xffffffff);
      FUN_00408500(DAT_00767024 + param_1 * 0x188);
      _mac_auth_db_group_entry_reset(param_1);
      memcpy(DAT_00767018,param_2,(DAT_00766fec + 1) * 4);
      FUN_004080f0(DAT_00767000,param_1);
      FUN_00407f30(DAT_00766ff8);
      return 0;
    }
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d group entry is not used.\n";
      uVar1 = 0x73e;
      goto LAB_00455ef0;
    }
  }
  return 0xffffffff;
}

