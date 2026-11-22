// func band_navigation_db_threshold_get @ 0055fea4 size=88

undefined4 band_navigation_db_threshold_get(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_004082d0(band_navigation_db_mutex,0xffffffff);
  uVar1 = band_navigation_config_users_threshold_get(band_navigation_cfg,param_1);
  FUN_00407f30(band_navigation_db_mutex);
  return uVar1;
}

