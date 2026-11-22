// func uac_nms_report_msg_thread @ 0049d670 size=212

void uac_nms_report_msg_thread(void)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  FUN_0051ad88(&local_28);
  do {
    FUN_004082d0(uac_nms_msg_report_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_uac_nms_msg_report_list), iVar1 == 0) {
      FUN_004086c0(uac_nms_msg_report_cond,uac_nms_msg_report_mutex,0xffffffff);
    }
    FUN_004082c0(&local_28,&g_uac_nms_msg_report_list);
    FUN_00407f30(uac_nms_msg_report_mutex);
    while (iVar1 = FUN_004081b0(&local_28), iVar1 != 0) {
      FUN_00408500(iVar1);
      if (*(int *)(iVar1 + 0x10) != 0) {
        uac_nms_report_msg_handle();
        FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      FUN_00407df0(iVar1);
    }
  } while( true );
}

