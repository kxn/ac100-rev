// func cloud_mngt_rrm_finish_cb @ 0048eedc size=44

undefined4 cloud_mngt_rrm_finish_cb(void)

{
  if (ap_report_switch != 0) {
    cloud_mngt_notify_report(0xb);
  }
  return 0;
}

