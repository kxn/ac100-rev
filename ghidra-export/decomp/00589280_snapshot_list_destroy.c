// func snapshot_list_destroy @ 00589280 size=92

undefined4 snapshot_list_destroy(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    while (iVar2 = FUN_004081b0(param_1), iVar2 != 0) {
      FUN_00408500(iVar2);
      snapshot_destroy(iVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}

