// func wserv_db_ip_tbl_exists_in_db @ 005eb190 size=20

void wserv_db_ip_tbl_exists_in_db(void)

{
  wserv_sqlite_table_exists("/etc/nouci_config/dbs/wserv_ip.db","igmp_ip_tbl");
  return;
}

