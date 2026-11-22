// func _wsta_intelligent_roam_sta_change_ap_info @ 00484c00 size=300

undefined4 _wsta_intelligent_roam_sta_change_ap_info(int param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  char local_310;
  byte local_30f;
  undefined1 auStack_2e8 [732];
  
  memset(&local_310,0,0x22);
  memset(auStack_2e8,0,0x2d8);
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = wsta_roam_db_cfg_get(&local_310);
  if (iVar1 == -1) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
    uVar3 = 0xcdc;
  }
  else {
    iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_2e8);
    if (iVar1 != -1) {
      if (local_310 != '\0') {
        return 0;
      }
      if (1 < local_30f) {
        return 0;
      }
      iVar1 = get_high_per_sta_cnt();
      iVar2 = wsta_db_get_total_num();
      if (iVar2 <= iVar1) {
        return 0;
      }
      wireless_network_mode_change_handle(2);
      apmngr_db_foreach_proc(0x15f0000,_wsta_intelligent_roam_set_rd_info_by_sta,0);
      return 0;
    }
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar3 = 0xce3;
  }
  printf(__format,"_wsta_intelligent_roam_sta_change_ap_info",uVar3);
  return 0xffffffff;
}

