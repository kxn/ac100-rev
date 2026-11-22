// func band_navigation_config_key_get @ 005602c0 size=1

undefined4 band_navigation_config_key_get(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *param_1;
    uVar1 = 0;
  }
  return uVar1;
}

