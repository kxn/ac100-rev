// func _sensor_di_get_freq_analy_data_last_refresh_time @ 00408ea4 size=72

int _sensor_di_get_freq_analy_data_last_refresh_time(void)

{
  int iVar1;
  
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  iVar1 = (int)l_sensor_di_freq_analy_last_refresh_time;
  FUN_00407f30(l_sensor_di_status_mutex);
  return iVar1;
}

