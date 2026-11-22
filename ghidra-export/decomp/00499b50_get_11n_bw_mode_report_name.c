// func get_11n_bw_mode_report_name @ 00499b50 size=1

char * get_11n_bw_mode_report_name(uint param_1)

{
  if ((param_1 & 0xffff) < 8) {
    return (&PTR_DAT_0069b4b4)[param_1 & 0xffff];
  }
  return "---";
}

