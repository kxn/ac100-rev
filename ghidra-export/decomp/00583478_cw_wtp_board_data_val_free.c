// func cw_wtp_board_data_val_free @ 00583478 size=128

void cw_wtp_board_data_val_free(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  while (iVar1 = FUN_004081b0(param_1 + 4), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
    FUN_00407df0(iVar1);
  }
  FUN_00407df0(param_1);
  return;
}

