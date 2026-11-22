// func cw_priv_sniffing_statistics_length @ 005c0480 size=36

uint cw_priv_sniffing_statistics_length(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = *param_1 * 0xe + 4U & 0xffff;
  }
  return uVar1;
}

