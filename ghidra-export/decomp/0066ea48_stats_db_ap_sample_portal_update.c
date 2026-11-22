// func stats_db_ap_sample_portal_update @ 0066ea48 size=244

undefined4 stats_db_ap_sample_portal_update(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    FUN_004082d0(l_stats_data,0xffffffff);
    pbVar5 = (byte *)(DAT_007cc8ec + param_1 * 0x1e0);
    if ((*pbVar5 & 1) != 0) {
      uVar3 = *(uint *)(pbVar5 + 0x54);
      uVar2 = uVar3 + param_2;
      *(uint *)(pbVar5 + 0x54) = uVar2;
      *(uint *)(pbVar5 + 0x50) = (uint)(uVar2 < uVar3) + *(int *)(pbVar5 + 0x50);
      if (*(int *)(pbVar5 + 0x88) == -1) {
        *(uint *)(pbVar5 + 0x88) = param_2;
      }
      else {
        *(uint *)(pbVar5 + 0x88) = param_2 + *(int *)(pbVar5 + 0x88);
      }
    }
    uVar4 = 0;
    FUN_00407f30(l_stats_data);
  }
  else {
    uVar4 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","stats_db_ap_sample_portal_update",
             0xd77,param_1);
    }
  }
  return uVar4;
}

