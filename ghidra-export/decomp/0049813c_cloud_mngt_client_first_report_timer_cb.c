// func cloud_mngt_client_first_report_timer_cb @ 0049813c size=148

void cloud_mngt_client_first_report_timer_cb(void)

{
  undefined4 extraout_v1;
  
  if (client_report_switch != 0) {
    if (ap_report_switch != 0) {
      set_stats_consumer_bit_mask(1,0);
    }
    FUN_00407e70();
    last_client_report_time = extraout_v1;
    cloud_mngt_notify_report(5);
    g_cloud_mngt_client_report_timer_id =
         FUN_00408340(client_first_report_interval,0,cloud_mngt_client_update_report_timer_cb,0,0,
                      "cloud_mngt_client_first_report_timer_cb",0x1e32);
  }
  return;
}

