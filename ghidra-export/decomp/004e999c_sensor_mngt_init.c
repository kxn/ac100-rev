// func sensor_mngt_init @ 004e999c size=916

uint sensor_mngt_init(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *__format;
  char *pcVar6;
  undefined4 uVar7;
  char local_d8 [32];
  undefined4 local_b8;
  code *local_b4;
  char *local_ac;
  undefined4 local_a8;
  code *local_a4;
  char *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  code *local_94;
  undefined1 auStack_64 [12];
  char *local_58;
  undefined4 local_54;
  code *local_50;
  code *local_4c;
  code *local_48;
  code *local_44;
  
  g_sensor_mngt_mutex = FUN_00407f00("sensor_mngt_mutex",1);
  if (g_sensor_mngt_mutex == 0) {
    uVar1 = 0;
    if (sensor_err_switch == '\0') {
      return 0;
    }
    __format = "[SENSOR_ERROR]%s()/%d Create sensor mutex failed.\n";
    pcVar6 = "sensor_mngt_init";
    uVar7 = 0xbcc;
  }
  else {
    FUN_0051ad88(&l_scan_bssid_callback_list);
    FUN_0051ad88(&l_status_change_callback_list);
    uVar1 = sensor_db_init();
    if (uVar1 != 0) {
      return uVar1;
    }
    memcpy(&local_ac,&DAT_006b1e40,0x48);
    iVar2 = FUN_00408120("apmng_sensor","settings",&local_ac,2);
    if (iVar2 == 0) {
      local_ac = (char *)0x0;
      local_a8 = 0;
      local_a4 = (code *)0x0;
      local_98 = 0;
      memset(auStack_64,0,0x4c);
      local_9c = 100;
      local_a0 = "sensor";
      uVar1 = 0xffffffff;
      local_94 = _sensor_join_check;
      iVar2 = apmngr_check_callback_register(&local_ac);
      if (iVar2 == -1) {
        if (sensor_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[SENSOR_ERROR]%s()/%d register callback to apmngr reboot failed.\n";
        pcVar6 = "_sensor_apmngr_callback_reg";
        uVar7 = 0x67d;
      }
      else {
        local_58 = "sensor";
        local_54 = 10;
        local_50 = _sensor_join;
        local_48 = _sensor_firm;
        local_4c = _sensor_leave;
        local_44 = _sensor_delete;
        iVar2 = apmngr_callback_register(auStack_64);
        if (iVar2 == 0) {
          local_a0 = (char *)0x0;
          local_a8 = 0x32000000;
          local_ac = "sensor";
          local_a4 = _sensor_multilink_callback_add;
          iVar2 = multi_link_reg(&local_ac);
          if (iVar2 == -1) {
            uVar1 = 0xffffffff;
            if (sensor_err_switch == '\0') {
              return 0xffffffff;
            }
            __format = "[SENSOR_ERROR]%s()/%d register callback to multi link failed.\n";
            pcVar6 = "_sensor_multi_link_callback_reg";
            uVar7 = 0x69d;
          }
          else {
            uVar3 = FUN_004084d0("sensor_global",2,_sensor_jcs_global_set);
            uVar4 = FUN_004084d0("sensor_discover_trigger",2,_sensor_jcs_discover_trigger);
            uVar5 = FUN_004084d0("sensor_list_added",3,_sensor_jcs_sensor_list_added_get);
            uVar1 = FUN_004084d0("sensor_manage_status",3,_sensor_jcs_sensor_manage_status_get);
            uVar1 = uVar4 | uVar3 | uVar5 | uVar1;
            if (uVar1 == 0) {
              uVar1 = apupd_upgrade_check_reg(_sensor_apupd_upgrade_check);
              if (uVar1 != 0) {
                return uVar1;
              }
              memset(local_d8,0,0x2c);
              local_b8 = 10;
              builtin_strncpy(local_d8,"sensor",6);
              local_b4 = _sensor_wportal_callback_sta_access_check;
              iVar2 = wportal_sta_access_check_reg(local_d8);
              if (iVar2 == 0) {
                sensor_stats_cb_reg_by_funcname
                          ("sensor_backhaul_test",100,_sensor_backhaul_test_result_handle);
                sensor_stats_cb_reg_by_funcname
                          ("neighbour_scan",100,_sensor_neighbor_scan_result_handle);
                return 0;
              }
              if (sensor_err_switch == '\0') {
                return 0;
              }
              __format = 
              "[SENSOR_ERROR]%s()/%d register sta access check callback to wportal failed \n";
              pcVar6 = "sensor_mngt_init";
              uVar7 = 0xbf8;
              uVar1 = 0;
            }
            else {
              if (sensor_err_switch == '\0') {
                return uVar1;
              }
              __format = "[SENSOR_ERROR]%s()/%d Failed to register callback to jcs.\n";
              pcVar6 = "_sensor_jcs_callback_reg";
              uVar7 = 0x8cf;
            }
          }
        }
        else {
          uVar1 = 0xffffffff;
          if (sensor_err_switch == '\0') {
            return 0xffffffff;
          }
          __format = "[SENSOR_ERROR]%s()/%d apmngr_callback_register() failed.\n";
          pcVar6 = "_sensor_apmngr_callback_reg";
          uVar7 = 0x68b;
        }
      }
    }
    else {
      uVar1 = 0xffffffff;
      if (sensor_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[SENSOR_ERROR]%s()/%d uci req parse failed.\n";
      pcVar6 = "_sensor_global_config_init";
      uVar7 = 0x36e;
    }
  }
  printf(__format,pcVar6,uVar7);
  return uVar1;
}

