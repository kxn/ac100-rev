// func cw_priv_ap_log_report_para_length @ 005a6230 size=28

undefined4 cw_priv_ap_log_report_para_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xd;
  if (*(char *)(param_1 + 4) != '\x01') {
    uVar1 = 0x19;
  }
  return uVar1;
}

