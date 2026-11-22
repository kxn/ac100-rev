// func cw_priv_lag_config_length @ 005b4330 size=24

int cw_priv_lag_config_length(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 2) + 3;
  }
  return iVar1;
}

