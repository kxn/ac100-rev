// func wportal_db_dm_framed_ip_hash_dump @ 00435014 size=60

void wportal_db_dm_framed_ip_hash_dump(void)

{
  puts("Aut entry for dm framed ip hash table:");
  FUN_00408570(dm_framed_ip_hash,_wportal_db_dm_framed_ip_hash_print,0);
  putchar(10);
  return;
}

