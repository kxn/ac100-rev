// func audit_client_db_is_server_enable @ 0050a03c size=20

bool audit_client_db_is_server_enable(void)

{
  return audit_server == 1;
}

