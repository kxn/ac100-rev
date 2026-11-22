// func rate_position_get @ 0055cb40 size=56

int rate_position_get(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_006d1674;
  while( true ) {
    if (param_1 == puVar2[-1]) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    if (iVar1 == 0xc) break;
    puVar2 = puVar2 + 1;
  }
  return -1;
}

