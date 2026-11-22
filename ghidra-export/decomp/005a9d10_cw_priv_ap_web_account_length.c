// func cw_priv_ap_web_account_length @ 005a9d10 size=32

int cw_priv_ap_web_account_length(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 2) + 4 + (uint)*(byte *)(param_1 + 3);
  }
  return iVar1;
}

