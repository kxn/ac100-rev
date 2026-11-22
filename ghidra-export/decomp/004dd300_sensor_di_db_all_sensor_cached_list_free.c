// func sensor_di_db_all_sensor_cached_list_free @ 004dd300 size=160

void sensor_di_db_all_sensor_cached_list_free(void)

{
  int iVar1;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : free_whole_sensor_cached_list ENTER\n",
           "sensor_di_db_all_sensor_cached_list_free",0x770);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  while (iVar1 = FUN_004081b0(&l_sensor_di_cached_sensor_list), iVar1 != 0) {
    FUN_00408500(iVar1);
    _sensor_di_db_sensor_di_data_free(iVar1);
  }
  FUN_00407f30(l_sensor_di_data_mutex);
  return;
}

