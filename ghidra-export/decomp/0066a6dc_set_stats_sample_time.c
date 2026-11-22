// func set_stats_sample_time @ 0066a6dc size=428

void set_stats_sample_time(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 < 4) {
    bVar1 = false;
    FUN_004082d0(stat_gloabl_data_mutex,0xffffffff);
    if (param_1 != (&stat_sample_time)[param_2]) {
      FUN_00408060((&l_stats_data)[param_2 + 10]);
      (&l_stats_data)[param_2 + 10] = 0xffffffff;
      for (iVar2 = FUN_004081b0(&g_sample_time_changed_callback_list + param_2 * 0xc); iVar2 != 0;
          iVar2 = FUN_00408680(iVar2)) {
        if (*(code **)(iVar2 + 0x14) != (code *)0x0) {
          (**(code **)(iVar2 + 0x14))(param_2);
        }
      }
      (&stat_sample_time)[param_2] = param_1;
      bVar1 = true;
      (&DAT_007cc94c)[param_2 * 2] = 0;
      (&g_sta_cur_time)[param_2 * 2] = 0;
      (&DAT_007cc96c)[param_2 * 2] = 0;
      (&g_sta_first_time)[param_2 * 2] = 0;
      (&g_sta_sample_cnt)[param_2] = 0;
    }
    FUN_00407f30(stat_gloabl_data_mutex);
    if (bVar1) {
      uVar3 = FUN_00408340((&stat_sample_time)[param_2],0,(&stats_info_sample_timer_hdl)[param_2],0,
                           0,"set_stats_sample_time",0x4c8);
      (&l_stats_data)[param_2 + 10] = uVar3;
    }
  }
  return;
}

