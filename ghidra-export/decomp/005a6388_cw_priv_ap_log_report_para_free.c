// func cw_priv_ap_log_report_para_free @ 005a6388 size=44

undefined4 cw_priv_ap_log_report_para_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
  }
  return 0;
}

