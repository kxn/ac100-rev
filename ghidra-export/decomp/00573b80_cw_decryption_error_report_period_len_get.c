// func cw_decryption_error_report_period_len_get @ 00573b80 size=12

undefined4 cw_decryption_error_report_period_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

