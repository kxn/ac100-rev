// func rrm_ap_pwr_para_reset @ 004b3614 size=292

void rrm_ap_pwr_para_reset(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    if (*(void **)(param_1 + 8) == (void *)0x0) {
      iVar2 = *(int *)(param_1 + 0x1c);
    }
    else {
      memset(*(void **)(param_1 + 8),0,*(size_t *)(param_1 + 0xc));
      iVar2 = *(int *)(param_1 + 0x1c);
    }
    iVar1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    if (iVar2 != 0) {
      for (; iVar1 < *(int *)(param_1 + 0xc); iVar1 = iVar1 + 1) {
        iVar2 = *(int *)(param_1 + 0x1c) + iVar1 * 0xf;
        *(undefined1 *)(iVar2 + 0xc) = 0;
        *(undefined1 *)(iVar2 + 0xd) = 0;
        *(undefined1 *)(iVar2 + 0xe) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x1c) + iVar1 * 0xf + 0xb) = 0;
      }
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
      }
      if (iVar2 + 4 == param_1 + 0x20) break;
      iVar1 = *(int *)(iVar2 + 0x24);
      iVar2 = iVar2 + 4;
    }
  }
  return;
}

