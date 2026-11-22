// func sensor_test_db_set_case @ 00503c70 size=376

undefined4 sensor_test_db_set_case(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_set_case ENTER,case_id=%d\n",
           "sensor_test_db_set_case",0x1138,param_1);
  }
  uVar4 = 0xffffffff;
  if (((param_1 < g_sensor_test_case_num_max) && (-1 < (int)param_1)) && (param_2 != 0)) {
    iVar3 = param_1 * 4;
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    if (*(int *)(l_sensor_test_case_list + iVar3) == 0) {
      FUN_00407f30(l_sensor_test_db_mutex);
    }
    else {
      iVar2 = _sensor_test_db_deep_copy_test_case_setting(param_2);
      if (iVar2 == 0) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d db_deep_copy_setting fail.\n","sensor_test_db_set_case"
                 ,0x114a);
        }
        uVar4 = 0xffffffff;
        FUN_00407f30(l_sensor_test_db_mutex);
      }
      else {
        if (*(int *)(*(int *)(l_sensor_test_case_list + iVar3) + 4) != 0) {
          sensor_test_db_case_setting_mem_free();
          *(undefined4 *)(*(int *)(l_sensor_test_case_list + iVar3) + 4) = 0;
        }
        uVar1 = l_sensor_test_db_mutex;
        uVar4 = 0;
        *(int *)(*(int *)(l_sensor_test_case_list + iVar3) + 4) = iVar2;
        FUN_00407f30(uVar1);
      }
    }
  }
  return uVar4;
}

