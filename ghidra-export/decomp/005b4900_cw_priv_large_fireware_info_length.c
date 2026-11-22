// func cw_priv_large_fireware_info_length @ 005b4900 size=12

undefined4 cw_priv_large_fireware_info_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x1d;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

