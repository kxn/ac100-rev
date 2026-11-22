// func cw_priv_roaming_calculate_result_free @ 005bbc9c size=176

undefined4 cw_priv_roaming_calculate_result_free(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0xc) == 0) {
      iVar1 = *(int *)(iVar3 + 0x10);
    }
    else {
      FUN_00407df0();
      iVar1 = *(int *)(iVar3 + 0x10);
    }
    uVar4 = 0;
    if (iVar1 != 0) {
      do {
        uVar2 = *(uint *)(iVar3 + 4);
        while( true ) {
          if (uVar2 <= uVar4) {
            FUN_00407df0();
            goto LAB_005bbd20;
          }
          iVar1 = uVar4 * 0x1c;
          uVar4 = uVar4 + 1;
          if (*(int *)(*(int *)(iVar3 + 0x10) + iVar1 + 0x18) == 0) break;
          FUN_00407df0();
          uVar2 = *(uint *)(iVar3 + 4);
        }
      } while( true );
    }
LAB_005bbd20:
    FUN_00407df0(iVar3);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

