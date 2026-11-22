// func uac_id_alloc @ 00519c20 size=124

uint uac_id_alloc(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (param_1[5] != param_1[4])) {
    iVar2 = param_1[2] + 1;
    puVar3 = (uint *)(*param_1 + param_1[2] * 4);
    uVar1 = *puVar3;
    *puVar3 = 0xffffffff;
    if (param_1[4] <= iVar2) {
      iVar2 = 0;
    }
    param_1[2] = iVar2;
    puVar3 = (uint *)(param_1[1] + ((int)uVar1 >> 5) * 4);
    *puVar3 = *puVar3 | 1 << (uVar1 & 0x1f);
    param_1[5] = param_1[5] + 1;
  }
  return uVar1;
}

