// func uac_nms_cw_recv_queue_high_threshold_handle @ 0049e1ac size=1

void uac_nms_cw_recv_queue_high_threshold_handle(void)

{
  _uac_nms_trigger_send_later_handle(0);
  is_cawap_buf_high = 1;
  return;
}

