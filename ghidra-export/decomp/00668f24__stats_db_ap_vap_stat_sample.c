// func _stats_db_ap_vap_stat_sample @ 00668f24 size=980

undefined4 _stats_db_ap_vap_stat_sample(int param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  uVar12 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    uVar3 = *param_2;
    uVar9 = param_2[1];
    uVar12 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar14 = (uint)*(ushort *)(param_1 + 0x10);
      iVar4 = apmngr_db_get_ap_max();
      if ((int)uVar14 < iVar4) {
        uVar5 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
        if ((uVar5 == 0xffffffff) || (uVar6 = rdmngr_profile_get_max_rd_per_ap(), uVar6 < uVar5)) {
          uVar12 = 0;
          if (stats_warning_switch != '\0') {
            printf("[STATISTICS_WARNING]%s()/%d apdb_radio_count_by_id() fail or rd_cnt exceeds.\n",
                   "_stats_db_ap_vap_stat_sample",0x426);
          }
        }
        else {
          iVar4 = 0;
          for (uVar6 = 1; uVar12 = 0, (int)uVar6 <= (int)uVar5; uVar6 = uVar6 + 1) {
            if (*(int *)(*(int *)(DAT_007cc8ec + uVar14 * 0x1e0 + 0x1d8) + iVar4 + 4) != 0) {
              iVar15 = 0;
              uVar13 = 1;
              while (uVar7 = rdmngr_profile_get_max_wlan_per_rd(), uVar13 <= uVar7) {
                iVar8 = apmngr_db_get_ap_max();
                if (((((int)uVar14 < iVar8) && (0 < (int)uVar6)) &&
                    (uVar7 = rdmngr_profile_get_max_rd_per_ap(), uVar6 <= uVar7)) &&
                   ((0 < (int)uVar13 &&
                    (uVar7 = rdmngr_profile_get_max_wlan_per_rd(), uVar13 <= uVar7)))) {
                  FUN_004082d0(l_stats_data,0xffffffff);
                  iVar8 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + uVar14 * 0x1e0 + 0x1d8) + iVar4
                                           + 4) + 0x160) + iVar15;
                  if ((iVar8 != 0) && ((*(byte *)(iVar8 + 8) & 0x18) == 0x10)) {
                    if (9 < *(byte *)(iVar8 + 0x48)) {
                      memcpy((void *)(iVar8 + 0x60),(void *)(iVar8 + 100),0x24);
                      memcpy((void *)(iVar8 + 0x88),(void *)(iVar8 + 0x8c),0x24);
                      memcpy((void *)(iVar8 + 0xb0),(void *)(iVar8 + 0xb4),0x24);
                      memcpy((void *)(iVar8 + 0xd8),(void *)(iVar8 + 0xdc),0x24);
                      *(undefined1 *)(iVar8 + 0x48) = 9;
                    }
                    bVar1 = *(byte *)(iVar8 + 8);
                    bVar2 = *(byte *)(iVar8 + 0x48);
                    uVar7 = (uint)bVar2;
                    if ((bVar1 & 4) == 0) {
                      *(undefined4 *)(iVar8 + 0x58) = 0xffffffff;
                      *(undefined4 *)(iVar8 + 0x5c) = 0xffffffff;
                      *(undefined4 *)(iVar8 + (uVar7 + 0x2c) * 4) = 0xffffffff;
                      *(undefined4 *)(iVar8 + (uVar7 + 0x36) * 4) = 0xffffffff;
                      *(undefined4 *)(iVar8 + (uVar7 + 0x18) * 4) = 0xffffffff;
                      *(undefined4 *)(iVar8 + (uVar7 + 0x22) * 4) = 0xffffffff;
                    }
                    else {
                      uVar11 = *(uint *)(iVar8 + 0x14);
                      uVar10 = uVar11 >> 3;
                      if (uVar11 < 8) {
                        uVar10 = (uint)(uVar11 != 0);
                      }
                      *(uint *)(iVar8 + (uVar7 + 0x18) * 4) = uVar10;
                      uVar11 = *(uint *)(iVar8 + 0x18);
                      uVar10 = uVar11 >> 3;
                      if (uVar11 < 8) {
                        uVar10 = (uint)(uVar11 != 0);
                      }
                      *(uint *)(iVar8 + (uVar7 + 0x22) * 4) = uVar10;
                      *(undefined4 *)(iVar8 + (uVar7 + 0x2c) * 4) = *(undefined4 *)(iVar8 + 0x58);
                      *(undefined4 *)(iVar8 + 0x58) = 0xffffffff;
                      *(undefined4 *)(iVar8 + (uVar7 + 0x36) * 4) = *(undefined4 *)(iVar8 + 0x5c);
                      *(undefined4 *)(iVar8 + 0x5c) = 0xffffffff;
                    }
                    *(byte *)(iVar8 + 0x48) = bVar2 + 1;
                    *(byte *)(iVar8 + 8) = bVar1 & 0xfb;
                    *(undefined4 *)(iVar8 + 0x54) = uVar9;
                    *(undefined4 *)(iVar8 + 0x50) = uVar3;
                  }
                  FUN_00407f30(l_stats_data);
LAB_00669110:
                  uVar13 = uVar13 + 1;
                  iVar15 = iVar15 + 0x100;
                }
                else {
                  if (stats_warning_switch != '\0') {
                    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n",
                           "stats_db_ssid_sample",0x3af,uVar14,uVar6,uVar13);
                    goto LAB_00669110;
                  }
                  uVar13 = uVar13 + 1;
                  iVar15 = iVar15 + 0x100;
                }
              }
            }
            iVar4 = iVar4 + 8;
          }
        }
      }
      else {
        uVar12 = 0xffffffff;
        if (stats_warning_switch != '\0') {
          printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","_stats_db_ap_vap_stat_sample",
                 0x41f,uVar14);
        }
      }
    }
  }
  return uVar12;
}

