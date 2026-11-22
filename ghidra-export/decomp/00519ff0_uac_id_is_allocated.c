// func uac_id_is_allocated @ 00519ff0 size=68

uint uac_id_is_allocated(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (((param_1 != 0) && (-1 < (int)param_2)) && ((int)param_2 < *(int *)(param_1 + 0x10))) {
    uVar1 = 1 << (param_2 & 0x1f) & *(uint *)(*(int *)(param_1 + 4) + ((int)param_2 >> 5) * 4);
  }
  return uVar1;
}

