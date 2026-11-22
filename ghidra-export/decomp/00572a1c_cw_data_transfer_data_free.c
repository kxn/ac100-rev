// func cw_data_transfer_data_free @ 00572a1c size=84

undefined4 cw_data_transfer_data_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

