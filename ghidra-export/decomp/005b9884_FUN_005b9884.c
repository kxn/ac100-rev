// func FUN_005b9884 @ 005b9884 size=112

void FUN_005b9884(byte *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)*param_1; iVar4 = iVar4 + 1) {
    iVar5 = 0;
    iVar3 = *(int *)(param_1 + 4) + iVar1;
    iVar2 = *(byte *)(iVar3 + 10) + 0xb;
    while (iVar5 < (int)((uint)*(byte *)(iVar3 + 9) * (uint)*(byte *)(iVar3 + 4))) {
      iVar5 = iVar5 + 1;
      if (iVar3 + iVar2 != 0) {
        iVar2 = iVar2 + *(byte *)(iVar3 + iVar2 + 1) + 2;
      }
    }
    iVar1 = iVar1 + iVar2;
  }
  return;
}

