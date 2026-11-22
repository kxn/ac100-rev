// func get_uac_nms_event_report @ 004a1454 size=796

undefined4 get_uac_nms_event_report(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  uint uVar4;
  undefined1 *puVar5;
  void *__dest;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  if (((param_1 == 0) || (param_2 == (int *)0x0)) || (iVar7 = *param_2, iVar7 < 1)) {
    uVar6 = 0xffffffff;
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d invalid params.\n","get_uac_nms_event_report",0x1a2);
    }
  }
  else {
    iVar8 = 0;
    FUN_004082d0(uac_nms_event_report_mutex,0xffffffff);
    iVar2 = FUN_004081b0(&g_uac_nms_event_report_list);
    bVar1 = true;
    while ((iVar2 != 0 && (0 < iVar7))) {
      iVar3 = FUN_00408680(iVar2);
      if (*(char **)(iVar2 + 0x20) == (char *)0x0) {
        if (cloud_mngt_debug_switch != '\0') {
          printf("[CLOUD_MNGT_DEBUG]%s()/%d node->ap_nms_report_info.data is NULL\n",
                 "get_uac_nms_event_report",0x1d8);
        }
        FUN_00408500(iVar2);
        FUN_00407df0(iVar2);
        iVar2 = iVar3;
      }
      else {
        __n = strlen(*(char **)(iVar2 + 0x20));
        if (cloud_mngt_debug_switch == '\0') {
          uVar4 = *(uint *)(iVar2 + 0x1c);
        }
        else {
          printf("[CLOUD_MNGT_DEBUG]%s()/%d tmp_len:%d node->ap_nms_report_info.len:%d len:%d.\r\n\n"
                 ,"get_uac_nms_event_report",0x1af,__n,*(undefined4 *)(iVar2 + 0x1c),iVar7);
          uVar4 = *(uint *)(iVar2 + 0x1c);
        }
        if (((uVar4 < __n) || ((int)__n < 1)) || (iVar7 + -1 < (int)__n)) {
          if (cloud_mngt_debug_switch != '\0') {
            printf("[CLOUD_MNGT_DEBUG]%s()/%d tmp_len check failed.\n","get_uac_nms_event_report",
                   0x1cc);
          }
          FUN_00408500(iVar2);
          g_total_fit_nms_events_cnt = g_total_fit_nms_events_cnt - *(int *)(iVar2 + 0x1c);
          g_test_events_len = g_test_events_len - *(int *)(iVar2 + 0x1c);
          FUN_00407df0(*(undefined4 *)(iVar2 + 0x20));
          *(undefined4 *)(iVar2 + 0x20) = 0;
          FUN_00407df0(iVar2);
          g_test_events_remain_count = g_test_events_remain_count + -1;
          iVar2 = iVar3;
        }
        else {
          if (!bVar1) {
            puVar5 = (undefined1 *)(param_1 + iVar8);
            iVar8 = iVar8 + 1;
            *puVar5 = 0x2c;
            iVar7 = iVar7 + -1;
          }
          __dest = (void *)(param_1 + iVar8);
          iVar8 = iVar8 + __n;
          memcpy(__dest,*(void **)(iVar2 + 0x20),__n);
          iVar7 = iVar7 - __n;
          *(char *)(iVar2 + 0x10) = *(char *)(iVar2 + 0x10) + '\x01';
          *(undefined1 *)(iVar2 + 0x11) = 1;
          FUN_00408500(iVar2);
          g_total_fit_nms_events_cnt = g_total_fit_nms_events_cnt - *(int *)(iVar2 + 0x1c);
          g_test_events_len = g_test_events_len - *(int *)(iVar2 + 0x1c);
          FUN_00407df0(*(undefined4 *)(iVar2 + 0x20));
          *(undefined4 *)(iVar2 + 0x20) = 0;
          FUN_00407df0(iVar2);
          bVar1 = false;
          g_test_events_remain_count = g_test_events_remain_count + -1;
          iVar2 = iVar3;
        }
      }
    }
    FUN_00407f30(uac_nms_event_report_mutex);
    if (cloud_mngt_info_switch != '\0') {
      printf("[CLOUD_MNGT_INFO]%s()/%d  len:%d g_total_fit_nms_events_cnt;%d.\r\n\n",
             "get_uac_nms_event_report",0x1e1,iVar7,g_total_fit_nms_events_cnt);
    }
    uVar6 = 0;
    *param_2 = iVar7;
  }
  return uVar6;
}

