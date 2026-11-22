// func get_stats_sample_time @ 0066a888 size=40

undefined4 get_stats_sample_time(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 4) {
    uVar1 = (&stat_sample_time)[param_1];
  }
  return uVar1;
}

