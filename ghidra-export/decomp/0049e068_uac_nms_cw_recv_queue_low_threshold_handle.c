// func uac_nms_cw_recv_queue_low_threshold_handle @ 0049e068 size=1

void uac_nms_cw_recv_queue_low_threshold_handle(void)

{
  _uac_nms_cancle_send_later_handle(0);
  is_cawap_buf_high = 0;
  return;
}

