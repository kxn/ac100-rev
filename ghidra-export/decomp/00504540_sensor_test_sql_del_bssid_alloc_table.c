// func sensor_test_sql_del_bssid_alloc_table @ 00504540 size=248

undefined4 sensor_test_sql_del_bssid_alloc_table(uint param_1)

{
  uint *puVar1;
  char *__format;
  undefined4 uVar2;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_sql_del_bssid_alloc_table ENTER\n",
           "sensor_test_sql_del_bssid_alloc_table",0x1221);
  }
  if (((int)param_1 < 0) || (g_sensor_test_case_num_max <= param_1)) {
    if (sensor_test_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_DEBUG]%s()/%d input invalid\n";
    uVar2 = 0x1226;
  }
  else {
    puVar1 = (uint *)FUN_00408450(0xc,0x122a);
    if (puVar1 != (uint *)0x0) {
      *puVar1 = param_1;
      puVar1[1] = 0;
      puVar1[2] = 0;
      uVar2 = sensor_test_db_msg_send(5,puVar1);
      return uVar2;
    }
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d bssid_alloc_ptr mem malloc fail\n";
    uVar2 = 0x122d;
  }
  printf(__format,"sensor_test_sql_del_bssid_alloc_table",uVar2);
  return 0xffffffff;
}

