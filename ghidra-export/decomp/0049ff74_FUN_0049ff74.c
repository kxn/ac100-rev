// func FUN_0049ff74 @ 0049ff74 size=96

undefined4 FUN_0049ff74(undefined4 param_1)

{
  int iVar1;
  
  if (((notify_ap_begin_report_enable_mask & notify_ap_begin_report_flag_mask) != 0) &&
     (iVar1 = check_nms_report_switch(), iVar1 == 0)) {
    uac_nms_notify_handle(4,param_1,1);
  }
  return 0;
}

