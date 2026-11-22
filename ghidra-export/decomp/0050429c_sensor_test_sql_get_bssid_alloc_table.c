// func sensor_test_sql_get_bssid_alloc_table @ 0050429c size=288

int sensor_test_sql_get_bssid_alloc_table(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char acStack_610 [1536];
  
  memset(acStack_610,0,0x600);
  if (((param_2 == 0) || ((int)param_1 < 0)) || (g_sensor_test_case_num_max <= param_1)) {
    iVar2 = -1;
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d input invalid\n","sensor_test_sql_get_bssid_alloc_table",
             0x11ee);
    }
  }
  else {
    snprintf(acStack_610,0x600,"select * from %s where test_case_id = %d;","bssidalloc_tbl",param_1)
    ;
    iVar2 = FUN_00407fb0(l_sensor_test_db_ptr,acStack_610,_sensor_test_sqlite_get_bssid_alloc_cb,
                         param_2);
    if ((iVar2 != 0) && (iVar1 = FUN_00408410(), iVar1 != 0)) {
      printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
             "sensor_test_sql_get_bssid_alloc_table",0x11f4,iVar2,acStack_610,
             "Failed to read database, select failed.");
    }
  }
  return iVar2;
}

