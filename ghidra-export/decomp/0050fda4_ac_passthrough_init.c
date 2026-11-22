// func ac_passthrough_init @ 0050fda4 size=724

undefined4 ac_passthrough_init(void)

{
  int iVar1;
  char *__format;
  char *pcVar2;
  undefined4 uVar3;
  char *local_a8;
  undefined4 local_a4;
  code *local_a0;
  char *local_9c;
  undefined4 local_98;
  code *local_88;
  undefined4 local_28;
  code *local_24;
  
  if (ac_passthrough_debug_switch != '\0') {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d .............ac_passthrough_init............\n",
           "ac_passthrough_init",0x972);
  }
  iVar1 = init_sub_device_report_handle();
  if ((iVar1 != 0) || (iVar1 = ac_passthrough_reponse_init(), iVar1 != 0)) goto LAB_0050ff08;
  local_9c = (char *)0x0;
  local_a4 = 0x82000000;
  local_a8 = "ac_passthrough";
  local_a0 = ac_passthrough_multilink_switch_to_master;
  iVar1 = multi_link_reg(&local_a8);
  if (iVar1 == -1) {
    if (ac_passthrough_err_switch == '\0') goto LAB_0050ff08;
    __format = "[AC_PASSTHROUGH_ERROR]%s()/%d register callback to multi link failed.\n";
    pcVar2 = "ac_passthrough_multilink_callback_init";
    uVar3 = 0x8c2;
  }
  else {
    memset(&local_a8,0,0x8c);
    strncpy((char *)&local_a8,"ac_passthrough",0x7f);
    local_28 = 100;
    local_24 = ac_passthrough_systime_callback;
    iVar1 = systime_event_register(&local_a8);
    if ((iVar1 != 0) || (iVar1 = apmngr_support_capacity_register(0x31), iVar1 != 0))
    goto LAB_0050ff08;
    ac_passthrough_msg_report_mutex = FUN_00407f00("ac_passthrough_send_mutex",0);
    if (ac_passthrough_msg_report_mutex == 0) {
      if (ac_passthrough_err_switch == '\0') goto LAB_0050ff08;
      __format = "[AC_PASSTHROUGH_ERROR]%s()/%d Create ac_passthrough msg mutex failed.\n";
      pcVar2 = "ac_passthrough_init";
      uVar3 = 0x991;
    }
    else {
      memset(&local_a8,0,0x4c);
      local_9c = "ac_passthrough";
      local_98 = 0x78;
      local_88 = ac_passthrough_callback_wtp_delete;
      iVar1 = apmngr_callback_register(&local_a8);
      if (iVar1 != -1) {
        if (ac_passthrough_debug_switch != '\0') {
          printf("[AC_PASSTHROUGH_DEBUG]%s()/%d .............ac_passthrough_jcs_init............\n",
                 "ac_passthrough_jcs_init",0x82e);
        }
        iVar1 = FUN_004084d0("ac_passthrough",2,_ac_passthrough_jcs_set);
        if ((((iVar1 == 0) &&
             (iVar1 = FUN_004084d0("ac_passthrough",3,_ac_passthrough_jcs_get), iVar1 == 0)) &&
            (iVar1 = FUN_004084d0("tdcp_passthrough",2,_tdcp_passthrough_jcs_set), iVar1 == 0)) &&
           ((iVar1 = FUN_004084d0("send_tdcp_test",2,_tdcp_send_jcs_set), iVar1 == 0 &&
            (iVar1 = tdcp_init(), iVar1 == 0)))) {
          FUN_0051ad88(&g_ac_passthrough_waitting_result_list);
          pthread_mutex_init((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock,
                             (pthread_mutexattr_t *)0x0);
          scan_waitting_result_list_timerid =
               FUN_00408340(0x1e,0,scan_passthrough_waitting_result_list,0,0,"ac_passthrough_init",
                            0x9a8);
          return 0;
        }
        goto LAB_0050ff08;
      }
      if (ac_passthrough_err_switch == '\0') goto LAB_0050ff08;
      __format = "[AC_PASSTHROUGH_ERROR]%s()/%d register callback to apmngr failed.\n";
      pcVar2 = "apmngr_ac_passthrough_callback_init";
      uVar3 = 0x6a7;
    }
  }
  printf(__format,pcVar2,uVar3);
LAB_0050ff08:
  ac_passthrough_fini();
  return 0xffffffff;
}

