// func cw_priv_sta_assoc_req_new_length @ 005c19e0 size=28

uint cw_priv_sta_assoc_req_new_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 0x10) + 0x11U & 0xffff;
  }
  return uVar1;
}

