// func _wserv_sqlite_thread_main @ 005f86fc size=676

undefined4 _wserv_sqlite_thread_main(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _wserv_sqlite_thread_main() start.\r\n",
           "_wserv_sqlite_thread_main",0x4ac);
  }
  iVar1 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv_rd.db",&l_wserv_rf_handle);
  if (iVar1 == 0) {
    iVar1 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv.db",&l_wserv_db_handle);
    if (iVar1 == 0) {
      iVar1 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv_ip.db",&l_wserv_ip_handle);
      if (iVar1 == 0) {
        do {
          FUN_004082d0(DAT_007cbf98,0xffffffff);
          while (iVar1 = FUN_004081b0(&DAT_007cbf8c), iVar1 == 0) {
            FUN_004086c0(DAT_007cbf9c,DAT_007cbf98,0xffffffff);
          }
          FUN_00408500(iVar1);
          FUN_00407f30(DAT_007cbf98);
          puVar2 = *(undefined4 **)(iVar1 + 0x10);
          if (puVar2 != (undefined4 *)0x0) {
            switch(*(undefined4 *)(iVar1 + 0xc)) {
            case 0:
              _wserv_sqlite_do_insert();
              break;
            case 1:
              FUN_005f7dcc(*puVar2);
              break;
            case 2:
              _wserv_sqlite_do_bind();
              break;
            case 3:
              _wserv_sqlite_do_unbind();
              break;
            case 4:
              FUN_005f7f3c();
              break;
            case 5:
              _wserv_sqlite_do_insert_ip();
              break;
            case 6:
              FUN_005f7e84(*puVar2);
              break;
            default:
              goto switchD_005f8908_default;
            }
            puVar2 = *(undefined4 **)(iVar1 + 0x10);
          }
switchD_005f8908_default:
          if (puVar2 != (undefined4 *)0x0) {
            FUN_00407df0();
            *(undefined4 *)(iVar1 + 0x10) = 0;
          }
          FUN_00407df0(iVar1);
        } while( true );
      }
      if (g_wserv_error == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = 0x4c0;
      pcVar4 = "/etc/nouci_config/dbs/wserv_ip.db";
    }
    else {
      if (g_wserv_error == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = 0x4b9;
      pcVar4 = "/etc/nouci_config/dbs/wserv.db";
    }
  }
  else {
    if (g_wserv_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    uVar3 = 0x4b2;
    pcVar4 = "/etc/nouci_config/dbs/wserv_rd.db";
  }
  printf("<wserv>[error]%s(): %d  -> _wserv_sqlite_thread_main() fail, path=%s\r\n",
         "_wserv_sqlite_thread_main",uVar3,pcVar4);
  return 0;
}

