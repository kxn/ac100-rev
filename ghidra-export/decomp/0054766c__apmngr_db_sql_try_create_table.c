// func _apmngr_db_sql_try_create_table @ 0054766c size=536

undefined4 _apmngr_db_sql_try_create_table(void)

{
  int iVar1;
  char **ppcVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  char **ppcVar5;
  undefined4 *puVar6;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *pcStack_20;
  
  local_38 = 
  "CREATE TABLE IF NOT EXISTS Group_table (seq INTEGER PRIMARY KEY AUTOINCREMENT,group_id INTEGER UNIQUE,name TEXT(52));"
  ;
  local_34 = 
  "CREATE TABLE IF NOT EXISTS ApTemplate_table (seq INTEGER PRIMARY KEY AUTOINCREMENT,entry_id INTEGER UNIQUE,group_id INTEGER,entry_name VARCHAR(52) NOT NULL, model_id INTEGER NOT NULL, hardware_ver VARCHAR(20) NOT NULL, ap_keep_alive INTEGER, client_keep_alive INTEGER, client_idle INTEGER, offline_selfmanage VARCHAR(4), username VARCHAR(32), password VARCHAR(16), phy_wire_vlan_1 INTEGER,phy_wire_vlan_2 INTEGER,phy_wire_vlan_3 INTEGER,phy_wire_vlan_4 INTEGER,ap_trunk INTEGER,led INTEGER,led_wifi_sync VARCHAR(4),led_timer_enable VARCHAR(4),led_close_date VARCHAR(10),led_close_time VARCHAR(10),led_open_date VARCHAR(10),led_open_time VARCHAR(10),bluetooth_enable INTEGER,account_username VARCHAR(64),account_password VARCHAR(64),new_ap_trunk INTEGER,lag_mode INTEGER,lag_phy_num INTEGER,lag_phy_list VARCHAR(20),telnet_status INTEGER,fit_fat_button_status INTEGER,radio_role_table_idx INTEGER,region_code INTEGER,firmware_id VARCHAR(33),ap_mesh_switch INTEGER,ssid_mlo_support INTEGER);"
  ;
  puVar6 = &g_apmngr_db;
  local_30 = 
  "CREATE TABLE IF NOT EXISTS ApEntryCfg_table(seq INTEGER PRIMARY KEY AUTOINCREMENT,entry_id INTEGER UNIQUE,group_id INTEGER,ap_role VARCHAR(10),cap_id INTEGER,mac VARCHAR(17) UNIQUE,entry_name VARCHAR(52) NOT NULL, model_id INTEGER NOT NULL, hardware_ver VARCHAR(20) NOT NULL, ap_keep_alive INTEGER, client_keep_alive INTEGER, client_idle INTEGER, offline_selfmanage VARCHAR(4), username VARCHAR(32), password VARCHAR(16), phy_wire_vlan_1 INTEGER,phy_wire_vlan_2 INTEGER,phy_wire_vlan_3 INTEGER,phy_wire_vlan_4 INTEGER,ap_trunk INTEGER,hdap_peer_id INTEGER,led INTEGER,led_wifi_sync VARCHAR(4),led_timer_enable VARCHAR(4),led_close_date VARCHAR(10),led_close_time VARCHAR(10),led_open_date VARCHAR(10),led_open_time VARCHAR(10),bluetooth_enable INTEGER,account_username VARCHAR(64),account_password VARCHAR(64),cloud_config_id VARCHAR(65),new_ap_trunk INTEGER,lag_mode INTEGER,lag_phy_num INTEGER,lag_phy_list VARCHAR(20),telnet_status INTEGER,fit_fat_button_status INTEGER,radio_role_table_idx INTEGER,region_code INTEGER,firmware_id VARCHAR(33),ap_mesh_switch INTEGER,ssid_mlo_support INTEGER);"
  ;
  ppcVar5 = &local_38;
  local_2c = 
  "CREATE TABLE IF NOT EXISTS ApEntryTmpCfg_table(seq INTEGER PRIMARY KEY AUTOINCREMENT,entry_id INTEGER UNIQUE,group_id INTEGER,ap_role VARCHAR(10),cap_id INTEGER,mac VARCHAR(17) UNIQUE,entry_name VARCHAR(52) NOT NULL, model_id INTEGER NOT NULL, hardware_ver VARCHAR(20) NOT NULL, ap_keep_alive INTEGER, client_keep_alive INTEGER, client_idle INTEGER, offline_selfmanage VARCHAR(4), username VARCHAR(32), password VARCHAR(16), phy_wire_vlan_1 INTEGER,phy_wire_vlan_2 INTEGER,phy_wire_vlan_3 INTEGER,phy_wire_vlan_4 INTEGER,ap_trunk INTEGER,hdap_peer_id INTEGER,led INTEGER,led_wifi_sync VARCHAR(4),led_timer_enable VARCHAR(4),led_close_date VARCHAR(10),led_close_time VARCHAR(10),led_open_date VARCHAR(10),led_open_time VARCHAR(10),bluetooth_enable INTEGER,account_username VARCHAR(64),account_password VARCHAR(64),cloud_config_id VARCHAR(65),new_ap_trunk INTEGER,lag_mode INTEGER,lag_phy_num INTEGER,lag_phy_list VARCHAR(20),telnet_status INTEGER,fit_fat_button_status INTEGER,radio_role_table_idx INTEGER,region_code INTEGER,firmware_id VARCHAR(33),ap_mesh_switch INTEGER,ssid_mlo_support INTEGER);"
  ;
  local_28 = 
  "CREATE TABLE IF NOT EXISTS ApEntryRun_table(seq INTEGER PRIMARY KEY AUTOINCREMENT,entry_id INTEGER UNIQUE,group_id INTEGER,ap_role VARCHAR(10),firm BIT,software_ver VARCHAR(26), led BOOLEAN, telnet_status BOOLEAN, status INTEGER, errno INTEGER);"
  ;
  local_24 = "DELETE FROM ApEntryTmpCfg_table;DELETE FROM ApEntryRun_table;";
  do {
    iVar4 = 0;
    ppcVar2 = ppcVar5;
    do {
      if ((*ppcVar2 != (char *)0x0) && (iVar1 = FUN_00407d60(*puVar6), iVar1 != 0)) {
        if (apmngr_err_switch == '\0') {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        __format = "[APMNGR_ERROR]%s()/%d Failed to create table.\n";
        uVar3 = 0x58d;
        goto LAB_005477e8;
      }
      iVar4 = iVar4 + 4;
      ppcVar2 = (char **)((int)ppcVar5 + iVar4);
    } while (iVar4 != 0xc);
    ppcVar5 = ppcVar5 + 3;
    puVar6 = puVar6 + 1;
    if (ppcVar5 == &pcStack_20) {
      iVar4 = FUN_00407d60(g_apmngr_db,
                           "INSERT OR IGNORE INTO Group_table (group_id, name) VALUES(0, \'default\');"
                          );
      if (iVar4 == 0) {
        iVar4 = FUN_00407fb0(g_apmngr_db,"SELECT entry_id, group_id, ap_role FROM ApEntryCfg_table;"
                             ,apmngr_db_sqlite_create_runinfo_by_id,0);
        if (iVar4 == 0) {
          iVar4 = FUN_00407d60(DAT_007c58e8,
                               "UPDATE ApEntryRun_table SET status = 0, led = 0, telnet_status = 0, errno = 0;"
                              );
          if (iVar4 == 0) {
            return 0;
          }
          if (apmngr_err_switch == '\0') {
            return 0xffffffff;
          }
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          __format = "[APMNGR_ERROR]%s()/%d Failed to init AP runtime table.\n";
          uVar3 = 0x5a8;
        }
        else {
          if (apmngr_err_switch == '\0') {
            return 0xffffffff;
          }
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          __format = "[APMNGR_ERROR]%s()/%d Failed to carry out sql command\n";
          uVar3 = 0x5a0;
        }
      }
      else {
        if (apmngr_err_switch == '\0') {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        __format = "[APMNGR_ERROR]%s()/%d Failed to create default group.\n";
        uVar3 = 0x597;
      }
LAB_005477e8:
      printf(__format,"_apmngr_db_sql_try_create_table",uVar3);
      return 0xffffffff;
    }
  } while( true );
}

