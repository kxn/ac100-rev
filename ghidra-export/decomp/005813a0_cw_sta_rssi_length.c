// func cw_sta_rssi_length @ 005813a0 size=36

uint cw_sta_rssi_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) * 7 + 5U & 0xffff;
  }
  return uVar1;
}

