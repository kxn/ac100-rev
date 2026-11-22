// func cloud_mngt_rrm_start_cb @ 0048ef08 size=44

undefined4 cloud_mngt_rrm_start_cb(void)

{
  if (ap_report_switch != 0) {
    cloud_mngt_notify_report(10);
  }
  return 0;
}

