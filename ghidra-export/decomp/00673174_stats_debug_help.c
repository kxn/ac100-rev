// func stats_debug_help @ 00673174 size=1

void stats_debug_help(void)

{
  puts("statistics module help:");
  puts("stats_err_switch                 -- error switch.");
  puts("stats_warning_switch             -- warning switch.");
  puts("stats_debug_switch               -- debug switch.");
  puts("stats_db_print_ap_by_id(int id)  -- show statistics of an ap entry.");
  puts("stats_db_print_ap_all()          -- show all ap statistics.");
  puts("stats_db_print_bssid_all()       -- show all bssid statistics.");
  puts("stats_db_print_sta_all()         -- show all station statistics.");
  puts("stats_db_print_sta_by_mac(char *mac) -- show station statistics of the specified mac.");
  puts("stats_db_print_ctl() \t\t\t -- show stats config.");
  puts("stats_print_pkt_info_stat() \t -- show packet rcv/send info statistics.");
  (*(code *)PTR_puts_00758f90)
            ("stats_clear_pkt_info_stat() \t -- reset packet rcv/send info statistics.");
  return;
}

