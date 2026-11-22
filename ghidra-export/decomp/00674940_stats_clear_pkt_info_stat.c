// func stats_clear_pkt_info_stat @ 00674940 size=1

void stats_clear_pkt_info_stat(void)

{
  l_stats_pkt_info_stat = 0;
  DAT_007cca14 = 0;
  DAT_007cca18 = 0;
  return;
}

