// func uac_id_free @ 00519c9c size=164

void uac_id_free(int *param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  if (((param_1 != (int *)0x0) && (-1 < (int)param_2)) && ((int)param_2 < param_1[4])) {
    iVar1 = ((int)param_2 >> 5) * 4;
    if ((*(int *)(param_1[1] + iVar1) >> (param_2 & 0x1f) & 1U) != 0) {
      iVar3 = param_1[3];
      *(uint *)(*param_1 + iVar3 * 4) = param_2;
      iVar3 = iVar3 + 1;
      param_1[3] = iVar3;
      if (param_1[4] <= iVar3) {
        param_1[3] = 0;
      }
      puVar2 = (uint *)(param_1[1] + iVar1);
      *puVar2 = *puVar2 & ~(1 << (param_2 & 0x1f));
      param_1[5] = param_1[5] + -1;
    }
  }
  return;
}

