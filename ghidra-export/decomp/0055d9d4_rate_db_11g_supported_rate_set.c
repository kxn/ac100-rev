// func rate_db_11g_supported_rate_set @ 0055d9d4 size=104

undefined4 rate_db_11g_supported_rate_set(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_004082d0(rate_db_mutex,0xffffffff);
  uVar1 = rrc_11g_supported_rate_set_set(rate_cfg,param_1,param_2);
  FUN_00407f30(rate_db_mutex);
  return uVar1;
}

