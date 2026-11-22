// func mac_auth_db_mac_entry_del @ 00453cb4 size=336

undefined4 mac_auth_db_mac_entry_del(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((int)param_1 < 0) || (g_mac_auth_profile <= param_1)) {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid mac id[%d].\n","mac_auth_db_mac_entry_del",0x596,
             param_1);
      return 0xffffffff;
    }
  }
  else {
    iVar1 = param_1 * 0xa8;
    if (*(int *)(DAT_00767020 + iVar1) != -1) {
      FUN_004082d0(DAT_00766ff4,0xffffffff);
      FUN_00407f40(DAT_00767008,DAT_00767020 + iVar1);
      memset((void *)(DAT_00767020 + iVar1 + 4),0,0x9c);
      puVar2 = (undefined4 *)(DAT_00767020 + iVar1);
      *puVar2 = 0xffffffff;
      *(undefined1 *)(puVar2 + 0x28) = 0;
      *(undefined1 *)((int)puVar2 + 0xa1) = 0;
      *(undefined1 *)((int)puVar2 + 0xa2) = 0;
      *(undefined1 *)((int)puVar2 + 0xa3) = 0;
      *(undefined1 *)(puVar2 + 0x29) = 0;
      *(undefined1 *)((int)puVar2 + 0xa5) = 0;
      FUN_004080f0(DAT_00766ffc,param_1);
      FUN_00407f30(DAT_00766ff4);
      return 0;
    }
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d mac entry is not used.\n","mac_auth_db_mac_entry_del",0x59c);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

