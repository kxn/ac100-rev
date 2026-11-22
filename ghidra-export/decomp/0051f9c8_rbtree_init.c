// func rbtree_init @ 0051f9c8 size=216

undefined4 * rbtree_init(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    puVar1 = (undefined4 *)0x0;
    printf("%s:%d Warning: dataCmp != NULL && keyDataCmp != NULL failed.\n","rbtree_init",0x243);
  }
  else {
    puVar1 = (undefined4 *)uac_mem_malloc_my(0x10,0x245);
    if (puVar1 == (undefined4 *)0x0) {
      printf("%s:%d Warning: root != NULL failed.\n","rbtree_init",0x246);
    }
    else {
      *puVar1 = 0;
      puVar1[1] = param_1;
      puVar1[2] = param_2;
      puVar1[3] = param_3;
    }
  }
  return puVar1;
}

