// func uac_nms_event_report_fini @ 004a1d78 size=116

void uac_nms_event_report_fini(void)

{
  uac_nms_event_report_pkt_uninit();
  if (uac_nms_event_report_mutex != 0) {
    FUN_00408360();
    uac_nms_event_report_mutex = 0;
  }
  if (uac_nms_event_msg_mutex != 0) {
    FUN_00408360();
    uac_nms_event_msg_mutex = 0;
  }
  if (uac_nms_event_msg_cond != 0) {
    FUN_00408220();
    uac_nms_event_msg_cond = 0;
  }
  return;
}

