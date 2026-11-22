// func cw_timer_destroy @ 0059c744 size=1

void cw_timer_destroy(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 != 0) {
    for (; iVar3 < *(int *)(param_1 + 4); iVar3 = iVar3 + 1) {
      iVar2 = *(int *)(param_1 + 0x10);
      while (iVar2 = FUN_00407fe0(iVar2 + iVar3 * 0xc), iVar2 != 0) {
        uVar1 = FUN_004081b0(*(int *)(param_1 + 0x10) + iVar3 * 0xc);
        cw_timer_remove(param_1,uVar1);
        iVar2 = *(int *)(param_1 + 0x10);
      }
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
    uac_mem_free_my(param_1);
    return;
  }
  return;
}

