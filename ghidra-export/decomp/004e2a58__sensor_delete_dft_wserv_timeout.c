// func _sensor_delete_dft_wserv_timeout @ 004e2a58 size=100

void _sensor_delete_dft_wserv_timeout(void)

{
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  wait_for_delete_dft_wserv_id = 0;
  if (g_dft_backhaul_wserv_id != -1) {
    uac_wservice_entry_delete_by_id();
    g_dft_backhaul_wserv_id = -1;
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  return;
}

