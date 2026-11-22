// func need_to_notify_ap_begin_report_by_flag_mask @ 0049fca8 size=292

undefined4
need_to_notify_ap_begin_report_by_flag_mask(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((param_3 < 2) && (param_4 - 4U < 4)) {
    if (param_1 == 1) {
      uVar3 = 0;
      if ((((notify_ap_begin_report_flag_mask >> (param_3 & 0x1f) & 1U) != 0) &&
          (((int)notify_ap_begin_report_enable_mask >> (param_3 & 0x1f) & 1U) == 0)) &&
         (iVar1 = check_nms_report_switch(), iVar1 == 0)) {
        uac_nms_notify_nms_aps_handle(param_4,param_2,1);
        notify_ap_begin_report_enable_mask =
             1 << (param_3 & 0x1f) | notify_ap_begin_report_enable_mask;
      }
    }
    else {
      uVar3 = 0;
      if (((notify_ap_begin_report_flag_mask >> (param_3 & 0x1f) & 1U) != 0) &&
         (uVar2 = 1 << (param_3 & 0x1f), (uVar2 & notify_ap_begin_report_enable_mask) == 1)) {
        uac_nms_notify_handle(param_4,param_2,param_1);
        notify_ap_begin_report_enable_mask = ~uVar2 & notify_ap_begin_report_enable_mask;
      }
    }
  }
  return uVar3;
}

