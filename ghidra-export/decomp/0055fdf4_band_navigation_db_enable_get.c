// func band_navigation_db_enable_get @ 0055fdf4 size=88

undefined4 band_navigation_db_enable_get(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_004082d0(band_navigation_db_mutex,0xffffffff);
  uVar1 = band_navigation_config_state_get(band_navigation_cfg,param_1);
  FUN_00407f30(band_navigation_db_mutex);
  return uVar1;
}

