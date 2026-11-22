// func test_print_sub_device_events @ 004a2478 size=220

void test_print_sub_device_events(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(uac_nms_event_report_mutex,0xffffffff);
  printf("totaol len:%d \r\n",g_total_fit_nms_events_cnt);
  iVar2 = FUN_004081b0(&g_uac_nms_event_report_list);
  while ((iVar1 = iVar2, iVar1 != 0 && (iVar2 = FUN_00408680(iVar1), iVar2 != 0))) {
    if (*(int *)(iVar1 + 0x20) != 0) {
      printf("report_try_time:%d node time:%d type:%d len:%d data:%s.\r\n",
             (uint)*(byte *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
             *(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c),*(int *)(iVar1 + 0x20));
      puts("==========\r");
    }
  }
  FUN_00407f30(uac_nms_event_report_mutex);
  return;
}

