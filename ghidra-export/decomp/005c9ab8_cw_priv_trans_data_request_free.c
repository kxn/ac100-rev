// func cw_priv_trans_data_request_free @ 005c9ab8 size=88

undefined4 cw_priv_trans_data_request_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 8) = 0;
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

