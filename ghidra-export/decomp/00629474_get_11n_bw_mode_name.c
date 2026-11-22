// func get_11n_bw_mode_name @ 00629474 size=1

char * get_11n_bw_mode_name(uint param_1)

{
  if ((param_1 & 0xffff) < 8) {
    return (&PTR_s_20MHz_0070c880)[param_1 & 0xffff];
  }
  return "---";
}

