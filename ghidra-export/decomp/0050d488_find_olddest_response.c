// func find_olddest_response @ 0050d488 size=100

int find_olddest_response(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar4 = 0;
    iVar2 = FUN_004081b0(param_1 + 4);
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0x14);
      while( true ) {
        if (iVar4 < iVar3) {
          iVar1 = iVar2;
          iVar4 = iVar3;
        }
        iVar2 = FUN_00408680(iVar2);
        if (iVar2 == 0) break;
        iVar3 = *(int *)(iVar2 + 0x14);
      }
    }
  }
  return iVar1;
}

