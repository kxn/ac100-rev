// func mac_auth_db_is_group_entry_enable_by_ssid @ 00456d44 size=96

bool mac_auth_db_is_group_entry_enable_by_ssid(int param_1)

{
  int iVar1;
  
  FUN_004082d0(DAT_00766ff8,0xffffffff);
  iVar1 = *(int *)(DAT_0076701c + param_1 * 4);
  FUN_00407f30(DAT_00766ff8);
  return iVar1 == -1;
}

