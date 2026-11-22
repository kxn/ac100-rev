// func uac_rdmngr_uninit @ 0062f2d0 size=172

undefined4 uac_rdmngr_uninit(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = rdmngr_db_uninit();
  if (iVar1 == 0) {
    iVar1 = rdmngr_uninit();
    if (iVar1 == 0) {
      return 0;
    }
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d rdmngr_uninit() error.\n";
    uVar2 = 0xaa0;
  }
  else {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_uninit() error.\n";
    uVar2 = 0xa9a;
  }
  printf(__format,"uac_rdmngr_uninit",uVar2);
  return 0xffffffff;
}

