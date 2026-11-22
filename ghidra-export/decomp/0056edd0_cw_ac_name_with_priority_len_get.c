// func cw_ac_name_with_priority_len_get @ 0056edd0 size=28

short cw_ac_name_with_priority_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 2) + 1;
  }
  return sVar1;
}

