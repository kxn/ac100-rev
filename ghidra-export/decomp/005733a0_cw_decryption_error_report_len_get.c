// func cw_decryption_error_report_len_get @ 005733a0 size=36

short cw_decryption_error_report_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = (ushort)*(byte *)(param_1 + 2) * (ushort)*(byte *)(param_1 + 1) + 3;
  }
  return sVar1;
}

