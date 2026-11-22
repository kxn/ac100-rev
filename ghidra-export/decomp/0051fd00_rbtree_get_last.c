// func rbtree_get_last @ 0051fd00 size=1

undefined4 rbtree_get_last(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int in_t9;
  
  if (param_1 == 0) {
    (**(code **)(in_t9 + 0x239bd0))
              (*(int *)(in_t9 + 0x239428) + 0x3480,*(int *)(in_t9 + 0x239428) + 0x35c0,0x2df,param_4
               ,in_t9 + 0x241400);
    uVar2 = 0;
  }
  else {
    iVar1 = rb_last();
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return uVar2;
}

