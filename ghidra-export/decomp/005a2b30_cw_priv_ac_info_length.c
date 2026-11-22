// func cw_priv_ac_info_length @ 005a2b30 size=12

undefined4 cw_priv_ac_info_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 6;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

