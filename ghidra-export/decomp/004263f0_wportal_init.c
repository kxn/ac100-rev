// func wportal_init @ 004263f0 size=4988

undefined4 wportal_init(void)

{
  int iVar1;
  size_t sVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  undefined1 local_198 [4];
  undefined1 auStack_194 [4];
  char *local_190;
  undefined4 local_18c;
  code *local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  char *local_174;
  undefined4 local_170;
  code *local_16c;
  char acStack_168 [32];
  undefined4 local_148;
  code *local_144;
  char acStack_13c [32];
  undefined4 local_11c;
  code *local_118;
  char local_110 [4];
  char *local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 *local_100;
  undefined4 local_fc;
  undefined2 local_f8;
  undefined2 local_f6;
  undefined1 *local_f4;
  undefined4 local_f0;
  code *local_ec;
  code *local_e8;
  undefined4 local_e4;
  undefined1 auStack_e0 [12];
  char *local_d4;
  undefined4 local_d0;
  code *local_cc;
  sockaddr local_94 [7];
  
  iVar1 = FUN_0051eb48("wportal","free_strategy_max",&g_max_free_strategy);
  if (iVar1 != 0) {
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Get free strategy profile info error!\n","wportal_init",0x317b);
    }
    g_max_free_strategy = 0x20;
  }
  iVar1 = FUN_0051eb48("wportal","sessmngr_max",&g_max_session);
  if (iVar1 != 0) {
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Get max session profile info error!\n","wportal_init",0x3182);
    }
    g_max_session = 100000;
  }
  iVar1 = FUN_00407f90("wportal","wechat_wifi_server_host",&wechat_server_host,0x100);
  if (iVar1 != 0) {
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Get wechat server host error!\n","wportal_init",0x3189);
    }
    strncpy(&wechat_server_host,"wifi.weixin.qq.com",0xff);
  }
  local_198[0] = 0;
  local_110[0] = '\0';
  local_110[1] = '\0';
  local_110[2] = '\0';
  local_110[3] = '\0';
  local_108 = 0;
  local_f0 = 0;
  local_10c = "https_enable";
  local_100 = &onoff_map;
  local_104 = 1;
  local_f8 = 1;
  local_f6 = 1;
  local_f4 = local_198;
  local_fc = 10;
  iVar1 = FUN_00408120("authentication","portal",local_110,1);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d uci req parse failed.\n","https_enable_config_restore",0x309a);
    }
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d get https enable failed!\n","wportal_init",0x3190);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  wportal_db_https_enable_set(local_198[0]);
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d  https_enable_config_restore set done\n",
           "https_enable_config_restore",0x30a0);
  }
  FUN_0051ad88(&l_wportal_sta_access_check_reg);
  FUN_0051ad88(&g_wportal_unauth_msg_list);
  iVar1 = wportal_db_init();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  g_wportal_unauth_mutex = FUN_00407f00("g_wportal_unauth_mutex",0);
  if (g_wportal_unauth_mutex == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create g_wportal_unauth_mutex failed.\n","wportal_init",0x31a2);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  g_wportal_unauth_cond = FUN_00407d80("g_wportal_unauth_cond");
  if (g_wportal_unauth_cond == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create g_wportal_unauth_cond failed.\n","wportal_init",0x31a9);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084e0(&g_wportal_unauth_msg_thread,"wportal_unth_report",
                       wportal_unauth_report_thread,0);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Failed to create unth report msg thread\n","wportal_init",0x31af)
      ;
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  cert_time_check_timer = FUN_00408340(0x15180,0,wportal_cert_check,0,0,"wportal_init",0x31b4);
  if (cert_time_check_timer == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d add  cert_time_check_timer failed!\n","wportal_init",0x31b6);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(local_110,0,0x2c);
  memcpy(local_110,"wportal_escape",0xe);
  local_f0 = 10;
  local_ec = _wportal_callback_sta_access_escape_check;
  iVar1 = wportal_sta_access_check_reg(local_110);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d register sta access check callback to wportal failed \n",
             "wportal_init",0x31c5);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084e0(auStack_194,"cloud_portal_update_dns",_cloud_portal_update_dns,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  unlink("/tmp/nginx_to_uac");
  unlink("/tmp/wifidog_to_uac");
  nginx_fd = socket(1,1,0);
  if (nginx_fd < 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create send socket failed.\n","wportal_init",0x31e5);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(local_94,0,0x6e);
  local_94[0].sa_family = 1;
  strcpy(local_94[0].sa_data,"/tmp/nginx_to_uac");
  sVar2 = strlen(local_94[0].sa_data);
  iVar1 = bind(nginx_fd,local_94,sVar2 + 2);
  if (iVar1 < 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Bind send socket failed.\n","wportal_init",0x31f0);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  wifidog_fd = socket(1,1,0);
  if (wifidog_fd < 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create send socket failed.\n","wportal_init",0x31f8);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(local_94,0,0x6e);
  local_94[0].sa_family = 1;
  strcpy(local_94[0].sa_data,"/tmp/wifidog_to_uac");
  sVar2 = strlen(local_94[0].sa_data);
  iVar1 = bind(wifidog_fd,local_94,sVar2 + 2);
  if (iVar1 < 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Bind send socket failed.\n","wportal_init",0x3203);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084d0("wportal",0,_wportal_jcs_add_callback);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d JCS register error!\n","wportal_init",0x320b);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084d0("wportal",1,_wportal_jcs_del_callback);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d JCS register error!\n","wportal_init",0x3212);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084d0("wportal",2,_wportal_jcs_set_callback);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d JCS register error!\n","wportal_init",0x3219);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084d0("wportal",3,_wportal_jcs_get_callback);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d JCS register error!\n","wportal_init",0x3220);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084d0("wportal_backup",3,wportal_jcs_backup_callback);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d JCS register error!\n","wportal_init",0x3227);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = FUN_004084d0("wportal_nsa_sync",2,wportal_jcs_nsa_sync_callback);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d JCS register error!\n","wportal_init",0x322e);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(acStack_13c,0,0x2c);
  strncpy(acStack_13c,"wportal_sta",0x1f);
  local_11c = 10;
  local_118 = _wportal_station_access_notify;
  iVar1 = wsta_db_event_register(0,acStack_13c);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wsta_db_event_register error!\n","wportal_init",0x323b);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(acStack_13c,0,0x2c);
  strncpy(acStack_13c,"wportal_sta",0x1f);
  local_11c = 10;
  local_118 = _wportal_station_ip_update_notify;
  iVar1 = wsta_db_event_register(2,acStack_13c);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wsta_db_event_register error!\n","wportal_init",0x3245);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(acStack_13c,0,0x2c);
  strncpy(acStack_13c,"wportal_sta",0x1f);
  local_11c = 10;
  local_118 = _wportal_station_leave_notify;
  iVar1 = wsta_db_event_register(1,acStack_13c);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wsta_db_event_register error!\n","wportal_init",0x3250);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(auStack_e0,0,0x4c);
  local_d4 = "wportal";
  local_d0 = 0x78;
  local_cc = _wportal_apmngr_callback_wtp_join;
  iVar1 = apmngr_callback_register(auStack_e0);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d register callback to apmngr failed.\n","wportal_init",0x325b);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  local_184 = 0;
  local_190 = "wportal_mtl";
  local_18c = 0xa000000;
  local_188 = _wportal_wtp_access_notify;
  iVar1 = multi_link_reg(&local_190);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d multi_link_reg error!\n","wportal_init",0x3268);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  free_strategy_interval = 5;
  wportal_free_strategy_packet_mutex = FUN_00407f00("wportal_free_strategy_packet_mutex",1);
  if (wportal_free_strategy_packet_mutex == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create database mutex failed.\n","wportal_init",0x3270);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  serv_wtp_address_arg_init(&free_strategy_arg);
  serv_wtp_address_arg_init(&free_strategy_arg_nosupp);
  serv_wtp_address_arg_init(&free_strategy_arg_v6);
  free_strategy_timer =
       FUN_00408340(free_strategy_interval,0,_wportal_free_strategy_packet_timer_handler,0,0,
                    "wportal_init",0x3276);
  if (free_strategy_timer == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d add  free strategy packet timer failed!\n","wportal_init",0x3278)
      ;
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(acStack_168,0,0x2c);
  strncpy(acStack_168,"wportal_wserv_bind",0x1f);
  local_148 = 0x32;
  local_144 = _wportal_wserv_bind_notify;
  iVar1 = wserv_db_event_register(0,acStack_168);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wserv_db_event_register error!\n","wportal_init",0x3282);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(acStack_168,0,0x2c);
  strncpy(acStack_168,"wportal_wserv_unbind",0x1f);
  local_148 = 0x32;
  local_144 = _wportal_wserv_unbind_notify;
  iVar1 = wserv_db_event_register(1,acStack_168);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wserv_db_event_register error!\n","wportal_init",0x328c);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(acStack_168,0,0x2c);
  strncpy(acStack_168,"wportal_ssid_portal_switch",0x1f);
  local_148 = 0x32;
  local_144 = wportal_update_ssid_portal_switch_to_ap;
  iVar1 = wserv_db_event_register(5,acStack_168);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wserv_db_event_register error!\n","wportal_init",0x3296);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(acStack_168,0,0x2c);
  strncpy(acStack_168,"wportal_wserv_del",0x1f);
  local_148 = 0x32;
  local_144 = _wportal_wserv_del_notify;
  iVar1 = wserv_db_event_register(4,acStack_168);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wserv_db_event_register error!\n","wportal_init",0x32a0);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  wportal_sta_update_mutex = FUN_00407f00("wportal_sta_update_mutex",1);
  if (wportal_sta_update_mutex == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create sta_update mutex failed.\n","wportal_init",0x32a7);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  wportal_cloud_server_update_mutex = FUN_00407f00("wportal_cloud_server_update_mutex",1);
  if (wportal_cloud_server_update_mutex == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create wportal_cloud_server_update_mutex failed.\n",
             "wportal_init",0x32ae);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  local_180 = 0;
  local_17c = 0;
  local_178 = 0;
  local_170 = 10;
  local_174 = "sta_update";
  local_16c = wportal_stream_statistics_cb;
  iVar1 = stats_callback_register(&local_180);
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d stats_callback_register error!\n","wportal_init",0x32b9);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  memset(local_110,0,0x30);
  snprintf(local_110,0x20,"wportal_auth");
  local_f0 = 10;
  local_ec = (code *)0x1;
  local_e4 = 0;
  local_e8 = wportal_sta_auth_cb;
  iVar1 = wportal_db_event_register(local_110);
  if (iVar1 == -1) {
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d register to wportal failed.\n","wportal_auth_event_cb_register",
             0x314b);
    }
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d wportal_auth_event_cb_register failed.\n","wportal_init",0x32bf);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = ac_cmcc_portal_init();
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d ac_cmcc_portal_init error!\n","wportal_init",12999);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = sso_notify_init();
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d sso_notify_init error!\n","wportal_init",0x32ce);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  wportal_update_rdt_ftt_mutex = FUN_00407f00("wportal_update_rdt_ftt_mutex",0);
  if (wportal_update_rdt_ftt_mutex == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create wportal cloud mutex error!\n","wportal_init",0x32dd);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  wportal_update_rdt_ftt_cond = FUN_00407d80("wportal_update_rdt_ftt_cond");
  if (wportal_update_rdt_ftt_cond == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Create wportal cloud cond error!\n","wportal_init",0x32e4);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  FUN_0051ad88(&g_wportal_update_rdt_ftt_list);
  iVar1 = FUN_004084e0(&g_wportal_update_rdt_ftt_thread,"wportal_update_rdt_ftt",
                       wportal_thread_update_rdt_ftt_to_ap,0);
  if (iVar1 != 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[WPORTAL_ERR]%s()/%d Failed to create wportal cloud thread!\n","wportal_init",0x32ec);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  pFVar3 = popen("ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"echo  18\",\"wait_time\":0,\"type\":\"feature\",\"action\":\"add\"}\' &> /dev/null"
                 ,"r");
  if (pFVar3 == (FILE *)0x0) {
    if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_004276a8;
    uVar4 = 0x30b1;
  }
  else {
    pclose(pFVar3);
    pFVar3 = popen("ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\": \"[ ! -f /tmp/custom_download_done ] && lua /usr/lib/lua/luci/model/cloud_template_handler.lua  nil nil cloud-custom\", \"wait_time\": 10, \"type\": \"online\", \"action\":\"add\" }\' &> /dev/null"
                   ,"r");
    if (pFVar3 == (FILE *)0x0) {
      if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_004276a8;
      uVar4 = 0x30bb;
    }
    else {
      pclose(pFVar3);
      pFVar3 = popen("ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"echo 19\",\"wait_time\":0,\"type\":\"feature\",\"action\":\"add\"}\' &> /dev/null"
                     ,"r");
      if (pFVar3 != (FILE *)0x0) {
        pclose(pFVar3);
        apmngr_support_capacity_register(2);
        apmngr_support_capacity_register(7);
        apmngr_support_sub_capacity_register(2,0);
        apmngr_support_sub_capacity_register(2,1);
        apmngr_support_capacity_register(0x21);
        wportal_debug_init();
        return 0;
      }
      if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_004276a8;
      uVar4 = 0x30c4;
    }
  }
  printf("[WPORTAL_ERR]%s()/%d Register feature report to cloud client failed.\n",
         "wportal_cloud_client_register",uVar4);
LAB_004276a8:
  if (wportal_err_switch == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 != 0) {
    printf("[WPORTAL_ERR]%s()/%d Failed to wportal_cloud_client_register!\n","wportal_init",0x32f2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

