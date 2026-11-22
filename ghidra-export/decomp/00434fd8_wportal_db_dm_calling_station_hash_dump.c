// func wportal_db_dm_calling_station_hash_dump @ 00434fd8 size=60

void wportal_db_dm_calling_station_hash_dump(void)

{
  puts("Aut entry for dm calling station hash table:");
  FUN_00408570(dm_calling_station_hash,_wportal_db_dm_calling_station_hash_print,0);
  putchar(10);
  return;
}

