// func _stats_db_ap_radio_stat_init @ 00669de4 size=668

undefined4 _stats_db_ap_radio_stat_init(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar8 = 1;
  if ((param_1 != 0) && (uVar8 = 0, *(int *)(param_1 + 0xc) != 0)) {
    uVar9 = (uint)*(ushort *)(param_1 + 0x10);
    iVar1 = apmngr_db_get_ap_max();
    if ((int)uVar9 < iVar1) {
      uVar2 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
      if ((uVar2 == 0xffffffff) || (uVar3 = rdmngr_profile_get_max_rd_per_ap(), uVar3 < uVar2)) {
        uVar8 = 0;
        if (stats_warning_switch != '\0') {
          pcVar6 = "[STATISTICS_WARNING]%s()/%d apdb_radio_count_by_id() fail or rd_cnt exceeds.\n";
          uVar5 = 0x580;
LAB_00669f50:
          printf(pcVar6,"_stats_db_ap_radio_stat_init",uVar5);
        }
      }
      else {
        iVar10 = uVar9 * 0x1e0;
        iVar1 = 0;
        for (iVar11 = 1; iVar11 <= (int)uVar2; iVar11 = iVar11 + 1) {
          pcVar6 = (char *)(*(int *)(DAT_007cc8ec + iVar10 + 0x1d8) + iVar1);
          if ((*pcVar6 == '\0') && (*(int *)(pcVar6 + 4) == 0)) {
            uVar8 = FUN_004082a0(1,0x168,0x588);
            *(undefined4 *)(pcVar6 + 4) = uVar8;
            iVar7 = DAT_007cc8ec + iVar10;
            if (*(int *)(*(int *)(iVar7 + 0x1d8) + iVar1 + 4) == 0) {
              uVar8 = 1;
              if (stats_err_switch == '\0') {
                return 1;
              }
              pcVar6 = "[STATISTICS_ERROR]%s()/%d No memory left\n";
              uVar5 = 0x58b;
              goto LAB_00669f50;
            }
            reset_stats_db_rd_sample();
            iVar7 = *(int *)(*(int *)(iVar7 + 0x1d8) + iVar1 + 4);
            uVar8 = rdmngr_profile_get_max_wlan_per_rd();
            uVar8 = FUN_004082a0(uVar8,0x100,0x592);
            *(undefined4 *)(iVar7 + 0x160) = uVar8;
            if (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar10 + 0x1d8) + iVar1 + 4) + 0x160) == 0
               ) {
              FUN_00407df0();
              *(undefined4 *)(*(int *)(DAT_007cc8ec + iVar10 + 0x1d8) + iVar1 + 4) = 0;
              return 1;
            }
            iVar7 = 0;
            uVar9 = 1;
            while (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), uVar9 <= uVar3) {
              iVar4 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar10 + 0x1d8) + iVar1 + 4) + 0x160
                              ) + iVar7;
              uVar9 = uVar9 + 1;
              if (iVar4 != 0) {
                *(undefined1 *)(iVar4 + 0x48) = 0;
                *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
                *(undefined4 *)(iVar4 + 0x18) = 0xffffffff;
                *(undefined4 *)(iVar4 + 0x58) = 0xffffffff;
                *(undefined4 *)(iVar4 + 0x5c) = 0xffffffff;
              }
              iVar7 = iVar7 + 0x100;
            }
          }
          iVar1 = iVar1 + 8;
        }
        uVar8 = 0;
      }
    }
    else {
      uVar8 = 1;
      if (stats_warning_switch != '\0') {
        printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","_stats_db_ap_radio_stat_init",0x579,
               uVar9);
      }
    }
  }
  return uVar8;
}

