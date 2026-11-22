// func cw_priv_rrm_neighs_list_val_free @ 005be34c size=180

void cw_priv_rrm_neighs_list_val_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      while (iVar1 < (int)(uint)*(ushort *)(param_1 + 2)) {
        iVar2 = iVar1 * 0xc;
        iVar1 = iVar1 + 1;
        if (*(int *)(*(int *)(param_1 + 4) + iVar2 + 8) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)(param_1 + 4) + iVar2 + 8) = 0;
        }
      }
      FUN_00407df0();
      *(undefined4 *)(param_1 + 4) = 0;
    }
    FUN_00407df0(param_1);
    return;
  }
  return;
}

