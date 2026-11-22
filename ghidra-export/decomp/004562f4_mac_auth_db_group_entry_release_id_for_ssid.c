// func mac_auth_db_group_entry_release_id_for_ssid @ 004562f4 size=196

undefined4 mac_auth_db_group_entry_release_id_for_ssid(uint param_1)

{
  undefined4 uVar1;
  
  if (((int)param_1 < 0) || (DAT_00766fe8 <= param_1)) {
    uVar1 = 0xffffffff;
    if (macauth_debug_switch != 0) {
      printf("[MACAUTH_DEBUG]%s()/%d Invalid group id[%d].\n",
             "mac_auth_db_group_entry_release_id_for_ssid",0x7a4,param_1);
    }
  }
  else {
    FUN_004082d0(DAT_00766ff8,0xffffffff);
    FUN_00408500(DAT_00767024 + param_1 * 0x188);
    FUN_004080f0(DAT_00767004,param_1);
    _mac_auth_db_group_entry_reset(param_1);
    uVar1 = 0;
    FUN_00407f30(DAT_00766ff8);
  }
  return uVar1;
}

