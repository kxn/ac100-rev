// func _stats_ap_online_cb @ 00672ab0 size=480

undefined4 _stats_ap_online_cb(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_2f0 [64];
  undefined4 local_2b0;
  undefined1 auStack_2a8 [464];
  undefined1 auStack_d8 [196];
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0);
  if (iVar1 == -1) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d get ap entry by id failed[%u]\n","_stats_ap_online_cb",0xdc,
           param_1);
    return 0xffffffff;
  }
  uVar2 = apdb_radio_count_by_id(local_2b0,auStack_d8);
  if (uVar2 == 0xffffffff) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_WARNING]%s()/%d apdb_radio_count_by_id() fail.\n","_stats_ap_online_cb",0xe2
          );
    return 0xffffffff;
  }
  uVar3 = rdmngr_profile_get_max_rd_per_ap();
  iVar1 = FUN_004082a0(1,uVar3,0xe6);
  iVar4 = rdmngr_profile_get_max_wlan_per_rd();
  iVar5 = rdmngr_profile_get_max_rd_per_ap();
  iVar4 = FUN_004082a0(1,iVar5 * iVar4,0xe7);
  if ((iVar1 == 0) || (iVar4 == 0)) {
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d out of memory\n","_stats_ap_online_cb",0xea);
    }
    uVar3 = 0xffffffff;
    if (iVar1 == 0) goto LAB_00672b70;
  }
  else {
    iVar5 = wserv_db_get_radio_state(param_1,uVar2,iVar1);
    if ((iVar5 == 0) && (iVar5 = wserv_db_get_radio_wlan_state(param_1,uVar2,iVar4), iVar5 == 0)) {
      stats_db_ap_active(param_1,auStack_2a8,uVar2 & 0xff,iVar1,iVar4);
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffff;
      if (stats_warning_switch != '\0') {
        printf("[STATISTICS_WARNING]%s()/%d get radio state or radio-wlan state fail.\n",
               "_stats_ap_online_cb",0xf1);
      }
    }
  }
  FUN_00407df0(iVar1);
LAB_00672b70:
  if (iVar4 != 0) {
    FUN_00407df0(iVar4);
  }
  return uVar3;
}

