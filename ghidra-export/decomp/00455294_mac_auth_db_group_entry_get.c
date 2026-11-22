// func mac_auth_db_group_entry_get @ 00455294 size=308

undefined4 mac_auth_db_group_entry_get(uint param_1,void *param_2)

{
  char *__format;
  undefined4 uVar1;
  
  if (param_2 == (void *)0x0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid group entry.\n";
      uVar1 = 0x64e;
LAB_00455390:
      printf(__format,"mac_auth_db_group_entry_get",uVar1,param_1);
      return 0xffffffff;
    }
  }
  else if (((int)param_1 < 0) || (DAT_00766fe8 <= param_1)) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid group entry id[%d].\n","mac_auth_db_group_entry_get",
             0x654,param_1);
      return 0xffffffff;
    }
  }
  else {
    if (*(int *)(DAT_00767024 + param_1 * 0x188 + 0xc) != -1) {
      FUN_004082d0(DAT_00766ff8,0xffffffff);
      memcpy(param_2,(void *)(DAT_00767024 + param_1 * 0x188),0x188);
      FUN_00407f30(DAT_00766ff8);
      return 0;
    }
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d group entry is not used.\n";
      uVar1 = 0x65a;
      goto LAB_00455390;
    }
  }
  return 0xffffffff;
}

