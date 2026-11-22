// func uac_stats_uninit @ 00673658 size=1

undefined4 uac_stats_uninit(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = stats_pkt_uninit();
  if (iVar1 == 0) {
    iVar1 = stats_db_uninit();
    if (iVar1 == 0) {
      return 0;
    }
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[STATISTICS_ERROR]%s()/%d stats_db_uninit() fail!\n";
    uVar2 = 0x1fc;
  }
  else {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[STATISTICS_ERROR]%s()/%d stats_pkt_uninit() fail!\n";
    uVar2 = 0x1f7;
  }
  printf(__format,"uac_stats_uninit",uVar2);
  return 0xffffffff;
}

