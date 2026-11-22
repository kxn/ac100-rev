// func uac_nms_dev_wstat_report_fini @ 004a0d0c size=116

void uac_nms_dev_wstat_report_fini(void)

{
  uac_nms_dev_wstat_report_pkt_uninit();
  if (uac_nms_dev_wstat_report_mutex != 0) {
    FUN_00408360();
    uac_nms_dev_wstat_report_mutex = 0;
  }
  if (uac_nms_dev_wstats_msg_mutex != 0) {
    FUN_00408360();
    uac_nms_dev_wstats_msg_mutex = 0;
  }
  if (uac_nms_dev_wstats_msg_cond != 0) {
    FUN_00408220();
    uac_nms_dev_wstats_msg_cond = 0;
  }
  return;
}

