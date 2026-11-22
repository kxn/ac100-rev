// func _update_backhaul_to_wserv_cfg_timeout @ 004e24f8 size=76

void _update_backhaul_to_wserv_cfg_timeout(void)

{
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  sensor_backhaul_set_timer = 0xffffffff;
  _clear_backhaul_wserv_cfg();
  FUN_00407f30(g_sensor_mngt_mutex);
  system("/usr/lib/lua/sensor/bh_wserv_set");
  return;
}

