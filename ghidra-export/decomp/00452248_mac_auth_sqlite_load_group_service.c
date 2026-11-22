// func mac_auth_sqlite_load_group_service @ 00452248 size=592

undefined4 mac_auth_sqlite_load_group_service(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int local_428;
  int local_424 [5];
  char acStack_410 [1024];
  
  local_424[0] = 0;
  local_424[1] = 0;
  local_424[2] = 0;
  local_424[3] = 0;
  local_424[4] = 0;
  memset(acStack_410,0,0x400);
  if (g_macauth_mode != 1) {
    return 0;
  }
  iVar1 = FUN_004521a4();
  if (iVar1 != 0) {
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[MACAUTH_ERROR]%s()/%d Create table failed.\n","mac_auth_sqlite_load_group_service",
           0x36c);
    return 0xffffffff;
  }
  iVar1 = FUN_00408130("/etc/nouci_config/dbs/mac_auth.db",&local_428,0);
  if (iVar1 != 0) goto LAB_00452314;
  local_424[0] = FUN_00451e18(DAT_00766fec + 1);
  if (local_424[0] == 0) {
    if (macauth_err_switch == 0) goto LAB_00452314;
    __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
    uVar3 = 0x376;
  }
  else {
    local_424[2] = FUN_00451e18(g_mac_auth_profile + 0x1fU >> 5);
    if (local_424[0] == 0) {
      if (macauth_err_switch == 0) goto LAB_00452314;
      __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
      uVar3 = 0x37c;
    }
    else {
      snprintf(acStack_410,0x400,"select * from %s","macAuthGroupTable");
      iVar1 = FUN_00407fb0(local_428,acStack_410,mac_auth_sqlite_group_cb,local_424);
      if (iVar1 != 0) {
        iVar2 = FUN_00408410();
        if (iVar2 != 0) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "mac_auth_sqlite_load_group_service",899,iVar1,acStack_410,
                 "Failed to read database, select failed.");
        }
        goto LAB_00452314;
      }
      if (macauth_debug_switch == 0) goto LAB_00452314;
      __format = "[MACAUTH_DEBUG]%s()/%d mac_auth_sqlite_load_group_servicec() OK.\n";
      uVar3 = 0x385;
    }
  }
  printf(__format,"mac_auth_sqlite_load_group_service",uVar3);
LAB_00452314:
  if (local_428 != 0) {
    FUN_004080b0();
    local_428 = 0;
  }
  if (local_424[0] != 0) {
    FUN_00407df0();
    local_424[0] = 0;
  }
  uVar3 = 0xffffffff;
  if (local_424[2] != 0) {
    FUN_00407df0();
  }
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  return uVar3;
}

