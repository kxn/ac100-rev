// func _wserv_change_state_timeout @ 004e232c size=68

void _wserv_change_state_timeout(void)

{
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  sensor_backhaul_set_timer = 0xffffffff;
  g_change_backhaul_wserv = 0;
  FUN_00407f30(g_sensor_mngt_mutex);
  return;
}

