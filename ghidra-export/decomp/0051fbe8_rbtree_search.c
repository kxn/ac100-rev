// func rbtree_search @ 0051fbe8 size=176

undefined4 rbtree_search(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    printf("%s:%d Warning: root != NULL && key != NULL failed.\n","rbtree_search",0x29d);
  }
  else {
    for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      pcVar3 = (code *)param_1[2];
      while (iVar1 = (*pcVar3)(param_2,*(undefined4 *)(iVar2 + 0xc)), -1 < iVar1) {
        if (iVar1 == 0) {
          return *(undefined4 *)(iVar2 + 0xc);
        }
        iVar2 = *(int *)(iVar2 + 4);
        if (iVar2 == 0) {
          return 0;
        }
        pcVar3 = (code *)param_1[2];
      }
    }
  }
  return 0;
}

