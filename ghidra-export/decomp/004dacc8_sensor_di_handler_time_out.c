// func sensor_di_handler_time_out @ 004dacc8 size=148

void sensor_di_handler_time_out(void)

{
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : handler_refresh_timer ENTER\n",
           "sensor_di_handler_time_out",0x1131);
  }
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  l_sensor_di_status = 0;
  l_sensor_di_timer = 0xffffffff;
  l_sensor_di_start_local_timestamp = 0;
  DAT_007685dc = 0;
  l_sensor_di_start_utc_timestamp = 0;
  l_sensor_di_last_inspection_time = 600;
  FUN_00407f30(l_sensor_di_status_mutex);
  sensor_di_cw_send_stop_notify_all_sensors();
  return;
}

