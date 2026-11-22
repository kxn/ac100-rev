// func cw_priv_sta_auth_rslt_length @ 005c5050 size=28

uint cw_priv_sta_auth_rslt_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 0xc) + 0x10U & 0xffff;
  }
  return uVar1;
}

