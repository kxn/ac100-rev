// func cw_priv_arp_defend_length @ 005ab450 size=36

uint cw_priv_arp_defend_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) * 10 + 6U & 0xffff;
  }
  return uVar1;
}

