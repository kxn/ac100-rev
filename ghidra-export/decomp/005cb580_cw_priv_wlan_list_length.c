// func cw_priv_wlan_list_length @ 005cb580 size=36

uint cw_priv_wlan_list_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) * 0x21 + 8U & 0xffff;
  }
  return uVar1;
}

