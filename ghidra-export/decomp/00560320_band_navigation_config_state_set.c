// func band_navigation_config_state_set @ 00560320 size=24

undefined4 band_navigation_config_state_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 4) = param_2;
  }
  return uVar1;
}

