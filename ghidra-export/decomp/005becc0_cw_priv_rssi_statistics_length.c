// func cw_priv_rssi_statistics_length @ 005becc0 size=36

uint cw_priv_rssi_statistics_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 0x10) * 0xe + 0x14U & 0xffff;
  }
  return uVar1;
}

