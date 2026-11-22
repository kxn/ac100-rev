// func sensor_test_sqlite_init @ 004feae4 size=860

undefined4 sensor_test_sqlite_init(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_c28 [4];
  char acStack_c24 [1536];
  char acStack_624 [1544];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_sqlite_init ENTER\n","sensor_test_sqlite_init",
           0xd54);
  }
  memset(acStack_624,0,0x600);
  iVar1 = FUN_00408130("/etc/nouci_config/dbs/sensor.db",&l_sensor_test_db_ptr,
                       uac_cfg_trigger_changed_by_restore);
  if (iVar1 == 0) {
    memset(acStack_c24,0,0x600);
    snprintf(acStack_c24,0x600,
             "CREATE TABLE IF NOT EXISTS %s(test_case_id INTEGER,test_case_name NVARCHAR(33),sch_type INTEGER,sch_period INTEGER,sch_time INTEGER,change_id INTEGER,rssi_threshold INTEGER,group_id TEXT,join_test_sensor TEXT,ssid_info TEXT,service TEXT,key INTEGER PRIMARY KEY AUTOINCREMENT);"
             ,"testcase_tbl");
    iVar1 = FUN_004fe95c("testcase_tbl",acStack_c24);
    if ((iVar1 != 0) && (sensor_test_err_switch != '\0')) {
      printf("[SENSOR_TEST_ERROR]%s()/%d Create table %s failed.\n",
             "_sensor_test_sqlite_create_table_test_case",0x106,"testcase_tbl");
    }
    memset(acStack_c24,0,0x600);
    snprintf(acStack_c24,0x600,
             "CREATE TABLE IF NOT EXISTS %s(bssid NVARCHAR(20),test_case_id INTEGER,status INTEGER,sensor_id INTEGER,rssi INTEGER,serv_id INTEGER,freqband INTEGER,key INTEGER PRIMARY KEY AUTOINCREMENT);"
             ,"bssidalloc_tbl");
    iVar1 = FUN_004fe95c("bssidalloc_tbl",acStack_c24);
    if ((iVar1 != 0) && (sensor_test_err_switch != '\0')) {
      printf("[SENSOR_TEST_ERROR]%s()/%d Create table %s failed.\n",
             "_sensor_test_sqlite_create_table_bssid_alloc",0x11c,"bssidalloc_tbl");
    }
    snprintf(acStack_624,0x600,"select * from %s;","testcase_tbl");
    iVar1 = FUN_00407fb0(l_sensor_test_db_ptr,acStack_624,_sensor_test_sqlite_test_case_init_cb,
                         l_sensor_test_case_list);
    if (iVar1 == 0) {
      FUN_004083b0(l_sensor_test_case_id_allocator);
      g_sensor_test_msgq = FUN_00408460("/sensor_test_msgq",30000,8,4);
      if (g_sensor_test_msgq == -1) {
        if (sensor_test_err_switch != '\0') {
          pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d Create sensor_test msgQ failed.\n";
          uVar5 = 0xd71;
LAB_004fecec:
          printf(pcVar3,"sensor_test_sqlite_init",uVar5);
        }
      }
      else {
        iVar1 = FUN_004084e0(auStack_c28,"sensor_test_sql_task",_sensor_test_sqlite_work_task,0);
        if (iVar1 == 0) {
          uVar5 = 0;
          FUN_00408620("/etc/nouci_config/dbs/sensor.db",sensor_test_db_msgq_len);
          if (sensor_test_debug_switch == '\0') {
            return 0;
          }
          pcVar3 = "[SENSOR_TEST_DEBUG]%s()/%d sensor_test_sqlite_init success EXIT\n";
          uVar4 = 0xd80;
          goto LAB_004fed0c;
        }
        if (sensor_test_err_switch != '\0') {
          pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d Create sensor test sql work thread failed.\n";
          uVar5 = 0xd78;
          goto LAB_004fecec;
        }
      }
    }
    else {
      iVar2 = FUN_00408410();
      if (iVar2 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n","sensor_test_sqlite_init",
               0xd68,iVar1,acStack_624,"Failed to read database, select failed.");
      }
    }
  }
  else if (sensor_err_switch != '\0') {
    uVar5 = sqlite3_errmsg(l_sensor_test_db_ptr);
    printf("[SENSOR_ERROR]%s()/%d Can\'t open database: %s/n\n","sensor_test_sqlite_init",0xd5c,
           uVar5);
  }
  uVar5 = 0xffffffff;
  sensor_test_sqlite_uninit();
  if (sensor_test_err_switch == '\0') {
    return 0xffffffff;
  }
  pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d sensor_test_sqlite_init fail EXIT\n";
  uVar4 = 0xd85;
LAB_004fed0c:
  printf(pcVar3,"sensor_test_sqlite_init",uVar4);
  return uVar5;
}

