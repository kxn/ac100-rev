// func wserv_db_ssid_utf8_to_gbk @ 005f47ac size=444

undefined4 wserv_db_ssid_utf8_to_gbk(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  size_t __n;
  char *pcVar3;
  undefined4 uVar4;
  char acStack_b0 [52];
  undefined1 auStack_7c [108];
  
  memset(auStack_7c,0,0x66);
  iVar1 = FUN_00408630(param_1,auStack_7c,0x32,0);
  if (iVar1 == -1) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "<wserv>[error]%s(): %d  -> uac_codeConv_utf8_to_unicode() fail!\r\n";
    uVar4 = 0x166d;
LAB_005f4870:
    printf(pcVar3,"wserv_db_ssid_utf8_to_gbk",uVar4);
    return 0xffffffff;
  }
  if (iVar1 < 0x33) {
    memset(acStack_b0,0,0x33);
    iVar1 = FUN_00408000(auStack_7c,acStack_b0,0x32,0);
    if (iVar1 == -1) {
      if (g_wserv_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar3 = "<wserv>[error]%s(): %d  -> uac_codeConv_unicode_to_gbk() fail!\r\n";
      uVar4 = 0x167e;
      goto LAB_005f4870;
    }
    if (iVar1 < 0x33) {
      __n = strlen(acStack_b0);
      strncpy(param_2,acStack_b0,__n);
      return 0;
    }
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "<wserv>[error]%s(): %d  -> toGbk src utf8 string is too long(error_len=%d)\r\n";
    uVar4 = 0x1684;
  }
  else {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "<wserv>[error]%s(): %d  -> toUnicode, src utf8 string is too long(error_len=%d)\r\n";
    uVar4 = 0x1673;
  }
  printf(pcVar3,"wserv_db_ssid_utf8_to_gbk",uVar4,iVar1);
  return 0xffffffff;
}

