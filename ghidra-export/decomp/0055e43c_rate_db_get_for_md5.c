// func rate_db_get_for_md5 @ 0055e43c size=164

undefined4 rate_db_get_for_md5(void *param_1)

{
  undefined4 uVar1;
  
  if ((rate_cfg_md5 == (void *)0x0) || (param_1 == (void *)0x0)) {
    uVar1 = 0xffffffff;
    if (rate_err_switch != 0) {
      printf("[RATE_ERR]%s()/%d rate db cfg or rate cfg to be set is NULL\n","rate_db_get_for_md5",
             0x3d0);
    }
  }
  else {
    FUN_004082d0(rate_db_mutex,0xffffffff);
    uVar1 = 0;
    memcpy(param_1,rate_cfg_md5,0x48);
    FUN_00407f30(rate_db_mutex);
  }
  return uVar1;
}

