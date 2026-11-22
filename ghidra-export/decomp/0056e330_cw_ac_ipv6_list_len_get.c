// func cw_ac_ipv6_list_len_get @ 0056e330 size=28

int cw_ac_ipv6_list_len_get(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (ushort *)0x0) {
    iVar1 = (*param_1 & 0xfff) << 4;
  }
  return iVar1;
}

