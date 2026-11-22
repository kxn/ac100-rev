// func transfer_rcc_db_to_rcc_md5 @ 0055e4e0 size=184

void transfer_rcc_db_to_rcc_md5(void)

{
  if ((rate_cfg_md5 != 0) && (rate_cfg != 0)) {
    FUN_004082d0(rate_db_mutex,0xffffffff);
    transfer_rate_db_to_rate_md5(rate_cfg,rate_cfg_md5);
    FUN_00407f30(rate_db_mutex);
    return;
  }
  if (rate_err_switch != 0) {
    printf("[RATE_ERR]%s()/%d rate db cfg or rate cfg to be set is NULL\n",
           "transfer_rcc_db_to_rcc_md5",0x3dc);
    return;
  }
  return;
}

