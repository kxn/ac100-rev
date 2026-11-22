// func sensor_test_db_get_case_service_type @ 00503528 size=220

uint sensor_test_db_get_case_service_type(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((-1 < (int)param_1) && (param_1 <= g_sensor_test_case_num_max)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    iVar1 = *(int *)(l_sensor_test_case_list + param_1 * 4);
    if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 4), iVar1 == 0)) {
      uVar2 = 0;
      FUN_00407f30(l_sensor_test_db_mutex);
    }
    else {
      uVar2 = (uint)*(ushort *)(iVar1 + 0x3c);
      FUN_00407f30(l_sensor_test_db_mutex);
      if (sensor_test_debug_switch != '\0') {
        printf("[SENSOR_TEST_DEBUG]%s()/%d case_id=%d,service_type=%d\n",
               "sensor_test_db_get_case_service_type",0x1078,param_1,uVar2);
      }
    }
  }
  return uVar2;
}

