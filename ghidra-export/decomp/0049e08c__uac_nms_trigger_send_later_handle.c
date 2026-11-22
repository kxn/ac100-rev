// func _uac_nms_trigger_send_later_handle @ 0049e08c size=288

void _uac_nms_trigger_send_later_handle(uint param_1)

{
  bool bVar1;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  uint uVar2;
  undefined8 uVar3;
  
  if (2 < param_1) {
    return;
  }
  FUN_004082d0((&uac_nms_send_ap_mutex)[param_1],0xffffffff);
  if ((&had_trigger_send_laster)[param_1] == 0) {
    (&had_trigger_send_laster)[param_1] = 1;
    FUN_00407e70();
    (&last_trigger_send_laster_time)[param_1] = extraout_v1_00;
  }
  else {
    uVar3 = FUN_00407e70();
    uVar2 = (uint)uVar3 - (&last_trigger_send_laster_time)[param_1];
    if (((int)((ulonglong)uVar3 >> 0x20) - ((int)(&last_trigger_send_laster_time)[param_1] >> 0x1f)
         == (uint)((uint)uVar3 < uVar2)) && (bVar1 = false, uVar2 < 0x78)) goto LAB_0049e154;
    FUN_00407e70();
    (&last_trigger_send_laster_time)[param_1] = extraout_v1;
  }
  bVar1 = true;
LAB_0049e154:
  FUN_00407f30((&uac_nms_send_ap_mutex)[param_1]);
  if (!bVar1) {
    return;
  }
  uac_nms_notify_handle(param_1,0,1);
  return;
}

