// func cw_priv_pwr_state_length @ 005b9180 size=12

undefined4 cw_priv_pwr_state_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

