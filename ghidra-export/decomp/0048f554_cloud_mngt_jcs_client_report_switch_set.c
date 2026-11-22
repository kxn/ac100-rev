// func cloud_mngt_jcs_client_report_switch_set @ 0048f554 size=344

void cloud_mngt_jcs_client_report_switch_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_v1;
  uint uVar3;
  undefined8 uVar4;
  
  iVar1 = json_object_object_get(param_1,"status");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
      goto LAB_0048f5b0;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_0048f5b0;
    }
  }
  iVar1 = -1;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "cloud_mngt_jcs_client_report_switch_set",0x1e3a);
  }
LAB_0048f5b0:
  uVar3 = (uint)(iVar1 != 0);
  if (client_report_switch == uVar3) {
    return;
  }
  client_report_switch = uVar3;
  if (uVar3 != 0) {
    uVar4 = FUN_00524078();
    client_stats_begin_report_time = (undefined4)((ulonglong)uVar4 >> 0x20);
    DAT_00767624 = (undefined4)uVar4;
    FUN_00407e70();
    last_ap_stats_info_is_first_report = 1;
    last_ap_stats_info_report_time = extraout_v1;
    notify_uac_nms_report_begin_trans_fit_ap();
    FUN_00408340(client_first_report_interval,0,cloud_mngt_client_first_report_timer_cb,0,0,
                 "cloud_mngt_jcs_client_report_switch_set",0x1e44);
    notify_uac_nms_report_begin_trans_fit_ap();
    return;
  }
  set_stats_consumer_bit_mask(0,0);
  return;
}

