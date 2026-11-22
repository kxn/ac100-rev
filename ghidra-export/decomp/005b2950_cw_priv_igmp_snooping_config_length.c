// func cw_priv_igmp_snooping_config_length @ 005b2950 size=32

int cw_priv_igmp_snooping_config_length(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = (*(byte *)(param_1 + 2) + 1) * 3;
  }
  return iVar1;
}

