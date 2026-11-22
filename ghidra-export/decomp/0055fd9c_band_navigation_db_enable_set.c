// func band_navigation_db_enable_set @ 0055fd9c size=88

undefined4 band_navigation_db_enable_set(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_004082d0(band_navigation_db_mutex,0xffffffff);
  uVar1 = band_navigation_config_state_set(band_navigation_cfg,param_1);
  FUN_00407f30(band_navigation_db_mutex);
  return uVar1;
}

