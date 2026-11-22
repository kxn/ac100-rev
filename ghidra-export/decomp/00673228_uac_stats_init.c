// func uac_stats_init @ 00673228 size=1072

undefined4 uac_stats_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  char *local_60;
  undefined4 local_5c;
  code *local_58;
  char *local_54;
  code *local_50;
  code *local_4c;
  code *local_48;
  code *local_40;
  code *local_3c;
  undefined4 local_38;
  undefined4 local_2c;
  
  iVar1 = stats_db_init();
  if (iVar1 == 0) {
    iVar1 = stats_pkt_init();
    if (iVar1 == 0) {
      memset(&local_60,0,0x2c);
      local_60 = (char *)0x73746174;
      local_40 = (code *)0xa;
      local_5c = CONCAT13('s',local_5c._1_3_);
      local_3c = _stats_sta_deassoc_cb;
      iVar1 = wsta_db_event_register(1,&local_60);
      if (iVar1 == 0) {
        local_3c = _stats_sta_assoc_cb;
        iVar1 = wsta_db_event_register(0,&local_60);
        if (iVar1 == 0) {
          memset(&local_60,0,0x4c);
          local_54 = "stats";
          local_50 = (code *)0x64;
          local_4c = _stats_ap_join_cb;
          local_48 = _stats_ap_disconnect_cb;
          local_40 = _stats_ap_del_cb;
          iVar1 = apmngr_callback_register(&local_60);
          if (iVar1 == 0) {
            local_54 = (char *)0x0;
            local_60 = "stats";
            local_5c = 0xa000000;
            local_58 = _stats_ap_online_cb;
            iVar1 = multi_link_reg(&local_60);
            if (iVar1 == -1) {
              if (stats_err_switch != '\0') {
                printf("[STATISTICS_ERROR]%s()/%d register callback to multi link failed.\n",
                       "_stats_multilink_callback_init",0x113);
              }
              if (stats_err_switch == '\0') goto LAB_006732c4;
              __format = "[STATISTICS_ERROR]%s()/%d _stats_multilink_callback_init() fail!\n";
              uVar2 = 0x1cc;
            }
            else {
              memset(&local_60,0,0x38);
              local_54 = "stats";
              local_50 = _stats_rd_enable_cb;
              local_4c = _stats_rd_disable_cb;
              local_2c = 0xdc;
              iVar1 = rdmngr_callback_register(&local_60);
              if (iVar1 == -1) {
                if (stats_err_switch != '\0') {
                  printf("[STATISTICS_ERROR]%s()/%d rdmngr_callback_register() fail!\n",
                         "_stats_rdmngr_callback_init",0x141);
                }
                if (stats_err_switch == '\0') goto LAB_006732c4;
                __format = "[STATISTICS_ERROR]%s()/%d _stats_rdmngr_callback_init() fail!\n";
                uVar2 = 0x1d2;
              }
              else {
                memset(&local_60,0,0x2c);
                strncpy((char *)&local_60,"stats_wlan_disable",0x1f);
                local_40 = (code *)0xa;
                local_3c = _stats_wlan_disable;
                iVar1 = wserv_db_event_register(3,&local_60);
                if (iVar1 == 0) {
                  strncpy((char *)&local_60,"stats_wlan_enable",0x1f);
                  local_40 = (code *)0xa;
                  local_38 = 0;
                  local_3c = _stats_wlan_enable;
                  iVar1 = wserv_db_event_register(2,&local_60);
                  if (iVar1 == 0) {
                    apmngr_support_capacity_register(0x18);
                    stats_help_reg();
                    return 0;
                  }
                  if (stats_err_switch != '\0') {
                    uVar2 = 0x179;
                    goto LAB_00673588;
                  }
                }
                else if (stats_err_switch != '\0') {
                  uVar2 = 0x16f;
LAB_00673588:
                  printf("[STATISTICS_ERROR]%s()/%d wserv_db_event_register() fail!\n",
                         "_stats_wserv_callback_init",uVar2);
                }
                if (stats_err_switch == '\0') goto LAB_006732c4;
                __format = "[STATISTICS_ERROR]%s()/%d _stats_wserv_callback_init() fail!\n";
                uVar2 = 0x1d8;
              }
            }
          }
          else {
            if (stats_err_switch != '\0') {
              printf("[STATISTICS_ERROR]%s()/%d apmngr_callback_register() fail!\n",
                     "_stats_apmngr_callback_init",200);
            }
            if (stats_err_switch == '\0') goto LAB_006732c4;
            __format = "[STATISTICS_ERROR]%s()/%d _stats_apmngr_callback_init() fail!\n";
            uVar2 = 0x1c6;
          }
          goto LAB_00673490;
        }
        if (stats_err_switch != '\0') {
          uVar2 = 0x71;
          goto LAB_00673344;
        }
      }
      else if (stats_err_switch != '\0') {
        uVar2 = 0x6a;
LAB_00673344:
        printf("[STATISTICS_ERROR]%s()/%d register disassociation event callback to stats  block failed.\n"
               ,"_stats_wstation_callback_init",uVar2);
      }
      if (stats_err_switch == '\0') goto LAB_006732c4;
      __format = "[STATISTICS_ERROR]%s()/%d stats_wstation_callback_init() fail!\n";
      uVar2 = 0x1c0;
    }
    else {
      if (stats_err_switch == '\0') goto LAB_006732c4;
      __format = "[STATISTICS_ERROR]%s()/%d stats_pkt_init() fail!\n";
      uVar2 = 0x1ba;
    }
  }
  else {
    if (stats_err_switch == '\0') goto LAB_006732c4;
    __format = "[STATISTICS_ERROR]%s()/%d stats_db_init() fail!\n";
    uVar2 = 0x1b4;
  }
LAB_00673490:
  printf(__format,"uac_stats_init",uVar2);
LAB_006732c4:
  stats_pkt_uninit();
  stats_db_uninit();
  return 0xffffffff;
}

