// func cw_priv_igmp_query_config_length @ 005b1ff0 size=12

undefined4 cw_priv_igmp_query_config_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

