// func cw_priv_nd_defend_length @ 005b70b0 size=36

uint cw_priv_nd_defend_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) * 0x16 + 6U & 0xffff;
  }
  return uVar1;
}

