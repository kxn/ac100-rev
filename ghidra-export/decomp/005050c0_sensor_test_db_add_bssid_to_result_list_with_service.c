// func sensor_test_db_add_bssid_to_result_list_with_service @ 005050c0 size=752

undefined4
sensor_test_db_add_bssid_to_result_list_with_service(uint param_1,int param_2,void *param_3)

{
  int iVar1;
  void *__s;
  char *__format;
  undefined4 uVar2;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_add_bssid_to_result_list_with_service ENTER,case_id=%d\n"
           ,"sensor_test_db_add_bssid_to_result_list_with_service",0x137c,param_1);
  }
  if (((((int)param_1 < 0) || (g_sensor_test_case_num_max <= param_1)) || (param_3 == (void *)0x0))
     || (param_2 == 0)) {
    __s = (void *)0x0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d invalid input\n",
             "sensor_test_db_add_bssid_to_result_list_with_service",0x1381);
    }
    goto LAB_00505200;
  }
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(*(undefined4 *)(l_sensor_test_result_list_hash + param_1 * 4),param_3);
  if (iVar1 != 0) {
    if (sensor_test_warning_switch != '\0') {
      printf("[SENSOR_TEST_WARNING]%s()/%d bssid already exists, do nothing\n",
             "sensor_test_db_add_bssid_to_result_list_with_service",0x1389);
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    return 0;
  }
  __s = (void *)FUN_00408450(0x9c,0x138f);
  if (__s == (void *)0x0) {
    if (sensor_test_err_switch != '\0') {
      __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
      uVar2 = 0x1392;
LAB_00505350:
      printf(__format,"sensor_test_db_add_bssid_to_result_list_with_service",uVar2);
    }
  }
  else {
    memset(__s,0,0x9c);
    memcpy((void *)((int)__s + 0x3e),param_3,6);
    iVar1 = _sensor_test_db_build_lists_for_bssid_result_node(__s,param_2);
    if (iVar1 == -1) {
      if (sensor_test_err_switch != '\0') {
        __format = "[SENSOR_TEST_ERROR]%s()/%d build_config_list_for_bssid_result_node fail\n";
        uVar2 = 0x139b;
        goto LAB_00505350;
      }
    }
    else {
      FUN_004086b0(l_sensor_test_result_list + param_1 * 0xc,__s);
      iVar1 = *(int *)(l_sensor_test_result_list_hash + param_1 * 4);
      if (iVar1 != 0) {
        FUN_00408380(iVar1,__s);
        FUN_00407f30(l_sensor_test_db_mutex);
        if (sensor_test_debug_switch == '\0') {
          return 0;
        }
        printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_add_bssid success EXIT\n",
               "sensor_test_db_add_bssid_to_result_list_with_service",0x13ac);
        return 0;
      }
      if (sensor_test_err_switch != '\0') {
        printf("[SENSOR_TEST_ERROR]%s()/%d hash not exist,case_id=%d\n",
               "sensor_test_db_add_bssid_to_result_list_with_service",0x13a4,param_1);
      }
      FUN_00408500(__s);
    }
  }
  FUN_00407f30(l_sensor_test_db_mutex);
LAB_00505200:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d sensor_test_db_add_bssid fail EXIT\n",
           "sensor_test_db_add_bssid_to_result_list_with_service",0x13b0);
  }
  sensor_test_db_bssid_result_node_mem_free(__s);
  return 0xffffffff;
}

