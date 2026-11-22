// func cw_data_transfer_data_len_get @ 00572850 size=28

short cw_data_transfer_data_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 2) + 4;
  }
  return sVar1;
}

