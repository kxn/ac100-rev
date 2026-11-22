// func wsta_roam_clear_pkt_info_stat @ 0048a380 size=1

void wsta_roam_clear_pkt_info_stat(void)

{
  l_wsta_roam_pkt_info_stat = 0;
  DAT_007675cc = 0;
  DAT_007675d0 = 0;
  DAT_007675d4 = 0;
  uRam007675d8 = 0;
  DAT_007675dc = 0;
  DAT_007675e0 = 0;
  return;
}

