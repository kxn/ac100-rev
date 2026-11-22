// func sensor_test_db_case_id_cost @ 004feedc size=100

void sensor_test_db_case_id_cost(int param_1)

{
  if (-1 < param_1) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    FUN_00408440(l_sensor_test_case_id_allocator,param_1);
    FUN_00407f30(l_sensor_test_db_mutex);
    return;
  }
  return;
}

