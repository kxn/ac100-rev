// func wserv_sqlite_init @ 005f93c8 size=700

undefined4 wserv_sqlite_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_sqlite_init() begin.\r\n","wserv_sqlite_init",0x621);
  }
  if (l_sql_data == 0) {
    memset(&l_sql_data,0,0x20);
    DAT_007cbf98 = FUN_00407f00("wserv_sql_msg_mutex",0);
    if (DAT_007cbf98 == 0) {
      if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005f9534;
      __format = "<wserv>[error]%s(): %d  -> create sql mutex fail.\r\n";
      uVar2 = 0x62c;
    }
    else {
      DAT_007cbf9c = FUN_00407d80("wserv_sql_msg_cond");
      if (DAT_007cbf9c == 0) {
        if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005f9534;
        __format = "<wserv>[error]%s(): %d  -> create sql cond fail.\r\n";
        uVar2 = 0x633;
      }
      else {
        FUN_0051ad88(&DAT_007cbf8c);
        iVar1 = _wserv_sqlite_try_create_tbl();
        if (iVar1 == 0) {
          FUN_00408620("/etc/nouci_config/dbs/wserv_rd.db",wserv_sqlite_get_msg_len);
          iVar1 = FUN_004084e0(&DAT_007cbfa4,"wserv_sql_thread",_wserv_sqlite_thread_main,0);
          if (iVar1 == 0) {
            DAT_007cbfa0 = 1;
            if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("<wserv>[debug]%s(): %d  -> wserv_sqlite_init() success.\r\n",
                     "wserv_sqlite_init",0x649);
            }
            l_sql_data = 1;
            return 0;
          }
          if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005f9534;
          __format = "<wserv>[error]%s(): %d  -> _wserv_sqlite_try_create_tbl() fail.\r\n";
          uVar2 = 0x645;
        }
        else {
          if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005f9534;
          __format = "<wserv>[error]%s(): %d  -> _wserv_sqlite_try_create_tbl() fail.\r\n";
          uVar2 = 0x63b;
        }
      }
    }
  }
  else {
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005f9534;
    __format = "<wserv>[error]%s(): %d  -> wserv sqlite has inited.\r\n";
    uVar2 = 0x624;
  }
  printf(__format,"wserv_sqlite_init",uVar2);
LAB_005f9534:
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_sqlite_init() fail.\r\n","wserv_sqlite_init",0x64d);
  }
  wserv_sqlite_uninit();
  return 0xffffffff;
}

