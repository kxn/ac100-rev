// func uac_wservice_init @ 005e01a0 size=3584

undefined4 uac_wservice_init(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  byte local_410;
  byte local_40f;
  byte local_40e [2];
  ushort local_40c;
  ushort local_40a;
  ushort local_408 [2];
  char *local_404;
  undefined4 local_400;
  code *local_3fc;
  undefined4 local_3f8;
  uint local_3f4;
  uint local_3f0 [5];
  uint local_3dc;
  undefined1 auStack_3db [3];
  undefined1 auStack_3d8 [12];
  char *local_3cc;
  code *local_3c8;
  code *local_3c4;
  code *local_3bc;
  code *local_3b0;
  undefined4 local_3a4;
  char acStack_3a0 [8];
  undefined1 auStack_398 [56];
  undefined1 auStack_360 [12];
  char *local_354;
  undefined4 local_350;
  code *local_34c;
  code *local_348;
  code *local_344;
  code *local_340;
  code *local_334;
  code *local_330;
  code *local_32c;
  code *local_328;
  code *local_31c;
  char local_314 [4];
  char *local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 *local_304;
  undefined4 local_300;
  undefined2 local_2fc;
  undefined2 local_2fa;
  byte *local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  char *local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined2 local_2d8;
  undefined2 local_2d6;
  byte *local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  char *local_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined2 local_2b4;
  undefined2 local_2b2;
  ushort *local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  char *local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined2 local_290;
  undefined2 local_28e;
  ushort *local_28c;
  undefined4 local_288;
  undefined4 local_284;
  char *local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined2 local_26c;
  undefined2 local_26a;
  ushort *local_268;
  undefined4 local_264;
  undefined4 local_260;
  char *local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined2 local_248;
  undefined2 local_246;
  byte *local_244;
  undefined4 local_240;
  undefined1 auStack_23c [283];
  undefined4 local_121;
  undefined4 local_11d;
  undefined1 uStack_119;
  uint local_118;
  undefined4 local_114;
  undefined4 local_110;
  char acStack_10c [50];
  undefined4 local_da;
  undefined4 local_d6;
  undefined4 local_d2;
  undefined1 local_45;
  byte local_42;
  byte local_41;
  ushort local_40;
  ushort local_3e;
  ushort local_3c;
  byte local_3a;
  undefined1 local_39;
  undefined1 local_38;
  int local_30;
  int local_2c;
  
  memset(auStack_360,0,0x4c);
  local_404 = (char *)0x0;
  local_400 = 0;
  local_3fc = (code *)0x0;
  local_3f8 = 0;
  memset(auStack_3d8,0,0x38);
  FUN_0051ad88(&g_wserv_callback_list);
  local_30 = wserv_db_wserv_tbl_exists_in_db();
  local_2c = wserv_db_ip_tbl_exists_in_db();
  iVar2 = wserv_db_init();
  if (iVar2 != 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> wserv_db_init() fail!\r\n";
    uVar6 = 0x174a;
    goto LAB_005e02b8;
  }
  iVar2 = wserv_sqlite_init();
  if (iVar2 != 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> wserv_sqlite_init() fail!\r\n";
    uVar6 = 0x1750;
    goto LAB_005e02b8;
  }
  iVar2 = uac_wservice_recover_rdentry();
  if (iVar2 != 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> uac_wservice_recover_rdentry() fail!\r\n";
    uVar6 = 0x1755;
    goto LAB_005e02b8;
  }
  FUN_004084d0("wservice",3,_uac_wserv_jcs_get);
  FUN_004084d0("wservice",0,_uac_wserv_jcs_add);
  FUN_004084d0("wservice",1,_uac_wserv_jcs_del);
  FUN_004084d0("wservice",2,_uac_wserv_jcs_set);
  FUN_004084d0("wserv_global",2,_uac_wserv_jcs_global_set);
  FUN_004084d0("wservice_ip",0,_uac_wserv_ip_jcs_add);
  FUN_004084d0("wservice_ip",1,_uac_wserv_ip_jcs_del);
  FUN_004084d0("wservice_ip",2,_uac_wserv_ip_jcs_set);
  iVar2 = uac_wservice_pkt_init();
  if (iVar2 != 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> uac_wservice_pkt_init() fail!\r\n";
    uVar6 = 0x1760;
    goto LAB_005e02b8;
  }
  local_40f = 0;
  local_2f8 = local_40e;
  local_314[0] = '\0';
  local_314[1] = '\0';
  local_314[2] = '\0';
  local_314[3] = '\0';
  local_40e[0] = 1;
  local_408[0] = 1;
  local_30c = 0;
  local_40a = 6;
  local_2ec = "igmp_drop_unknown";
  local_40c = 0x3c;
  local_2f4 = 0;
  local_410 = 10;
  local_2e8 = 0;
  local_2e0 = 0;
  local_2d4 = &local_40f;
  local_304 = &onoff_map;
  local_310 = "igmp_snooping_enable";
  local_2c8 = "igmp_2g_rate";
  local_300 = 10;
  local_2b0 = local_408;
  local_308 = 1;
  local_2fc = 1;
  local_2fa = 1;
  local_2f0 = 1;
  local_2e4 = 1;
  local_2dc = 10;
  local_2d8 = 1;
  local_2d6 = 1;
  local_2cc = 2;
  local_2c0 = 1;
  local_2b8 = 10;
  local_2b4 = 1;
  local_2d0 = 0;
  local_2c4 = 0;
  local_2bc = 0;
  local_2b2 = 2;
  local_28e = 2;
  local_2a8 = 3;
  local_26a = 2;
  local_268 = &local_40c;
  local_29c = 1;
  local_2a4 = "igmp_5g_rate";
  local_28c = &local_40a;
  local_260 = 5;
  local_290 = 1;
  local_284 = 4;
  local_25c = "igmp_max_resp_time";
  local_278 = 1;
  local_26c = 1;
  local_280 = "igmp_query_interval";
  local_254 = 1;
  local_248 = 1;
  local_246 = 1;
  local_244 = &local_410;
  local_2ac = 0;
  local_2a0 = 0;
  local_298 = 0;
  local_294 = 10;
  local_288 = 0;
  local_27c = 0;
  local_274 = 0;
  local_270 = 10;
  local_264 = 0;
  local_258 = 0;
  local_250 = 0;
  local_24c = 10;
  local_240 = 0;
  iVar2 = FUN_00408120("apmng_wserv","igmp_settings",local_314,6);
  if (iVar2 != 0) {
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d uci req parse failed.\n","uac_wservice_global_config_restore",
             0x171c);
    }
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> uac_wservice_global_config_restore() fail!\r\n";
    uVar6 = 0x1766;
    goto LAB_005e02b8;
  }
  g_wserv_igmp_entry = local_40e[0];
  DAT_0074fe59 = local_40f;
  DAT_0074fe5a = local_408[0];
  DAT_0074fe5c = local_40a;
  DAT_0074fe5e = local_40c;
  DAT_0074fe60 = local_410;
  if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> ignp_snp_enable = %d,igmp_drop_unknown=  %d, igmp_2g_rate = %d, igmp_5g_rate = %d, igmp_query_interval = %d, igmp_max_resp_time = %d\r\n"
           ,"uac_wservice_global_config_restore",0x1729,(uint)g_wserv_igmp_entry,(uint)DAT_0074fe59,
           (uint)DAT_0074fe5a,(uint)DAT_0074fe5c,(uint)DAT_0074fe5e,(uint)DAT_0074fe60);
  }
  rdmngr_set_multi_rate((undefined1)DAT_0074fe5a,(undefined1)DAT_0074fe5c);
  memset(auStack_360,0,0x4c);
  local_354 = "wservice";
  local_350 = 0x6e;
  local_34c = _uac_wserv_ap_connect_cb;
  local_348 = _uac_wserv_ap_disconnect_cb;
  local_344 = _uac_wserv_ap_firm_cb;
  local_340 = _uac_wserv_ap_del_cb;
  local_334 = _uac_wserv_ap_inherit;
  local_330 = _uac_wserv_ap_copy;
  local_32c = _uac_wserv_checksum_update_cb;
  local_328 = _uac_wserv_ap_cap_change_cb;
  local_31c = _uac_wserv_ap_model_update_cb;
  iVar2 = apmngr_callback_register(auStack_360);
  if (iVar2 != 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> apmngr_callback_register() fail!\r\n";
    uVar6 = 0x1779;
    goto LAB_005e02b8;
  }
  local_3f8 = 0;
  local_400 = 0x50000000;
  local_404 = "wservice";
  local_3fc = _uac_wserv_ap_enter_run;
  iVar2 = multi_link_reg(&local_404);
  if (iVar2 == -1) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> multi_link_reg() fail!\r\n";
    uVar6 = 0x1786;
    goto LAB_005e02b8;
  }
  local_3cc = "wservice";
  local_3c8 = _uac_wserv_rd_enable;
  local_3c4 = _uac_wserv_rd_disable;
  local_3bc = _uac_wserv_rd_change;
  local_3b0 = _uac_wserv_rd_rrm_is_end;
  local_3a4 = 200;
  iVar2 = rdmngr_callback_register(auStack_3d8);
  if (iVar2 == -1) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> rdmngr_callback_register() fail!\r\n";
    uVar6 = 0x1793;
    goto LAB_005e02b8;
  }
  DAT_007598e4 = FUN_00407f00("wserv_packet_mutex",1);
  if (DAT_007598e4 == 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> Create database mutex failed.\r\n";
    uVar6 = 0x17a0;
    goto LAB_005e02b8;
  }
  uVar6 = apmngr_db_get_ap_max();
  DAT_007598e8 = FUN_004082a0(uVar6,0xc,0x17a3);
  iVar2 = 0;
  if (DAT_007598e8 == 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
    uVar6 = 0x17a6;
    goto LAB_005e02b8;
  }
  for (; iVar3 = apmngr_db_get_ap_max(), iVar7 = DAT_007598e8, iVar2 < iVar3; iVar2 = iVar2 + 1) {
    iVar3 = iVar2 * 0xc;
    uVar6 = rdmngr_profile_get_max_rd_per_ap();
    uVar6 = FUN_004082a0(uVar6,4,0x17ab);
    *(undefined4 *)(iVar7 + iVar3 + 8) = uVar6;
    *(undefined1 *)(DAT_007598e8 + iVar3) = 0xff;
    *(undefined1 *)(DAT_007598e8 + iVar3 + 1) = 0xff;
    if (*(int *)(DAT_007598e8 + iVar3 + 8) == 0) {
      if (g_wserv_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
      uVar6 = 0x17b0;
      goto LAB_005e02b8;
    }
    for (uVar8 = 0; uVar4 = rdmngr_profile_get_max_rd_per_ap(), uVar8 < uVar4; uVar8 = uVar8 + 1) {
      iVar7 = *(int *)(DAT_007598e8 + iVar3 + 8);
      uVar6 = rdmngr_profile_get_max_wlan_per_rd();
      uVar6 = FUN_004082a0(uVar6,1,0x17b5);
      *(undefined4 *)(iVar7 + uVar8 * 4) = uVar6;
      if (*(int *)(*(int *)(DAT_007598e8 + iVar3 + 8) + uVar8 * 4) == 0) {
        if (g_wserv_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
        uVar6 = 0x17b8;
        goto LAB_005e02b8;
      }
    }
  }
  apmngr_support_capacity_register(0xd);
  apmngr_support_capacity_register(0x11);
  apmngr_support_capacity_register(0x20);
  apmngr_support_capacity_register(0x3f);
  apmngr_support_sub_capacity_register(0x5f,1);
  if ((local_30 != 0) || (iVar2 = FUN_004081a0(), iVar2 == 0)) {
LAB_005e0a84:
    if (local_2c != 0) {
LAB_005e0b64:
      uac_wservice_help_reg();
      return 0;
    }
    local_3f4 = 0;
    local_3f0[0] = 0;
    local_3f0[1] = 0;
    local_3f0[2] = 0;
    local_3f0[3] = 0;
    local_3f0[4] = 0;
    local_3dc = 0;
    memset(acStack_3a0,0,0x40);
    memcpy(acStack_3a0,"239.255.255.250",0x10);
    FUN_0051a7a8(acStack_3a0,local_3f0);
    uVar1 = (undefined2)local_3dc;
    local_3dc = CONCAT13(0,CONCAT12(1,uVar1));
    local_3f4 = wserv_db_ip_add(&local_3f4);
    if (local_3f4 == 0xffffffff) {
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar5 = "<wserv>[error]%s(): %d  -> wserv_db_ip_add() fail.\r\n";
        uVar6 = 0x16b5;
LAB_005e0bbc:
        printf(pcVar5,"_uac_wserv_add_default_white_list",uVar6);
      }
    }
    else {
      iVar2 = wserv_sqlite_notify(5,&local_3f4,0x1c);
      if (iVar2 == 0) goto LAB_005e0b64;
      uVar6 = wserv_sqlite_notify(5,&local_3f4,0x1c);
      printf("excute result = %d\n",uVar6);
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar5 = "<wserv>[error]%s(): %d  -> _wserv_sqlite_do_insert_ip() fail!\r\n";
        uVar6 = 0x16bc;
        goto LAB_005e0bbc;
      }
    }
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "<wserv>[error]%s(): %d  -> wserv add default white list failed.\r\n";
    uVar6 = 0x17d1;
    goto LAB_005e02b8;
  }
  memset(auStack_23c,0,0x205);
  local_3f4 = 0;
  local_3f0[0] = local_3f0[0] & 0xffff;
  memset(acStack_3a0,0,0x20);
  memset(local_314,0,0x40);
  iVar2 = FUN_00407f70(local_314,0x40);
  if (iVar2 != 0) {
    snprintf(local_314,0x40,"TP-LINK");
  }
  iVar2 = FUN_005135a8(&local_3f4);
  if (iVar2 == 0) {
    sprintf(acStack_3a0,"%02X%02X%02X%02X%02X%02X",local_3f4 >> 0x18,local_3f4 >> 0x10 & 0xff,
            local_3f4 >> 8 & 0xff,local_3f4 & 0xff,local_3f0[0] >> 0x18,local_3f0[0] >> 0x10 & 0xff)
    ;
    if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> mac: %s\r\n","_uac_wserv_add_default_entry",0x166c,
             acStack_3a0);
    }
    local_121 = 1;
    local_110 = 1;
    local_d2 = 0;
    local_da = 0;
    local_d6 = 1;
    local_45 = 1;
    uStack_119 = 0;
    local_11d = 1;
    local_40 = DAT_0074fe5a;
    local_3e = DAT_0074fe5c;
    local_39 = 1;
    local_3c = DAT_0074fe5e;
    local_38 = 0;
    local_3a = DAT_0074fe60;
    local_41 = DAT_0074fe59;
    local_118 = 0x7f01;
    local_114 = 0;
    local_42 = g_wserv_igmp_entry;
    snprintf(acStack_10c,0x32,"%s_%s",local_314,auStack_398);
    iVar2 = wserv_db_entry_add(auStack_23c);
    if (iVar2 == -1) {
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar5 = "<wserv>[error]%s(): %d  -> wserv_db_entry_add() fail.\r\n";
        uVar6 = 0x168d;
        goto LAB_005e0dec;
      }
    }
    else {
      iVar2 = wserv_sqlite_notify(4,auStack_23c,0x205);
      if (iVar2 == 0) {
        local_118 = local_118 & 0xff0000ff | 0x7f0000;
        snprintf(acStack_10c,0x32,"%s_5G_%s",local_314,auStack_398);
        iVar2 = wserv_db_entry_add(auStack_23c);
        if (iVar2 == -1) {
          if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar5 = "<wserv>[error]%s(): %d  -> wserv_db_entry_add() fail.\r\n";
            uVar6 = 0x169d;
            goto LAB_005e0dec;
          }
        }
        else {
          iVar2 = wserv_sqlite_notify(4,auStack_23c,0x205);
          if (iVar2 == 0) goto LAB_005e0a84;
          if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar5 = "<wserv>[error]%s(): %d  -> wserv_sqlite_notify() fail!\r\n";
            uVar6 = 0x16a3;
            goto LAB_005e0dec;
          }
        }
      }
      else if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar5 = "<wserv>[error]%s(): %d  -> wserv_sqlite_notify() fail!\r\n";
        uVar6 = 0x1693;
        goto LAB_005e0dec;
      }
    }
  }
  else if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    pcVar5 = "<wserv>[error]%s(): %d  -> fail to get dev mac.\r\n";
    uVar6 = 0x1668;
LAB_005e0dec:
    printf(pcVar5,"_uac_wserv_add_default_entry",uVar6);
  }
  if (g_wserv_error == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  pcVar5 = "<wserv>[error]%s(): %d  -> wserv add default entry failed.\r\n";
  uVar6 = 0x17c8;
LAB_005e02b8:
  printf(pcVar5,"uac_wservice_init",uVar6);
  return 0xffffffff;
}

