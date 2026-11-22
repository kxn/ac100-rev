// func apmngr_debug_help @ 005481a0 size=60

void apmngr_debug_help(void)

{
  puts("apmngr debug commands:");
  puts("apmngr_debug_help()                                -- help menu");
  apmngr_debug_help_print();
  apmngr_db_debug_help_print();
  apmngr_db_sqlite_debug_help_print();
  return;
}

