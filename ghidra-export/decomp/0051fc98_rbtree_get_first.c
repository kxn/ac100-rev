// func rbtree_get_first @ 0051fc98 size=1

undefined4 rbtree_get_first(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int in_t9;
  
  if (param_1 == 0) {
    (**(code **)(in_t9 + 0x239c38))
              (*(int *)(in_t9 + 0x239490) + 0x3480,*(int *)(in_t9 + 0x239490) + 0x35ac,0x2c1,param_4
               ,in_t9 + 0x241468);
    uVar2 = 0;
  }
  else {
    iVar1 = rb_first();
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return uVar2;
}

