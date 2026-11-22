// func cw_priv_sta_auth_req_length @ 005c4960 size=28

uint cw_priv_sta_auth_req_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 8) + 0xcU & 0xffff;
  }
  return uVar1;
}

