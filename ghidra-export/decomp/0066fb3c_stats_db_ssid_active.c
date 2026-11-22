// func stats_db_ssid_active @ 0066fb3c size=588

undefined4 stats_db_ssid_active(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  param_1 = param_1 & 0xffff;
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xff;
  iVar1 = apmngr_db_get_ap_max();
  if (((((int)param_1 < iVar1) && (param_2 != 0)) &&
      (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) &&
     ((param_3 != 0 && (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), param_3 <= uVar2)))) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar3 = param_1 * 0x1e0;
    iVar1 = (param_2 - 1) * 8;
    pbVar4 = *(byte **)(*(int *)((byte *)(DAT_007cc8ec + iVar3) + 0x1d8) + iVar1 + 4);
    if (pbVar4 == (byte *)0x0) {
      if (stats_warning_switch != '\0') {
        printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_ssid_active",0x1038,
               param_1,param_2,param_3);
      }
      uVar7 = 0xffffffff;
      FUN_00407f30(l_stats_data);
    }
    else {
      if (((*(byte *)(DAT_007cc8ec + iVar3) & 1) != 0) && ((*pbVar4 & 1) != 0)) {
        iVar6 = (param_3 - 1) * 0x100;
        *(byte *)(*(int *)(pbVar4 + 0x160) + iVar6 + 8) =
             *(byte *)(*(int *)(pbVar4 + 0x160) + iVar6 + 8) | 1;
        iVar5 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar3 + 0x1d8) + iVar1 + 4) + 0x160) +
                iVar6;
        *(byte *)(iVar5 + 8) = *(byte *)(iVar5 + 8) & 0xf7;
        *(undefined4 *)
         (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar3 + 0x1d8) + iVar1 + 4) + 0x160) + iVar6 + 4
         ) = 0;
        *(undefined4 *)
         (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar3 + 0x1d8) + iVar1 + 4) + 0x160) + iVar6) =
             0;
        iVar6 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar3 + 0x1d8) + iVar1 + 4) + 0x160) +
                iVar6;
        if ((*(int *)(iVar6 + 0x50) == *(int *)(iVar6 + 0x40)) &&
           (*(int *)(iVar6 + 0x54) == *(int *)(iVar6 + 0x44))) {
          uVar8 = FUN_00524078(l_stats_data);
          *(undefined8 *)(iVar6 + 0x40) = uVar8;
        }
      }
      uVar7 = 0;
      FUN_00407f30(l_stats_data);
    }
  }
  else {
    uVar7 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_ssid_active",0x1030,
             param_1,param_2,param_3);
    }
  }
  return uVar7;
}

