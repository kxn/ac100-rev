// func mac_auth_db_group_entry_add_for_ssid @ 00455b18 size=480

undefined4 mac_auth_db_group_entry_add_for_ssid(int param_1,void *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = 0xffffffff;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid group entry.\n","mac_auth_db_group_entry_add_for_ssid",
             0x700);
    }
  }
  else {
    FUN_004082d0(DAT_00766ff8,0xffffffff);
    uVar1 = FUN_004085b0(DAT_00767004);
    if (uVar1 == 0xffffffff) {
      uVar4 = 0xffffffff;
      if (macauth_err_switch != 0) {
        printf("[MACAUTH_ERROR]%s()/%d uac_id_alloc() failed.\n",
               "mac_auth_db_group_entry_add_for_ssid",0x709);
      }
    }
    else if (((int)uVar1 < 0) || (DAT_00766fe8 <= uVar1)) {
      uVar4 = 0xffffffff;
      if (macauth_err_switch != 0) {
        printf("[MACAUTH_ERROR]%s()/%d Invalid group id(%d).\n",
               "mac_auth_db_group_entry_add_for_ssid",0x70f,uVar1);
      }
    }
    else {
      iVar3 = uVar1 * 0x188;
      *(undefined4 *)(DAT_00767024 + iVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      iVar2 = DAT_00767024 + iVar3;
      *(undefined4 *)(iVar2 + 0x184) = *(undefined4 *)(param_1 + 0x184);
      memcpy((void *)(iVar2 + 0x14),(void *)(param_1 + 0x14),0x9c);
      memcpy((void *)(DAT_00767024 + iVar3 + 0xb0),(void *)(param_1 + 0xb0),0x9c);
      memcpy(*(void **)(DAT_00767024 + iVar3 + 0x180),param_2,(g_mac_auth_profile + 0x1fU >> 5) << 2
            );
      FUN_004086b0(&DAT_0076700c,DAT_00767024 + iVar3);
      uVar4 = 0;
      *(uint *)(DAT_00767024 + iVar3 + 0xc) = uVar1;
      *(uint *)(param_1 + 0xc) = uVar1;
    }
    FUN_00407f30(DAT_00766ff8);
  }
  return uVar4;
}

