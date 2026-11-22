// func sensor_test_db_case_result_init @ 005040c0 size=476

undefined4 sensor_test_db_case_result_init(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_case_result_init ENTER,case\n",
           "sensor_test_db_case_result_init",0x11b6);
  }
  if (((int)param_1 < 0) || (g_sensor_test_case_num_max <= param_1)) {
    if (sensor_test_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_DEBUG]%s()/%d input invalid\n";
    uVar2 = 0x11bc;
  }
  else {
    iVar4 = param_1 * 4;
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    if (*(int *)(l_sensor_test_result_list_hash + iVar4) != 0) {
      FUN_00408310();
      *(undefined4 *)(l_sensor_test_result_list_hash + iVar4) = 0;
    }
    iVar5 = param_1 * 0xc;
    while (iVar1 = FUN_004081b0(l_sensor_test_result_list + iVar5), iVar1 != 0) {
      FUN_00408500(iVar1);
      sensor_test_db_bssid_result_node_mem_free(iVar1);
    }
    FUN_0051ad88(l_sensor_test_result_list + iVar5);
    puVar3 = (undefined4 *)(l_sensor_test_result_list_hash + iVar4);
    *puVar3 = 0;
    uVar2 = FUN_004080a0(_sensor_test_db_hash_obj,_sensor_test_db_hash_key,_sensor_test_db_hash_cmp,
                         1000);
    *puVar3 = uVar2;
    if (*(int *)(l_sensor_test_result_list_hash + iVar4) != 0) {
      FUN_0051ad88(l_sensor_test_result_list + iVar5);
      FUN_00407f30(l_sensor_test_db_mutex);
      return 0;
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d create hash failed.\n";
    uVar2 = 0x11db;
  }
  printf(__format,"sensor_test_db_case_result_init",uVar2);
  return 0xffffffff;
}

