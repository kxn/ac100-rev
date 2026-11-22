// func band_navigation_config_destroy @ 00560214 size=40

undefined4 band_navigation_config_destroy(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    FUN_00407df0();
    uVar1 = 0;
  }
  return uVar1;
}

