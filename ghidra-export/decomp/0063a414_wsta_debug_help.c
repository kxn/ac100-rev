// func wsta_debug_help @ 0063a414 size=1

void wsta_debug_help(void)

{
  wsta_db_debug_help();
  puts("wsta_print_pkt_info_stat()        -- show packet info statistics.");
  puts("wsta_clear_pkt_info_stat()        -- clear packet info statistics.");
  puts("wsta_print_assoc_check_reg()      -- show assoc check reg.");
  return;
}

