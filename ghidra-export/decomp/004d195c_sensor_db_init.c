// func sensor_db_init @ 004d195c size=788

undefined4 sensor_db_init(void)

{
  int iVar1;
  void *__s;
  char *__format;
  char *pcVar2;
  undefined4 uVar3;
  
  FUN_0051ad88(&g_sensor_msg_list);
  iVar1 = apmngr_db_get_sensor_max();
  __s = (void *)FUN_00408450(iVar1 * 0x18,0x40a);
  g_sensor_entry_array = __s;
  if (__s == (void *)0x0) {
    if (sensor_err_switch == '\0') goto LAB_004d1b10;
    __format = "[SENSOR_ERROR]%s()/%d Malloc entry array failed.\n";
    pcVar2 = "sensor_db_init";
    uVar3 = 0x40d;
  }
  else {
    iVar1 = apmngr_db_get_sensor_max();
    memset(__s,0,iVar1 * 0x18);
    iVar1 = apmngr_db_get_sensor_max();
    g_sensor_vap_hash =
         FUN_004080a0(_sensor_db_vap_hash_obj,_sensor_db_vap_hash_key_func,
                      _sensor_db_vap_hash_cmp_func,iVar1 << 1);
    if (g_sensor_vap_hash == 0) {
      if (sensor_err_switch == '\0') goto LAB_004d1b10;
      __format = "[SENSOR_ERROR]%s()/%d Create sensor vap hash failed.\n";
      pcVar2 = "sensor_db_init";
      uVar3 = 0x418;
    }
    else {
      g_sensor_mutex = FUN_00407f00("sensor_mutex",1);
      if (g_sensor_mutex == 0) {
        if (sensor_err_switch == '\0') goto LAB_004d1b10;
        __format = "[SENSOR_ERROR]%s()/%d Create sensor mutex failed.\n";
        pcVar2 = "sensor_db_init";
        uVar3 = 0x41f;
      }
      else {
        g_sensor_sql_mutex = FUN_00407f00("sensor_sql_mutex",0);
        if (g_sensor_sql_mutex == 0) {
          if (sensor_err_switch == '\0') goto LAB_004d1b10;
          __format = "[SENSOR_ERROR]%s()/%d Create sensor sql mutex failed.\n";
          pcVar2 = "sensor_db_init";
          uVar3 = 0x425;
        }
        else {
          g_sensor_msg_cond = FUN_00407d80("sensor_sql_msg_cond");
          if (g_sensor_msg_cond == 0) {
            if (sensor_err_switch == '\0') goto LAB_004d1b10;
            __format = "[SENSOR_ERROR]%s()/%d Create apmngr msg cond failed.\n";
            pcVar2 = "sensor_db_init";
            uVar3 = 0x42b;
          }
          else {
            FUN_00408620("/etc/nouci_config/dbs/sensor.db",
                         sensor_db_sqlite_option_changed_node_num_get);
            iVar1 = FUN_00408130("/etc/nouci_config/dbs/sensor.db",&g_sensor_db_ptr,
                                 uac_cfg_trigger_changed_by_restore);
            if (iVar1 != 0) {
              if (sensor_err_switch != '\0') {
                uVar3 = sqlite3_errmsg(g_sensor_db_ptr);
                printf("[SENSOR_ERROR]%s()/%d Can\'t open database: %s/n\n","sensor_db_init",0x434,
                       uVar3);
              }
              goto LAB_004d1b10;
            }
            iVar1 = FUN_00407d60(g_sensor_db_ptr,
                                 "CREATE TABLE IF NOT EXISTS sensorCfgTable (seq INTEGER PRIMARY KEY AUTOINCREMENT,sensor_id INTEGER UNIQUE,primary_bssid VARCHAR(20));"
                                );
            if (iVar1 == 0) {
              iVar1 = _sensor_db_sql_recover();
              if (iVar1 != 0) {
                return 0xffffffff;
              }
              apmngr_db_foreach_proc(0x800000,_sensor_entry_init_from_ap_entry,0);
              iVar1 = FUN_004084e0(&g_sensor_sqlite_thread,"tSensor_sql",
                                   _sensor_db_sqlite_thread_main,0);
              if (iVar1 == 0) {
                g_sensor_sqlite_thread_start = 1;
                iVar1 = _sensor_db_wips_try_create_table();
                if (iVar1 == 0) {
                  return 0;
                }
                if (sensor_err_switch == '\0') goto LAB_004d1b10;
                __format = "[SENSOR_ERROR]%s()/%d _sensor_db_wips_try_create_table fail\n";
                pcVar2 = "sensor_db_init";
                uVar3 = 0x44d;
              }
              else {
                if (sensor_err_switch == '\0') goto LAB_004d1b10;
                __format = "[SENSOR_ERROR]%s()/%d Failed to create sqlite thread\n";
                pcVar2 = "sensor_db_init";
                uVar3 = 0x446;
              }
            }
            else {
              if (sensor_err_switch == '\0') goto LAB_004d1b10;
              __format = "[SENSOR_ERROR]%s()/%d Failed to create table.\n";
              pcVar2 = "_sensor_db_sql_try_create_table";
              uVar3 = 0x8f;
            }
          }
        }
      }
    }
  }
  printf(__format,pcVar2,uVar3);
LAB_004d1b10:
  sensor_db_uninit();
  return 0xffffffff;
}

