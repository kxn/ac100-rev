// func sensor_test_sql_add_bssid_alloc_table @ 005043bc size=388

undefined4 sensor_test_sql_add_bssid_alloc_table(uint param_1,void *param_2,uint param_3)

{
  uint *puVar1;
  void *__dest;
  char *__format;
  undefined4 uVar2;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_sql_add_bssid_alloc_table ENTER\n",
           "sensor_test_sql_add_bssid_alloc_table",0x11fd);
  }
  if ((((param_2 == (void *)0x0) || ((int)param_1 < 0)) || (g_sensor_test_case_num_max <= param_1))
     || ((int)param_3 < 1)) {
    if (sensor_test_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_DEBUG]%s()/%d input invalid\n";
    uVar2 = 0x1202;
  }
  else {
    puVar1 = (uint *)FUN_00408450(0xc,0x1206);
    if (puVar1 == (uint *)0x0) {
      if (sensor_test_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[SENSOR_TEST_ERROR]%s()/%d bssid_alloc_ptr mem malloc fail\n";
      uVar2 = 0x1209;
    }
    else {
      *puVar1 = param_1;
      puVar1[1] = param_3;
      puVar1[2] = 0;
      __dest = (void *)FUN_00408450(param_3 * 0x24,0x120f);
      puVar1[2] = (uint)__dest;
      if (__dest != (void *)0x0) {
        memcpy(__dest,param_2,param_3 * 0x24);
        uVar2 = sensor_test_db_msg_send(4,puVar1);
        return uVar2;
      }
      if (sensor_test_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[SENSOR_TEST_ERROR]%s()/%d bssid_alloc_array mem malloc fail\n";
      uVar2 = 0x1212;
    }
  }
  printf(__format,"sensor_test_sql_add_bssid_alloc_table",uVar2);
  return 0xffffffff;
}

