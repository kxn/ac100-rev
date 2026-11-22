// func apupd_init @ 00648ff8 size=1992

undefined4 apupd_init(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *local_a8;
  undefined4 local_a4;
  code *local_a0;
  code *local_9c;
  undefined4 local_98;
  code *local_94;
  code *local_90;
  code *local_80;
  undefined4 local_28;
  code *local_24;
  
  iVar1 = FUN_0051eb48("apmng_upgrade","large_firmware_threshold",&g_large_firmware_threshold);
  if (iVar1 == -1) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get profile[apmng_upgrade->large_firmware_threshold] fail.\r\n"
             ,"_apupd_read_global_info",0xef);
    }
    g_large_firmware_threshold = dft_large_firmware_threshold;
  }
  g_large_firmware_threshold = g_large_firmware_threshold << 0x14;
  iVar1 = FUN_0051eb48("apmng_upgrade","sub_file_size",&g_large_firmware_sub_file_size);
  if (iVar1 == -1) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get profile[apmng_upgrade->sub_file_size ] fail.\r\n",
             "_apupd_read_global_info",0xf8);
    }
    g_large_firmware_sub_file_size = dft_large_firmware_sub_file_size;
  }
  g_large_firmware_sub_file_size = g_large_firmware_sub_file_size << 0x14;
  iVar1 = apupd_db_init();
  if (iVar1 == -1) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0064938c;
    pcVar2 = "[APUPD_ERROR]%32s() %05d: init apupd db failed.\r\n";
    uVar3 = 0x12a5;
  }
  else {
    FUN_0051ad88(&apupd_check_callback_list);
    iVar1 = apdb_traversal(apupd_apdb_callback_apdb_add,0);
    if (iVar1 == -1) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0064938c;
      pcVar2 = "[APUPD_ERROR]%32s() %05d: init apupd model by apdb failed.\r\n";
      uVar3 = 0x12ac;
    }
    else {
      FUN_004084d0("apupd_config",2,apupd_jcs_callack_apupd_config_set);
      FUN_004084d0("apupd_model",3,apupd_jcs_callback_apupd_models_get);
      FUN_004084d0("apupd_model",0,apupd_jcs_callback_apupd_models_add);
      FUN_004084d0("apupd_model",1,apupd_jcs_callback_apupd_models_del);
      FUN_004084d0("apupd_model",2,apupd_jcs_callback_apupd_models_set);
      FUN_004084d0("apupd_image_check",3,apupd_jcs_callback_apupd_image_check);
      FUN_004084d0("apupd_log",3,apupd_jcs_callback_apupd_log_get);
      FUN_004084d0("apupd_log",1,apupd_jcs_callback_apupd_log_del);
      FUN_004084d0("apupd_status",3,apupd_jcs_callback_apupd_status_get);
      FUN_004084d0("apupd_wtp",3,apupd_jcs_callback_apupd_wtp_get);
      FUN_004084d0("apupd_wtp",2,apupd_jcs_callback_apupd_set_for_ap);
      FUN_004084d0("ap_firmed_model",3,apupd_jcs_callback_apupd_model_list_get);
      FUN_004084d0("apupd_upgrade_status",3,apupd_jcs_callback_ap_upgrade_status);
      FUN_004084d0("apupd_group_delete",2,apupd_jcs_callback_ap_group_delete);
      FUN_004084d0("apupd_check_allow_update",3,apupd_jcs_callback_check_allow_update);
      FUN_004084d0("apupd_large_image_status",3,apupd_jcs_large_image_status_get);
      FUN_004084d0("apupd_large_image_status",2,apupd_jcs_large_image_status_set);
      memset(&local_a8,0,0x4c);
      local_9c = (code *)&DAT_00713190;
      local_98 = 0x78;
      local_90 = apupd_apmngr_callback_apupd_wtp_del;
      local_80 = apupd_apmngr_callback_apupd_group_join;
      iVar1 = apmngr_callback_register(&local_a8);
      if (iVar1 == -1) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: register callback to apmngr failed.\r\n",
                 "apupd_apmngr_callback_init",0xf72);
        }
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0064938c;
        pcVar2 = "[APUPD_ERROR]%32s() %05d: register callbakc to apmngr failed.\r\n";
        uVar3 = 0x12bc;
      }
      else {
        local_a8 = &DAT_00713190;
        local_a4 = 0x78000000;
        local_a0 = apupd_multilink_callback_apupd_wtp_add;
        local_9c = apupd_multilink_callback_apupd_wtp_del;
        iVar1 = multi_link_reg(&local_a8);
        if (iVar1 == -1) {
          if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APUPD_ERROR]%32s() %05d: register callback to multi link failed.\r\n",
                   "apupd_multilink_callback_init",0x1248);
          }
          if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0064938c;
          pcVar2 = "[APUPD_ERROR]%32s() %05d: register callback to multilink failed.\r\n";
          uVar3 = 0x12c3;
        }
        else {
          iVar1 = serv_msg_mngr_register(8,100,apupd_capwap_callback_config_update_response_listen);
          if (iVar1 == -1) {
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar2 = 
              "[APUPD_ERROR]%32s() %05d: register callback to listen config update response.\r\n";
              uVar3 = 0x10c8;
LAB_00649540:
              printf(pcVar2,"apupd_capwap_callback_init",uVar3);
            }
          }
          else {
            iVar1 = serv_msg_mngr_register(0x10,1,apupd_capwap_callback_image_response_listen);
            if (iVar1 == -1) {
              if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar2 = 
                "[APUPD_ERROR]%32s() %05d: register callback to listen image response failed.\r\n";
                uVar3 = 0x10cf;
                goto LAB_00649540;
              }
            }
            else {
              iVar1 = serv_msg_mngr_register(3,100,apupd_capwap_callback_join_request_listen);
              if (iVar1 == -1) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar2 = 
                  "[APUPD_ERROR]%32s() %05d: register callback to listen join request failed.\r\n";
                  uVar3 = 0x10d6;
                  goto LAB_00649540;
                }
              }
              else {
                iVar1 = serv_msg_mngr_register(0xf,1,apupd_capwap_callback_image_request_listen);
                if (iVar1 != -1) {
                  local_a8 = (undefined4 *)0x0;
                  local_a4 = 0;
                  local_a0 = (code *)0x0;
                  local_98 = 0;
                  local_9c = (code *)&DAT_00713190;
                  local_94 = apupd_apdb_callback_apdb_update_one;
                  iVar1 = apdb_callback_register(&local_a8);
                  if (iVar1 == -1) {
                    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                      printf("[APUPD_ERROR]%32s() %05d: register callback to apdb failed.\r\n",
                             "apupd_apdb_callback_init",0x11cf);
                    }
                    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                    goto LAB_0064938c;
                    pcVar2 = "[APUPD_ERROR]%32s() %05d: register callbakc to apdb failed.\r\n";
                    uVar3 = 0x12d1;
                  }
                  else {
                    memset(&local_a8,0,0x8c);
                    local_a8 = (undefined4 *)0x61707570;
                    local_a4 = CONCAT13(100,local_a4._1_3_);
                    local_28 = 10;
                    local_24 = apupd_systime_callback_models_timer_restart;
                    iVar1 = systime_event_register(&local_a8);
                    if (iVar1 != -1) {
                      udbg_help_register(&DAT_00713190,"apupd_debug_help()");
                      return 0;
                    }
                    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                      printf("[APUPD_ERROR]%32s() %05d: register callback to systime failed.\r\n",
                             "apupd_systime_callback_init",0x1279);
                    }
                    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                    goto LAB_0064938c;
                    pcVar2 = "[APUPD_ERROR]%32s() %05d: register callbakc to systime failed.\r\n";
                    uVar3 = 0x12d8;
                  }
                  goto LAB_00649420;
                }
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar2 = 
                  "[APUPD_ERROR]%32s() %05d: register callback to listen image request.\r\n";
                  uVar3 = 0x10dd;
                  goto LAB_00649540;
                }
              }
            }
          }
          if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0064938c;
          pcVar2 = "[APUPD_ERROR]%32s() %05d: register callbakc to capwap failed.\r\n";
          uVar3 = 0x12ca;
        }
      }
    }
  }
LAB_00649420:
  printf(pcVar2,"apupd_init",uVar3);
LAB_0064938c:
  iVar1 = apupd_destroy();
  if (((iVar1 == -1) && (g_apupd_error != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: destroy apupd failed.\r\n","apupd_init",0x12e2);
  }
  return 0xffffffff;
}

