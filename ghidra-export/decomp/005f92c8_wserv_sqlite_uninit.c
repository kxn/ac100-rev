// func wserv_sqlite_uninit @ 005f92c8 size=256

undefined4 wserv_sqlite_uninit(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_007cbfa0 != 0) {
    iVar1 = pthread_kill(DAT_007cbfa4,3);
    if (((iVar1 == 0) || (g_wserv_error == 0)) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      DAT_007cbfa0 = 0;
    }
    else {
      printf("<wserv>[error]%s(): %d  -> pthread_kill() fail, ret = %d.\r\n","wserv_sqlite_uninit",
             0x5f6,iVar1);
      DAT_007cbfa0 = 0;
    }
  }
  while (iVar1 = FUN_004081b0(&DAT_007cbf8c), iVar1 != 0) {
    FUN_00408500(iVar1);
    if (*(int *)(iVar1 + 0x10) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
  }
  FUN_00408220(DAT_007cbf9c);
  FUN_00408360(DAT_007cbf98);
  l_sql_data = 0;
  return 0;
}

