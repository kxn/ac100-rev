// func uac_nms_params_report_test_handle @ 004a3548 size=196

undefined4 uac_nms_params_report_test_handle(int param_1)

{
  int iVar1;
  undefined4 extraout_v1;
  undefined4 uVar2;
  undefined4 local_58;
  char acStack_54 [68];
  
  uVar2 = 0;
  local_58 = 0;
  memset(acStack_54,0,0x40);
  if (-1 < param_1) {
    g_test_ap_id = param_1;
    FUN_00407e70();
    snprintf(acStack_54,0x40,"params_report_handle_test%d",extraout_v1);
    iVar1 = FUN_004084e0(&local_58,"uac_nms_event_report_handle_test",test_report_nms_params,
                         &g_test_ap_id);
    if ((iVar1 != 0) && (uVar2 = 0xffffffff, cloud_mngt_err_switch != '\0')) {
      printf("[CLOUD_MNGT_ERROR]%s()/%d Failed to create cloud mngt msg thread\n",
             "uac_nms_params_report_test_handle",0x27d);
    }
  }
  return uVar2;
}

