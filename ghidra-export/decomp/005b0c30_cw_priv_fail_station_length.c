// func cw_priv_fail_station_length @ 005b0c30 size=36

uint cw_priv_fail_station_length(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = *param_1 * 0x11 + 4U & 0xffff;
  }
  return uVar1;
}

