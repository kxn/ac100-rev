// func _sensor_db_wips_try_create_table @ 004cf360 size=144

undefined4 _sensor_db_wips_try_create_table(void)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_808 [2048];
  
  uVar2 = 0;
  memset(acStack_808,0,0x800);
  snprintf(acStack_808,0x800,
           "CREATE TABLE IF NOT EXISTS whitelist_table(whitelist_id INTEGER,mac VARCHAR ( 17 ),ssid VARCHAR ( 128 ),ssid_encode INTEGER,sensor_id INTEGER,rssi INTEGER,last_discover_time INTEGER,operation_time INTEGER);CREATE INDEX IF NOT EXISTS whitelist_table_whitelist_id ON whitelist_table (whitelist_id);"
          );
  iVar1 = FUN_00407d60(g_sensor_db_ptr,acStack_808);
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, sensor_err_switch != '\0')) {
    printf("[SENSOR_ERROR]%s()/%d uac_sqlite_exec_no_cb() fail, sql=%s\n",
           "_sensor_db_wips_try_create_table",0xb1,acStack_808);
  }
  return uVar2;
}

