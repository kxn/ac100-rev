// func cw_priv_lldp_report_length @ 005b4f50 size=28

uint cw_priv_lldp_report_length(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = *param_1 + 4U & 0xffff;
  }
  return uVar1;
}

