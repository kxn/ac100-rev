// func _sensor_db_sql_recover @ 004cf6d4 size=404

int _sensor_db_sql_recover(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char acStack_420 [1028];
  
  memset(acStack_420,0,0x400);
  uVar1 = apmngr_db_get_sensor_max();
  FUN_00408300(&g_invalid_sensor_id,&g_invalid_sensor_id_pos,uVar1);
  snprintf(acStack_420,0x400," SELECT * FROM %s;","sensorCfgTable");
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d [SQL Command] %s\n\n","_sensor_db_sql_recover",0x222,acStack_420);
  }
  iVar2 = FUN_00407fb0(g_sensor_db_ptr,acStack_420,_sensor_db_sqlite_cfg_restore,0);
  if (iVar2 == 0) {
    iVar2 = FUN_00408490(g_invalid_sensor_id,g_invalid_sensor_id_pos,g_sensor_db_ptr,
                         "sensorCfgTable","sensor_id");
    if ((iVar2 == 0) && (0 < g_invalid_sensor_id_pos)) {
      FUN_00408400(&g_invalid_sensor_id);
    }
    FUN_00407de0(&g_invalid_sensor_id,&g_invalid_sensor_id_pos);
  }
  else {
    iVar3 = FUN_00408410();
    if (iVar3 != 0) {
      printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"Failed to recover %s.\"\n",
             "_sensor_db_sql_recover",0x223,iVar2,acStack_420,"sensorCfgTable");
    }
  }
  return iVar2;
}

