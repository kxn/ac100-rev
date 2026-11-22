// func cw_priv_trans_data_request_length @ 005c9920 size=28

uint cw_priv_trans_data_request_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) + 4U & 0xffff;
  }
  return uVar1;
}

