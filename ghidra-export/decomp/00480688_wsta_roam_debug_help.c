// func wsta_roam_debug_help @ 00480688 size=172

void wsta_roam_debug_help(void)

{
  puts("wstation fast roam module help:");
  puts("wsta_roam_err_switch                 -- error switch.");
  puts("wsta_roam_warning_switch             -- warning switch.");
  puts("wsta_roam_debug_switch               -- debug switch.");
  puts("wsta_roam_strategy_switch            -- roaming strategy switch.");
  puts("wsta_roam_db_print_pmk_all()         -- show all pmk roaming entry.");
  puts("wsta_roam_db_print_global_stats()    -- show global roaming stats.");
  puts("wsta_roam_db_print_ap_stats_by_id(u_int16_t id)  -- show ap\'s roaming stats by id.");
  puts("wsta_roam_db_print_ap_stats_all()    -- show all ap\'s roaming stats.");
  puts("wsta_roam_db_print_sta_tmprcd_all()  -- show all station\'s tmp record.");
  puts("wsta_roam_db_print_config()          -- show wstation fast roaming config.");
  puts("wsta_roam_print_pkt_info_stat()      -- show packet info statistics.");
  puts("wsta_roam_clear_pkt_info_stat()      -- clear packet info statistics.");
  return;
}

