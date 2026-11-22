// func uac_rrm_init @ 004af92c size=1928

undefined4 uac_rrm_init(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 local_750;
  undefined4 local_74c;
  undefined4 local_748;
  undefined4 local_744;
  undefined4 local_740;
  undefined *local_73c;
  undefined4 local_738;
  code *local_734;
  undefined4 local_730;
  undefined1 auStack_72c [52];
  undefined1 auStack_6f8 [52];
  char acStack_6c4 [128];
  undefined4 local_644;
  code *local_640;
  undefined4 local_638;
  char *local_634;
  undefined4 local_630;
  undefined4 local_62c;
  undefined4 *local_628;
  undefined4 local_624;
  undefined2 local_620;
  undefined2 local_61e;
  undefined4 *local_61c;
  undefined4 local_618;
  undefined4 local_614;
  char *local_610;
  undefined4 local_60c;
  undefined4 local_608;
  undefined4 *local_604;
  undefined4 local_600;
  undefined2 local_5fc;
  undefined2 local_5fa;
  undefined4 *local_5f8;
  undefined4 local_5f4;
  undefined4 local_5f0;
  char *local_5ec;
  undefined4 local_5e8;
  undefined4 local_5e4;
  undefined4 *local_5e0;
  undefined4 local_5dc;
  undefined2 local_5d8;
  undefined2 local_5d6;
  undefined4 *local_5d4;
  undefined4 local_5d0;
  undefined4 local_5cc;
  char *local_5c8;
  undefined4 local_5c4;
  undefined4 local_5c0;
  undefined4 *local_5bc;
  undefined4 local_5b8;
  undefined2 local_5b4;
  undefined2 local_5b2;
  undefined4 *local_5b0;
  undefined4 local_5ac;
  undefined4 local_5a8;
  char *local_5a4;
  undefined4 local_5a0;
  undefined4 local_59c;
  undefined4 local_598;
  undefined4 local_594;
  undefined2 local_590;
  undefined2 local_58e;
  undefined1 *local_58c;
  undefined4 local_588;
  undefined4 local_584;
  char *local_580;
  undefined4 local_57c;
  undefined4 local_578;
  undefined4 local_574;
  undefined4 local_570;
  undefined2 local_56c;
  undefined2 local_56a;
  undefined1 *local_568;
  undefined4 local_564;
  undefined4 local_560;
  char *local_55c;
  undefined4 local_558;
  undefined4 local_554;
  undefined4 local_550;
  undefined4 local_54c;
  undefined2 local_548;
  undefined2 local_546;
  undefined4 local_544;
  undefined4 local_540;
  undefined4 local_53c;
  char *local_538;
  undefined4 local_534;
  undefined4 local_530;
  undefined4 local_52c;
  undefined4 local_528;
  undefined2 local_524;
  undefined2 local_522;
  undefined1 *local_520;
  undefined4 local_51c;
  undefined4 local_518;
  char *local_514;
  undefined4 local_510;
  undefined4 local_50c;
  undefined4 local_508;
  undefined4 local_504;
  undefined2 local_500;
  undefined2 local_4fe;
  undefined4 *local_4fc;
  undefined4 local_4f8;
  undefined4 local_4f4;
  char *local_4f0;
  undefined4 local_4ec;
  undefined4 local_4e8;
  undefined4 local_4e4;
  undefined4 local_4e0;
  undefined2 local_4dc;
  undefined2 local_4da;
  undefined4 *local_4d8;
  undefined4 local_4d4;
  undefined4 local_4d0;
  char *local_4cc;
  undefined4 local_4c8;
  undefined4 local_4c4;
  undefined4 *local_4c0;
  undefined4 local_4bc;
  undefined2 local_4b8;
  undefined2 local_4b6;
  undefined4 *local_4b4;
  undefined4 local_4b0;
  undefined4 local_4ac;
  char *local_4a8;
  undefined4 local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  undefined2 local_494;
  undefined2 local_492;
  undefined1 *local_490;
  undefined4 local_48c;
  undefined4 local_488;
  char *local_484;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined4 local_474;
  undefined2 local_470;
  undefined2 local_46e;
  undefined1 *local_46c;
  undefined4 local_468;
  undefined4 local_464;
  char *local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined2 local_44c;
  undefined2 local_44a;
  undefined1 *local_448;
  undefined4 local_444;
  undefined4 local_440;
  char *local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined2 local_428;
  undefined2 local_426;
  undefined4 *local_424;
  undefined4 local_420;
  undefined1 auStack_41c [1028];
  
  memset(acStack_6c4,0,0x8c);
  local_748 = 0;
  local_744 = 0;
  local_740 = 0;
  local_73c = (undefined *)0x0;
  local_738 = 0;
  local_734 = (code *)0x0;
  local_730 = 0;
  rrm_signal = FUN_004085e0("ac_rrm",0);
  if (rrm_signal == 0) {
    if (rrm_err_switch == '\0') goto LAB_004afa18;
    pcVar2 = "[RRM_ERROR]%s()/%d uac_sem_create() fail!\n";
    uVar3 = 0xb50;
  }
  else {
    iVar1 = rrm_db_init();
    if (iVar1 == 0) {
      local_74c = 0;
      memset(auStack_6f8,0,0x32);
      memset(auStack_72c,0,0x32);
      local_750 = 0;
      memset(auStack_41c,0,0x400);
      iVar1 = FUN_005135a8(&ctl);
      if (iVar1 == 0) {
        local_638 = 0;
        local_630 = 0;
        local_618 = 0;
        local_60c = 0;
        local_61c = &g_chnl_enable;
        local_634 = "chnl_enable";
        local_5f4 = 0;
        local_5e8 = 0;
        local_610 = "pwr_enable";
        local_5d0 = 0;
        local_5c4 = 0;
        local_5f8 = &g_pwr_enable;
        local_62c = 1;
        local_5f0 = 2;
        local_624 = 10;
        local_620 = 1;
        local_61e = 4;
        local_5ec = "bw_2g";
        local_628 = &onoff_map;
        local_614 = 1;
        local_608 = 1;
        local_5d4 = &g_bw_2g;
        local_604 = &onoff_map;
        local_600 = 10;
        local_5fc = 1;
        local_5fa = 4;
        local_5e4 = 1;
        local_5e0 = &bw_map;
        local_5dc = 10;
        local_5d8 = 1;
        local_5d6 = 4;
        local_5cc = 3;
        local_5c8 = "bw_5g";
        local_5c0 = 1;
        local_5bc = &bw_map;
        local_5b2 = 4;
        local_5a0 = 3;
        local_57c = 3;
        local_5a4 = "chnl_2g_set";
        local_558 = 3;
        local_5b0 = &g_bw_5g;
        local_5b8 = 10;
        local_58c = &DAT_00767bd1;
        local_5b4 = 1;
        local_584 = 5;
        local_5a8 = 4;
        local_59c = 1;
        local_594 = 10;
        local_580 = "chnl_5g1_set";
        local_590 = 4;
        local_58e = 1;
        local_578 = 1;
        local_568 = &DAT_00767bd6;
        local_570 = 10;
        local_560 = 6;
        local_56c = 4;
        local_56a = 1;
        local_554 = 1;
        local_55c = "chnl_5g2_set";
        local_54c = 10;
        local_548 = 4;
        local_5ac = 0;
        local_598 = 0;
        local_588 = 0;
        local_574 = 0;
        local_564 = 0;
        local_550 = 0;
        local_546 = 1;
        local_544 = 0x767bdb;
        local_530 = 1;
        local_53c = 7;
        local_528 = 10;
        local_524 = 1;
        local_522 = 1;
        local_538 = "pwr_threshold";
        local_50c = 1;
        local_520 = &high_threshold;
        local_504 = 10;
        local_518 = 8;
        local_500 = 1;
        local_4fe = 4;
        local_4e8 = 1;
        local_514 = "pwr_max_pwr";
        local_4e0 = 10;
        local_4dc = 1;
        local_4da = 4;
        local_4fc = &rrm_pwr_max_power;
        local_4d0 = 10;
        local_4f4 = 9;
        local_540 = 0;
        local_534 = 0;
        local_52c = 0;
        local_4f0 = "pwr_min_pwr";
        local_51c = 0;
        local_510 = 0;
        local_508 = 0;
        local_4d8 = &rrm_pwr_min_power;
        local_4f8 = 0;
        local_4ec = 0;
        local_4e4 = 0;
        local_4d4 = 0;
        local_4cc = "autorrm_enable";
        local_4b4 = &local_74c;
        local_4c4 = 1;
        local_4c0 = &onoff_map;
        local_4ac = 0xb;
        local_4bc = 10;
        local_4b8 = 1;
        local_4b6 = 4;
        local_4a8 = "autorrm_date";
        local_4a4 = 1;
        local_488 = 0xc;
        local_4a0 = 1;
        local_494 = 1;
        local_480 = 1;
        local_484 = "autorrm_time";
        local_47c = 1;
        local_464 = 0xd;
        local_470 = 1;
        local_45c = 1;
        local_458 = 1;
        local_460 = "group_id_str";
        local_4c8 = 0;
        local_4b0 = 0;
        local_49c = 0;
        local_498 = 0;
        local_492 = 0x32;
        local_48c = 0;
        local_478 = 0;
        local_474 = 0;
        local_46e = 0x32;
        local_468 = 0;
        local_454 = 0;
        local_450 = 0;
        local_44a = 0x400;
        local_426 = 4;
        local_440 = 0xe;
        local_44c = 1;
        local_434 = 1;
        local_428 = 1;
        local_424 = &local_750;
        local_43c = "freq_enable";
        local_444 = 0;
        local_438 = 0;
        local_430 = 0;
        local_42c = 10;
        local_420 = 0;
        local_490 = auStack_6f8;
        local_46c = auStack_72c;
        local_448 = auStack_41c;
        iVar1 = FUN_00408120("apmng_rrm","settings",&local_638,0xf);
        if (iVar1 == 0) {
          rrm_channel_list = (undefined1)local_588;
          DAT_00767bd5 = (undefined1)local_564;
          DAT_00767bd8._2_1_ = (undefined1)local_540;
          low_threshold = high_threshold;
          _rrm_group_id_set(auStack_41c);
          _rrm_freq_enable_set(local_750);
          _rrm_group_id_set(auStack_41c);
          _rrm_freq_enable_set(local_750);
          _autorrm_config_set(local_74c,auStack_6f8,auStack_72c);
          iVar1 = serv_msg_mngr_register(9,0x41,_rrm_pkt_wtp_event_listener);
          if (iVar1 == 0) {
            iVar1 = FUN_004084d0("ac_rrm_state",3,_rrm_jcs_rrm_state_get);
            if (((iVar1 != 0) ||
                (iVar1 = FUN_004084d0("ac_rrmpara",2,_rrm_jcs_rrm_para_set), iVar1 != 0)) ||
               (iVar1 = FUN_004084d0("ac_manualrrm",2,_rrm_jcs_manual_rrm_set), iVar1 != 0))
            goto LAB_004afa18;
            FUN_0051ad88(&g_rrm_cb_list);
            local_748 = 0;
            local_738 = 100;
            local_744 = 0;
            local_740 = 0;
            local_730 = 0;
            local_73c = &DAT_006a0f50;
            local_734 = _rrm_apmngr_reboot_check;
            iVar1 = apmngr_check_callback_register(&local_748);
            if (iVar1 == -1) {
              if (rrm_err_switch == '\0') goto LAB_004afa18;
              pcVar2 = "[RRM_ERROR]%s()/%d register callback to apmngr reboot failed.\n";
              uVar3 = 0xb80;
            }
            else {
              memset(acStack_6c4,0,0x8c);
              strncpy(acStack_6c4,"rrm",0x7f);
              local_644 = 0x6e;
              local_640 = _autorrm_systime_callback;
              iVar1 = systime_event_register(acStack_6c4);
              if (iVar1 == 0) {
                iVar1 = uac_rrm_sync_init();
                if (iVar1 == 0) {
                  rrm_db_state_set(0);
                  apmngr_support_capacity_register(0x1b);
                  FUN_004084e0(&rrm_tid,&DAT_006a0f50,_rrm_task,0);
                  rrm_help_reg();
                  return 0;
                }
                if (rrm_err_switch == '\0') goto LAB_004afa18;
                pcVar2 = "[RRM_ERROR]%s()/%d uac_rrm_sync_init failed.\n";
                uVar3 = 0xb8e;
              }
              else {
                if (rrm_err_switch == '\0') goto LAB_004afa18;
                pcVar2 = "[RRM_ERROR]%s()/%d register callback to systime event failed.\n";
                uVar3 = 0xb89;
              }
            }
          }
          else {
            if (rrm_err_switch == '\0') goto LAB_004afa18;
            pcVar2 = "[RRM_ERROR]%s()/%d register wtp event req for rrm module fail.\n";
            uVar3 = 0xb63;
          }
          goto LAB_004affec;
        }
        if (rrm_err_switch != '\0') {
          pcVar2 = "[RRM_ERROR]%s()/%d uci req parse failed.\n";
          uVar3 = 0xa21;
          goto LAB_004afe00;
        }
      }
      else if (rrm_err_switch != '\0') {
        pcVar2 = "[RRM_ERROR]%s()/%d read mac addr failed\n";
        uVar3 = 0xa05;
LAB_004afe00:
        printf(pcVar2,"_rrm_read_global_info",uVar3);
      }
      if (rrm_err_switch == '\0') goto LAB_004afa18;
      pcVar2 = "[RRM_ERROR]%s()/%d _rrm_read_global_info() fail!\n";
      uVar3 = 0xb5c;
    }
    else {
      if (rrm_err_switch == '\0') goto LAB_004afa18;
      pcVar2 = "[RRM_ERROR]%s()/%d rrm_db_init() fail!\n";
      uVar3 = 0xb56;
    }
  }
LAB_004affec:
  printf(pcVar2,"uac_rrm_init",uVar3);
LAB_004afa18:
  uac_rrm_uninit();
  return 0xffffffff;
}

