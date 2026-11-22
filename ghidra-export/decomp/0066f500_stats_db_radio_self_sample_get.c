// func stats_db_radio_self_sample_get @ 0066f500 size=1

undefined4 stats_db_radio_self_sample_get(uint param_1,uint param_2,byte *param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xff;
  iVar1 = apmngr_db_get_ap_max();
  if ((((int)param_1 < iVar1) && (param_2 != 0)) &&
     (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
    if (param_3 != (byte *)0x0) {
      iVar1 = (param_2 - 1) * 8;
      FUN_004082d0(l_stats_data,0xffffffff);
      iVar5 = param_1 * 0x1e0;
      pbVar3 = *(byte **)(*(int *)(DAT_007cc8ec + iVar5 + 0x1d8) + iVar1 + 4);
      uVar4 = 1;
      if ((pbVar3 != (byte *)0x0) && ((*pbVar3 & 1) != 0)) {
        uVar4 = 0;
        *param_3 = pbVar3[0x48];
        *(undefined4 *)(param_3 + 4) =
             *(undefined4 *)(*(int *)(*(int *)(DAT_007cc8ec + iVar5 + 0x1d8) + iVar1 + 4) + 0x4c);
        memcpy(param_3 + 8,
               (void *)(*(int *)(*(int *)(DAT_007cc8ec + iVar5 + 0x1d8) + iVar1 + 4) + 0x50),10);
      }
      FUN_00407f30(l_stats_data);
      return uVar4;
    }
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_radio_self_sample_get",0xf1e);
      return 0xffffffff;
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n","stats_db_radio_self_sample_get",0xf18
           ,param_1,param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

