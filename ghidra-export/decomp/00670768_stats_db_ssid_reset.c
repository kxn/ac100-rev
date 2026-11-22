// func stats_db_ssid_reset @ 00670768 size=796

undefined4 stats_db_ssid_reset(ushort param_1,byte param_2,byte param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int extraout_v1;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int *piVar10;
  
  uVar8 = (uint)param_3;
  uVar7 = (uint)param_2;
  uVar6 = (uint)param_1;
  iVar1 = apmngr_db_get_ap_max();
  if (((((int)uVar6 < iVar1) && (uVar7 != 0)) &&
      (uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar7 <= uVar2)) &&
     ((uVar8 != 0 && (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar8 <= uVar2)))) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = *(int *)(*(int *)(DAT_007cc8ec + uVar6 * 0x1e0 + 0x1d8) + (uVar7 - 1) * 8 + 4);
    if (iVar1 == 0) {
      if (stats_warning_switch != '\0') {
        printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_ssid_reset",0x100a,
               uVar6,uVar7,uVar8);
      }
      FUN_00407f30(l_stats_data);
      return 0xffffffff;
    }
    piVar10 = (int *)(*(int *)(iVar1 + 0x160) + (uVar8 - 1) * 0x100);
    iVar1 = memcmp((void *)((int)piVar10 + 9),&bssid_empty,6);
    if (iVar1 != 0) {
      stats_db_bssid_del((void *)((int)piVar10 + 9));
      bssid_changed_callback_proc(1,uVar6);
    }
    piVar10[1] = param_4;
    FUN_00407e70();
    *piVar10 = DAT_00758cf0 + 5 + extraout_v1;
    uVar9 = l_stats_data;
    *(byte *)(piVar10 + 2) = *(byte *)(piVar10 + 2) & 0xfc | 8;
    FUN_00407f30(uVar9);
    iVar1 = apmngr_db_get_ap_max();
    if ((((int)uVar6 < iVar1) && (uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar7 <= uVar2)) &&
       (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar8 <= uVar2)) {
      puVar3 = (ushort *)FUN_004082a0(1,4,0xfdc);
      if (puVar3 == (ushort *)0x0) {
        if (stats_err_switch == '\0') {
          return 0;
        }
        printf("[STATISTICS_ERROR]%s()/%d malloc AP_RD_INFO fail\n","stats_db_callback_ssid_leave",
               0xfde);
        return 0;
      }
      *puVar3 = param_1;
      *(byte *)(puVar3 + 1) = param_2;
      *(byte *)((int)puVar3 + 3) = param_3;
      iVar1 = FUN_00408340(0,10000,stats_db_callback_ssid_leave_async,puVar3,
                           stats_db_callback_ssid_leave_arg_free,"stats_db_callback_ssid_leave",
                           0xfe5);
      if (iVar1 != -1) {
        return 0;
      }
      if (stats_err_switch != '\0') {
        printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","stats_db_callback_ssid_leave",
               0xfe8);
      }
      FUN_00407df0(puVar3);
      return 0;
    }
    uVar9 = 0;
    if (stats_warning_switch == '\0') {
      return 0;
    }
    pcVar4 = "stats_db_callback_ssid_leave";
    uVar5 = 0xfd9;
  }
  else {
    uVar9 = 0xffffffff;
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "stats_db_ssid_reset";
    uVar5 = 0x1002;
  }
  printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n",pcVar4,uVar5,uVar6,uVar7,uVar8);
  return uVar9;
}

