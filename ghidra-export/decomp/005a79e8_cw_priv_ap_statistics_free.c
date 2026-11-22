// func cw_priv_ap_statistics_free @ 005a79e8 size=104

undefined4 cw_priv_ap_statistics_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x2c) == 0) {
      iVar1 = *(int *)(iVar2 + 0x30);
    }
    else {
      FUN_00407df0();
      iVar1 = *(int *)(iVar2 + 0x30);
    }
    if (iVar1 != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar2);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

