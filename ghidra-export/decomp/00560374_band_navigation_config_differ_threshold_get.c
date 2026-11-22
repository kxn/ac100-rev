// func band_navigation_config_differ_threshold_get @ 00560374 size=36

undefined4 band_navigation_config_differ_threshold_get(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    uVar1 = 0;
  }
  return uVar1;
}

