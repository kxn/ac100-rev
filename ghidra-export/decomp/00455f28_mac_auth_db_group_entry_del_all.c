// func mac_auth_db_group_entry_del_all @ 00455f28 size=208

undefined4 mac_auth_db_group_entry_del_all(void)

{
  uint uVar1;
  
  uVar1 = 0;
  FUN_004082d0(DAT_00766ff8,0xffffffff);
  while (uVar1 < DAT_00766fe8) {
    if (*(int *)(DAT_00767024 + uVar1 * 0x188 + 0xc) == -1) {
      uVar1 = uVar1 + 1;
    }
    else {
      FUN_00408500();
      _mac_auth_db_group_entry_reset(uVar1);
      FUN_004080f0(DAT_00767000,uVar1);
      uVar1 = uVar1 + 1;
    }
  }
  memset(DAT_00767018,-1,(DAT_00766fec + 1) * 4);
  FUN_00407f30(DAT_00766ff8);
  return 0;
}

