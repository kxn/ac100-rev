// func cw_duplicate_ipv6_address_len_get @ 00575860 size=24

int cw_duplicate_ipv6_address_len_get(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 0x11) + 0x12;
  }
  return iVar1;
}

