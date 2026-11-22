// func clean_uac_nms_event_report @ 004a20c8 size=472

undefined4 clean_uac_nms_event_report(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(uac_nms_event_report_mutex,0xffffffff);
  if (g_fit_ap_nms_events_test == 1) {
    printf("going to clean totaol len:%d \r\n",g_total_fit_nms_events_cnt);
  }
  iVar2 = FUN_004081b0(&g_uac_nms_event_report_list);
  do {
    while( true ) {
      iVar1 = iVar2;
      if (iVar1 == 0) {
        FUN_00407f30(uac_nms_event_report_mutex);
        return 0;
      }
      iVar2 = FUN_00408680(iVar1);
      if ((2 < *(byte *)(iVar1 + 0x10)) || (param_1 == 1)) break;
      if (param_2 == 1) {
        if (*(char *)(iVar1 + 0x11) == '\x01') break;
      }
      else if ((param_2 == 0) && (*(char *)(iVar1 + 0x11) == '\x01')) {
        *(undefined1 *)(iVar1 + 0x11) = 0;
      }
    }
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d clean time:%d type:%d len:%d data:%s.\r\n\n",
             "clean_uac_nms_event_report",0x1f9,*(undefined4 *)(iVar1 + 0x14),
             *(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c),
             *(undefined4 *)(iVar1 + 0x20));
    }
    FUN_00408500(iVar1);
    g_total_fit_nms_events_cnt = g_total_fit_nms_events_cnt - *(int *)(iVar1 + 0x1c);
    g_test_events_len = g_test_events_len - *(int *)(iVar1 + 0x1c);
    if (*(int *)(iVar1 + 0x20) != 0) {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 0x20) = 0;
    }
    FUN_00407df0(iVar1);
    g_test_events_remain_count = g_test_events_remain_count + -1;
  } while( true );
}

