// func _uac_nms_params_report_handle @ 004a2958 size=312

void _uac_nms_params_report_handle(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = get_report_ulr(1);
  uVar1 = get_long_link_id(uVar1);
LAB_004a29bc:
  FUN_004082d0(uac_nms_params_msg_mutex,0xffffffff);
  FUN_004086c0(uac_nms_params_msg_cond,uac_nms_params_msg_mutex,0xffffffff);
  iVar2 = do_uac_nms_params_report_handle;
  do_uac_nms_params_report_handle = 0;
  FUN_00407f30(uac_nms_params_msg_mutex);
  do {
    if (iVar2 == 1) {
      FUN_004082d0(uac_nms_params_report_mutex,0xffffffff);
      iVar2 = g_total_fit_nms_params_cnt;
      FUN_00407f30(uac_nms_params_report_mutex);
      if (iVar2 < 1) goto LAB_004a29f8;
    }
    else {
LAB_004a29f8:
      FUN_004082d0(uac_nms_params_report_mutex,0xffffffff);
      iVar2 = g_total_fit_nms_params_cnt;
      FUN_00407f30(uac_nms_params_report_mutex);
      if (iVar2 < 0x40000) goto LAB_004a29bc;
    }
    iVar2 = check_nms_report_switch();
    if (iVar2 != 0) goto LAB_004a29bc;
    iVar2 = 0;
    uac_nms_fit_ap_info_report_handle
              (cloud_mngt_report_event_stats_head_add,get_uac_nms_params_report,uac_nms_report,0,
               update_params_report_time,",\"subDeviceStats\":[",1,uVar1);
  } while( true );
}

