// func stats_db_ap_for_each_range @ 0066d728 size=964

undefined4 stats_db_ap_for_each_range(code *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined4 extraout_v1;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  uVar1 = 0xffffffff;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if (param_1 != (code *)0x0) {
    iVar11 = 0;
    FUN_0051ad88(&local_38);
    FUN_004082d0(l_stats_data,0xffffffff);
    while (iVar2 = apmngr_db_get_ap_max(), iVar11 < iVar2) {
      FUN_00407e70();
      pbVar9 = (byte *)(DAT_007cc8ec + iVar11 * 0x1e0);
      if (pbVar9 == (byte *)0x0) {
LAB_0066d9c0:
        iVar11 = iVar11 + 1;
      }
      else {
        if (((*pbVar9 & 1) != 0) || (*(int *)(pbVar9 + 4) != 0)) {
          iVar2 = memcmp(&ap_mac_empty,pbVar9 + 0x10,6);
          if (iVar2 != 0) {
            if (stats_debug_switch != '\0') {
              printf("[STATISTICS_DEBUG]%s()/%d %02X-%02X-%02X-%02X-%02X-%02X  cur_time:%d\n",
                     "_stats_ap_copy_to_list",0xb20,(uint)pbVar9[0x10],(uint)pbVar9[0x11],
                     (uint)pbVar9[0x12],(uint)pbVar9[0x13],(uint)pbVar9[0x14],(uint)pbVar9[0x15],
                     extraout_v1);
            }
            iVar2 = FUN_004082a0(1,0x28,0xb23);
            if (iVar2 != 0) {
              memcpy((void *)(iVar2 + 0xc),pbVar9 + 0x10,6);
              *(int *)(iVar2 + 0x14) = iVar11;
              *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(pbVar9 + 8);
              *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(pbVar9 + 4);
              *(byte *)(iVar2 + 0x1c) = *pbVar9;
              if (*(int *)(pbVar9 + 0x1d8) != 0) {
                uVar1 = rdmngr_profile_get_max_rd_per_ap(&local_38);
                iVar3 = FUN_004082a0(uVar1,0xc,0xb2d);
                *(int *)(iVar2 + 0x24) = iVar3;
                if (iVar3 != 0) {
                  iVar3 = 0;
                  iVar10 = 0;
                  for (uVar12 = 1; uVar4 = rdmngr_profile_get_max_rd_per_ap(), uVar12 <= uVar4;
                      uVar12 = uVar12 + 1) {
                    iVar5 = *(int *)(*(int *)(pbVar9 + 0x1d8) + iVar10 + 4);
                    if (iVar5 != 0) {
                      *(undefined4 *)(*(int *)(iVar2 + 0x24) + iVar3 + 4) =
                           *(undefined4 *)(iVar5 + 0x34);
                      *(undefined1 *)(*(int *)(iVar2 + 0x24) + iVar3) =
                           **(undefined1 **)(*(int *)(pbVar9 + 0x1d8) + iVar10 + 4);
                      iVar5 = *(int *)(iVar2 + 0x24);
                      uVar1 = rdmngr_profile_get_max_wlan_per_rd();
                      uVar1 = FUN_004082a0(uVar1,0xc,0xb35);
                      *(undefined4 *)(iVar5 + iVar3 + 8) = uVar1;
                      if ((*(int *)(*(int *)(*(int *)(pbVar9 + 0x1d8) + iVar10 + 4) + 0x160) != 0)
                         && (*(int *)(*(int *)(iVar2 + 0x24) + iVar3 + 8) != 0)) {
                        iVar5 = 0;
                        for (uVar4 = 1; uVar8 = rdmngr_profile_get_max_wlan_per_rd(), uVar4 <= uVar8
                            ; uVar4 = uVar4 + 1) {
                          iVar6 = iVar5 * 0x20;
                          *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x24) + iVar3 + 8) + iVar5 + 4)
                               = *(undefined4 *)
                                  (*(int *)(*(int *)(*(int *)(pbVar9 + 0x1d8) + iVar10 + 4) + 0x160)
                                  + iVar6);
                          puVar7 = (undefined1 *)
                                   (*(int *)(*(int *)(iVar2 + 0x24) + iVar3 + 8) + iVar5);
                          iVar5 = iVar5 + 8;
                          *puVar7 = *(undefined1 *)
                                     (*(int *)(*(int *)(*(int *)(pbVar9 + 0x1d8) + iVar10 + 4) +
                                              0x160) + iVar6 + 8);
                        }
                      }
                    }
                    iVar10 = iVar10 + 8;
                    iVar3 = iVar3 + 0xc;
                  }
                }
              }
              FUN_004086b0(&local_38,iVar2);
            }
          }
          goto LAB_0066d9c0;
        }
        iVar11 = iVar11 + 1;
      }
    }
    FUN_00407f30(l_stats_data);
    iVar11 = FUN_004081b0(&local_38);
    while (uVar1 = 0, iVar11 != 0) {
      iVar2 = FUN_00408680(iVar11);
      (*param_1)(iVar11 + 0xc,param_2);
      if (*(int *)(iVar11 + 0x24) != 0) {
        iVar3 = 0;
        uVar12 = 1;
        while( true ) {
          uVar4 = rdmngr_profile_get_max_rd_per_ap();
          if (uVar4 < uVar12) break;
          uVar12 = uVar12 + 1;
          if (*(int *)(*(int *)(iVar11 + 0x24) + iVar3 + 8) != 0) {
            FUN_00407df0();
            *(undefined4 *)(*(int *)(iVar11 + 0x24) + iVar3 + 8) = 0;
          }
          iVar3 = iVar3 + 0xc;
        }
        FUN_00407df0();
        *(undefined4 *)(iVar11 + 0x24) = 0;
      }
      FUN_00407df0(iVar11);
      iVar11 = iVar2;
    }
  }
  return uVar1;
}

