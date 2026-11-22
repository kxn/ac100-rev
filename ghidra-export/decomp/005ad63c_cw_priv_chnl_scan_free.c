// func cw_priv_chnl_scan_free @ 005ad63c size=176

undefined4 cw_priv_chnl_scan_free(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if ((*(char *)(iVar1 + 1) != '\0') && (iVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
      while (iVar2 < (int)(uint)*(byte *)(iVar1 + 1)) {
        iVar3 = iVar2 * 8;
        iVar2 = iVar2 + 1;
        if (*(int *)(*(int *)(iVar1 + 4) + iVar3 + 4) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)(iVar1 + 4) + iVar3 + 4) = 0;
        }
      }
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 4) = 0;
    }
    FUN_00407df0(iVar1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

