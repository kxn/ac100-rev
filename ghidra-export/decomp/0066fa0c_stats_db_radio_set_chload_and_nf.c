// func stats_db_radio_set_chload_and_nf @ 0066fa0c size=304

undefined4
stats_db_radio_set_chload_and_nf(uint param_1,uint param_2,byte param_3,undefined1 param_4)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xff;
  iVar1 = apmngr_db_get_ap_max();
  if ((((int)param_1 < iVar1) && (param_2 != 0)) &&
     (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
    iVar1 = (param_2 - 1) * 8;
    FUN_004082d0(l_stats_data,0xffffffff);
    pbVar3 = *(byte **)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + iVar1 + 4);
    if ((pbVar3 != (byte *)0x0) && ((*pbVar3 & 3) == 3)) {
      pbVar3[0x11] = param_3;
      *(undefined1 *)(*(int *)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + iVar1 + 4) + 0x10)
           = param_4;
    }
    uVar4 = 0;
    FUN_00407f30(l_stats_data);
  }
  else {
    uVar4 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n","stats_db_radio_set_chload_and_nf",
             0xf9d,param_1,param_2);
    }
  }
  return uVar4;
}

