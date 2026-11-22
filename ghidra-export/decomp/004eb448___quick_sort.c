// func __quick_sort @ 004eb448 size=192

void __quick_sort(int param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  while (param_2 < param_3) {
    piVar2 = (int *)(param_1 + param_2 * 4);
    cVar1 = *(char *)(*piVar2 + 6);
    piVar3 = piVar2;
    iVar7 = param_2;
    iVar4 = param_2;
    while (iVar4 = iVar4 + 1, iVar4 <= param_3) {
      if (*(char *)(piVar3[1] + 6) < cVar1) {
        iVar7 = iVar7 + 1;
        piVar5 = (int *)(param_1 + iVar7 * 4);
        iVar6 = *piVar5;
        *piVar5 = piVar3[1];
        piVar3[1] = iVar6;
      }
      piVar3 = piVar3 + 1;
    }
    iVar4 = *piVar2;
    piVar3 = (int *)(param_1 + iVar7 * 4);
    *piVar2 = *piVar3;
    *piVar3 = iVar4;
    __quick_sort(param_1,param_2,iVar7 + -1);
    param_2 = iVar7 + 1;
  }
  return;
}

