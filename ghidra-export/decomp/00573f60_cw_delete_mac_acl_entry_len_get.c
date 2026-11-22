// func cw_delete_mac_acl_entry_len_get @ 00573f60 size=36

short cw_delete_mac_acl_entry_len_get(byte *param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != (byte *)0x0) {
    sVar1 = (ushort)param_1[1] * (ushort)*param_1 + 2;
  }
  return sVar1;
}

