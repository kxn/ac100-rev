// func is_implicit_leave @ 0063a43c size=24

undefined4 is_implicit_leave(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((*(uint *)(param_1 + 100) & 2) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}

