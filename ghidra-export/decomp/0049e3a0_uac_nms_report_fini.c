// func uac_nms_report_fini @ 0049e3a0 size=36

void uac_nms_report_fini(void)

{
  uac_nms_event_report_fini();
  uac_nms_params_report_fini();
  uac_nms_dev_wstat_report_fini();
  return;
}

