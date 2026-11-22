// func nms_callback_wtp_add @ 004a0298 size=380

undefined4 nms_callback_wtp_add(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_2e8 [12];
  int local_2dc;
  int local_2d4;
  int local_2ac;
  undefined1 auStack_2a0 [381];
  char local_123;
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar2 = 0x1cb;
  }
  else if ((local_2ac == 0) || (local_2d4 == 7)) {
    if (cloud_mngt_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d AP not firmed or is sensor.\n";
    uVar2 = 0x1d1;
  }
  else {
    iVar1 = set_cloud_mngt_ap_nms_spupport(param_1,0);
    if (iVar1 != 0) {
      return 0;
    }
    if ((((local_123 != '\0') && (local_2dc != 0)) && (g_uac_nms_report_switch == 1)) &&
       (g_nms_support_switch == 1)) {
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d %s %d ap_id:%d\r\n\n","nms_callback_wtp_add",0x1e0,
               "nms_callback_wtp_add",0x1e0,param_1);
      }
      uVar2 = FUN_0049ff74(auStack_2a0);
      return uVar2;
    }
    if (cloud_mngt_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d AP not add to cloud no need passthroug report.\n";
    uVar2 = 0x1dd;
  }
  printf(__format,"nms_callback_wtp_add",uVar2);
  return 0xffffffff;
}

