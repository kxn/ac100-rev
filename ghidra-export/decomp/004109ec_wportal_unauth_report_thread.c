// func wportal_unauth_report_thread @ 004109ec size=300

void wportal_unauth_report_thread(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  FUN_0051ad88(&local_30);
  do {
    FUN_004082d0(g_wportal_unauth_mutex,0xffffffff);
    while( true ) {
      iVar1 = FUN_004081b0(&g_wportal_unauth_msg_list);
      if (iVar1 != 0) break;
      FUN_004086c0(g_wportal_unauth_cond,g_wportal_unauth_mutex,0xffffffff);
    }
    iVar1 = FUN_00407fe0(&g_wportal_unauth_msg_list);
    FUN_004082c0(&local_30,&g_wportal_unauth_msg_list);
    if (iVar1 <= wportal_unauth_event_count) {
      wportal_unauth_event_count = wportal_unauth_event_count - iVar1;
    }
    FUN_00407f30(g_wportal_unauth_mutex);
    if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d read to handle unauth event count:%d.\n",
             "wportal_unauth_report_thread",0x3123,iVar1);
    }
    while (iVar1 = FUN_004081b0(&local_30), iVar1 != 0) {
      FUN_00408500(iVar1);
      trigger_auth_session_timeout_event(iVar1);
      FUN_00407df0(iVar1);
    }
  } while( true );
}

