// func wsta_print_pkt_info_stat @ 006366ac size=1

void wsta_print_pkt_info_stat(void)

{
  printf("l_wsta_pkt_info_stat.%-20s = %10u\n","rssi_report",l_wsta_pkt_info_stat);
  printf("l_wsta_pkt_info_stat.%-20s = %10u\n","sta_list",DAT_007cc674);
  printf("l_wsta_pkt_info_stat.%-20s = %10u\n","sta_assoc",DAT_007cc678);
  printf("l_wsta_pkt_info_stat.%-20s = %10u\n","sta_reassoc",DAT_007cc67c);
  printf("l_wsta_pkt_info_stat.%-20s = %10u\n","sta_deassoc",DAT_007cc680);
  printf("l_wsta_pkt_info_stat.%-20s = %10u\n","ip_report",DAT_007cc684);
  return;
}

