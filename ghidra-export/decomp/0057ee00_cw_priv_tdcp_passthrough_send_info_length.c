// func cw_priv_tdcp_passthrough_send_info_length @ 0057ee00 size=28

uint cw_priv_tdcp_passthrough_send_info_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) + 9U & 0xffff;
  }
  return uVar1;
}

