// func rate_db_11a_mandatory_rate_get @ 0055d5dc size=120

undefined4 rate_db_11a_mandatory_rate_get(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_004082d0(rate_db_mutex,0xffffffff);
  uVar1 = rrc_11a_mandatory_rate_set_get(rate_cfg,param_1,param_2,param_3);
  FUN_00407f30(rate_db_mutex);
  return uVar1;
}

