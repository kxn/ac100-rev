// func mac_auth_db_group_entry_status_set @ 004557e8 size=312

undefined4 mac_auth_db_group_entry_status_set(int param_1)

{
  char *__format;
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid group entry.\n";
      uVar1 = 0x6b4;
LAB_004558e8:
      printf(__format,"mac_auth_db_group_entry_status_set",uVar1);
      return 0xffffffff;
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xc);
    if (((int)uVar2 < 0) || (DAT_00766fe8 <= uVar2)) {
      if (macauth_err_switch != 0) {
        printf("[MACAUTH_ERROR]%s()/%d Invalid group entry id[%d].\n",
               "mac_auth_db_group_entry_status_set",0x6ba);
        return 0xffffffff;
      }
    }
    else {
      if (*(int *)(DAT_00767024 + uVar2 * 0x188 + 0xc) != -1) {
        FUN_004082d0(DAT_00766ff8,0xffffffff);
        uVar1 = DAT_00766ff8;
        *(undefined4 *)(DAT_00767024 + *(int *)(param_1 + 0xc) * 0x188 + 0x10) =
             *(undefined4 *)(param_1 + 0x10);
        FUN_00407f30(uVar1);
        return 0;
      }
      if (macauth_err_switch != 0) {
        __format = "[MACAUTH_ERROR]%s()/%d group entry is not used.\n";
        uVar1 = 0x6c0;
        goto LAB_004558e8;
      }
    }
  }
  return 0xffffffff;
}

