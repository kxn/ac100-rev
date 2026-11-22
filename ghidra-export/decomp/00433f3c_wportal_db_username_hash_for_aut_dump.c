// func wportal_db_username_hash_for_aut_dump @ 00433f3c size=92

void wportal_db_username_hash_for_aut_dump(void)

{
  puts("Username hash table for aut:");
  FUN_004082d0(wportal_aut_mutex,0xffffffff);
  FUN_00408570(username_hash_for_aut,_wportal_db_username_hash_aut_foreach_cb_func,0);
  FUN_00407f30(wportal_aut_mutex);
  putchar(10);
  return;
}

