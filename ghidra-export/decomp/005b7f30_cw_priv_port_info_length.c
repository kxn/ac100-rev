// func cw_priv_port_info_length @ 005b7f30 size=44

int cw_priv_port_info_length(byte *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 != (byte *)0x0) && (iVar1 = 1, *(int *)(param_1 + 4) != 0)) {
    iVar1 = (uint)*param_1 * 8 + 1;
  }
  return iVar1;
}

