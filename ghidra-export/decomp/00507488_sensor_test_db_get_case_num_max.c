// func sensor_test_db_get_case_num_max @ 00507488 size=72

undefined4 sensor_test_db_get_case_num_max(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  uVar1 = g_sensor_test_case_num_max;
  FUN_00407f30(l_sensor_test_db_mutex);
  return uVar1;
}

