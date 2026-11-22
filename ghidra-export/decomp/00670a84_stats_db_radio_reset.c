// func stats_db_radio_reset @ 00670a84 size=872

undefined4 stats_db_radio_reset(ushort param_1,byte param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  int extraout_v1;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  uVar12 = (uint)param_2;
  uVar11 = (uint)param_1;
  FUN_00407e70();
  iVar1 = apmngr_db_get_ap_max();
  if ((((int)uVar11 < iVar1) && (uVar12 != 0)) &&
     (uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar12 <= uVar2)) {
    iVar1 = (uVar12 - 1) * 8;
    FUN_004082d0(l_stats_data,0xffffffff);
    pbVar3 = *(byte **)(*(int *)(DAT_007cc8ec + uVar11 * 0x1e0 + 0x1d8) + iVar1 + 4);
    if (pbVar3 == (byte *)0x0) {
      if (stats_warning_switch != '\0') {
        printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n","stats_db_radio_reset",0xe6d,
               uVar11,uVar12);
      }
      FUN_00407f30(l_stats_data);
      return 0xffffffff;
    }
    *(int *)(pbVar3 + 0x38) = param_3;
    iVar14 = DAT_00758cf0;
    if (DAT_00758cf0 <= DAT_00758ce8) {
      iVar14 = DAT_00758ce8;
    }
    if (iVar14 < DAT_00758cec) {
      iVar14 = DAT_00758cec;
    }
    iVar14 = extraout_v1 + iVar14 + 5;
    if (*(int *)(pbVar3 + 0x34) != 0) {
      *(int *)(pbVar3 + 0x34) = iVar14;
    }
    iVar13 = 0;
    uVar2 = 1;
    *pbVar3 = *pbVar3 & 0xfc | 8;
    while (uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 <= uVar4) {
      piVar10 = (int *)(*(int *)(*(int *)(*(int *)(DAT_007cc8ec + uVar11 * 0x1e0 + 0x1d8) + iVar1 +
                                         4) + 0x160) + iVar13);
      if (*piVar10 != 0) {
        *piVar10 = iVar14;
      }
      piVar10[1] = param_3;
      iVar5 = memcmp((void *)((int)piVar10 + 9),&bssid_empty,6);
      if (iVar5 == 0) {
        uVar2 = uVar2 + 1;
        iVar13 = iVar13 + 0x100;
      }
      else {
        stats_db_bssid_del((void *)((int)piVar10 + 9));
        bssid_changed_callback_proc(1,uVar11);
        uVar2 = uVar2 + 1;
        iVar13 = iVar13 + 0x100;
      }
    }
    FUN_00407f30(l_stats_data);
    iVar1 = apmngr_db_get_ap_max();
    if (((int)uVar11 < iVar1) && (uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar12 <= uVar2)) {
      puVar6 = (ushort *)FUN_004082a0(1,4,0xe3d);
      if (puVar6 == (ushort *)0x0) {
        if (stats_err_switch == '\0') {
          return 0;
        }
        printf("[STATISTICS_ERROR]%s()/%d malloc AP_RD_INFO fail\n","stats_db_callback_rd_leave",
               0xe3f);
        return 0;
      }
      *puVar6 = param_1;
      *(byte *)(puVar6 + 1) = param_2;
      iVar1 = FUN_00408340(0,10000,stats_db_callback_rd_leave_async,puVar6,
                           stats_db_callback_rd_leave_arg_free,"stats_db_callback_rd_leave",0xe45);
      if (iVar1 != -1) {
        return 0;
      }
      if (stats_err_switch != '\0') {
        printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","stats_db_callback_rd_leave",
               0xe48);
      }
      FUN_00407df0(puVar6);
      return 0;
    }
    uVar9 = 0;
    if (stats_warning_switch == '\0') {
      return 0;
    }
    pcVar7 = "stats_db_callback_rd_leave";
    uVar8 = 0xe3a;
  }
  else {
    uVar9 = 0xffffffff;
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    pcVar7 = "stats_db_radio_reset";
    uVar8 = 0xe64;
  }
  printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n",pcVar7,uVar8,uVar11,uVar12);
  return uVar9;
}

