// func mac_auth_db_group_entry_del_all_for_ssid @ 00455ff8 size=212

undefined4 mac_auth_db_group_entry_del_all_for_ssid(void)

{
  void *__s;
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  FUN_004082d0(DAT_00766ff8,0xffffffff);
  while (__s = DAT_0076701c, uVar2 < DAT_00766fe8) {
    if (*(int *)(DAT_00767024 + uVar2 * 0x188 + 0xc) == -1) {
      uVar2 = uVar2 + 1;
    }
    else {
      FUN_00408500();
      _mac_auth_db_group_entry_reset(uVar2);
      FUN_004080f0(DAT_00767004,uVar2);
      uVar2 = uVar2 + 1;
    }
  }
  iVar1 = wserv_profile_get_max_wservice();
  memset(__s,-1,iVar1 << 2);
  FUN_00407f30(DAT_00766ff8);
  return 0;
}

