// func stats_print_pkt_info_stat @ 006748d8 size=1

void stats_print_pkt_info_stat(void)

{
  printf("l_stats_pkt_info_stat.%-20s = %10u\n","sta_req",l_stats_pkt_info_stat);
  printf("l_stats_pkt_info_stat.%-20s = %10u\n","ap_req",DAT_007cca14);
  printf("l_stats_pkt_info_stat.%-20s = %10u\n","rssi_req",DAT_007cca18);
  return;
}

