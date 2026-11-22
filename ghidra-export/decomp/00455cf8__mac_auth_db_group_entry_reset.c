// func _mac_auth_db_group_entry_reset @ 00455cf8 size=192

void _mac_auth_db_group_entry_reset(int param_1)

{
  int iVar1;
  
  param_1 = param_1 * 0x188;
  *(undefined4 *)(DAT_00767024 + param_1 + 0xc) = 0xffffffff;
  *(undefined4 *)(DAT_00767024 + param_1 + 0x10) = 0;
  iVar1 = DAT_00767024 + param_1;
  *(undefined4 *)(iVar1 + 0x184) = 0;
  memset((void *)(iVar1 + 0x14),0,0x9c);
  memset((void *)(DAT_00767024 + param_1 + 0xb0),0,0x9c);
  memset((void *)(DAT_00767024 + param_1 + 0x14c),0,0x33);
  memset(*(void **)(DAT_00767024 + param_1 + 0x180),0,(g_mac_auth_profile + 0x1fU >> 5) << 2);
  return;
}

