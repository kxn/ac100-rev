// func wsta_clear_pkt_info_stat @ 00636750 size=1

void wsta_clear_pkt_info_stat(void)

{
  l_wsta_pkt_info_stat = 0;
  DAT_007cc674 = 0;
  DAT_007cc678 = 0;
  DAT_007cc67c = 0;
  DAT_007cc680 = 0;
  DAT_007cc684 = 0;
  return;
}

