// func sensor_mngt_uninit @ 004e9d30 size=56

void sensor_mngt_uninit(void)

{
  if (g_sensor_mngt_mutex != 0) {
    FUN_00408360();
    g_sensor_mngt_mutex = 0;
  }
  sensor_db_uninit();
  return;
}

