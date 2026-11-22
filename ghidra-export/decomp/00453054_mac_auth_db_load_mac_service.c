// func mac_auth_db_load_mac_service @ 00453054 size=480

undefined4 mac_auth_db_load_mac_service(uint *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == (uint *)0x0) {
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[MACAUTH_ERROR]%s()/%d Invalid mac entry.\n","mac_auth_db_load_mac_service",0x3d9);
    return 0xffffffff;
  }
  if (((int)*param_1 < 0) || (g_mac_auth_profile <= *param_1)) {
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[MACAUTH_ERROR]%s()/%d Invalid mac entry Id(%d).\n","mac_auth_db_load_mac_service",0x3df
          );
    return 0xffffffff;
  }
  FUN_004082d0(DAT_00766ff4,0xffffffff);
  *(uint *)(DAT_00767020 + *param_1 * 0xa8) = *param_1;
  memcpy((void *)(DAT_00767020 + *param_1 * 0xa8 + 4),param_1 + 1,0x9c);
  memcpy((void *)(DAT_00767020 + *param_1 * 0xa8 + 0xa0),param_1 + 0x28,6);
  FUN_00408440(DAT_00766ffc,*param_1);
  iVar1 = FUN_00407fa0(DAT_00767008,param_1 + 0x28);
  if (iVar1 == 0) {
    uVar3 = 0;
    iVar1 = FUN_00408380(DAT_00767008,DAT_00767020 + *param_1 * 0xa8);
    if (iVar1 == 0) goto LAB_00453184;
    if (macauth_err_switch != 0) {
      __format = "[MACAUTH_ERROR]%s()/%d uac_hash_add() mac id(%d) failed.\n";
      uVar2 = 0x3ef;
      goto LAB_004531d8;
    }
  }
  else if (macauth_err_switch != 0) {
    __format = "[MACAUTH_ERROR]%s()/%d Invalid db data, duplicate mac address of id(%d).\n";
    uVar2 = 0x3ea;
LAB_004531d8:
    uVar3 = 0xffffffff;
    printf(__format,"mac_auth_db_load_mac_service",uVar2,*param_1);
    goto LAB_00453184;
  }
  uVar3 = 0xffffffff;
LAB_00453184:
  FUN_00407f30(DAT_00766ff4);
  return uVar3;
}

