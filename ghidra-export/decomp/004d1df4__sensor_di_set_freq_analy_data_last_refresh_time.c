// func _sensor_di_set_freq_analy_data_last_refresh_time @ 004d1df4 size=68

void _sensor_di_set_freq_analy_data_last_refresh_time(undefined2 param_1)

{
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  l_sensor_di_freq_analy_last_refresh_time = param_1;
  FUN_00407f30(l_sensor_di_status_mutex);
  return;
}

