// func wsta_roam_print_pkt_info_stat @ 0048a2c8 size=1

void wsta_roam_print_pkt_info_stat(void)

{
  printf("l_wsta_roam_pkt_info_stat.%-20s = %10u\n","inform",l_wsta_roam_pkt_info_stat);
  printf("l_wsta_roam_pkt_info_stat.%-20s = %10u\n","inform_suc",DAT_007675cc);
  printf("l_wsta_roam_pkt_info_stat.%-20s = %10u\n","request",DAT_007675d0);
  printf("l_wsta_roam_pkt_info_stat.%-20s = %10u\n","request_suc",DAT_007675d4);
  printf("l_wsta_roam_pkt_info_stat.%-20s = %10u\n","response",uRam007675d8);
  printf("l_wsta_roam_pkt_info_stat.%-20s = %10u\n","roam_trigger",DAT_007675dc);
  printf("l_wsta_roam_pkt_info_stat.%-20s = %10u\n","others",DAT_007675e0);
  return;
}

