// func apmngr_db_debug_help_print @ 00543204 size=88

void apmngr_db_debug_help_print(void)

{
  puts("apmngr_db_debug_ap_show(int detail)                -- show ap entry for all");
  puts("apmngr_db_debug_ap_show_by_mac(char *mac)          -- show ap entry for target mac");
  puts("apmngr_db_debug_ap_show_by_group(int group_id)     -- show ap entry of specified group");
  puts("apmngr_db_debug_template_show()                    -- show template entry for all");
  puts("apmngr_db_debug_entry_show()                       -- show ap and template entry for all");
  puts("apmngr_db_debug_group_show()                       -- show group for all");
  return;
}

