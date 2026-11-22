// func stats_db_radio_active @ 0066ef38 size=736

undefined4 stats_db_radio_active(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 uVar10;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xff;
  uVar10 = FUN_00524078();
  iVar1 = apmngr_db_get_ap_max();
  if ((((int)param_1 < iVar1) && (param_2 != 0)) &&
     (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
    iVar1 = param_1 * 0x1e0;
    FUN_004082d0(l_stats_data,0xffffffff);
    if ((*(byte *)(DAT_007cc8ec + iVar1) & 1) != 0) {
      iVar7 = (param_2 - 1) * 8;
      pbVar6 = *(byte **)(*(int *)((byte *)(DAT_007cc8ec + iVar1) + 0x1d8) + iVar7 + 4);
      if (pbVar6 != (byte *)0x0) {
        *pbVar6 = *pbVar6 | 1;
        pbVar6 = *(byte **)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar7 + 4);
        *pbVar6 = *pbVar6 & 0xf7;
        iVar3 = DAT_007cc8ec + iVar1;
        *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x1d8) + iVar7 + 4) + 0x38) = 0;
        *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x1d8) + iVar7 + 4) + 0x34) = 0;
        iVar3 = *(int *)(*(int *)(iVar3 + 0x1d8) + iVar7 + 4);
        if ((*(int *)(iVar3 + 0x68) == *(int *)(iVar3 + 0x40)) &&
           (*(int *)(iVar3 + 0x6c) == *(int *)(iVar3 + 0x44))) {
          *(undefined8 *)(iVar3 + 0x40) = uVar10;
        }
        if (param_3 != 0) {
          iVar9 = 0;
          iVar3 = l_stats_data;
          uVar2 = 1;
          while (uVar4 = rdmngr_profile_get_max_wlan_per_rd(iVar3), uVar2 <= uVar4) {
            iVar3 = l_stats_data;
            if (*(char *)(param_3 + uVar2 + -1) == '\0') {
LAB_0066f1c0:
              iVar9 = iVar9 + 0x100;
              uVar2 = uVar2 + 1;
            }
            else {
              iVar3 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar7 + 4) + 0x160)
                      + iVar9;
              *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) | 1;
              iVar3 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar7 + 4) + 0x160)
                      + iVar9;
              *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) & 0xf7;
              *(undefined4 *)
               (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar7 + 4) + 0x160) +
                iVar9 + 4) = 0;
              *(undefined4 *)
               (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar7 + 4) + 0x160) +
               iVar9) = 0;
              iVar5 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar1 + 0x1d8) + iVar7 + 4) + 0x160)
                      + iVar9;
              iVar3 = *(int *)(iVar5 + 0x50);
              if (*(int *)(iVar5 + 0x50) != *(int *)(iVar5 + 0x40)) goto LAB_0066f1c0;
              iVar3 = *(int *)(iVar5 + 0x54);
              if (*(int *)(iVar5 + 0x54) != *(int *)(iVar5 + 0x44)) goto LAB_0066f1c0;
              iVar9 = iVar9 + 0x100;
              *(undefined8 *)(iVar5 + 0x40) = uVar10;
              iVar3 = (int)((ulonglong)uVar10 >> 0x20);
              uVar2 = uVar2 + 1;
            }
          }
        }
      }
    }
    uVar8 = 0;
    FUN_00407f30(l_stats_data);
  }
  else {
    uVar8 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n","stats_db_radio_active",0xe9e,
             param_1,param_2);
    }
  }
  return uVar8;
}

