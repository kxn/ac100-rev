// func rbtree_traverse @ 0051fe6c size=212

void rbtree_traverse(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != 0) && (param_2 != (code *)0x0)) {
    iVar1 = rb_first();
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(iVar1 + 0xc);
      while ((iVar2 = (*param_2)(param_3,uVar3), iVar2 != -1 && (iVar1 = rb_next(iVar1), iVar1 != 0)
             )) {
        uVar3 = *(undefined4 *)(iVar1 + 0xc);
      }
    }
    return;
  }
  printf("%s:%d Warning: root != NULL && callback != NULL failed.\n","rbtree_traverse",0x333);
  return;
}

