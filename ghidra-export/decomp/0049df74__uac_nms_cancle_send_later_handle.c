// func _uac_nms_cancle_send_later_handle @ 0049df74 size=244

void _uac_nms_cancle_send_later_handle(uint param_1)

{
  bool bVar1;
  undefined4 extraout_v1;
  
  if (param_1 < 3) {
    bVar1 = false;
    FUN_004082d0((&uac_nms_send_ap_mutex)[param_1],0xffffffff);
    if (((&had_trigger_send_laster)[param_1] == 1) && (is_cawap_buf_high == 0)) {
      bVar1 = true;
      FUN_00407e70();
      (&had_trigger_send_laster)[param_1] = 0;
      (&last_try_cancle_send_laster_time)[param_1] = extraout_v1;
    }
    FUN_00407f30((&uac_nms_send_ap_mutex)[param_1]);
    if (bVar1) {
      uac_nms_notify_handle(param_1,0,0);
      return;
    }
  }
  return;
}

