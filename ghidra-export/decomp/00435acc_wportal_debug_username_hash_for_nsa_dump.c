// func wportal_debug_username_hash_for_nsa_dump @ 00435acc size=1

void wportal_debug_username_hash_for_nsa_dump(void)

{
  puts("Username hash table for nsa:");
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  FUN_00408570(username_hash_for_nsa,_wportal_db_username_hash_nsa_foreach_cb_func,0);
  FUN_00407f30(wportal_nsa_mutex);
  putchar(10);
  return;
}

