// func apupd_db_init @ 00651e98 size=2728

undefined4 apupd_db_init(void)

{
  int iVar1;
  void *pvVar2;
  char *__format;
  undefined4 uVar3;
  
  apupd_db_mutex = FUN_00407f00("apupd_db_mutex",0);
  if (apupd_db_mutex == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00652454;
    __format = "[APUPD_ERROR]%32s() %05d: create mutex failed.\r\n";
    uVar3 = 0x19c9;
  }
  else {
    apupd_db_cond = FUN_00407d80("apupd_db_cond");
    if (apupd_db_cond == 0) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00652454;
      __format = "[APUPD_ERROR]%32s() %05d: create cond failed.\r\n";
      uVar3 = 0x19d1;
    }
    else {
      apupd_msg_mutex = FUN_00407f00("apupd_msg_mutex",0);
      if (apupd_msg_mutex == 0) {
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00652454;
        __format = "[APUPD_ERROR]%32s() %05d: create mutex failed.\r\n";
        uVar3 = 0x19d8;
      }
      else {
        apupd_msg_cond = FUN_00407d80("apupd_msg_cond");
        if (apupd_msg_cond == 0) {
          if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00652454;
          __format = "[APUPD_ERROR]%32s() %05d: create cond failed.\r\n";
          uVar3 = 0x19df;
        }
        else {
          iVar1 = FUN_0051eb48("ac_apupd","max_update_model",&APUPD_UPDATING_MODLE_NUM_MAX);
          if (iVar1 == -1) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
              APUPD_UPDATING_MODLE_NUM_MAX = 100;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: get profile[ac_apupd->max_update_model] failed.\r\n"
                     ,"apupd_db_init",0x19e5);
              APUPD_UPDATING_MODLE_NUM_MAX = 100;
            }
          }
          iVar1 = FUN_0051eb48("ac_apupd","max_update_wtp",&APUPD_UPDATING_WTP_NUM_MAX);
          if (iVar1 == -1) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
              APUPD_UPDATING_WTP_NUM_MAX = 1000;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: get profile[ac_apupd->max_update_wtp] failed.\r\n",
                     "apupd_db_init",0x19eb);
              APUPD_UPDATING_WTP_NUM_MAX = 1000;
            }
          }
          iVar1 = FUN_0051eb48("ac_apupd","max_import_software",&APUPD_IMPORT_SOFTWARE_NUM_MAX);
          if (iVar1 == -1) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
              APUPD_IMPORT_SOFTWARE_NUM_MAX = 0x14;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: get profile[ac_apupd->max_import_software] failed.\r\n"
                     ,"apupd_db_init",0x19f1);
              APUPD_IMPORT_SOFTWARE_NUM_MAX = 0x14;
            }
          }
          iVar1 = FUN_0051eb48("ac_apupd","max_get_version_num",&APUPD_GET_VERSION_NUM_MAX);
          if (iVar1 == -1) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
              APUPD_GET_VERSION_NUM_MAX = 1;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: get profile[ac_apupd->max_get_version_num] failed.\r\n"
                     ,"apupd_db_init",0x19f6);
              APUPD_GET_VERSION_NUM_MAX = 1;
            }
          }
          iVar1 = FUN_0051eb48("ac_apupd","max_download_software",&APUPD_DOWNLOAD_SOFTWARE_NUM_MAX);
          if (iVar1 == -1) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
              APUPD_DOWNLOAD_SOFTWARE_NUM_MAX = 1;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: get profile[ac_apupd->max_download_software] failed.\r\n"
                     ,"apupd_db_init",0x19fb);
              APUPD_DOWNLOAD_SOFTWARE_NUM_MAX = 1;
            }
          }
          iVar1 = FUN_0051eb48("ac_apupd","max_all_model_size",&APUPD_ALL_SOFTWARE_SIZE_MAX);
          if (iVar1 == -1) {
            if (g_apupd_debug == 0) {
              APUPD_ALL_SOFTWARE_SIZE_MAX = 0;
            }
            else {
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                APUPD_ALL_SOFTWARE_SIZE_MAX = 0;
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: get profile[ac_apupd->max_all_model_size] failed.\r\n"
                       ,"apupd_db_init",0x1a00);
                APUPD_ALL_SOFTWARE_SIZE_MAX = 0;
              }
            }
          }
          APUPD_WTP_MAX = apmngr_db_get_ap_max();
          apupd_model_hash =
               FUN_004080a0(apupd_model_hash_obj,apupd_model_hash_key,apupd_model_hash_cmp,0x400);
          if (apupd_model_hash == 0) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_00652454;
            __format = "[APUPD_ERROR]%32s() %05d: create model hash failed.\r\n";
            uVar3 = 0x1a0b;
          }
          else {
            apupd_wtp_hash =
                 FUN_004080a0(apupd_wtp_hash_obj,apupd_wtp_hash_key,apupd_wtp_hash_cmp,APUPD_WTP_MAX
                             );
            if (apupd_wtp_hash == 0) {
              if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_00652454;
              __format = "[APUPD_ERROR]%32s() %05d: create wtp hash failed.\r\n";
              uVar3 = 0x1a15;
            }
            else {
              apupd_hwid_hash =
                   FUN_004080a0(apupd_hwid_hash_obj,apupd_hwid_hash_key,apupd_hwid_hash_cmp,0x400);
              if (apupd_hwid_hash == 0) {
                if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                goto LAB_00652454;
                __format = "[APUPD_ERROR]%32s() %05d: create hwid hash failed.\r\n";
                uVar3 = 0x1a20;
              }
              else {
                pvVar2 = (void *)FUN_00408450(0xc,0x1a24);
                apupd_model_list = pvVar2;
                if (pvVar2 == (void *)0x0) {
                  if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                  goto LAB_00652454;
                  __format = "[APUPD_ERROR]%32s() %05d: create model list failed.\r\n";
                  uVar3 = 0x1a27;
                }
                else {
                  memset(pvVar2,0,0xc);
                  FUN_0051ad88(pvVar2);
                  pvVar2 = (void *)FUN_00408450(0xc,0x1a2e);
                  apupd_model_list_for_ui = pvVar2;
                  if (pvVar2 == (void *)0x0) {
                    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                    goto LAB_00652454;
                    __format = "[APUPD_ERROR]%32s() %05d: create model list failed.\r\n";
                    uVar3 = 0x1a31;
                  }
                  else {
                    memset(pvVar2,0,0xc);
                    FUN_0051ad88(pvVar2);
                    FUN_0051ad88(&g_apupd_timer_list);
                    apupd_update_model_hash =
                         FUN_004080a0(apupd_update_model_hash_obj,apupd_update_model_hash_key,
                                      apupd_update_model_hash_cmp,0x400);
                    if (apupd_update_model_hash == 0) {
                      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                      goto LAB_00652454;
                      __format = "[APUPD_ERROR]%32s() %05d: create update model hash failed.\r\n";
                      uVar3 = 0x1a40;
                    }
                    else {
                      apupd_update_wtp_hash =
                           FUN_004080a0(apupd_update_wtp_hash_obj,apupd_update_wtp_hash_key,
                                        apupd_update_wtp_hash_cmp,APUPD_WTP_MAX);
                      if (apupd_update_wtp_hash == 0) {
                        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                        goto LAB_00652454;
                        __format = "[APUPD_ERROR]%32s() %05d: create update model hash failed.\r\n";
                        uVar3 = 0x1a4b;
                      }
                      else {
                        pvVar2 = (void *)FUN_00408450(0xc,0x1a50);
                        apupd_update_model_list = pvVar2;
                        if (pvVar2 == (void *)0x0) {
                          if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                          goto LAB_00652454;
                          __format = "[APUPD_ERROR]%32s() %05d: create model list failed.\r\n";
                          uVar3 = 0x1a53;
                        }
                        else {
                          memset(pvVar2,0,0xc);
                          FUN_0051ad88(pvVar2);
                          pvVar2 = (void *)FUN_00408450(0xc,0x1a59);
                          apupd_wtp_list = pvVar2;
                          if (pvVar2 == (void *)0x0) {
                            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                            goto LAB_00652454;
                            __format = "[APUPD_ERROR]%32s() %05d: create model list failed.\r\n";
                            uVar3 = 0x1a5c;
                          }
                          else {
                            memset(pvVar2,0,0xc);
                            FUN_0051ad88(pvVar2);
                            apupd_config = (undefined4 *)FUN_00408450(4,0x1a62);
                            if (apupd_config == (undefined4 *)0x0) {
                              if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)
                                 ) goto LAB_00652454;
                              __format = "[APUPD_ERROR]%32s() %05d: malloc config failed.\r\n";
                              uVar3 = 0x1a65;
                            }
                            else {
                              *apupd_config = 1;
                              FUN_0051ad88(&apupd_report_upgrade_info);
                              apupd_updating_model_num = 0;
                              apupd_updating_wtp_num = 0;
                              apupd_import_software_num = 0;
                              iVar1 = FUN_004084e0(&apupd_thread,&DAT_00713190,apupd_thread_callback
                                                   ,0);
                              if (iVar1 == -1) {
                                if ((g_apupd_error == 0) ||
                                   (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00652454;
                                __format = "[APUPD_ERROR]%32s() %05d: create thread failed.\r\n";
                                uVar3 = 0x1a7a;
                              }
                              else {
                                iVar1 = FUN_004084e0(&apupd_timer_thread,"apupd_timer",
                                                     apupd_timer_thread_callback,0);
                                if (iVar1 == 0) {
                                  return 0;
                                }
                                if ((g_apupd_error == 0) ||
                                   (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00652454;
                                __format = 
                                "[APUPD_ERROR]%32s() %05d: Failed to create apupd timer thread\r\n";
                                uVar3 = 0x1a80;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf(__format,"apupd_db_init",uVar3);
LAB_00652454:
  if (apupd_db_mutex != 0) {
    FUN_00408360();
    apupd_db_mutex = 0;
  }
  if (apupd_db_cond != 0) {
    FUN_00408220();
    apupd_db_cond = 0;
  }
  if (apupd_msg_mutex != 0) {
    FUN_00408360();
    apupd_msg_mutex = 0;
  }
  if (apupd_msg_cond != 0) {
    FUN_00408220();
    apupd_msg_cond = 0;
  }
  if (apupd_model_hash != 0) {
    FUN_00408310();
    apupd_model_hash = 0;
  }
  if (apupd_wtp_hash != 0) {
    FUN_00408310();
    apupd_wtp_hash = 0;
  }
  if (apupd_model_list != (void *)0x0) {
    FUN_00407df0();
    apupd_model_list = (void *)0x0;
  }
  if (apupd_update_model_hash != 0) {
    FUN_00407df0();
    apupd_update_model_hash = 0;
  }
  if (apupd_update_wtp_hash != 0) {
    FUN_00407df0();
    apupd_update_model_hash = 0;
  }
  if (apupd_update_model_list != (void *)0x0) {
    FUN_00407df0();
    apupd_update_model_list = (void *)0x0;
  }
  if (apupd_wtp_list != (void *)0x0) {
    FUN_00407df0();
    apupd_wtp_list = (void *)0x0;
  }
  if (apupd_config != (undefined4 *)0x0) {
    FUN_00407df0();
    apupd_config = (undefined4 *)0x0;
  }
  apupd_updating_wtp_num = 0;
  apupd_updating_model_num = 0;
  return 0xffffffff;
}

