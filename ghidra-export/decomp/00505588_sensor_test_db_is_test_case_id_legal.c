// func sensor_test_db_is_test_case_id_legal @ 00505588 size=128

bool sensor_test_db_is_test_case_id_legal(uint param_1)

{
  bool bVar2;
  int iVar1;
  
  bVar2 = false;
  if ((-1 < (int)param_1) && (param_1 < g_sensor_test_case_num_max)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    iVar1 = *(int *)(l_sensor_test_case_list + param_1 * 4);
    FUN_00407f30(l_sensor_test_db_mutex);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}

