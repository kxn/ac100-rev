// func cw_decryption_error_report_period_free @ 00573c40 size=60

undefined4 cw_decryption_error_report_period_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

