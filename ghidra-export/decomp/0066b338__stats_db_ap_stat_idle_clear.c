// func _stats_db_ap_stat_idle_clear @ 0066b338 size=1088

undefined4 _stats_db_ap_stat_idle_clear(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_v1;
  char *__format;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  
  FUN_00407e70();
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0;
  }
  if ((*(ushort *)(param_1 + 0x28) & 5) != 0) {
    return 0;
  }
  if ((*(ushort *)(param_1 + 0x28) & 2) != 0) {
    return 0;
  }
  uVar2 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
  if (uVar2 == 0xffffffff) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_WARNING]%s()/%d apdb_radio_count_by_id() fail.\n",
           "_stats_db_ap_stat_idle_clear",0x601);
    return 0xffffffff;
  }
  uVar1 = *(ushort *)(param_1 + 0x10);
  iVar3 = apmngr_db_get_ap_max();
  if (iVar3 <= (int)(uint)uVar1) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    uVar2 = (uint)*(ushort *)(param_1 + 0x10);
    __format = "[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n";
    uVar9 = 0x606;
LAB_0066b44c:
    printf(__format,"_stats_db_ap_stat_idle_clear",uVar9,uVar2);
    return 0xffffffff;
  }
  uVar4 = rdmngr_profile_get_max_rd_per_ap();
  if (uVar4 < uVar2) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[STATISTICS_ERROR]%s()/%d radio cnt out of range[%u]\n";
    uVar9 = 0x60b;
    goto LAB_0066b44c;
  }
  FUN_004082d0(l_stats_data,0xffffffff);
  puVar10 = (undefined1 *)(DAT_007cc8ec + (uint)*(ushort *)(param_1 + 0x10) * 0x1e0);
  iVar3 = 0;
  if (extraout_v1 < *(uint *)(puVar10 + 4)) {
    iVar12 = 1;
  }
  else {
    iVar12 = 1;
    if (*(uint *)(puVar10 + 4) != 0) {
      if (*(int *)(puVar10 + 0xc) != 0) {
        puVar10[0x10] = 0;
        puVar10[0x11] = 0;
        puVar10[0x12] = 0;
        puVar10[0x13] = 0;
        puVar10[0x14] = 0;
        puVar10[0x15] = 0;
      }
      *(undefined4 *)(puVar10 + 4) = 0;
      *puVar10 = 0;
      if (*(int *)(puVar10 + 0xc) == 0) {
        *(undefined4 *)(puVar10 + 0x60) = 0;
        puVar10[0x18] = 0;
        memset(puVar10 + 0x19,0,8);
        puVar10[0x21] = 0;
        memset(puVar10 + 0x70,0,0x168);
      }
      else {
        memset(puVar10 + 0x18,0,0x1c0);
        *(undefined4 *)(puVar10 + 0x74) = 0xffffffff;
        *(undefined4 *)(puVar10 + 0x78) = 0xffffffff;
        *(undefined4 *)(puVar10 + 0x7c) = 0xffffffff;
        *(undefined4 *)(puVar10 + 0x80) = 0xffffffff;
        *(undefined4 *)(puVar10 + 0x84) = 0xffffffff;
      }
      iVar3 = 0;
      *(undefined4 *)(puVar10 + 8) = 0;
      puVar10[0x16] = 0;
      for (iVar12 = 1; iVar12 <= (int)uVar2; iVar12 = iVar12 + 1) {
        if (*(int *)(*(int *)(DAT_007cc8ec + (uint)*(ushort *)(param_1 + 0x10) * 0x1e0 + 0x1d8) +
                     iVar3 + 4) != 0) {
          iVar11 = 0;
          reset_ap_rd_sample(*(undefined4 *)(puVar10 + 0xc),(uint)*(ushort *)(param_1 + 0x10),iVar12
                            );
          for (uVar4 = 1; uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar4 <= uVar5;
              uVar4 = uVar4 + 1) {
            iVar6 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec +
                                               (uint)*(ushort *)(param_1 + 0x10) * 0x1e0 + 0x1d8) +
                                      iVar3 + 4) + 0x160) + iVar11;
            iVar11 = iVar11 + 0x100;
            reset_ap_rd_ssid_sample(*(undefined4 *)(puVar10 + 0xc),iVar6);
          }
        }
        iVar3 = iVar3 + 8;
      }
      goto LAB_0066b5d8;
    }
  }
  for (; iVar12 <= (int)uVar2; iVar12 = iVar12 + 1) {
    iVar11 = 0;
    iVar6 = *(int *)(*(int *)(DAT_007cc8ec + (uint)*(ushort *)(param_1 + 0x10) * 0x1e0 + 0x1d8) +
                     iVar3 + 4);
    uVar4 = 1;
    if (((iVar6 == 0) || (extraout_v1 < *(uint *)(iVar6 + 0x34))) || (*(uint *)(iVar6 + 0x34) == 0))
    {
      while (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar4 <= uVar5) {
        puVar8 = (uint *)(*(int *)(*(int *)(*(int *)(DAT_007cc8ec +
                                                     (uint)*(ushort *)(param_1 + 0x10) * 0x1e0 +
                                                    0x1d8) + iVar3 + 4) + 0x160) + iVar11);
        if ((puVar8 == (uint *)0x0) || (uVar5 = *puVar8, extraout_v1 < uVar5)) {
LAB_0066b6bc:
          uVar4 = uVar4 + 1;
          iVar11 = iVar11 + 0x100;
        }
        else {
          if (uVar5 != 0) {
            reset_ap_rd_ssid_sample(*(undefined4 *)(puVar10 + 0xc));
            goto LAB_0066b6bc;
          }
          uVar4 = uVar4 + 1;
          iVar11 = iVar11 + 0x100;
        }
      }
    }
    else {
      while( true ) {
        uVar5 = rdmngr_profile_get_max_wlan_per_rd();
        if (uVar5 < uVar4) break;
        uVar4 = uVar4 + 1;
        iVar7 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + (uint)*(ushort *)(param_1 + 0x10) * 0x1e0
                                          + 0x1d8) + iVar3 + 4) + 0x160) + iVar11;
        iVar11 = iVar11 + 0x100;
        reset_ap_rd_ssid_sample(*(undefined4 *)(puVar10 + 0xc),iVar7);
      }
      reset_ap_rd_sample(*(undefined4 *)(puVar10 + 0xc),(uint)*(ushort *)(param_1 + 0x10),iVar12,
                         iVar6);
    }
    iVar3 = iVar3 + 8;
  }
LAB_0066b5d8:
  FUN_00407f30(l_stats_data);
  return 0;
}

