// func mac_auth_db_group_entry_set @ 004553c8 size=548

undefined4 mac_auth_db_group_entry_set(int param_1,void *param_2,void *param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint uVar3;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid group entry.\n";
      uVar2 = 0x66b;
LAB_00455598:
      printf(__format,"mac_auth_db_group_entry_set",uVar2);
      return 0xffffffff;
    }
  }
  else {
    uVar3 = *(uint *)(param_1 + 0xc);
    if (((int)uVar3 < 0) || (DAT_00766fe8 <= uVar3)) {
      if (macauth_err_switch != 0) {
        printf("[MACAUTH_ERROR]%s()/%d Invalid group entry id[%d].\n","mac_auth_db_group_entry_set",
               0x671);
        return 0xffffffff;
      }
    }
    else {
      if (*(int *)(DAT_00767024 + uVar3 * 0x188 + 0xc) != -1) {
        FUN_004082d0(DAT_00766ff8,0xffffffff);
        *(undefined4 *)(DAT_00767024 + *(int *)(param_1 + 0xc) * 0x188 + 0x10) =
             *(undefined4 *)(param_1 + 0x10);
        iVar1 = DAT_00767024;
        *(undefined4 *)(DAT_00767024 + *(int *)(param_1 + 0xc) * 0x188 + 0x184) =
             *(undefined4 *)(param_1 + 0x184);
        memcpy((void *)(iVar1 + *(int *)(param_1 + 0xc) * 0x188 + 0x14),(void *)(param_1 + 0x14),
               0x9c);
        memcpy((void *)(DAT_00767024 + *(int *)(param_1 + 0xc) * 0x188 + 0xb0),
               (void *)(param_1 + 0xb0),0x9c);
        memcpy((void *)(DAT_00767024 + *(int *)(param_1 + 0xc) * 0x188 + 0x14c),
               (void *)(param_1 + 0x14c),0x33);
        memcpy(*(void **)(DAT_00767024 + *(int *)(param_1 + 0xc) * 0x188 + 0x180),param_3,
               (g_mac_auth_profile + 0x1fU >> 5) << 2);
        memcpy(DAT_00767018,param_2,(DAT_00766fec + 1) * 4);
        FUN_00407f30(DAT_00766ff8);
        return 0;
      }
      if (macauth_err_switch != 0) {
        __format = "[MACAUTH_ERROR]%s()/%d group entry is not used.\n";
        uVar2 = 0x677;
        goto LAB_00455598;
      }
    }
  }
  return 0xffffffff;
}

