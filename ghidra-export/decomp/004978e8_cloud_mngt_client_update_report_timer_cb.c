// func cloud_mngt_client_update_report_timer_cb @ 004978e8 size=236

void cloud_mngt_client_update_report_timer_cb(void)

{
  g_cloud_mngt_client_report_timer_id = -1;
  if (ap_report_switch != 0) {
    if (client_report_switch != 0) {
      cloud_mngt_notify_report(8);
    }
    if ((((ap_report_switch != 0) && (client_report_switch != 0)) &&
        (g_cloud_mngt_client_report_timer_id == -1)) &&
       ((g_cloud_mngt_client_report_timer_id =
              FUN_00408340(client_report_interval,0,cloud_mngt_client_update_report_timer_cb,0,0,
                           "cloud_mngt_client_update_report_timer_cb",0x1d30),
        g_cloud_mngt_client_report_timer_id == -1 && (cloud_mngt_err_switch != '\0')))) {
      printf("[CLOUD_MNGT_ERROR]%s()/%d Start g_cloud_mngt_client_report_timer_id failed.\n",
             "cloud_mngt_client_update_report_timer_cb",0x1d33);
      return;
    }
  }
  return;
}

