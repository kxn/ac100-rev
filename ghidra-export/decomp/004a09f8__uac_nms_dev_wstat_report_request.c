// func _uac_nms_dev_wstat_report_request @ 004a09f8 size=572

undefined4 _uac_nms_dev_wstat_report_request(void *param_1,size_t param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  void *__s;
  void *__s_00;
  int iVar3;
  undefined4 extraout_v1;
  undefined4 uVar4;
  
  iVar2 = check_nms_get_passthrough_report(*(undefined2 *)(param_3 + 0x10));
  if ((iVar2 != 0) && (g_fit_ap_dev_wstat_report_test != 1)) {
    return 0;
  }
  if (param_1 == (void *)0x0) {
    return 0;
  }
  if ((int)param_2 < 0x100000) {
    if ((int)param_2 < 1) {
      return 0;
    }
    __s = (void *)FUN_00408450(0x24,0xe3);
    if (__s == (void *)0x0) {
      if (cloud_mngt_err_switch == '\0') {
        return 0xffffffff;
      }
      uVar4 = 0xe6;
    }
    else {
      memset(__s,0,0x24);
      uVar1 = *(ushort *)(param_3 + 0x10);
      *(size_t *)((int)__s + 0x1c) = param_2;
      *(undefined4 *)((int)__s + 0x18) = 0;
      *(uint *)((int)__s + 0xc) = (uint)uVar1;
      __s_00 = (void *)FUN_00408450(param_2 + 1,0xf2);
      *(void **)((int)__s + 0x20) = __s_00;
      if (__s_00 != (void *)0x0) {
        memset(__s_00,0,*(int *)((int)__s + 0x1c) + 1);
        memcpy(*(void **)((int)__s + 0x20),param_1,param_2);
        FUN_004082d0(uac_nms_dev_wstat_report_mutex,0xffffffff);
        iVar2 = g_total_fit_ap_dev_wstat_report_cnt;
        if (param_2 + g_total_fit_ap_dev_wstat_report_cnt < 0x100000) {
          *(undefined1 *)((int)__s + 0x10) = 0;
        }
        else {
          iVar3 = replace_old_uac_nms_params_report(param_2,&g_uac_nms_dev_wstat_report_list);
          g_total_fit_ap_dev_wstat_report_cnt = iVar2 - iVar3;
          *(undefined1 *)((int)__s + 0x10) = 0;
        }
        *(undefined1 *)((int)__s + 0x11) = 0;
        FUN_00407e70();
        *(undefined4 *)((int)__s + 0x14) = extraout_v1;
        FUN_004086b0(&g_uac_nms_dev_wstat_report_list,__s);
        iVar2 = param_2 + g_total_fit_ap_dev_wstat_report_cnt;
        g_total_fit_ap_dev_wstat_report_cnt = iVar2;
        FUN_00407f30(uac_nms_dev_wstat_report_mutex);
        if (iVar2 * 100 < 0x5a00000) {
          _uac_nms_cancle_send_later_handle(3);
        }
        else {
          _uac_nms_trigger_send_later_handle();
        }
        FUN_004082d0(uac_nms_dev_wstats_msg_mutex,0xffffffff);
        FUN_004084b0(uac_nms_dev_wstats_msg_cond);
        FUN_00407f30(uac_nms_dev_wstats_msg_mutex);
        return 0;
      }
      FUN_00407df0(__s);
      if (cloud_mngt_err_switch == '\0') {
        return 0xffffffff;
      }
      uVar4 = 0xf6;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d no memory to alloc!!!\n","_uac_nms_dev_wstat_report_request",
           uVar4);
    return 0xffffffff;
  }
  return 0;
}

