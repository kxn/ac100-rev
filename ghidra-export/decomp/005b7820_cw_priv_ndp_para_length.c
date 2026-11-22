// func cw_priv_ndp_para_length @ 005b7820 size=24

int cw_priv_ndp_para_length(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 0x13) + 0x14;
  }
  return iVar1;
}

