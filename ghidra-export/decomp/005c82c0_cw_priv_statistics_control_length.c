// func cw_priv_statistics_control_length @ 005c82c0 size=12

undefined4 cw_priv_statistics_control_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 9;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

