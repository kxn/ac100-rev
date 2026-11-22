// func cloud_mngt_fini @ 0049c4ac size=448

void cloud_mngt_fini(void)

{
  if (g_cloud_mngt_msg_thread != 0) {
    pthread_kill(g_cloud_mngt_msg_thread,3);
    g_cloud_mngt_msg_thread = 0;
  }
  if (cloud_mngt_msg_mutex != 0) {
    FUN_00408360();
    cloud_mngt_msg_mutex = 0;
  }
  if (cloud_mngt_msg_cond != 0) {
    FUN_00408220();
    cloud_mngt_msg_cond = 0;
  }
  if (g_cloud_mngt_msg_report_thread != 0) {
    pthread_kill(g_cloud_mngt_msg_report_thread,3);
    g_cloud_mngt_msg_report_thread = 0;
  }
  if (cloud_mngt_msg_report_mutex != 0) {
    FUN_00408360();
    cloud_mngt_msg_report_mutex = 0;
  }
  if (cloud_mngt_msg_report_cond != 0) {
    FUN_00408220();
    cloud_mngt_msg_report_cond = 0;
  }
  if (cloud_mngt_data_mutex != 0) {
    FUN_00408360();
    cloud_mngt_data_mutex = 0;
  }
  if (g_cloud_mngt_ap_report_timer_id != -1) {
    FUN_00408060();
    g_cloud_mngt_ap_report_timer_id = -1;
  }
  if (g_cloud_mngt_client_report_timer_id != -1) {
    FUN_00408060();
    g_cloud_mngt_client_report_timer_id = -1;
  }
  if (g_cloud_mngt_config_sync_report_timer_id != -1) {
    FUN_00408060();
    g_cloud_mngt_config_sync_report_timer_id = -1;
  }
  _cloud_mngt_sync_module_config_clear();
  if (ap_container != 0) {
    FUN_00408090();
    ap_container = 0;
  }
  if (bssid_info_changed_sc != 0) {
    FUN_00408090();
    bssid_info_changed_sc = 0;
  }
  if (client_container != 0) {
    FUN_00408090();
    client_container = 0;
  }
  if (client_events_container != 0) {
    FUN_00408090();
    client_events_container = 0;
  }
  uac_nms_report_fini();
  return;
}

