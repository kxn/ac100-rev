// func wserv_db_wserv_tbl_exists_in_db @ 005eb168 size=20

void wserv_db_wserv_tbl_exists_in_db(void)

{
  wserv_sqlite_table_exists("/etc/nouci_config/dbs/wserv.db","wserv_tbl");
  return;
}

