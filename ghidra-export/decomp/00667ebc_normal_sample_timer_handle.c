// func normal_sample_timer_handle @ 00667ebc size=844

undefined4 normal_sample_timer_handle(uint param_1)

{
  bool bVar1;
  int extraout_v1;
  undefined4 extraout_v1_00;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 local_30;
  
  if (3 < param_1) {
    return 0xffffffff;
  }
  if (stats_debug_switch != '\0') {
    printf("[STATISTICS_DEBUG]%s()/%d _stats_sta_sample_timer_handle start\n",
           "normal_sample_timer_handle",0x267);
  }
  uVar8 = FUN_00524078();
  iVar7 = (int)((ulonglong)uVar8 >> 0x20);
  uVar5 = (uint)uVar8;
  *(undefined8 *)(&g_sta_cur_time + param_1 * 2) = uVar8;
  iVar6 = (&stat_sample_time)[param_1];
  iVar3 = (&g_sta_first_time)[param_1 * 2];
  if (iVar3 == 0 && (&DAT_007cc96c)[param_1 * 2] == 0) {
    *(undefined8 *)(&g_sta_first_time + param_1 * 2) = uVar8;
    local_30 = 0;
  }
  else {
    uVar2 = uVar5 - (&DAT_007cc96c)[param_1 * 2];
    local_30 = (longlong)(iVar6 * (&g_sta_sample_cnt)[param_1]) * -1000000 +
               CONCAT44((iVar7 - iVar3) - (uint)(uVar5 < uVar2),uVar2);
  }
  if (stats_debug_switch != '\0') {
    printf("[STATISTICS_DEBUG]%s()/%d now_real_time:%llu first_sample:%llu\n",
           "normal_sample_timer_handle",0x273,&g_sta_first_time + param_1 * 2,iVar7,uVar5,
           (&g_sta_first_time)[param_1 * 2],(&DAT_007cc96c)[param_1 * 2]);
  }
  if (stats_debug_switch != '\0') {
    printf("[STATISTICS_DEBUG]%s()/%d g_sta_cur_time[%d]:%llu\n","normal_sample_timer_handle",0x274,
           param_1,(&g_sta_cur_time)[param_1 * 2],(&DAT_007cc94c)[param_1 * 2]);
  }
  if (stats_debug_switch != '\0') {
    printf("[STATISTICS_DEBUG]%s()/%d total_inaccuracy_time:%lld g_sta_sample_cnt[type]:%d\n",
           "normal_sample_timer_handle",0x275);
  }
  iVar7 = (&g_sta_sample_cnt)[param_1];
  uVar4 = 0;
  if (iVar7 != 0) {
    if ((local_30._0_4_ < 1) && ((local_30._0_4_ != 0 || (local_30._4_4_ == 0)))) {
      uVar4 = 0;
    }
    else {
      uVar2 = (uint)((longlong)iVar6 * 1000000);
      uVar5 = uVar2 - local_30._4_4_;
      iVar3 = ((int)((ulonglong)((longlong)iVar6 * 1000000) >> 0x20) - local_30._0_4_) -
              (uint)(uVar2 < uVar5);
      if (iVar3 < 1) {
        if (iVar3 != 0) {
          uVar4 = 0;
          goto LAB_0066804c;
        }
        if (uVar5 == 0) {
          uVar4 = 0;
          goto LAB_0066804c;
        }
      }
      __divdi3(iVar3,uVar5,0,1000000);
      __moddi3(iVar3,uVar5,0,1000000);
      uVar4 = extraout_v1_00;
      iVar6 = extraout_v1;
    }
  }
LAB_0066804c:
  bVar1 = stats_debug_switch != '\0';
  (&g_sta_sample_cnt)[param_1] = iVar7 + 1;
  if (bVar1) {
    printf("[STATISTICS_DEBUG]%s()/%d time_interval:%d tim_interval_usec:%d\n",
           "normal_sample_timer_handle",0x281,iVar6,uVar4);
  }
  uVar4 = FUN_00408340(iVar6,uVar4,(&stats_info_sample_timer_hdl)[param_1],0,0,
                       "normal_sample_timer_handle",0x282);
  return uVar4;
}

