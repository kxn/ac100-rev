// func _sensor_test_sqlite_case_delete @ 00501f28 size=396

int _sensor_test_sqlite_case_delete(uint *param_1)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  char acStack_118 [260];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_sqlite_case_delete ENTER\n",
           "_sensor_test_sqlite_case_delete",0x123);
  }
  memset(acStack_118,0,0x100);
  if (param_1 == (uint *)0x0) {
    return -1;
  }
  uVar1 = *param_1;
  if (((int)uVar1 < 0) || (g_sensor_test_case_num_max <= uVar1)) {
    iVar4 = -1;
    if (sensor_test_debug_switch == '\0') {
      uVar1 = param_1[1];
      goto LAB_00501f98;
    }
    __format = "[SENSOR_TEST_DEBUG]%s()/%d input case_id invalid\n";
    uVar3 = 0x12e;
  }
  else {
    snprintf(acStack_118,0x100,"DELETE FROM %s WHERE test_case_id = %d;","testcase_tbl",uVar1);
    iVar4 = FUN_00407d60(l_sensor_test_db_ptr,acStack_118);
    if (iVar4 != 0) {
      iVar2 = FUN_00408410();
      if (iVar2 == 0) {
        uVar1 = param_1[1];
      }
      else {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
               "_sensor_test_sqlite_case_delete",0x133,iVar4,acStack_118,
               "Failed to del in testcase_tbl.");
        uVar1 = param_1[1];
      }
      goto LAB_00501f98;
    }
    if (sensor_test_debug_switch == '\0') {
      uVar1 = param_1[1];
      goto LAB_00501f98;
    }
    __format = "[SENSOR_TEST_DEBUG]%s()/%d sqlite case del success\n";
    uVar3 = 0x135;
  }
  printf(__format,"_sensor_test_sqlite_case_delete",uVar3);
  uVar1 = param_1[1];
LAB_00501f98:
  if (uVar1 != 0) {
    sensor_test_db_case_setting_mem_free();
    param_1[1] = 0;
  }
  FUN_00407df0(param_1);
  return iVar4;
}

