// func wsta_roam_db_print_config @ 00483568 size=576

void wsta_roam_db_print_config(void)

{
  puts("intelligent para:");
  printf("roam_wireless_network_mode: %d\n",(uint)l_wsta_roam_cfg);
  printf("cur_roam_wireless_network_mode: %d\n",(uint)DAT_00767575);
  printf("roma_cnt: %d\n",(uint)DAT_00767577);
  printf("silence_time: %d\n",(uint)DAT_00767578);
  printf("high_per_roma_cnt: %d\n",(uint)DAT_0076757a);
  printf("high_per_silence_time: %d\n",(uint)DAT_0076757c);
  printf("acs_timeout: %d\n",(uint)DAT_0076757e);
  printf("rssi_trigger_threshold_high_performance: %d\n",(int)DAT_00767576);
  printf("_11k_switch: %d\n",(uint)DAT_0076757f);
  printf("_11v_switch: %d\n",(uint)DAT_00767580);
  printf("_11r_switch: %d\n",(uint)DAT_00767581);
  puts("2g para:");
  printf("_2g_trigger_type: 0x%02x\n",(uint)DAT_00767582);
  printf("_2g_rssi_trigger_threshold: %d\n",(int)DAT_00767583);
  printf("_2g_rssi_kick_switch: %d\n",(uint)DAT_00767584);
  printf("_2g_rssi_kick_threshold: %d\n",(int)DAT_00767585);
  printf("_2g_rate_trigger_threshold: %d\n",(uint)DAT_00767586);
  printf("_2g_rate_kick_switch: %d\n",(uint)DAT_00767587);
  printf("_2g_rate_kick_threshold: %d\n",(uint)DAT_00767588);
  puts("5g para:");
  printf("_5g_trigger_type: 0x%02x\n",(uint)DAT_00767589);
  printf("_5g_rssi_trigger_threshold: %d\n",(int)DAT_0076758a);
  printf("_5g_rssi_kick_switch: %d\n",(uint)DAT_0076758b);
  printf("_5g_rssi_kick_threshold: %d\n",(int)DAT_0076758c);
  printf("_5g_rate_trigger_threshold: %d\n",(uint)DAT_0076758d);
  printf("_5g_rate_kick_switch: %d\n",(uint)DAT_0076758e);
  printf("_5g_rate_kick_threshold: %d\n",(uint)DAT_0076758f);
  putchar(10);
  printf("threshold_check_interval: %d\n",(uint)DAT_00767590);
  printf("roaming_dif: %d\n",(uint)DAT_00767591);
  printf("blacklist_restrict_time: %d\n",(uint)DAT_00767592);
  printf("stats_switch: %d\n",(uint)DAT_00767593);
  printf("stats_interval: %d\n",(uint)DAT_00767594);
  printf("roaming strategy: %d\n",l_wsta_roam_strategy);
  return;
}

