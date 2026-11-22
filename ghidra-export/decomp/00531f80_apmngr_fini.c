// func apmngr_fini @ 00531f80 size=36

void apmngr_fini(void)

{
  apmngr_db_sqlite_fini();
  apmngr_db_fini();
  apmngr_support_capacity_uninit();
  return;
}

