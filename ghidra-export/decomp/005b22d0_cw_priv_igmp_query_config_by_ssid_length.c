// func cw_priv_igmp_query_config_by_ssid_length @ 005b22d0 size=36

uint cw_priv_igmp_query_config_by_ssid_length(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = *param_1 * 3 + 4U & 0xffff;
  }
  return uVar1;
}

