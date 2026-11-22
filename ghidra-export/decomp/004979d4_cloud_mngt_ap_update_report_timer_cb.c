// func cloud_mngt_ap_update_report_timer_cb @ 004979d4 size=332

void cloud_mngt_ap_update_report_timer_cb(void)

{
  uint extraout_v1;
  
  g_cloud_mngt_ap_report_timer_id = -1;
  if (ap_report_switch != 0) {
    if ((ap_offline_or_online != 0) || (ap_update_count = ap_update_count + 1, 2 < ap_update_count))
    {
      ap_offline_or_online = 0;
      ap_update_count = 0;
      cloud_mngt_notify_report(6);
      cloud_mngt_notify_report(7);
      FUN_00407e70();
      if ((last_ap_add_time < extraout_v1) &&
         (ap_add_report_interval < extraout_v1 - last_ap_add_time)) {
        cloud_mngt_notify_report(4);
      }
    }
    if ((((ap_report_switch != 0) && (g_cloud_mngt_ap_report_timer_id == -1)) &&
        (g_cloud_mngt_ap_report_timer_id =
              FUN_00408340(ap_report_interval,0,cloud_mngt_ap_update_report_timer_cb,0,0,
                           "cloud_mngt_ap_update_report_timer_cb",0x1d1f),
        g_cloud_mngt_ap_report_timer_id == -1)) && (cloud_mngt_err_switch != '\0')) {
      printf("[CLOUD_MNGT_ERROR]%s()/%d Start g_cloud_mngt_ap_report_timer_id failed.\n",
             "cloud_mngt_ap_update_report_timer_cb",0x1d22);
      return;
    }
  }
  return;
}

