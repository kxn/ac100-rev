// func uac_nms_event_report_test_handle @ 004a22a0 size=1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 uac_nms_event_report_test_handle(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_v1;
  int iVar3;
  undefined4 uStack_68;
  char acStack_64 [68];
  
  uStack_68 = 0;
  memset(acStack_64,0,0x40);
  iVar1 = get_report_thread_size();
  if ((-1 < param_1) && (_g_test_ap_id = param_1, iRam00767ae4 != 1)) {
    for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
      FUN_00407e70();
      snprintf(acStack_64,0x40,"event_report_handle_test%d",extraout_v1);
      iVar2 = FUN_004084e0(&uStack_68,acStack_64,test_report_nms_event,&g_test_ap_id);
      if (iVar2 != 0) {
        if (cloud_mngt_err_switch != '\0') {
          printf("[CLOUD_MNGT_ERROR]%s()/%d Failed to create cloud mngt msg thread\n",
                 "uac_nms_event_report_test_handle",0x2b2);
          return 0xffffffff;
        }
        return 0xffffffff;
      }
      iRam00767ae4 = 1;
    }
  }
  return 0;
}

