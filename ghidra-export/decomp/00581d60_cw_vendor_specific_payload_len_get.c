// func cw_vendor_specific_payload_len_get @ 00581d60 size=28

short cw_vendor_specific_payload_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 6) + 6;
  }
  return sVar1;
}

