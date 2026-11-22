// func unregister_notify_ap_begin_report_flag_mask @ 0049dcb0 size=1

undefined4 unregister_notify_ap_begin_report_flag_mask(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 2) {
    notify_ap_begin_report_flag_mask = ~(1 << (param_1 & 0x1f)) & notify_ap_begin_report_flag_mask;
    uVar1 = 0;
  }
  return uVar1;
}

