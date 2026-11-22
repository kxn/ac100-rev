// func check_nms_get_passthrough_report @ 004a0414 size=188

undefined4 check_nms_get_passthrough_report(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e8 [20];
  int local_2d4;
  
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
  uVar2 = 0xffffffff;
  if ((((iVar1 != -1) && (local_2d4 != 7)) && (g_uac_nms_report_switch == 1)) &&
     (g_nms_support_switch == 1)) {
    iVar1 = cloud_mngt_ap_is_nms_spupport(param_1,0);
    uVar2 = 0;
    if ((iVar1 != 1) && (uVar2 = 0xffffffff, g_fit_ap_ignore_nms_ap_check == 1)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

