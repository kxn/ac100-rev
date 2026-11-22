// func _sensor_db_sqlite_thread_main @ 004cff1c size=324

void _sensor_db_sqlite_thread_main(void)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  FUN_0051ad88(&local_30);
  do {
    FUN_004082d0(g_sensor_sql_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_sensor_msg_list), iVar1 == 0) {
      FUN_004086c0(g_sensor_msg_cond,g_sensor_sql_mutex,0xffffffff);
    }
    FUN_004082c0(&local_30,&g_sensor_msg_list);
    FUN_00407f30(g_sensor_sql_mutex);
    while (iVar1 = FUN_004081b0(&local_30), iVar1 != 0) {
      FUN_00408500(iVar1);
      g_sensor_sql_option_changed_node_num = g_sensor_sql_option_changed_node_num + -1;
      if (*(uint *)(iVar1 + 0xc) < 5) {
        switch(*(uint *)(iVar1 + 0xc)) {
        case 0:
          _sensor_db_sqlite_insert();
          break;
        case 1:
          _sensor_db_sqlite_update();
          break;
        case 2:
          _sensor_db_sqlite_delete(*(undefined2 *)*(undefined4 **)(iVar1 + 0x10));
          break;
        case 3:
          _sensor_db_sqlite_wips_whitelist_add();
          break;
        case 4:
          _sensor_db_sqlite_wips_whitelist_delete(**(undefined4 **)(iVar1 + 0x10));
        }
      }
      FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
      FUN_00407df0(iVar1);
    }
  } while( true );
}

