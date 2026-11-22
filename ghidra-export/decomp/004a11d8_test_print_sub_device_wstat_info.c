// func test_print_sub_device_wstat_info @ 004a11d8 size=1

void test_print_sub_device_wstat_info(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(uac_nms_dev_wstat_report_mutex,0xffffffff);
  printf("totaol len:%d \r\n",g_total_fit_ap_dev_wstat_report_cnt);
  iVar2 = FUN_004081b0(&g_uac_nms_dev_wstat_report_list);
  while ((iVar1 = iVar2, iVar1 != 0 && (iVar2 = FUN_00408680(iVar1), iVar2 != 0))) {
    if (*(int *)(iVar2 + 0x20) != 0) {
      printf("report_try_time:%d node time:%d type:%d len:%d data:%s.\r\n",
             (uint)*(byte *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
             *(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c),
             *(undefined4 *)(iVar1 + 0x20));
      puts("==========\r");
    }
  }
  uac_mutex_give(uac_nms_dev_wstat_report_mutex);
  return;
}

