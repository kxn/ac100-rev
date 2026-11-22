// func rbtree_insert @ 0051faa0 size=328

undefined4 rbtree_insert(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    uVar4 = 0x266;
    __format = "%s:%d Warning: root != NULL && data != NULL failed.\n";
  }
  else {
    piVar1 = (int *)uac_mem_malloc_my(0x10,0x268);
    if (piVar1 != (int *)0x0) {
      piVar1[3] = param_2;
      piVar1[1] = 0;
      piVar1[2] = 0;
      *piVar1 = (int)piVar1;
      iVar2 = 0;
      piVar5 = param_1;
      while( true ) {
        while( true ) {
          iVar6 = *piVar5;
          if (iVar6 == 0) {
            *piVar1 = iVar2;
            piVar1[1] = 0;
            piVar1[2] = 0;
            *piVar5 = (int)piVar1;
            rb_insert_color(piVar1,param_1);
            return 0;
          }
          iVar3 = (*(code *)param_1[1])(piVar1[3],*(undefined4 *)(iVar6 + 0xc));
          iVar2 = iVar6;
          if (-1 < iVar3) break;
          piVar5 = (int *)(*piVar5 + 8);
        }
        if (iVar3 == 0) break;
        piVar5 = (int *)(*piVar5 + 4);
      }
      uac_mem_free_my(piVar1);
      return 0xffffffff;
    }
    uVar4 = 0x269;
    __format = "%s:%d Warning: data_wrapper != NULL failed.\n";
  }
  printf(__format,"rbtree_insert",uVar4);
  return 0xffffffff;
}

