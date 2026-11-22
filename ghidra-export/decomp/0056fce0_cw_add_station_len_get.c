// func cw_add_station_len_get @ 0056fce0 size=36

short cw_add_station_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 8) + 2 + (ushort)*(byte *)(param_1 + 1);
  }
  return sVar1;
}

