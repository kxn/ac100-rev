// func cw_priv_sta_list_length @ 005c66b0 size=36

uint cw_priv_sta_list_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = (*(int *)(param_1 + 4) + 1) * 6 & 0xffff;
  }
  return uVar1;
}

