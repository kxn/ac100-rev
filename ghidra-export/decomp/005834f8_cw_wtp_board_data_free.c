// func cw_wtp_board_data_free @ 005834f8 size=60

undefined4 cw_wtp_board_data_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    cw_wtp_board_data_val_free();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

