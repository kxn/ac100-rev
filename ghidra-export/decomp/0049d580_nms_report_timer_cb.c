// func nms_report_timer_cb @ 0049d580 size=160

void nms_report_timer_cb(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((param_1 != (uint *)0x0) && (uVar2 = *param_1, uVar2 < 3)) {
    if ((code *)(&PTR_uac_nms_event_timer_handle_0069cb90)[uVar2] != (code *)0x0) {
      (*(code *)(&PTR_uac_nms_event_timer_handle_0069cb90)[uVar2])();
    }
    uVar1 = FUN_00408340(5,0,nms_report_timer_cb,param_1,0,"nms_report_timer_cb",0x292);
    (&g_uac_nms_report_timer)[uVar2] = uVar1;
  }
  return;
}

