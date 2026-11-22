// func update_wstat_report_time @ 004a05d0 size=40

undefined4 update_wstat_report_time(void)

{
  undefined4 extraout_v1;
  
  FUN_00407e70();
  g_last_report_fit_ap_dev_wstat_time = extraout_v1;
  return 0;
}

