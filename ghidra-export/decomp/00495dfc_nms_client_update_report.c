// func nms_client_update_report @ 00495dfc size=840

/* WARNING: Removing unreachable block (ram,0x00495ee8) */

void nms_client_update_report(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *__s;
  undefined4 uVar4;
  int extraout_v1;
  int extraout_v1_00;
  int iVar5;
  
  FUN_00407e70();
  iVar1 = get_stats_sample_report_time(0);
  iVar2 = get_stats_sample_time(0);
  if ((((ap_report_switch != 0) && (client_report_switch != 0)) && (iVar1 != -1)) && (iVar2 != -1))
  {
    iVar5 = extraout_v1 - last_ap_stats_info_report_time;
    if (cloud_mngt_info_switch != '\0') {
      printf("[CLOUD_MNGT_INFO]%s()/%d report_time_interval:%d\n","nms_client_update_report",0x19d2,
             iVar1);
    }
    if (cloud_mngt_info_switch != '\0') {
      printf("[CLOUD_MNGT_INFO]%s()/%d cur_time:%d\n","nms_client_update_report",0x19d3,extraout_v1)
      ;
    }
    if (cloud_mngt_info_switch != '\0') {
      printf("[CLOUD_MNGT_INFO]%s()/%d last_client_stats_report_time:%d\n",
             "nms_client_update_report",0x19d4,last_ap_stats_info_report_time);
    }
    if (cloud_mngt_info_switch != '\0') {
      printf("[CLOUD_MNGT_INFO]%s()/%d tmp_time_interval:%d\n","nms_client_update_report",0x19d5,
             iVar5);
    }
    if (((iVar5 < iVar1) && (param_1 == 0)) && (last_ap_stats_info_is_first_report == 0)) {
      uVar3 = iVar1 - iVar5 >> 0x1f;
      iVar1 = (uVar3 ^ iVar1 - iVar5) - uVar3;
      if (cloud_mngt_info_switch != '\0') {
        printf("[CLOUD_MNGT_INFO]%s()/%d labs_time:%ld\n","nms_client_update_report",0x19dc,iVar1);
      }
      if (iVar2 / 5 < iVar1) {
        return;
      }
    }
    last_ap_stats_info_is_first_report = 0;
    FUN_00407e70();
    last_ap_stats_info_report_time = extraout_v1_00;
    iVar1 = json_object_new_object();
    __s = (int *)FUN_00408450(0x34,0x19e7);
    if (__s != (int *)0x0) {
      memset(__s,0,0x34);
      uVar4 = apmngr_db_get_ap_max();
      iVar2 = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,client_handle_hash_cmp,
                           uVar4);
      __s[0xb] = iVar2;
      *__s = iVar1;
      __s[4] = params_report_cnt_limit;
      __s[6] = 7;
      __s[5] = (int)"subDeviceStats";
      FUN_0049164c(iVar1);
      stats_db_sta_for_each_range(nms_report_client_add_to_json,__s);
      if ((0 < __s[3]) && (__s[1] != 0)) {
        FUN_00408570(__s[0xb],add_client_hash_node);
        json_object_object_add(*__s,__s[5],__s[1]);
        __s[1] = 0;
        free_ac_cloud_mngt_hash(__s + 0xb,0);
        if ((ap_report_switch != 0) && (client_report_switch != 0)) {
          nms_stat_obj_send_to_cloud(__s[6],*__s);
        }
      }
    }
    if (iVar1 != 0) {
      json_object_put(iVar1);
    }
    free_ac_cloud_mngt_hash(__s + 0xb,1);
    if (__s != (int *)0x0) {
      if (__s[1] != 0) {
        json_object_put();
      }
      FUN_00407df0(__s);
      return;
    }
  }
  return;
}

