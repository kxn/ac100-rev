// func cw_priv_set_silence_params_length @ 005bfa10 size=12

undefined4 cw_priv_set_silence_params_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

