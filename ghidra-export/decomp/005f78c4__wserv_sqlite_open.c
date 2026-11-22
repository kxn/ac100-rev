// func _wserv_sqlite_open @ 005f78c4 size=128

undefined4 _wserv_sqlite_open(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_00408130(param_1,param_2,uac_cfg_trigger_changed_by_restore);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, g_wserv_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[error]%s(): %d  -> sqlite3_open() fail, path=%s\r\n","_wserv_sqlite_open",0x1fa,
           param_1);
  }
  return uVar2;
}

