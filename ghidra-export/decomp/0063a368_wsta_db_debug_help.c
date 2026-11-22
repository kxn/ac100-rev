// func wsta_db_debug_help @ 0063a368 size=172

void wsta_db_debug_help(void)

{
  puts("wstation module help:");
  puts("g_wsta_error               -- error switch.");
  puts("g_wsta_warning             -- warning switch.");
  puts("g_wsta_debug               -- debug switch.");
  puts("wsta_db_print_all()        -- show all wstation entry.");
  puts("wsta_db_print_roam_all()   -- show all roam wstation entry.");
  puts("wsta_db_print_ap_all()     -- show all wstations associated to ap.");
  puts("wsta_db_print_list(0/1)    -- show all wstation in list.");
  puts("wsta_db_print_event_reg()  -- show event reg.");
  puts("wsta_db_mlo_hash_dump()     -- show mlo wstation hash.");
  puts("wsta_print_event_stat()     -- show wstation event statistics.");
  puts("wsta_clear_event_stat()     -- clear wstation event statistics.");
  puts("wsta_print_profile()       -- show profile values.");
  return;
}

