// func _uac_nms_event_report_request @ 004a1770 size=804

/* WARNING: Removing unreachable block (ram,0x004a19c8) */

undefined4 _uac_nms_event_report_request(void *param_1,size_t param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  void *__s;
  void *__s_00;
  int iVar3;
  undefined4 extraout_v1;
  undefined4 uVar4;
  
  iVar2 = check_nms_get_passthrough_report(*(undefined2 *)(param_3 + 0x10));
  if ((iVar2 != 0) && (g_fit_ap_nms_events_test != 1)) {
    return 0;
  }
  if (param_1 == (void *)0x0) {
    return 0;
  }
  if ((int)param_2 < 0x500000) {
    if ((int)param_2 < 1) {
      return 0;
    }
    __s = (void *)FUN_00408450(0x24,0xe7);
    if (__s == (void *)0x0) {
      if (cloud_mngt_err_switch == '\0') {
        return 0xffffffff;
      }
      uVar4 = 0xea;
    }
    else {
      g_test_events_count = g_test_events_count + 1;
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d g_total_fit_nms_events_cnt:%d tmp_len:%d g_test_events_len:%d g_test_events_count:%d.\n"
               ,"_uac_nms_event_report_request",0xf1,g_total_fit_nms_events_cnt,param_2,
               g_test_events_len,g_test_events_count);
      }
      memset(__s,0,0x24);
      uVar1 = *(ushort *)(param_3 + 0x10);
      *(size_t *)((int)__s + 0x1c) = param_2;
      *(undefined4 *)((int)__s + 0x18) = 0;
      *(uint *)((int)__s + 0xc) = (uint)uVar1;
      __s_00 = (void *)FUN_00408450(param_2 + 1,0xf9);
      *(void **)((int)__s + 0x20) = __s_00;
      if (__s_00 != (void *)0x0) {
        memset(__s_00,0,*(int *)((int)__s + 0x1c) + 1);
        memcpy(*(void **)((int)__s + 0x20),param_1,param_2);
        FUN_004082d0(uac_nms_event_report_mutex,0xffffffff);
        if (0x4fffff < param_2 + g_total_fit_nms_events_cnt) {
          DAT_00767abc = DAT_00767abc + 1;
          if ((g_test_events_debug != 0) && (DAT_00767abc % 1000 == 0)) {
            printf("g_total_fit_nms_events_cnt:%d tmp_len:%d g_test_events_len:%d g_test_events_count:%d.\r\n"
                   ,g_total_fit_nms_events_cnt,param_2,g_test_events_len,g_test_events_count);
          }
          iVar2 = g_total_fit_nms_events_cnt;
          iVar3 = replace_old_uac_nms_params_report(param_2,&g_uac_nms_event_report_list);
          g_total_fit_nms_events_cnt = iVar2 - iVar3;
          g_test_events_len = g_test_events_len - iVar3;
        }
        *(undefined1 *)((int)__s + 0x10) = 0;
        *(undefined1 *)((int)__s + 0x11) = 0;
        FUN_00407e70();
        *(undefined4 *)((int)__s + 0x14) = extraout_v1;
        FUN_004086b0(&g_uac_nms_event_report_list,__s);
        iVar2 = param_2 + g_total_fit_nms_events_cnt;
        g_test_events_len = param_2 + g_test_events_len;
        g_test_events_remain_count = g_test_events_remain_count + 1;
        g_total_fit_nms_events_cnt = iVar2;
        FUN_00407f30(uac_nms_event_report_mutex);
        if (iVar2 * 100 < 0x1c200000) {
          _uac_nms_cancle_send_later_handle();
        }
        else {
          _uac_nms_trigger_send_later_handle(1);
        }
        FUN_004082d0(uac_nms_event_msg_mutex,0xffffffff);
        FUN_004084b0(uac_nms_event_msg_cond);
        FUN_00407f30(uac_nms_event_msg_mutex);
        return 0;
      }
      FUN_00407df0(__s);
      if (cloud_mngt_err_switch == '\0') {
        return 0xffffffff;
      }
      uVar4 = 0xfd;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d no memory to alloc!!!\n","_uac_nms_event_report_request",uVar4
          );
    return 0xffffffff;
  }
  return 0;
}

