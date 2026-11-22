// func apmngr_init @ 00530ae0 size=3212

undefined4 apmngr_init(void)

{
  int iVar1;
  uint uVar2;
  FILE *__stream;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *local_438;
  char *local_434;
  undefined4 local_430;
  undefined4 local_424;
  undefined4 local_420;
  int local_410;
  undefined4 local_40c;
  int local_408;
  undefined4 local_404;
  undefined4 local_400;
  int local_3fc;
  undefined4 local_3f8;
  undefined4 local_3f4;
  undefined4 local_3f0;
  undefined4 local_3ec;
  char *local_3e8;
  code *local_3e4;
  undefined4 local_3e0;
  char local_3dc [32];
  char local_3bc [64];
  char acStack_37c [64];
  undefined4 local_33c;
  char *local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 *local_32c;
  undefined4 local_328;
  undefined2 local_324;
  undefined2 local_322;
  undefined4 *local_320;
  undefined4 local_31c;
  undefined4 local_318;
  char *local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined2 local_300;
  undefined2 local_2fe;
  char *local_2fc;
  undefined4 local_2f8;
  char acStack_2f4 [128];
  undefined4 local_274;
  code *local_270;
  undefined4 local_268;
  char *local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 *local_258;
  undefined4 local_254;
  undefined2 local_250;
  undefined2 local_24e;
  int *local_24c;
  undefined4 local_248;
  undefined4 local_244;
  char *local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 *local_234;
  undefined4 local_230;
  undefined2 local_22c;
  undefined2 local_22a;
  int *local_228;
  undefined4 local_224;
  undefined4 local_220;
  char *local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined2 local_208;
  undefined2 local_206;
  undefined4 *local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  char *local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined2 local_1e4;
  undefined2 local_1e2;
  undefined4 *local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  char *local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined2 local_1c0;
  undefined2 local_1be;
  char *local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  char *local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined2 local_19c;
  undefined2 local_19a;
  undefined4 *local_198;
  undefined4 local_194;
  undefined4 local_190;
  char *local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 *local_180;
  undefined4 local_17c;
  undefined2 local_178;
  undefined2 local_176;
  undefined4 *local_174;
  undefined4 local_170;
  undefined4 local_16c;
  char *local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 *local_15c;
  undefined4 local_158;
  undefined2 local_154;
  undefined2 local_152;
  undefined4 *local_150;
  undefined4 local_14c;
  undefined4 local_148;
  char *local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 *local_138;
  undefined4 local_134;
  undefined2 local_130;
  undefined2 local_12e;
  int *local_12c;
  undefined4 local_128;
  undefined4 local_124;
  char *local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined2 local_10c;
  undefined2 local_10a;
  char *local_108;
  undefined4 local_104;
  undefined4 local_100;
  char *local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined2 local_e8;
  undefined2 local_e6;
  char *local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  char *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 *local_cc;
  undefined4 local_c8;
  undefined2 local_c4;
  undefined2 local_c2;
  undefined4 *local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  char *local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  undefined4 local_a4;
  undefined2 local_a0;
  undefined2 local_9e;
  int *local_9c;
  undefined4 local_98;
  undefined4 local_94;
  char *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined4 *local_78;
  undefined4 local_74;
  undefined4 local_70;
  char *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  char *local_30;
  undefined4 local_2c;
  
  local_3f4 = 0;
  local_3f0 = 0;
  local_3ec = 0;
  local_3e8 = (char *)0x0;
  local_3e4 = (code *)0x0;
  local_3e0 = 0;
  memset(acStack_2f4,0,0x8c);
  FUN_0051ad88(&g_apmngr_callback_list);
  FUN_0051ad88(&g_apmngr_check_callback_list);
  memset(&sub_cap_index,-1,0x60);
  iVar1 = apmngr_db_init();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = apmngr_db_sqlite_init();
  if (iVar1 != 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APMNGR_ERROR]%s()/%d Failed to init sqlite.\n\n";
    pcVar4 = "apmngr_init";
    uVar5 = 0xd13;
    goto LAB_00530f10;
  }
  iVar1 = apmngr_jcs_reg_callback();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = apmngr_support_capacity_init();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = apmngr_pkt_init();
  local_108 = local_3dc;
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  local_3f8 = 0;
  local_3fc = 0;
  local_400 = 0;
  local_404 = 0;
  memset(local_108,0,0x20);
  memset(local_3bc,0,0x20);
  local_408 = 0;
  local_40c = 0;
  memset(&local_33c,0,0x40);
  memset(acStack_37c,0,0x40);
  local_174 = &local_3f8;
  local_190 = 0;
  local_176 = 4;
  local_152 = 4;
  local_12e = 4;
  local_12c = &local_3fc;
  local_168 = "auto_firm";
  local_150 = &local_400;
  local_124 = 3;
  local_148 = 2;
  local_18c = "apmngr_status";
  local_188 = 0;
  local_170 = 0;
  local_144 = "auto_reboot";
  local_164 = 0;
  local_14c = 0;
  local_184 = 1;
  local_17c = 10;
  local_180 = &onoff_map;
  local_15c = &onoff_map;
  local_158 = 10;
  local_138 = &onoff_map;
  local_134 = 10;
  local_120 = "reboot_day";
  local_178 = 1;
  local_16c = 1;
  local_160 = 1;
  local_154 = 1;
  local_140 = 0;
  local_13c = 1;
  local_130 = 1;
  local_128 = 0;
  local_11c = 1;
  local_118 = 0;
  local_fc = "reboot_time";
  local_10a = 0x20;
  local_dc = 5;
  local_100 = 4;
  local_e6 = 0x20;
  local_d8 = "dft_offline_selfmanage";
  local_c0 = &local_404;
  local_cc = &onoff_map;
  local_b8 = 6;
  local_c8 = 10;
  local_c2 = 4;
  local_a8 = &onoff_map;
  local_9c = &local_408;
  local_b4 = "sub_proxy_enable";
  local_a4 = 10;
  local_114 = 0;
  local_110 = 0;
  local_10c = 1;
  local_104 = 0;
  local_f8 = 1;
  local_f4 = 0;
  local_f0 = 0;
  local_ec = 0;
  local_e8 = 1;
  local_e0 = 0;
  local_d4 = 0;
  local_d0 = 0;
  local_c4 = 1;
  local_bc = 0;
  local_b0 = 0;
  local_ac = 1;
  local_a0 = 1;
  local_9e = 4;
  local_80 = 10;
  local_78 = &local_40c;
  local_94 = 7;
  local_70 = 8;
  local_56 = 0x40;
  local_32 = 0x40;
  local_7a = 4;
  local_6c = "sub_proxy_uri";
  local_98 = 0;
  local_4c = 9;
  local_90 = "sub_proxy_url_max_len";
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_7c = 1;
  local_74 = 0;
  local_68 = 1;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 1;
  local_50 = 0;
  local_48 = "sub_proxy_protocol";
  local_44 = 1;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 1;
  local_2c = 0;
  local_e4 = local_3bc;
  local_54 = &local_33c;
  local_30 = acStack_37c;
  iVar1 = FUN_00408120("apmng_set","settings",&local_190,10);
  if (iVar1 != 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APMNGR_ERROR]%s()/%d uci req parse failed.\n";
    pcVar4 = "apmngr_global_config_restore";
    uVar5 = 0x3cb;
    goto LAB_00530f10;
  }
  local_400 = 1;
  if ((local_3fc == 1) && ((local_3dc[0] == '\0' || (local_3bc[0] == '\0')))) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APMNGR_ERROR]%s()/%d Reboot date and time parse failed.\n";
    pcVar4 = "apmngr_global_config_restore";
    uVar5 = 0x3d4;
    goto LAB_00530f10;
  }
  local_24c = &local_410;
  local_410 = 0;
  local_268 = 0;
  local_260 = 0;
  local_25c = 0;
  local_254 = 10;
  local_240 = "https_port";
  local_264 = "http_port";
  local_230 = 10;
  local_228 = &local_410;
  local_258 = (undefined4 *)0x0;
  local_250 = 1;
  local_24e = 4;
  local_248 = 0;
  local_244 = 0;
  local_23c = 0;
  local_238 = 0;
  local_234 = (undefined4 *)0x0;
  local_22c = 1;
  local_22a = 4;
  local_224 = 0;
  iVar1 = strcmp(acStack_37c,"http");
  if (iVar1 == 0) {
    iVar1 = FUN_00408120("ngx_proxy",&DAT_00681f70,&local_268,1);
    if (iVar1 == 0) {
LAB_005310dc:
      local_438 = acStack_37c;
      apmngr_suy_proxy_info_set(local_408,local_40c,local_410,&local_33c);
      apmngr_global_status_set(local_3f8);
      apmngr_db_set_dft_offline_selfmanage(local_404);
      iVar1 = apmngr_global_config_set(local_3fc,local_400,local_3dc,local_3bc);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      local_410 = 0;
      local_408 = 0;
      local_40c = 4;
      local_404 = 0;
      local_3dc[0] = '\0';
      local_3dc[1] = '\0';
      local_3dc[2] = '\0';
      local_3dc[3] = '\0';
      local_3dc[4] = '\0';
      local_3dc[5] = '\0';
      local_3dc[6] = '\0';
      local_3dc[7] = '\0';
      local_3dc[8] = '\0';
      local_3dc[9] = '\0';
      local_3dc[10] = '\0';
      local_3dc[0xb] = '\0';
      local_3dc[0xc] = '\0';
      local_3dc[0xd] = '\0';
      local_3dc[0xe] = '\0';
      local_3dc[0xf] = '\0';
      local_3dc[0x10] = '\0';
      local_3dc[0x11] = '\0';
      local_3dc[0x12] = '\0';
      local_3dc[0x13] = '\0';
      local_400 = 0x14;
      memset(local_3bc,0,0x40);
      local_24c = &local_410;
      local_268 = 0;
      local_258 = &onoff_map;
      local_234 = &onoff_map;
      local_228 = &local_408;
      local_264 = "ac_log_switch";
      local_220 = 2;
      local_260 = 0;
      local_25c = 1;
      local_254 = 10;
      local_21c = "ac_log_level";
      local_204 = &local_40c;
      local_240 = "remote_server_switch";
      local_230 = 10;
      local_1fc = 3;
      local_20c = 10;
      local_250 = 1;
      local_24e = 4;
      local_1f8 = "remote_log_level";
      local_1e0 = &local_404;
      local_248 = 0;
      local_244 = 1;
      local_23c = 0;
      local_238 = 1;
      local_22c = 1;
      local_22a = 4;
      local_224 = 0;
      local_218 = 0;
      local_214 = 0;
      local_210 = 0;
      local_208 = 1;
      local_206 = 4;
      local_200 = 0;
      local_1f4 = 0;
      local_1f0 = 0;
      local_1e8 = 10;
      local_1a0 = 10;
      local_198 = &local_400;
      local_1ec = 0;
      local_1d4 = "remote_server";
      local_1e4 = 1;
      local_1be = 0x40;
      local_1e2 = 4;
      local_1b4 = 5;
      local_1dc = 0;
      local_1d8 = 4;
      local_1d0 = 1;
      local_1cc = 0;
      local_1c8 = 0;
      local_1c4 = 0;
      local_1c0 = 1;
      local_1b8 = 0;
      local_1b0 = "remote_report_interval";
      local_1ac = 0;
      local_1a8 = 0;
      local_1a4 = 0;
      local_19c = 1;
      local_19a = 4;
      local_194 = 0;
      local_1bc = local_3bc;
      iVar1 = FUN_00408120("apmng_set","aplog_setting",&local_268,6);
      if (iVar1 == 0) {
        if ((local_408 == 1) && (iVar1 = FUN_0051a7a8(local_3bc,local_3dc), iVar1 != 0)) {
          if (apmngr_err_switch == '\0') {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          printf("[APMNGR_ERROR]%s()/%d Illegal remote server:%s.\n","apmngr_aplog_config_restore",
                 0x406,local_3bc);
          return 0xffffffff;
        }
        for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
          *(char *)((int)&local_438 + uVar2) = local_3dc[uVar2];
        }
        local_420 = 0;
        local_424 = local_400;
        iVar1 = apmngr_aplog_config_set(local_410,local_40c,local_408,local_404);
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        local_400 = 0;
        memset(local_3bc,0,0x20);
        local_33c = 0;
        local_328 = 10;
        local_334 = 0;
        local_322 = 4;
        local_320 = &local_400;
        local_338 = "enable";
        local_31c = 0;
        local_330 = 1;
        local_324 = 1;
        local_318 = 1;
        local_310 = 1;
        local_300 = 1;
        local_32c = &onoff_map;
        local_314 = "telnet_port";
        local_30c = 0;
        local_308 = 0;
        local_304 = 0;
        local_2fe = 0x20;
        local_2f8 = 0;
        local_2fc = local_3bc;
        iVar1 = FUN_00408120("diagnose","settings",&local_33c,2);
        if (iVar1 == 0) {
          apmngr_db_telnet_enable_set(local_400);
          iVar1 = strcmp(local_3bc,"default");
          if (iVar1 != 0) {
            uVar2 = atoi(local_3bc);
            apmngr_db_telnet_port_set(uVar2 & 0xffff);
          }
          if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APMNGR_DEBUG]%s()/%d diagnose global config set done\n",
                   "diagnose_global_config_restore",0x42b);
          }
          local_3f4 = 0;
          local_3f0 = 0;
          local_3ec = 0;
          local_3e0 = 0;
          local_3e8 = "apmngr";
          local_3e4 = apmngr_apdb_update_proc;
          iVar1 = apdb_callback_register(&local_3f4);
          if (iVar1 != 0) {
            return 0xffffffff;
          }
          memset(acStack_2f4,0,0x8c);
          strncpy(acStack_2f4,"apmngr",0x7f);
          local_274 = 100;
          local_270 = _apmngr_systime_callback;
          iVar1 = systime_event_register(acStack_2f4);
          if (iVar1 != 0) {
            return 0xffffffff;
          }
          apmngr_debug_init();
          iVar1 = apmngr_db_sync_init();
          if (iVar1 != 0) {
            return 0xffffffff;
          }
          iVar1 = apmngr_db_datasync_init();
          if (iVar1 != 0) {
            return 0xffffffff;
          }
          memset(local_3bc,0,0x40);
          __stream = fopen("/tmp/ha_mngt/trp_mystate","rb");
          if (__stream == (FILE *)0x0) {
            return 0;
          }
          fread(local_3bc,1,0x40,__stream);
          fclose(__stream);
          if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APMNGR_DEBUG]%s()/%d trp_mystate = %s\n","apmngr_ac_datasync_status_restore",
                   0x446,local_3bc);
          }
          iVar1 = memcmp(local_3bc,"slave",5);
          if (iVar1 == 0) {
            local_438 = (char *)0x0;
            ac_datasync_status = 0;
            local_434 = "apmngr_ac_datasync_status_restore";
            local_430 = 0x44a;
            g_apmngr_id_datasync_timer =
                 FUN_00408340(g_apmngr_id_datasync_time,0,apmngr_id_datasync_timeout,0);
            return 0;
          }
          iVar1 = memcmp(local_3bc,"master",6);
          if (iVar1 == 0) {
            ac_datasync_status = 1;
            return 0;
          }
          iVar1 = memcmp(local_3bc,"load_balance",0xc);
          if (iVar1 != 0) {
            return 0;
          }
          ac_datasync_status = 2;
          return 0;
        }
        if (apmngr_err_switch == '\0') {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar3 = "[APMNGR_ERROR]%s()/%d uci req parse failed.\n";
        pcVar4 = "diagnose_global_config_restore";
        uVar5 = 0x421;
      }
      else {
        if (apmngr_err_switch == '\0') {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar3 = "[APMNGR_ERROR]%s()/%d uci req parse failed.\n";
        pcVar4 = "apmngr_aplog_config_restore";
        uVar5 = 0x3ff;
      }
      goto LAB_00530f10;
    }
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar3 = "[APMNGR_ERROR]%s()/%d uci req parse failed.\n";
      uVar5 = 0x38d;
      goto LAB_0053107c;
    }
  }
  else {
    iVar1 = strcmp(acStack_37c,"https");
    if (iVar1 == 0) {
      iVar1 = FUN_00408120("ngx_proxy",&DAT_00681f70,&local_244,1);
      if (iVar1 == 0) goto LAB_005310dc;
      if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar3 = "[APMNGR_ERROR]%s()/%d uci req parse failed.\n";
        uVar5 = 0x396;
        goto LAB_0053107c;
      }
    }
    else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar3 = "[APMNGR_ERROR]%s()/%d Unrecognized protocol!\n";
      uVar5 = 0x39c;
LAB_0053107c:
      printf(pcVar3,"apmngr_sub_proxy_port_get",uVar5);
    }
  }
  if (apmngr_err_switch == '\0') {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar3 = "[APMNGR_ERROR]%s()/%d get sub_proxy_port failed\n";
  pcVar4 = "apmngr_global_config_restore";
  uVar5 = 0x3db;
LAB_00530f10:
  printf(pcVar3,pcVar4,uVar5);
  return 0xffffffff;
}

