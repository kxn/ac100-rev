// func cloud_mngt_init @ 0049c66c size=3324

undefined4 cloud_mngt_init(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 *local_74;
  undefined4 local_70;
  code *local_6c;
  code *local_68;
  char *local_64;
  undefined4 local_60;
  code *local_5c;
  undefined4 *local_58;
  code *local_54;
  code *local_50;
  code *local_4c;
  code *local_48;
  code *local_44;
  code *local_40;
  undefined4 local_30;
  code *local_24;
  
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = (undefined4 *)0x0;
  local_70 = 0;
  local_6c = (code *)0x0;
  local_68 = (code *)0x0;
  cloud_mngt_msg_mutex = FUN_00407f00("cloud_mngt_msg_mutex",0);
  if (cloud_mngt_msg_mutex == 0) {
    if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
    pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt msg mutex failed.\n";
    pcVar4 = "cloud_mngt_init";
    uVar5 = 0x2034;
  }
  else {
    last_ap_stats_info_report_time = 0;
    DAT_007cca60 = 0;
    DAT_007cca64 = 0;
    DAT_007cca68 = 0;
    nms_report_ap_stats_handle = 0;
    DAT_007cca40 = nms_report_ap_devstats_add_to_json;
    DAT_007cca44 = nms_report_ap_radiostats_add_to_json;
    DAT_007cca48 = nms_report_ap_vapstats_add_to_json;
    cloud_mngt_msg_cond = FUN_00407d80("cloud_mngt_msg_cond");
    if (cloud_mngt_msg_cond == 0) {
      if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
      pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt msg cond failed.\n";
      pcVar4 = "cloud_mngt_init";
      uVar5 = 0x2043;
    }
    else {
      FUN_0051ad88(&g_cloud_mngt_msg_list);
      cloud_mngt_msg_report_mutex = FUN_00407f00("cloud_mngt_msg_report_mutex",0);
      if (cloud_mngt_msg_report_mutex == 0) {
        if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
        pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt report msg mutex failed.\n";
        pcVar4 = "cloud_mngt_init";
        uVar5 = 0x204c;
      }
      else {
        cloud_mngt_msg_report_cond = FUN_00407d80("cloud_mngt_msg_report_cond");
        if (cloud_mngt_msg_report_cond == 0) {
          if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
          pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt report msg cond failed.\n";
          pcVar4 = "cloud_mngt_init";
          uVar5 = 0x2053;
        }
        else {
          cloud_mngt_data_mutex = FUN_00407f00("cloud_mngt_data_mutex",1);
          if (cloud_mngt_data_mutex == 0) {
            if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
            pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt data mutex failed.\n";
            pcVar4 = "cloud_mngt_init";
            uVar5 = 0x205a;
          }
          else {
            FUN_0051ad88(&g_cloud_mngt_msg_report_list);
            FUN_0051ad88(&g_cloud_mngt_sync_module_list);
            local_64 = (char *)0x0;
            local_60 = (uint)local_60._2_2_;
            iVar1 = FUN_00408050(site_id,0x40);
            if (iVar1 == 0) {
              strcpy(site_id,"0");
              iVar1 = FUN_005135a8(&local_64);
              if (iVar1 == 0) {
                sprintf(device_mac,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_64 >> 0x18,
                        (uint)local_64 >> 0x10 & 0xff,(uint)local_64 >> 8 & 0xff,
                        (uint)local_64 & 0xff,local_60 >> 0x18,local_60 >> 0x10 & 0xff);
                iVar1 = FUN_00408700(&device_type,0x21);
                if (iVar1 == 0) {
                  iVar1 = FUN_00408140(&firmware_id,0x21);
                  if (iVar1 == 0) {
                    iVar1 = FUN_00408350(&g_device_name,0x81);
                    if (iVar1 == 0) {
                      iVar1 = cloud_mngt_key_cert_path_init();
                      if (iVar1 == 0) {
                        iVar1 = FUN_004084d0("cloud_mngt_report_para",2,
                                             cloud_mngt_jcs_report_para_set);
                        if (((((iVar1 != 0) ||
                              (iVar1 = FUN_004084d0("ap_report_switch",2,
                                                    cloud_mngt_jcs_report_msg_set), iVar1 != 0)) ||
                             (iVar1 = FUN_004084d0("client_report_switch",2,
                                                   cloud_mngt_jcs_client_report_switch_set),
                             iVar1 != 0)) ||
                            ((((iVar1 = FUN_004084d0("ap_update_token",2,
                                                     cloud_mngt_jcs_update_token_set), iVar1 != 0 ||
                               (iVar1 = FUN_004084d0("ap_set_token",2,cloud_mngt_jcs_set_token_set),
                               iVar1 != 0)) ||
                              ((iVar1 = FUN_004084d0("cloud_mngt_sync_device_config",2,
                                                     cloud_mngt_jcs_device_cloud_config_id_set),
                               iVar1 != 0 ||
                               ((iVar1 = FUN_004084d0("cloud_mngt_sync_cloud_config_switch",2,
                                                      cloud_mngt_jcs_cloud_config_switch_set),
                                iVar1 != 0 ||
                                (iVar1 = FUN_004084d0("cloud_mngt_clear_config_id",2,
                                                      cloud_mngt_jcs_clear_cloud_config_id),
                                iVar1 != 0)))))) ||
                             (iVar1 = FUN_004084d0("ac_alias_changed",2,cloud_mngt_jcs_alias_changed
                                                  ), iVar1 != 0)))) ||
                           (((iVar1 = FUN_004084d0("ac_config_id_changed",2,
                                                   cloud_mngt_jcs_config_id_changed), iVar1 != 0 ||
                             (iVar1 = FUN_004084d0("cloud_mngt_sync_module_config_report",2,
                                                   cloud_mngt_jcs_sync_module_config), iVar1 != 0))
                            || (iVar1 = FUN_004084d0("notify_unbind",2,cloud_mngt_jcs_notify_unbind)
                               , iVar1 != 0)))) goto LAB_0049c7c0;
                        iVar1 = FUN_004084e0(&g_cloud_mngt_msg_thread,"CloudMsgThread",
                                             cloud_mngt_thread_main,0);
                        if (iVar1 == 0) {
                          iVar1 = FUN_004084e0(&g_cloud_mngt_msg_report_thread,
                                               "CloudMsgReportThread",cloud_mngt_report_thread,0);
                          if (iVar1 == 0) {
                            ap_container = FUN_00408180("ap_container",0x14,ap_report_count,
                                                        cloud_mngt_ap_obj_hash_func,
                                                        cloud_mngt_ap_key_hash_func,
                                                        cloud_mngt_ap_cmp_func,
                                                        cloud_mngt_ap_key_get_func,
                                                        cloud_mngt_ap_data_free,
                                                        cloud_mngt_ap_update_func,
                                                        cloud_mngt_ap_handle);
                            if (ap_container == 0) {
                              if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                              pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d Failed to create ap container\n";
                              pcVar4 = "cloud_mngt_init";
                              uVar5 = 0x207b;
                            }
                            else {
                              client_container =
                                   FUN_00408180("client_container",0xb4,client_report_count,
                                                cloud_mngt_client_obj_hash_func,
                                                cloud_mngt_client_key_hash_func,
                                                cloud_mngt_client_cmp_func,
                                                cloud_mngt_client_key_get_func,
                                                cloud_mngt_client_data_free,
                                                cloud_mngt_client_update_func,
                                                cloud_mngt_client_handle);
                              if (client_container == 0) {
                                if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                pcVar3 = 
                                "[CLOUD_MNGT_ERROR]%s()/%d Failed to create client container\n";
                                pcVar4 = "cloud_mngt_init";
                                uVar5 = 0x2084;
                              }
                              else {
                                client_events_container =
                                     FUN_00407e50("client_event_container",0xb4,client_report_count,
                                                  cloud_mngt_client_events_data_free,
                                                  cloud_mngt_client_events_handle);
                                if (client_events_container == 0) {
                                  if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                  pcVar3 = 
                                  "[CLOUD_MNGT_ERROR]%s()/%d Failed to create client container\n";
                                  pcVar4 = "cloud_mngt_init";
                                  uVar5 = 0x208a;
                                }
                                else {
                                  FUN_00408600(client_events_container,1);
                                  bssid_info_changed_sc =
                                       FUN_00408180("bssid_container",bssid_info_changed_sc_interval
                                                    ,bssid_info_changed_sc_num,
                                                    cloud_mngt_bssid_obj_hash_func,
                                                    cloud_mngt_bssid_key_hash_func,
                                                    cloud_mngt_bssid_cmp_func,
                                                    cloud_mngt_bssid_key_get_func,
                                                    cloud_mngt_bssid_data_free,
                                                    cloud_mngt_bssid_update_func,
                                                    cloud_mngt_bssid_handle);
                                  if (bssid_info_changed_sc == 0) {
                                    if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                    pcVar3 = 
                                    "[CLOUD_MNGT_ERROR]%s()/%d Failed to create client container\n";
                                    pcVar4 = "cloud_mngt_init";
                                    uVar5 = 0x2094;
                                  }
                                  else {
                                    FUN_00408600(bssid_info_changed_sc,1);
                                    memset(&local_64,0,0x4c);
                                    local_58 = &DAT_0069a274;
                                    local_54 = (code *)0x78;
                                    local_50 = cloud_mngt_apmngr_callback_wtp_join;
                                    local_48 = cloud_mngt_apmngr_callback_wtp_add;
                                    local_44 = cloud_mngt_apmngr_callback_wtp_del;
                                    local_4c = cloud_mngt_apmngr_callback_wtp_disconnect;
                                    local_24 = cloud_mngt_apmngr_callback_wtp_name_changed;
                                    iVar1 = apmngr_callback_register(&local_64);
                                    if (iVar1 == -1) {
                                      if (cloud_mngt_err_switch != '\0') {
                                        printf("[CLOUD_MNGT_ERROR]%s()/%d register callback to apmngr failed.\n"
                                               ,"cloud_mngt_apmngr_callback_init",0xe2e);
                                      }
                                      if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                      pcVar3 = 
                                      "[CLOUD_MNGT_ERROR]%s()/%d Failed to cloud_mngt_apmngr_callback_init\n"
                                      ;
                                      pcVar4 = "cloud_mngt_init";
                                      uVar5 = 0x209c;
                                    }
                                    else {
                                      local_58 = (undefined4 *)0x0;
                                      local_64 = "cloud";
                                      local_60 = 0x79000000;
                                      local_5c = cloud_multilink_switch_to_master;
                                      iVar1 = multi_link_reg(&local_64);
                                      if (iVar1 == -1) {
                                        if (cloud_mngt_err_switch != '\0') {
                                          printf("[CLOUD_MNGT_ERROR]%s()/%d register callback to multi link failed.\n"
                                                 ,"cloud_mngt_multilink_callback_init",0x1fa9);
                                        }
                                        if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                        pcVar3 = 
                                        "[CLOUD_MNGT_ERROR]%s()/%d Failed to cloud_mngt_multilink_callback_init\n"
                                        ;
                                        pcVar4 = "cloud_mngt_init";
                                        uVar5 = 0x20a2;
                                      }
                                      else {
                                        memset(&local_64,0,0x20);
                                        local_58 = &DAT_0069a274;
                                        local_54 = (code *)0x78;
                                        local_4c = cloud_mngt_bssid_callback_add;
                                        local_50 = cloud_mngt_bssid_callback_del;
                                        iVar1 = stats_db_bssid_changed_notify_register(&local_64);
                                        if (iVar1 == -1) {
                                          if (cloud_mngt_err_switch != '\0') {
                                            printf(
                                                  "[CLOUD_MNGT_ERROR]%s()/%d register callback to bssid_info_reg_s failed.\n"
                                                  ,"cloud_mngt_bssid_update_callback_init",0xe61);
                                          }
                                          if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                          pcVar3 = 
                                          "[CLOUD_MNGT_ERROR]%s()/%d Failed to cloud_mngt_apmngr_callback_init\n"
                                          ;
                                          pcVar4 = "cloud_mngt_init";
                                          uVar5 = 0x20a8;
                                        }
                                        else {
                                          memset(&local_64,0,0x38);
                                          local_58 = &DAT_0069a274;
                                          local_4c = cloud_mngt_rd_cfg_all_change_cb;
                                          local_54 = _cloud_mngt_rd_cfg_changed;
                                          local_50 = _cloud_mngt_rd_cfg_changed;
                                          local_48 = cloud_mngt_rd_cfg_change;
                                          local_30 = 100;
                                          iVar1 = rdmngr_callback_register(&local_64);
                                          if (iVar1 == -1) {
                                            if (cloud_mngt_err_switch != '\0') {
                                              printf(
                                                  "[CLOUD_MNGT_ERROR]%s()/%d rdmngr_callback_register() fail!\n"
                                                  ,"cloud_mngt_rdmngr_callback_init",0x1fbd);
                                            }
                                            if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                            pcVar3 = 
                                            "[CLOUD_MNGT_ERROR]%s()/%d Failed to cloud_mngt_rdmngr_callback_init\n"
                                            ;
                                            pcVar4 = "cloud_mngt_init";
                                            uVar5 = 0x20ae;
                                          }
                                          else {
                                            memset(&local_64,0,0x2c);
                                            local_64 = (char *)0x636c6f75;
                                            local_60 = 0x645f6d6e;
                                            local_5c = (code *)CONCAT22(0x6774,local_5c._2_2_);
                                            local_44 = (code *)0xa;
                                            local_40 = cloud_mngt_wsta_callback_sta_add;
                                            iVar1 = wsta_db_event_register(0,&local_64);
                                            if (iVar1 == 0) {
                                              local_40 = cloud_mngt_wsta_callback_sta_del;
                                              iVar1 = wsta_db_event_register(1,&local_64);
                                              if (iVar1 == 0) {
                                                iVar1 = init_info_report2();
                                                if (iVar1 == 0) {
                                                  iVar1 = stats_db_fail_sta_hdl_reg
                                                                    (cloud_mngt_fail_client_handle);
                                                  if (iVar1 == 0) {
                                                    iVar1 = 0;
                                                    iVar2 = stats_db_auth_ok_sta_hdl_reg
                                                                      (
                                                  cloud_mngt_auth_ok_client_handle);
                                                  if (iVar2 == 0) {
                                                    do {
                                                      local_80 = 0;
                                                      local_7c = 0;
                                                      local_78 = 0;
                                                      iVar2 = iVar1 + 1;
                                                      local_74 = &DAT_0069a274;
                                                      local_70 = 0x78;
                                                      local_6c = cloud_mngt_ap_sample_time_change_cb
                                                      ;
                                                      local_68 = cloud_mngt_ap_sample_normal_cb;
                                                      stats_db_sample_time_changed_notify_register
                                                                (&local_80,iVar1);
                                                      iVar1 = iVar2;
                                                    } while (iVar2 != 4);
                                                    local_64 = (char *)0x0;
                                                    local_60 = 0;
                                                    local_5c = (code *)0x0;
                                                    local_58 = &DAT_0069a274;
                                                    local_54 = cloud_mngt_rrm_start_cb;
                                                    local_50 = cloud_mngt_rrm_finish_cb;
                                                    local_4c = (code *)0x64;
                                                    iVar1 = rrm_callback_register(&local_64);
                                                    if (iVar1 == -1) {
                                                      if (cloud_mngt_err_switch != '\0') {
                                                        printf(
                                                  "[CLOUD_MNGT_ERROR]%s()/%d rrm_callback_register() fail!\n"
                                                  ,"cloud_mngt_rrm_callback_init",0x1fdf);
                                                  }
                                                  if (cloud_mngt_err_switch == '\0')
                                                  goto LAB_0049c7c0;
                                                  pcVar3 = 
                                                  "[CLOUD_MNGT_ERROR]%s()/%d Failed to rrm_callback_register\n"
                                                  ;
                                                  pcVar4 = "cloud_mngt_init";
                                                  uVar5 = 0x20d5;
                                                  }
                                                  else {
                                                    cloud_mngt_feature_register();
                                                    system(
                                                  "ubus call cloudclient register_cmd_callback \'{ \"register_notify_cmd\": \"lua /usr/lib/lua/luci/model/apmngr_cloud_report_switch.lua on sub_devices\", \"wait_time\": 0, \"type\": \"online\", \"action\":\"add\" }\'"
                                                  );
                                                  system(
                                                  "ubus call cloudclient register_cmd_callback \'{ \"register_notify_cmd\": \"lua /usr/lib/lua/luci/model/apmngr_cloud_report_switch.lua off \", \"wait_time\": 0, \"type\": \"offline\", \"action\":\"add\" }\'"
                                                  );
                                                  system(
                                                  "ubus call cloudclient register_cmd_callback \'{ \"register_notify_cmd\": \"lua /usr/lib/lua/luci/model/check_cert.lua offline \", \"wait_time\": 0, \"type\": \"offline\", \"action\":\"add\" }\'"
                                                  );
                                                  system(
                                                  "ubus call cloudclient register_cmd_callback \'{ \"register_notify_cmd\": \"lua /usr/lib/lua/luci/model/check_cert.lua online\", \"wait_time\": 0, \"type\": \"online\", \"action\":\"add\" }\'"
                                                  );
                                                  system(
                                                  "ubus call cloudclient register_cmd_callback \'{ \"register_notify_cmd\": \"lua /usr/lib/lua/luci/model/apmngr_cloud_update_token.lua\", \"wait_time\": 0, \"type\": \"new_token_change\", \"action\":\"add\" }\'"
                                                  );
                                                  cloud_mngt_debug_init();
                                                  iVar1 = uac_nms_report_init();
                                                  if (iVar1 == 0) {
                                                    return 0;
                                                  }
                                                  if (cloud_mngt_err_switch == '\0')
                                                  goto LAB_0049c7c0;
                                                  pcVar3 = 
                                                  "[CLOUD_MNGT_ERROR]%s()/%d Failed to uac_nms_report_init\n"
                                                  ;
                                                  pcVar4 = "cloud_mngt_init";
                                                  uVar5 = 0x20e0;
                                                  }
                                                  }
                                                  else {
                                                    if (cloud_mngt_err_switch == '\0')
                                                    goto LAB_0049c7c0;
                                                    pcVar3 = 
                                                  "[CLOUD_MNGT_ERROR]%s()/%d Failed to stats_db_fail_sta_hdl_reg\n"
                                                  ;
                                                  pcVar4 = "cloud_mngt_init";
                                                  uVar5 = 0x20c5;
                                                  }
                                                  }
                                                  else {
                                                    if (cloud_mngt_err_switch == '\0')
                                                    goto LAB_0049c7c0;
                                                    pcVar3 = 
                                                  "[CLOUD_MNGT_ERROR]%s()/%d Failed to stats_db_fail_sta_hdl_reg\n"
                                                  ;
                                                  pcVar4 = "cloud_mngt_init";
                                                  uVar5 = 0x20bf;
                                                  }
                                                }
                                                else {
                                                  if (cloud_mngt_err_switch == '\0')
                                                  goto LAB_0049c7c0;
                                                  pcVar3 = 
                                                  "[CLOUD_MNGT_ERROR]%s()/%d Failed to init_info_report2\n"
                                                  ;
                                                  pcVar4 = "cloud_mngt_init";
                                                  uVar5 = 0x20b9;
                                                }
                                                goto LAB_0049c828;
                                              }
                                              if (cloud_mngt_err_switch != '\0') {
                                                pcVar3 = 
                                                "[CLOUD_MNGT_ERROR]%s()/%d register disassociation evnet callback to wstation  block failed.\n"
                                                ;
                                                uVar5 = 0xfcf;
                                                goto LAB_0049d014;
                                              }
                                            }
                                            else if (cloud_mngt_err_switch != '\0') {
                                              pcVar3 = 
                                              "[CLOUD_MNGT_ERROR]%s()/%d register association evnet callback to wstation  block failed.\n"
                                              ;
                                              uVar5 = 0xfc6;
LAB_0049d014:
                                              printf(pcVar3,"cloud_mngt_wstation_callback_init",
                                                     uVar5);
                                            }
                                            if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                                            pcVar3 = 
                                            "[CLOUD_MNGT_ERROR]%s()/%d Failed to cloud_mngt_wstation_callback_init\n"
                                            ;
                                            pcVar4 = "cloud_mngt_init";
                                            uVar5 = 0x20b4;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else {
                            if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                            pcVar3 = 
                            "[CLOUD_MNGT_ERROR]%s()/%d Failed to create cloud mngt report msg thread\n"
                            ;
                            pcVar4 = "cloud_mngt_init";
                            uVar5 = 0x2073;
                          }
                        }
                        else {
                          if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                          pcVar3 = 
                          "[CLOUD_MNGT_ERROR]%s()/%d Failed to create cloud mngt msg thread\n";
                          pcVar4 = "cloud_mngt_init";
                          uVar5 = 0x206d;
                        }
                      }
                      else {
                        if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                        pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d get path failed\n";
                        pcVar4 = "cloud_mngt_global_config_read";
                        uVar5 = 0x1019;
                      }
                    }
                    else {
                      if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                      pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d get devcie name failed\n";
                      pcVar4 = "cloud_mngt_global_config_read";
                      uVar5 = 0x1012;
                    }
                  }
                  else {
                    if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                    pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d read firmware id from ubus failed\n";
                    pcVar4 = "cloud_mngt_global_config_read";
                    uVar5 = 0x100d;
                  }
                }
                else {
                  if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                  pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d read device type failed\n";
                  pcVar4 = "cloud_mngt_global_config_read";
                  uVar5 = 0x1008;
                }
              }
              else {
                if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
                pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d read mac addr failed\n";
                pcVar4 = "cloud_mngt_global_config_read";
                uVar5 = 0xfff;
              }
            }
            else {
              if (cloud_mngt_err_switch == '\0') goto LAB_0049c7c0;
              pcVar3 = "[CLOUD_MNGT_ERROR]%s()/%d read site_id failed\n";
              pcVar4 = "cloud_mngt_global_config_read";
              uVar5 = 0xff5;
            }
          }
        }
      }
    }
  }
LAB_0049c828:
  printf(pcVar3,pcVar4,uVar5);
LAB_0049c7c0:
  cloud_mngt_fini();
  return 0xffffffff;
}

