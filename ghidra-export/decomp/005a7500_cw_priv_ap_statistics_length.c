// func cw_priv_ap_statistics_length @ 005a7500 size=48

int cw_priv_ap_statistics_length(byte *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    iVar1 = (uint)*param_1 * 0x20 + (uint)param_1[1] * 0x1c + 0x2a;
  }
  return iVar1;
}

