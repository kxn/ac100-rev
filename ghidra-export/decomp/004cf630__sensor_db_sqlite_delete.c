// func _sensor_db_sqlite_delete @ 004cf630 size=164

undefined4 _sensor_db_sqlite_delete(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  uVar2 = 0xffffffff;
  iVar1 = snprintf(acStack_408,0x400,"DELETE FROM %s WHERE sensor_id = %d;","sensorCfgTable",param_1
                  );
  if (-1 < iVar1) {
    uVar2 = 0;
    iVar1 = FUN_00407d60(g_sensor_db_ptr,acStack_408);
    if ((iVar1 != 0) && (uVar2 = 0xffffffff, sensor_err_switch != '\0')) {
      printf("[SENSOR_ERROR]%s()/%d Failed to insert to AP-entry table.\n",
             "_sensor_db_sqlite_delete",0x102);
    }
  }
  return uVar2;
}

