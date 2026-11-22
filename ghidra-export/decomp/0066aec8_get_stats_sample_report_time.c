// func get_stats_sample_report_time @ 0066aec8 size=40

undefined4 get_stats_sample_report_time(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 4) {
    uVar1 = (&stat_sample_report_time)[param_1];
  }
  return uVar1;
}

