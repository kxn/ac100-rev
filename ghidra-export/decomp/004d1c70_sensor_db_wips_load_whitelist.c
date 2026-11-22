// func sensor_db_wips_load_whitelist @ 004d1c70 size=184

int sensor_db_wips_load_whitelist(void)

{
  int iVar1;
  int iVar2;
  char acStack_810 [2052];
  
  memset(acStack_810,0,0x800);
  snprintf(acStack_810,0x800,"SELECT * FROM whitelist_table ORDER BY operation_time DESC");
  iVar1 = FUN_00407fb0(g_sensor_db_ptr,acStack_810,_sensor_db_wips_foreach_callback,0);
  if ((iVar1 != 0) && (iVar2 = FUN_00408410(), iVar2 != 0)) {
    printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
           "sensor_db_wips_load_whitelist",0x4ca,iVar1,acStack_810,"select whitelist fail");
  }
  return iVar1;
}

