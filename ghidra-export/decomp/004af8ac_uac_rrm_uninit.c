// func uac_rrm_uninit @ 004af8ac size=128

undefined4 uac_rrm_uninit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (rrm_signal != 0) {
    FUN_00408390();
  }
  iVar1 = rrm_db_uninit();
  if (iVar1 == 0) {
    uVar2 = 0;
    uac_rrm_sync_uninit();
  }
  else {
    uVar2 = 0xffffffff;
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d rrm_db_uninit() fail!\n","uac_rrm_uninit",0xbb2);
    }
  }
  return uVar2;
}

