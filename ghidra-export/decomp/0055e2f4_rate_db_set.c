// func rate_db_set @ 0055e2f4 size=164

undefined4 rate_db_set(void *param_1)

{
  undefined4 uVar1;
  
  if ((rate_cfg == (void *)0x0) || (param_1 == (void *)0x0)) {
    uVar1 = 0xffffffff;
    if (rate_err_switch != 0) {
      printf("[RATE_ERR]%s()/%d rate db cfg or rate cfg to be set is NULL\n","rate_db_set",0x3a4);
    }
  }
  else {
    FUN_004082d0(rate_db_mutex,0xffffffff);
    uVar1 = 0;
    memcpy(rate_cfg,param_1,0x1b4);
    FUN_00407f30(rate_db_mutex);
  }
  return uVar1;
}

