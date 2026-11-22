// func uac_wstation_uninit @ 006341a0 size=172

undefined4 uac_wstation_uninit(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = uac_wstation_pkt_uninit();
  if (iVar1 == 0) {
    iVar1 = wsta_db_uninit();
    if (iVar1 == 0) {
      return 0;
    }
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> wserv_db_uninit() fail!\r\n";
    uVar2 = 0x68b;
  }
  else {
    if (g_wsta_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wsta>[error]%s(): %d  -> uac_wstation_pkt_uninit() fail!\r\n";
    uVar2 = 0x685;
  }
  printf(__format,"uac_wstation_uninit",uVar2);
  return 0xffffffff;
}

