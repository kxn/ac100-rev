// func _sensor_test_sqlite_bssid_alloc_delete @ 004fd848 size=360

int _sensor_test_sqlite_bssid_alloc_delete(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char acStack_110 [256];
  
  memset(acStack_110,0,0x100);
  if (((param_1 == (uint *)0x0) || (uVar1 = *param_1, (int)uVar1 < 0)) ||
     (g_sensor_test_case_num_max <= uVar1)) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d input invalid\n","_sensor_test_sqlite_bssid_alloc_delete",
             0x212);
    }
    iVar3 = -1;
    if (param_1 == (uint *)0x0) {
      return -1;
    }
    uVar1 = param_1[2];
  }
  else {
    snprintf(acStack_110,0x100,"DELETE FROM %s WHERE test_case_id = %d;","bssidalloc_tbl",uVar1);
    iVar3 = FUN_00407d60(l_sensor_test_db_ptr,acStack_110);
    if (iVar3 == 0) {
      if (sensor_test_debug_switch == '\0') {
        uVar1 = param_1[2];
      }
      else {
        printf("[SENSOR_TEST_DEBUG]%s()/%d sqlite bssid_alloc delete success\n",
               "_sensor_test_sqlite_bssid_alloc_delete",0x21a);
        uVar1 = param_1[2];
      }
    }
    else {
      iVar2 = FUN_00408410();
      if (iVar2 == 0) {
        uVar1 = param_1[2];
      }
      else {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
               "_sensor_test_sqlite_bssid_alloc_delete",0x218,iVar3,acStack_110,
               "Failed to del in bssid_alloc_table.");
        uVar1 = param_1[2];
      }
    }
  }
  if (uVar1 != 0) {
    FUN_00407df0();
    param_1[2] = 0;
  }
  FUN_00407df0(param_1);
  return iVar3;
}

