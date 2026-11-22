// func cw_priv_delete_implicitly_leave_station_len_get @ 005af0f0 size=24

int cw_priv_delete_implicitly_leave_station_len_get(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 1) + 2;
  }
  return iVar1;
}

