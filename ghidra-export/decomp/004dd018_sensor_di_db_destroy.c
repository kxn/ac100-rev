// func sensor_di_db_destroy @ 004dd018 size=100

void sensor_di_db_destroy(void)

{
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_destroy ENTER\n","sensor_di_db_destroy",
           0x723);
  }
  if (l_sensor_di_data_mutex != 0) {
    FUN_00408360();
    l_sensor_di_data_mutex = 0;
  }
  return;
}

