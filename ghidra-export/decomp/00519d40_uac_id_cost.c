// func uac_id_cost @ 00519d40 size=120

void uac_id_cost(int *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if (((param_1 != (int *)0x0) && (-1 < (int)param_2)) && ((int)param_2 < param_1[4])) {
    puVar1 = (uint *)(param_1[1] + ((int)param_2 >> 5) * 4);
    uVar2 = *puVar1;
    if (((int)uVar2 >> (param_2 & 0x1f) & 1U) == 0) {
      *puVar1 = uVar2 | 1 << (param_2 & 0x1f);
      param_1[5] = param_1[5] + 1;
      *(undefined4 *)(*param_1 + param_2 * 4) = 0xffffffff;
    }
  }
  return;
}

