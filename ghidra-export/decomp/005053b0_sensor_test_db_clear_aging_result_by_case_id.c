// func sensor_test_db_clear_aging_result_by_case_id @ 005053b0 size=472

undefined4 sensor_test_db_clear_aging_result_by_case_id(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_clear_aging_result_by_case_id ENTER case_id=%d,aging_timestamp=%d\n"
           ,"sensor_test_db_clear_aging_result_by_case_id",0x1468,param_1,param_2);
  }
  uVar1 = 0xffffffff;
  if ((-1 < (int)param_1) && (param_1 < g_sensor_test_case_num_max)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    if (l_sensor_test_result_list != 0) {
      for (iVar2 = FUN_004081b0(l_sensor_test_result_list + param_1 * 0xc); iVar2 != 0;
          iVar2 = FUN_00408680(iVar2)) {
        _sensor_test_db_result_list_aging(iVar2 + 0x48,param_2);
        _sensor_test_db_result_list_aging(iVar2 + 0x54,param_2);
        _sensor_test_db_result_list_aging(iVar2 + 0x60,param_2);
        _sensor_test_db_result_list_aging(iVar2 + 0x6c,param_2);
        _sensor_test_db_result_list_aging(iVar2 + 0x78,param_2);
        for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(iVar2 + 0x95); iVar3 = iVar3 + 1) {
          _sensor_test_db_result_list_aging(*(int *)(iVar2 + 0x84) + iVar3 * 0xc,param_2);
        }
        for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(iVar2 + 0x96); iVar3 = iVar3 + 1) {
          _sensor_test_db_result_list_aging(*(int *)(iVar2 + 0x88) + iVar3 * 0xc,param_2);
        }
        for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(iVar2 + 0x97); iVar3 = iVar3 + 1) {
          _sensor_test_db_result_list_aging(*(int *)(iVar2 + 0x8c) + iVar3 * 0xc,param_2);
        }
        for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(iVar2 + 0x98); iVar3 = iVar3 + 1) {
          _sensor_test_db_result_list_aging(*(int *)(iVar2 + 0x90) + iVar3 * 0xc,param_2);
        }
      }
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

