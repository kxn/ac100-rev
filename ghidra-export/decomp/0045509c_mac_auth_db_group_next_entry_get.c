// func mac_auth_db_group_next_entry_get @ 0045509c size=1

undefined4 mac_auth_db_group_next_entry_get(uint param_1,void *param_2)

{
  void *__src;
  char *__format;
  uint uVar1;
  undefined4 uVar2;
  
  if (param_2 == (void *)0x0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid group entry.\n";
      uVar2 = 0x623;
code_r0x00455208:
      printf(__format,"mac_auth_db_group_next_entry_get",uVar2,param_1);
      return 0xffffffff;
    }
  }
  else if (((int)param_1 < 0) || (DAT_00766fe8 <= param_1)) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid group entry id[%d].\n",
             "mac_auth_db_group_next_entry_get",0x628,param_1);
      return 0xffffffff;
    }
  }
  else {
    if (*(int *)(DAT_00767024 + param_1 * 0x188 + 0xc) != -1) {
      FUN_004082d0(DAT_00766ff8,0xffffffff);
      uVar2 = 0xffffffff;
      __src = (void *)FUN_00408680(DAT_00767024 + param_1 * 0x188);
      if (__src != (void *)0x0) {
        uVar1 = *(uint *)((int)__src + 0xc);
        if (((int)uVar1 < 0) || (DAT_00766fe8 <= uVar1)) {
          uVar2 = 0xffffffff;
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d Invalid group entry id[%d],list size.\n",
                   "mac_auth_db_group_next_entry_get",0x639);
          }
        }
        else if (*(int *)(DAT_00767024 + uVar1 * 0x188 + 0xc) == -1) {
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d group entry is not used.\n",
                   "mac_auth_db_group_next_entry_get",0x63e);
          }
        }
        else {
          memcpy(param_2,__src,0x188);
          uVar2 = 0;
        }
      }
      FUN_00407f30(DAT_00766ff8);
      return uVar2;
    }
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d group entry is not used.\n";
      uVar2 = 0x62d;
      goto code_r0x00455208;
    }
  }
  return 0xffffffff;
}

