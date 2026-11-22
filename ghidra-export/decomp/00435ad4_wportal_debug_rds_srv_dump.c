// func wportal_debug_rds_srv_dump @ 00435ad4 size=1

void wportal_debug_rds_srv_dump(void)

{
  puts("Radius server:");
  wportal_db_rds_srv_traverse(_wportal_db_rds_srv_traverse_print,0);
  putchar(10);
  return;
}

