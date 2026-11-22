// func get_uac_nms_dev_wstat_report @ 004a0730 size=712

undefined4 get_uac_nms_dev_wstat_report(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  undefined1 *puVar4;
  void *__dest;
  int iVar5;
  int iVar6;
  
  if (((param_1 == 0) || (param_2 == (int *)0x0)) || (iVar5 = *param_2, iVar5 < 1)) {
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d invalid params.\n","get_uac_nms_dev_wstat_report",400);
    }
    return 0xffffffff;
  }
  FUN_004082d0(uac_nms_dev_wstat_report_mutex,0xffffffff);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d get_uac_nms_dev_status_list.\n","get_uac_nms_dev_wstat_report"
           ,0x195);
  }
  iVar6 = 0;
  bVar1 = true;
  iVar2 = FUN_004081b0(&g_uac_nms_dev_wstat_report_list);
  do {
    while( true ) {
      if ((iVar2 == 0) || (iVar5 < 1)) {
        FUN_00407f30(uac_nms_dev_wstat_report_mutex);
        if (cloud_mngt_info_switch == '\0') {
          *param_2 = iVar5;
          return 0;
        }
        printf("[CLOUD_MNGT_INFO]%s()/%d  len:%d g_total_fit_ap_dev_wstat_report_cnt;%d.\r\n\n",
               "get_uac_nms_dev_wstat_report",0x1c8,iVar5,g_total_fit_ap_dev_wstat_report_cnt);
        *param_2 = iVar5;
        return 0;
      }
      iVar3 = FUN_00408680(iVar2);
      if (*(char **)(iVar2 + 0x20) != (char *)0x0) break;
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d node->ap_nms_report_info.data is NULL\n",
               "get_uac_nms_dev_wstat_report",0x1c0);
      }
      FUN_00408500(iVar2);
LAB_004a0930:
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
    __n = strlen(*(char **)(iVar2 + 0x20));
    if (((*(uint *)(iVar2 + 0x1c) < __n) || ((int)__n < 1)) || (iVar5 + -1 < (int)__n)) {
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d tmp_len check failed.\n","get_uac_nms_dev_wstat_report",
               0x1b6);
      }
      FUN_00408500(iVar2);
      g_total_fit_ap_dev_wstat_report_cnt =
           g_total_fit_ap_dev_wstat_report_cnt - *(int *)(iVar2 + 0x1c);
      FUN_00407df0(*(undefined4 *)(iVar2 + 0x20));
      *(undefined4 *)(iVar2 + 0x20) = 0;
      goto LAB_004a0930;
    }
    if (!bVar1) {
      puVar4 = (undefined1 *)(param_1 + iVar6);
      iVar6 = iVar6 + 1;
      *puVar4 = 0x2c;
      iVar5 = iVar5 + -1;
    }
    __dest = (void *)(param_1 + iVar6);
    iVar6 = iVar6 + __n;
    memcpy(__dest,*(void **)(iVar2 + 0x20),__n);
    iVar5 = iVar5 - __n;
    bVar1 = false;
    *(char *)(iVar2 + 0x10) = *(char *)(iVar2 + 0x10) + '\x01';
    *(undefined1 *)(iVar2 + 0x11) = 1;
    FUN_00408500(iVar2);
    g_total_fit_ap_dev_wstat_report_cnt =
         g_total_fit_ap_dev_wstat_report_cnt - *(int *)(iVar2 + 0x1c);
    FUN_00407df0(*(undefined4 *)(iVar2 + 0x20));
    *(undefined4 *)(iVar2 + 0x20) = 0;
    FUN_00407df0(iVar2);
    iVar2 = iVar3;
  } while( true );
}

