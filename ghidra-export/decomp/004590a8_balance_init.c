// func balance_init @ 004590a8 size=1248

undefined4 balance_init(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *local_88;
  char local_84 [4];
  code *local_80;
  code *local_7c;
  undefined4 local_68;
  code *local_64;
  char local_5c [12];
  char *local_50;
  undefined4 local_4c;
  code *local_44;
  undefined4 local_3c;
  code *local_38;
  
  iVar1 = balance_db_init();
  if (iVar1 == -1) {
    if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00459200;
    pcVar2 = "[BALANCE_ERROR](%32s) %05d: init balance db failed.\r\n";
    uVar3 = 0x4de;
  }
  else {
    iVar1 = FUN_004084d0("ac_balance",2,balance_jcs_callback_balance_set);
    if (iVar1 == -1) {
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BALANCE_ERROR](%32s) %05d: register callback to jcs failed.\r\n",
               "balance_jcs_callback_balance_init",0x26e);
      }
      if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00459200;
      pcVar2 = "[BALANCE_ERROR](%32s) %05d: register callback to jcs failed.\r\n";
      uVar3 = 0x4e5;
    }
    else {
      memset(local_5c,0,0x4c);
      local_4c = 0x78;
      local_50 = "balance";
      local_44 = balance_apmngr_callback_balance_wtp_del;
      iVar1 = apmngr_callback_register(local_5c);
      if (iVar1 == -1) {
        if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[BALANCE_ERROR](%32s) %05d: register callback to apmngr failed.\r\n",
                 "balance_apmngr_callback_balance_init",0x2b9);
        }
        if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00459200;
        pcVar2 = "[BALANCE_ERROR](%32s) %05d: register callback to apmngr failed.\r\n";
        uVar3 = 0x4ec;
      }
      else {
        local_88 = "balance";
        local_84[0] = 'd';
        local_84[1] = '\0';
        local_84[2] = '\0';
        local_84[3] = '\0';
        local_80 = balance_multilink_callback_balance_wtp_add;
        local_7c = balance_multilink_callback_balance_wtp_del;
        iVar1 = multi_link_reg(&local_88);
        if (iVar1 == -1) {
          if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[BALANCE_ERROR](%32s) %05d: register callback to multi link failed.\r\n",
                   "balance_multilink_callback_balance_init",0x4a7);
          }
          if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
          goto LAB_00459200;
          pcVar2 = "[BALANCE_ERROR](%32s) %05d: register callback to multilink failed.\r\n";
          uVar3 = 0x4f3;
        }
        else {
          memset(&local_88,0,0x2c);
          memset(local_5c,0,0x2c);
          local_88 = (char *)0x62616c61;
          local_68 = 10;
          local_3c = 10;
          builtin_strncpy(local_5c,"balance",7);
          local_84[2] = 'e';
          local_84[0] = 'n';
          local_84[1] = 'c';
          local_38 = balance_wsta_callback_balance_sta_check;
          iVar1 = wsta_assoc_check_reg(local_5c);
          if (iVar1 == 0) {
            local_64 = balance_wsta_callback_balance_sta_add;
            iVar1 = wsta_db_event_register(0,&local_88);
            if (iVar1 == 0) {
              local_64 = balance_wsta_callback_balance_sta_del;
              iVar1 = wsta_db_event_register(1,&local_88);
              if (iVar1 == 0) {
                iVar1 = serv_msg_mngr_register(9,1,balance_capwap_callback_wtp_event_request_listen)
                ;
                if (iVar1 == -1) {
                  if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar2 = 
                    "[BALANCE_ERROR](%32s) %05d: register callback to listen wtp event request failed.\r\n"
                    ;
                    uVar3 = 0x433;
                    goto LAB_00459534;
                  }
                }
                else {
                  iVar1 = serv_msg_mngr_register
                                    (5,0x32,balance_capwap_callback_cfg_status_request_listen);
                  if (iVar1 != -1) {
                    wsta_roam_db_roam_strategy_register(balance_roam_strategy_get);
                    wsta_roam_db_roam_strategy_update(0);
                    udbg_help_register("balance","balance_debug_help()");
                    return 0;
                  }
                  if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar2 = 
                    "[BALANCE_ERROR](%32s) %05d: register callback to listen configuration status request failed.\r\n"
                    ;
                    uVar3 = 0x439;
LAB_00459534:
                    printf(pcVar2,"balance_capwap_callback_balance_init",uVar3);
                  }
                }
                if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                goto LAB_00459200;
                pcVar2 = "[BALANCE_ERROR](%32s) %05d: register callback to capwap failed.\r\n";
                uVar3 = 0x501;
                goto LAB_00459318;
              }
              if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar2 = 
                "[BALANCE_ERROR](%32s) %05d: register disassociation evnet callback to wstation  block failed.\r\n"
                ;
                uVar3 = 0x3c6;
                goto LAB_00459338;
              }
            }
            else if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar2 = 
              "[BALANCE_ERROR](%32s) %05d: register association evnet callback to wstation  block failed.\r\n"
              ;
              uVar3 = 0x3be;
              goto LAB_00459338;
            }
          }
          else if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar2 = 
            "[BALANCE_ERROR](%32s) %05d: register check callback to wstation  block failed \r\n";
            uVar3 = 0x3b6;
LAB_00459338:
            printf(pcVar2,"balance_wstation_callback_balance_init",uVar3);
          }
          if ((g_balance_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
          goto LAB_00459200;
          pcVar2 = "[BALANCE_ERROR](%32s) %05d: register callback to wsta failed.\r\n";
          uVar3 = 0x4fa;
        }
      }
    }
  }
LAB_00459318:
  printf(pcVar2,"balance_init",uVar3);
LAB_00459200:
  balance_db_destroy();
  return 0xffffffff;
}

