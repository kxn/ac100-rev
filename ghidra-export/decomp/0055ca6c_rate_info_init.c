// func rate_info_init @ 0055ca6c size=200

undefined4 rate_info_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = rate_db_init();
  if (iVar1 == 0) {
    iVar1 = FUN_004084d0("ac_rate",2,jcs_callback_rate_set);
    if (iVar1 == 0) {
      udbg_help_register("rate","rate_debug_help()");
      uVar2 = 0;
    }
    else {
      if (rate_err_switch != 0) {
        printf("[RATE_ERR]%s()/%d register callback to jcs failed\n","rate_info_init",0xed);
      }
      uVar2 = 0xffffffff;
      rate_db_destroy();
    }
  }
  else {
    uVar2 = 0xffffffff;
    if (rate_err_switch != 0) {
      printf("[RATE_ERR]%s()/%d init rate database failed\n","rate_info_init",0xe6);
    }
  }
  return uVar2;
}

