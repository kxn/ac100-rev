// func _stats_db_ap_radio_stat_sample @ 0066965c size=1488

undefined4 _stats_db_ap_radio_stat_sample(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  undefined1 auStack_98 [26];
  ushort local_7e;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar9 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    local_30 = *param_2;
    local_2c = param_2[1];
    uVar9 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar11 = (uint)*(ushort *)(param_1 + 0x10);
      iVar1 = apmngr_db_get_ap_max();
      if ((int)uVar11 < iVar1) {
        uVar2 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
        if ((uVar2 == 0xffffffff) || (uVar3 = rdmngr_profile_get_max_rd_per_ap(), uVar3 < uVar2)) {
          uVar9 = 0;
          if (stats_warning_switch != '\0') {
            printf("[STATISTICS_WARNING]%s()/%d apdb_radio_count_by_id() fail or rd_cnt exceeds.\n",
                   "_stats_db_ap_radio_stat_sample",0x3fb);
          }
        }
        else {
          local_40 = 0;
          local_3c = uVar11 * 0x1e0;
          for (uVar3 = 1; uVar9 = 0, (int)uVar3 <= (int)uVar2; uVar3 = uVar3 + 1) {
            if (*(int *)(*(int *)(DAT_007cc8ec + local_3c + 0x1d8) + local_40 + 4) != 0) {
              uVar12 = uVar3 & 0xff;
              memset(auStack_98,0,0x54);
              iVar1 = apmngr_db_get_ap_max();
              if ((((int)uVar11 < iVar1) && (uVar12 != 0)) &&
                 (uVar4 = rdmngr_profile_get_max_rd_per_ap(), uVar12 <= uVar4)) {
                memset(auStack_98,0,0x54);
                uVar9 = rdmngr_db_generate_rd_id(uVar11,uVar12);
                iVar1 = rdmngr_db_rd_entry_get(uVar9,auStack_98);
                uVar9 = rdmngr_db_generate_rd_id(uVar11,uVar12);
                local_38 = rdmngr_db_get_rd_freq_band(uVar9);
                FUN_004082d0(l_stats_data,0xffffffff);
                pbVar10 = *(byte **)(*(int *)(DAT_007cc8ec + local_3c + 0x1d8) + (uVar12 - 1) * 8 +
                                    4);
                if ((pbVar10 != (byte *)0x0) && (bVar6 = *pbVar10, (bVar6 & 8) == 0)) {
                  if (iVar1 == -1) {
                    if ((bVar6 & 0x10) != 0) {
                      bVar6 = pbVar10[100];
LAB_00669920:
                      if (9 < bVar6) {
                        memcpy(pbVar10 + 0x78,pbVar10 + 0x7c,0x24);
                        memcpy(pbVar10 + 0xa0,pbVar10 + 0xa4,0x24);
                        memcpy(pbVar10 + 200,pbVar10 + 0xcc,0x24);
                        memcpy(pbVar10 + 0xf0,pbVar10 + 0xf4,0x24);
                        memcpy(pbVar10 + 0x118,pbVar10 + 0x119,9);
                        memcpy(pbVar10 + 0x122,pbVar10 + 0x123,9);
                        memcpy(pbVar10 + 300,pbVar10 + 0x12d,9);
                        memcpy(pbVar10 + 0x136,pbVar10 + 0x137,9);
                        memcpy(pbVar10 + 0x140,pbVar10 + 0x141,9);
                        memcpy(pbVar10 + 0x14a,pbVar10 + 0x14b,9);
                        memcpy(pbVar10 + 0x154,pbVar10 + 0x155,9);
                        memcpy(pbVar10 + 0x50,pbVar10 + 0x51,9);
                        memcpy(pbVar10 + 0x5a,pbVar10 + 0x5b,9);
                        memcpy(pbVar10 + 0x50,pbVar10 + 0x51,9);
                        memcpy(pbVar10 + 0x5a,pbVar10 + 0x5b,9);
                        pbVar10[100] = 9;
                      }
                      bVar6 = *pbVar10;
                      uVar4 = (uint)pbVar10[100];
                      iVar1 = uVar4 + 0x1e;
                      if ((bVar6 & 4) == 0) {
                        pbVar8 = pbVar10 + iVar1 * 4;
                        pbVar8[0] = 0xff;
                        pbVar8[1] = 0xff;
                        pbVar8[2] = 0xff;
                        pbVar8[3] = 0xff;
                        pbVar8 = pbVar10 + (uVar4 + 0x28) * 4;
                        pbVar8[0] = 0xff;
                        pbVar8[1] = 0xff;
                        pbVar8[2] = 0xff;
                        pbVar8[3] = 0xff;
                        pbVar10[0x70] = 0xff;
                        pbVar10[0x71] = 0xff;
                        pbVar10[0x72] = 0xff;
                        pbVar10[0x73] = 0xff;
                        pbVar10[0x74] = 0xff;
                        pbVar10[0x75] = 0xff;
                        pbVar10[0x76] = 0xff;
                        pbVar10[0x77] = 0xff;
                        pbVar8 = pbVar10 + (uVar4 + 0x32) * 4;
                        pbVar8[0] = 0xff;
                        pbVar8[1] = 0xff;
                        pbVar8[2] = 0xff;
                        pbVar8[3] = 0xff;
                        pbVar8 = pbVar10 + (uVar4 + 0x3c) * 4;
                        pbVar8[0] = 0xff;
                        pbVar8[1] = 0xff;
                        pbVar8[2] = 0xff;
                        pbVar8[3] = 0xff;
                        pbVar10[uVar4 + 0x118] = 0xff;
                        pbVar10[uVar4 + 0x122] = 0xff;
                        pbVar10[uVar4 + 300] = 0xff;
                        pbVar10[uVar4 + 0x136] = 0xff;
                        pbVar10[uVar4 + 0x140] = 0xff;
                        pbVar10[uVar4 + 0x14a] = 0xff;
                        pbVar10[uVar4 + 0x154] = 0x7f;
                        if (local_38 != -1) {
                          *(int *)(pbVar10 + 4) = local_38;
                        }
                      }
                      else {
                        uVar5 = *(uint *)(pbVar10 + 0x14);
                        if (uVar5 == 0xffffffff) {
                          pbVar8 = pbVar10 + iVar1 * 4;
                          pbVar8[0] = 0xff;
                          pbVar8[1] = 0xff;
                          pbVar8[2] = 0xff;
                          pbVar8[3] = 0xff;
                        }
                        else {
                          uVar7 = uVar5 >> 3;
                          if (uVar5 < 8) {
                            uVar7 = (uint)(uVar5 != 0);
                          }
                          *(uint *)(pbVar10 + iVar1 * 4) = uVar7;
                        }
                        uVar5 = *(uint *)(pbVar10 + 0x18);
                        if (uVar5 == 0xffffffff) {
                          pbVar8 = pbVar10 + (uVar4 + 0x28) * 4;
                          pbVar8[0] = 0xff;
                          pbVar8[1] = 0xff;
                          pbVar8[2] = 0xff;
                          pbVar8[3] = 0xff;
                        }
                        else {
                          uVar7 = uVar5 >> 3;
                          if (uVar5 < 8) {
                            uVar7 = (uint)(uVar5 != 0);
                          }
                          *(uint *)(pbVar10 + (uVar4 + 0x28) * 4) = uVar7;
                        }
                        *(undefined4 *)(pbVar10 + (uVar4 + 0x32) * 4) =
                             *(undefined4 *)(pbVar10 + 0x70);
                        pbVar10[0x70] = 0xff;
                        pbVar10[0x71] = 0xff;
                        pbVar10[0x72] = 0xff;
                        pbVar10[0x73] = 0xff;
                        *(undefined4 *)(pbVar10 + (uVar4 + 0x3c) * 4) =
                             *(undefined4 *)(pbVar10 + 0x74);
                        pbVar10[0x74] = 0xff;
                        pbVar10[0x75] = 0xff;
                        pbVar10[0x76] = 0xff;
                        pbVar10[0x77] = 0xff;
                        pbVar10[uVar4 + 0x118] = pbVar10[0x11];
                        pbVar10[uVar4 + 0x122] = pbVar10[0x31];
                        pbVar10[uVar4 + 300] = pbVar10[0x32];
                        pbVar10[uVar4 + 0x136] = pbVar10[0x12];
                        pbVar10[uVar4 + 0x140] = pbVar10[0x30];
                        pbVar10[uVar4 + 0x14a] = pbVar10[0x33];
                        pbVar10[uVar4 + 0x154] = pbVar10[0x10];
                        *pbVar10 = bVar6 & 0xfb;
                      }
                      bVar6 = wsta_db_get_rd_sta_num(uVar11,uVar12);
                      pbVar10[uVar4 + 0x50] = bVar6;
                      uVar12 = (uint)local_7e;
                      if (uVar12 == 0) {
                        bVar6 = 0xff;
                      }
                      else {
                        if (uVar12 == 0) {
                          trap(7);
                        }
                        uVar12 = ((uint)bVar6 * 100) / uVar12;
                        bVar6 = (byte)uVar12;
                        pbVar10[uVar4 + 0x5a] = bVar6;
                        if (100 < (uVar12 & 0xff)) {
                          bVar6 = 100;
                        }
                      }
                      pbVar10[uVar4 + 0x5a] = bVar6;
                      *(undefined4 *)(pbVar10 + 0x6c) = local_2c;
                      pbVar10[100] = pbVar10[100] + 1;
                      *(undefined4 *)(pbVar10 + 0x68) = local_30;
                    }
                  }
                  else if (bVar6 != 0) {
                    bVar6 = pbVar10[100];
                    goto LAB_00669920;
                  }
                }
                FUN_00407f30(l_stats_data);
              }
              else if (stats_warning_switch != '\0') {
                printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n","stats_db_radio_sample",
                       0x338,uVar11,uVar12);
              }
            }
            local_40 = local_40 + 8;
          }
        }
      }
      else {
        uVar9 = 0xffffffff;
        if (stats_warning_switch != '\0') {
          printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","_stats_db_ap_radio_stat_sample",
                 0x3f4,uVar11);
        }
      }
    }
  }
  return uVar9;
}

