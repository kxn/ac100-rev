// func wserv_sqlite_load_service @ 005f89a0 size=384

undefined4 wserv_sqlite_load_service(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_818;
  char acStack_814 [2056];
  
  local_818 = 0;
  memset(acStack_814,0,0x800);
  iVar1 = _wserv_sqlite_try_create_tbl();
  if (iVar1 == 0) {
    iVar1 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv.db",&local_818);
    if (iVar1 == 0) {
      snprintf(acStack_814,0x800,"select * from wserv_tbl");
      iVar1 = FUN_00407fb0(local_818,acStack_814,_wserv_for_each_cb,0);
      if (iVar1 == 0) {
        uVar3 = 0;
        goto LAB_005f89e8;
      }
      iVar2 = FUN_00408410();
      if (iVar2 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
               "wserv_sqlite_load_service",0x500,iVar1,acStack_814,"select wserv fail");
        goto LAB_005f8a3c;
      }
    }
    else if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> sqlite3_open() fail, path=%s\r\n",
             "wserv_sqlite_load_service",0x4fb,"/etc/nouci_config/dbs/wserv.db");
      goto LAB_005f8a3c;
    }
  }
  else if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[error]%s(): %d  -> _wserv_sqlite_try_create_tbl() fail.\r\n",
           "wserv_sqlite_load_service",0x4f4);
LAB_005f8a3c:
    uVar3 = 0xffffffff;
    goto LAB_005f89e8;
  }
  uVar3 = 0xffffffff;
LAB_005f89e8:
  if (local_818 != 0) {
    FUN_004080b0();
  }
  return uVar3;
}

