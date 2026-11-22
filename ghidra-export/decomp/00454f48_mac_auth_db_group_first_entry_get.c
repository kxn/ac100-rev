// func mac_auth_db_group_first_entry_get @ 00454f48 size=1

undefined4 mac_auth_db_group_first_entry_get(void *param_1)

{
  void *__src;
  uint uVar1;
  undefined4 uVar2;
  
  if (param_1 == (void *)0x0) {
    uVar2 = 0xffffffff;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid group entry.\n","mac_auth_db_group_first_entry_get",
             0x601);
    }
  }
  else {
    uVar2 = 0xffffffff;
    FUN_004082d0(DAT_00766ff8,0xffffffff);
    __src = (void *)FUN_004081b0(&DAT_0076700c);
    if (__src != (void *)0x0) {
      uVar1 = *(uint *)((int)__src + 0xc);
      if (((int)uVar1 < 0) || (DAT_00766fe8 <= uVar1)) {
        uVar2 = 0xffffffff;
        if (macauth_err_switch != 0) {
          printf("[MACAUTH_ERROR]%s()/%d Invalid group entry id[%d].\n",
                 "mac_auth_db_group_first_entry_get",0x60d);
        }
      }
      else if (*(int *)(DAT_00767024 + uVar1 * 0x188 + 0xc) == -1) {
        if (macauth_err_switch != 0) {
          printf("[MACAUTH_ERROR]%s()/%d group entry is not used.\n",
                 "mac_auth_db_group_first_entry_get",0x612);
        }
      }
      else {
        uVar2 = 0;
        memcpy(param_1,__src,0x188);
      }
    }
    FUN_00407f30(DAT_00766ff8);
  }
  return uVar2;
}

