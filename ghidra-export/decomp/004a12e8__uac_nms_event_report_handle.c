// func _uac_nms_event_report_handle @ 004a12e8 size=364

void _uac_nms_event_report_handle(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = get_report_ulr(0);
  uVar2 = get_long_link_id(uVar2);
LAB_004a134c:
  FUN_004082d0(uac_nms_event_msg_mutex,0xffffffff);
  FUN_004086c0(uac_nms_event_msg_cond,uac_nms_event_msg_mutex,0xffffffff);
  iVar3 = do_uac_nms_events_report_handle;
  do_uac_nms_events_report_handle = 0;
  FUN_00407f30(uac_nms_event_msg_mutex);
  do {
    if (iVar3 == 1) {
      bVar1 = false;
      FUN_004082d0(uac_nms_event_report_mutex,0xffffffff);
      if ((0 < g_total_fit_nms_events_cnt) && (bVar1 = true, cloud_mngt_debug_switch != '\0')) {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d check_uac_nms_event_list_reach_report_size\n",
               "check_uac_nms_event_list_size",0x8b);
      }
      FUN_00407f30(uac_nms_event_report_mutex);
      if (!bVar1) goto LAB_004a1388;
    }
    else {
LAB_004a1388:
      FUN_004082d0(uac_nms_event_report_mutex,0xffffffff);
      iVar3 = g_total_fit_nms_events_cnt;
      FUN_00407f30(uac_nms_event_report_mutex);
      if (iVar3 < 0x40000) goto LAB_004a134c;
    }
    iVar3 = check_nms_report_switch();
    if (iVar3 != 0) goto LAB_004a134c;
    iVar3 = 0;
    uac_nms_fit_ap_info_report_handle
              (cloud_mngt_report_event_stats_head_add,get_uac_nms_event_report,uac_nms_report,0,
               update_event_report_time,",\"devEventList\":[",0,uVar2);
  } while( true );
}

