// func uac_nms_wstat_timer_handle @ 004a0fd4 size=172

void uac_nms_wstat_timer_handle(void)

{
  int iVar1;
  int extraout_v1;
  
  iVar1 = check_nms_report_switch();
  if ((iVar1 == 0) && (FUN_00407e70(), 0x78 < extraout_v1 - g_last_report_fit_ap_dev_wstat_time)) {
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d uac_nms_wstat_timer_handle.\n","uac_nms_wstat_timer_handle",
             0x17f);
    }
    FUN_004082d0(uac_nms_dev_wstats_msg_mutex,0xffffffff);
    do_uac_nms_wstats_report_handle = 1;
    FUN_004084b0(uac_nms_dev_wstats_msg_cond);
    FUN_00407f30(uac_nms_dev_wstats_msg_mutex);
    return;
  }
  return;
}

