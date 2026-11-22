// func wserv_sqlite_table_exists @ 005f8f60 size=480

undefined4 wserv_sqlite_table_exists(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  int local_14;
  
  local_14 = 0;
  iVar1 = access(param_1,0);
  if (iVar1 == -1) {
    if (g_wserv_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("<wserv>[debug]%s(): %d  -> db file[%s] not exists.\r\n","wserv_sqlite_table_exists",
           0x581,param_1);
    return 0;
  }
  iVar1 = _wserv_sqlite_open(param_1,&local_14);
  if (iVar1 == 0) {
    iVar1 = FUN_00408100(local_14,"SELECT 1 FROM sqlite_master where type=\'table\' and name=?",
                         0xffffffff,&local_18,0);
    if (iVar1 == 0) {
      sqlite3_bind_text(local_18,1,param_2,0xffffffff,0xffffffff);
      uVar2 = 1;
      iVar1 = FUN_004083f0(local_18);
      if ((((iVar1 != 100) && (uVar2 = 0, iVar1 != 0x65)) && (g_wserv_error != 0)) &&
         (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> wserv_sqlite_table_exists fail\r\n",
               "wserv_sqlite_table_exists",0x5a1);
      }
      FUN_004084a0(local_18);
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
           "wserv_sqlite_table_exists",0x588,param_1);
  }
  uVar2 = 0;
LAB_005f8fb8:
  if (local_14 != 0) {
    FUN_004080b0();
  }
  return uVar2;
}

