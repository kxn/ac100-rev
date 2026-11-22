// func mac_auth_db_mac_entry_add @ 00453aa8 size=524

undefined4 mac_auth_db_mac_entry_add(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 == (uint *)0x0) {
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[MACAUTH_ERROR]%s()/%d Invalid mac entry.\n","mac_auth_db_mac_entry_add",0x561);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_00766ff4,0xffffffff);
  puVar1 = (uint *)FUN_00407fa0(DAT_00767008,param_1 + 0x28);
  if (puVar1 == (uint *)0x0) {
    uVar2 = FUN_004085b0(DAT_00766ffc);
    if (uVar2 == 0xffffffff) {
      uVar4 = 0xffffffff;
      if (macauth_err_switch != 0) {
        printf("[MACAUTH_ERROR]%s()/%d uac_id_alloc() failed.\n","mac_auth_db_mac_entry_add",0x574);
      }
    }
    else {
      if (((int)uVar2 < 0) || (g_mac_auth_profile <= uVar2)) {
        uVar4 = 0xffffffff;
        if (macauth_err_switch == 0) goto LAB_00453b20;
        __format = "[MACAUTH_ERROR]%s()/%d Invalid mac id(%d).\n";
        uVar3 = 0x57a;
      }
      else {
        iVar5 = uVar2 * 0xa8;
        *(uint *)(DAT_00767020 + iVar5) = uVar2;
        *param_1 = uVar2;
        memcpy((void *)(DAT_00767020 + iVar5 + 4),param_1 + 1,0x9c);
        memcpy((void *)(DAT_00767020 + iVar5 + 0xa0),param_1 + 0x28,6);
        uVar4 = 0;
        iVar5 = FUN_00408380(DAT_00767008,DAT_00767020 + iVar5);
        if ((iVar5 == 0) || (uVar4 = 0xffffffff, macauth_err_switch == 0)) goto LAB_00453b20;
        __format = "[MACAUTH_ERROR]%s()/%d uac_hash_add() failed, mac_id:%d\n";
        uVar3 = 0x585;
      }
      uVar4 = 0xffffffff;
      printf(__format,"mac_auth_db_mac_entry_add",uVar3,uVar2);
    }
  }
  else {
    if (macauth_debug_switch == 0) {
      uVar2 = *puVar1;
    }
    else {
      printf("[MACAUTH_DEBUG]%s()/%d duplicate mac address.\n","mac_auth_db_mac_entry_add",0x56a);
      uVar2 = *puVar1;
    }
    uVar4 = 0xfffffffe;
    *param_1 = uVar2;
  }
LAB_00453b20:
  FUN_00407f30(DAT_00766ff4);
  return uVar4;
}

