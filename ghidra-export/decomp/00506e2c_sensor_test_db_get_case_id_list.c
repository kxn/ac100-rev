// func sensor_test_db_get_case_id_list @ 00506e2c size=272

undefined4 sensor_test_db_get_case_id_list(int param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_case_id_list ENTER\n",
           "sensor_test_db_get_case_id_list",0x164b);
  }
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    uVar6 = 0xffffffff;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d input invalid\n","sensor_test_db_get_case_id_list",0x1651);
    }
  }
  else {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    uVar2 = 0;
    piVar4 = l_sensor_test_case_list;
    for (uVar3 = 0; uVar1 = l_sensor_test_db_mutex, uVar3 < g_sensor_test_case_num_max;
        uVar3 = uVar3 + 1) {
      if ((*piVar4 != 0) && (uVar2 < g_sensor_test_case_num_max)) {
        iVar5 = uVar2 * 4;
        uVar2 = uVar2 + 1;
        *(uint *)(param_1 + iVar5) = uVar3;
      }
      piVar4 = piVar4 + 1;
    }
    uVar6 = 0;
    *param_2 = uVar2;
    FUN_00407f30(uVar1);
  }
  return uVar6;
}

