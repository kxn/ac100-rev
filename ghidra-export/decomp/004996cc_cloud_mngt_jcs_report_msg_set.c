// func cloud_mngt_jcs_report_msg_set @ 004996cc size=872

void cloud_mngt_jcs_report_msg_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_v1;
  char *__src;
  uint uVar4;
  undefined8 uVar5;
  char acStack_60 [72];
  
  memset(acStack_60,0,0x41);
  iVar1 = json_object_object_get(param_1,"site_id");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "cloud_mngt_jcs_report_msg_set",0x1de3);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_60,__src,0x40);
  strncpy(site_id,acStack_60,0x40);
  iVar1 = json_object_object_get(param_1,"status");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
      goto LAB_004997b4;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar5 = json_object_get_double(iVar1);
      uVar4 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      goto LAB_004997b4;
    }
  }
  uVar4 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "cloud_mngt_jcs_report_msg_set",0x1de7);
  }
LAB_004997b4:
  uVar3 = (uint)(uVar4 != 0);
  if (ap_report_switch == uVar3) {
    return;
  }
  ap_report_switch = uVar3;
  if (uVar3 == 0) {
    FUN_00407ea0(ap_container);
    FUN_00407ea0(client_container);
    FUN_00407ea0(client_events_container);
    FUN_00407ea0(bssid_info_changed_sc);
    client_report_switch = 0;
    ap_update_count = 0;
    ap_offline_or_online = 0;
    if (g_cloud_mngt_ap_report_timer_id != -1) {
      FUN_00408060();
      g_cloud_mngt_ap_report_timer_id = -1;
    }
    if (g_cloud_mngt_client_report_timer_id != -1) {
      FUN_00408060();
      g_cloud_mngt_client_report_timer_id = -1;
    }
    if (g_cloud_mngt_config_sync_report_timer_id != -1) {
      FUN_00408060();
      g_cloud_mngt_config_sync_report_timer_id = -1;
    }
    notify_uac_nms_report_stop_trans_fit_ap();
    set_stats_consumer_bit_mask(0,0);
    cloud_mngt_sync_module_config_clear();
  }
  else {
    if (client_report_switch != 0) {
      set_stats_consumer_bit_mask(1,0);
    }
    cloud_mngt_notify_report(3);
    FUN_00407e70();
    DAT_007cca50 = 1;
    DAT_007cca54 = 1;
    DAT_007cca58 = 1;
    last_ap_report_time = extraout_v1;
    DAT_007cca60 = extraout_v1;
    DAT_007cca64 = extraout_v1;
    DAT_007cca68 = extraout_v1;
    uVar5 = FUN_00524078();
    last_ap_stats_begin_report_time = (undefined4)((ulonglong)uVar5 >> 0x20);
    DAT_00767634 = (undefined4)uVar5;
    g_cloud_mngt_ap_report_timer_id =
         FUN_00408340(ap_first_report_interval,0,cloud_mngt_ap_update_report_timer_cb,0,0,
                      "cloud_mngt_jcs_report_msg_set",0x1dfa);
    ap_offline_or_online = 1;
    FUN_00408340(1,0,_uac_com_update_dev_ip,0,0,"cloud_mngt_jcs_report_msg_set",0x1dfd);
    cloud_mngt_notify_ca_certs(0,1);
  }
  FUN_00498f20(uVar4 & 0xff,0,1);
  return;
}

