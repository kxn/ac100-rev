// func uac_wservice_uninit @ 005e0fa0 size=240

undefined4 uac_wservice_uninit(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = uac_wservice_pkt_uninit();
  if (iVar1 == 0) {
    iVar1 = wserv_sqlite_uninit();
    if (iVar1 == 0) {
      iVar1 = wserv_db_uninit();
      if (iVar1 == 0) {
        return 0;
      }
      if (g_wserv_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "<wserv>[error]%s(): %d  -> wserv_db_uninit() fail!\r\n";
      uVar2 = 0x1801;
    }
    else {
      if (g_wserv_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "<wserv>[error]%s(): %d  -> wserv_sqlite_uninit() fail!\r\n";
      uVar2 = 0x17fb;
    }
  }
  else {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[error]%s(): %d  -> uac_wservice_pkt_uninit() fail!\r\n";
    uVar2 = 0x17f5;
  }
  printf(__format,"uac_wservice_uninit",uVar2);
  return 0xffffffff;
}

