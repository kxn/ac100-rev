// func wserv_db_bind_tbl_exists_in_db @ 005eb17c size=1

undefined4 wserv_db_bind_tbl_exists_in_db(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = 0;
  iVar1 = access("/etc/nouci_config/dbs/wserv_rd.db",0);
  if (iVar1 == -1) {
    if (g_wserv_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("<wserv>[debug]%s(): %d  -> db file[%s] not exists.\r\n","wserv_sqlite_table_exists",
           0x581,"/etc/nouci_config/dbs/wserv_rd.db");
    return 0;
  }
  iVar1 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv_rd.db",&iStack_14);
  if (iVar1 == 0) {
    iVar1 = FUN_00408100(iStack_14,"SELECT 1 FROM sqlite_master where type=\'table\' and name=?",
                         0xffffffff,&uStack_18,0);
    if (iVar1 == 0) {
      sqlite3_bind_text(uStack_18,1,"bind_tbl",0xffffffff,0xffffffff);
      uVar2 = 1;
      iVar1 = FUN_004083f0(uStack_18);
      if ((((iVar1 != 100) && (uVar2 = 0, iVar1 != 0x65)) && (g_wserv_error != 0)) &&
         (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> wserv_sqlite_table_exists fail\r\n",
               "wserv_sqlite_table_exists",0x5a1);
      }
      FUN_004084a0(uStack_18);
      goto LAB_005f8fb8;
    }
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005f8fb4;
    printf("<wserv>[error]%s(): %d  -> wserv_sqlite_table_exists fail\r\n",
           "wserv_sqlite_table_exists",0x590);
  }
  else {
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
LAB_005f8fb4:
      uVar2 = 0;
      goto LAB_005f8fb8;
    }
    printf("<wserv>[error]%s(): %d  -> _wserv_sqlite_open() fail, path=%s\r\n",
           "wserv_sqlite_table_exists",0x588,"/etc/nouci_config/dbs/wserv_rd.db");
  }
  uVar2 = 0;
LAB_005f8fb8:
  if (iStack_14 != 0) {
    FUN_004080b0();
  }
  return uVar2;
}

