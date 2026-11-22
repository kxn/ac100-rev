// func mac_auth_db_group_entry_get_by_ssid @ 00456b58 size=396

undefined4 mac_auth_db_group_entry_get_by_ssid(uint param_1,void *param_2)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if (param_2 == (void *)0x0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid group entry.\n";
      uVar3 = 0x8a1;
      goto LAB_00456bd8;
    }
  }
  else {
    if ((-1 < (int)param_1) && (uVar1 = wserv_profile_get_max_wservice(), param_1 < uVar1)) {
      FUN_004082d0(DAT_00766ff8,0xffffffff);
      iVar2 = *(int *)(DAT_0076701c + param_1 * 4);
      if (iVar2 == -1) {
        uVar3 = 0xffffffff;
        if (macauth_debug_switch != 0) {
          printf("[MACAUTH_DEBUG]%s()/%d no group entry binded into vlan(%d).\n",
                 "mac_auth_db_group_entry_get_by_ssid",0x8af,param_1);
        }
      }
      else {
        iVar2 = iVar2 * 0x188;
        memcpy(param_2,(void *)(DAT_00767024 + iVar2),0x188);
        uVar3 = 0;
        if ((*(int *)(DAT_00767024 + iVar2 + 0x10) == 0) &&
           (uVar3 = 0xffffffff, macauth_debug_switch != 0)) {
          printf("[MACAUTH_DEBUG]%s()/%d group entry is disabled.\n",
                 "mac_auth_db_group_entry_get_by_ssid",0x8b5);
        }
      }
      FUN_00407f30(DAT_00766ff8);
      return uVar3;
    }
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid vlan id.\n";
      uVar3 = 0x8a7;
LAB_00456bd8:
      printf(__format,"mac_auth_db_group_entry_get_by_ssid",uVar3);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

