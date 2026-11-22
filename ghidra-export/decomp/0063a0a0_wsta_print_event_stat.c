// func wsta_print_event_stat @ 0063a0a0 size=184

void wsta_print_event_stat(void)

{
  printf("l_wsta_pkt_stat.%-20s = %10u\n","ap_roam_wsta",l_wsta_info_stat);
  printf("l_wsta_pkt_stat.%-20s = %10u\n","rd_roam_wsta",DAT_007cc734);
  printf("l_wsta_pkt_stat.%-20s = %10u\n","wlan_roam_wsta",DAT_007cc738);
  printf("l_wsta_pkt_stat.%-20s = %10u\n","duplicate_wsta",DAT_007cc740);
  printf("l_wsta_pkt_stat.%-20s = %10u\n","new_assoc_wsta",DAT_007cc73c);
  printf("l_wsta_pkt_stat.%-20s = %10u\n","deassoc_not_found",DAT_007cc744);
  printf("l_wsta_pkt_stat.%-20s = %10u\n","deassoc_err_inf",DAT_007cc748);
  return;
}

