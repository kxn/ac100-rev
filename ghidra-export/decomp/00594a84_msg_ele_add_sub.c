// func msg_ele_add_sub @ 00594a84 size=96

void msg_ele_add_sub(int param_1,undefined2 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = FUN_00408450(0x10,0x107);
    if (iVar1 != 0) {
      *(undefined2 *)(iVar1 + 0xc) = param_2;
      FUN_004086b0(param_1 + 0x10,iVar1);
      return;
    }
  }
  return;
}

