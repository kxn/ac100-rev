// func ucl_auth_db_fini @ 004a88f0 size=108

undefined4 ucl_auth_db_fini(void)

{
  if (g_first_report_mutex != 0) {
    uac_mutex_destroy();
    g_first_report_mutex = 0;
  }
  if (g_offline_station_mutex != 0) {
    uac_mutex_destroy();
    g_offline_station_mutex = 0;
  }
  return 0;
}

