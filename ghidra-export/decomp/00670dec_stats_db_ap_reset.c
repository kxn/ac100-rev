// func stats_db_ap_reset @ 00670dec size=724

undefined4 stats_db_ap_reset(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int extraout_v1;
  int extraout_v1_00;
  int extraout_v1_01;
  char *__format;
  undefined4 uVar5;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  param_2 = param_2 & 0xff;
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    uVar2 = rdmngr_profile_get_max_rd_per_ap();
    if (param_2 <= uVar2) {
      iVar11 = param_1 * 0x1e0;
      FUN_004082d0(l_stats_data,0xffffffff);
      pbVar6 = (byte *)(DAT_007cc8ec + iVar11);
      *pbVar6 = *pbVar6 & 0xfc | 8;
      iVar1 = DAT_00758cf0;
      if (DAT_00758cf0 <= DAT_00758ce8) {
        iVar1 = DAT_00758ce8;
      }
      if (iVar1 < DAT_00758cec) {
        iVar1 = DAT_00758cec;
      }
      iVar1 = iVar1 + 5;
      if (*(int *)(pbVar6 + 4) == 0) {
        FUN_00407e70();
        *(int *)(pbVar6 + 4) = iVar1 + extraout_v1_01;
      }
      iVar8 = 0;
      iVar10 = 1;
      *(int *)(pbVar6 + 0xc) = param_3;
      do {
        if ((int)param_2 < iVar10) {
          FUN_00407f30(l_stats_data);
          return 0;
        }
        pbVar6 = *(byte **)(*(int *)(DAT_007cc8ec + iVar11 + 0x1d8) + iVar8 + 4);
        if (pbVar6 != (byte *)0x0) {
          *pbVar6 = *pbVar6 & 0xfc | 8;
          if (*(int *)(pbVar6 + 0x34) == 0) {
            FUN_00407e70();
            *(int *)(pbVar6 + 0x34) = iVar1 + extraout_v1_00;
          }
          iVar9 = 0;
          uVar2 = 1;
          *(int *)(pbVar6 + 0x38) = param_3;
          while (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 <= uVar3) {
            piVar7 = (int *)(*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar11 + 0x1d8) + iVar8 + 4)
                                     + 0x160) + iVar9);
            if (piVar7 == (int *)0x0) {
LAB_0067103c:
              uVar2 = uVar2 + 1;
              iVar9 = iVar9 + 0x100;
            }
            else {
              *(byte *)(piVar7 + 2) = *(byte *)(piVar7 + 2) & 0xfc | 8;
              piVar7[1] = param_3;
              if (*piVar7 == 0) {
                FUN_00407e70();
                *piVar7 = iVar1 + extraout_v1;
              }
              iVar4 = memcmp((void *)((int)piVar7 + 9),&bssid_empty,6);
              if (iVar4 == 0) goto LAB_0067103c;
              stats_db_bssid_del((void *)((int)piVar7 + 9));
              bssid_changed_callback_proc(1,param_1);
              uVar2 = uVar2 + 1;
              iVar9 = iVar9 + 0x100;
            }
          }
        }
        iVar10 = iVar10 + 1;
        iVar8 = iVar8 + 8;
      } while( true );
    }
    if (stats_err_switch != '\0') {
      __format = "[STATISTICS_ERROR]%s()/%d radio cnt out of range[%u]\n";
      uVar5 = 0xc9c;
      goto LAB_00670ed0;
    }
  }
  else if (stats_warning_switch != '\0') {
    __format = "[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n";
    uVar5 = 0xc97;
    param_2 = param_1;
LAB_00670ed0:
    printf(__format,"stats_db_ap_reset",uVar5,param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

