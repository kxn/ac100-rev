// func mac_auth_db_group_entry_get_by_vid @ 004569cc size=396

undefined4 mac_auth_db_group_entry_get_by_vid(uint param_1,void *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_2 == (void *)0x0) {
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid group entry.\n";
      uVar2 = 0x87d;
      goto LAB_00456a50;
    }
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_00766fec + 1U)) {
      FUN_004082d0(DAT_00766ff8,0xffffffff);
      iVar1 = *(int *)(DAT_00767018 + param_1 * 4);
      if (iVar1 == -1) {
        uVar2 = 0xffffffff;
        if (macauth_debug_switch != 0) {
          printf("[MACAUTH_DEBUG]%s()/%d no group entry binded into vlan(%d).\n",
                 "mac_auth_db_group_entry_get_by_vid",0x88b,param_1);
        }
      }
      else {
        iVar1 = iVar1 * 0x188;
        memcpy(param_2,(void *)(DAT_00767024 + iVar1),0x188);
        uVar2 = 0;
        if ((*(int *)(DAT_00767024 + iVar1 + 0x10) == 0) &&
           (uVar2 = 0xffffffff, macauth_debug_switch != 0)) {
          printf("[MACAUTH_DEBUG]%s()/%d group entry is disabled.\n",
                 "mac_auth_db_group_entry_get_by_vid",0x891);
        }
      }
      FUN_00407f30(DAT_00766ff8);
      return uVar2;
    }
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d Invalid vlan id.\n";
      uVar2 = 0x883;
LAB_00456a50:
      printf(__format,"mac_auth_db_group_entry_get_by_vid",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

