// func snapshot_destroy @ 0059551c size=300

undefined4 snapshot_destroy(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    while (iVar2 = FUN_004081b0(param_1 + 0x48), iVar2 != 0) {
      FUN_00408500(iVar2);
      while (iVar3 = FUN_004081b0(iVar2 + 0x10), iVar3 != 0) {
        FUN_00408500(iVar3);
        FUN_00407df0(iVar3);
      }
      FUN_00407df0(iVar2);
    }
    while (iVar2 = FUN_004081b0(param_1 + 0x3c), iVar2 != 0) {
      FUN_00408500(iVar2);
      while (iVar3 = FUN_004081b0(iVar2 + 0x10), iVar3 != 0) {
        FUN_00408500(iVar3);
        FUN_00407df0(iVar3);
      }
      FUN_00407df0(iVar2);
    }
    if (*(int *)(param_1 + 0x54) == 0) {
      iVar2 = *(int *)(param_1 + 0x58);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x54) = 0;
      iVar2 = *(int *)(param_1 + 0x58);
    }
    if (iVar2 != 0) {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x58) = 0;
    }
    FUN_00407df0(param_1);
    uVar1 = 0;
  }
  return uVar1;
}

