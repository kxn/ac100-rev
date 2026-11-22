// func cw_priv_except_length @ 005b0820 size=12

undefined4 cw_priv_except_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x18;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

