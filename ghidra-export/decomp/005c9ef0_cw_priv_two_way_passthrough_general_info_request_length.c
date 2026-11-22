// func cw_priv_two_way_passthrough_general_info_request_length @ 005c9ef0 size=28

uint cw_priv_two_way_passthrough_general_info_request_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 8) + 0xcU & 0xffff;
  }
  return uVar1;
}

