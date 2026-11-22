// func _wsta_intelligent_roam_ctl_pkt_send_cb @ 00489930 size=436

undefined4 _wsta_intelligent_roam_ctl_pkt_send_cb(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  char local_310;
  byte local_30f;
  undefined1 auStack_2e8 [12];
  int local_2dc;
  undefined2 local_2d8;
  
  uVar4 = 0xffffffff;
  memset(auStack_2e8,0,0x2d8);
  memset(&local_310,0,0x22);
  iVar1 = wsta_roam_db_cfg_get(&local_310);
  if (iVar1 == -1) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
    uVar3 = 0xbca;
LAB_004899dc:
    printf(__format,"_wsta_intelligent_roam_ctl_pkt_send_cb",uVar3);
    return uVar4;
  }
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    uVar4 = 0xffffffff;
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar3 = 0xbd1;
    goto LAB_004899dc;
  }
  if (local_2dc == 0) {
    uVar4 = 0;
    if (wsta_roam_debug_switch == '\0') {
      return 0;
    }
    __format = "[WSTA_ROAM_DEBUG]%s()/%d wtp is template, don\'t send msg to it.\n";
    uVar3 = 0xbd7;
    goto LAB_004899dc;
  }
  iVar1 = rdmngr_working_channel_send_by_ap_id(local_2d8);
  if (iVar1 != 0) {
    uVar4 = 0xffffffff;
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d rdmngr_working_channel_send_by_ap_id error.\n";
    uVar3 = 0xbdd;
    goto LAB_004899dc;
  }
  if (local_310 == '\0') {
    if (1 < local_30f) goto LAB_00489ad4;
    iVar1 = apmngr_db_active_ap_num_get();
    iVar2 = get_high_per_ap_cnt();
    if (iVar2 < iVar1 + 1) {
      uVar4 = wireless_network_mode_change_handle(2);
      return uVar4;
    }
  }
  else if (local_310 != '\x01') goto LAB_00489ad4;
  _wsta_intelligent_roam_set_rd_info(auStack_2e8,0);
  iVar1 = _wstat_roam_update_wireless_network_mode_to_ap(auStack_2e8,0);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
LAB_00489ad4:
  uVar4 = FUN_004897a4(param_1);
  return uVar4;
}

