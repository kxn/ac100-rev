// func wsta_roam_uninit @ 00480aec size=144

undefined4 wsta_roam_uninit(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = wsta_roam_pkt_uninit();
  if (iVar1 == 0) {
    iVar1 = wsta_roam_db_uninit();
    if (iVar1 == 0) {
      return 0;
    }
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d wsta_roam_db_uninit() fail!\n";
    uVar2 = 0x242;
  }
  else {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d wsta_roam_pkt_uninit() fail!\n";
    uVar2 = 0x23d;
  }
  printf(__format,"wsta_roam_uninit",uVar2);
  return 0xffffffff;
}

