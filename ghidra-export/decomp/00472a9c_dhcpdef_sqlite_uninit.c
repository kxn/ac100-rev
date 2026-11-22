// func dhcpdef_sqlite_uninit @ 00472a9c size=288

undefined4 dhcpdef_sqlite_uninit(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_007670d0 != 0) {
    iVar1 = pthread_kill(DAT_007670d4,3);
    if (((iVar1 == 0) || (g_dhcpdef_error == 0)) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      DAT_007670d0 = 0;
    }
    else {
      printf("\x1b[31;49m[%s]<%s():%d> pthread_kill() fail, ret = %d.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_sqlite_uninit",0x39a,iVar1);
      DAT_007670d0 = 0;
    }
  }
  if (l_db_handle != 0) {
    FUN_004080b0();
    l_db_handle = 0;
  }
  while (iVar1 = FUN_004081b0(&DAT_007670bc), iVar1 != 0) {
    FUN_00408500(iVar1);
    if (*(int *)(iVar1 + 0x10) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
  }
  FUN_00408220(DAT_007670cc);
  FUN_00408360(DAT_007670c8);
  l_sql_data = 0;
  return 0;
}

