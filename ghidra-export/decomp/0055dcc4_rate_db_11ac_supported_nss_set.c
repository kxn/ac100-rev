// func rate_db_11ac_supported_nss_set @ 0055dcc4 size=88

undefined4 rate_db_11ac_supported_nss_set(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_004082d0(rate_db_mutex,0xffffffff);
  uVar1 = rrc_11ac_supported_max_nss_set(rate_cfg,param_1);
  FUN_00407f30(rate_db_mutex);
  return uVar1;
}

