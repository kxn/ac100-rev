// func uac_nms_report_init @ 0049e3c4 size=1440

undefined4 uac_nms_report_init(void)

{
  int iVar1;
  void *__s;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 local_70;
  undefined *local_6c;
  undefined4 local_68;
  code *local_64;
  undefined *local_60;
  undefined4 local_5c;
  code *local_54;
  code *local_24;
  
  local_70 = 0;
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d .............uac_nms_report_init............\n",
           "uac_nms_report_init",0x42d);
  }
  iVar1 = FUN_0051eb48("ac_capwap","thread_size",&reprot_thread_size);
  if (iVar1 == -1) {
    if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
    pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d read profile failed.\n";
    pcVar3 = "uac_nms_report_init";
    uVar4 = 0x430;
  }
  else {
    iVar1 = apmngr_db_get_ap_max();
    __s = (void *)FUN_00408450(iVar1 << 3,0x434);
    g_cloud_mngt_ap_array = __s;
    if (__s == (void *)0x0) {
      if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
      pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d Malloc entry array failed.\n";
      pcVar3 = "uac_nms_report_init";
      uVar4 = 0x437;
    }
    else {
      iVar1 = apmngr_db_get_ap_max();
      memset(__s,0,iVar1 << 3);
      iVar1 = FUN_0051eb48("apmng_set","support_nms_ap_max",&g_nms_aps_support_cnt);
      if (iVar1 == -1) {
        if (cloud_mngt_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d uci get profile nms aps support.\n";
        uVar4 = 0x43e;
LAB_0049e4b4:
        printf(pcVar2,"uac_nms_report_init",uVar4);
        return 0xffffffff;
      }
      iVar1 = uac_nms_report_get_fit_ap_nms_support();
      if (iVar1 == -1) {
        if (cloud_mngt_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d uci get nms aps support enable error.\n";
        uVar4 = 0x443;
        goto LAB_0049e4b4;
      }
      uac_nms_ap_entry_mutex = FUN_00407f00("uac_nms_ap_entry_mutex",0);
      if (uac_nms_ap_entry_mutex == 0) {
        if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
        pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d Create uac nms msg mutex failed.\n";
        pcVar3 = "uac_nms_report_init";
        uVar4 = 0x44a;
      }
      else {
        iVar1 = FUN_004084d0("uac_nms_report_switch",2,uac_nms_report_jcs_switch_set);
        if ((iVar1 != 0) || (iVar1 = apmngr_support_capacity_register(0x31), iVar1 != 0))
        goto LAB_0049e7ec;
        FUN_0051ad88(&g_uac_nms_msg_report_list);
        uac_nms_msg_report_mutex = FUN_00407f00("uac_nms_msg_report_mutex",0);
        if (uac_nms_msg_report_mutex == 0) {
          if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
          pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d Create uac nms msg mutex failed.\n";
          pcVar3 = "uac_nms_report_init";
          uVar4 = 0x45d;
        }
        else {
          uac_nms_msg_report_cond = FUN_00407d80("uac_nms_msg_report_cond");
          if (uac_nms_msg_report_cond == 0) {
            if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
            pcVar2 = 
            "[CLOUD_MNGT_ERROR]%s()/%d Create uac_nms_msg_report_cond report msg cond failed.\n";
            pcVar3 = "uac_nms_report_init";
            uVar4 = 0x464;
          }
          else {
            iVar1 = init_long_link(reprot_thread_size * 3);
            if (iVar1 == 0) {
              local_60 = (undefined *)0x0;
              local_68 = 0x78000000;
              local_6c = &DAT_0069c2b4;
              local_64 = nms_callback_wtp_add;
              iVar1 = multi_link_reg(&local_6c);
              if (iVar1 == -1) {
                if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
                pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d register callback to multi link failed.\n";
                pcVar3 = "apmngr_nms_callback_init";
                uVar4 = 0x1f2;
              }
              else {
                memset(&local_6c,0,0x4c);
                local_60 = &DAT_0069c2b4;
                local_5c = 0x78;
                local_54 = nms_callback_wtp_leave;
                local_24 = nms_callback_cloud_finish_add_wtp;
                iVar1 = apmngr_callback_register(&local_6c);
                if (iVar1 == -1) {
                  if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
                  pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d register callback to apmngr failed.\n";
                  pcVar3 = "cloud_nms_apmngr_callback_init";
                  uVar4 = 0x27c;
                }
                else {
                  piVar6 = &uac_nms_send_ap_mutex;
                  do {
                    iVar1 = FUN_00407f00("uac_nms_send_ap_mutex",0);
                    *piVar6 = iVar1;
                    if (iVar1 == 0) goto LAB_0049e7ec;
                    piVar6 = piVar6 + 1;
                  } while (piVar6 != &had_trigger_send_laster);
                  puVar7 = &g_uac_nms_report_timer;
                  iVar1 = 0;
                  do {
                    iVar5 = iVar1 * 4;
                    iVar1 = iVar1 + 1;
                    uVar4 = FUN_00408340(5,0,nms_report_timer_cb,&g_uac_nms_report_type + iVar5,0,
                                         "uac_nms_report_src_init",0x2a5);
                    *puVar7 = uVar4;
                    puVar7 = puVar7 + 1;
                  } while (iVar1 != 3);
                  iVar1 = 0;
                  do {
                    *(undefined4 *)((int)&had_trigger_send_laster + iVar1) = 0;
                    *(undefined4 *)((int)&last_trigger_send_laster_time + iVar1) = 0;
                    puVar7 = (undefined4 *)((int)&last_try_cancle_send_laster_time + iVar1);
                    iVar1 = iVar1 + 4;
                    *puVar7 = 0xffffffff;
                  } while (iVar1 != 0x20);
                  iVar1 = uac_nms_event_report_init();
                  if ((((iVar1 != 0) || (iVar1 = uac_nms_params_report_init(), iVar1 != 0)) ||
                      (iVar1 = uac_nms_dev_wstat_report_init(), iVar1 != 0)) ||
                     (iVar1 = cw_ac_recieve_cb_register(uac_nms_recieve_network_conflict_handle),
                     iVar1 != 0)) goto LAB_0049e7ec;
                  iVar1 = FUN_004084e0(&g_uac_nms_msg_report_thread,"UacNmsMsgReportThread",
                                       uac_nms_report_msg_thread,0);
                  if (iVar1 == 0) {
                    iVar1 = FUN_004084e0(&local_70,"UacCheckNmsAptThread",select_nms_aps,0);
                    if (iVar1 == 0) {
                      iVar1 = serv_ent_mngr_register(1,0x79,_uac_nms_report_pkt_enter_run_cb);
                      if (iVar1 == 0) {
                        register_notify_ap_begin_report_flag_mask(0);
                        return 0;
                      }
                      if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
                      pcVar2 = 
                      "[CLOUD_MNGT_ERROR]%s()/%d register callback to listen Enter-Run Event.\n";
                      pcVar3 = "uac_nms_report_init";
                      uVar4 = 0x4a5;
                    }
                    else {
                      if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
                      pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d Failed to create cselect_nms_aps thread\n"
                      ;
                      pcVar3 = "uac_nms_report_init";
                      uVar4 = 0x49f;
                    }
                  }
                  else {
                    if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
                    pcVar2 = 
                    "[CLOUD_MNGT_ERROR]%s()/%d Failed to uac_nms_report_msg_thread msg thread\n";
                    pcVar3 = "uac_nms_report_init";
                    uVar4 = 0x499;
                  }
                }
              }
            }
            else {
              if (cloud_mngt_err_switch == '\0') goto LAB_0049e7ec;
              pcVar2 = "[CLOUD_MNGT_ERROR]%s()/%d Failed to init_long_link\n";
              pcVar3 = "uac_nms_report_init";
              uVar4 = 0x46a;
            }
          }
        }
      }
    }
  }
  printf(pcVar2,pcVar3,uVar4);
LAB_0049e7ec:
  uac_nms_report_fini();
  return 0xffffffff;
}

