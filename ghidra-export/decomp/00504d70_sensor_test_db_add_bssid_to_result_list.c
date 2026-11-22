// func sensor_test_db_add_bssid_to_result_list @ 00504d70 size=848

undefined4 sensor_test_db_add_bssid_to_result_list(uint param_1,void *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  void *__s;
  int iVar3;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_add_bssid ENTER,case_id=%d\n",
           "sensor_test_db_add_bssid_to_result_list",0x1337,param_1);
  }
  if ((((int)param_1 < 0) || (g_sensor_test_case_num_max <= param_1)) || (param_2 == (void *)0x0)) {
    __s = (void *)0x0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d invalid input\n","sensor_test_db_add_bssid_to_result_list",
             0x133c);
    }
    goto LAB_00504f90;
  }
  iVar3 = param_1 * 4;
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(*(undefined4 *)(l_sensor_test_result_list_hash + iVar3),param_2);
  if (iVar1 != 0) {
    if (sensor_test_warning_switch != '\0') {
      printf("[SENSOR_TEST_WARNING]%s()/%d bssid already exists, do nothing\n",
             "sensor_test_db_add_bssid_to_result_list",0x1344);
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    return 0;
  }
  if ((*(int *)(l_sensor_test_case_list + iVar3) == 0) ||
     (*(int *)(*(int *)(l_sensor_test_case_list + iVar3) + 4) == 0)) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d no such test case\n",
             "sensor_test_db_add_bssid_to_result_list",0x134c);
    }
    __s = (void *)0x0;
    FUN_00407f30(l_sensor_test_db_mutex);
    goto LAB_00504f90;
  }
  __s = (void *)FUN_00408450(0x9c,0x1352);
  if (__s == (void *)0x0) {
    if (sensor_test_err_switch != '\0') {
      __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
      uVar2 = 0x1355;
LAB_00505044:
      printf(__format,"sensor_test_db_add_bssid_to_result_list",uVar2);
    }
  }
  else {
    memset(__s,0,0x9c);
    memcpy((void *)((int)__s + 0x3e),param_2,6);
    iVar1 = _sensor_test_db_build_lists_for_bssid_result_node
                      (__s,*(int *)(*(int *)(l_sensor_test_case_list + iVar3) + 4) + 0x3c);
    if (iVar1 == -1) {
      if (sensor_test_err_switch != '\0') {
        __format = "[SENSOR_TEST_ERROR]%s()/%d build_config_list_for_bssid_result_node fail\n";
        uVar2 = 0x135e;
        goto LAB_00505044;
      }
    }
    else {
      FUN_004086b0(l_sensor_test_result_list + param_1 * 0xc,__s);
      if (*(int *)(l_sensor_test_result_list_hash + iVar3) != 0) {
        FUN_00408380(*(int *)(l_sensor_test_result_list_hash + iVar3),__s);
        FUN_00407f30(l_sensor_test_db_mutex);
        if (sensor_test_debug_switch == '\0') {
          return 0;
        }
        printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_add_bssid success EXIT\n",
               "sensor_test_db_add_bssid_to_result_list",0x136f);
        return 0;
      }
      if (sensor_test_err_switch != '\0') {
        printf("[SENSOR_TEST_ERROR]%s()/%d hash not exist,case_id=%d\n",
               "sensor_test_db_add_bssid_to_result_list",0x1367,param_1);
      }
      FUN_00408500(__s);
    }
  }
  FUN_00407f30(l_sensor_test_db_mutex);
LAB_00504f90:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d sensor_test_db_add_bssid fail EXIT\n",
           "sensor_test_db_add_bssid_to_result_list",0x1373);
  }
  sensor_test_db_bssid_result_node_mem_free(__s);
  return 0xffffffff;
}

