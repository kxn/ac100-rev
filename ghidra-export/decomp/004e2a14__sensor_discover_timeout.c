// func _sensor_discover_timeout @ 004e2a14 size=68

void _sensor_discover_timeout(void)

{
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  sensor_discover_timer = 0xffffffff;
  _sensor_discover_reset(0);
  FUN_00407f30(g_sensor_mngt_mutex);
  return;
}

