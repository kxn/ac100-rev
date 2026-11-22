// func mac_auth_sqlite_load_group_service_for_ssid @ 00452498 size=672

/* WARNING: Type propagation algorithm not settling */

undefined4 mac_auth_sqlite_load_group_service_for_ssid(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int local_428 [6];
  char acStack_410 [1024];
  
  local_428[1] = 0;
  local_428[2] = 0;
  local_428[3] = 0;
  local_428[4] = 0;
  local_428[5] = 0;
  memset(acStack_410,0,0x400);
  if (g_macauth_mode != 0) {
    return 0;
  }
  iVar1 = FUN_004521a4();
  if (iVar1 != 0) {
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[MACAUTH_ERROR]%s()/%d Create table failed.\n",
           "mac_auth_sqlite_load_group_service_for_ssid",0x3a5);
    return 0xffffffff;
  }
  iVar1 = FUN_00408130("/etc/nouci_config/dbs/mac_auth.db",local_428,0);
  if (iVar1 != 0) goto LAB_00452560;
  uVar3 = wserv_profile_get_max_wservice();
  local_428[2] = FUN_00451e18(uVar3);
  if (local_428[2] == 0) {
    if (macauth_err_switch == 0) goto LAB_00452560;
    __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
    uVar3 = 0x3ad;
  }
  else {
    local_428[3] = FUN_00451e18(g_mac_auth_profile + 0x1fU >> 5);
    if (local_428[3] == 0) {
      if (macauth_err_switch == 0) goto LAB_00452560;
      __format = "[MACAUTH_ERROR]%s()/%d no memory.\n";
      uVar3 = 0x3b3;
    }
    else {
      FUN_00408300(local_428 + 4,local_428 + 5,DAT_00766fe8);
      snprintf(acStack_410,0x400,"select * from %s","macAuthGroupTable");
      iVar1 = FUN_00407fb0(local_428[0],acStack_410,mac_auth_sqlite_group_cb_for_ssid,local_428 + 1)
      ;
      if (iVar1 != 0) {
        iVar2 = FUN_00408410();
        if (iVar2 != 0) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "mac_auth_sqlite_load_group_service_for_ssid",0x3ba,iVar1,acStack_410,
                 "Failed to read database, select failed.");
        }
        goto LAB_00452560;
      }
      iVar2 = FUN_00408490(local_428[4],local_428[5],local_428[0],"macAuthGroupTable","id");
      if (iVar2 != 0) {
        FUN_00407de0(local_428 + 4,local_428 + 5);
        goto LAB_00452560;
      }
      FUN_00407de0(local_428 + 4,local_428 + 5);
      if (macauth_debug_switch == 0) goto LAB_00452560;
      __format = "[MACAUTH_DEBUG]%s()/%d mac_auth_sqlite_load_group_servicec_for_ssid() OK.\n";
      uVar3 = 0x3c1;
    }
  }
  printf(__format,"mac_auth_sqlite_load_group_service_for_ssid",uVar3);
LAB_00452560:
  if (local_428[0] != 0) {
    FUN_004080b0();
    local_428[0] = 0;
  }
  if (local_428[2] != 0) {
    FUN_00407df0();
    local_428[2] = 0;
  }
  uVar3 = 0xffffffff;
  if (local_428[3] != 0) {
    FUN_00407df0();
  }
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  return uVar3;
}

