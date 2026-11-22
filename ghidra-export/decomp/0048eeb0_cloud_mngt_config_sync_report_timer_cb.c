// func cloud_mngt_config_sync_report_timer_cb @ 0048eeb0 size=44

void cloud_mngt_config_sync_report_timer_cb(void)

{
  g_cloud_mngt_config_sync_report_timer_id = 0xffffffff;
  if (ap_report_switch == 0) {
    return;
  }
  cloud_mngt_notify_report(0x15);
  return;
}

