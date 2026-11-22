// func mac_auth_db_mac_entry_get @ 0045346c size=308

undefined4 mac_auth_db_mac_entry_get(uint param_1,void *param_2)

{
  char *__format;
  undefined4 uVar1;
  
  if (param_2 == (void *)0x0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid mac entry.\n";
      uVar1 = 0x4d6;
LAB_00453568:
      printf(__format,"mac_auth_db_mac_entry_get",uVar1,param_1);
      return 0xffffffff;
    }
  }
  else if (((int)param_1 < 0) || (g_mac_auth_profile <= param_1)) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid mac entry id[%d].\n","mac_auth_db_mac_entry_get",0x4dc,
             param_1);
      return 0xffffffff;
    }
  }
  else {
    if (*(int *)(DAT_00767020 + param_1 * 0xa8) != -1) {
      FUN_004082d0(DAT_00766ff4,0xffffffff);
      memcpy(param_2,(void *)(DAT_00767020 + param_1 * 0xa8),0xa8);
      FUN_00407f30(DAT_00766ff4);
      return 0;
    }
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d mac entry is not used.\n";
      uVar1 = 0x4e2;
      goto LAB_00453568;
    }
  }
  return 0xffffffff;
}

