// func sensor_di_init @ 004d9c50 size=844

undefined4 sensor_di_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  char *local_20;
  undefined4 local_1c;
  code *local_18;
  undefined4 local_14;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_init ENTER\n","sensor_di_init",0x736);
  }
  l_sensor_di_cur_viewed_sensor_id = 0xffffffff;
  l_sensor_di_timer = 0xffffffff;
  l_sensor_di_status = 0;
  l_sensor_di_status_mutex = FUN_00407f00("sensor_di_status_mutex",1);
  if (l_sensor_di_status_mutex == 0) {
    if (sensor_di_err_switch == 0) goto LAB_004d9ee8;
    __format = "[SENSOR_DI_ERROR]%s()/line %d : l_sensor_di_status_mutex fail\n";
    uVar2 = 0x740;
  }
  else {
    DAT_007685d0 = 0;
    DAT_007685d0 = FUN_004080a0(_sensor_di_cache_bssid_hash_obj,_sensor_di_cache_bssid_hash_key,
                                _sensor_di_cache_bssid_hash_cmp,1000);
    if (DAT_007685d0 == 0) {
      if (sensor_di_err_switch == 0) goto LAB_004d9ee8;
      __format = "[SENSOR_DI_ERROR]%s()/line %d : hash create fail\n";
      uVar2 = 0x748;
    }
    else {
      iVar1 = sensor_di_db_init();
      if (iVar1 == -1) {
        if (sensor_di_err_switch == 0) goto LAB_004d9ee8;
        __format = "[SENSOR_DI_ERROR]%s()/line %d : sensor_di_db_init fail\n";
        uVar2 = 0x74e;
      }
      else {
        local_14 = 0;
        local_20 = "deep_inspection";
        local_1c = 0x32000000;
        local_18 = _deep_inspection_multilink_callback_sensor_add;
        iVar1 = multi_link_reg(&local_20);
        if (iVar1 != -1) {
          FUN_004084d0("set_deep_inspection_setting",2,jcs_deep_inspection_setting);
          FUN_004084d0("set_deep_inspection_scan_mode_change",2,
                       jcs_deep_inspection_sensor_scan_mode_change);
          FUN_004084d0("get_deep_inspection_setting",3,jcs_get_deep_inspection_setting);
          FUN_004084d0("get_deep_inspection_scan_mode_change",3,
                       jcs_get_deep_inspection_sensor_scan_mode_change);
          FUN_004084d0("deep_inspection_status",3,jcs_deep_inspection_status);
          FUN_004084d0("deep_inspection_chnl_usage_list",3,jcs_deep_inspection_chnl_usage_list);
          FUN_004084d0("deep_inspection_selected_chnl_usage",3,
                       jcs_deep_inspection_selected_chnl_usage);
          FUN_004084d0("deep_inspection_multi_chnl_rssi",3,jcs_deep_inspection_multi_chnl_rssi);
          FUN_004084d0("deep_inspection_multi_chnl_waterfall",3,
                       jcs_deep_inspection_multi_chnl_waterfall);
          FUN_004084d0("deep_inspection_multi_chnl_density",3,jcs_deep_inspection_multi_chnl_density
                      );
          FUN_004084d0("deep_checkup_pkt_ssid_list",3,jcs_deep_checkup_pkt_ssid_list);
          FUN_004084d0("deep_checkup_pkt_bssid_list",3,jcs_deep_checkup_pkt_bssid_list);
          FUN_004084d0("deep_checkup_pkt_sta_list",3,jcs_deep_checkup_pkt_sta_list);
          sensor_stats_cb_reg_by_funcname("indepth_checkup",100,sensor_di_result_collect_cb);
          if (sensor_di_debug_switch == 0) {
            return 0;
          }
          printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_init SUCCESS\n","sensor_di_init",0x768);
          return 0;
        }
        if (sensor_di_err_switch != 0) {
          printf("[SENSOR_DI_ERROR]%s()/line %d : register callback to multi link failed.\n",
                 "_deep_inspection_multilink_callback_init",0x721);
        }
        if (sensor_di_err_switch == 0) goto LAB_004d9ee8;
        __format = 
        "[SENSOR_DI_ERROR]%s()/line %d : deep_inspection_multilink_callback_init() fail!\n";
        uVar2 = 0x754;
      }
    }
  }
  printf(__format,"sensor_di_init",uVar2);
LAB_004d9ee8:
  sensor_di_destroy();
  return 0xffffffff;
}

