// func _update_backhaul_to_wserv_cfg_immediately @ 004e24b4 size=68

void _update_backhaul_to_wserv_cfg_immediately(void)

{
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  _clear_backhaul_wserv_cfg();
  FUN_00407f30(g_sensor_mngt_mutex);
  system("/usr/lib/lua/sensor/bh_wserv_set");
  return;
}

