// func dhcpdef_debug_help @ 00472f54 size=1

void dhcpdef_debug_help(void)

{
  puts("dhcp defend debug commands:");
  puts("dhcpdef_debug_help(void)                           -- help menu");
  puts("dhcpdef_db_profile_print(void)                     -- show profile");
  puts("dhcpdef_db_memstat_print(void)                     -- show memory used");
  puts("dhcpdef_db_svr_entry_count(void)                   -- show current dhcp-server entry count")
  ;
  puts(
      "dhcpdef_db_svr_entry_print_by_id(int32_t svr_id)   -- show one dhcp-server entry by server id"
      );
  puts("dhcpdef_db_svr_entry_print_all(void)               -- show all dhcp-server entries");
  puts("dhcpdef_db_apbind_entry_count(void)                -- show current ap entry count");
  puts("dhcpdef_db_apbind_entry_print_by_id(int32_t ap_id) -- show one ap entry by ap id");
  puts("dhcpdef_db_apbind_entry_print_all(void)            -- show all ap entries");
  puts("g_dhcpdef_error=1/0                                -- enable/disable <error> level message")
  ;
  puts(
      "g_dhcpdef_warn=1/0                                 -- enable/disable <warning> level messages"
      );
  (*(code *)PTR_puts_00758f90)
            (
            "g_dhcpdef_info=1/0                                 -- enable/disable <debug> level messages"
            );
  return;
}

