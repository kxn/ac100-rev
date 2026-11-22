// func update_params_report_time @ 004a2560 size=40

undefined4 update_params_report_time(void)

{
  undefined4 extraout_v1;
  
  FUN_00407e70();
  g_last_report_fit_ap_params_time = extraout_v1;
  return 0;
}

