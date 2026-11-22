// func wsta_intelligent_roam_manual_change_wireless_network_mode @ 00489c08 size=456

undefined4 wsta_intelligent_roam_manual_change_wireless_network_mode(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  char *pcVar4;
  int local_60;
  undefined1 local_5c [36];
  byte local_38;
  char local_37;
  
  memset(&local_38,0,0x22);
  if (2 < param_1) {
    return 0xffffffff;
  }
  if (wsta_roam_debug_switch != '\0') {
    printf("[WSTA_ROAM_DEBUG]%s()/%d begin to manual change roam_wireless_network_mode:%d\n",
           "wsta_intelligent_roam_manual_change_wireless_network_mode",0xc90,param_1);
  }
  wsta_roam_db_cfg_get(&local_38);
  if (param_1 == local_38) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d invalid ap mode\n";
    pcVar4 = "wsta_intelligent_roam_manual_change_wireless_network_mode";
    uVar2 = 0xc97;
LAB_00489ce0:
    printf(__format,pcVar4,uVar2);
    return 0xffffffff;
  }
  memset(local_5c,0,0x22);
  iVar1 = wsta_roam_db_cfg_get(local_5c);
  if (iVar1 == -1) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
    pcVar4 = "_wstat_roam_switch_wirless_network_mode";
    uVar2 = 0xb49;
    goto LAB_00489ce0;
  }
  local_5c[0] = (undefined1)param_1;
  wsta_roam_db_cfg_set(local_5c);
  if (local_37 != '\x02') goto LAB_00489c9c;
  if (param_1 != 1) {
    if (param_1 != 0) goto LAB_00489c9c;
    iVar1 = apmngr_db_active_ap_num_get();
    iVar3 = get_high_per_ap_cnt();
    if (iVar3 < iVar1) goto LAB_00489c9c;
    iVar1 = get_high_per_sta_cnt();
    iVar3 = wsta_db_get_total_num();
    if (iVar1 < iVar3) goto LAB_00489c9c;
  }
  local_60 = 0;
  apmngr_db_foreach_proc(0x15f0000,_wstat_roam_check_exist_support_ap,&local_60);
  if (local_60 == 0) {
    update_high_per_ap_chn_info(1,0,1);
    update_high_per_ap_chn_info(2,0,1);
    update_high_per_ap_chn_info(3,0,1);
  }
LAB_00489c9c:
  uVar2 = check_cur_wireless_network_mode(1);
  return uVar2;
}

