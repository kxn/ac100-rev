// func stats_db_radio_sample_mask_check @ 0066a614 size=200

undefined4 stats_db_radio_sample_mask_check(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = DAT_007cc8ec + param_1 * 0x1e0;
    uVar2 = 0xffffffff;
    if ((iVar1 != 0) && ((*(int *)(iVar1 + 8) >> (param_2 & 0x1f) & 1U) != 0)) {
      uVar2 = 0;
    }
    FUN_00407f30(l_stats_data);
  }
  else {
    uVar2 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","stats_db_radio_sample_mask_check",
             0x2d7,param_1);
    }
  }
  return uVar2;
}

