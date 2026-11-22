// func sensor_discover_exit @ 004e8b58 size=148

undefined4 sensor_discover_exit(void)

{
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if (g_sensor_enable == 0) {
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Sensor(%d) is closed\n","sensor_discover_exit",0xb23,0);
    }
  }
  else {
    _sensor_discover_reset(0);
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  return 0;
}

