// func wserv_debug_help @ 005f5e54 size=136

void wserv_debug_help(void)

{
  puts("wservice module help:");
  puts("g_wserv_error               -- error switch.");
  puts("g_wserv_warning             -- warning switch.");
  puts("g_wserv_debug               -- debug switch.");
  puts("wserv_db_print_ap_hash()    -- show ap info bind to vlan.");
  puts("wserv_db_print_all()        -- show all wservices and rd bind info.");
  puts("wserv_db_print_event_reg()  -- show event reg.");
  puts("wserv_rd_print_all()        -- show rd bind info.");
  puts("wserv_ip_print_all()        -- show igmp ip info.");
  puts("wserv_print_profile()       -- show profile values.");
  return;
}

