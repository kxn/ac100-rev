// func cw_priv_mac_filter_length @ 005b5440 size=40

uint cw_priv_mac_filter_length(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (uint)(*(byte *)(param_1 + 1) >> 3) * *param_1 + 8 & 0xffff;
  }
  return uVar1;
}

