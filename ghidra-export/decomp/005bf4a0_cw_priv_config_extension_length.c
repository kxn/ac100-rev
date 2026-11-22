// func cw_priv_config_extension_length @ 005bf4a0 size=28

uint cw_priv_config_extension_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) + 5U & 0xffff;
  }
  return uVar1;
}

