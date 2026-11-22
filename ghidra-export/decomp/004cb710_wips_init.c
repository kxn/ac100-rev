// func wips_init @ 004cb710 size=1280

undefined4 wips_init(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *local_88;
  undefined4 local_84;
  code *local_80;
  char *local_7c;
  undefined4 local_78;
  code *local_74;
  code *local_70;
  undefined1 auStack_68 [12];
  char *local_5c;
  undefined4 local_58;
  code *local_48;
  
  g_wips_info_max_size = _wips_profile_get("wips_info_max");
  g_whitelist_max_size = _wips_profile_get("wips_whitelist_max");
  wips_global_mutex = FUN_00407f00("wips_global_mutex",1);
  if (wips_global_mutex == 0) {
    if (sensor_err_switch == '\0') goto LAB_004cbb74;
    pcVar2 = "[SENSOR_ERROR]%s()/%d Create config mutex failed.\n";
    uVar3 = 0xc4c;
  }
  else {
    g_wips_id_allocator = FUN_004080e0(g_wips_info_max_size);
    g_whitelist_id_allocator = FUN_004080e0(g_whitelist_max_size);
    if ((g_wips_id_allocator == 0) || (g_whitelist_id_allocator == 0)) {
      if (sensor_err_switch == '\0') goto LAB_004cbb74;
      pcVar2 = "[SENSOR_ERROR]%s()/%d Init id allocator failed.\n";
      uVar3 = 0xc55;
    }
    else {
      g_wips_id2entry = FUN_00408450((uint)g_wips_info_max_size << 2,0xc59);
      if (g_wips_id2entry == 0) {
        if (sensor_err_switch == '\0') goto LAB_004cbb74;
        pcVar2 = "[SENSOR_ERROR]%s()/%d init g_wips_id2entry error\n";
        uVar3 = 0xc5c;
      }
      else {
        FUN_0051ad88(&g_wips_list);
        FUN_0051ad88(&g_white_list);
        g_counter_info_hash =
             FUN_004080a0(wips_counter_info_obj_hash_func,wips_counter_info_key_hash_func,
                          wips_counter_info_cmp_func,g_wips_info_max_size);
        if (g_counter_info_hash != 0) {
          wips_entry_clear_interval();
          wips_counter_interval();
          FUN_004084d0("wips_event_info",3,wips_jcs_callback_wips_event_info_get);
          FUN_004084d0("wips_event_info",2,wips_jcs_callback_wips_event_info_set);
          FUN_004084d0("wips_event_detail",3,wips_jcs_callback_wips_event_detail_get);
          FUN_004084d0("whitelist",3,wips_jcs_callback_whitelist_get);
          FUN_004084d0("whitelist",0,wips_jcs_callback_whitelist_add);
          FUN_004084d0("whitelist",1,wips_jcs_callback_whitelist_delete);
          FUN_004084d0("wips_statistics",3,wips_jcs_callback_statistics_get);
          FUN_004084d0("wips_statistics_num",3,wips_jcs_callback_statistics_num_get);
          sensor_stats_cb_reg_by_typeid(0x13157f9,100,wips_event_no_auth_ssid_cb);
          sensor_stats_cb_reg_by_typeid(0x13157fa,100,wips_event_assoc_req_torrent);
          sensor_stats_cb_reg_by_typeid(0x13157fb,100,wips_event_reassoc_req_torrent);
          sensor_stats_cb_reg_by_typeid(0x13157fc,100,wips_event_probe_req_torrent);
          sensor_stats_cb_reg_by_typeid(0x13157fd,100,wips_event_auth_torrent);
          sensor_stats_cb_reg_by_typeid(0x13157fe,100,wips_event_ps_pool_torrent);
          sensor_stats_cb_reg_by_typeid(0x13157ff,100,wips_event_beacon_torrent);
          sensor_stats_cb_reg_by_typeid(0x1315800,100,wips_event_rts_torrent);
          sensor_stats_cb_reg_by_typeid(0x1315801,100,wips_event_cts_torrent);
          sensor_stats_cb_reg_by_typeid(0x1315802,100,wips_event_disassoc_torrent);
          sensor_stats_cb_reg_by_typeid(0x1315803,100,wips_event_deauth_torrent);
          sensor_stats_cb_reg_by_typeid(0x1315804,100,wips_event_bssid_illegal_dev);
          sensor_stats_cb_reg_by_typeid(0x1315805,100,wips_event_ssid_illegal_dev);
          sensor_scan_bssid_update_reg(wips_whitelist_update_with_scan_info);
          memset(auStack_68,0,0x4c);
          local_88 = (char *)0x0;
          local_58 = 0x82;
          local_84 = 0;
          local_80 = (code *)0x0;
          local_7c = (char *)0x0;
          local_5c = "sensor_wips";
          local_48 = wips_ap_del;
          iVar1 = apmngr_callback_register(auStack_68);
          if (iVar1 == -1) {
            if (sensor_err_switch == '\0') goto LAB_004cba54;
            pcVar2 = "[SENSOR_ERROR]%s()/%d register callback to apmngr failed.\n";
            uVar3 = 0xbee;
          }
          else {
            local_88 = "sensor_wips";
            local_7c = (char *)0x0;
            local_84 = CONCAT13(6,local_84._1_3_);
            local_80 = wips_ap_multilink;
            iVar1 = multi_link_reg(&local_88);
            if ((iVar1 != -1) || (sensor_err_switch == '\0')) goto LAB_004cba54;
            pcVar2 = "[SENSOR_ERROR]%s()/%d multi_link_reg() failed.\n";
            uVar3 = 0xbfa;
          }
          printf(pcVar2,"wips_apmngr_callback_init",uVar3);
LAB_004cba54:
          memset(&local_88,0,0x20);
          local_7c = "sensor_wips";
          local_78 = 10;
          local_74 = wips_wserv_add;
          local_70 = wips_wserv_set;
          iVar1 = uac_wservice_callback_register(&local_88);
          if ((iVar1 == -1) && (sensor_err_switch != '\0')) {
            printf("[SENSOR_ERROR]%s()/%d wserv_reg failed\n","wips_wserv_callback_init",0xc2e);
          }
          FUN_004082d0(wips_global_mutex,0xffffffff);
          sensor_db_wips_load_whitelist();
          FUN_004083b0(g_whitelist_id_allocator);
          FUN_00407f30(wips_global_mutex);
          return 0;
        }
        g_counter_info_hash = 0;
        if (sensor_err_switch == '\0') goto LAB_004cbb74;
        pcVar2 = "[SENSOR_ERROR]%s()/%d create g_counter_info_hash failed.\n";
        uVar3 = 0xc6b;
      }
    }
  }
  printf(pcVar2,"wips_init",uVar3);
LAB_004cbb74:
  wips_uninit();
  return 0xffffffff;
}

