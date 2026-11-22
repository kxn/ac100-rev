// func cw_msg_ele_remove @ 00562c94 size=1

undefined4 cw_msg_ele_remove(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = FUN_004081b0(param_1 + 0x1c);
    while (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x10) == param_2) {
        FUN_00408500(iVar2);
        FUN_00407df0(iVar2);
        return 0;
      }
      iVar2 = FUN_00408680();
    }
    uVar1 = 0;
  }
  return uVar1;
}

