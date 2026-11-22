// func nms_report_ap_stats_update_report @ 00495a80 size=892

/* WARNING: Removing unreachable block (ram,0x00495d18) */

void nms_report_ap_stats_update_report(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *__s;
  char *__s_00;
  size_t sVar3;
  uint uVar4;
  int extraout_v1;
  int iVar5;
  
  FUN_00407e70();
  if (param_1 - 1U < 3) {
    iVar1 = get_stats_sample_report_time(param_1);
    iVar2 = get_stats_sample_time(param_1);
    if (((ap_report_switch != 0) && (iVar1 != -1)) && (iVar2 != -1)) {
      iVar5 = extraout_v1 - (&last_ap_stats_info_report_time)[param_1];
      if (cloud_mngt_info_switch != '\0') {
        printf("[CLOUD_MNGT_INFO]%s()/%d type:%d report_time_interval:%d\n",
               "nms_report_ap_stats_update_report",0x1980,param_1,iVar1);
      }
      if (cloud_mngt_info_switch != '\0') {
        printf("[CLOUD_MNGT_INFO]%s()/%d cur_time:%d\n","nms_report_ap_stats_update_report",0x1981,
               extraout_v1);
      }
      if (cloud_mngt_info_switch != '\0') {
        printf("[CLOUD_MNGT_INFO]%s()/%d last_ap_stats_info_report_time:%d\n",
               "nms_report_ap_stats_update_report",0x1982,(&last_ap_stats_info_report_time)[param_1]
              );
      }
      if (cloud_mngt_info_switch != '\0') {
        printf("[CLOUD_MNGT_INFO]%s()/%d tmp_time_interval:%d\n","nms_report_ap_stats_update_report"
               ,0x1983,iVar5);
      }
      if (((iVar5 < iVar1) && (param_2 == 0)) &&
         ((&last_ap_stats_info_is_first_report)[param_1] == 0)) {
        uVar4 = iVar1 - iVar5 >> 0x1f;
        iVar1 = (uVar4 ^ iVar1 - iVar5) - uVar4;
        if (cloud_mngt_info_switch != '\0') {
          printf("[CLOUD_MNGT_INFO]%s()/%d labs_time:%ld\n","nms_report_ap_stats_update_report",
                 0x198a,iVar1);
        }
        if (iVar2 / 5 < iVar1) {
          return;
        }
      }
      (&last_ap_stats_info_is_first_report)[param_1] = 0;
      (&last_ap_stats_info_report_time)[param_1] = extraout_v1;
      iVar1 = json_object_new_object();
      __s = (int *)FUN_00408450(0x34,0x1995);
      if (__s != (int *)0x0) {
        memset(__s,0,0x34);
        *__s = iVar1;
        __s[4] = (&params_report_cnt_limit)[param_1];
        __s[6] = 6;
        __s[5] = (int)"subDeviceStats";
        __s[0xc] = 0x3f800;
        FUN_0049164c(iVar1);
        iVar2 = __s[0xc];
        __s_00 = (char *)json_object_to_json_string_ext(iVar1,0);
        sVar3 = strlen(__s_00);
        __s[0xc] = ~sVar3 + iVar2;
        stats_db_ap_for_each_range((&nms_report_ap_stats_handle)[param_1],__s);
        if ((0 < __s[3]) && (__s[1] != 0)) {
          json_object_object_add(*__s,__s[5]);
          __s[1] = 0;
          if (ap_report_switch != 0) {
            nms_stat_obj_send_to_cloud(__s[6],*__s);
          }
        }
      }
      if (iVar1 != 0) {
        json_object_put(iVar1);
      }
      if (__s != (int *)0x0) {
        if (__s[1] != 0) {
          json_object_put();
        }
        FUN_00407df0(__s);
        return;
      }
    }
  }
  return;
}

