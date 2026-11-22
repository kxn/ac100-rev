// func rrm_db_init @ 004b1bac size=116

undefined4 rrm_db_init(void)

{
  undefined4 uVar1;
  
  rrm_mutex = FUN_00407f00("rrm_mutex",1);
  uVar1 = 0;
  if (rrm_mutex == 0) {
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d Create database mutex failed.\n","rrm_db_init",0x7d);
    }
    rrm_db_uninit();
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

