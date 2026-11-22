// func register_notify_ap_begin_report_flag_mask @ 0049dc80 size=48

undefined4 register_notify_ap_begin_report_flag_mask(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 2) {
    notify_ap_begin_report_flag_mask = 1 << (param_1 & 0x1f) | notify_ap_begin_report_flag_mask;
    uVar1 = 0;
  }
  return uVar1;
}

