// func wsta_clear_event_stat @ 0063a158 size=1

void wsta_clear_event_stat(void)

{
  l_wsta_info_stat = 0;
  DAT_007cc734 = 0;
  DAT_007cc738 = 0;
  DAT_007cc73c = 0;
  DAT_007cc740 = 0;
  DAT_007cc744 = 0;
  DAT_007cc748 = 0;
  return;
}

