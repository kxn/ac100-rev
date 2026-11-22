// func msg_ele_add @ 00594a18 size=108

int msg_ele_add(int param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 != 0) && (iVar1 = FUN_00408450(0x1c,0xeb), iVar1 != 0)) {
    *(undefined2 *)(iVar1 + 0xc) = param_2;
    FUN_004086b0(param_1,iVar1);
    FUN_0051ad88(iVar1 + 0x10);
  }
  return iVar1;
}

