// func uac_nms_event_report_init @ 004a1dec size=560

undefined4 uac_nms_event_report_init(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 local_68;
  char acStack_64 [72];
  
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d .............uac_nms_event_report_init............\n",
           "uac_nms_event_report_init",0x148);
  }
  uac_nms_event_report_mutex = FUN_00407f00("uac_nms_event_report_mutex",0);
  if (uac_nms_event_report_mutex == 0) {
    if (cloud_mngt_err_switch == '\0') goto LAB_004a1f84;
    __format = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt msg mutex failed.\n";
    pcVar5 = "uac_nms_event_report_init";
    uVar3 = 0x14d;
  }
  else {
    uac_nms_event_msg_mutex = FUN_00407f00("uac_nms_event_msg_report_mutex",0);
    if (uac_nms_event_msg_mutex == 0) {
      if (cloud_mngt_err_switch == '\0') goto LAB_004a1f84;
      __format = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt report msg mutex failed.\n";
      pcVar5 = "uac_nms_event_report_init";
      uVar3 = 0x154;
    }
    else {
      uac_nms_event_msg_cond = FUN_00407d80("uac_nms_event_msg_report_cond");
      if (uac_nms_event_msg_cond != 0) {
        g_total_fit_nms_events_cnt = 0;
        iVar4 = 0;
        FUN_0051ad88(&g_uac_nms_event_report_list);
        local_68 = 0;
        memset(acStack_64,0,0x40);
        iVar1 = get_report_thread_size();
        if (init_uac_nms_events_report_handle == 0) {
          pcVar5 = "init_uac_nms_event_report_thread";
          for (; iVar4 < iVar1; iVar4 = iVar4 + 1) {
            memset(acStack_64,0,0x40);
            snprintf(acStack_64,0x40,"%s%d","init_uac_nms_event_report_thread",iVar4);
            iVar2 = FUN_004084e0(&local_68,acStack_64,_uac_nms_event_report_handle,0);
            if (iVar2 != 0) {
              if (cloud_mngt_err_switch == '\0') goto LAB_004a1f84;
              uVar3 = 0xbb;
              __format = "[CLOUD_MNGT_ERROR]%s()/%d Failed to create cloud mngt msg thread\n";
              goto LAB_004a1fa0;
            }
          }
          init_uac_nms_events_report_handle = 1;
        }
        iVar1 = uac_nms_event_report_pkt_init();
        if (iVar1 == 0) {
          return 0;
        }
        goto LAB_004a1f84;
      }
      if (cloud_mngt_err_switch == '\0') goto LAB_004a1f84;
      __format = "[CLOUD_MNGT_ERROR]%s()/%d Create cloud mngt report msg cond failed.\n";
      pcVar5 = "uac_nms_event_report_init";
      uVar3 = 0x15b;
    }
  }
LAB_004a1fa0:
  printf(__format,pcVar5,uVar3);
LAB_004a1f84:
  uac_nms_event_report_fini();
  return 0xffffffff;
}

