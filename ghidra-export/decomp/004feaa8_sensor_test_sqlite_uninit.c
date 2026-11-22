// func sensor_test_sqlite_uninit @ 004feaa8 size=60

undefined4 sensor_test_sqlite_uninit(void)

{
  if (l_sensor_test_db_ptr != 0) {
    FUN_004080b0();
    l_sensor_test_db_ptr = 0;
  }
  return 0;
}

