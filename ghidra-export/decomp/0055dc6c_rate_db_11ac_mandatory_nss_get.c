// func rate_db_11ac_mandatory_nss_get @ 0055dc6c size=88

undefined4 rate_db_11ac_mandatory_nss_get(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_004082d0(rate_db_mutex,0xffffffff);
  uVar1 = rrc_11ac_mandatory_max_nss_get(rate_cfg,param_1);
  FUN_00407f30(rate_db_mutex);
  return uVar1;
}

