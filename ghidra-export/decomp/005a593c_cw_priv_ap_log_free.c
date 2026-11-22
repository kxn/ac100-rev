// func cw_priv_ap_log_free @ 005a593c size=164

undefined4 cw_priv_ap_log_free(int param_1)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  if (puVar1 != (ushort *)0x0) {
    if ((*puVar1 != 0) && (iVar2 = 0, *(int *)(puVar1 + 2) != 0)) {
      while (iVar2 < (int)(uint)*puVar1) {
        iVar3 = iVar2 * 8;
        iVar2 = iVar2 + 1;
        if (*(int *)(*(int *)(puVar1 + 2) + iVar3 + 4) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)(puVar1 + 2) + iVar3 + 4) = 0;
        }
      }
      FUN_00407df0();
      puVar1[2] = 0;
      puVar1[3] = 0;
    }
    FUN_00407df0(puVar1);
  }
  return 0;
}

