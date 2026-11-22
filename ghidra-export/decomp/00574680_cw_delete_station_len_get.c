// func cw_delete_station_len_get @ 00574680 size=24

int cw_delete_station_len_get(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 1) + 2;
  }
  return iVar1;
}

