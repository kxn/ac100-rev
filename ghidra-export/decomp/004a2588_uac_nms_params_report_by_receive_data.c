// func uac_nms_params_report_by_receive_data @ 004a2588 size=68

undefined4 uac_nms_params_report_by_receive_data(void)

{
  FUN_004082d0(uac_nms_params_msg_mutex,0xffffffff);
  FUN_004084b0(uac_nms_params_msg_cond);
  FUN_00407f30(uac_nms_params_msg_mutex);
  return 0;
}

