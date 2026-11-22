// func band_navigation_config_max_failures_get @ 005603b0 size=36

undefined4 band_navigation_config_max_failures_get(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    uVar1 = 0;
  }
  return uVar1;
}

