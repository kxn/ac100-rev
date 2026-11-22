// func rdmngr_print_profile @ 00621fa0 size=116

void rdmngr_print_profile(void)

{
  puts("########################################################");
  printf("g_rdmngr_profile.max_rd_per_ap    = %d\n",DAT_007cc65c);
  printf("g_rdmngr_profile.max_wlan_per_rd  = %d\n",g_rdmngr_profile);
  printf("g_rdmngr_profile.rssi_kick_supoort= %d\n",DAT_007cc660);
  puts("########################################################");
  return;
}

