// func cw_ac_ipv4_list_len_get @ 0056dd00 size=28

int cw_ac_ipv4_list_len_get(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (ushort *)0x0) {
    iVar1 = (*param_1 & 0x3fff) << 2;
  }
  return iVar1;
}

