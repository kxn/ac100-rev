// func cw_priv_roaming_trigger_free @ 005bd294 size=144

undefined4 cw_priv_roaming_trigger_free(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 != 0) {
    uVar4 = 0;
    if (*(int *)(iVar3 + 8) != 0) {
      do {
        uVar1 = *(uint *)(iVar3 + 4);
        while( true ) {
          if (uVar1 <= uVar4) {
            FUN_00407df0();
            goto LAB_005bd2fc;
          }
          iVar2 = uVar4 * 0x10;
          uVar4 = uVar4 + 1;
          if (*(int *)(*(int *)(iVar3 + 8) + iVar2 + 0xc) == 0) break;
          FUN_00407df0();
          uVar1 = *(uint *)(iVar3 + 4);
        }
      } while( true );
    }
LAB_005bd2fc:
    FUN_00407df0(iVar3);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

