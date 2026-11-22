// func wportal_db_rds_srv_hash_dump @ 00434f9c size=60

void wportal_db_rds_srv_hash_dump(void)

{
  puts("Radius server hash table:");
  FUN_00408570(rds_srv_hash_addr,_wportal_db_rds_srv_hash_print,0);
  putchar(10);
  return;
}

