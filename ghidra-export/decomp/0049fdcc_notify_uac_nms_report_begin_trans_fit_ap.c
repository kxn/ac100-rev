// func notify_uac_nms_report_begin_trans_fit_ap @ 0049fdcc size=84

void notify_uac_nms_report_begin_trans_fit_ap(void)

{
  clean_uac_nms_event_report(1,0);
  clean_uac_nms_params_report(1,0);
  clean_uac_nms_dev_wstat_report(1,0);
  g_uac_nms_report_switch = 1;
  need_to_notify_ap_begin_report_by_flag_mask(1,0,0,4);
  return;
}

