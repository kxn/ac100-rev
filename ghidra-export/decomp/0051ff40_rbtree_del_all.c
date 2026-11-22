// func rbtree_del_all @ 0051ff40 size=192

void rbtree_del_all(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    printf("%s:%d Warning: root != NULL failed.\n","rbtree_del_all",0x352);
    return;
  }
  while (iVar1 = rb_first(param_1), iVar1 != 0) {
    rb_erase(iVar1,param_1);
    if (*(code **)(param_1 + 0xc) != (code *)0x0) {
      (**(code **)(param_1 + 0xc))(*(undefined4 *)(iVar1 + 0xc));
    }
    uac_mem_free_my(iVar1);
  }
  return;
}

