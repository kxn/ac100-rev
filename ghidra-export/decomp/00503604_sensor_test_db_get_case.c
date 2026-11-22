// func sensor_test_db_get_case @ 00503604 size=300

int sensor_test_db_get_case(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_case ENTER,case_id=%d\n",
           "sensor_test_db_get_case",0x108f,param_1);
  }
  if ((param_1 < g_sensor_test_case_num_max) && (-1 < (int)param_1)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    iVar1 = *(int *)(l_sensor_test_case_list + param_1 * 4);
    iVar2 = 0;
    if ((iVar1 != 0) &&
       (((*(int *)(iVar1 + 4) != 0 &&
         (iVar2 = _sensor_test_db_deep_copy_test_case_setting(), iVar2 == 0)) &&
        (sensor_test_err_switch != '\0')))) {
      printf("[SENSOR_TEST_ERROR]%s()/%d deep_copy_case_setting fail\n","sensor_test_db_get_case",
             0x109e);
    }
    FUN_00407f30(l_sensor_test_db_mutex);
  }
  else {
    iVar2 = 0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d invalid case_id\n","sensor_test_db_get_case",0x1094);
    }
  }
  return iVar2;
}

