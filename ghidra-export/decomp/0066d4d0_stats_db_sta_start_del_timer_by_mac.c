// func stats_db_sta_start_del_timer_by_mac @ 0066d4d0 size=164

undefined4 stats_db_sta_start_del_timer_by_mac(int param_1)

{
  int iVar1;
  int extraout_v1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  FUN_00407e70();
  if (param_1 != 0) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_007cc8e0,param_1);
    if (iVar1 != 0) {
      uVar2 = 0;
      *(int *)(iVar1 + 0x40) = stat_sample_report_time + 5 + extraout_v1;
      *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) & 0xfc | 8;
    }
    FUN_00407f30(l_stats_data);
  }
  return uVar2;
}

