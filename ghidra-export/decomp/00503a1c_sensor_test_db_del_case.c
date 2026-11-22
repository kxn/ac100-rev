// func sensor_test_db_del_case @ 00503a1c size=596

undefined4 sensor_test_db_del_case(uint param_1,int param_2)

{
  uint *puVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_del_case ENTER, id=%d\n",
           "sensor_test_db_del_case",0x10f8,param_1);
  }
  if (g_sensor_test_case_num_max <= param_1) {
    return 0xffffffff;
  }
  if ((int)param_1 < 0) {
    return 0xffffffff;
  }
  iVar3 = param_1 * 4;
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  if (*(int *)(l_sensor_test_case_list + iVar3) == 0) {
    FUN_00407f30(l_sensor_test_db_mutex);
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d no such case to delete.\n";
    uVar2 = 0x1106;
  }
  else {
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d find case to del, id=%d\n","sensor_test_db_del_case",0x110a
             ,param_1);
    }
    sensor_test_db_case_setting_mem_free
              (*(undefined4 *)(*(int *)(l_sensor_test_case_list + iVar3) + 4));
    FUN_00407df0(*(undefined4 *)(l_sensor_test_case_list + iVar3));
    *(undefined4 *)(l_sensor_test_case_list + iVar3) = 0;
    if (*(int *)(l_sensor_test_result_list_hash + iVar3) != 0) {
      FUN_00408310();
      *(undefined4 *)(l_sensor_test_result_list_hash + iVar3) = 0;
    }
    while (iVar3 = FUN_004081b0(l_sensor_test_result_list + param_1 * 0xc), iVar3 != 0) {
      FUN_00408500(iVar3);
      sensor_test_db_bssid_result_node_mem_free(iVar3);
    }
    FUN_0051ad88(l_sensor_test_result_list + param_1 * 0xc);
    FUN_004080f0(l_sensor_test_case_id_allocator,param_1);
    FUN_00407f30(l_sensor_test_db_mutex);
    if (param_2 != 1) {
      return 0;
    }
    puVar1 = (uint *)FUN_00408450(8,0x1128);
    if (puVar1 != (uint *)0x0) {
      *puVar1 = param_1;
      puVar1[1] = 0;
      sensor_test_db_msg_send(1,puVar1);
      return 0;
    }
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d case_ptr mem malloc fail\n";
    uVar2 = 0x112b;
  }
  printf(__format,"sensor_test_db_del_case",uVar2);
  return 0xffffffff;
}

