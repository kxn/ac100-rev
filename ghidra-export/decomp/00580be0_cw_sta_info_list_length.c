// func cw_sta_info_list_length @ 00580be0 size=36

uint cw_sta_info_list_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 8) * 0xe + 9U & 0xffff;
  }
  return uVar1;
}

