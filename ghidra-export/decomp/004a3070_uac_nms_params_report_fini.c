// func uac_nms_params_report_fini @ 004a3070 size=116

void uac_nms_params_report_fini(void)

{
  uac_nms_params_report_pkt_uninit();
  if (uac_nms_params_report_mutex != 0) {
    FUN_00408360();
    uac_nms_params_report_mutex = 0;
  }
  if (uac_nms_params_msg_mutex != 0) {
    FUN_00408360();
    uac_nms_params_msg_mutex = 0;
  }
  if (uac_nms_params_msg_cond != 0) {
    FUN_00408220();
    uac_nms_params_msg_cond = 0;
  }
  return;
}

