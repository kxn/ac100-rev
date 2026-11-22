// func sensor_di_get_cache_sensor_max @ 004e1d88 size=72

undefined4 sensor_di_get_cache_sensor_max(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  uVar1 = l_sensor_di_cache_sensor_max;
  FUN_00407f30(l_sensor_di_data_mutex);
  return uVar1;
}

