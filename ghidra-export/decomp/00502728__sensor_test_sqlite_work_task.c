// func _sensor_test_sqlite_work_task @ 00502728 size=284

void _sensor_test_sqlite_work_task(void)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = 0;
  local_20 = 0;
  local_28 = 0;
switchD_005027dc_caseD_0:
LAB_00502774:
  while (iVar1 = FUN_00408250(g_sensor_test_msgq,&local_24,8,0xffffffff,&local_28), iVar1 == -1) {
    if (sensor_test_warning_switch != '\0') {
      printf("[SENSOR_TEST_WARNING]%s()/%d receive msgs error\n\n","_sensor_test_sqlite_work_task",
             0x5cd);
    }
  }
  switch(local_24) {
  case 0:
  case 3:
  case 6:
  case 7:
    goto switchD_005027dc_caseD_0;
  case 1:
    _sensor_test_sqlite_case_delete(local_20);
    goto LAB_00502774;
  case 2:
    _sensor_test_sqlite_case_update(local_20);
    goto LAB_00502774;
  case 4:
    _sensor_test_sqlite_bssid_alloc_insert(local_20);
    goto LAB_00502774;
  case 5:
    _sensor_test_sqlite_bssid_alloc_delete(local_20);
    goto LAB_00502774;
  default:
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d unknown msg type:%d.\n\n","_sensor_test_sqlite_work_task",
             0x5e7);
    }
    goto LAB_00502774;
  }
}

