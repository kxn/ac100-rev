// func rate_db_11g_multicast_rate_get @ 0055e08c size=88

undefined4 rate_db_11g_multicast_rate_get(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_004082d0(rate_db_mutex,0xffffffff);
  uVar1 = rrc_11g_multicast_rate_get(rate_cfg,param_1);
  FUN_00407f30(rate_db_mutex);
  return uVar1;
}

