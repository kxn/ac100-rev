// func rrm_ap_pwr_para_destroy @ 004b3308 size=336

void rrm_ap_pwr_para_destroy(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar2 = *(int *)(param_1 + 8);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x18) = 0;
      iVar2 = *(int *)(param_1 + 8);
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x14);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 8) = 0;
      iVar2 = *(int *)(param_1 + 0x14);
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x1c);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x14) = 0;
      iVar2 = *(int *)(param_1 + 0x1c);
    }
    if (iVar2 != 0) {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x20);
    iVar2 = param_1;
    while( true ) {
      iVar3 = 0;
      if (iVar1 != 0) {
        for (; iVar3 < *(int *)(param_1 + 0xc); iVar3 = iVar3 + 1) {
          iVar1 = *(int *)(iVar2 + 0x20);
          while (iVar1 = FUN_004081b0(iVar1 + iVar3 * 0xc), iVar1 != 0) {
            FUN_00408500(iVar1);
            FUN_00407df0(iVar1);
            iVar1 = *(int *)(iVar2 + 0x20);
          }
        }
        FUN_00407df0(*(undefined4 *)(iVar2 + 0x20));
        *(undefined4 *)(iVar2 + 0x20) = 0;
      }
      if (iVar2 + 4 == param_1 + 0x20) break;
      iVar1 = *(int *)(iVar2 + 0x24);
      iVar2 = iVar2 + 4;
    }
    FUN_00407df0(param_1);
    return;
  }
  return;
}

