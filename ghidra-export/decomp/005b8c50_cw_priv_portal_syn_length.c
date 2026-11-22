// func cw_priv_portal_syn_length @ 005b8c50 size=28

short cw_priv_portal_syn_length(short *param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != (short *)0x0) {
    sVar1 = *param_1 + 2;
  }
  return sVar1;
}

