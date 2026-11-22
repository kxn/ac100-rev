// func sensor_di_destroy @ 004d9bec size=100

void sensor_di_destroy(void)

{
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_destroy ENTER\n","sensor_di_destroy",0x77f);
  }
  if (l_sensor_di_status_mutex != 0) {
    FUN_00408360();
    l_sensor_di_status_mutex = 0;
  }
  sensor_di_db_destroy();
  return;
}

