// func cloud_mngt_ap_sample_time_change_cb @ 00497b80 size=96

undefined4 cloud_mngt_ap_sample_time_change_cb(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (((param_1 < 4) && (uVar1 = 0, ap_report_switch != 0)) &&
     (param_1 != 0 || client_report_switch != 0)) {
    cloud_mngt_notify_report(param_1 + 0x10);
  }
  return uVar1;
}

