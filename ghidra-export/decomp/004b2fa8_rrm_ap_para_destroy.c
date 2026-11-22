// func rrm_ap_para_destroy @ 004b2fa8 size=392

void rrm_ap_para_destroy(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar1 = *(int *)(param_1 + 8);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x18) = 0;
      iVar1 = *(int *)(param_1 + 8);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x14);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 8) = 0;
      iVar1 = *(int *)(param_1 + 0x14);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x14) = 0;
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x20);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x1c) = 0;
      iVar1 = *(int *)(param_1 + 0x20);
    }
    iVar2 = 0;
    if (iVar1 != 0) {
      for (; iVar2 < *(int *)(param_1 + 0xc); iVar2 = iVar2 + 1) {
        iVar1 = *(int *)(param_1 + 0x20);
        while (iVar1 = FUN_004081b0(iVar1 + iVar2 * 0xc), iVar1 != 0) {
          FUN_00408500(iVar1);
          FUN_00407df0(iVar1);
          iVar1 = *(int *)(param_1 + 0x20);
        }
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x20));
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
    iVar1 = 0;
    if (*(int *)(param_1 + 0x24) != 0) {
      for (; iVar1 < *(int *)(param_1 + 0xc); iVar1 = iVar1 + 1) {
        iVar2 = *(int *)(param_1 + 0x24);
        while (iVar2 = FUN_004081b0(iVar2 + iVar1 * 0xc), iVar2 != 0) {
          FUN_00408500(iVar2);
          FUN_00407df0(iVar2);
          iVar2 = *(int *)(param_1 + 0x24);
        }
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    FUN_00407df0(param_1);
    return;
  }
  return;
}

