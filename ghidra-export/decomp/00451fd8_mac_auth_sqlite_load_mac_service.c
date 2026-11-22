// func mac_auth_sqlite_load_mac_service @ 00451fd8 size=460

undefined4 mac_auth_sqlite_load_mac_service(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_818;
  char acStack_814 [1024];
  char acStack_414 [1028];
  
  memset(acStack_414,0,0x400);
  memset(acStack_814,0,0x400);
  snprintf(acStack_814,0x400,
           "CREATE TABLE IF NOT EXISTS %s(id          INTEGER,name        VARCHAR(128),mac\t\t\tVARCHAR(128),key\t\t\tINTEGER PRIMARY KEY AUTOINCREMENT)"
           ,"macAuthMacTable");
  iVar1 = FUN_00451e5c("macAuthMacTable",acStack_814,"mac","name");
  if (iVar1 == 0) {
    iVar1 = FUN_00408130("/etc/nouci_config/dbs/mac_auth.db",&local_818,0);
    if (iVar1 == 0) {
      snprintf(acStack_414,0x400,"select * from %s","macAuthMacTable");
      iVar1 = FUN_00407fb0(local_818,acStack_414,mac_auth_sqlite_mac_cb,0);
      if (iVar1 == 0) {
        if (macauth_debug_switch != 0) {
          printf("[MACAUTH_DEBUG]%s()/%d mac_auth_sqlite_load_mac_service() OK.\n",
                 "mac_auth_sqlite_load_mac_service",0x468);
        }
      }
      else {
        iVar3 = FUN_00408410();
        if (iVar3 != 0) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "mac_auth_sqlite_load_mac_service",0x466,iVar1,acStack_414,
                 "Failed to read database, select failed.");
        }
      }
    }
    if (local_818 != 0) {
      FUN_004080b0();
    }
    uVar2 = 0xffffffff;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  else {
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Create table %s failed.\n","mac_auth_sqlite_create_mac_table",
             0x44e,"macAuthMacTable");
    }
    if (macauth_err_switch == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      printf("[MACAUTH_ERROR]%s()/%d Create table failed.\n","mac_auth_sqlite_load_mac_service",
             0x45d);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

