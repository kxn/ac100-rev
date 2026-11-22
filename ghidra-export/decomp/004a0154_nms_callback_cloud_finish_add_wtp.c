// func nms_callback_cloud_finish_add_wtp @ 004a0154 size=324

undefined4 nms_callback_cloud_finish_add_wtp(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x3c) == 0)) {
    uVar3 = 0xffffffff;
    if (cloud_mngt_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d AP not firmed or is sensor.\n";
    uVar2 = 600;
  }
  else {
    if ((((*(int *)(param_1 + 0xc) != 0) && (g_uac_nms_report_switch == 1)) &&
        (g_nms_support_switch == 1)) &&
       ((iVar1 = cloud_mngt_ap_is_nms_spupport(*(undefined2 *)(param_1 + 0x10),0), iVar1 == 1 &&
        (*(int *)(param_1 + 0x14) != 7)))) {
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d %s %d ap_id:%d\r\n\n","nms_callback_cloud_finish_add_wtp",
               0x266,"nms_callback_cloud_finish_add_wtp",0x266,(uint)*(ushort *)(param_1 + 0x10));
      }
      uVar3 = FUN_0049ff74(param_1 + 0x48);
      return uVar3;
    }
    uVar3 = 0;
    if (cloud_mngt_debug_switch == '\0') {
      return 0;
    }
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d AP not add to cloud no need passthroug report.\n";
    uVar2 = 0x263;
  }
  printf(__format,"nms_callback_cloud_finish_add_wtp",uVar2);
  return uVar3;
}

