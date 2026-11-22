// func notify_uac_nms_report_stop_trans_fit_ap @ 0049fe20 size=80

void notify_uac_nms_report_stop_trans_fit_ap(void)

{
  clean_uac_nms_event_report(1,0);
  clean_uac_nms_params_report(1,0);
  clean_uac_nms_dev_wstat_report(1,0);
  g_uac_nms_report_switch = 0;
  need_to_notify_ap_begin_report_by_flag_mask(0,0,0,4);
  return;
}

