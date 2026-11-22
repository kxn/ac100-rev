// func sensor_db_uninit @ 004d182c size=304

void sensor_db_uninit(void)

{
  int iVar1;
  
  if (g_sensor_sqlite_thread_start != 0) {
    pthread_kill(g_sensor_sqlite_thread,3);
    g_sensor_sqlite_thread_start = 0;
  }
  if (g_sensor_entry_array != 0) {
    FUN_00407df0();
    g_sensor_entry_array = 0;
  }
  if (g_sensor_vap_hash != 0) {
    FUN_00408570(g_sensor_vap_hash,_sensor_db_hash_vap_item_free,0);
    FUN_00408310(g_sensor_vap_hash);
    g_sensor_vap_hash = 0;
  }
  if (g_sensor_mutex != 0) {
    FUN_00408360();
    g_sensor_mutex = 0;
  }
  if (g_sensor_sql_mutex != 0) {
    FUN_00408360();
    g_sensor_sql_mutex = 0;
  }
  if (g_sensor_msg_cond == 0) {
    FUN_00408220(0);
    g_sensor_msg_cond = 0;
  }
  if (g_sensor_db_ptr != 0) {
    FUN_004080b0();
    g_sensor_db_ptr = 0;
  }
  while (iVar1 = FUN_004081b0(&g_sensor_msg_list), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
    FUN_00407df0(iVar1);
  }
  return;
}

