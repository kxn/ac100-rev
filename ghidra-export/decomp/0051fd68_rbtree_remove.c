// func rbtree_remove @ 0051fd68 size=260

void rbtree_remove(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    printf("%s:%d Warning: root != NULL && key != NULL failed.\n","rbtree_remove",0x300);
    return;
  }
  iVar2 = *param_1;
  do {
    if (iVar2 == 0) {
      return;
    }
    pcVar3 = (code *)param_1[2];
    while (iVar1 = (*pcVar3)(param_2,*(undefined4 *)(iVar2 + 0xc)), -1 < iVar1) {
      if (iVar1 == 0) {
        rb_erase(iVar2,param_1);
        if ((code *)param_1[3] != (code *)0x0) {
          (*(code *)param_1[3])(*(undefined4 *)(iVar2 + 0xc));
        }
        uac_mem_free_my(iVar2);
        return;
      }
      iVar2 = *(int *)(iVar2 + 4);
      if (iVar2 == 0) {
        return;
      }
      pcVar3 = (code *)param_1[2];
    }
    iVar2 = *(int *)(iVar2 + 8);
  } while( true );
}

