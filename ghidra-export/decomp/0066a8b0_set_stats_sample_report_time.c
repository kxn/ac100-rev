// func set_stats_sample_report_time @ 0066a8b0 size=44

void set_stats_sample_report_time(int param_1,uint param_2)

{
  if ((param_2 < 4) && (param_1 != (&stat_sample_report_time)[param_2])) {
    (&stat_sample_report_time)[param_2] = param_1;
  }
  return;
}

